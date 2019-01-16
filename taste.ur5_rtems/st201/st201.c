/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

/* User code: This file will not be overwritten by TASTE. */

#include "st201.h"
#include <stdio.h>

#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st201_packets.h"

extern void (*ptr_st201_RI_planHomeRequest)(void);
extern void (*ptr_st201_RI_setHome)(const asn1SccPusTC_201_1_3_Data *);
extern void (*ptr_st201_RI_planMoveRequest)(const asn1SccPusTC_201_1_3_Data *);

void st201_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	if(NULL == ptr_st201_RI_setHome)
	{
		ptr_st201_RI_setHome = st201_RI_setHome;
	}
	if(NULL == ptr_st201_RI_planMoveRequest)
	{
		ptr_st201_RI_planMoveRequest = st201_RI_planMoveRequest;
	}
	if(NULL == ptr_st201_RI_planHomeRequest)
	{
		ptr_st201_RI_planHomeRequest = st201_RI_planHomeRequest;
	}
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
		if( pus_TC_201_1_setHomeRequest == subtype )
		{
			//TODOOOO
			st201_RI_setHome(&IN_tcPacket->data.u.tcData.data.u.st_201_1_3);
		}
		else if( pus_TC_201_2_planHomeRequest == subtype )
		{
			//TODOOOO
			st201_RI_planHomeRequest();
		}
		else if( pus_TC_201_3_planMoveRequest == subtype )
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
	printf("report\n");
	pusPacket_t outTm;
	pusApid_t apid;
	pusSequenceCount_t seqCount;
	pusApid_t destination = 1;

	st201_RI_getApid(&apid);
	st201_RI_getSequenceCount(&seqCount);
	pus_tm_201_4_createPlanReport(&outTm, apid, seqCount, destination, IN_observation);
	st201_RI_newTm(&outTm);
}

