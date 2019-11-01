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

/* tbfSubscriber.java

   A publication of data of type tbf

   This file is derived from code automatically generated by the rtiddsgen 
   command:

   rtiddsgen -language java -example <arch> .idl

   Example publication of type tbf automatically generated by 
   'rtiddsgen' To test them follow these steps:

   (1) Compile this file and the example subscription.

   (2) Start the subscription on the same domain used for with the command
       java tbfSubscriber <domain_id> <sample_count>

   (3) Start the publication with the command
       java tbfPublisher <domain_id> <sample_count>

   (4) [Optional] Specify the list of discovery initial peers and 
       multicast receive addresses via an environment variable or a file 
       (in the current working directory) called NDDS_DISCOVERY_PEERS. 
       
   You can run any number of publishers and subscribers programs, and can 
   add and remove them dynamically from the domain.
              
                                   
   Example:
        
       To run the example application on domain <domain_id>:
            
       Ensure that $(NDDSHOME)/lib/<arch> is on the dynamic library path for
       Java.                       
       
        On UNIX systems: 
             add $(NDDSHOME)/lib/<arch> to the 'LD_LIBRARY_PATH' environment
             variable
                                         
        On Windows systems:
             add %NDDSHOME%\lib\<arch> to the 'Path' environment variable
                        

       Run the Java applications:
       
        java -Djava.ext.dirs=$NDDSHOME/class tbfPublisher <domain_id>

        java -Djava.ext.dirs=$NDDSHOME/class tbfSubscriber <domain_id>  
       
       
modification history
------------ -------   
*/

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Arrays;

import com.rti.dds.domain.*;
import com.rti.dds.infrastructure.*;
import com.rti.dds.subscription.*;
import com.rti.dds.topic.*;
import com.rti.ndds.config.*;


// ===========================================================================

public class tbfSubscriber {
	
	public static final double NANOSECOND = 1000000000.0;
	
    // -----------------------------------------------------------------------
    // Public Methods
    // -----------------------------------------------------------------------
    
    public static void main(String[] args) {
        // --- Get domain ID --- //
        int domainId = 0;
        if (args.length >= 1) {
            domainId = Integer.valueOf(args[0]).intValue();
        }
        
        // -- Get max loop count; 0 means infinite loop --- //
        int sampleCount = 0;
        if (args.length >= 2) {
            sampleCount = Integer.valueOf(args[1]).intValue();
        }
        
        
        /* Uncomment this to turn on additional logging
        Logger.get_instance().set_verbosity_by_category(
            LogCategory.NDDS_CONFIG_LOG_CATEGORY_API,
            LogVerbosity.NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
        */
        
        // --- Run --- //
        subscriberMain(domainId, sampleCount);
    }
    
    
    
    // -----------------------------------------------------------------------
    // Private Methods
    // -----------------------------------------------------------------------
    
    // --- Constructors: -----------------------------------------------------
    
    private tbfSubscriber() {
        super();
    }
    
    
    // -----------------------------------------------------------------------
    
