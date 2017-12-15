

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from SerializedTypeKeyed.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef SerializedTypeKeyed_1719073588_h
#define SerializedTypeKeyed_1719073588_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

#define KEY_HASH_LENGTH_16 (16)

extern const char *SerializedTypeKeyedTYPENAME;

typedef struct SerializedTypeKeyed {

    DDS_Octet   key_hash [(KEY_HASH_LENGTH_16)];
    struct    DDS_OctetSeq  buffer ;

} SerializedTypeKeyed ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* SerializedTypeKeyed_get_typecode(void); /* Type code */

DDS_SEQUENCE(SerializedTypeKeyedSeq, SerializedTypeKeyed);

NDDSUSERDllExport
RTIBool SerializedTypeKeyed_initialize(
    SerializedTypeKeyed* self);

NDDSUSERDllExport
RTIBool SerializedTypeKeyed_initialize_ex(
    SerializedTypeKeyed* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool SerializedTypeKeyed_initialize_w_params(
    SerializedTypeKeyed* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
void SerializedTypeKeyed_finalize(
    SerializedTypeKeyed* self);

NDDSUSERDllExport
void SerializedTypeKeyed_finalize_ex(
    SerializedTypeKeyed* self,RTIBool deletePointers);

NDDSUSERDllExport
void SerializedTypeKeyed_finalize_w_params(
    SerializedTypeKeyed* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void SerializedTypeKeyed_finalize_optional_members(
    SerializedTypeKeyed* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool SerializedTypeKeyed_copy(
    SerializedTypeKeyed* dst,
    const SerializedTypeKeyed* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* SerializedTypeKeyed */

