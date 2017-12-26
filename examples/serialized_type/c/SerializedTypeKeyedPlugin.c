
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from SerializedTypeKeyed.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <string.h>
#include <stdio.h>

#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifndef osapi_type_h
#include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
#include "osapi/osapi_utility.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif

#ifndef cdr_type_object_h
#include "cdr/cdr_typeObject.h"
#endif

#ifndef cdr_encapsulation_h
#include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "dds_c/dds_c_typecode_impl.h"

/* The following need to made public. They are defined in TypeCodeSupport.c */
extern DDS_Boolean DDS_TypeCode_is_type_keyed(const DDS_TypeCode *type);

extern unsigned int DDS_TypeCode_get_type_serialized_key_max_size(
	DDS_TypeCode *type,
	RTIBool include_encapsulation,
	RTIEncapsulationId encapsulation_id,
	unsigned int current_alignment);


#define RTI_CDR_CURRENT_SUBMODULE RTI_CDR_SUBMODULE_MASK_STREAM

#include "SerializedTypeKeyedPlugin.h"


struct SerializedTypeKeyedPluginEndpointData {
	PRESTypePluginEndpointData defaultEndpointData;
	struct PRESTypePlugin *typePlugin;
};

#define GET_DEFAULT_ENDPOINT_DATA(epd) ( ((struct SerializedTypeKeyedPluginEndpointData *)epd)->defaultEndpointData  )
#define GET_TYPE_PLUGIN(epd) ( ((struct SerializedTypeKeyedPluginEndpointData *)epd)->typePlugin  )
#define GET_TYPE_CODE(epd) (  (struct DDS_TypeCode *)(GET_TYPE_PLUGIN(epd)->typeCode)  )

struct SerializedTypeKeyedPluginUserBuffer {
	int serializedKeyMaxSize;
};


/* TODO
   Note that:

   EndpointInfo contains PRESTypePlugin *
   PRESTypePlugin contains RTICdrTypeCode *

   PRESTypePluginEndpointData is defined as PRESTypePluginDefaultEndpointData for the plugin
   PRESTypePluginDefaultEndpointData contains PRESTypePluginEndpointInfo *
*/

/* ----------------------------------------------------------------------------
*  Type SerializedTypeKeyed
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

SerializedTypeKeyed*
SerializedTypeKeyedPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params) 
{
    SerializedTypeKeyed *sample = NULL;

    RTIOsapiHeap_allocateStructure(&(sample),SerializedTypeKeyed);
    if (sample == NULL) {
        return NULL;
    }

    if (!SerializedTypeKeyed_initialize_w_params(sample,alloc_params)) {
        RTIOsapiHeap_freeStructure(sample);
        sample=NULL;
    }
    return sample; 
} 

SerializedTypeKeyed *
SerializedTypeKeyedPluginSupport_create_data_ex(RTIBool allocate_pointers) 
{
    SerializedTypeKeyed *sample = NULL;

    RTIOsapiHeap_allocateStructure(&(sample),SerializedTypeKeyed);

    if(sample == NULL) {
        return NULL;
    }

    if (!SerializedTypeKeyed_initialize_ex(sample,allocate_pointers, RTI_TRUE)) {
        RTIOsapiHeap_freeStructure(sample);
        sample=NULL;
    }

    return sample; 
}

SerializedTypeKeyed *
SerializedTypeKeyedPluginSupport_create_data(void)
{
    return SerializedTypeKeyedPluginSupport_create_data_ex(RTI_TRUE);
}

void 
SerializedTypeKeyedPluginSupport_destroy_data_w_params(
    SerializedTypeKeyed *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params) {

    SerializedTypeKeyed_finalize_w_params(sample,dealloc_params);

    RTIOsapiHeap_freeStructure(sample);
    sample=NULL;
}

void 
SerializedTypeKeyedPluginSupport_destroy_data_ex(
    SerializedTypeKeyed *sample,RTIBool deallocate_pointers) {

    SerializedTypeKeyed_finalize_ex(sample,deallocate_pointers);

    RTIOsapiHeap_freeStructure(sample);
    sample=NULL;
}

void 
SerializedTypeKeyedPluginSupport_destroy_data(
    SerializedTypeKeyed *sample) {

    SerializedTypeKeyedPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}

RTIBool 
SerializedTypeKeyedPluginSupport_copy_data(
    SerializedTypeKeyed *dst,
    const SerializedTypeKeyed *src)
{
    return SerializedTypeKeyed_copy(dst,(const SerializedTypeKeyed*) src);
}

/* This should be used to print formatted data */
DDS_ReturnCode_t SerializedTypeKeyedTypeSupport_print_data2(
	const SerializedTypeKeyed *sample,
	FILE  *fp,
	const char *desc,
	unsigned int indent_level,
	struct DDS_TypeCode *type_code)

