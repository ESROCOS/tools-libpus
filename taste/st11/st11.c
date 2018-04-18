/* User code: This file will not be overwritten by TASTE. */

#include "st11.h"

#include "pus_error.h"
#include "pus_types.h"
#include "pus_time.h"

#include "pus_st11_packets.h"
#include "pus_timebased_scheduling.h"
#include "pus_st11_config.h"




void st11_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	pus_scheduling_initialize(NULL);
}

void st11_PI_tc11(const asn1SccPusPacket *IN_tcPacket)
{
    /* Write your code here! */
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	errorCode = PUS_EXPECT_ST11TC(IN_tcPacket, pusSubtype_NONE);
	if(PUS_NO_ERROR == errorCode )
	{
		//send 1.1
		subtype = pus_TM_1_1_successfulAcceptance;
		st11_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);


		pusSubservice_t subtype = pus_getTcSubtype(IN_tcPacket);
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
			errorCode = pus_scheduling_tc_11_4_packetToTable(IN_tcPacket);
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
		st11_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}

	if( PUS_NO_ERROR == errorCode)
	{
		//send 1.7
		subtype = pus_TM_1_7_successfulCompletion;
		st11_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
	else
	{
		//send 1.8
		subtype = pus_TM_1_8_failedCompletion;
		st11_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
}

