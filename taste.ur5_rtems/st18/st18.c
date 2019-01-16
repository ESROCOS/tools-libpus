/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

/* User code: This file will not be overwritten by TASTE. */

#include "st18.h"
#include <stdio.h>

#include "pus_st18_packets.h"
#include "pus_obcp_engine.h"

void st18_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */

	pus_obcp_initialize(NULL);
}

void st18_PI_tc18(const asn1SccPusPacket *IN_tcPacket)
{
    /* Write your code here! */

    /* Write your code here! */
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	errorCode = PUS_EXPECT_ST18TC(IN_tcPacket, pusSubtype_NONE);
	if(PUS_NO_ERROR == errorCode )
	{
		//send 1.1
		subtype = pus_TM_1_1_successfulAcceptance;
		st18_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);


		pusSubservice_t subtype = pus_getTcSubtype(IN_tcPacket);
		if( pus_TC_18_1_loadObcpDirect == subtype )
		{
			pusSt18ObcpId_t obcpId;

			pusSt01FailureCode_t auxErr = pus_tc_18_X_getObcpId(&obcpId, IN_tcPacket);
			if(PUS_NO_ERROR != auxErr)
			{
				errorCode = auxErr;
			}
			else
			{
				pusSt18ObcpCode_t obcpCode;
				auxErr = pus_tc_18_1_getObcpCode(&obcpCode, IN_tcPacket);
				if(PUS_NO_ERROR != auxErr)
				{
					errorCode = auxErr;
				}
				else
				{
					errorCode = pus_obcp_loadObcp(&obcpId, &obcpCode);
				}
			}
		}
		else if( pus_TC_18_2_unloadObcp == subtype )
		{
			pusSt18ObcpId_t obcpId;

			pusSt01FailureCode_t auxErr = pus_tc_18_X_getObcpId(&obcpId, IN_tcPacket);
			if(PUS_NO_ERROR != auxErr)
			{
				errorCode = auxErr;
			}
			else
			{
				errorCode = pus_obcp_unloadObcp(&obcpId);
			}
		}
		else if( pus_TC_18_3_activateObcp == subtype )
		{
			pusSt18ObcpId_t obcpId;

			pusSt01FailureCode_t auxErr = pus_tc_18_X_getObcpId(&obcpId, IN_tcPacket);
			if(PUS_NO_ERROR != auxErr)
			{
				errorCode = auxErr;
			}
			else
			{
				errorCode = pus_obcp_activateObcp(&obcpId);
			}
		}
		else if( pus_TC_18_4_stopObcp == subtype )
		{
			pusSt18ObcpId_t obcpId;

			pusSt01FailureCode_t auxErr = pus_tc_18_X_getObcpId(&obcpId, IN_tcPacket);
			if(PUS_NO_ERROR != auxErr)
			{
				errorCode = auxErr;
			}
			else
			{
				errorCode = pus_obcp_stopObcp(&obcpId);
			}
		}
		else if( pus_TC_18_5_suspendObcp== subtype )
		{
			pusSt18ObcpId_t obcpId;

			pusSt01FailureCode_t auxErr = pus_tc_18_X_getObcpId(&obcpId, IN_tcPacket);
			if(PUS_NO_ERROR != auxErr)
			{
				errorCode = auxErr;
			}
			else
			{
				errorCode = pus_obcp_suspendObcp(&obcpId);
			}
		}
		else if( pus_TC_18_6_resumeObcp == subtype )
		{
			pusSt18ObcpId_t obcpId;

			pusSt01FailureCode_t auxErr = pus_tc_18_X_getObcpId(&obcpId, IN_tcPacket);
			if(PUS_NO_ERROR != auxErr)
			{
				errorCode = auxErr;
			}
			else
			{
				errorCode = pus_obcp_resumeObcp(&obcpId);
			}
		}
		else if( pus_TC_18_12_abortObcp == subtype )
		{
			pusSt18ObcpId_t obcpId;

			pusSt01FailureCode_t auxErr = pus_tc_18_X_getObcpId(&obcpId, IN_tcPacket);
			if(PUS_NO_ERROR != auxErr)
			{
				errorCode = auxErr;
			}
			else
			{
				errorCode = pus_obcp_abortObcp(&obcpId);
			}
		}
		/*else if( pus_TC_18_13_loadObcpByReference == subtype )
		{
			//errorCode = pus_obcp_
		}*/
		else if( pus_TC_18_21_startObcpEngine == subtype )
		{
			errorCode = pus_obcp_startEngine();
		}
		else if( pus_TC_18_22_stopObcpEngine == subtype )
		{
			errorCode = pus_obcp_stopEngine();
		}
		else
		{
			errorCode = PUS_ERROR_TC_SUBTYPE;
		}

	}
	else
	{
		errorCode = PUS_ERROR_TC_SERVICE;

		//send 1.2
		subtype = pus_TM_1_2_failedAcceptance;
		st18_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}

	if( PUS_NO_ERROR == errorCode)
	{
		//send 1.7
		subtype = pus_TM_1_7_successfulCompletion;
		st18_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
	else
	{
		//send 1.8
		subtype = pus_TM_1_8_failedCompletion;
		st18_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
}

