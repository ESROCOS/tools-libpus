#ifndef __DEBUG_MESSAGES_H__
#define __DEBUG_MESSAGES_H__

#ifdef __cplusplus
extern "C" {
#endif

// debug_printf is used for logging and error reporting
//
typedef enum tagDebugLevel {
    LVL_INFO,
    LVL_WARN,
    LVL_ERROR,
    LVL_PANIC
} DebugLevel;

void debug_printf(DebugLevel level, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
