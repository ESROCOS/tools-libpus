#ifdef __unix__

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "debug_messages.h"

// debug_printf is used for logging and error reporting

void debug_printf(DebugLevel level, const char *fmt, ...)
{
    static int bFirstTime = 1;
    static int bPrintsEnabled = 0;
    static char message[4096];

    if (bFirstTime) {
	bFirstTime = 0;
	bPrintsEnabled = (NULL != getenv("ASSERT_DEBUG"))?1:0;
    }
    if (level == LVL_ERROR)
	printf("%s\n", "***** ERROR just happened: *****");
    if (((level == LVL_INFO || level == LVL_WARN) && bPrintsEnabled) || 
	level == LVL_ERROR || 
	level == LVL_PANIC) 
    {
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(message, sizeof message, fmt, ap);
	printf("%s", message);
	va_end(ap);
    }
    if (level == LVL_PANIC)
	exit(1);
}

#endif
