/* User code: This file will not be overwritten by TASTE. */

#include "st01.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_types.h"

#include "pus_st01_packets.h"

void st01_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void st01_PI_ACK(const asn1SccPusPacket *IN_tcPacket,
                 const asn1SccPusSubserviceType *IN_reportType,
                 const asn1SccPusSt01FailureCode *IN_error,
                 const asn1SccPusSt01FailureInfo *IN_errorInfo,
				 const asn1SccPusStepId *IN_step)
{
    /* Write your code here! */
	if( NULL == IN_tcPacket || NULL == IN_reportType )
	{
		printf("Error st01_PI_ACK  -  NULL PARAM \n");
		exit(-1);
	}
	pus_clearError();

	printf(" - ST01: Packet TC%llu_%llu received, subtype: %llu, error %llu, step %llu\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket), *IN_reportType, *IN_error, *IN_step);

	pusApid_t apid;
	pusSequenceCount_t seqCount;
	st01_RI_getApid(&apid);

	if( pus_TM_1_1_successfulAcceptance == *IN_reportType && pus_getTcAckFlagAcceptance(IN_tcPacket))
	{
		pusPacket_t tm;
		st01_RI_getSequenceCount(&seqCount);
		if( PUS_NO_ERROR == pus_tm_1_1_createAcceptanceReportSuccess(&tm, apid, seqCount, IN_tcPacket))
		{
			printf(" - ST01: Creating successfulAcceptance from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
			st01_RI_newTm(&tm);
		}
	}
	else if( pus_TM_1_2_failedAcceptance == *IN_reportType && pus_getTcAckFlagAcceptance(IN_tcPacket))
	{
		pusPacket_t tm;
		st01_RI_getSequenceCount(&seqCount);
		if( PUS_NO_ERROR == pus_tm_1_2_createAcceptanceReportFailure(&tm, apid, seqCount, IN_tcPacket, *IN_error, IN_errorInfo))
		{
			printf(" - ST01: Creating failedAcceptance from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
			st01_RI_newTm(&tm);
		}
	}
	else if( pus_TM_1_3_successfulStart == *IN_reportType && pus_getTcAckFlagStart(IN_tcPacket))
	{
		pusPacket_t tm;
		st01_RI_getSequenceCount(&seqCount);
		if( PUS_NO_ERROR == pus_tm_1_3_createStartReportSuccess(&tm, apid, seqCount, IN_tcPacket))
		{
			printf(" - ST01: Creating successfulStart from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
			st01_RI_newTm(&tm);
		}
	}
	else if( pus_TM_1_4_failedStart == *IN_reportType && pus_getTcAckFlagStart(IN_tcPacket))
	{
		pusPacket_t tm;
		st01_RI_getSequenceCount(&seqCount);
		if( PUS_NO_ERROR == pus_tm_1_4_createStartReportFailure(&tm, apid, seqCount, IN_tcPacket, *IN_error, IN_errorInfo))
		{
			printf(" - ST01: Creating failedStart from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
			st01_RI_newTm(&tm);
		}
	}
	else if( pus_TM_1_5_successfulProgress == *IN_reportType && pus_getTcAckFlagProgress(IN_tcPacket))
	{
		pusPacket_t tm;
		st01_RI_getSequenceCount(&seqCount);
		if( PUS_NO_ERROR == pus_tm_1_5_createProgressReportSuccess(&tm, apid, seqCount, IN_tcPacket, *IN_step))
		{
			printf(" - ST01: Creating successfulProgress from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
			st01_RI_newTm(&tm);
		}
	}
	else if( pus_TM_1_6_failedProgress == *IN_reportType && pus_getTcAckFlagProgress(IN_tcPacket))
	{
		pusPacket_t tm;
		st01_RI_getSequenceCount(&seqCount);
		if( PUS_NO_ERROR == pus_tm_1_6_createProgressReportFailure(&tm, apid, seqCount, IN_tcPacket, *IN_step, *IN_error, IN_errorInfo))
		{
			printf(" - ST01: Creating failedProgress from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
			st01_RI_newTm(&tm);
		}
	}
	else if( pus_TM_1_7_successfulCompletion == *IN_reportType && pus_getTcAckFlagCompletion(IN_tcPacket))
	{
		pusPacket_t tm;
		st01_RI_getSequenceCount(&seqCount);
		if( PUS_NO_ERROR == pus_tm_1_7_createCompletionReportSuccess(&tm, apid, seqCount, IN_tcPacket))
		{
			printf(" - ST01: Creating successfulCompletion from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
			st01_RI_newTm(&tm);
		}
	}
	else if( pus_TM_1_8_failedCompletion == *IN_reportType && pus_getTcAckFlagCompletion(IN_tcPacket))
	{
		pusPacket_t tm;
		st01_RI_getSequenceCount(&seqCount);
		if( PUS_NO_ERROR == pus_tm_1_8_createCompletionReportFailure(&tm, apid, seqCount, IN_tcPacket, *IN_error, IN_errorInfo))
		{
			printf(" - ST01: Creating failedCompletion from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
			st01_RI_newTm(&tm);
		}
	}
	else
	{
		printf(" - ST01: No report TM1_%llu needed for TC%llu_%llu .\n", *IN_reportType, pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
	}

}

