/* User code: This file will not be overwritten by TASTE. */

#include "st18.h"

#include "pus_st18_packets.h"
#include "pus_obcp_engine.h"

void st18_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */

	pus_obcp_initialize(NULL);

	const size_t testUpy_len[] = { 142 };
	const uint8_t *testUpy_data[] = {
	    (const uint8_t*)"\x4d\x02\x02\x1f\x2a\x05\x00\x00\x00\x00\x00\x08\x0a\x00\xf1\x00\x29\x00\x00\xff\x80\x11\x68\xf2\x00\x24\xf2\x00\x1b\xc1\x00\x17\x00\x1b\xf2\x00\x1e\xf3\x00\x97\x66\x01\x64\x02\x32\x11\x5b\x08\x3c\x6d\x6f\x64\x75\x6c\x65\x3e\x08\x63\x6f\x64\x65\x33\x2e\x70\x79\x0a\x74\x65\x73\x74\x6d\x6f\x64\x75\x6c\x65\x0a\x74\x65\x73\x74\x6d\x6f\x64\x75\x6c\x65\x05\x70\x72\x69\x6e\x74\x0a\x74\x65\x73\x74\x6d\x6f\x64\x75\x6c\x65\x09\x68\x65\x6c\x6c\x6f\x54\x65\x73\x74\x01\x00\x73\x18\x48\x69\x20\x66\x72\x6f\x6d\x20\x75\x50\x79\x3a\x20\x54\x65\x73\x74\x69\x6e\x67\x20\x41\x50\x49",
	};

	pusSt18ObcpId_t id1;
	memcpy(id1.arr, "OBCP_1\0", 10);

	pusSt18ObcpCode_t code1;
	memcpy(code1.arr, testUpy_data[0], testUpy_len[0]);
	code1.nCount = testUpy_len[0];
	printf("OBCP START load:%d\n", pus_obcp_loadObcp(&id1, &code1));

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