{
	DDS_ReturnCode_t retCode;

	if (fp == NULL) {
		fp = stdout;
	}

	if (desc != NULL) {
		fprintf(fp, "%*s", indent_level, "");
		fprintf(fp, "%s:\n", desc);
	}
	else {
		fprintf(fp, "\n");
	}

	struct DDS_DynamicData *data = DDS_DynamicData_new(	type_code, &DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);
	if (data == NULL) {
		return DDS_RETCODE_ERROR;
	}

	retCode = DDS_DynamicData_from_cdr_buffer(data, 
		DDS_OctetSeq_get_contiguous_bufferI(&sample->serialized_data), 
		DDS_OctetSeq_get_length(&sample->serialized_data));

	if (retCode != DDS_RETCODE_OK) {
		goto done;
	}
	retCode = DDS_DynamicDataFormatter_print(data, fp, indent_level+1);


done:
	DDS_DynamicData_delete(data);
	return retCode;
}

/*
 * Returns the number of bytes written or -1 in case of an error.
 */
int
SerializedTypePlugin_dumpBytes(const unsigned char *pByte, unsigned int length, int indent_level)
{
	unsigned int  i, row, col;
	const unsigned int BYTES_PER_ROW = 16;

	if (length == 0) {
		RTILog_debug("<empty>\n");
		return 0;
	}
	else if ( pByte == NULL )  {
		return -1;
	}

	/* Otherwise print */
#define AS_CHAR(x) (isprint(x)?(x):'.')

	for (row = 0; ; ++row) {
		i = row * BYTES_PER_ROW;
		RTILog_debug("\n");
		RTICdrType_printIndent(indent_level + 2);
		RTILog_debug("%04x  ", i);

		for (col = 0; col < BYTES_PER_ROW; ++col, ++i) {
			if (i < length) {
				RTILog_debug("%02x ", pByte[i]);
			}
			else {
				RTILog_debug("   ");
			}
			if (col == (BYTES_PER_ROW / 2 - 1)) { RTILog_debug(" "); }
		}

		RTILog_debug("   ");
		i = row * BYTES_PER_ROW;
		for (col = 0, i = row * BYTES_PER_ROW; col < BYTES_PER_ROW; ++col, ++i) {
			if (i >= length) {
				break;
			}
			RTILog_debug("%c", AS_CHAR(pByte[i]));
			if (col == (BYTES_PER_ROW / 2 - 1)) { RTILog_debug(" "); }
		}
		if (i >= length) {
			break;
		}
	}
	RTILog_debug("\n");

	return i;
}


void 
SerializedTypeKeyedPluginSupport_print_data(
    const SerializedTypeKeyed *sample,
    const char *desc,
    unsigned int indent_level)
{
	unsigned int  i;
	unsigned int  length;
	unsigned char *pByte;

	RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
        RTILog_debug("%s:\n", desc);
    } else {
        RTILog_debug("\n");
    }

    if (sample == NULL) {
        RTILog_debug("NULL\n");
        return;
    }

	RTICdrType_printPrimitivePreamble(&sample->key_hash, "key_hash", indent_level + 1);
	RTILog_debug("< ");
	for (i = 0; i < KEY_HASH_LENGTH_16; ++i) {
        RTILog_debug("%02x ", sample->key_hash[i]);
    }
	RTILog_debug(">\n");

	RTICdrType_printPrimitivePreamble(&sample->serialized_key, "serialized_key", indent_level + 1);
	pByte = DDS_OctetSeq_get_contiguous_bufferI(&sample->serialized_key);
	length = DDS_OctetSeq_get_length(&sample->serialized_key);
	SerializedTypePlugin_dumpBytes(pByte, length, indent_level);

	RTICdrType_printPrimitivePreamble(&sample->serialized_data, "serialized_data", indent_level + 1);
	pByte     = DDS_OctetSeq_get_contiguous_bufferI(&sample->serialized_data);
	length = DDS_OctetSeq_get_length(&sample->serialized_data);
	SerializedTypePlugin_dumpBytes(pByte, length, indent_level);
}

SerializedTypeKeyed *
SerializedTypeKeyedPluginSupport_create_key_ex(RTIBool allocate_pointers){
    SerializedTypeKeyed *key = NULL;

    RTIOsapiHeap_allocateStructure(&(key),SerializedTypeKeyedKeyHolder);

    SerializedTypeKeyed_initialize_ex(key,allocate_pointers, RTI_TRUE);

    return key;
}

SerializedTypeKeyed *
SerializedTypeKeyedPluginSupport_create_key(void)
{
    return  SerializedTypeKeyedPluginSupport_create_key_ex(RTI_TRUE);
}

void 
SerializedTypeKeyedPluginSupport_destroy_key_ex(
    SerializedTypeKeyedKeyHolder *key,RTIBool deallocate_pointers)
{
    SerializedTypeKeyed_finalize_ex(key,deallocate_pointers);

    RTIOsapiHeap_freeStructure(key);
}

