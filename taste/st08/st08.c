/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
 
/* User code: This file will not be overwritten by TASTE. */

#include "st08.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "functions.h"

#include "pus_st08_packets.h"
#include "pus_st08_config.h"

void st08_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	pus_st08_initialize(NULL);
}

void st08_PI_tc08(const asn1SccPusPacket *IN_tcPacket)
{
    /* Write your code here! */

	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	pusSt01FailureCode_t errorExpect = PUS_EXPECT_ST08(IN_tcPacket, pus_TC_8_1_performFunction);
	if( PUS_NO_ERROR == errorExpect )
	{
		printf(" - ST08: TC%llu_%llu received.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));

		//send acceptance success
		printf(" - ST08: send pus_TM_1_1_successfulAcceptance \n");

		subtype = pus_TM_1_1_successfulAcceptance;
		st08_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);

		printf(" - ST08: Processing packet\n");
		pusSt08FunctiontId_t functionId;
		pus_tc_8_1_getFunctionId(&functionId, IN_tcPacket);
		if( pus_st08_isInFunctionTable(functionId) )
		{
			subtype = pus_TM_1_3_successfulStart;
			printf(" - ST08: send pus_TM_1_3_successfulStart\n");
			st08_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);

			errorExpect = pus_st08_functionTable[functionId]();
			if( PUS_NO_ERROR == errorExpect )
			{
				//send completion success
				printf(" - ST08: send pus_TM_1_7_successfulCompletion \n");
				subtype = pus_TM_1_7_successfulCompletion;
				st08_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
			}
			else
			{
				printf(" - ST08: send pus_TM_1_8_failedCompletion \n");
				subtype = pus_TM_1_8_failedCompletion;
				errorCode = errorExpect;
				st08_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
			}
			return;
		}
		printf(" - ST08: send pus_TM_1_8_failedCompletion \n");
		subtype = pus_TM_1_4_failedStart;
		errorCode = PUS_ERROR_UNEXPECTED_FUNCTION_ID;
		st08_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}
	else
	{
		//send acceptance failure
		printf(" - ST08: send pus_TM_1_2_failedAcceptance \n");
		//st08_RI_ACK(IN_tcPacket, &pus_TM_1_2_failedAcceptance, &errorExpect, NULL, NULL);
		/*subtype = pus_TM_1_2_failedAcceptance;
		errorCode = errorExpect;
		st08_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);*/
		return;
	}
}

