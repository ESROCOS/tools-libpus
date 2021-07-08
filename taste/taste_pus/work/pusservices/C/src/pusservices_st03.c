/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
 
/* User code: This file will not be overwritten by TASTE. */

//#include "pusservices_st03.h"
#include "pusservices_apid.h"

#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st03_packets.h"
#include "pus_housekeeping.h"
#include "pus_st03_config.h"

/*! Initialize the service */
void pusservices_initService03(void)
{
    /*Initialization of Housekeeping*/
    pus_hk_initialize(NULL);
	//pus_hk_setHK_PARAM_INT01(5);
	//pus_hk_setHK_PARAM_REAL01(100.0);
	//pus_hk_setHK_PARAM_INT02(6);
	//pus_hk_setHK_PARAM_UINT01(10);
	//pus_hk_setHK_PARAM_BYTE01(0x3);
	//pus_hk_setHK_PARAM_BOOL01(false);
}

void pusservices_st03HkReportTrigger()
{
	//TM3.25 report
	pusPacket_t tm;
	pusApid_t apid;
	pusSequenceCount_t seqCount;
	pusApid_t destination = 1;

	pusSt03HousekeepingReportId_t reportId = pus_ST03_DEFAULT_HK_REPORT;
	pusSt03ReportInfo_t reportInfo;
	if ( pus_ST03_DEFAULT_HK_REPORT == reportId )
	{
		//pus_hk_getReportParams
		reportInfo.numParams = pus_st03_HkReportInfos[reportId].numParams;
		reportInfo.paramIds = pus_st03_HkReportInfos[reportId].paramIds;
	}
	else
	{
		return;
	}

    apid = pusservices_getApid();//st03_RI_getApid(&apid); 
    seqCount = pusservices_getTmSequenceCount();//st03_RI_getSequenceCount(&seqCount);
	

	pus_tm_3_25_createHousekeepingReport(&tm, apid, seqCount, reportId, destination);
	pus_tm_3_25_setNumParameters(&tm, reportInfo.numParams);
	pusStoredParam_t paramValue;
	pusSt01FailureCode_t isAvailable;
	for( size_t i = 0; i < reportInfo.numParams; i++)
	{
        isAvailable = pus_hk_getStoredParam(reportInfo.paramIds[i], &paramValue);//st03_RI_getParamValue(&reportInfo.paramIds[i], &paramValue, &isAvailable); 
		printf("i: %lu, id: %llu, param:%llu\n", i, reportInfo.paramIds[i], paramValue);
		if( PUS_NO_ERROR == isAvailable )
		{
			pus_tm_3_25_setParameterValue(&tm, i, paramValue);
		}
		else
		{
			printf("param not available\n");
		}
	}


	pusservices_PI_addTm(&tm); 
}

void pusservices_processTc03(const pusPacket_t *tcPacket)
{
    pusSubservice_t subtype;
    pusSt01FailureCode_t errorCode = PUS_NO_ERROR;
    pusSt01FailureInfo_t info;
    pusStepId_t step = 0;
    pusSt03HousekeepingReportId_t reportId;
    pusSt01FailureCode_t errorExpect = PUS_EXPECT_ST03TC(tcPacket, pusSubtype_NONE);
    if( PUS_NO_ERROR == errorExpect )
    {
        printf(" - ST03: TC%llu_%llu received.\n", pus_getTcService(tcPacket), pus_getTcSubtype(tcPacket));
        subtype = pus_TM_1_1_successfulAcceptance;
        pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);
        if(pus_getTcSubtype(tcPacket) == pus_TC_3_5_enablePeriodicHousekeeping)
        {
            reportId = pus_tc_3_5_getReportId(tcPacket);
            errorCode = pus_hk_enableReport(reportId);
        }
        else /* TC(3,6) */
        {
            reportId = pus_tc_3_6_getReportId(tcPacket);
            errorCode = pus_hk_disableReport(reportId);
        }
        if(errorCode == PUS_NO_ERROR)
        {
            printf(" - ST03: send pus_TM_1_7_successfulCompletion \n");
            subtype = pus_TM_1_7_successfulCompletion;
            pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);
        }
        else
        {
            printf(" - ST03: send pus_TM_1_8_failedCompletion \n");
            subtype = pus_TM_1_8_failedCompletion;
            pusservices_PI_ack(tcPacket, &subtype, &errorCode, &info, &step);
        }
        return;
    }
    else
    {
        //send acceptance failure
        printf(" - ST08: send pus_TM_1_2_failedAcceptance \n");
        subtype = pus_TM_1_2_failedAcceptance;
        pusservices_PI_ack(tcPacket, &subtype, &errorExpect, &info, &step);
        return;
    }
}

