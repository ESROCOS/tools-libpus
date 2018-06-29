/* User code: This file will not be overwritten by TASTE. */

#include "st201.h"
#include <stdio.h>

#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st201_packets.h"

void st201_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void st201_PI_tc201(const asn1SccPusPacket *IN_tcPacket)
{
	/* Write your code here! */
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	errorCode = PUS_EXPECT_ST201TC(IN_tcPacket, pusSubtype_NONE);
	if(PUS_NO_ERROR == errorCode )
	{
		//send 1.1
		subtype = pus_TM_1_1_successfulAcceptance;
		st201_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);

		pusSubservice_t subtype = pus_getTcSubtype(IN_tcPacket);
		if( pus_TC_201_1_setHomeRequest )
		{
			//TODOOOO
			st201_RI_setHome(&IN_tcPacket->data.u.tcData.data.u.st_201_1_3);
		}
		else if( pus_TC_201_2_planHomeRequest )
		{
			//TODOOOO
			st201_RI_planHomeRequest();
		}
		else if( pus_TC_201_3_planMoveRequest )
		{
			//TODOOOO
			st201_RI_planMoveRequest(&IN_tcPacket->data.u.tcData.data.u.st_201_1_3);
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
		st201_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}

	if( PUS_NO_ERROR == errorCode)
	{
		//send 1.7
		subtype = pus_TM_1_7_successfulCompletion;
		st201_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
	else
	{
		//send 1.8
		subtype = pus_TM_1_8_failedCompletion;
		st201_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
}

void st201_PI_report(const asn1SccPusSt201PlanObservation *IN_observation)
{
    /* Write your code here! */

	pusPacket_t outTm;
	pusApid_t apid;
	pusSequenceCount_t seqCount;
	pusApid_t destination = 1;

	st201_RI_getApid(&apid);
	st201_RI_getSequenceCount(&seqCount);
	pus_tm_201_4_createPlanReport(&outTm, apid, seqCount, destination, IN_observation);
}