void 
SerializedTypeKeyedPluginSupport_destroy_key(
    SerializedTypeKeyedKeyHolder *key) {

SerializedTypeKeyedPluginSupport_destroy_key_ex(key, RTI_TRUE);
}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData
SerializedTypeKeyedPlugin_on_participant_attached(
	void *registration_data,
	const struct PRESTypePluginParticipantInfo *participant_info,
	RTIBool top_level_registration,
	void *container_plugin_context,
	RTICdrTypeCode *type_code)
{
	if (registration_data) {} /* To avoid warnings */
	if (participant_info) {} /* To avoid warnings */
	if (top_level_registration) {} /* To avoid warnings */
	if (container_plugin_context) {} /* To avoid warnings */
	if (type_code) {} /* To avoid warnings */

	return PRESTypePluginDefaultParticipantData_new(participant_info);

}

void
SerializedTypeKeyedPlugin_on_participant_detached(
	PRESTypePluginParticipantData participant_data)
{
	PRESTypePluginDefaultParticipantData_delete(participant_data);
}

PRESTypePluginEndpointData
SerializedTypeKeyedPlugin_on_endpoint_attached(
	PRESTypePluginParticipantData participant_data,
	const struct PRESTypePluginEndpointInfo *endpoint_info,
	RTIBool top_level_registration,
	void *containerPluginContext)
{
	struct SerializedTypeKeyedPluginEndpointData *customEndpointData = NULL;
	unsigned int serializedSampleMaxSize;
	unsigned int serializedKeyMaxSize;

	if (top_level_registration) {} /* To avoid warnings */
	if (containerPluginContext) {} /* To avoid warnings */

	customEndpointData = (struct SerializedTypeKeyedPluginEndpointData *)malloc(sizeof(*customEndpointData));
	if (customEndpointData == NULL) {
		goto errorReturn;
	}

	customEndpointData->defaultEndpointData = PRESTypePluginDefaultEndpointData_new(
		participant_data,
		endpoint_info,
		(PRESTypePluginDefaultEndpointDataCreateSampleFunction)
		SerializedTypeKeyedPluginSupport_create_data,
		(PRESTypePluginDefaultEndpointDataDestroySampleFunction)
		SerializedTypeKeyedPluginSupport_destroy_data,
		(PRESTypePluginDefaultEndpointDataCreateKeyFunction)
		SerializedTypeKeyedPluginSupport_create_key,
		(PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
		SerializedTypeKeyedPluginSupport_destroy_key);

	if (customEndpointData->defaultEndpointData == NULL) {
		goto errorReturn;
	}

	customEndpointData->typePlugin = endpoint_info->typePlugin;
	serializedKeyMaxSize = SerializedTypeKeyedPlugin_get_serialized_key_max_size(
		customEndpointData, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, 0);

	if (!PRESTypePluginDefaultEndpointData_createMD5StreamWithInfo(
		customEndpointData->defaultEndpointData, endpoint_info, serializedKeyMaxSize))
	{
		goto errorReturn;
	}

	if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
		serializedSampleMaxSize = SerializedTypeKeyedPlugin_get_serialized_sample_max_size(
			customEndpointData, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, 0);

		PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(
			customEndpointData->defaultEndpointData, serializedSampleMaxSize);

		if (PRESTypePluginDefaultEndpointData_createWriterPool(
			customEndpointData->defaultEndpointData,
			endpoint_info,
			(PRESTypePluginGetSerializedSampleMaxSizeFunction)
			SerializedTypeKeyedPlugin_get_serialized_sample_max_size, 
			customEndpointData,
			(PRESTypePluginGetSerializedSampleSizeFunction)
			SerializedTypeKeyedPlugin_get_serialized_sample_size,
			customEndpointData) == RTI_FALSE) {

			goto errorReturn;
		}
	}

	return customEndpointData;

  errorReturn:
	if (customEndpointData != NULL) {
		if (customEndpointData->defaultEndpointData != NULL ) {
			PRESTypePluginDefaultEndpointData_delete(customEndpointData->defaultEndpointData);
		}
		free(customEndpointData);
	}
	return NULL;
}


void 
SerializedTypeKeyedPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  
    PRESTypePluginDefaultEndpointData_delete(GET_DEFAULT_ENDPOINT_DATA(endpoint_data));
}

void    
SerializedTypeKeyedPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    SerializedTypeKeyed *sample,
    void *handle)
{

    SerializedTypeKeyed_finalize_optional_members(sample, RTI_TRUE);

    PRESTypePluginDefaultEndpointData_returnSample(
		GET_DEFAULT_ENDPOINT_DATA(endpoint_data), sample, handle);
}

