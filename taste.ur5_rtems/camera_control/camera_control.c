/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

/* User code: This file will not be overwritten by TASTE. */

#include "camera_control.h"

#include "pus_types.h"

bool flag_operationRequestReceived;

void camera_control_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
    flag_operationRequestReceived = false;
}

void camera_control_PI_trigger()
{
    if( true == flag_operationRequestReceived )
    {
        flag_operationRequestReceived = false;
        asn1SccT_UInt64 aux = 1;
        camera_control_RI_setFrameRequest(&aux);
    } 
}


void camera_control_PI_operationRequest(const asn1SccPusSt200ControlId *IN_operation)
{
    /* Write your code here! */
    flag_operationRequestReceived = true;
}

void camera_control_PI_setCameraReport(const asn1SccT_UInt64 *IN_status)
{
    /* Write your code here! */
	pusSt200Observation obs = *IN_status;
	camera_control_RI_report(&obs);
}

