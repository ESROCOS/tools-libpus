/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include <assert.h>

#include "pus_time.h"
#include "pus_error.h"

void pus_now(pusTime_t* outNow)
{
	if (NULL == outNow)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}

	struct timespec ts;

	if (0 == clock_gettime(CLOCK_REALTIME, &ts))
	{
		pus_posix2time(outNow, &ts);
	}
	else
	{
		PUS_SET_ERROR(PUS_ERROR_SYSTEM_TIME);
		return;
	}
}

void pus_time2posix(struct timespec* outPosixTime, const pusTime_t* pusTime)
{
	assert(NULL != outPosixTime);

	outPosixTime->tv_sec = pusTime->tv_sec;
	outPosixTime->tv_nsec = pusTime->tv_nsec;
}

void pus_posix2time(pusTime_t* outPusTime, const struct timespec* posixTime)
{
	assert(NULL != outPusTime);

	outPusTime->tv_sec = posixTime->tv_sec;
	outPusTime->tv_nsec = posixTime->tv_nsec;
}