RTIBool 
SerializedTypeKeyedPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SerializedTypeKeyed *dst,
    const SerializedTypeKeyed *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return SerializedTypeKeyedPluginSupport_copy_data(dst, src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
SerializedTypeKeyedPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/**
 * This plugin can only be used as a top-level type. 
 * It expects the SerializedTypeKeyed to contain data serialized with its
 * encapsulation header already there.
 *
 * @param serialize_encapsulation normally it indicates whether encapsulaton should be serialized
 *    it also indicates whether we are serializing the data as a a top-level type (in the
 *	  RTPSSerializedPayload or we are serializing as part of a nested type).
      For SerializedTypeKeyedPlugin_serialize() it must be set to TRUE
 *
 * @param encapsulation_id the encapsulation identifier in case serialize_encapsulation==TRUE
 *    the implementation of SerializedTypeKeyedPlugin_serialize checks that the value of
 *    encapsulation_id matches the first two bytes in sample->key_hash
 */
RTIBool 
SerializedTypeKeyedPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const SerializedTypeKeyed *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool retval = RTI_TRUE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

	/* This plugin can only be used to publish the top-level DDS Topic-Type
	 * in which case serialize_encapsulation==TRUE. If that is not
	 * the case then it is an error.
	 */
	if (!serialize_encapsulation) {
		return RTI_FALSE;
	}

    position = RTICdrStream_resetAlignment(stream);

    if(serialize_sample) {
		/* The sample->serialized_data contains the serialized encapsulation followed by the serialized
		 * data, so we only need to copy that into
		 * the CDR stream. Not the key_hash, not the length of the data itself
		 * The SerializedType sample->serialized_data is always a contiguous buffer
		 */
		DDS_Octet *buffer = DDS_OctetSeq_get_contiguous_bufferI(&sample->serialized_data);
		if ( buffer == NULL ) {
			return RTI_FALSE;
		}

		/* The encapsulation_id appears in the sample->serialized_data as octet[2] using big-endian
		 * byte order
		 */
		if ( encapsulation_id != (buffer[0] * 256 + buffer[1]) ) {
			return RTI_FALSE;
		}

		/* Use RTICdrStream_serializePrimitiveArray so that there is no additional length prepended */
		if (!RTICdrStream_serializePrimitiveArray(
				stream, (void*)buffer,
			DDS_OctetSeq_get_length(&sample->serialized_data),
			RTI_CDR_OCTET_TYPE)) {
			return RTI_FALSE;
		}
    }

    RTICdrStream_restoreAlignment(stream ,position);

    return retval;
}


/**
	TODO. The code-block below does not belong here.
	It should be pushed to the CDR module, perhaps inside
	RTICdrStream_deserializeAndSetCdrEncapsulation so that the
	stream size is alredy correct when SerializedTypeKeyedPlugin_deserialize_sample
	is called. 

	Adjust the size of the CDR stream to not include the alignment
	padding. See http://issues.omg.org/browse/DDSXTY12-10

	@precondition The RTICdrStream *stream has alreadt processed
	              the encapsulation header and therefore has set the
				  encapsulation options returned by
				  RTICdrStream_getEncapsulationOptions()
*/
void
SerializedTypeKeyedPlugin_remove_padding_from_stream(struct RTICdrStream *stream)
{
	/* See http://issues.omg.org/browse/DDSXTY12-10 */
	DDS_UnsignedShort padding_size_mask = 0x0003;
	DDS_UnsignedShort padding_size;
	int adjustedBufferLength;

	padding_size = RTICdrStream_getEncapsulationOptions(stream) & padding_size_mask;
	adjustedBufferLength = RTICdrStream_getBufferLength(stream) - padding_size;
	RTICdrStream_setBufferLength(stream, adjustedBufferLength);
}

