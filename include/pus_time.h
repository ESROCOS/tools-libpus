#ifndef PUS_TIME_H
#define PUS_TIME_H

#include <time.h>
#include "pus_types.h"

//! Get the current time
void pus_now(pusTime_t* outNow);

//! Convert to POSIX timespec
void pus_time2posix(struct timespec* outPosixTime, const pusTime_t* pusTime);

//! Convert from POSIX timespec
void pus_posix2time(pusTime_t* outPusTime, const struct timespec* posixTime);


#endif // PUS_TIME_H
