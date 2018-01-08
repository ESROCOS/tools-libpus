/* User code: This file will not be overwritten by TASTE. */

#include "st05.h"

#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st05_packets.h"
#include "pus_events.h"
#include "pus_st05_config.h"

asn1SccPusUInt64 counter;

void st05_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	counter = 0;
}

void st05_PI_trigger()
{
    /* Write your code here! */
	pusSt05Event_t event;
	asn1SccPusUInt64 lastCounter = counter;
	st05_RI_getNextEvent(&lastCounter, &event, &counter);

	if(lastCounter != counter)
	{
		printf(" -ST05: New event read. ID: %llu, count: %llu\n", pus_events_getEventId(&event), counter);
		pusPacket_t outTm;
		pusApid_t apid;
		pusSequenceCount_t seqCount;
		st05_RI_getApid(&apid);
		st05_RI_getSequenceCount(&seqCount);

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
		st05_RI_newTmNoInherit(&outTm);
	}
	else
	{
		//printf(" -ST05: No new events .\n");
	}
}

