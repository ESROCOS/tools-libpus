/* User code: This file will not be overwritten by TASTE. */

#include "st03.h"

#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st03_packets.h"
#include "pus_housekeeping.h"
#include "pus_st03_config.h"

void st03_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void st03_PI_HkReportTrigger()
{
    /* Write your code here! */

	//TM3.25 report
	pusPacket_t tm;
	pusApid_t apid;
	pusSequenceCount_t seqCount;
	pusApid_t destination = 1;

	pusSt03HousekeepingReportId_t reportId = pus_ST03_DEFAULT_HK_REPORT;
	pusSt03ReportInfo_t reportInfo;
	if ( pus_ST03_DEFAULT_HK_REPORT == reportId )
	{

		reportInfo.numParams = pus_st03_defaultHkReportInfo.numParams;
		reportInfo.paramIds = pus_st03_defaultHkReportInfo.paramIds;
	}
	else
	{
		return;
	}

	st03_RI_getApid(&apid);
	st03_RI_getSequenceCount(&seqCount);

	pus_tm_3_25_createHousekeepingReport(&tm, apid, seqCount, reportId, destination);
	pus_tm_3_25_setNumParameters(&tm, reportInfo.numParams);
	pusStoredParam_t paramValue;
	pusSt01FailureCode_t isAvailable;
	for( size_t i = 0; i < reportInfo.numParams; i++)
	{
		st03_RI_getParamValue(&reportInfo.paramIds[i], &paramValue, &isAvailable);
		//printf("i: %lu, id: %llu, param:%llu\n", i, reportInfo.paramIds[i], paramValue);
		if( PUS_NO_ERROR == isAvailable )
		{
			pus_tm_3_25_setParameterValue(&tm, i, paramValue);
		}
		else
		{
			//printf("param not available\n");
			pus_tm_3_25_setParameterValue(&tm, i, 0);
		}
	}

	st03_RI_newTm(&tm);
}

