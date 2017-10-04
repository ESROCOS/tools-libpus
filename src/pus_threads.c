#include "pus_threads.h"
#include "pus_error.h"

#if PUS_USE_PTHEAD

//
// Implementation with libpthread
//

bool pus_mutexInit(pusMutex_t* mutex)
{
	int ok = 0;
	pthread_mutexattr_t attrib;

	if (NULL == mutex)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}

	ok = pthread_mutexattr_init(&attrib);
	if (!ok)
	{
		PUS_SET_ERROR_2(PUS_ERROR_THREADS, ok);
		return false;
	}
	
	ok = pthread_mutex_init(mutex, &attrib);
	if (!ok)
	{
		PUS_SET_ERROR_2(PUS_ERROR_THREADS, ok);
		return false;
	}
	
	return true;
}

bool pus_mutexLock(pusMutex_t* mutex)
{
	int ok = 0;
	
	if (NULL == mutex)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}
	
	ok = pthread_mutex_lock(mutex);
	if (!ok)
	{
		PUS_SET_ERROR_2(PUS_ERROR_THREADS, ok);
		return false;
	}
	
	return true;
}

bool pus_mutexUnlock(pusMutex_t* mutex)
{
	int ok = 0;

	if (NULL == mutex)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}

	ok = pthread_mutex_unlock(mutex);
	if (!ok)
	{
		PUS_SET_ERROR_2(PUS_ERROR_THREADS, ok);
		return false;
	}

	return true;
}

#else

//
// Not implemented; all functions will fail
//

#pragma message("pus_threads functions are disabled")

bool pus_mutexInit(pusMutex_t* mutex)
{
	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	return false;
}

bool pus_mutexLock(pusMutex_t* mutex)
{
	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	return false;
}

bool pus_mutexUnlock(pusMutex_t* mutex)
{
	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	return false;
}

#endif
