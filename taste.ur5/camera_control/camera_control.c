/* User code: This file will not be overwritten by TASTE. */

#include "camera_control.h"

#include "pus_types.h"


void camera_control_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void camera_control_PI_operationRequest(const asn1SccPusSt200ControlId *IN_operation)
{
    /* Write your code here! */
	camera_control_RI_setFrameRequest();
}

void camera_control_PI_setCameraReport(const asn1SccT_UInt64 *IN_status)
{
    /* Write your code here! */
	pusSt200Observation obs = *IN_status;
	camera_control_RI_report(&obs);
}

