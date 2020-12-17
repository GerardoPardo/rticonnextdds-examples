/* SerializeTypecode_subscriber.cxx
*/

#include <stdio.h>
#include <stdlib.h>

#include <map>
#include <string>

#include "ndds/ndds_cpp.h"

class DynamicDataReaderListener : public DDSDataReaderListener {
public:
    virtual void on_data_available (DDSDataReader *reader);
    virtual void on_subscription_matched (DDSDataReader *reader,  const DDS_SubscriptionMatchedStatus &status);
    
protected:
    virtual void print_members_recursively(DDS_DynamicData &dynamic_data, int indent);
};

void DynamicDataReaderListener::on_data_available(DDSDataReader *reader)
{
    DDS_ReturnCode_t retcode;

    printf("on_data_available(): Topic: \"%s\", type: \"%s\"\n", 
        reader->get_topicdescription()->get_name(), reader->get_topicdescription()->get_type_name());

    // Take all the samples
    DDSDynamicDataReader *dynamic_reader = DDSDynamicDataReader::narrow(reader);
    DDS_DynamicDataSeq data_seq;
    DDS_SampleInfoSeq  info_seq;

    retcode = dynamic_reader->take(data_seq, info_seq, DDS_LENGTH_UNLIMITED,
                                   DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ALIVE_INSTANCE_STATE);
    if (retcode == DDS_RETCODE_NO_DATA) {
        return;
    } else if (retcode != DDS_RETCODE_OK) {
        printf("take error %d\n", retcode);
        return;
    }

    printf("Read %d samples.\n", data_seq.length());
    for (int i = 0; i < data_seq.length(); ++i) {
       printf("Received data sample[%d]:\n", i);
       data_seq[i].print(stdout, 4);

      // Illustrate the use of the DynamicData APIs to recursively iterate through the members
      print_members_recursively(data_seq[i], 4);
    } 

    retcode = dynamic_reader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "return loan error %d\n", retcode);
    }
}

void DynamicDataReaderListener::print_members_recursively(DDS_DynamicData &dynamic_data, int indent)
{
    DDS_DynamicDataMemberInfo member_info;
    DDS_ReturnCode_t retcode;

    int member_count = dynamic_data.get_member_count();
    for (int index = 0; index < member_count; ++index ) {
        retcode = dynamic_data.get_member_info_by_index(member_info, index);
        if ( member_info.member_kind == DDS_TK_LONG ) {
            int value;
            retcode = dynamic_data.get_long (value, NULL, member_info.member_id);
            printf("%*sMember name: \"%s\", kind: %d, value: %d\n", 
                   indent, "", member_info.member_name, member_info.member_kind, value);
        }
        else if ( member_info.member_kind == DDS_TK_STRING ) {
            const DDS_UnsignedLong STRING_SIZE = 256;
            char value[STRING_SIZE];
            char *value_ptr = value;
            DDS_UnsignedLong str_length = STRING_SIZE-1;
            
            retcode = dynamic_data.get_string (value_ptr, &str_length, NULL, member_info.member_id);
            if ( retcode != DDS_RETCODE_OK ) {
                printf("Failed to get member name: \"%s\", of type string.\n", member_info.member_name);
                if ( str_length > (STRING_SIZE -1) ) {
                    printf("Specified buffer can hold %d characters, but string value requires %d characters.\n",
                           STRING_SIZE -1, str_length);
                }   
            } else {
                printf("%*sMember name: \"%s\", kind: %d, value: \"%s\"\n", 
                       indent, "", member_info.member_name, member_info.member_kind, value);
            }
        }
        else if ( member_info.member_kind == DDS_TK_STRUCT ) {
            DDS_DynamicData nested_dynamic_data(NULL, DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);
            printf("%*sMember name: \"%s\", kind: %d (Structure), nested members:\n",  
                   indent, "", member_info.member_name, member_info.member_kind);
            retcode = dynamic_data.bind_complex_member( nested_dynamic_data, NULL, member_info.member_id);
            print_members_recursively(nested_dynamic_data, indent + 4);
            retcode = dynamic_data.unbind_complex_member(nested_dynamic_data); 
        }
    }
}


void DynamicDataReaderListener::on_subscription_matched(DDSDataReader *reader,  const DDS_SubscriptionMatchedStatus &status)
{
    printf("on_subscription_matched(): Topic: \"%s\", type: \"%s\" now has %d matched DataWriters.\n", 
        reader->get_topicdescription()->get_name(), reader->get_topicdescription()->get_type_name(),
        status.current_count);
}

class MonitorDiscoveredTopics {

public:
    bool start(int domainId);
    bool wait_for_discovery_data();
    bool shutdown();
    void process_discovered_data_writers();

protected:
    virtual bool process_type(const char *type_name, DDS_TypeCode * type_code);
    virtual bool process_topic(const char *topic_name, const char *type_name);
    virtual bool register_new_type(const char *type_name, DDS_TypeCode * type_code);

private:
    DDSDomainParticipant *participant;
    DDSSubscriber *subscriber;
    DDSTopic *topic;
    DDSDataReader *reader;
    DDS_ReturnCode_t retcode;
    int count;
    DDSWaitSet *discovery_waitset;
    DDSConditionSeq active_condition_seq;
    DDSPublicationBuiltinTopicDataDataReader   *publicationsDR;
    DynamicDataReaderListener *data_reader_listener;

