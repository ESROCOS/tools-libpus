/*! \file pus_parameter_monitoring.h
 *  \brief Management of the parameter monitoring table
 *
 *  Defines the parameters monitoring table used by the service ST[12].
 *
 *  Access to the table is optionally protected by a mutex. This allows implementing
 *  the service using external synchronization (by TASTE) or not.
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_ROBOT_CONTROL_H
#define PUS_ROBOT_CONTROL_H


#ifdef  __cplusplus
extern "C" {
#endif

#include "pus_types.h"
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_threads.h"


pusError_t pus_robotControl_initialize(pusMutex_t* mutex);

pusError_t pus_robotControl_finalize();

bool pus_robotControl_isInitialized();


pusError_t pus_robotControl_setHomePositionPoints(pusSt201Point point1, pusSt201Point point2, pusSt201Point point3);

pusError_t pus_robotControl_getHomePositionPoints(pusSt201Point* point1, pusSt201Point* point2, pusSt201Point* point3);


pusError_t pus_robotControl_setHomeOrientationPoints(pusSt201Point point1, pusSt201Point point2, pusSt201Point point3, pusSt201Point point4);

pusError_t pus_robotControl_getHomeOrientationPoints(pusSt201Point* point1, pusSt201Point* point2, pusSt201Point* point3, pusSt201Point* point4);



#ifdef  __cplusplus
}
#endif


#endif
