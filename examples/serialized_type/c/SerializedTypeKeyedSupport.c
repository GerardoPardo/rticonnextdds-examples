
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from SerializedTypeKeyed.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include "SerializedTypeKeyedSupport.h"
#include "SerializedTypeKeyedPlugin.h"

/* ========================================================================= */
/**
<<IMPLEMENTATION>>

Defines:   TData,
TDataWriter,
TDataReader,
TTypeSupport

Configure and implement 'SerializedTypeKeyed' support classes.

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
#define TTYPENAME   SerializedTypeKeyedTYPENAME

/* Defines */
#define TDataWriter SerializedTypeKeyedDataWriter
#define TData       SerializedTypeKeyed

#include "dds_c/generic/dds_c_data_TDataWriter.gen"

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
#define TTYPENAME   SerializedTypeKeyedTYPENAME

/* Defines */
#define TDataReader SerializedTypeKeyedDataReader
#define TDataSeq    SerializedTypeKeyedSeq
#define TData       SerializedTypeKeyed

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
#define TTYPENAME    SerializedTypeKeyedTYPENAME
#define TPlugin_new  SerializedTypeKeyedPlugin_new
#define TPlugin_delete  SerializedTypeKeyedPlugin_delete

/* Defines */
#define TTypeSupport SerializedTypeKeyedTypeSupport
#define TData        SerializedTypeKeyed
#define TDataReader  SerializedTypeKeyedDataReader
#define TDataWriter  SerializedTypeKeyedDataWriter
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

