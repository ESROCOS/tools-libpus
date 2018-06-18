/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_camera_control__
#define __USER_CODE_H_camera_control__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void camera_control_startup();

void camera_control_PI_operationRequest(const asn1SccPusSt200ControlId *);

void camera_control_PI_setCameraReport(const asn1SccT_UInt64 *);

extern void camera_control_RI_report(const asn1SccPusSt200Observation *);

extern void camera_control_RI_setFrameRequest();

#ifdef __cplusplus
}
#endif


#endif
