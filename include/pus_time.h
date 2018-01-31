/*! \file pus_time.h
 *  \brief Functions to read the on-board time and convert to/from POSIX time.
 *
 *  The \ref pusTime_t type is defined in \ref pus_types.h.
 *
 *  This module provides support functions for reading the on-board time and
 *  converting the PUS library time type to POSIX and back.
 *
 *  The purpose of the module is to allow for the adaptation of the PUS library
 *  to different on-board time representations.
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_TIME_H
#define PUS_TIME_H

#include <time.h>
#include "pus_types.h"

#ifdef  __cplusplus
extern "C" {
#endif
//! Get the current time
void pus_now(pusTime_t* outNow);

//! Convert to POSIX timespec
void pus_time2posix(struct timespec* outPosixTime, const pusTime_t* pusTime);

//! Convert from POSIX timespec
void pus_posix2time(pusTime_t* outPusTime, const struct timespec* posixTime);

#ifdef  __cplusplus
}
#endif

#endif // PUS_TIME_H
