/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pusservices_config.h"

#ifdef PUSSERVICES_11_ENABLED

#include "pusservices_st11.h"
#include "pusservices.h"
#include "pus_st11_config.h"
#include "pus_st11_packets.h"
#include "pus_timebased_scheduling.h"


/*! Initialize the service */
void pusservices_initService11(void)
{
	pus_scheduling_initialize(NULL);
}


/*! Process a PUS11 TC */
void pusservices_processTc11(const pusPacket_t *tcPacket)
{
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	errorCode = PUS_EXPECT_ST11TC(tcPacket, pusSubtype_NONE);
	if(PUS_NO_ERROR == errorCode )
	{
		//send 1.1
		subtype = pus_TM_1_1_successfulAcceptance;
		pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);

		pusSubservice_t subtype = pus_getTcSubtype(tcPacket);
		if( pus_TC_11_1_enableTimeBasedScheduling == subtype )
		{
			errorCode = pus_scheduling_enableFunction();
		}
		else if( pus_TC_11_2_disableTimeBasedScheduling == subtype )
		{
			errorCode = pus_scheduling_disableFunction();
		}
		else if( pus_TC_11_3_resetTimeBasedSchedule == subtype )
		{
			errorCode = pus_scheduling_resetFunction();
		}
		else if( pus_TC_11_4_insertActivity == subtype )
		{
			errorCode = pus_scheduling_tc_11_4_packetToTable(tcPacket);
		}
		else
		{
			errorCode = PUS_ERROR_TC_SUBTYPE;
		}
	}
	else
	{
		errorCode = PUS_ERROR_TC_SERVICE;

		//send 1.2
		subtype = pus_TM_1_2_failedAcceptance;
		pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}

	if( PUS_NO_ERROR == errorCode)
	{
		//send 1.7
		subtype = pus_TM_1_7_successfulCompletion;
		pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);
	}
	else
	{
		//send 1.8
		subtype = pus_TM_1_8_failedCompletion;
		pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);
	}
}


/*! Set the next scheduled TC for execution */
pusError_t pusservices_st11runNextTc()
{
	pusPacket_t tc;
	pusTime_t time;
	pus_now(&time);
    
    pusError_t error = pus_scheduling_getScheduledActivity(&tc, &time);

    if (PUS_ERROR_NO_SCHEDULED_TC == error)
    {
        /* No TC scheduled to execute now */
		//printf(" - ST11: processing packet\n");
        return PUS_NO_ERROR;
    }
    else if(PUS_NO_ERROR == error)
	{
        printf(" - ST11: TC%llu_%llu scheduled\n", pus_getTcService(&tc), pus_getTcSubtype(&tc));
		pusservices_PI_addTc(&tc);
		pus_clearError();
        return PUS_NO_ERROR;
	}
    else
    {
        printf("ERROR pusservices_st11runNextTc: get scheduled, code %d (continue)\n", error);
		pus_clearError();
        return error;
    }
}


#endif
