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

	for(size_t i=0; i<pus_scheduling_tableSize; i++)
	{
		pus_scheduling_table[i].deleted = true;
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
	for(size_t i = 0; i < pus_scheduling_tableSize; i++)
	{
		if( true == pus_scheduling_table[j].deleted )
		{
			pus_scheduling_table[j].action = *tcAction;
			pus_scheduling_table[j].deleted = false;
			pus_scheduling_table[j].time = *time;
			return PUS_SET_ERROR(PUS_NO_ERROR);
		}

		j = (j+1)%pus_scheduling_tableSize;
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
	for(size_t i = 0; i < pus_scheduling_tableSize; i++)
	{
		if( false == pus_scheduling_table[j].deleted )
		{
			if( pus_scheduling_isActivityExecutable( &pus_scheduling_table[j].time, time))
			{
				*tcAction = pus_scheduling_table[j].action;
				pus_scheduling_table[j].deleted = true;

				return PUS_SET_ERROR(PUS_NO_ERROR);
			}
		}

		j = (j+1)%pus_scheduling_tableSize;
	}

	return PUS_SET_ERROR(PUS_ERROR_DEFINITION_NOT_FOUND);
}

pusError_t pus_scheduling_tc_11_4_packetToTable(pusPacket_t* packet)
{
	if( NULL == packet )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( PUS_NO_ERROR == PUS_EXPECT_ST11TC(packet, pus_TC_DATA_ST_11_4))
	{
		return PUS_GET_ERROR();
	}

	int32_t nCount;
	size_t max = pus_scheduling_tableSize;
	if( PUS_NO_ERROR != pus_tc_11_4_getActivities(&nCount, pus_scheduling_tableAuxiliar, packet, max))
	{
		return PUS_GET_ERROR();
	}

	pusPacket_t tcAction;
	for(int32_t i = 0; i<nCount; i++)
	{
		pus_packetReduced_createPacketFromPacketReduced(&tcAction, &pus_scheduling_tableAuxiliar[i].packetReduced);

		if( PUS_NO_ERROR != pus_scheduling_insertActivity(&tcAction, &pus_scheduling_tableAuxiliar[i].time))
		{
			return PUS_GET_ERROR();
		}
	}


	return PUS_SET_ERROR(PUS_NO_ERROR);
}



