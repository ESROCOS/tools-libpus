/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

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

}


void onboardsoftware_PI_pusTrigger()
{
	onboardsoftware_RI_tcTrigger();

	onboardsoftware_RI_tmTrigger();


	if(varReports == 15)
	{
		onboardsoftware_RI_EventActionTrigger();

		onboardsoftware_RI_PmonTrigger();

		onboardsoftware_RI_schedulingTrigger();

		onboardsoftware_RI_HkReportTrigger();
		onboardsoftware_RI_EventReportTrigger();
		varReports = 0;
	}
	varReports++;
}



void onboardsoftware_PI_planHome (const asn1SccT_Boolean *IN_trig)
{
   // Write your code here
	printf("[OBSW] onboardsoftware_PI_planHome \n");
}


void onboardsoftware_PI_planMove (const asn1SccBase_Pose *IN_pose)
{
   // Write your code here
	printf("[OBSW] onboardsoftware_PI_planMove \n");
}

void onboardsoftware_PI_configHome(const asn1SccBase_Pose *IN_pose)
{
	printf("[OBSW] onboardsoftware_PI_configHome \n");
}

void onboardsoftware_PI_setRoboReportOBSW(const asn1SccPusSt201PlanObservation * status)
{
	printf("[OBSW] onboardsoftware_PI_setRoboReportOBSW \n");
}
