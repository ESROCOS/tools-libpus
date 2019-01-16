/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

/* User code: This file will not be overwritten by TASTE. */

#include "st200.h"

#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st200_packets.h"

extern void (*ptr_st200_RI_operationRequest)(const asn1SccPusSt200ControlId *);

void st200_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	if(NULL == ptr_st200_RI_operationRequest)
	{
		ptr_st200_RI_operationRequest = st200_RI_operationRequest;
	}
}

void st200_PI_tc200(const asn1SccPusPacket *IN_tcPacket)
{
	/* Write your code here! */
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	errorCode = PUS_EXPECT_ST200TC(IN_tcPacket, pusSubtype_NONE);
	if(PUS_NO_ERROR == errorCode )
	{
		//send 1.1
		subtype = pus_TM_1_1_successfulAcceptance;
		st200_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);

		pusSubservice_t subtype = pus_getTcSubtype(IN_tcPacket);
		if( pus_TC_200_1_controlRequest == subtype )
		{
			//TODOOOO
			pusSt200ControlId request = pus_tc_200_1_getControlId(IN_tcPacket);
			st200_RI_operationRequest(&request);
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
		st200_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}

	if( PUS_NO_ERROR == errorCode)
	{
		//send 1.7
		subtype = pus_TM_1_7_successfulCompletion;
		st200_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
	else
	{
		//send 1.8
		subtype = pus_TM_1_8_failedCompletion;
		st200_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
}

void st200_PI_report(const asn1SccPusSt200Observation *IN_observation)
{
    /* Write your code here! */
	pusPacket_t outTm;
	pusApid_t apid;
	pusSequenceCount_t seqCount;
	pusApid_t destination = 1;

	st200_RI_getApid(&apid);
	st200_RI_getSequenceCount(&seqCount);
	//pus_tm_200_2_createControlCameraReport(&outTm, apid, seqCount, destination, *IN_observation);
}

