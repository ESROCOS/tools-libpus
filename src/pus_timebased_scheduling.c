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
bool pus_scheduling_functionStatus = false;

pusSchedulingActivity_t pus_scheduling_queue[10];

const size_t pus_scheduling_queueSize = 10;

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

	pus_scheduling_initializedFlag = true;
	pus_scheduling_resetFunction();
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_scheduling_finalize()
{
	if (!pus_scheduling_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		pus_scheduling_mutex = NULL;
		pus_scheduling_initializedFlag = false;
		pus_scheduling_functionStatus = false;
		return PUS_SET_ERROR(PUS_NO_ERROR);
	}
}

bool pus_scheduling_isInitialized()
{
	return pus_scheduling_initializedFlag;
}

bool pus_scheduling_isFunctionEnable()
{
	return pus_scheduling_functionStatus;
}

pusError_t pus_scheduling_setFunctionFlag(bool flag)
{
	if( ! pus_scheduling_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	pus_scheduling_functionStatus = flag;
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_scheduling_enableFunction()
{
	if( ! pus_scheduling_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	if(pus_scheduling_isFunctionEnable())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_ENABLED);
	}

	return pus_scheduling_setFunctionFlag(true);
}

pusError_t pus_scheduling_disableFunction()
{
	if( ! pus_scheduling_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	if( !pus_scheduling_isFunctionEnable())
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
	pus_scheduling_functionStatus = false;

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
	for(size_t i = 0; i < pus_scheduling_queueSize; i++)
	{
		if( true == pus_scheduling_queue[j].deleted )
		{
			pus_scheduling_queue[j].action = *tcAction;
			pus_scheduling_queue[j].deleted = false;
			pus_scheduling_queue[j].time = *time;
			return PUS_SET_ERROR(PUS_NO_ERROR);
		}

		j = (j+1)%pus_scheduling_queueSize;
	}
	return PUS_SET_ERROR(PUS_ERROR_MAXIMUM_REACHED);
}

bool pus_scheduling_isActivityExecutable(const pusTime_t* timeRelease, const pusTime_t* timeRef)
{

	if ( NULL == timeRelease || NULL == timeRef )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if(timeRelease->tv_sec < timeRef->tv_sec)
	{
		return true;
	}
	if( (timeRelease->tv_sec == timeRef->tv_sec) && (timeRelease->tv_nsec <= timeRef->tv_nsec) )
	{
		return true;
	}
	return false;
}

pusError_t pus_scheduling_getScheduledActivity(pusPacket_t* tcAction, const pusTime_t* time)
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
	for(size_t i = 0; i < pus_scheduling_queueSize; i++)
	{
		if( false == pus_scheduling_queue[j].deleted )
		{
			if( pus_scheduling_isActivityExecutable( &pus_scheduling_queue[j].time, time))
			{
				*tcAction = pus_scheduling_queue[j].action;
				pus_scheduling_queue[j].deleted = true;

				return PUS_SET_ERROR(PUS_NO_ERROR);
			}
		}

		j = (j+1)%pus_scheduling_queueSize;
	}

	return PUS_SET_ERROR(PUS_ERROR_DEFINITION_NOT_FOUND);
}

