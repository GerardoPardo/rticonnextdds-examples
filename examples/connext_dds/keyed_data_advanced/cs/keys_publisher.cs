/*******************************************************************************
 (c) 2005-2014 Copyright, Real-Time Innovations, Inc.  All rights reserved.
 RTI grants Licensee a license to use, modify, compile, and create derivative
 works of the Software.  Licensee has the right to distribute object form only
 for use with RTI products.  The Software is provided "as is", with no warranty
 of any type, including any warranty for fitness for any purpose. RTI is under
 no obligation to maintain or support the Software.  RTI shall not be liable for
 any incidental or consequential damages arising out of the use or inability to
 use the software.
 ******************************************************************************/
using System;
using System.Collections.Generic;
using System.Text;
/* keys_publisher.cs

   A publication of data of type keys

   This file is derived from code automatically generated by the rtiddsgen 
   command:

   rtiddsgen -language C# -example <arch> keys.idl

   Example publication of type keys automatically generated by 
   'rtiddsgen'. To test them follow these steps:

   (1) Compile this file and the example subscription.

   (2) Start the subscription with the command
       objs\<arch>\keys_subscriber <domain_id> <sample_count>
                
   (3) Start the publication with the command
       objs\<arch>\keys_publisher <domain_id> <sample_count>

   (4) [Optional] Specify the list of discovery initial peers and 
       multicast receive addresses via an environment variable or a file 
       (in the current working directory) called NDDS_DISCOVERY_PEERS. 

   You can run any number of publishers and subscribers programs, and can 
   add and remove them dynamically from the domain.


   Example:

       To run the example application on domain <domain_id>:

       bin\<Debug|Release>\keys_publisher <domain_id> <sample_count>
       bin\<Debug|Release>\keys_subscriber <domain_id> <sample_count>

       
modification history
------------ -------       
*/

public class keysPublisher
{

    public static void Main(string[] args)
    {

        // --- Get domain ID --- //
        int domain_id = 0;
        if (args.Length >= 1)
        {
            domain_id = Int32.Parse(args[0]);
        }

        // --- Get max loop count; 0 means infinite loop  --- //
        int sample_count = 0;
        if (args.Length >= 2)
        {
            sample_count = Int32.Parse(args[1]);
        }

        /* Uncomment this to turn on additional logging
        NDDS.ConfigLogger.get_instance().set_verbosity_by_category(
            NDDS.LogCategory.NDDS_CONFIG_LOG_CATEGORY_API, 
            NDDS.LogVerbosity.NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
        */

        // --- Run --- //
        try
        {
            keysPublisher.publish(
                domain_id, sample_count);
        }
        catch (DDS.Exception)
        {
            Console.WriteLine("error in publisher");
        }
    }

