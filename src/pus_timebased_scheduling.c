#include "pus_timebased_scheduling.h"

#include "pus_error.h"
#include "pus_threads.h"
#include "pus_types.h"
#include "pus_packet.h"

// Mutex to lock access to the event tables
pusMutex_t* pus_scheduling_mutex = NULL;

// Initialized flag
bool pus_scheduling_initializedFlag = false;

pusError_t pus_scheduling_initialize(pusMutex_t* mutex)
{
	if (pus_scheduling_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	pus_scheduling_mutex = mutex;

	if (NULL != pus_scheduling_mutex && !pus_mutexLockOk(pus_scheduling_mutex))
	{
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	/*if (PUS_NO_ERROR != pus_scheduling_configure())
	{
		if (NULL != pus_scheduling_mutex)
		{
			(void) pus_mutexUnlockOk(pus_scheduling_mutex);
		}
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}*/

	if (NULL != pus_scheduling_mutex && !pus_mutexUnlockOk(pus_scheduling_mutex))
	{
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	// Flag service initialized = true
	pus_scheduling_initializedFlag = true;
	return PUS_SET_ERROR(PUS_NO_ERROR);



	return PUS_SET_ERROR(PUS_NO_ERROR);
}

bool pus_scheduling_isInitialized()
{
	return pus_scheduling_initializedFlag;
}
