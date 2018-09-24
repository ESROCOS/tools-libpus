/* User code: This file will not be overwritten by TASTE. */

#include "onboardsoftware.h"
#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st05_config.h"
#include "pus_st20_config.h"


int varReports;
void onboardsoftware_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	varReports = 0;
}

void onboardsoftware_PI_debugTrigger()
{
    /* Write your code here! */
	int test = 0;
	pusSt20OnBoardParamId_t changeHkParam = SET_HK_OUT_OF_RANGE_PARAM, throwEventsParam = SET_THROW_EVENTS_PARAM;
	pusSt03ParamId_t hkParam = HK_PARAM_BOOL01;
	pusStoredParam_t value;
	pusSt01FailureCode_t error;

	switch(test)
	{
		case 0:
		{
			onboardsoftware_RI_getOnBoardParam(&throwEventsParam, &value, &error);
			if (PUS_NO_ERROR == error && value == 1) {
				printf(" - ON BOARD SOFTWARE: Events raised\n");

				pusSt05Event_t event;
				pus_events_createEVENT_INFO_01(&event, 23, 54);
				onboardsoftware_RI_pushNewEvent(&event);
				pus_events_createEVENT_LOW_02(&event, 23, 54);
				onboardsoftware_RI_pushNewEvent(&event);
				pus_events_createEVENT_MEDIUM_03(&event, 23, 54);
				onboardsoftware_RI_pushNewEvent(&event);
				pus_events_createEVENT_HIGH_04(&event, 23, 54);
				onboardsoftware_RI_pushNewEvent(&event);
			}
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


void onboardsoftware_PI_pusTrigger()
{
	onboardsoftware_RI_tcTrigger();

	onboardsoftware_RI_tmTrigger();

	onboardsoftware_RI_EventActionTrigger();

	onboardsoftware_RI_PmonTrigger();

	onboardsoftware_RI_schedulingTrigger();

	if(varReports == 23)
	{
		onboardsoftware_RI_HkReportTrigger();
		onboardsoftware_RI_EventReportTrigger();
		varReports = 0;
	}
	varReports++;
}



void onboardsoftware_PI_planHome (const asn1SccT_Boolean *IN_trig)
{
   // Write your code here
	printf(" -OBSW: onboardsoftware_PI_planHome \n");
}


void onboardsoftware_PI_planMove (const asn1SccBase_Pose *IN_pose)
{
   // Write your code here
	printf(" -OBSW: onboardsoftware_PI_planMove \n");
}

void onboardsoftware_PI_configHome(const asn1SccBase_Pose *IN_pose)
{
	printf("onboardsoftware_PI_configHome \n");
}

void onboardsoftware_PI_setRoboReportOBSW(const asn1SccPusSt201PlanObservation * status)
{
	printf("onboardsoftware_PI_setRoboReportOBSW \n");
}
