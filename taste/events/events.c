/* User code: This file will not be overwritten by TASTE. */

#include "events.h"

#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st05_packets.h"
#include "pus_events.h"
#include "pus_st05_config.h"

void events_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	pus_events_initialize(NULL);
}

void events_PI_getNextEvent(const asn1SccPusUInt64 *IN_actualCounter,
							asn1SccPusSt05Event *OUT_eventInfo,
                            asn1SccPusUInt64 *OUT_nextCounter) //TODO INcount
{
    /* Write your code here! */

	uint64_t counter = (uint64_t) *IN_actualCounter;
	pusError_t error = pus_st05_getNextBufferEvent(OUT_eventInfo, &counter);
	if( PUS_NO_ERROR == error )
	{
		//printf(" -EVENTS: getNextEvent successfully.\n");

	}
	else
	{
		//printf(" -EVENTS: getNextEvent fail %d\n", error);
		pus_clearError();
	}
	*OUT_nextCounter = counter;
}

void events_PI_pushNewEvent(const asn1SccPusSt05Event *IN_eventInfo)
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

void events_PI_debugTrigger()
{
	pusSt05Event_t event;
	pus_events_createEVENT_INFO_01(&event, 23, 54);
	pusError_t error = pus_st05_pushBufferEvent(&event);
	if(PUS_NO_ERROR == error)
	{
		printf(" -EVENTS: new event in buffer.\n");
	}
	else
	{
		printf(" -EVENTS: debugTrigger error %d\n", error);
	}
}
