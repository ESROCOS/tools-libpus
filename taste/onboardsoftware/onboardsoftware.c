/* User code: This file will not be overwritten by TASTE. */

#include "onboardsoftware.h"
#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st05_config.h"
#include "pus_st20_config.h"

void onboardsoftware_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void onboardsoftware_PI_debugTrigger()
{
    /* Write your code here! */
	int test = 0;
	pusSt20OnBoardParamId_t changeHkParam = SET_HK_OUT_OF_RANGE_PARAM;
	pusSt03ParamId_t hkParam = HK_PARAM_BOOL01;
	pusStoredParam_t value;
	pusSt01FailureCode_t error;

	switch(test)
	{
		case 0:
		{
			printf(" - ON BOARD SOFTWARE: Event raised\n");
			pusSt05Event_t event;
			pus_events_createEVENT_INFO_01(&event, 23, 54);
			onboardsoftware_RI_pushNewEvent(&event);
			onboardsoftware_RI_getOnBoardParam(&changeHkParam, &value, &error);
			if (PUS_NO_ERROR == error && value == 1) {
				pusStoredParam_t val1 = 1;
				pusStoredParam_t val2 = 0;

				onboardsoftware_RI_setParamValue(&hkParam, &val1); //Sets HK_PARAM_BOOL01 out of range
				onboardsoftware_RI_setOnBoardParam(&changeHkParam, &val2);
			}
			break;
		}
		case 1:
		{
			break;
		}
		default:
			printf("No test\n");
	}


}

