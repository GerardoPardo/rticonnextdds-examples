# Example Code: Serialized Type

## Building C Example
Before compiling or running the example, make sure the environment variable
`NDDSHOME` is set to the directory where your version of *RTI Connext* is
installed.

Run *rtiddsgen* with the `-example` option and the target architecture of your
choice (e.g., *i86Win32VS2010* or *i86Linux2.6gcc4.4.5*). The *RTI Connext Core
Libraries and Utilities Getting Started Guide* describes this process in detail.
Follow the same procedure to generate the code and build the examples. **Do not
use the `-replace` option.** 
We have already provided the generated code for SerializedType.idl (
which should not be modified by the user of this example)
Assuming you want to send ShapeType on the wire on 
*x64Linux3gcc4.8.2* run:
```
rtiddsgen -language C -example x64Linux3gcc4.8.2 ShapeType.idl
```

You should be able to see that the Plugin, Support and Type files are generated for ShapeType.idl.

To build the project, first generate a makefile using:
```
rtiddsgen -language C -example x64Linux3gcc4.8.2 SerializedType.idl
```
Now in the makefile which is generated, you will have to edit the following section:
1. SOURCES:
Add the following files to sources (for ShapeType)
$(SOURCE_DIR)/ShapeTypeSupport.c $(SOURCE_DIR)ShapeTypePlugin.c $(SOURCE_DIR)ShapeType.c

## Running C Example
In two separate command prompt windows for the publisher and subscriber. Run
the following commands from the example directory (this is necessary to ensure
the application loads the QoS defined in *USER_QOS_PROFILES.xml*):

On *Windows* systems run:
```
objs\<arch_name>\SerializedType_publisher.exe  <domain_id> <samples_to_send>
objs\<arch_name>\SerializedType_subscriber.exe <domain_id>  <sleep_periods>
```

On *UNIX* systems run:
```
./objs/<arch_name>/SerializedType_publisher  <domain_id> <samples_to_send>
./objs/<arch_name>/SerializedType_subscriber <domain_id> <sleep_periods>
```

The applications accept up to two arguments:

1. The `<domain_id>`. Both applications must use the same domain ID in order
to communicate. The default is 0.
2. How long the examples should run, measured in samples for the publisher
and sleep periods for the subscriber. A value of '0' instructs the
application to run forever; this is the default.

You should now be able to see that the type which gets published on the wire is the 
ShapeType and you can deserialize it on demand at the receiving end.

## Disclaimer
This example does not provide full support for keyed data types. We are still working on getting 
it to work with keyed data.