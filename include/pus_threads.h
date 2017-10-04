/*! \file pus_threads.h
 *  \brief Multi-threading functions used by the PUS library.
 *
 *  This module provides wrappers for multi-threading types and functions
 *  of the OS, to ease portability. The implementation uses POSIX threads.
 *
 *  \author GMV
 */

#ifndef PUS_THREADS_H
#define PUS_THREADS_H

#include <stdbool.h>
#include <pthread.h>


#ifndef PUS_USE_PTHREAD
//! Set PUS_USE_PTHREAD to 0 to not use libpthread; functions in this module will return failure
#define PUS_USE_PTHREAD 1
#endif


//! Mutex type
typedef pthread_mutex_t pusMutex_t;

//! Initialize a mutex object
/*! Returns true if success. Otherwise, returns false and sets error condition with \ref pus_setError
 */
bool pus_mutexInit(pusMutex_t* mutex);

//! Lock a mutex
/*! Returns true if success. Otherwise, returns false and sets error condition with \ref pus_setError
 */
bool pus_mutexLock(pusMutex_t* mutex);

//! Unlock a mutex
/*! Returns true if success. Otherwise, returns false and sets error condition with \ref pus_setError
 */
bool pus_mutexUnlock(pusMutex_t* mutex);


#endif // PUS_THREADS_H
