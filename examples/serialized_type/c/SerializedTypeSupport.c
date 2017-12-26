
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from SerializedType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include "SerializedTypeSupport.h"
#include "SerializedTypePlugin.h"

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'SerializedType' support classes.

Note: Only the #defined classes get defined
*/

/* ----------------------------------------------------------------- */
/* DDSDataWriter
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataWriter, TData
*/

/* Requires */
#define TTYPENAME   SerializedTypeTYPENAME

/* Defines */
#define TDataWriter SerializedTypeDataWriter
#define TData       SerializedType

#include "dds_c/generic/dds_c_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

/* Extra functions */
DDS_ReturnCode_t SerializedTypeDataWriter_write_raw(
	SerializedTypeDataWriter* self,
	const unsigned char  data_key_hash[16],
	unsigned long        data_serialized_length,
	const unsigned char* data_serialized)
{
	SerializedType instance_data;
	SerializedType_initialize(&instance_data);
	memcpy(instance_data.key_hash, data_key_hash, KEY_HASH_LENGTH_16);
	DDS_OctetSeq_loan_contiguous(&instance_data.serialized_data, data_serialized,
		data_serialized_length, data_serialized_length);

	return SerializedTypeDataWriter_write(self, &instance_data, &DDS_HANDLE_NIL);
}


/* ----------------------------------------------------------------- */
/* DDSDataReader
*/

/**
<<IMPLEMENTATION >>

Defines:   TDataReader, TDataSeq, TData
*/

/* Requires */
#define TTYPENAME   SerializedTypeTYPENAME

/* Defines */
#define TDataReader SerializedTypeDataReader
#define TDataSeq    SerializedTypeSeq
#define TData       SerializedType

#include "dds_c/generic/dds_c_data_TDataReader.gen"

#undef TDataReader
#undef TDataSeq
#undef TData

#undef TTYPENAME

/* ----------------------------------------------------------------- */
/* TypeSupport

<<IMPLEMENTATION >>

Requires:  TTYPENAME,
TPlugin_new
TPlugin_delete
Defines:   TTypeSupport, TData, TDataReader, TDataWriter
*/

/* Requires */
#define TTYPENAME    SerializedTypeTYPENAME
#define TPlugin_new  SerializedTypePlugin_new
#define TPlugin_delete  SerializedTypePlugin_delete

/* Defines */
#define TTypeSupport SerializedTypeTypeSupport
#define TData        SerializedType
#define TDataReader  SerializedTypeDataReader
#define TDataWriter  SerializedTypeDataWriter
#define TGENERATE_SER_CODE
#define TGENERATE_TYPECODE

#include "dds_c/generic/dds_c_data_TTypeSupport.gen"

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

/*  
   The SerializedType needs to be registered passing the
   TypeCode of the underlying type. That will ensure the right
   type information is propagated on the wire.

   Note that SerializedTypeTypeSupport_register_type() is defined by
   the macros above. We can't avoid it the way the code is generated.
   That function should not be called. Instead the application should
   call TTypeSupport_register_type2()

   serialized_key_max_size should be set to 0 if the type is Unkeyed. Otherwise
   it shoud be set to the maximum size of the serialized key of the
   underlying type defined by the type_code paramameter.

   TODO: Would be nice to redefine SerializedTypeTypeSupport_register_type()
   to have the implementation below instead of having to add a new register_type2()
   function. At least we could find a way to prevent register_type() from being
   called...
*/
DDS_ReturnCode_t SerializedTypeTypeSupport_register_type2(
	DDS_DomainParticipant* participant,
	const char* type_name,
	struct DDS_TypeCode *type_code)
{
	struct PRESTypePlugin *presTypePlugin = NULL;
	DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;

	if (participant == NULL) {
		goto finError;
	}

	/* TODO pass the type_code */
	presTypePlugin = SerializedTypePlugin_new2(type_code);
	if (presTypePlugin == NULL) {
		goto finError;
	}

	retcode = DDS_DomainParticipant_register_type(
		participant,
		type_name,
		presTypePlugin,
		NULL /* registration_data */);
	if (retcode != DDS_RETCODE_OK) {
		goto finError;
	}
	return DDS_RETCODE_OK;

finError:
	if (presTypePlugin != NULL) {
		SerializedTypePlugin_delete(presTypePlugin);
	}

	return retcode;
}
