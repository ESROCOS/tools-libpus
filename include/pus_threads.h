/*! \file pus_threads.h
 *  \brief Multi-threading functions used by the PUS library.
 *
 *  This module provides wrappers for multi-threading types and functions
 *  of the OS, to ease portability. The implementation uses POSIX threads.
 *
 *  Define PUS_DISABLE_THREADS as 1 to disable the use of mutexes inside the library.
 *  This will remove the dependency on libpthread. All pus_mutex... functions will
 *  fail, returning false and setting PUS_ERROR to PUS_ERROR_THREADS_DISABLED.
 *
 *  This is useful if one wants to manage the shared resources by means external to
 *  the library. For instance, TASTE applications should leave all thread creation and
 *  synchronization to TASTE, and not use threads or mutexes internally.
 *
 *  \author GMV
 */

#ifndef PUS_THREADS_H
#define PUS_THREADS_H


#include <stdbool.h>

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef PUS_DISABLE_THREADS

typedef void* pusMutex_t;

#else

#include <pthread.h>
//! Mutex type
typedef pthread_mutex_t pusMutex_t;

#endif

//! Initialize a mutex object
/*! Returns true if success. Otherwise, returns false and sets error condition with \ref pus_setError
 */
bool pus_mutexInitOk(pusMutex_t* mutex);

//! Destroy a mutex object
/*! Returns true if success. Otherwise, returns false and sets error condition with \ref pus_setError
 */
bool pus_mutexDestroyOk(pusMutex_t* mutex);

//! Lock a mutex
/*! Returns true if success. Otherwise, returns false and sets error condition with \ref pus_setError
 */
bool pus_mutexLockOk(pusMutex_t* mutex);

//! Unlock a mutex
/*! Returns true if success. Otherwise, returns false and sets error condition with \ref pus_setError
 */
bool pus_mutexUnlockOk(pusMutex_t* mutex);

#ifdef  __cplusplus
}
#endif

#endif // PUS_THREADS_H
