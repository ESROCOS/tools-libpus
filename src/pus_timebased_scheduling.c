#include "pus_timebased_scheduling.h"

#include "pus_error.h"
#include "pus_threads.h"
#include "pus_types.h"
#include "pus_packet.h"
#include "pus_time.h"

// Mutex to lock access to the event tables
pusMutex_t* pus_scheduling_mutex = NULL;

// Initialized flag
bool pus_scheduling_initializedFlag = false;

// Function Flag
bool pus_scheduling_functionFlag = false;

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

	for(size_t i=0; i<pus_scheduling_queueSize; i++)
	{
		pus_scheduling_queue[i].deleted = true;
	}

	pus_scheduling_functionFlag = false;
	pus_scheduling_initializedFlag = true;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

bool pus_scheduling_isInitialized()
{
	return pus_scheduling_initializedFlag;
}

bool pus_scheduling_isFunctionEnable()
{
	return pus_scheduling_functionFlag;
}

pusError_t pus_scheduling_setFunctionFlag(bool flag)
{
	if( ! pus_scheduling_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	pus_scheduling_functionFlag = flag;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_scheduling_enableFunction()
{
	if(pus_scheduling_isFunctionEnable())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_ENABLED);
	}

	return pus_scheduling_setFunctionFlag(true);
}

pusError_t pus_scheduling_disableFunction()
{
	if(pus_scheduling_isFunctionEnable())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_DISABLED);
	}

	return pus_scheduling_setFunctionFlag(false);
}

pusError_t pus_scheduling_resetFunction()
{
	if( ! pus_scheduling_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	for(size_t i=0; i<pus_scheduling_queueSize; i++)
	{
		pus_scheduling_queue[i].deleted = true;
	}
	pus_scheduling_functionFlag = false;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_scheduling_insertActivity(const pusPacket_t* tcAction, const pusTime_t* time)
{
	if ( NULL == tcAction || NULL == time )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( ! pus_scheduling_isInitialized() )
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	static size_t j = 0;
	for(size_t i = 0; i < pus_scheduling_queueSize; i++, (j++)%pus_scheduling_queueSize)
	{
		if( true == pus_scheduling_queue[j].deleted )
		{
			pus_scheduling_queue[j].action = *tcAction;
			pus_scheduling_queue[j].deleted = false;
			pus_scheduling_queue[j].time = *time;

			return PUS_SET_ERROR(PUS_NO_ERROR);
		}
	}
	return PUS_SET_ERROR(PUS_ERROR_MAXIMUM_REACHED);
}

bool pus_scheduling_isActivityExecutable(const pusTime_t* timeRelease, const pusTime_t* timeRef)
{
	return((timeRelease->tv_sec >= timeRef->tv_sec) && (timeRelease->tv_nsec >= timeRef->tv_nsec));
}

pusError_t pus_scheduling_getActivity(pusPacket_t* tcAction, const pusTime_t* time)
{
	if ( NULL == tcAction || NULL == time )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( ! pus_scheduling_isInitialized() )
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	pusTime_t timeRef;
	pus_now(&timeRef);

	static size_t j = 0;
	for(size_t i = 0; i < pus_scheduling_queueSize; i++, (j++)%pus_scheduling_queueSize)
	{
		if( false == pus_scheduling_queue[j].deleted )
		{
			if( pus_scheduling_isActivityExecutable( &pus_scheduling_queue[j].time, &timeRef))
			{
				*tcAction = pus_scheduling_queue[j].action;
				pus_scheduling_queue[j].deleted = true;

				return PUS_SET_ERROR(PUS_NO_ERROR);
			}
		}
	}

	return PUS_SET_ERROR(PUS_ERROR_DEFINITION_NOT_FOUND);
}

