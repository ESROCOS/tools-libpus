#ifndef __TIMEINMS_H__
#define __TIMEINMS_H__

#if __STDC_VERSION__ >= 199901L
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 600
#endif
#else
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif
#endif /* __STDC_VERSION__ */

#include <time.h>

long long getTimeInMilliseconds(void);

#endif
