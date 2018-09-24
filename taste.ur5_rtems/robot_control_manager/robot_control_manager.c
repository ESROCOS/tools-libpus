/* User code: This file will not be overwritten by TASTE. */

#include "robot_control_manager.h"

#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_robot_control.h"

bool flag_setHomeReceived;
bool flag_planHomeReceived;
bool flag_planMoveReceived;

asn1SccBase_Pose poseMove_setHome;
asn1SccBase_Pose poseMove_planMove;

void robot_control_manager_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	pus_robotControl_initialize(NULL);
	flag_setHomeReceived = false;
	flag_planHomeReceived = false;
	flag_planMoveReceived = false;
}

void robot_control_manager_PI_trigger()
{
	if(true == flag_setHomeReceived)
	{
		flag_setHomeReceived = false;
		robot_control_manager_RI_configHome(&poseMove_setHome);
	}
	if(true == flag_planHomeReceived)
	{
		flag_planHomeReceived = false;
		asn1SccT_Boolean aux = 1;
		robot_control_manager_RI_planHome(&aux);
	}	
	if(true == flag_planMoveReceived)
	{
		flag_planMoveReceived = false;
		robot_control_manager_RI_planMove(&poseMove_planMove);
	}
}



void robot_control_manager_PI_setHome(const asn1SccPusTC_201_1_3_Data *IN_pusPose)
{
    /* Write your code here! */
	pus_robotControl_setHomeOrientationPoints(IN_pusPose->orientation.arr[0], IN_pusPose->orientation.arr[1], IN_pusPose->orientation.arr[2], IN_pusPose->orientation.arr[3]);
	pus_robotControl_setHomePositionPoints(IN_pusPose->position.arr[0], IN_pusPose->position.arr[1], IN_pusPose->position.arr[2]);

	poseMove_setHome.orientation.im.nCount = 3;
	poseMove_setHome.position.data.nCount = 3;

	for(int i = 0; i<3; i++)
	{
		poseMove_setHome.orientation.im.arr[i] = IN_pusPose->orientation.arr[i];
		poseMove_setHome.position.data.arr[i] = IN_pusPose->position.arr[i];
	}
	poseMove_setHome.orientation.re = IN_pusPose->orientation.arr[3];

	flag_setHomeReceived = true;
}

void robot_control_manager_PI_planHomeRequest()
{
    /* Write your code here! */	 
	flag_planHomeReceived = true;
}

void robot_control_manager_PI_planMoveRequest(const asn1SccPusTC_201_1_3_Data *IN_pusPose)
{
    /* Write your code here! */	
	poseMove_planMove.orientation.im.nCount = 3;
	poseMove_planMove.position.data.nCount = 3;

	for(int i = 0; i<3; i++)
	{
		poseMove_planMove.orientation.im.arr[i] = IN_pusPose->orientation.arr[i];
		poseMove_planMove.position.data.arr[i] = IN_pusPose->position.arr[i];
	}
	poseMove_planMove.orientation.re = IN_pusPose->orientation.arr[3];

	flag_planMoveReceived = true;
}

void robot_control_manager_PI_planHomeReport(const asn1SccPlanCmdStatus *IN_status)
{
    /* Write your code here! */
	pusSt201PlanObservation obs;
	obs.id = 2;
	obs.code = *IN_status;
	robot_control_manager_RI_report(&obs);
	robot_control_manager_RI_setRobotReportOBSW(&obs);
}

void robot_control_manager_PI_planMoveReport(const asn1SccPlanCmdStatus *IN_status)
{
    /* Write your code here! */
	pusSt201PlanObservation obs;
	obs.id = 3;
	obs.code = *IN_status;
	robot_control_manager_RI_report(&obs);
	robot_control_manager_RI_setRobotReportOBSW(&obs);
}

void robot_control_manager_PI_configHomeReport(const asn1SccT_Boolean * IN_status)
{
	pusSt201PlanObservation obs;
	obs.id = 1;
	obs.code = *IN_status;
	robot_control_manager_RI_report(&obs);
	robot_control_manager_RI_setRobotReportOBSW(&obs);
}

