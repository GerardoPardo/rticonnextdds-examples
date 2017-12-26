# Example Code: Serialized Type

## Concept
This example provides a generic SerializedType that can be used to
read and write data that is serialized at the application layer.

The example provides a SerializedTypeSupport that is used to register
the types and thus create Topics for the registered types along with
a SerializedTypeDataReader and SerializedTypeDataWriter used to read
and write data, respectively.

Typical uses for the SerializedType are the creation of services
(e.g. a "recording service") that can receive and store the data in
serialized form into disk. Likewise a "replay" service can read that
serialized data from disk and publish it.

## Example Description

The SerializedType can be used to publish and subscribe data of any
legal DDS type. It is important to note that the data is still
strongly types even if the data is passed to the DataWriter/Reader in
serialized form.

Remote applications see the DataWriter as a regular typed DDS
DataWriter of the type defined by the  *DDS_TypeCode*. They have no
way of knowing that a *SerializedTypeDataWriter* or
*SerializedTypeDataReader* is being used.

To use the *SerializedType* the application must register a type using
the function  *SerializedType_register_type2()*.  Unlike the regular
*SerializedType_register_type()* function this version takes an
additional *DDS_TypeCode* parameter that defines the DDS Type of the
data that will be published/subscribed.

The  *DDS_TypeCode* may be obtained in different ways:
* It may be discovered from remote applications. This is a typical
scenario on "recording" or "spy" applications.

* It may be constructed using the DDS_TypeCodeFactory. See
https://community.rti.com/static/documentation/connext-dds/5.3.0/doc/api/connext_dds/api_c/structDDS__TypeCodeFactory.html

* It may be obtained by generating code from an IDL file. For type
defined in the IDL (e.g. *struct Foo*) there is a corresponding
function generated (e.g. *Foo_get_typecode()*) that returns the
*DDS_TypeCode* for that type.

The included example uses the last of the three approaches. For this
reason the example includes another IDL file (ShapeType.idl) that
defines the data type that will be published/subscribed with the
SerializedType DataWriter/DataReader.

The defined type in ShapeType.idl is compatible with the type defined
in RTI ShapesDemo. This allows this example to interoperate with the
RTI ShapesDemo application.