/**
* This plugin can only be used as a top-level type.
* It expects the RTICdrStream to contain the encapsulatio header
* followed by the serialized data itself
*/
RTIBool
SerializedTypeKeyedPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    SerializedTypeKeyed *sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample,
    void *endpoint_plugin_qos)
{
    char * position = NULL;
    RTIBool done = RTI_FALSE;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */
   
	/* This plugin can only be used to publish the top-level DDS Topic-Type
	 * in which case deserialize_encapsulation==TRUE. If that is not
	 * the case then it is an error.
	 */
	if (!deserialize_encapsulation) {
		return RTI_FALSE;
	}

	position = RTICdrStream_resetAlignment(stream);

    /* TODO. The call does not belong here. It should be pushed 
	 * inside RTICdrStream_deserializeAndSetCdrEncapsulation 
	 */
	SerializedTypeKeyedPlugin_remove_padding_from_stream(stream);

    if (deserialize_sample) {
		/* Note that sample->key_hash was already set by SerializedTypeKeyedPlugin_deserialize()
		   it is done there because SerializedTypeKeyedPlugin_deserialize_sample does not 
		   have access to the SampleInfo where that information is
		*/

		/* We do not set the serialized_key on deserialization */
		DDS_OctetSeq_set_length(&sample->serialized_key, 0);

		/* We copy everything that remains in the CDR stream */
		int bytesLeftInStream = RTICdrStream_getRemainder(stream);
		DDS_Octet *cdrBufferPtr  = RTICdrStream_getCurrentPosition(stream);
		if (cdrBufferPtr == NULL) {
			goto fin;
		}

		/* Do not call SerializedTypeKeyed_initialize_ex initialize here 
		   because it would override the key_hash field
		   SerializedTypeKeyed_initialize_ex(sample, RTI_FALSE, RTI_FALSE); 
		 */
		if (!DDS_OctetSeq_from_array(&sample->serialized_data, cdrBufferPtr, bytesLeftInStream) ) {
			goto fin;
		}
		RTICdrStream_incrementCurrentPosition(stream, bytesLeftInStream);
    }

    done = RTI_TRUE;

  fin:
    if ( (done != RTI_TRUE) && 
		 (RTICdrStream_getRemainder(stream) >= RTI_CDR_PARAMETER_HEADER_ALIGNMENT) ) {
        return RTI_FALSE;   
    }

	RTICdrStream_restoreAlignment(stream,position);

    return RTI_TRUE;
}

RTIBool
SerializedTypeKeyedPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const SerializedTypeKeyed *sample)
{
	/* TODO */
    return RTI_FALSE;     
}

RTIBool
SerializedTypeKeyedPlugin_deserialize_from_cdr_buffer(
    SerializedTypeKeyed *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    SerializedTypeKeyed_finalize_optional_members(sample, RTI_TRUE);
    return SerializedTypeKeyedPlugin_deserialize_sample( 
        NULL, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

DDS_ReturnCode_t
SerializedTypeKeyedPlugin_data_to_string(
    const SerializedTypeKeyed *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property)
{
    DDS_DynamicData *data = NULL;
    char *buffer = NULL;
    unsigned int length = 0;
    struct DDS_PrintFormat printFormat;
    DDS_ReturnCode_t retCode = DDS_RETCODE_ERROR;

    if (sample == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (str_size == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (property == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (!SerializedTypeKeyedPlugin_serialize_to_cdr_buffer(
        NULL, 
        &length, 
        sample)) {
        return DDS_RETCODE_ERROR;
    }

    RTIOsapiHeap_allocateBuffer(&buffer, length, RTI_OSAPI_ALIGNMENT_DEFAULT);
    if (buffer == NULL) {
        return DDS_RETCODE_ERROR;
    }

    if (!SerializedTypeKeyedPlugin_serialize_to_cdr_buffer(
        buffer, 
        &length, 
        sample)) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }

    data = DDS_DynamicData_new(
        SerializedTypeKeyed_get_typecode(), 
        &DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);
    if (data == NULL) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }

    retCode = DDS_DynamicData_from_cdr_buffer(data, buffer, length);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_PrintFormatProperty_to_print_format(
        property, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_DynamicDataFormatter_to_string_w_format(
        data, 
        str,
        str_size, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    RTIOsapiHeap_freeBuffer(buffer);
    DDS_DynamicData_delete(data);
    return DDS_RETCODE_OK;
}


/* 
  TODO: This function should be added to CstReaderCollator and exposed in the header file

  The sample parameter is pointing to  &( ((PRESCstReaderCollatorSample *)collatoreSample)->data)
  so we can use it to get to the &(collatoreSample->keyHash)
*/
void
PRESCstReaderCollator_copyKeyHash(DDS_Octet *outKeyHashPtr, SerializedTypeKeyed **sample) \
{
	size_t dataOffset = offsetof(struct PRESCstReaderCollatorSample, data);
	struct PRESCstReaderCollatorSample *collatorSample = (struct PRESCstReaderCollatorSample *) ((char *)sample - dataOffset);

	memcpy(outKeyHashPtr, &(collatorSample->keyHash.value), KEY_HASH_LENGTH_16);
}

RTIBool 
SerializedTypeKeyedPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    SerializedTypeKeyed **sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,   
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos)
{

    RTIBool result;
    const char *METHOD_NAME = "SerializedTypeKeyedPlugin_deserialize";

	PRESCstReaderCollator_copyKeyHash((*sample)->key_hash, sample);

    if (drop_sample) {} /* To avoid warnings */

    stream->_xTypesState.unassignable = RTI_FALSE;
    result= SerializedTypeKeyedPlugin_deserialize_sample( 
        endpoint_data, (sample != NULL)?*sample:NULL,
        stream, deserialize_encapsulation, deserialize_sample, 
        endpoint_plugin_qos);
 
	if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }
    if (!result && stream->_xTypesState.unassignable ) {

        RTICdrLog_exception(
            METHOD_NAME, 
            &RTI_CDR_LOG_UNASSIGNABLE_SAMPLE_OF_TYPE_s, 
            "SerializedTypeKeyed");
    }

    return result;
}

RTIBool SerializedTypeKeyedPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream,   
    RTIBool skip_encapsulation,
    RTIBool skip_sample, 
    void *endpoint_plugin_qos)
{
	/* Advance to the end of the stream */
	int bytesLeftInStream = RTICdrStream_getRemainder(stream);
	RTICdrStream_incrementCurrentPosition(stream, bytesLeftInStream);

    return RTI_FALSE;
}

unsigned int 
SerializedTypeKeyedPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
	return DDS_TypeCode_get_type_serialized_max_size(
		GET_TYPE_CODE(endpoint_data),
	    include_encapsulation,
		encapsulation_id, current_alignment);
}

unsigned int 
SerializedTypeKeyedPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = SerializedTypeKeyedPlugin_get_serialized_sample_max_size_ex(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int 
SerializedTypeKeyedPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
	return DDS_TypeCode_get_type_serialized_min_size(
		GET_TYPE_CODE(endpoint_data),
		include_encapsulation, encapsulation_id,
		current_alignment, DDS_BOOLEAN_FALSE, DDS_BOOLEAN_FALSE);
}

/* Returns the size of the sample in its serialized form (in bytes).
* It can also be an estimation in excess of the real buffer needed 
* during a call to the serialize() function.
* The value reported does not have to include the space for the
* encapsulation flags.
*/
unsigned int
SerializedTypeKeyedPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const SerializedTypeKeyed * sample) 
{
	/* TODO: review alignments */

	int encapsulation_size = 0;
	if (include_encapsulation) {
		if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
			return 1;
		}
		RTICdrStream_getEncapsulationSize(encapsulation_size);
	}

	/* The length of the serialized data is what is kept in the unerlying sequence */
	return  encapsulation_size + DDS_OctetSeq_get_length(&sample->serialized_data);
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
SerializedTypeKeyedPlugin_get_key_kind_USER_KEY(void)
{
    return PRES_TYPEPLUGIN_USER_KEY;
}

