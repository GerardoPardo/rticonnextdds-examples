
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from SerializedTypeKeyed.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <string.h>

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

#define RTI_CDR_CURRENT_SUBMODULE RTI_CDR_SUBMODULE_MASK_STREAM

#include "SerializedTypeKeyedPlugin.h"

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

void 
SerializedTypeKeyedPluginSupport_print_data(
    const SerializedTypeKeyed *sample,
    const char *desc,
    unsigned int indent_level)
{
	unsigned int  i, row, col;
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

	RTICdrType_printVariableSizedInteger(sample->key_hash, "key_hash", indent_level + 1, KEY_HASH_LENGTH_16);
	RTICdrType_printPrimitivePreamble(&sample->buffer, "buffer", indent_level + 1);
		
	pByte     = DDS_OctetSeq_get_contiguous_bufferI(&sample->buffer);
	length = DDS_OctetSeq_get_length(&sample->buffer);

#define AS_CHAR(x) (isprint(x)?(x):'.')

#define BYTES_PER_ROW (16)

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
			if (col == (BYTES_PER_ROW/2 -1) ) { RTILog_debug(" "); }
		}

		RTILog_debug("   ");
		i = row * BYTES_PER_ROW;
		for (col = 0, i = row * BYTES_PER_ROW; col < BYTES_PER_ROW; ++col, ++i) {
			if (i >= length) {
				break;
			}
			RTILog_debug("%c", AS_CHAR(pByte[i]) );
			if (col == (BYTES_PER_ROW / 2 - 1)) { RTILog_debug(" "); }
		}
		if (i >= length) {
			break;
		}
	}
	RTILog_debug("\n");
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

    SerializedTypeKeyedPluginSupport_destroy_key_ex(key,RTI_TRUE);
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
    PRESTypePluginEndpointData epd = NULL;

    unsigned int serializedSampleMaxSize;

    unsigned int serializedKeyMaxSize;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */

    epd = PRESTypePluginDefaultEndpointData_new(
        participant_data,
        endpoint_info,
        (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
        SerializedTypeKeyedPluginSupport_create_data,
        (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
        SerializedTypeKeyedPluginSupport_destroy_data,
        (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
        SerializedTypeKeyedPluginSupport_create_key ,            
        (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
        SerializedTypeKeyedPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    } 
    serializedKeyMaxSize =  SerializedTypeKeyedPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

    if(!PRESTypePluginDefaultEndpointData_createMD5StreamWithInfo(
        epd,endpoint_info,serializedKeyMaxSize))  
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        serializedSampleMaxSize = SerializedTypeKeyedPlugin_get_serialized_sample_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);

        PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

        if (PRESTypePluginDefaultEndpointData_createWriterPool(
            epd,
            endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
            SerializedTypeKeyedPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            SerializedTypeKeyedPlugin_get_serialized_sample_size,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }

    return epd;    
}

void 
SerializedTypeKeyedPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{  

    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
SerializedTypeKeyedPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    SerializedTypeKeyed *sample,
    void *handle)
{

    SerializedTypeKeyed_finalize_optional_members(sample, RTI_TRUE);

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

RTIBool 
SerializedTypeKeyedPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    SerializedTypeKeyed *dst,
    const SerializedTypeKeyed *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return SerializedTypeKeyedPluginSupport_copy_data(dst,src);
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

    if(serialize_encapsulation) {
        if (!RTICdrStream_serializeAndSetCdrEncapsulation(stream , encapsulation_id)) {
            return RTI_FALSE;
        }

        position = RTICdrStream_resetAlignment(stream);
    }

    if(serialize_sample) {


		// The sample->buffer contains the serialized data, so we only need to copy that into
		// the CDR stream. Not the key_hash, nor the length of the data itself
		// The SerilizedType sample->buffer is always a contiguous buffer

		/*
		if (!RTICdrStream_serializePrimitiveArray(
		stream, (void*) sample->key_hash, (KEY_HASH_LENGTH_16), RTI_CDR_OCTET_TYPE)) {
		return RTI_FALSE;
		}
		*/

		DDS_Octet *buffer = DDS_OctetSeq_get_contiguous_bufferI(&sample->buffer);
		if ( buffer == NULL ) {
			return RTI_FALSE;
		}

		/* Use RTICdrStream_serializePrimitiveArray so that there is no additional length prepended */
		if (!RTICdrStream_serializePrimitiveArray(
				stream, (void*)buffer,
			DDS_OctetSeq_get_length(&sample->buffer),
			RTI_CDR_OCTET_TYPE)) {
			return RTI_FALSE;
		}
    }

    if(serialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return retval;
}

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
   
	if (deserialize_encapsulation) {

		if (!RTICdrStream_deserializeAndSetCdrEncapsulation(stream)) {
			return RTI_FALSE;
		}
		position = RTICdrStream_resetAlignment(stream);

		{
			/* TODO. This does not belong here. It should be pushed to the CDR module to that the
			   stream size is correct when this function is called. */
			   /* Based on the encapsulation_options we can adjust the size of the CDR stream to remove
				  the alignment padding. See http://issues.omg.org/browse/DDSXTY12-10 */
			DDS_UnsignedShort padding_size_mask = 0x0003;
			DDS_UnsignedShort padding_size;
			int adjustedBufferLength;

			padding_size = RTICdrStream_getEncapsulationOptions(stream) & padding_size_mask;
			adjustedBufferLength = RTICdrStream_getBufferLength(stream) - padding_size;
			RTICdrStream_setBufferLength(stream, adjustedBufferLength);
			if (padding_size != 0) {
				RTILog_debug("DEBUG: Adjusted Length to compensate for %d of padding\n", (int)padding_size);
			}
		}
	}
	else {
		/* The deserialization of the data as a serialized block only works if we are deserialing everything 
		   that remains in the CDR stream, therefore we require that deserialize_encapsulation == TRUE */
		return RTI_FALSE;
	}

    if(deserialize_sample) {
		/* TODO: We should pass the SampleInfo / Meta-Data to the deserialization. Having the
		KeyHash and publication_guid/handle can be very useful in deserialization.
		In this case it would allow the Key to be re-created.
		In the meantime we cannot set the key field correctly so we intialize to 0xFF
		*/
		memset(sample->key_hash, 0xFF, KEY_HASH_LENGTH_16);

		/* This only works if we are deserialing everything that remains in the CDR stream */
		int bytesLeftInStream = RTICdrStream_getRemainder(stream);
		DDS_Octet *cdrBufferPtr  = RTICdrStream_getCurrentPosition(stream);
		if (cdrBufferPtr == NULL) {
			goto fin;
		}

		SerializedTypeKeyed_initialize_ex(sample, RTI_FALSE, RTI_FALSE);
		if (!DDS_OctetSeq_from_array(&sample->buffer, cdrBufferPtr, bytesLeftInStream) ) {
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
    if (deserialize_encapsulation) {
        RTICdrStream_restoreAlignment(stream,position);
    }

    return RTI_TRUE;
}

RTIBool
SerializedTypeKeyedPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const SerializedTypeKeyed *sample)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    RTIBool result;

    if (length == NULL) {
        return RTI_FALSE;
    }

    epd._maxSizeSerializedSample =
    SerializedTypeKeyedPlugin_get_serialized_sample_max_size(
        NULL, RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 0);

    if (buffer == NULL) {
        *length = 
        SerializedTypeKeyedPlugin_get_serialized_sample_size(
            (PRESTypePluginEndpointData)&epd,
            RTI_TRUE,
            RTICdrEncapsulation_getNativeCdrEncapsulationId(),
            0,
            sample);

        if (*length == 0) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }    

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, *length);

    result = SerializedTypeKeyedPlugin_serialize(
        (PRESTypePluginEndpointData)&epd, sample, &stream, 
        RTI_TRUE, RTICdrEncapsulation_getNativeCdrEncapsulationId(), 
        RTI_TRUE, NULL);  

    *length = RTICdrStream_getCurrentPositionOffset(&stream);
    return result;     
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
	/* TODO */
	/* This function can only be implemented if we are using XCDR version 2 and
	   the type is either APPENDABLE or MUTABLE because those types are wrapped by
	   a length.
	   */

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
	/* TODO */
	/* This would need to use DynamicData and the TypeCode */
	return 1024;
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

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;

    if (endpoint_data) {} /* To avoid warnings */ 

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
    }

	/* TODO */
	/* Unclear what we can return here. May need to use the DynamicData */
	current_alignment += 4;

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return  current_alignment - initial_alignment;
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

    unsigned int initial_alignment = current_alignment;

    unsigned int encapsulation_size = current_alignment;
    struct PRESTypePluginDefaultEndpointData epd;   

    if (sample==NULL) {
        return 0;
    }
    if (endpoint_data == NULL) {
        endpoint_data = (PRESTypePluginEndpointData) &epd;
        PRESTypePluginDefaultEndpointData_setBaseAlignment(
            endpoint_data,
            current_alignment);        
    }

    if (include_encapsulation) {

        if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
            return 1;
        }
        RTICdrStream_getEncapsulationSize(encapsulation_size);
        encapsulation_size -= current_alignment;
        current_alignment = 0;
        initial_alignment = 0;
        PRESTypePluginDefaultEndpointData_setBaseAlignment(
            endpoint_data,
            current_alignment);
    }

	/* The length of teh serialized data is what is kept in the unerlying sequence */
	current_alignment += DDS_OctetSeq_get_length(&sample->buffer);

    if (include_encapsulation) {
        current_alignment += encapsulation_size;
    }
    return current_alignment - initial_alignment;
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
SerializedTypeKeyedPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_USER_KEY;
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
    return KEY_HASH_LENGTH_16;
}

