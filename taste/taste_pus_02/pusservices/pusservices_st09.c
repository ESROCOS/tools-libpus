/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */


#include "pusservices_config.h"

#ifdef PUSSERVICES_09_ENABLED

#include "pusservices_st09.h"
#include "pusservices.h"
#include "pusservices_apid.h"
#include "pus_st09_packets.h"


uint64_t g_tmCounter;
pusApidInfo_t g_time_apid;


/*! Initialize the service */
void pusservices_initService09(void)
{
	g_tmCounter = 0;
	pus_initApidInfo(&g_time_apid, pus_APID_TIME, NULL);
	pus_time_setReportGenerationExponentialRate(PUSSERVICES_TIME_REPORT_EXP_RATE);
}


/*! Notify that a TM frame is sent
 * 
 * A PUS[9,2] TM is sent every 2^PUSSERVICES_TIME_REPORT_EXP_RATE TMs.
 */
void pusservices_st09notifyTm(void)
{
	g_tmCounter++;
	uint64_t counterTrigger = 0;
    pusPacket_t tmPacket;
    
    /* Get rate, defines every how many TM a time report TM[9,2] is sent */
	pus_time_getReportGenerationRate(&counterTrigger);

	if (counterTrigger == g_tmCounter)
	{
		pusApid_t apid = pusservices_getApid();
		pusSequenceCount_t seqCount = pusservices_getTmSequenceCount();

        /* Create TM */
		pusError_t error = pus_tm_9_2_createCucTimeReport(&tmPacket, apid, seqCount);
        if (PUS_NO_ERROR != error)
        {
            printf("ERROR pusservices_st09notifyTm: CUC time error %d (continue)\n", error);
            return;
        }

        /* Get TM data for debug print only */
		pusTime_t timeAux;
		pusSt09ExponentialRate_t rate;
		pus_tm_9_2_getDataField(&tmPacket, &timeAux, &rate);
		printf(" - ST09 pusservices_st09notifyTm: time = %llu\n", timeAux.tv_sec);

        /* Send TM */
		printf(" - ST09: Sending TM[9.2]\n");
        pusservices_PI_addTm(&tmPacket);

        /* Reset counter */
		g_tmCounter = 0;
	}
}


/*! Process Service 9 TC
 * 
 * TC[9,1] set time report generation rate
 */
void pusservices_processTc09(const pusPacket_t *tcPacket)
{
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	errorCode = PUS_EXPECT_ST09TC(tcPacket, pusSubtype_NONE);
	if (PUS_NO_ERROR == errorCode)
	{
		//send 1.1
		printf(" - ST09: pus_TM_1_1_successfulAcceptance\n.");
		subtype = pus_TM_1_1_successfulAcceptance;
		pusservices_RI_ack(tcPacket, &subtype, &errorCode, &info, &step);

		pusSt09ExponentialRate_t expRate;
		if (PUS_NO_ERROR != pus_tc_9_1_getExponentialRate(&expRate, tcPacket))
		{
			errorCode = PUS_ERROR_NOT_INITIALIZED;
		}
		else
		{
			errorCode = pus_time_setReportGenerationExponentialRate(expRate);
			g_tmCounter = 0;
		}
	}
	else
	{
		errorCode = PUS_ERROR_TC_SERVICE;

		//send 1.2
		printf(" -ST09: pus_TM_1_2_failedAcceptance\n");
		subtype = pus_TM_1_2_failedAcceptance;
		pusservices_RI_ack(tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}

	if (PUS_NO_ERROR == errorCode)
	{
		//send 1.7
		subtype = pus_TM_1_7_successfulCompletion;
		pusservices_RI_ack(tcPacket, &subtype, &errorCode, &info, &step);
	}
	else
	{
		//send 1.8
		subtype = pus_TM_1_8_failedCompletion;
		pusservices_RI_ack(tcPacket, &subtype, &errorCode, &info, &step);
	}
}


#endif