PRESTypePluginKeyKind
SerializedTypeKeyedPlugin_get_key_kind_NO_KEY(void)
{
	return PRES_TYPEPLUGIN_NO_KEY;
}

RTIBool 
SerializedTypeKeyedPlugin_serialize_key_to_cdr_buffer(
	char * buffer,
	unsigned int *length,
	const void *typed_sample, /* This should point to a sample of the type expected by serializeKeyFcn */
	PRESTypePluginSerializeKeyFunction serializeKeyFnc )
{
	RTIBool returnValue;
	struct RTICdrStream stream;
	RTICdrStream_init(&stream);
	RTICdrStream_set(&stream, (char *)buffer, *length);

	returnValue = serializeKeyFnc(NULL, typed_sample, &stream, RTI_FALSE, RTI_CDR_ENCAPSULATION_ID_CDR_BE, RTI_TRUE, NULL);
	if (returnValue) {
		*length = RTICdrStream_getCurrentPositionOffset(&stream);
	}

	return returnValue;
}

RTIBool 
SerializedTypeKeyedPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const SerializedTypeKeyed *sample, 
    struct RTICdrStream *stream,    
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos)
{
	/* TODO this is called when a sample is registered on the writer side */
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_key) {
		if (!RTICdrStream_checkSize(stream, KEY_HASH_LENGTH_16)) {
			return RTI_FALSE;
		}
		RTIOsapiMemory_copy(RTICdrStream_getCurrentPosition(stream), sample->key_hash, KEY_HASH_LENGTH_16);
		RTICdrStream_incrementCurrentPosition(stream, KEY_HASH_LENGTH_16);
    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool SerializedTypeKeyedPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    SerializedTypeKeyed *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
	/* TODO */
    char * position = NULL;

    if (endpoint_data) {} /* To avoid warnings */
    if (endpoint_plugin_qos) {} /* To avoid warnings */

    if(deserialize_encapsulation) {

        if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }
    if (deserialize_key) {

        if (!RTICdrStream_deserializePrimitiveArray(
            stream, (void*) sample->key_hash, (KEY_HASH_LENGTH_16), RTI_CDR_OCTET_TYPE)) {
            return RTI_FALSE;
        }

    }

    if(deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;

}

RTIBool SerializedTypeKeyedPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    SerializedTypeKeyed **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
	/* TODO */
    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */
    stream->_xTypesState.unassignable = RTI_FALSE;
    result= SerializedTypeKeyedPlugin_deserialize_key_sample(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
    if (result) {
        if (stream->_xTypesState.unassignable) {
            result = RTI_FALSE;
        }
    }

    return result;    

}

unsigned int
SerializedTypeKeyedPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
	return SerializedTypeKeyedPlugin_get_serialized_key_max_size(
		endpoint_data, include_encapsulation, encapsulation_id, current_alignment);
}

