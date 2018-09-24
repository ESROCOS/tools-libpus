/* User code: This file will not be overwritten by TASTE. */

#include "st19.h"

#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st19_packets.h"
#include "pus_st19_config.h"

#include "pus_events.h"

asn1SccPusUInt64 counter;

void st19_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	counter = 0;
	pus_eventAction_initialize(NULL);
}

void st19_PI_tc19(const asn1SccPusPacket *IN_tcPacket)
{
    /* Write your code here! */
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	errorCode = PUS_EXPECT_ST19(IN_tcPacket, pusSubtype_NONE);
	if(PUS_NO_ERROR == errorCode )
	{
		//send 1.1
		//printf(" -ST19: pus_TM_1_1_successfulAcceptance\n.");
		subtype = pus_TM_1_1_successfulAcceptance;
		st19_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);

		pusSt05EventId_t eventID;
		if( PUS_NO_ERROR != pus_tc_19_X_getEventId(&eventID, IN_tcPacket))
		{
			errorCode = PUS_ERROR_NOT_INITIALIZED;
		}
		else
		{
			pusSubservice_t subtype = pus_getTcSubtype(IN_tcPacket);
			printf(" -ST19: Subtype: %llu, eventId %llu", subtype, eventID);
			if( pus_TC_19_1_addEventActionDefinitions == subtype )
			{
				pusPacketReduced_t tcActionR;
				pusPacket_t tcAction;
				pus_tc_19_1_getAction(&tcActionR, IN_tcPacket);
				pus_packetReduced_createPacketFromPacketReduced(&tcAction, &tcActionR);
				errorCode =  pus_eventAction_addEventActionDefinition(eventID, &tcAction);
			}
			else if( pus_TC_19_2_deleteEventActionDefinitions == subtype )
			{
				errorCode = pus_eventAction_deleteEventActionDefinition(eventID);
			}
			else if( pus_TC_19_4_enableEventActionDefinitions == subtype )
			{
				errorCode = pus_eventAction_enableEventActionDefinition(eventID);
			}
			else if( pus_TC_19_5_disableEventActionDefinitions == subtype )
			{
				errorCode = pus_eventAction_disableEventActionDefinition(eventID);
			}
			else
			{
				errorCode = PUS_ERROR_TC_SUBTYPE;
			}
		}
	}
	else
	{
		errorCode = PUS_ERROR_TC_SERVICE;

		//send 1.2
		//printf(" -ST19: pus_TM_1_2_failedAcceptance\n");
		subtype = pus_TM_1_2_failedAcceptance;
		st19_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}

	if( PUS_NO_ERROR == errorCode)
	{
		//send 1.7
		subtype = pus_TM_1_7_successfulCompletion;
		st19_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
	else
	{
		//send 1.8
		subtype = pus_TM_1_8_failedCompletion;
		//printf("Error 19.4 %llu", errorCode);
		st19_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
}

void st19_PI_EventActionTrigger()
{
    /* Write your code here! */
	pusSt05Event_t event;
	asn1SccPusUInt64 lastCounter = counter;
	st19_RI_getNextEvent(&lastCounter, &event, &counter);

	if( lastCounter != counter )
	{
		pusPacket_t tcAction;
		if(PUS_NO_ERROR == pus_eventAction_getAction(&tcAction, pus_events_getEventId(&event)))
		{
			printf(" -ST19: TC%llu_%llu generated.\n", pus_getTcService(&tcAction), pus_getTcSubtype(&tcAction));
			st19_RI_newTc(&tcAction);
		}
	}
}

