
/**/

#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_c.h"
#include "SerializedTypeKeyed.h"
#include "SerializedTypeKeyedSupport.h"

#include "ShapeType.h"
#include "ShapeTypePlugin.h"

/* Delete all entities */
static int publisher_shutdown(
    DDS_DomainParticipant *participant)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = DDS_DomainParticipant_delete_contained_entities(participant);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = DDS_DomainParticipantFactory_delete_participant(
            DDS_TheParticipantFactory, participant);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    /* RTI Data Distribution Service provides finalize_instance() method on
    domain participant factory for people who want to release memory used
    by the participant factory. Uncomment the following block of code for
    clean destruction of the singleton. */
    /*
    retcode = DDS_DomainParticipantFactory_finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "finalize_instance error %d\n", retcode);
        status = -1;
    }
    */

    return status;
}

static int publisher_main(int domainId, int sample_count)
{
    DDS_DomainParticipant *participant = NULL;
    DDS_Publisher *publisher = NULL;
    DDS_Topic *topic = NULL;
    DDS_DataWriter *writer = NULL;
    SerializedTypeKeyedDataWriter *SerializedTypeKeyed_writer = NULL;
    SerializedTypeKeyed *instance = NULL;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    const char *type_name = NULL;
    int count = 0;  
    struct DDS_Duration_t send_period = {4,0};

    /* To customize participant QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    participant = DDS_DomainParticipantFactory_create_participant(
        DDS_TheParticipantFactory, domainId, &DDS_PARTICIPANT_QOS_DEFAULT,
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        fprintf(stderr, "create_participant error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* To customize publisher QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    publisher = DDS_DomainParticipant_create_publisher(
        participant, &DDS_PUBLISHER_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        fprintf(stderr, "create_publisher error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Register type before creating topic */
	retcode = SerializedTypeKeyedTypeSupport_register_type2(
		participant, "ShapeType", ShapeType_get_typecode());

	if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "register_type error %d\n", retcode);
        publisher_shutdown(participant);
        return -1;
    }

    /* To customize topic QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    topic = DDS_DomainParticipant_create_topic(
        participant, "Square",
        "ShapeType", &DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        fprintf(stderr, "create_topic error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* To customize data writer QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    writer = DDS_Publisher_create_datawriter(
        publisher, topic,
        &DDS_DATAWRITER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        fprintf(stderr, "create_datawriter error\n");
        publisher_shutdown(participant);
        return -1;
    }
    SerializedTypeKeyed_writer = SerializedTypeKeyedDataWriter_narrow(writer);
    if (SerializedTypeKeyed_writer == NULL) {
        fprintf(stderr, "DataWriter narrow error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* Create data sample for writing */
    instance = SerializedTypeKeyedTypeSupport_create_data_ex(DDS_BOOLEAN_TRUE);
    if (instance == NULL) {
        fprintf(stderr, "SerializedTypeKeyedTypeSupport_create_data error\n");
        publisher_shutdown(participant);
        return -1;
    }

    /* For a data type that has a key, if the same instance is going to be
    written multiple times, initialize the key here
    and register the keyed instance prior to writing */
    /*
    instance_handle = SerializedTypeKeyedDataWriter_register_instance(
        SerializedTypeKeyed_writer, instance);
    */

	ShapeType shapeType;
	ShapeType_initialize(&shapeType);

#define NUMBER_OF_COLORS (4)
	char *colors[NUMBER_OF_COLORS] = { "GREEN", "RED", "BLUE", "YELLOW" };
	int  xbase[NUMBER_OF_COLORS] = { 10, 50, 100, 150 };
	int  ybase[NUMBER_OF_COLORS] = {  0,  0,  0,   0 };

	for (count = 0; (sample_count == 0) || (count < sample_count); ++count) {

		printf("Writing ShapeType, count %d\n", count);

		/* Modify the data to be written here */
		strcpy_s(shapeType.color, COLOR_LENGTH_MAX, colors[count % NUMBER_OF_COLORS]);
		shapeType.x = xbase[count % NUMBER_OF_COLORS] + count % 250;
		shapeType.y = ybase[count % NUMBER_OF_COLORS] + (2 * count) % 250;
		shapeType.shapesize = 20 + count % 30;

		/* Write data */
#define SERIALIZATION_BUFFER_SIZE (1024)
		// Use "int" so that it is aligned to a 4-byte boundary */
		int serializationBuffer[(SERIALIZATION_BUFFER_SIZE+3)/4];
		int serializationLength = SERIALIZATION_BUFFER_SIZE;

		/* serializationLength on input it is the maximum size.
		   on successful output it is the number of bytes used for the serialization */
		ShapeTypePlugin_serialize_to_cdr_buffer((char *)&serializationBuffer, &serializationLength, &shapeType);

		/* ShapeType_serialize_to_cdr_buffer() adds the 4-byte encapsulation header */
		/* Use DDS_OctetSeq_loan_contiguous() instead of DDS_OctetSeq_copy() to save one copy */
		DDS_OctetSeq_loan_contiguous(&(instance->buffer), ((DDS_Octet *)serializationBuffer),
			serializationLength, SERIALIZATION_BUFFER_SIZE);

		/* TODO: Use ShapeType_serialize_key */ 
		for (int i = 0; i < 16; ++i) {
			instance->key_hash[i] = (char)((count+i) % 256);
		}

        retcode = SerializedTypeKeyedDataWriter_write(
            SerializedTypeKeyed_writer, instance, &instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            fprintf(stderr, "write error %d\n", retcode);
        }
		DDS_OctetSeq_unloan(&(instance->buffer));

        NDDS_Utility_sleep(&send_period);
    }

    /*
    retcode = SerializedTypeKeyedDataWriter_unregister_instance(
        SerializedTypeKeyed_writer, instance, &instance_handle);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "unregister instance error %d\n", retcode);
    }
    */

    /* Delete data sample */
    retcode = SerializedTypeKeyedTypeSupport_delete_data_ex(instance, DDS_BOOLEAN_TRUE);
    if (retcode != DDS_RETCODE_OK) {
        fprintf(stderr, "SerializedTypeKeyedTypeSupport_delete_data error %d\n", retcode);
    }

    /* Cleanup and delete delete all entities */         
    return publisher_shutdown(participant);
}

int main(int argc, char *argv[])
{
    int domainId = 0;
    int sample_count = 0; /* infinite loop */

    if (argc >= 2) {
        domainId = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

    /* Uncomment this to turn on additional logging
    NDDS_Config_Logger_set_verbosity_by_category(
        NDDS_Config_Logger_get_instance(),
        NDDS_CONFIG_LOG_CATEGORY_API, 
        NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */

    return publisher_main(domainId, sample_count);
}

