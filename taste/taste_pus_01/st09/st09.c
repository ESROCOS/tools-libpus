/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
 
/* User code: This file will not be overwritten by TASTE. */

#include "st09.h"


#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_types.h"

#include "pus_st09_packets.h"

uint64_t tmCounter;
pusApidInfo_t apid;

void st09_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	tmCounter = 0;
	pus_initApidInfo(&apid, pus_APID_TIME, NULL);
	pus_time_setReportGenerationExponentialRate(2);
}

void st09_PI_incCount(asn1SccPusPacket *OUT_tmPacket,
                      asn1SccPusSt01FailureCode *OUT_isAvailable)
{
    /* Write your code here! */
	tmCounter++;
	uint64_t counterTrigger = 0;
	pus_time_getReportGenerationRate(&counterTrigger);

	if ( counterTrigger == tmCounter)
	{
		*OUT_isAvailable = PUS_NO_ERROR;

		pusApid_t apid;
		pusSequenceCount_t seqCount;
		st09_RI_getApid(&apid);
		st09_RI_getSequenceCount(&seqCount);

		pusError_t error = pus_tm_9_2_createCucTimeReport(OUT_tmPacket, apid, seqCount);

		pusTime_t timeAux;
		pusSt09ExponentialRate_t rate;
		pus_tm_9_2_getDataField(OUT_tmPacket, &timeAux, &rate);
		printf(" INC COUNT: Time2: %llu\n", timeAux.tv_sec);


		printf(" INC COUNT: TM%llu_%llu inserted in TmQueue.\n", pus_getTmService(OUT_tmPacket), pus_getTmSubtype(OUT_tmPacket));
		printf(" INC COUNT: in, error %u\n", error);
		tmCounter = 0;
	}
	else
	{
		*OUT_isAvailable = PUS_ERROR_NOT_AVAILABLE;
	}
}

void st09_PI_tc09(const asn1SccPusPacket *IN_tcPacket)
{
    /* Write your code here! */
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	errorCode = PUS_EXPECT_ST09TC(IN_tcPacket, pusSubtype_NONE);
	if(PUS_NO_ERROR == errorCode )
	{
		//send 1.1
		printf(" - ST09: pus_TM_1_1_successfulAcceptance\n.");
		subtype = pus_TM_1_1_successfulAcceptance;
		st09_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);

		pusSt09ExponentialRate_t expRate;
		if (PUS_NO_ERROR != pus_tc_9_1_getExponentialRate(&expRate, IN_tcPacket))
		{
			errorCode = PUS_ERROR_NOT_INITIALIZED;
		}
		else
		{
			errorCode = pus_time_setReportGenerationExponentialRate(expRate);
			tmCounter = 0;
		}
	}
	else
	{
		errorCode = PUS_ERROR_TC_SERVICE;

		//send 1.2
		printf(" -ST09: pus_TM_1_2_failedAcceptance\n");
		subtype = pus_TM_1_2_failedAcceptance;
		st09_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}

	if (PUS_NO_ERROR == errorCode)
	{
		//send 1.7
		subtype = pus_TM_1_7_successfulCompletion;
		st09_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
	else
	{
		//send 1.8
		subtype = pus_TM_1_8_failedCompletion;
		st09_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
}


