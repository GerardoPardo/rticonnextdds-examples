/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from SerializedType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "SerializedType.h"

/* ========================================================================= */
const char *SerializedTypeTYPENAME = "SerializedType";

DDS_TypeCode* SerializedType_get_typecode() 
{
	static RTIBool is_initialized = RTI_FALSE;

	static DDS_TypeCode SerializedType_g_tc_key_hash_array = DDS_INITIALIZE_ARRAY_TYPECODE(1, (KEY_HASH_LENGTH_16), NULL, NULL);
	static DDS_TypeCode SerializedType_g_tc_serialized_key_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((100), NULL);
	static DDS_TypeCode SerializedType_g_tc_serialized_data_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE((100), NULL);
	static DDS_TypeCode_Member SerializedType_g_tc_members[3] =
	{

		{
			(char *)"key_hash",/* Member name */
			{
				0,/* Representation ID */
				DDS_BOOLEAN_FALSE,/* Is a pointer? */
				-1, /* Bitfield bits */
				NULL/* Member type code is assigned later */
			},
		0, /* Ignored */
		0, /* Ignored */
		0, /* Ignored */
		NULL, /* Ignored */
		RTI_CDR_KEY_MEMBER , /* Is a key? */
		DDS_PUBLIC_MEMBER,/* Member visibility */
		1,
		NULL/* Ignored */
		},
		{
			(char *)"serialized_key",/* Member name */
			{
				1,/* Representation ID */
				DDS_BOOLEAN_FALSE,/* Is a pointer? */
				-1, /* Bitfield bits */
				NULL/* Member type code is assigned later */
			},
		0, /* Ignored */
		0, /* Ignored */
		0, /* Ignored */
		NULL, /* Ignored */
		RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
		DDS_PUBLIC_MEMBER,/* Member visibility */
		1,
		NULL/* Ignored */
		},
		{
			(char *)"serialized_data",/* Member name */
			{
				2,/* Representation ID */
				DDS_BOOLEAN_FALSE,/* Is a pointer? */
				-1, /* Bitfield bits */
				NULL/* Member type code is assigned later */
			},
		0, /* Ignored */
		0, /* Ignored */
		0, /* Ignored */
		NULL, /* Ignored */
		RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
		DDS_PUBLIC_MEMBER,/* Member visibility */
		1,
		NULL/* Ignored */
		}
	};

	static DDS_TypeCode SerializedType_g_tc =
	{ {
			DDS_TK_STRUCT,/* Kind */
			DDS_BOOLEAN_FALSE, /* Ignored */
			-1, /*Ignored*/
			(char *)"SerializedType", /* Name */
			NULL, /* Ignored */
			0, /* Ignored */
			0, /* Ignored */
			NULL, /* Ignored */
			3, /* Number of members */
			SerializedType_g_tc_members, /* Members */
			DDS_VM_NONE  /* Ignored */
		} }; /* Type code for SerializedType*/

	if (is_initialized) {
		return &SerializedType_g_tc;
	}

	SerializedType_g_tc_key_hash_array._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

	SerializedType_g_tc_serialized_key_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

	SerializedType_g_tc_serialized_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;

	SerializedType_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& SerializedType_g_tc_key_hash_array;
	SerializedType_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& SerializedType_g_tc_serialized_key_sequence;
	SerializedType_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& SerializedType_g_tc_serialized_data_sequence;

	is_initialized = RTI_TRUE;

	return &SerializedType_g_tc;
}

RTIBool SerializedType_initialize(
    SerializedType* sample) {
    return SerializedType_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool SerializedType_initialize_ex(
    SerializedType* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return SerializedType_initialize_w_params(
        sample,&allocParams);

}

RTIBool SerializedType_initialize_w_params(
    SerializedType* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{
    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

	memset(sample->key_hash, 0xFF, KEY_HASH_LENGTH_16);
	DDS_OctetSeq_initialize(&sample->serialized_key);
	DDS_OctetSeq_initialize(&sample->serialized_data);

	return RTI_TRUE;
}

void SerializedType_finalize(
    SerializedType* sample)
{
    SerializedType_finalize_ex(sample,RTI_TRUE);
}

void SerializedType_finalize_ex(
    SerializedType* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    SerializedType_finalize_w_params(
        sample,&deallocParams);
}

void SerializedType_finalize_w_params(
    SerializedType* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{
    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

	DDS_OctetSeq_finalize(&sample->serialized_key);
	DDS_OctetSeq_finalize(&sample->serialized_data);
}

void SerializedType_finalize_optional_members(
    SerializedType* sample, RTIBool deletePointers)
{
	return;
}

RTIBool SerializedType_copy(
    SerializedType* dst,
    const SerializedType* src)
{
    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

	// Copy key hash
	RTIOsapiMemory_copy(dst->key_hash, src->key_hash, KEY_HASH_LENGTH_16);

	// Copy automatically resizes the destination sequence
	if (!DDS_OctetSeq_copy(&dst->serialized_key, &src->serialized_key)) {
		return RTI_FALSE;
	}
	if (!DDS_OctetSeq_copy(&dst->serialized_data, &src->serialized_data)) {
		return RTI_FALSE;
	}
	return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'SerializedType' sequence class.
*/
#define T SerializedType
#define TSeq SerializedTypeSeq

#define T_initialize_w_params SerializedType_initialize_w_params

#define T_finalize_w_params   SerializedType_finalize_w_params
#define T_copy       SerializedType_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