unsigned int
SerializedTypeKeyedPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{	
	return DDS_TypeCode_get_type_serialized_key_max_size(
		    GET_TYPE_CODE(endpoint_data),
		    include_encapsulation,
			encapsulation_id, current_alignment);
}

RTIBool 
SerializedTypeKeyedPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SerializedTypeKeyed *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos)
{
	/* TODO */
	/* This would need to use DynamicData */
	return RTI_FALSE;
}

RTIBool 
SerializedTypeKeyedPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    SerializedTypeKeyedKeyHolder *dst, 
    const SerializedTypeKeyed *src)
{
	/* TODO */
    if (endpoint_data) {} /* To avoid warnings */   

    if (!RTICdrType_copyArray(
        dst->key_hash ,src->key_hash,(KEY_HASH_LENGTH_16), RTI_CDR_OCTET_SIZE)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool 
SerializedTypeKeyedPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    SerializedTypeKeyed *dst, const
    SerializedTypeKeyedKeyHolder *src)
{
	/* TODO */
    if (endpoint_data) {} /* To avoid warnings */   
    if (!RTICdrType_copyArray(
        dst->key_hash ,src->key_hash,(KEY_HASH_LENGTH_16), RTI_CDR_OCTET_SIZE)) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool 
SerializedTypeKeyedPlugin_instance_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    DDS_KeyHash_t *keyhash,
    const SerializedTypeKeyed *instance)
{
	if (endpoint_data) {} /* To avoid warnings */

	RTIOsapiMemory_copy(
		keyhash->value, instance->key_hash, KEY_HASH_LENGTH_16);

    return RTI_TRUE;
}

RTIBool 
SerializedTypeKeyedPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
	/* TODO */
	/* This would need to use DynamicData */
 
    return RTI_FALSE;
}

/* ------------------------------------------------------------------------
* Sample and Key Management
*   (these used to be #defined to the underlying presentation fucntion)
* ------------------------------------------------------------------------ */
void *
SerializedTypeKeyedPlugin_get_sample(
	PRESTypePluginEndpointData endpointData,
	void **handle /* out */)
{
	return PRESTypePluginDefaultEndpointData_getSample(
				GET_DEFAULT_ENDPOINT_DATA(endpointData),
				handle);
}

RTIBool
SerializedTypeKeyedPlugin_get_buffer(
	PRESTypePluginEndpointData endpointData,
	struct REDABuffer *buffer,
	RTIEncapsulationId encapsulationId,
	const void * user_data)
{
	return PRESTypePluginDefaultEndpointData_getBuffer(
				GET_DEFAULT_ENDPOINT_DATA(endpointData),
				buffer,
				encapsulationId,
				user_data);
}

void
SerializedTypeKeyedPlugin_return_buffer(
	PRESTypePluginEndpointData endpointData,
	struct REDABuffer *buffer,
	RTIEncapsulationId encapsulationId)
{
	PRESTypePluginDefaultEndpointData_returnBuffer(
		GET_DEFAULT_ENDPOINT_DATA(endpointData),
		buffer,
		encapsulationId);
}

void *
SerializedTypeKeyedPlugin_get_key(
	PRESTypePluginEndpointData endpointData,
	void **handle /* out */)
{
	return PRESTypePluginDefaultEndpointData_getKey(
				GET_DEFAULT_ENDPOINT_DATA(endpointData),
				handle);
}

void
SerializedTypeKeyedPlugin_return_key(
	PRESTypePluginEndpointData endpointData,
	void *key, void *handle)
{
	PRESTypePluginDefaultEndpointData_returnKey(
		GET_DEFAULT_ENDPOINT_DATA(endpointData),
		key,
		handle);
}

void *
SerializedTypeKeyedPlugin_create_sample(
	PRESTypePluginEndpointData endpointData)
{
	return PRESTypePluginDefaultEndpointData_createSample(
				GET_DEFAULT_ENDPOINT_DATA(endpointData));
}