    static void publish(int domain_id, int sample_count)
    {

        // --- Create participant --- //

        /* To customize participant QoS, use 
           the configuration file USER_QOS_PROFILES.xml */
        DDS.DomainParticipant participant =
            DDS.DomainParticipantFactory.get_instance().create_participant(
                domain_id,
                DDS.DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT,
                null /* listener */,
                DDS.StatusMask.STATUS_MASK_NONE);
        if (participant == null)
        {
            shutdown(participant);
            throw new ApplicationException("create_participant error");
        }

        // --- Create publisher --- //

        /* To customize publisher QoS, use 
           the configuration file USER_QOS_PROFILES.xml */
        DDS.Publisher publisher = participant.create_publisher(
        DDS.DomainParticipant.PUBLISHER_QOS_DEFAULT,
        null /* listener */,
        DDS.StatusMask.STATUS_MASK_NONE);
        if (publisher == null)
        {
            shutdown(participant);
            throw new ApplicationException("create_publisher error");
        }

        // --- Create topic --- //

        /* Register type before creating topic */
        System.String type_name = keysTypeSupport.get_type_name();
        try
        {
            keysTypeSupport.register_type(
                participant, type_name);
        }
        catch (DDS.Exception e)
        {
            Console.WriteLine("register_type error {0}", e);
            shutdown(participant);
            throw e;
        }

        /* To customize topic QoS, use 
           the configuration file USER_QOS_PROFILES.xml */
        DDS.Topic topic = participant.create_topic(
            "Example keys",
            type_name,
            DDS.DomainParticipant.TOPIC_QOS_DEFAULT,
            null /* listener */,
            DDS.StatusMask.STATUS_MASK_NONE);
        if (topic == null)
        {
            shutdown(participant);
            throw new ApplicationException("create_topic error");
        }

        // --- Create writer --- //

        /* We are going to load different QoS profiles for the two DWs */
        DDS.DataWriterQos writerQos = new DDS.DataWriterQos();

        /* To customize data writer QoS, use 
           the configuration file USER_QOS_PROFILES.xml */
        DDS.DataWriter writer = publisher.create_datawriter(
            topic,
            DDS.Publisher.DATAWRITER_QOS_DEFAULT,
            null /* listener */,
            DDS.StatusMask.STATUS_MASK_NONE);
        DDS.DomainParticipantFactory.get_instance().get_datawriter_qos_from_profile(writerQos, "keys_Library", "keys_Profile_dw2");   

        /* If you want to set the writer_data_lifecycle QoS settings
        * programmatically rather than using the XML, you will need to add
        * the following lines to your code and comment out the create_datawriter
        * and get_datawriter_qos_from_profile calls above.
        */

        /*
        publisher.get_default_datawriter_qos(writerQos);

        writerQos.writer_data_lifecycle.autodispose_unregistered_instances = false;
        writerQos.ownership.kind = DDS.OwnershipQosPolicyKind.EXCLUSIVE_OWNERSHIP_QOS;
        writerQos.ownership_strength.value = 10;

        DDS.DataWriter writer = publisher.create_datawriter(
            topic,
            writerQos,
            null,
            DDS.StatusMask.STATUS_MASK_NONE);

        writerQos.ownership_strength.value = 5;
        */

        DDS.DataWriter writer2 = publisher.create_datawriter(
            topic,
            writerQos,
            null /* listener */,
            DDS.StatusMask.STATUS_MASK_NONE);

        if (writer == null)
        {
            shutdown(participant);
            throw new ApplicationException("create_datawriter error");
        }
        keysDataWriter keys_writer = (keysDataWriter)writer;

        if (writer2 == null)
        {
            shutdown(participant);
            throw new ApplicationException("create_datawriter error");
        }
        keysDataWriter keys_writer2 = (keysDataWriter)writer2;

        // --- Write --- //

        /* Creates three instances */
        keys[] instance = new keys[3] { null, null, null };

        /* Create data sample for writing */
        instance[0] = keysTypeSupport.create_data();
        instance[1] = keysTypeSupport.create_data();
        instance[2] = keysTypeSupport.create_data();
        if ((instance[0] == null)
                       ||
            (instance[1] == null)
                       ||
            (instance[2] == null)
            )
        {
            shutdown(participant);
            throw new ApplicationException(
                "keysTypeSupport.create_data error");
        }

        /* RTI Connext could examine the key fields each time it needs to determine
        * which data-instance is being modified.
        * However, for performance and semantic reasons, it is better
        * for your application to declare all the data-instances it intends to
        * modify prior to actually writing any samples. This is known as registration.
        */

        /* In order to register the instances, we must set their associated keys first */
        instance[0].code = 0;
        instance[1].code = 1;
        instance[2].code = 2;

        /* For a data type that has a key, if the same instance is going to be
           written multiple times, initialize the key here
           and register the keyed instance prior to writing */
        DDS.InstanceHandle_t[] handle = new DDS.InstanceHandle_t[3];

        Console.WriteLine("----DW1 registering instance handle", instance[0].code);
        handle[0] = keys_writer.register_instance(instance[0]);

        // Init coordinates
        instance[0].x = 1;
        instance[1].x = 1;
        instance[2].x = 1;

        int[] active = new int[] { 1, 0, 0 }; // Only send active keys.

        /* Make variables for the instance for the second datawriter to use.
        Note that it actually refers to the same logical instance, but
        because we're running both datawriters in the same thread, we
        to create separate variables so they don't clobber each other.
        */

        keys instance_dw2 = null;

        instance_dw2 = keysTypeSupport.create_data();
        if (instance_dw2 == null)
        {
            shutdown(participant);
            throw new ApplicationException("keysTypeSupport.create_data error");
        }

        /* instance_dw2 and instance[1] have the same key, and thus
           will write to the same instance (ins1). 
         */
        instance_dw2.code = instance[1].code;
        instance_dw2.x = 2;
        DDS.InstanceHandle_t handle_dw2 = keys_writer2.register_instance(instance_dw2);
        int active_dw2 = 1;

        /* Main loop */
        const System.Int32 send_period = 1000; // milliseconds
        for (int count = 0; (sample_count == 0) || (count < sample_count); ++count)
        {
            System.Threading.Thread.Sleep(send_period);

            /* Modify the data to be sent here */
            instance[0].y = count;
            instance[1].y = count + 1000;
            instance[2].y = count + 2000;

            instance_dw2.y = -count - 1000;

            /* We control two datawriters via a state machine here rather than
               introducing separate threads.
            */
            /* Control first DataWriter */
            switch (count)
            {
                case 4:
                    { /* Start sending the second (ins1) and third instances (ins2) */
                        Console.WriteLine("----DW1 registering instance {0}", instance[1].code);
                        Console.WriteLine("----DW1 registering instance {0}", instance[2].code);
                        handle[1] = keys_writer.register_instance(instance[1]);
                        handle[2] = keys_writer.register_instance(instance[2]);
                        active[1] = 1;
                        active[2] = 1;
                    } break;
                case 8:
                    { /* Dispose the second instance (ins1) */
                        Console.WriteLine("----DW1 disposing instance {0}", instance[1].code);
                        try
                        {
                            keys_writer.dispose(instance[1], ref handle[1]);
                        }
                        catch (DDS.Exception e)
                        {
                            Console.WriteLine("dispose instance error: {0}", e);
                            return;
                        }

                        active[1] = 0;
                    } break;
                case 10:
                    { /* Unregister the second instance (ins1) */
                        Console.WriteLine("----DW1 unregistering instance {0}", instance[1].code);
                        try
                        {
                            keys_writer.unregister_instance(instance[1], ref handle[1]);
                        }
                        catch (DDS.Exception e)
                        {
                            Console.WriteLine("unregister instance error: {0}", e);
                            return;
                        }

                        active[1] = 0;
                    } break;
                case 12:
                    { /* Unregister the third instance (ins2) */
                        Console.WriteLine("----DW1 unregistering instance {0}", instance[2].code);

                        try
                        {
                            keys_writer.unregister_instance(instance[2], ref handle[2]);
                        }
                        catch (DDS.Exception e)
                        {
                            Console.WriteLine("unregister instance error: {0}", e);
                            return;
                        }

                        active[2] = 0;

                        /* Re-register the second instance (ins1) */
                        Console.WriteLine("----DW1 re-registering instance {0}", instance[1].code);
                        handle[1] = keys_writer.register_instance(instance[1]);
                        active[1] = 1;
                    } break;
                case 16:
                    { /* Re-register the third instance (ins2) */
                        Console.WriteLine("----DW1 re-registering instance {0}", instance[2].code);
                        handle[2] = keys_writer.register_instance(instance[2]);
                        active[2] = 1;
                    } break;
            }

            for (int i = 0; i < 3; ++i)
            {
                if (active[i] == 1)
                {
                    Console.WriteLine("DW1 write; code: {0}, x: {1}, y: {2}",
                                      instance[i].code, instance[i].x, instance[i].y);

                    try
                    {
                        keys_writer.write(instance[i], ref handle[i]);
                    }
                    catch (DDS.Exception e)
                    {
                        Console.WriteLine("write error {0}", e);
                        return;
                    }

                }
            }

            /* Control second datawriter */
            switch (count)
            {
                case 16:
                    { /* Dispose the instance (ins1). 
                       Since it has lower ownership strength, this does nothing */
                        Console.WriteLine("----DW2 disposing instance {0}", instance_dw2.code);
                        try
                        {
                            keys_writer2.dispose(instance_dw2, ref handle_dw2);
                        }
                        catch (DDS.Exception e)
                        {
                            Console.WriteLine("dispose error {0}", e);
                            return;
                        }

                        active_dw2 = 0;
                    } break;
            }

            if (active_dw2 == 1)
            {
                Console.WriteLine("DW2 write; code: {0}, x: {1}, y: {2}",
                       instance_dw2.code, instance_dw2.x, instance_dw2.y);
                try
                {
                    keys_writer2.write(instance_dw2, ref handle_dw2);
                }
                catch (DDS.Exception e)
                {
                    Console.WriteLine("write error {0}", e);
                    return;
                }
            }


        }

        // --- Shutdown --- //

        /* Delete data sample */
        for (int i = 0; i < 3; i++)
        {

            try
            {
                keysTypeSupport.delete_data(instance[i]);
            }
            catch (DDS.Exception e)
            {
                Console.WriteLine(
                    "keysTypeSupport.delete_data error: {0}", e);
            }
        }
        try
        {
            keysTypeSupport.delete_data(instance_dw2);
        }
        catch (DDS.Exception e)
        {
            Console.WriteLine(
                "keysTypeSupport.delete_data error: {0}", e);
        }

        /* Delete all entities */
        shutdown(participant);
    }

    static void shutdown(
        DDS.DomainParticipant participant)
    {

        /* Delete all entities */

        if (participant != null)
        {
            participant.delete_contained_entities();
            DDS.DomainParticipantFactory.get_instance().delete_participant(
                ref participant);
        }

        /* RTI Connext provides finalize_instance() method on
           domain participant factory for people who want to release memory
           used by the participant factory. Uncomment the following block of
           code for clean destruction of the singleton. */
        /*
        try {
            DDS.DomainParticipantFactory.finalize_instance();
        } catch (DDS.Exception e) {
            Console.WriteLine("finalize_instance error: {0}", e);
            throw e;
        }
        */
    }
}
