
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from SerializedTypeKeyed.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef SerializedTypeKeyedSupport_1719073588_h
#define SerializedTypeKeyedSupport_1719073588_h

/* Uses */
#include "SerializedTypeKeyed.h"

#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)

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

DDS_TYPESUPPORT_C(SerializedTypeKeyedTypeSupport, SerializedTypeKeyed);
DDS_DATAWRITER_C(SerializedTypeKeyedDataWriter, SerializedTypeKeyed);
DDS_DATAREADER_C(SerializedTypeKeyedDataReader, SerializedTypeKeyedSeq, SerializedTypeKeyed);

NDDSUSERDllExport DDSCDllExport
DDS_ReturnCode_t SerializedTypeKeyedTypeSupport_register_type2(
	DDS_DomainParticipant* participant,
	const char* type_name,
	struct DDS_TypeCode *type_code);

DDS_ReturnCode_t SerializedTypeKeyedTypeSupport_print_data2(
	const SerializedTypeKeyed *sample,
	FILE  *fp,
	const char *desc,
	unsigned int indent_level,
	struct DDS_TypeCode *type_code);

/* Special higher-level writers */
struct SerializedTypeKeyedWriter {
	DDS_DataWriter* _parent;
};

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif  /* SerializedTypeKeyedSupport_1719073588_h */

