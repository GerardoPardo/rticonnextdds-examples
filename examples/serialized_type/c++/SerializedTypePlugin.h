

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from SerializedType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef SerializedTypePlugin_1419555957_h
#define SerializedTypePlugin_1419555957_h

#include "SerializedType.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

extern "C" {

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct SerializedType
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct SerializedType)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * SerializedType must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct SerializedType.
    */
    typedef  class SerializedType SerializedTypeKeyHolder;

    #define SerializedTypePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
    #define SerializedTypePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define SerializedTypePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

    #define SerializedTypePlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define SerializedTypePlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define SerializedTypePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define SerializedTypePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern SerializedType*
    SerializedTypePluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern SerializedType*
    SerializedTypePluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern SerializedType*
    SerializedTypePluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePluginSupport_copy_data(
        SerializedType *out,
        const SerializedType *in);

    NDDSUSERDllExport extern void 
    SerializedTypePluginSupport_destroy_data_w_params(
        SerializedType *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    SerializedTypePluginSupport_destroy_data_ex(
        SerializedType *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    SerializedTypePluginSupport_destroy_data(
        SerializedType *sample);

    NDDSUSERDllExport extern void 
    SerializedTypePluginSupport_print_data(
        const SerializedType *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern SerializedType*
    SerializedTypePluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern SerializedType*
    SerializedTypePluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    SerializedTypePluginSupport_destroy_key_ex(
        SerializedTypeKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    SerializedTypePluginSupport_destroy_key(
        SerializedTypeKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    SerializedTypePlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    SerializedTypePlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    SerializedTypePlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    SerializedTypePlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    SerializedTypePlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        SerializedType *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        SerializedType *out,
        const SerializedType *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePlugin_serialize(
        PRESTypePluginEndpointData endpoint_data,
        const SerializedType *sample,
        struct RTICdrStream *stream, 
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePlugin_deserialize_sample(
        PRESTypePluginEndpointData endpoint_data,
        SerializedType *sample, 
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    SerializedTypePlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const SerializedType *sample); 

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        SerializedType **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    SerializedTypePlugin_deserialize_from_cdr_buffer(
        SerializedType *sample,
        const char * buffer,
        unsigned int length);    
    NDDSUSERDllExport extern DDS_ReturnCode_t
    SerializedTypePlugin_data_to_string(
        const SerializedType *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    

    NDDSUSERDllExport extern RTIBool
    SerializedTypePlugin_skip(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        RTIBool skip_encapsulation,  
        RTIBool skip_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern unsigned int 
    SerializedTypePlugin_get_serialized_sample_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);    

    NDDSUSERDllExport extern unsigned int 
    SerializedTypePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    SerializedTypePlugin_get_serialized_sample_min_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int
    SerializedTypePlugin_get_serialized_sample_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        const SerializedType * sample);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    SerializedTypePlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    SerializedTypePlugin_get_serialized_key_max_size_ex(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool * overflow,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    SerializedTypePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePlugin_serialize_key(
        PRESTypePluginEndpointData endpoint_data,
        const SerializedType *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePlugin_deserialize_key_sample(
        PRESTypePluginEndpointData endpoint_data,
        SerializedType * sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        SerializedType ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    SerializedTypePlugin_serialized_sample_to_key(
        PRESTypePluginEndpointData endpoint_data,
        SerializedType *sample,
        struct RTICdrStream *stream, 
        RTIBool deserialize_encapsulation,  
        RTIBool deserialize_key, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        SerializedTypeKeyHolder *key, 
        const SerializedType *instance);

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        SerializedType *instance, 
        const SerializedTypeKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePlugin_instance_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        DDS_KeyHash_t *keyhash,
        const SerializedType *instance);

    NDDSUSERDllExport extern RTIBool 
    SerializedTypePlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    SerializedTypePlugin_new(void);

    NDDSUSERDllExport extern struct PRESTypePlugin*
    SerializedTypePlugin_new2(struct DDS_TypeCode *type_code);

    NDDSUSERDllExport extern void
    SerializedTypePlugin_delete(struct PRESTypePlugin *);

}

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

/* TODO this is needed in order to be able to navigate from
   PRESCstReaderCollatorSample::data to PRESCstReaderCollatorSample::keyHash 
   
   Rather than copying the declaration here which is nt maintainable we should
   expose the function to get to the keyHash from the data.

   This structure is defined in CstReaderCollator.c
*/
#define PRES_READER_QUEUE_MAX_VIRTUAL_WRITERS_PER_SAMPLE (5)
struct PRESCstReaderCollatorSampleVirtualWriterEntry {
    struct PRESReaderQueueVirtualWriter * virtualWriter;
    struct PRESCstReaderCollatorInstanceVirtualWriterEntry * instanceVirtualWriter;
    struct REDASequenceNumber virtualSn;
};

struct PRESCstReaderCollatorSample {
    struct REDAInlineListNode node;
    struct PRESCstReaderCollatorEntry * entry; /* Entry containing the sample */
    struct REDASequenceNumber vSn; /* Sample virtual sn */
    struct REDASequenceNumber originalVirtualSn; /* Original virtual sn */
    struct MIGRtpsGuid originalVirtualWriterGuid; /* Every sample from the same entry has the same virtual GUID */
    void * data; /* Deserialize data or Deserialize key */
    void * dataHandle;
    RTIBool hasValidData;
    RTIBool hasValidKey;
    RTIBool invalidSample; /* It can be RTI_TRUE only for batch configurations */
    struct RTINtpTime sourceTimestamp;
    RTIBool hasSourceTimestamp;
    int loanCount;
    RTIBool isTaken;
    /* The relatedOriginalVirtualWriterGuid and relatedOriginalVirtualSn
    together form the sample identity of a related sample. Example
    for related sample: In request reply use case when sending a reply sample
    the associated request will be the related sample */
    struct MIGRtpsGuid relatedOriginalVirtualWriterGuid;
    struct REDASequenceNumber relatedOriginalVirtualSn;
    /* A sample is considered processed by an application the first time a loan is returned */
    RTIBool processedByApplication;
    /* List of virtual writers that have tried to commit this sample */
    /* We support up to 5 remote virtual writers */
    /* If a sixth remote virtual writer try to commit the sample, it will be considered
    as processed by the application for that remote writer */
    int numberOfVirtualWriters;
    struct PRESCstReaderCollatorSampleVirtualWriterEntry virtualWriters[PRES_READER_QUEUE_MAX_VIRTUAL_WRITERS_PER_SAMPLE];
    PRESSampleStateKind sampleState;
    /*
    * This state is for content filters. It tells us whether the sample
    * passed the filter, failed the filter or has not yet been evaluated*
    * against the filter
    */
    int filterState;

    /*
    * Used to keep track of whether a sample's queryConditionFilterState
    * is valid for each of the query conditions. A filter state is not valid
    * if the sample hasn't been evaluated against a query condition yet
    */
    RTI_UINT32 queryConditionFilterStateValidity;

    /*
    * Used to keep track of whether a sample passed or failed each of the
    * query conditions
    */
    RTI_UINT32 queryConditionFilterState;
    /* list of filters for which this sample meets filter criteria */
    struct REDAInlineList matchedFilters;
    RTI_UINT32 serializedDataLength;
    char *serializedDataPosition;
    struct MIGRtpsKeyHash keyHash;
    PRESSampleFlag sampleFlag;
    struct MIGRtpsGuid relatedReaderGuid;
    struct MIGRtpsGuid relatedSourceGuid;
    struct MIGRtpsGuid sourceGuid;

    PRESSampleHash sampleHash;
};

#endif /* SerializedTypePlugin_1419555957_h */