void
SerializedTypeKeyedPlugin_destroy_sample(
	PRESTypePluginEndpointData endpointData,
	void *sample)
{
	PRESTypePluginDefaultEndpointData_deleteSample(
		GET_DEFAULT_ENDPOINT_DATA(endpointData),
		sample);
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
/* This function should not be used. Use SerializedTypeKeyedPlugin_new2() */
struct PRESTypePlugin *SerializedTypeKeyedPlugin_new(void)
{
	return NULL;
}


struct PRESTypePlugin *SerializedTypeKeyedPlugin_new2( struct DDS_TypeCode *type_code, int serialized_key_max_size ) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =	(PRESTypePluginOnParticipantAttachedCallback)
		SerializedTypeKeyedPlugin_on_participant_attached;
    plugin->onParticipantDetached =	(PRESTypePluginOnParticipantDetachedCallback)
		SerializedTypeKeyedPlugin_on_participant_detached;
    plugin->onEndpointAttached =    (PRESTypePluginOnEndpointAttachedCallback)
		SerializedTypeKeyedPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =    (PRESTypePluginOnEndpointDetachedCallback)
		SerializedTypeKeyedPlugin_on_endpoint_detached;

    plugin->copySampleFnc =    (PRESTypePluginCopySampleFunction)
		SerializedTypeKeyedPlugin_copy_sample;
    plugin->createSampleFnc =    (PRESTypePluginCreateSampleFunction)
		SerializedTypeKeyedPlugin_create_sample;
    plugin->destroySampleFnc =    (PRESTypePluginDestroySampleFunction)
		SerializedTypeKeyedPlugin_destroy_sample;

    plugin->serializeFnc =    (PRESTypePluginSerializeFunction)
		SerializedTypeKeyedPlugin_serialize;
    plugin->deserializeFnc =  (PRESTypePluginDeserializeFunction)
		SerializedTypeKeyedPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =  (PRESTypePluginGetSerializedSampleMaxSizeFunction)
		SerializedTypeKeyedPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =  (PRESTypePluginGetSerializedSampleMinSizeFunction)
		SerializedTypeKeyedPlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =    (PRESTypePluginGetSampleFunction)
		SerializedTypeKeyedPlugin_get_sample;
    plugin->returnSampleFnc = (PRESTypePluginReturnSampleFunction)
		SerializedTypeKeyedPlugin_return_sample;

	if ( (type_code != NULL) && DDS_TypeCode_is_type_keyed(type_code) ) {
		plugin->getKeyKindFnc = (PRESTypePluginGetKeyKindFunction)
			SerializedTypeKeyedPlugin_get_key_kind_USER_KEY;
	}
	else {
		plugin->getKeyKindFnc = (PRESTypePluginGetKeyKindFunction)
			SerializedTypeKeyedPlugin_get_key_kind_NO_KEY;
	}

    plugin->getSerializedKeyMaxSizeFnc = (PRESTypePluginGetSerializedKeyMaxSizeFunction)
		SerializedTypeKeyedPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =    (PRESTypePluginSerializeKeyFunction)
		SerializedTypeKeyedPlugin_serialize_key;
    plugin->deserializeKeyFnc =  (PRESTypePluginDeserializeKeyFunction)
		SerializedTypeKeyedPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc = (PRESTypePluginDeserializeKeySampleFunction)
		SerializedTypeKeyedPlugin_deserialize_key_sample;

    plugin-> instanceToKeyHashFnc = (PRESTypePluginInstanceToKeyHashFunction)
		SerializedTypeKeyedPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = (PRESTypePluginSerializedSampleToKeyHashFunction)
		SerializedTypeKeyedPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =      (PRESTypePluginGetKeyFunction)
		SerializedTypeKeyedPlugin_get_key;
    plugin->returnKeyFnc =   (PRESTypePluginReturnKeyFunction)
		SerializedTypeKeyedPlugin_return_key;

    plugin->instanceToKeyFnc =   (PRESTypePluginInstanceToKeyFunction)
		SerializedTypeKeyedPlugin_instance_to_key;
    plugin->keyToInstanceFnc =   (PRESTypePluginKeyToInstanceFunction)
		SerializedTypeKeyedPlugin_key_to_instance;

    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
	plugin->typeCode = (struct RTICdrTypeCode *)type_code;  /*  SerializedTypeKeyed_get_typecode(); */

    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE;

    /* Serialized buffer */
    plugin->getBuffer =     (PRESTypePluginGetBufferFunction)
		SerializedTypeKeyedPlugin_get_buffer;
    plugin->returnBuffer =   (PRESTypePluginReturnBufferFunction)
		SerializedTypeKeyedPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =    (PRESTypePluginGetSerializedSampleSizeFunction)
		SerializedTypeKeyedPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = SerializedTypeKeyedTYPENAME;

	struct SerializedTypeKeyedPluginUserBuffer *pluginUserBuffer;
	RTIOsapiHeap_allocateStructure(&pluginUserBuffer, struct SerializedTypeKeyedPluginUserBuffer);
	pluginUserBuffer->serializedKeyMaxSize = serialized_key_max_size;
	plugin->_userBuffer = (PRESWord *)pluginUserBuffer;

    return plugin;
}

void
SerializedTypeKeyedPlugin_delete(struct PRESTypePlugin *plugin)
{
	RTIOsapiHeap_freeStructure(plugin->_userBuffer);
	RTIOsapiHeap_freeStructure(plugin);
}
#undef RTI_CDR_CURRENT_SUBMODULE 