    private static void subscriberMain(int domainId, int sampleCount) {

        DomainParticipant participant = null;
        Subscriber subscriber = null;
        Topic topic = null;
        DataReaderListener listener = null;
        tbfDataReader reader = null;

        try {

            // --- Create participant --- //
    
            /* To customize participant QoS, use
               the configuration file
               USER_QOS_PROFILES.xml */
    
            participant = DomainParticipantFactory.TheParticipantFactory.
                create_participant(
                    domainId, DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT,
                    null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (participant == null) {
                System.err.println("create_participant error\n");
                return;
            }                         

            // --- Create subscriber --- //
    
            /* To customize subscriber QoS, use
               the configuration file USER_QOS_PROFILES.xml */
    
            subscriber = participant.create_subscriber(
                DomainParticipant.SUBSCRIBER_QOS_DEFAULT, null /* listener */,
                StatusKind.STATUS_MASK_NONE);
            if (subscriber == null) {
                System.err.println("create_subscriber error\n");
                return;
            }     
                
            // --- Create topic --- //
        
            /* Register type before creating topic */
            String typeName = tbfTypeSupport.get_type_name(); 
            tbfTypeSupport.register_type(participant, typeName);
    
            /* To customize topic QoS, use
               the configuration file USER_QOS_PROFILES.xml */
    
            topic = participant.create_topic(
                "Example tbf",
                typeName, DomainParticipant.TOPIC_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (topic == null) {
                System.err.println("create_topic error\n");
                return;
            }                     
        
            // --- Create reader --- //

            listener = new tbfListener();
    
            /* To customize data reader QoS, use
               the configuration file USER_QOS_PROFILES.xml */
    
            reader = (tbfDataReader)
                subscriber.create_datareader(
                    topic, Subscriber.DATAREADER_QOS_DEFAULT, listener,
                    StatusKind.STATUS_MASK_ALL);
            if (reader == null) {
                System.err.println("create_datareader error\n");
                return;
            }                         

            /*
             * If you want to change the time-based filter programmatically
             * (e.g., to 2 seconds) rather than using the XML file, you will
             * need to add the following lines to your code and comment out the
             * create_datareader call above.
             */

            // DataReaderQos readerQos = new DataReaderQos();
            // subscriber.get_default_datareader_qos(readerQos);

            // Duration_t minimumSeparation = new Duration_t(2,0);
            // readerQos.time_based_filter.minimum_separation.sec =
            //         minimumSeparation.sec;
            // readerQos.time_based_filter.minimum_separation.nanosec =
            //         minimumSeparation.nanosec;
            // reader = (tbfDataReader) subscriber.create_datareader(
            //         topic,
            //         readerQos,
            //         listener,
            //         StatusKind.STATUS_MASK_ALL);
            // if (reader == null) {
            //     System.err.println("create_datareader error\n");
            //     return;
            // }

            // --- Wait for data --- //

            /* Results table header: (1) source timestamp of the sample received;
             * (2) instance id (instance.code value); and (3) value of x (instance.x).
             */
            System.out.println("================================================");
            System.out.println("Source Timestamp\tInstance\tX");
            System.out.println("================================================");

            
            final long receivePeriodSec = 4;

            for (int count = 0;
                 (sampleCount == 0) || (count < sampleCount);
                 ++count) {
//            	System.out.println("tbf subscriber sleeping for "
//            			+ receivePeriodSec + " sec...");
                try {
                    Thread.sleep(receivePeriodSec * 1000);  // in millisec
                } catch (InterruptedException ix) {
                    System.err.println("INTERRUPTED");
                    break;
                }
            }
        } finally {

            // --- Shutdown --- //

            if(participant != null) {
                participant.delete_contained_entities();

                DomainParticipantFactory.TheParticipantFactory.
                    delete_participant(participant);
            }
            /* RTI Connext provides the finalize_instance()
               method for users who want to release memory used by the
               participant factory singleton. Uncomment the following block of
               code for clean destruction of the participant factory
               singleton. */
            //DomainParticipantFactory.finalize_instance();
        }
    }
    
    // -----------------------------------------------------------------------
    // Private Types
    // -----------------------------------------------------------------------
    
    // =======================================================================
    
    private static class tbfListener extends DataReaderAdapter {
            
        tbfSeq _dataSeq = new tbfSeq();
        SampleInfoSeq _infoSeq = new SampleInfoSeq();

        public void on_data_available(DataReader reader) {
            tbfDataReader tbfReader =
                (tbfDataReader)reader;
            
            try {
                tbfReader.take(
                    _dataSeq, _infoSeq,
                    ResourceLimitsQosPolicy.LENGTH_UNLIMITED,
                    SampleStateKind.ANY_SAMPLE_STATE,
                    ViewStateKind.ANY_VIEW_STATE,
                    InstanceStateKind.ANY_INSTANCE_STATE);

                for(int i = 0; i < _dataSeq.size(); ++i) {
                    SampleInfo info = (SampleInfo)_infoSeq.get(i);

                    if (info.valid_data) {
                        double sourceTimestamp = info.source_timestamp.sec +
                        		info.source_timestamp.nanosec/NANOSECOND;
                        
                        System.out.printf("%f\t%d\t\t%d\n",
                        		sourceTimestamp,
                        		((tbf)_dataSeq.get(i)).x, 
                        		((tbf)_dataSeq.get(i)).code);
                    }
                }
            } catch (RETCODE_NO_DATA noData) {
                // No data to process
            } finally {
                tbfReader.return_loan(_dataSeq, _infoSeq);
            }
        }
    }
}


        