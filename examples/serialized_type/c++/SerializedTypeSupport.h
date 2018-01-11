
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from SerializedType.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef SerializedTypeSupport_1419555957_h
#define SerializedTypeSupport_1419555957_h

/* Uses */
#include "SerializedType.h"

#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)

class __declspec(dllimport) DDSTypeSupport;
class __declspec(dllimport) DDSDataWriter;
class __declspec(dllimport) DDSDataReader;

#endif

/* ========================================================================= */
/**
Uses:     T

Defines:  TTypeSupport, TDataWriter, TDataReader

Organized using the well-documented "Generics Pattern" for
implementing generics in C and C++.
*/

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)

#endif

DDS_TYPESUPPORT_CPP(
    SerializedTypeTypeSupport, 
    SerializedType);

DDS_DATAWRITER_CPP(SerializedTypeDataWriter, SerializedType);
DDS_DATAREADER_CPP(SerializedTypeDataReader, SerializedTypeSeq, SerializedType);

NDDSUSERDllExport DDSCDllExport
DDS_ReturnCode_t SerializedTypeTypeSupport_register_type2(
	DDSDomainParticipant* participant,
	const char* type_name,
	struct DDS_TypeCode *type_code);

DDS_ReturnCode_t SerializedTypeTypeSupport_print_data2(
	const SerializedType *sample,
	FILE  *fp,
	const char *desc,
	unsigned int indent_level,
	struct DDS_TypeCode *type_code);

/* Special higher-level writers */
struct SerializedTypeWriter {
	DDS_DataWriter* _parent;
};

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif  /* SerializedTypeSupport_1419555957_h */