    typedef std::map<std::string, DDSDynamicDataTypeSupport *> TypecodeMap;
    TypecodeMap discoveredTypes;
};



/*
 * This function reads all the new recived samples in the publicationsDR. 
 * 
 * Each of these samples contains the information received via the DDS builtin 
 * discovery protocol about a DataWriter the the DomainParticipant has discovered.
 * 
 * The sample formation is encoded in DDS_PublicationBuiltinTopicData and contains 
 * informtion about the Topic name, Type name and associated Type descriptip. 
 * 
 * This is used to register the type information with the DomainParticipant as well
 * as to created a DataReader that Topic and Type.
 */
void MonitorDiscoveredTopics::process_discovered_data_writers() {
    DDS_PublicationBuiltinTopicData publicationData;
    DDS_PublicationBuiltinTopicData_initialize( &publicationData);
    DDS_SampleInfo info;

    //printf("MonitorDicoveredTypes::process_discovered_data_writers()\n");
    while ( publicationsDR->take_next_sample(publicationData, info) == DDS_RETCODE_OK ) {

        // Process only new DataWriters. They are the only ones that may contain Topics 
        // and Types that we may have not seen before.
        // While some Qos parameters may change during the lifetime of a DataWriter the 
        // data-type and Topic name cannot change.
        if ( info.view_state == DDS_NEW_VIEW_STATE ) {
            printf("DataWriter (New) name: \"%s\"  topic: \"%s\" type: \"%s\"\n" ,
                    publicationData.publication_name.name,
                    publicationData.topic_name,
                    publicationData.type_name);
            process_type(publicationData.type_name, publicationData.type_code);
            process_topic(publicationData.topic_name, publicationData.type_name);
        }
    }
}

/*
 * This function only processes types if the type description (DDS_TypeCode) is provided
 * otherwise it ignores the type so that it can be processed later if it is discovered
 * from another source.
 * 
 * The function returs true if no errors were encountered. This indicates that either
 * it is a new type and it was successfully registered or matches an already registered type.
 */ 
bool MonitorDiscoveredTopics::process_type(const char *type_name, DDS_TypeCode *type_code) {
    DDSDynamicDataTypeSupport *existing_type_support = NULL;
    DDS_ExceptionCode_t ex;
    TypecodeMap::iterator iterator;

    printf("process_type(): Processing type with name = \"%s\"\n", type_name);
    if ( type_code == NULL ) {
        printf("No type information was supplied for type_name: \"%s\". Ignoring type.\n", type_name);
        return false;
    }

    // See if we already had a type with the same name
    iterator  = this->discoveredTypes.find(type_name);
    if ( iterator != this->discoveredTypes.end() ) {
        printf("A type with name \%s\" had been registered already. Comparing the type definitions...\n", type_name);
        existing_type_support = iterator->second;
        if ( existing_type_support->get_data_type()->equal(type_code, ex) ) {
            printf("The new type matches the existing definition\n");
            return true;
        }
        else {
            printf("The type DOES NOT match the existing definition. New definition will be ignored.\n");

            printf("Existing definition for type \%s\":\n", type_name);
            existing_type_support->get_data_type()->print_IDL(0, ex);

            printf("Definition for new type with the same name (ignored):\n");
            type_code->print_IDL(0, ex);
            return false;
        }
    }

    // If we get here we discovered a type name for the first time
    return register_new_type(type_name, type_code);;
 }

 /* 
  * Creates a DDSDynamicDataTypeSupport from the specified DDS_TypeCode and uses it
  * to register the type with the DomainParticipant. This makes it possible to
  * to create Topics for that type.
  * 
  * It keeps a reference to the created DDSDynamicDataTypeSupport in the discoveredTypes 
  * map so that whenver a new type is discovered it can check it it has been already
  * registered.
  * 
  * The function returs true if no errors were encountered. This indicates that the new
  * type was registered with the DomainParticipant.
  */ 
bool MonitorDiscoveredTopics::register_new_type(const char *type_name, DDS_TypeCode *type_code) {
    DDS_ExceptionCode_t ex;
    DDS_ReturnCode_t dds_retcode;

    printf("register_new_type(): Registering type: \"%s\". Equivalent IDL is:\n", type_name);
    type_code->print_IDL(0, ex);

    // Create a Dynamic Type Support object from the Discovered TypeCode
    DDSDynamicDataTypeSupport *dynamic_type_support = 
        new DDSDynamicDataTypeSupport(type_code, DDS_DYNAMIC_DATA_TYPE_PROPERTY_DEFAULT);

    dds_retcode = dynamic_type_support->register_type(this->participant, type_name);
    if ( dds_retcode != DDS_RETCODE_OK ) {
        printf("Error registering type \"%s\" with the DomainParticipant. Rectode: %d\n.", type_name, dds_retcode);
        return false;
    }

    // Save a copy of the DDSDynamicDataTypeSupport keyed by the name
    this->discoveredTypes[type_name] = dynamic_type_support;
    return true;
}