unsigned int
SerializedTypeKeyedPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
	unsigned int initial_alignment = current_alignment;
	unsigned int encapsulation_size = current_alignment;

	if (endpoint_data) {} /* To avoid warnings */

	if (include_encapsulation) {

		if (!RTICdrEncapsulation_validEncapsulationId(encapsulation_id)) {
			return 1;
		}
		RTICdrStream_getEncapsulationSize(encapsulation_size);
		encapsulation_size -= current_alignment;
		current_alignment = 0;
		initial_alignment = 0;
	}

	current_alignment += KEY_HASH_LENGTH_16;

	if (include_encapsulation) {
		current_alignment += encapsulation_size;
	}

	return current_alignment - initial_alignment;
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
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *SerializedTypeKeyedPlugin_new(void) 
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
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    SerializedTypeKeyedPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    SerializedTypeKeyedPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    SerializedTypeKeyedPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    SerializedTypeKeyedPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    SerializedTypeKeyedPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    SerializedTypeKeyedPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    SerializedTypeKeyedPlugin_destroy_sample;

    plugin->serializeFnc =
    (PRESTypePluginSerializeFunction)
    SerializedTypeKeyedPlugin_serialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction)
    SerializedTypeKeyedPlugin_deserialize;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    SerializedTypeKeyedPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    SerializedTypeKeyedPlugin_get_serialized_sample_min_size;

    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    SerializedTypeKeyedPlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    SerializedTypeKeyedPlugin_return_sample;

    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    SerializedTypeKeyedPlugin_get_key_kind;

    plugin->getSerializedKeyMaxSizeFnc =   
    (PRESTypePluginGetSerializedKeyMaxSizeFunction)
    SerializedTypeKeyedPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
    (PRESTypePluginSerializeKeyFunction)
    SerializedTypeKeyedPlugin_serialize_key;
    plugin->deserializeKeyFnc =
    (PRESTypePluginDeserializeKeyFunction)
    SerializedTypeKeyedPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
    (PRESTypePluginDeserializeKeySampleFunction)
    SerializedTypeKeyedPlugin_deserialize_key_sample;

    plugin-> instanceToKeyHashFnc = 
    (PRESTypePluginInstanceToKeyHashFunction)
    SerializedTypeKeyedPlugin_instance_to_keyhash;
    plugin->serializedSampleToKeyHashFnc = 
    (PRESTypePluginSerializedSampleToKeyHashFunction)
    SerializedTypeKeyedPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
    (PRESTypePluginGetKeyFunction)
    SerializedTypeKeyedPlugin_get_key;
    plugin->returnKeyFnc =
    (PRESTypePluginReturnKeyFunction)
    SerializedTypeKeyedPlugin_return_key;

    plugin->instanceToKeyFnc =
    (PRESTypePluginInstanceToKeyFunction)
    SerializedTypeKeyedPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
    (PRESTypePluginKeyToInstanceFunction)
    SerializedTypeKeyedPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    plugin->typeCode =  (struct RTICdrTypeCode *)SerializedTypeKeyed_get_typecode();

    plugin->languageKind = PRES_TYPEPLUGIN_DDS_TYPE;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    SerializedTypeKeyedPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    SerializedTypeKeyedPlugin_return_buffer;
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    SerializedTypeKeyedPlugin_get_serialized_sample_size;

    plugin->endpointTypeName = SerializedTypeKeyedTYPENAME;

    return plugin;
}

void
SerializedTypeKeyedPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 
#undef RTI_CDR_CURRENT_SUBMODULE 
