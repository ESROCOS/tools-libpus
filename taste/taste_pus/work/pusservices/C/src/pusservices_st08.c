/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pusservices_config.h"

#ifdef PUSSERVICES_08_ENABLED

#include "pusservices_st08.h"
#include "pusservices.h"
#include "pus_st08_config.h"
#include "pus_st08_packets.h"


/*! Initialize the service */
void pusservices_initService08(void)
{
	pus_st08_initialize(NULL);
}


/*! Process a PUS08 TC */
void pusservices_processTc08(const pusPacket_t *tcPacket)
{
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	pusSt01FailureCode_t errorExpect = PUS_EXPECT_ST08(tcPacket, pus_TC_8_1_performFunction);
	if( PUS_NO_ERROR == errorExpect )
	{
		printf(" - ST08: TC%llu_%llu received.\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));

		//send acceptance success
		printf(" - ST08: send pus_TM_1_1_successfulAcceptance \n");

		subtype = pus_TM_1_1_successfulAcceptance;
		pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);

		printf(" - ST08: Processing packet\n");
		pusSt08FunctiontId_t functionId;
		pus_tc_8_1_getFunctionId(&functionId, tcPacket);
		if( pus_st08_isInFunctionTable(functionId) )
		{
			subtype = pus_TM_1_3_successfulStart;
			printf(" - ST08: send pus_TM_1_3_successfulStart\n");
			pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);

			errorExpect = pus_st08_functionTable[functionId]();
			if( PUS_NO_ERROR == errorExpect )
			{
				//send completion success
				printf(" - ST08: send pus_TM_1_7_successfulCompletion \n");
				subtype = pus_TM_1_7_successfulCompletion;
				pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);
			}
			else
			{
				printf(" - ST08: send pus_TM_1_8_failedCompletion \n");
				subtype = pus_TM_1_8_failedCompletion;
				errorCode = errorExpect;
				pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);
			}
			return;
		}
		printf(" - ST08: send pus_TM_1_8_failedCompletion \n");
		subtype = pus_TM_1_4_failedStart;
		errorCode = PUS_ERROR_UNEXPECTED_FUNCTION_ID;
		pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}
	else
	{
		//send acceptance failure
		printf(" - ST08: send pus_TM_1_2_failedAcceptance \n");
		subtype = pus_TM_1_2_failedAcceptance;
		pusservices_PI_ack(tcPacket, &subtype, &errorExpect, NULL, NULL);
		return;
	}
}

#endif
