/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
 
/* User code: This file will not be overwritten by TASTE. */

#include "st17.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

#include "pus_st17_packets.h"



void st17_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void st17_PI_tc17(const asn1SccPusPacket *IN_tcPacket)
{
    /* Write your code here! */
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	pusError_t error = PUS_EXPECT_ST17TC(IN_tcPacket, pusSubtype_NONE);
	if( PUS_NO_ERROR == error )
	{
		printf(" - ST17: TC%llu_%llu received.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));

		printf(" - ST17: sending packet to ST01 Acceptance success\n");
		subtype = pus_TM_1_1_successfulAcceptance;
		st17_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);


		printf(" - ST17: processing packet\n");
		pusPacket_t outTm;
		pusApid_t apid;
		pusSequenceCount_t seqCount;
		st17_RI_getApid(&apid);
		st17_RI_getSequenceCount(&seqCount);
		pusError_t error = pus_tm_17_2_createConnectionTestReport(&outTm, apid, seqCount, IN_tcPacket->apid);
		printf(" - ST17: error: %d\n", error);
		if( PUS_NO_ERROR == error)
		{
			printf(" - ST17: Sending TM17.2\n");
			st17_RI_newTm(&outTm);
		}

	}
	else
	{
		subtype = pus_TM_1_2_failedAcceptance;
		errorCode = error;
		st17_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
		printf(" - ST17: Error in st17_PI_tc17, %d (no exit)\n", error);
	}

}

