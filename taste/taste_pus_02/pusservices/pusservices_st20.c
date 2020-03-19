/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

#include "pusservices_st20.h"
#include "pusservices.h"
#include <stdio.h>
#include "pus_types.h"
#include "pus_error.h"

#include "pus_st20_packets.h"

/*! Initialize the service */
void pusservices_initService20()
{
    /*Nothing to do*/
}

void pusservices_processTc20(const asn1SccPusPacket *IN_tcPacket)
{
    /* Write your code here! */
	pusSubservice_t subtype;
	pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
	pusSt01FailureInfo_t info;
	pusStepId_t step = 0;

	errorCode = PUS_EXPECT_ST20TC(IN_tcPacket, pusSubtype_NONE);
	if(PUS_NO_ERROR == errorCode )
	{
		//send 1.1
		subtype = pus_TM_1_1_successfulAcceptance;
		pusservices_PI_ack(IN_tcPacket, &subtype, &errorCode, &info, &step);//st20_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);


		pusSubservice_t subtype = pus_getTcSubtype(IN_tcPacket);
		if( pus_TC_20_1_reportParameterValues == subtype )
		{
			pusSt20OnBoardParamId_t paramId;
			pusStoredParam_t paramValue;
			paramId = pus_tc_20_X_getParamId(IN_tcPacket);
			errorCode = pus_parameters_getStoredParam(paramId, &paramValue);
			if( PUS_NO_ERROR == errorCode)
			{
				pusPacket_t tm;
				pusApid_t apid, destination;
				pusSequenceCount_t seqCount;

				apid = pusservices_getApid();// st20_RI_getApid(&apid);
				seqCount = pusservices_getTmSequenceCount();// st20_RI_getSequenceCount(&seqCount);
				destination = pus_getApid(IN_tcPacket);

				errorCode = pus_tm_20_2_createParameterValueReport(&tm, apid, seqCount, destination, paramId, paramValue);
				if( PUS_NO_ERROR == errorCode)
				{
					pusservices_PI_addTm(&tm);// st20_RI_newTm(&tm);
				}
			}
		}
		else if( pus_TC_20_3_setParameterValues == subtype )
		{
			pusSt20OnBoardParamId_t paramId;
			pusStoredParam_t paramValue;
			paramValue = pus_tc_20_3_getParamValue(IN_tcPacket);
			paramId = pus_tc_20_X_getParamId(IN_tcPacket);
			errorCode = pus_parameters_setStoredParam(paramId, paramValue);
			printf(" - ST20 setparam: id %llu, value %llu, error %llu", paramId, paramValue, errorCode);

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
		pusservices_PI_ack(IN_tcPacket, &subtype, &errorCode, &info, &step);// st20_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
		return;
	}

	if( PUS_NO_ERROR == errorCode)
	{
		//send 1.7
		subtype = pus_TM_1_7_successfulCompletion;
		pusservices_PI_ack(IN_tcPacket, &subtype, &errorCode, &info, &step);//st20_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
	else
	{
		//send 1.8
		subtype = pus_TM_1_8_failedCompletion;
		pusservices_PI_ack(IN_tcPacket, &subtype, &errorCode, &info, &step);//st20_RI_ACK(IN_tcPacket, &subtype, &errorCode, &info, &step);
	}
}

