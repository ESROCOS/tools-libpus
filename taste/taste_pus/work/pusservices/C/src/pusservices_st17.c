/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pusservices_config.h"

#ifdef PUSSERVICES_17_ENABLED

#include "pusservices_st17.h"
#include "pusservices.h"
#include "pusservices_apid.h"
#include "pus_st17_packets.h"


/*! Initialize the service */
void pusservices_initService17(void)
{
    /* Nothing to do */
}


/*! Process a PUS17 TC */
void pusservices_processTc17(const pusPacket_t *tcPacket)
{
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	pusError_t error = PUS_EXPECT_ST17TC(tcPacket, pusSubtype_NONE);
	if (PUS_NO_ERROR == error )
	{
		printf(" - ST17: TC%llu_%llu received.\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));

		printf(" - ST17: sending packet to ST01 Acceptance success\n");
		subtype = pus_TM_1_1_successfulAcceptance;
		pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);

		printf(" - ST17: processing packet\n");
		pusPacket_t outTm;
		pusApid_t apid = pusservices_getApid();
		pusSequenceCount_t seqCount = pusservices_getTmSequenceCount();
		pusError_t error = pus_tm_17_2_createConnectionTestReport(&outTm, apid, seqCount, tcPacket->apid);
		printf(" - ST17: error: %d\n", error);
		if (PUS_NO_ERROR == error)
		{
			printf(" - ST17: Sending TM17.2\n");
			pusservices_PI_addTm(&outTm);
		}

	}
	else
	{
		subtype = pus_TM_1_2_failedAcceptance;
		errorCode = error;
		pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);
		printf(" - ST17: Error in st17_PI_tc17, %d (continue)\n", error);
	}
}

#endif
