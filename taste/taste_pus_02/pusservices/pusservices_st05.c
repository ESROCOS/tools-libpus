/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
 

#include "pusservices_st05.h"
#include "pusservices_events.h"
#include "pusservices_tm.h"
#include "pusservices_apid.h"


#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st05_packets.h"
#include "pus_events.h"
#include "pus_st05_config.h"

asn1SccPusUInt64 counter;

/*! Initialize the service */
void pusservices_initService05()
{
	counter = 0;
    pus_events_initialize(NULL);
}

void pusservices_st05_EventReportTrigger()
{
    pusError_t pus_error;
	pusSt05Event_t event;
	asn1SccPusUInt64 lastCounter = counter;
    
	pusservices_events_getNextEvent(&lastCounter,&event, &counter);//st05_RI_getNextEvent(&lastCounter, &event, &counter); TODO

	if(lastCounter != counter)
	{
		printf(" -ST05: New event read. ID: %llu, count: %llu\n", pus_events_getEventId(&event), counter);
		pusPacket_t outTm;
		pusApid_t apid;
		pusSequenceCount_t seqCount;
		apid = pusservices_getApid();//st05_RI_getApid(&apid);
		seqCount = pusservices_getTmSequenceCount();//st05_RI_getSequenceCount(&seqCount); 

		switch( pus_st05_eventInfoList[pus_events_getEventId(&event)].defaultSeverity )
		{
		case PUS_ST05_SEVERITY_INFO:
			if(PUS_NO_ERROR != pus_tm_5_1_createInformativeEventReport(&outTm, apid, seqCount, &event, pus_st05_eventReportDestination))
			{
				return;
			}
			break;
		case PUS_ST05_SEVERITY_LOW:
			if(PUS_NO_ERROR != pus_tm_5_2_createLowSeverityEventReport(&outTm, apid, seqCount, &event, pus_st05_eventReportDestination))
			{
				return;
			}
			break;
		case PUS_ST05_SEVERITY_MEDIUM:
			if(PUS_NO_ERROR != pus_tm_5_3_createMediumSeverityEventReport(&outTm, apid, seqCount, &event, pus_st05_eventReportDestination))
			{
				return;
			}
			break;
		case PUS_ST05_SEVERITY_HIGH:
			if(PUS_NO_ERROR != pus_tm_5_4_createHighSeverityEventReport(&outTm, apid, seqCount, &event, pus_st05_eventReportDestination))
			{
				return;
			}
			break;
		default:
			return;
		}
		pus_error = pusservices_queueTm(&outTm);//st05_RI_newTmNoInherit(&outTm); 
        //TODO: Check pus_error
	}
	else
	{
		//printf(" -ST05: No new events .\n");
		pus_clearError();
	}
}

