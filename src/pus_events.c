#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
#include <string.h>
#include "pus_events.h"


// Mutex to lock access to the housekeeping parameter tables
pusMutex_t* pus_events_mutex = NULL;

// Initialized flag
bool pus_events_initializedFlag = false;

//! Destination for ST05 reports
extern const pusApid_t pus_st05_eventReportDestination;

//! Event information list
extern pusSt05EventInfo_t pus_st05_eventInfoList[];

//! Size of the event information list
extern const size_t pus_st05_eventInfoListLength;

//! Event circular buffer
extern pusSt05EventInBuffer_t pus_st05_eventBuffer[];

//! Size of the event circular buffer
extern const size_t pus_st05_eventBufferLength;




pusError_t pus_events_initialize(pusMutex_t* mutex)
{
	if (pus_events_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	pus_events_mutex = mutex;

	if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	if (PUS_NO_ERROR != pus_events_configure())
	{
		if (NULL != pus_events_mutex)
		{
			(void) pus_mutexUnlockOk(pus_events_mutex);
		}
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	// Initialize buffer controller
	pus_st05_eventBufferCounter = 0;
	pus_st05_eventBufferIn = 0;

	// Initialize buffer with default values
	pusSt05Event_t aux;
	aux.eventId = 0;
	aux.data.data1 = 0;
	aux.data.data2 = 0;
	for(size_t i; i < pus_st05_eventBufferLength; i++)
	{
		pus_st05_eventBuffer[i].event = aux;
		pus_st05_eventBuffer[i].eventBufferCounter = 0;
	}

	// Flag service initialized = true
	pus_events_initializedFlag = true;
	return PUS_NO_ERROR;
}


pusError_t pus_events_finalize()
{
	if (!pus_events_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		pus_events_mutex = NULL;
		pus_events_initializedFlag = false;
		return PUS_NO_ERROR;
	}
}

bool pus_events_isInitialized()
{
	return pus_events_initializedFlag;
}


bool pus_evens_isInInfoList(pusSt05Event_t* event/*,  pusSubservice_t* severity */) //TODO, devolver severity?
{
	if( NULL == event)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}
	else
	{
		if( event->eventId < pus_st05_getEventInfoListLength() )
		{
			// TODO; como comprobar tipo datos
			//*severity = pus_st05_eventInfoList[event->eventId].defaultSeverity;
			PUS_SET_ERROR(PUS_NO_ERROR);
			return true;
		}

		/*for(size_t i = 0; i < pus_st05_getEventInfoListLength(); i++)
		{
			if(event->eventId == i)
			{
				PUS_SET_ERROR(PUS_NO_ERROR);
				return true;
			}
		}*/

		PUS_SET_ERROR(PUS_ERROR_EVENT_NOT_FOUND);
		return false;
	}
}


pusError_t pus_st05_putBufferEvent(pusSt05Event_t * event)
{
	if( NULL == event )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	pus_st05_eventBuffer[pus_st05_eventBufferIn].event = *event;
	pus_st05_eventBuffer[pus_st05_eventBufferIn].eventBufferCounter = pus_st05_eventBufferCounter;

	pus_st05_eventBufferIn = (pus_st05_eventBufferIn + 1) % pus_st05_eventBufferLength;
	pus_st05_eventBufferCounter = (pus_st05_eventBufferCounter + 1) % PUS_ST05_EVENT_BUFFER_COUNTER_LIMIT;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}


pusError_t pus_st05_getNextBufferEvent(pusSt05Event_t *next, uint64_t *actualCounter)
{
	if( NULL == next || NULL == actualCounter )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( *actualCounter >= PUS_ST05_EVENT_BUFFER_COUNTER_LIMIT )
	{
		return PUS_SET_ERROR(PUS_ERROR_OUT_OF_RANGE);
	}

	if( 0 == pus_st05_eventBufferCounter )
	{
		return PUS_SET_ERROR(PUS_ERROR_EMPTY_BUFFER);
	}

	// Comprobación para no entrar en el bucle
	/*if( pus_st05_eventBufferCounter <= QUEUE_SIZE )
	{
		if( (*actualCounter+1 < ( pus_st05_eventBufferCounter - QUEUE_SIZE + LIMIT_EVENT_COUNT)) && (*actualCounter+1 >= eventCounter))
		{
			return PUS_ERROR_NEXT_EVENT_NOT_FOUND;
		}
	}
	else if(*actualCounter+1 >= eventCounter)
	{
		return PUS_ERROR_NEXT_EVENT_NOT_FOUND;
	}
	else if(*actualCounter+1 < eventCounter-QUEUE_SIZE)
	{
		return PUS_ERROR_NEXT_EVENT_NOT_FOUND;
	}*/


	for(size_t i = 0; i < pus_st05_eventBufferLength; i++)
	{
		if( pus_st05_eventBuffer[i].eventBufferCounter == ((*actualCounter+1) % PUS_ST05_EVENT_BUFFER_COUNTER_LIMIT) )
		{
			*next = pus_st05_eventBuffer[i].event;
			*actualCounter = pus_st05_eventBuffer[i].eventBufferCounter;
			return PUS_SET_ERROR(PUS_NO_ERROR); // NO_ERROR
		}
	}

	return PUS_SET_ERROR(PUS_ERROR_NEXT_EVENT_NOT_FOUND); // ERROR NOT_FOUND
}


//! getter pus_st05_eventBufferIn
size_t pus_st05_getEventBufferIn()
{
	return pus_st05_eventBufferIn;
}

//! setter pus_st05_eventBufferIn
void pus_st05_setEventBufferIn(size_t bufferIn)
{
	pus_st05_eventBufferIn = bufferIn;
}

//! getter pus_st05_eventBufferCounter
size_t pus_st05_getEventBufferCounter()
{
	return pus_st05_eventBufferCounter;
}

//! setter pus_st05_eventBufferCounter
void pus_st05_setEventBufferCounter(size_t counter)
{
	pus_st05_eventBufferCounter = counter;
}

//! getter pus_st05_eventBufferLength
size_t pus_st05_getEventBufferLength()
{
	return pus_st05_eventBufferLength;
}

pusApid_t pus_st05_getEventDestination()
{
	return pus_st05_eventReportDestination;
}

size_t pus_st05_getEventInfoListLength()
{
	return pus_st05_eventInfoListLength;
}



// get y set para los parametors de pusSt05Event_t

//pusError_t pus_hk_getUInt32Param(pusSt03ParamId_t param, uint32_t* outValue)
//{
//	if (NULL == outValue)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
//	}
//	else if (param >= pus_ST03_PARAM_LIMIT)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
//	}
//	else
//	{
//		if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
//		{
//			return PUS_ERROR_THREADS;
//		}
//
//		pusError_t result = PUS_NO_ERROR;
//
//		if (PUS_ST03_UINT32 != pus_st03_paramInfo[param].type)
//		{
//			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
//		}
//		else
//		{
//			result = pus_hk_paramToUInt32(outValue, pus_st03_params[param]);
//		}
//
//		if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
//		{
//			result = PUS_ERROR_THREADS;
//		}
//
//		return result;
//	}
//}
//
//pusError_t pus_hk_setUInt32Param(pusSt03ParamId_t param, uint32_t value)
//{
//	if (param >= pus_ST03_PARAM_LIMIT)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
//	}
//	else
//	{
//		if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
//		{
//			return PUS_ERROR_THREADS;
//		}
//
//		pusError_t result = PUS_NO_ERROR;
//
//		if (PUS_ST03_UINT32 != pus_st03_paramInfo[param].type)
//		{
//			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
//		}
//		else
//		{
//			pus_st03_params[param] = (uint64_t)value;
//			result = PUS_NO_ERROR;
//		}
//
//		if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
//		{
//			result = PUS_ERROR_THREADS;
//		}
//
//		return result;
//	}
//}
//
//pusError_t pus_hk_getInt32Param(pusSt03ParamId_t param, int32_t* outValue)
//{
//	if (NULL == outValue)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
//	}
//	else if (param >= pus_ST03_PARAM_LIMIT)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
//	}
//	else
//	{
//		if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
//		{
//			return PUS_ERROR_THREADS;
//		}
//
//		pusError_t result = PUS_NO_ERROR;
//
//		if (PUS_ST03_INT32 != pus_st03_paramInfo[param].type)
//		{
//			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
//		}
//		else
//		{
//			result = pus_hk_paramToInt32(outValue, pus_st03_params[param]);
//		}
//
//		if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
//		{
//			result = PUS_ERROR_THREADS;
//		}
//
//		return result;
//	}
//}
//
//pusError_t pus_hk_setInt32Param(pusSt03ParamId_t param, int32_t value)
//{
//	if (param >= pus_ST03_PARAM_LIMIT)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
//	}
//	else
//	{
//		if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
//		{
//			return PUS_ERROR_THREADS;
//		}
//
//		pusError_t result = PUS_NO_ERROR;
//
//		if (PUS_ST03_INT32 != pus_st03_paramInfo[param].type)
//		{
//			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
//		}
//		else
//		{
//			int64_t aux = value;
//			memcpy(&pus_st03_params[param], &aux, sizeof(int64_t));
//			result = PUS_NO_ERROR;
//		}
//
//		if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
//		{
//			result = PUS_ERROR_THREADS;
//		}
//
//		return result;
//	}
//}
//
//pusError_t pus_hk_getReal64Param(pusSt03ParamId_t param, double* outValue)
//{
//	if (NULL == outValue)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
//	}
//	else if (param >= pus_ST03_PARAM_LIMIT)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
//	}
//	else
//	{
//		if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
//		{
//			return PUS_ERROR_THREADS;
//		}
//
//		pusError_t result = PUS_NO_ERROR;
//
//		if (PUS_ST03_REAL64 != pus_st03_paramInfo[param].type)
//		{
//			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
//		}
//		else
//		{
//			result = pus_hk_paramToReal64(outValue, pus_st03_params[param]);
//		}
//
//		if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
//		{
//			result = PUS_ERROR_THREADS;
//		}
//
//		return result;
//	}
//}
//
//pusError_t pus_hk_setReal64Param(pusSt03ParamId_t param, double value)
//{
//	if (param >= pus_ST03_PARAM_LIMIT)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
//	}
//	else
//	{
//		if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
//		{
//			return PUS_ERROR_THREADS;
//		}
//
//		pusError_t result = PUS_NO_ERROR;
//
//		if (PUS_ST03_REAL64 != pus_st03_paramInfo[param].type)
//		{
//			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
//		}
//		else
//		{
//			double aux = value;
//			memcpy(&pus_st03_params[param], &aux, sizeof(double));
//			result = PUS_NO_ERROR;
//		}
//
//		if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
//		{
//			result = PUS_ERROR_THREADS;
//		}
//
//		return result;
//	}
//}
//
//pusError_t pus_hk_getBoolParam(pusSt03ParamId_t param, bool* outValue)
//{
//	if (NULL == outValue)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
//	}
//	else if (param >= pus_ST03_PARAM_LIMIT)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
//	}
//	else
//	{
//		if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
//		{
//			return PUS_ERROR_THREADS;
//		}
//
//		pusError_t result = PUS_NO_ERROR;
//
//		if (PUS_ST03_BOOL != pus_st03_paramInfo[param].type)
//		{
//			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
//		}
//		else
//		{
//			result = pus_hk_paramToBool(outValue, pus_st03_params[param]);
//		}
//
//		if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
//		{
//			result = PUS_ERROR_THREADS;
//		}
//
//		return result;
//	}
//}
//
//pusError_t pus_hk_setBoolParam(pusSt03ParamId_t param, bool value)
//{
//	if (param >= pus_ST03_PARAM_LIMIT)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
//	}
//	else
//	{
//		if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
//		{
//			return PUS_ERROR_THREADS;
//		}
//
//		pusError_t result = PUS_NO_ERROR;
//
//		if (PUS_ST03_BOOL != pus_st03_paramInfo[param].type)
//		{
//			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
//		}
//		else
//		{
//			pus_st03_params[param] = (uint64_t)value;
//			result = PUS_NO_ERROR;
//		}
//
//		if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
//		{
//			result = PUS_ERROR_THREADS;
//		}
//
//		return result;
//	}
//}
//
//pusError_t pus_hk_getByteParam(pusSt03ParamId_t param, uint8_t* outValue)
//{
//	if (NULL == outValue)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
//	}
//	else if (param >= pus_ST03_PARAM_LIMIT)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
//	}
//	else
//	{
//		if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
//		{
//			return PUS_ERROR_THREADS;
//		}
//
//		pusError_t result = PUS_NO_ERROR;
//
//		if (PUS_ST03_BYTE != pus_st03_paramInfo[param].type)
//		{
//			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
//		}
//		else
//		{
//			result = pus_hk_paramToByte(outValue, pus_st03_params[param]);
//		}
//
//		if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
//		{
//			result = PUS_ERROR_THREADS;
//		}
//
//		return result;
//	}
//}
//
//pusError_t pus_hk_setByteParam(pusSt03ParamId_t param, uint8_t value)
//{
//	if (param >= pus_ST03_PARAM_LIMIT)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
//	}
//	else
//	{
//		if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
//		{
//			return PUS_ERROR_THREADS;
//		}
//
//		pusError_t result = PUS_NO_ERROR;
//
//		if (PUS_ST03_BYTE != pus_st03_paramInfo[param].type)
//		{
//			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
//		}
//		else
//		{
//			pus_st03_params[param] = (uint64_t)value;
//			result = PUS_NO_ERROR;
//		}
//
//		if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
//		{
//			result = PUS_ERROR_THREADS;
//		}
//
//		return result;
//	}
//}
//
////
//// Cast parameter to type
////
//
//pusError_t pus_hk_paramToUInt32(uint32_t* outValue, pusStoredParam_t paramValue)
//{
//	if (NULL == outValue)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
//	}
//	else if (paramValue > UINT32_MAX)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_LIMIT);
//	}
//	else
//	{
//		*outValue = (uint32_t)paramValue;
//		return PUS_NO_ERROR;
//	}
//}
//
//pusError_t pus_hk_paramToInt32(int32_t* outValue, pusStoredParam_t paramValue)
//{
//	if (NULL == outValue)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
//	}
//	else
//	{
//		int64_t i64 = 0;
//		memcpy(&i64, &paramValue, sizeof(int64_t));
//
//		if (i64 < INT32_MIN || i64 > INT32_MAX)
//		{
//			return PUS_SET_ERROR(PUS_ERROR_LIMIT);
//		}
//		else
//		{
//			*outValue = (int32_t)i64;
//			return PUS_NO_ERROR;
//		}
//	}
//}
//
//pusError_t pus_hk_paramToReal64(double* outValue, pusStoredParam_t paramValue)
//{
//	if (NULL == outValue)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
//	}
//	else
//	{
//		memcpy(outValue, &paramValue, sizeof(double));
//		return PUS_NO_ERROR;
//	}
//}
//
//pusError_t pus_hk_paramToBool(bool* outValue, pusStoredParam_t paramValue)
//{
//	if (NULL == outValue)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
//	}
//	else
//	{
//		*outValue = (bool)paramValue;
//		return PUS_NO_ERROR;
//	}
//}
//
//pusError_t pus_hk_paramToByte(uint8_t* outValue, pusStoredParam_t paramValue)
//{
//	if (NULL == outValue)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
//	}
//	else if (paramValue > UINT8_MAX)
//	{
//		return PUS_SET_ERROR(PUS_ERROR_LIMIT);
//	}
//	else
//	{
//		*outValue = (uint8_t)paramValue;
//		return PUS_NO_ERROR;
//	}
//}
//

