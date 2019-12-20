/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */


#include "pusservices_st01.h"
#include "pusservices_config.h"
#include "pusservices.h"
#include "pusservices_apid.h"
#include "pus_st01_packets.h"


/*! Initialize the service */
void pusservices_initService01(void)
{
    /* Nothing to do */
}


void pusservices_st01Ack(const asn1SccPusPacket *tcPacket, 
                         asn1SccPusSubserviceType reportType,
                         asn1SccPusSt01FailureCode error,
                         const asn1SccPusSt01FailureInfo *errorInfo,
                         asn1SccPusStepId step)
{
	if (NULL == tcPacket )
	{
		printf("Error st01_PI_ACK  -  NULL PARAM \n");
		exit(-1);
	}
	pus_clearError();

	printf(" - ST01: Packet TC%llu_%llu received, subtype: %llu, error %llu, step %llu\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket), reportType, error, step);

	pusPacket_t tm;
	pusApid_t apid = pusservices_getApid();
	pusSequenceCount_t seqCount = pusservices_getTmSequenceCount();

	if (pus_TM_1_1_successfulAcceptance == reportType && pus_getTcAckFlagAcceptance(tcPacket))
	{
		if (PUS_NO_ERROR == pus_tm_1_1_createAcceptanceReportSuccess(&tm, apid, seqCount, tcPacket))
		{
			printf(" - ST01: Creating successfulAcceptance from TC%llu_%llu send.\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));
			pusservices_PI_addTm(&tm);
		}
	}
	else if (pus_TM_1_2_failedAcceptance == reportType && pus_getTcAckFlagAcceptance(tcPacket))
	{
		if (PUS_NO_ERROR == pus_tm_1_2_createAcceptanceReportFailure(&tm, apid, seqCount, tcPacket, error, errorInfo))
		{
			printf(" - ST01: Creating failedAcceptance from TC%llu_%llu send.\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));
			pusservices_PI_addTm(&tm);
		}
	}
	else if (pus_TM_1_3_successfulStart == reportType && pus_getTcAckFlagStart(tcPacket))
	{
		if (PUS_NO_ERROR == pus_tm_1_3_createStartReportSuccess(&tm, apid, seqCount, tcPacket))
		{
			printf(" - ST01: Creating successfulStart from TC%llu_%llu send.\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));
			pusservices_PI_addTm(&tm);
		}
	}
	else if (pus_TM_1_4_failedStart == reportType && pus_getTcAckFlagStart(tcPacket))
	{
		if (PUS_NO_ERROR == pus_tm_1_4_createStartReportFailure(&tm, apid, seqCount, tcPacket, error, errorInfo))
		{
			printf(" - ST01: Creating failedStart from TC%llu_%llu send.\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));
			pusservices_PI_addTm(&tm);
		}
	}
	else if (pus_TM_1_5_successfulProgress == reportType && pus_getTcAckFlagProgress(tcPacket))
	{
		if (PUS_NO_ERROR == pus_tm_1_5_createProgressReportSuccess(&tm, apid, seqCount, tcPacket, step))
		{
			printf(" - ST01: Creating successfulProgress from TC%llu_%llu send.\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));
			pusservices_PI_addTm(&tm);
		}
	}
	else if (pus_TM_1_6_failedProgress == reportType && pus_getTcAckFlagProgress(tcPacket))
	{
		if (PUS_NO_ERROR == pus_tm_1_6_createProgressReportFailure(&tm, apid, seqCount, tcPacket, step, error, errorInfo))
		{
			printf(" - ST01: Creating failedProgress from TC%llu_%llu send.\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));
			pusservices_PI_addTm(&tm);
		}
	}
	else if (pus_TM_1_7_successfulCompletion == reportType && pus_getTcAckFlagCompletion(tcPacket))
	{
		if (PUS_NO_ERROR == pus_tm_1_7_createCompletionReportSuccess(&tm, apid, seqCount, tcPacket))
		{
			printf(" - ST01: Creating successfulCompletion from TC%llu_%llu send.\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));
			pusservices_PI_addTm(&tm);
		}
	}
	else if (pus_TM_1_8_failedCompletion == reportType && pus_getTcAckFlagCompletion(tcPacket))
	{
		if (PUS_NO_ERROR == pus_tm_1_8_createCompletionReportFailure(&tm, apid, seqCount, tcPacket, error, errorInfo))
		{
			printf(" - ST01: Creating failedCompletion from TC%llu_%llu send.\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));
			pusservices_PI_addTm(&tm);
		}
	}
	else
	{
		printf(" - ST01: No report TM1_%llu needed for TC%llu_%llu .\n", reportType, pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));
	}
}

