

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from SerializedType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef SerializedType_1419555957_h
#define SerializedType_1419555957_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

static const DDS_Long KEY_HASH_LENGTH_16= 16;
extern "C" {

    extern const char *SerializedTypeTYPENAME;

}

struct SerializedTypeSeq;
#ifndef NDDS_STANDALONE_TYPE
class SerializedTypeTypeSupport;
class SerializedTypeDataWriter;
class SerializedTypeDataReader;
#endif

class SerializedType 
{
  public:
    typedef struct SerializedTypeSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef SerializedTypeTypeSupport TypeSupport;
    typedef SerializedTypeDataWriter DataWriter;
    typedef SerializedTypeDataReader DataReader;
    #endif

    DDS_Octet   key_hash [(KEY_HASH_LENGTH_16)];
    DDS_OctetSeq  serialized_key ;
    DDS_OctetSeq  serialized_data ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* SerializedType_get_typecode(void); /* Type code */

DDS_SEQUENCE(SerializedTypeSeq, SerializedType);

NDDSUSERDllExport
RTIBool SerializedType_initialize(
    SerializedType* self);

NDDSUSERDllExport
RTIBool SerializedType_initialize_ex(
    SerializedType* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool SerializedType_initialize_w_params(
    SerializedType* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
void SerializedType_finalize(
    SerializedType* self);

NDDSUSERDllExport
void SerializedType_finalize_ex(
    SerializedType* self,RTIBool deletePointers);

NDDSUSERDllExport
void SerializedType_finalize_w_params(
    SerializedType* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void SerializedType_finalize_optional_members(
    SerializedType* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool SerializedType_copy(
    SerializedType* dst,
    const SerializedType* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* SerializedType */

