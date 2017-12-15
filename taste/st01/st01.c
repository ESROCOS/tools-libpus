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

	printf(" - ST01 Packet TC%llu_%llu received, subtype: %llu.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket), *IN_reportType);

	pusApid_t apid;
	pusSequenceCount_t seqCount;
	st01_RI_getApid(&apid);

	if( pus_TM_1_1_successfulAcceptance == *IN_reportType )
	{
		pusPacket_t tm;
		st01_RI_getSequenceCount(&seqCount);
		pus_tm_1_1_createAcceptanceReportSuccess(&tm, apid, seqCount, IN_tcPacket);
		printf(" - ST01: successfulAcceptance from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
		st01_RI_newTm(&tm);
	}
	else if( pus_TM_1_2_failedAcceptance == *IN_reportType )
	{
		pusPacket_t tm;
		st01_RI_getSequenceCount(&seqCount);
		pus_tm_1_2_createAcceptanceReportFailure(&tm, apid, seqCount, IN_tcPacket, *IN_error, IN_errorInfo);
		printf(" - ST01: failedAcceptance from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
		st01_RI_newTm(&tm);
	}
	else if( pus_TM_1_3_successfulStart == *IN_reportType )
	{

	}
	else if( pus_TM_1_4_failedStart == *IN_reportType )
	{

	}
	else if( pus_TM_1_5_successfulProgress == *IN_reportType )
	{

	}
	else if( pus_TM_1_6_failedProgress == *IN_reportType )
	{

	}
	else if( pus_TM_1_7_successfulCompletion == *IN_reportType )
	{

	}
	else if( pus_TM_1_8_failedCompletion == *IN_reportType )
	{

	}
	else
	{
		printf("Error st01_PI_ACK \n");
		exit(-1);
	}

}

