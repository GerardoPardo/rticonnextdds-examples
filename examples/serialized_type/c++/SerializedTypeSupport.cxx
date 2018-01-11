
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from SerializedType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include "SerializedTypeSupport.h"
#include "SerializedTypePlugin.h"

#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif        

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

#include "dds_cpp/generic/dds_cpp_data_TDataWriter.gen"

#undef TDataWriter
#undef TData

#undef TTYPENAME

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

#include "dds_cpp/generic/dds_cpp_data_TDataReader.gen"

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

#include "dds_cpp/generic/dds_cpp_data_TTypeSupport.gen"


DDS_ReturnCode_t SerializedTypeTypeSupport::register_type2(DDSDomainParticipant* participant, char const* type_name, DDS_TypeCode* type_code) {
	return SerializedTypeTypeSupport_register_type2(participant, type_name, type_code);
}


SerializedTypeTypeSupport::SerializedTypeTypeSupport(bool osrf) {

}

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
	DDSDomainParticipant* participant,
	const char* type_name,
	struct DDS_TypeCode *type_code)
{
	DDSTypeSupport* ddsDataType = NULL;
	struct PRESTypePlugin *presTypePlugin = NULL;
	DDS_ReturnCode_t result = DDS_RETCODE_ERROR;
	DDS_Boolean deleteDataType = DDS_BOOLEAN_FALSE;
    RTIBool alreadyRegistered = RTI_FALSE;

	if (participant == NULL) {
		goto done;
	}

	/* TODO pass the type_code */
	presTypePlugin = SerializedTypePlugin_new2(type_code);
	if (presTypePlugin == NULL) {
		goto done;
	}

	ddsDataType = new TTypeSupport(true);
    if (ddsDataType == NULL) {
    	fprintf(stderr, "Error while registering type\n");
        goto done;
    }
    deleteDataType = DDS_BOOLEAN_TRUE;

    presTypePlugin->_userBuffer = (PRESWord *)ddsDataType;
    alreadyRegistered = participant->is_type_registered(type_name);

    result = participant->register_type(
        type_name, presTypePlugin, NULL, !alreadyRegistered);
    if (result != DDS_RETCODE_OK) {
    	fprintf(stderr, "Error while registering type\n");
        goto done;
    }

    /* If the type was already registered then the call to register_type
       returns DDS_RETCODE_OK and is a noop so we need to delete the
       type support */
    if (!alreadyRegistered) {
        deleteDataType = DDS_BOOLEAN_FALSE;
    }

    result = DDS_RETCODE_OK;
done:
    if (presTypePlugin != NULL) {
        TPlugin_delete(presTypePlugin);
    }
    if (deleteDataType) {
        delete (TTypeSupport*)ddsDataType;
        ddsDataType = NULL;
    }
    return result;

}

#undef TTypeSupport
#undef TData
#undef TDataReader
#undef TDataWriter
#undef TGENERATE_TYPECODE
#undef TGENERATE_SER_CODE
#undef TTYPENAME
#undef TPlugin_new
#undef TPlugin_delete

