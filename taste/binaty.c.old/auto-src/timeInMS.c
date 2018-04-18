#include "timeInMS.h"

long long getTimeInMilliseconds()
{
#ifdef __linux__
    struct timespec tv;
    clock_gettime(CLOCK_MONOTONIC, &tv);
    long long val = 1000000000LL*(long long)tv.tv_sec + (long long)tv.tv_nsec;
    return val;
#else
    return 0LL;
#endif
}
