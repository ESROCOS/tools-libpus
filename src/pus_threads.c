#include "pus_threads.h"
#include "pus_error.h"


bool pus_mutexInit(pusMutex_t* mutex)
{
	int res = 0;
	pthread_mutexattr_t attrib;

	if (NULL == mutex)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}

	res = pthread_mutexattr_init(&attrib);
	if (0 != res)
	{
		PUS_SET_ERROR_INT(PUS_ERROR_THREADS, res);
		return false;
	}
	
	res = pthread_mutex_init(mutex, &attrib);
	if (0 != res)
	{
		PUS_SET_ERROR_INT(PUS_ERROR_THREADS, res);
		return false;
	}
	
	return true;
}

bool pus_mutexDestroy(pusMutex_t* mutex)
{
	int res = 0;

	if (NULL == mutex)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}

	res = pthread_mutex_destroy(mutex);
	if (0 != res)
	{
		PUS_SET_ERROR_INT(PUS_ERROR_THREADS, res);
		return false;
	}

	return true;
}

bool pus_mutexLock(pusMutex_t* mutex)
{
	int res = 0;
	
	if (NULL == mutex)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}
	
	res = pthread_mutex_lock(mutex);
	if (0 != res)
	{
		PUS_SET_ERROR_INT(PUS_ERROR_THREADS, res);
		return false;
	}
	
	return true;
}

bool pus_mutexUnlock(pusMutex_t* mutex)
{
	int res = 0;

	if (NULL == mutex)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}

	res = pthread_mutex_unlock(mutex);
	if (0 != res)
	{
		PUS_SET_ERROR_INT(PUS_ERROR_THREADS, res);
		return false;
	}

	return true;
}

