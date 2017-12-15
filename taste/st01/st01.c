/* User code: This file will not be overwritten by TASTE. */

#include "st01.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

pusApidInfo_t apidSt01;

void st01_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */

	pus_initApidInfo(&apidSt01, 3, NULL);

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

	printf(" - ST01 Packet TC%llu_%llu received, subtype: %d.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket), *IN_reportType);

	if( pus_TM_1_1_successfulAcceptance == *IN_reportType )
	{
		pusPacket_t tm;
		pus_tm_1_1_createAcceptanceReportSuccess(&tm, &apidSt01, IN_tcPacket);
		printf(" - ST01: successfulAcceptance from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
		st17_RI_newTm(&tm);
	}
	else if( pus_TM_1_2_failedAcceptance == *IN_reportType )
	{
		pusPacket_t tm;
		pus_tm_1_2_createAcceptanceReportFailure(&tm, &apidSt01, IN_tcPacket, *IN_error, *IN_errorInfo);
		printf(" - ST01: failedAcceptance from TC%llu_%llu send.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
		st17_RI_newTm(&tm);
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

