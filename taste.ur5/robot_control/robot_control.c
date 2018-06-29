/* User code: This file will not be overwritten by TASTE. */

#include "robot_control.h"

#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_robot_control.h"

void robot_control_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	pus_robotControl_initialize(NULL);
}

void robot_control_PI_setHome(const asn1SccPusTC_201_1_3_Data *IN_pusPose)
{
    /* Write your code here! */      
        asn1SccBase_Pose pose;

	pose.orientation.re = 0;// idk what is this :)
	pose.orientation.im.nCount = 3;
	pose.position.data.nCount = 3;

	for(int i = 0; i<3; i++)
	{
		pose.orientation.im.arr[i] = IN_pusPose->orientation.arr[i];
		pose.position.data.arr[i] = IN_pusPose->position.arr[i];
	}

	robot_control_RI_configHome(&pose);
        
}

void robot_control_PI_planHomeRequest()
{
    /* Write your code here! */
	asn1SccT_Boolean trig = 1;

	robot_control_RI_planHome(&trig);
}

void robot_control_PI_planMoveRequest(const asn1SccPusTC_201_1_3_Data *IN_pusPose)
{
    /* Write your code here! */
	asn1SccBase_Pose poseMove;

	poseMove.orientation.re = 0;// idk what is this :)
	poseMove.orientation.im.nCount = 3;
	poseMove.position.data.nCount = 3;

	for(int i = 0; i<3; i++)
	{
		poseMove.orientation.im.arr[i] = IN_pusPose->orientation.arr[i];
		poseMove.position.data.arr[i] = IN_pusPose->position.arr[i];
	}

	robot_control_RI_planMove(&poseMove);
}

void robot_control_PI_planHomeReport(const asn1SccPlanCmdStatus *IN_status)
{
    /* Write your code here! */
	pusSt201PlanObservation obs;
	obs.id = 0;
	obs.code = *IN_status;
	robot_control_RI_report(&obs);
}

void robot_control_PI_planMoveReport(const asn1SccPlanCmdStatus *IN_status)
{
    /* Write your code here! */
	pusSt201PlanObservation obs;
	obs.id = 1;
	obs.code = *IN_status;
	robot_control_RI_report(&obs);
}

void robot_control_PI_configHomeReport(const asn1SccT_Boolean *IN_status)
{
    /* Write your code here! */
	pusSt201PlanObservation obs;
	obs.id = 2;
	obs.code = *IN_status;
	robot_control_RI_report(&obs);
}
