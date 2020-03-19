/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
 
/* User code: This file will not be overwritten by TASTE. */

#include "pusservices_events.h"

#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st05_packets.h"
#include "pus_events.h"
#include "pus_st05_config.h"

/*void events_startup()
{

	pus_events_initialize(NULL);
}*/

void pusservices_events_getNextEvent(const asn1SccPusUInt64 *IN_actualCounter,
							asn1SccPusSt05Event *OUT_eventInfo,
                            asn1SccPusUInt64 *OUT_nextCounter)
{
    /* Write your code here! */

	uint64_t counter = (uint64_t) *IN_actualCounter;
	pusError_t error = pus_st05_getNextBufferEvent(OUT_eventInfo, &counter);
	if( PUS_NO_ERROR == error )
	{
		printf(" -EVENTS: getNextEvent successfully.\n");
		*OUT_nextCounter = counter;
	}
	else
	{
		printf(" -EVENTS: getNextEvent fail %d\n", error);
		*OUT_nextCounter = *IN_actualCounter;
		pus_clearError();
	}

	//printf(" -EVENTS: *OUT_nextCounter %llu, *IN_actualCounter %llu\n", *OUT_nextCounter, *IN_actualCounter);
}

void pusservices_events_pushNewEvent(const asn1SccPusSt05Event *IN_eventInfo)
{
    /* Write your code here! */
	pusError_t error = pus_st05_pushBufferEvent(IN_eventInfo);
	if(PUS_NO_ERROR == error)
	{
		printf(" -EVENTS: new event in buffer.\n");
	}
	else
	{
		printf(" -EVENTS: pushNew error %d\n", error);
	}
}

void pusservices_events_debugEventsTrigger()
{
	pusSt05Event_t event;
	pus_events_createEVENT_INFO_01(&event, 23, 54);
	pusError_t error = pus_st05_pushBufferEvent(&event);
	if(PUS_NO_ERROR == error)
	{
		printf(" -EVENTS: new event in buffer (info, trigger).\n");
	}
	else
	{
		printf(" -EVENTS: debugTrigger error %d\n", error);
	}
}