/*
 * This function checks whether the specifed Topic has alreaby been subscribe to and if not it
 * creates a DataReader to subscribe to the Topic, registering a callback function that print data 
 * received on that Topic.
 * 
 * If the Topic has already been subscribe the function does nothing. Note that a single DataReader 
 * (the already created one) is only able to receive from the new DataWriter on the Topic if type
 * specified by the new DataWriter is compatible with the type of the existing DataReader, and also
 * if the new DataWriter has a Qos compatible with the one of the existing DataReader.
 */ 
bool MonitorDiscoveredTopics::process_topic(const char *topic_name, const char *type_name) {
    
    printf("process_topic:() Processing topic: \"%s\" with associated type: \"%s\".\n", 
          topic_name, type_name);

    DDSTopicDescription *topic_description =  this->participant->lookup_topicdescription(topic_name);
    // Check if this Topic has alrady been created:
    if ( topic_description != NULL) {
        int  type_name_comparison = strcmp(type_name, topic_description->get_type_name());

        printf("Topic with name \"%s\" already exists. No new Topic is created. "
               "Existing topic %s the same type name.\n", 
               topic_name, 
               (type_name_comparison==0)?"has":"does not have");

        return true;
    }

    // No exisitng Topic with that name was found. Create one:
    DDSTopic *topic = 
        this->participant->create_topic(topic_name, type_name, DDS_TOPIC_QOS_DEFAULT, NULL, DDS_STATUS_MASK_NONE);
    if ( topic == NULL ) {
        printf("Error creating topic \"%s\" with type \%s\".\n", topic_name, type_name);
        return false;
    }
    printf("Created Topic \"%s\", type \%s\".\n", topic_name, type_name);

    // Create a dynamic data DataReader for the Topic, using the implicit subscriber
    DDSDataReader * reader = 
        reader = this->participant->create_datareader(
                        topic, DDS_DATAREADER_QOS_DEFAULT, 
                        data_reader_listener,  DDS_DATA_AVAILABLE_STATUS | DDS_SUBSCRIPTION_MATCHED_STATUS);
    if ( reader == NULL ) {
        printf("Error creating DataReader for Topic \"%s\" with type \%s\".\n", topic_name, type_name);
        return false;            
    }
    printf("Created DataReader for Topic \%s\".\n",  topic_name);

    return true;
}

bool MonitorDiscoveredTopics::wait_for_discovery_data() {
    //printf("MonitorDicoveredTypes::wait_for_discovery_data()\n");
    return ( discovery_waitset->wait(active_condition_seq, DDS_DURATION_INFINITE) == DDS_RETCODE_OK);
}

bool MonitorDiscoveredTopics::start(int domainId)
{
    /* To customize the participant QoS, use 
       the configuration file USER_QOS_PROFILES.xml */
    participant = DDSTheParticipantFactory->create_participant(
        domainId, DDS_PARTICIPANT_QOS_DEFAULT, 
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("MonitorDiscoveredTopics::start: create_participant error.\n");
        shutdown();
        return false;
    }

    publicationsDR  = (DDSPublicationBuiltinTopicDataDataReader *)
            participant->get_builtin_subscriber()->lookup_datareader("DCPSPublication");

    if ( publicationsDR == NULL ) {
        printf("MonitorDiscoveredTopics::start: Error retrieving \"DCPSPublications\" builtin reader.\n");
        return false;
    }

    discovery_waitset = new DDSWaitSet();

    // Attach the conditions that would wakeup the waitset. In this case the arrival of data on
    // any of the builting datareaders
    discovery_waitset->attach_condition(publicationsDR->get_statuscondition());
    publicationsDR->get_statuscondition()->set_enabled_statuses(DDS_DATA_AVAILABLE_STATUS);

    data_reader_listener = new DynamicDataReaderListener();

    printf("MonitorDiscoveredTopics::start: Started on domainId = %d\n", domainId);

    return true;
}

/* Delete all entities */
bool MonitorDiscoveredTopics::shutdown()
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            printf("MonitorDiscoveredTopics::shutdown: Error in  delete_contained_entities(), retcode=%d\n", retcode);
            return false;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            printf("MonitorDiscoveredTopics::shutdown: Error in delete_participant(), retcode=%d\n", retcode);
            return false;
        }
    }

    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        printf("MonitorDiscoveredTopics::shutdown: Error in finalize_instance(), retcode=%d\n", retcode);
        return false;
    }

    return true;
}



int main(int argc, char *argv[])
{
    int domainId = 0;

    if (argc >= 2) {
        domainId = atoi(argv[1]);
    }

    MonitorDiscoveredTopics *discovery_monitor = new MonitorDiscoveredTopics();
    discovery_monitor->start(domainId);

    while ( true ) {
        discovery_monitor->wait_for_discovery_data();
        discovery_monitor->process_discovered_data_writers();
    }
}
