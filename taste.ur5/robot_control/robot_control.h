/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_robot_control__
#define __USER_CODE_H_robot_control__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void robot_control_startup();

void robot_control_PI_setHome(const asn1SccPusTC_201_1_3_Data *);

void robot_control_PI_planHomeRequest();

void robot_control_PI_planMoveRequest(const asn1SccPusTC_201_1_3_Data *);

void robot_control_PI_planHomeReport(const asn1SccPlanCmdStatus *);

void robot_control_PI_planMoveReport(const asn1SccPlanCmdStatus *);

extern void robot_control_RI_report(const asn1SccPusSt201PlanObservation *);

extern void robot_control_RI_planMove(const asn1SccBase_Pose *);

extern void robot_control_RI_planHome(const asn1SccBase_Pose *);

#ifdef __cplusplus
}
#endif


#endif
