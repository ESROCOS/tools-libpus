/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
#include <string.h>
#include "pus_events.h"


// Mutex to lock access to the event tables
pusMutex_t* pus_events_mutex = NULL;

// Initialized flag
bool pus_events_initializedFlag = false;

//! Pointer for buffer in
size_t pus_st05_eventBufferCounter;

//! Counter of the events that has been inserted
size_t pus_st05_eventBufferIn;

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
	pus_st05_eventBufferCounter = 1;
	pus_st05_eventBufferIn = 0;

	// Initialize buffer with default values
	pusSt05Event_t aux;
	aux.eventId = UINT32_MAX+1;
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


bool pus_events_isInInfoList(pusSt05Event_t* event)
{
	if( NULL == event)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}
	else
	{
		if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		if( event->eventId < pus_st05_getEventInfoListLength() )
		{
			PUS_SET_ERROR(PUS_NO_ERROR);
			return true;
		}

		if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		PUS_SET_ERROR(PUS_ERROR_EVENT_NOT_FOUND);
		return false;
	}
}



pusError_t pus_st05_pushBufferEvent(const pusSt05Event_t * event)
{
	if( NULL == event )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
	{
		return PUS_ERROR_THREADS;
	}

	pus_st05_eventBuffer[pus_st05_eventBufferIn].event = *event;
	pus_st05_eventBuffer[pus_st05_eventBufferIn].eventBufferCounter = pus_st05_eventBufferCounter;

	pus_st05_eventBufferIn = (pus_st05_eventBufferIn + 1) % pus_st05_eventBufferLength;
	pus_st05_eventBufferCounter = (pus_st05_eventBufferCounter + 1) % PUS_ST05_EVENT_BUFFER_COUNTER_LIMIT;

	if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
	{
		return PUS_ERROR_THREADS;
	}

	return PUS_SET_ERROR(PUS_NO_ERROR);
}


pusError_t pus_st05_getNextBufferEvent(pusSt05Event_t* next, uint64_t* actualCounter)
{
	if( NULL == next || NULL == actualCounter )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (NULL != pus_events_mutex && !pus_mutexLockOk(pus_events_mutex))
	{
		return PUS_ERROR_THREADS;
	}

	if( *actualCounter >= PUS_ST05_EVENT_BUFFER_COUNTER_LIMIT )
	{
		return PUS_SET_ERROR(PUS_ERROR_OUT_OF_RANGE);
	}

	if( 0 == pus_st05_eventBufferCounter )
	{
		return PUS_SET_ERROR(PUS_ERROR_EMPTY_BUFFER);
	}

	for(size_t i = 0; i < pus_st05_eventBufferLength; i++)
	{
		if( pus_st05_eventBuffer[i].eventBufferCounter == ((*actualCounter+1) % PUS_ST05_EVENT_BUFFER_COUNTER_LIMIT) )
		{
			*next = pus_st05_eventBuffer[i].event;
			*actualCounter = pus_st05_eventBuffer[i].eventBufferCounter;
			return PUS_SET_ERROR(PUS_NO_ERROR); // NO_ERROR
		}
	}


	if (NULL != pus_events_mutex && !pus_mutexUnlockOk(pus_events_mutex))
	{
		return PUS_ERROR_THREADS;
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


// Getters/Setters pusSt05Event_t
pusSt05EventId_t pus_events_getEventId(const pusSt05Event_t* event)
{
	if (NULL == event)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return pus_EVENT_ID_NONE;
	}
	else
	{
		return event->eventId;
	}
}

void pus_events_setEventId(pusSt05Event_t* event, pusSt05EventId_t eventId)
{
	if (NULL == event)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	else
	{
		event->eventId = eventId;
	}
}


pusSt05EventAuxData_t pus_events_getEventAuxData(const pusSt05Event_t* event)
{
	if (NULL == event)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return pus_EVENT_AUXDATA_NONE;
	}
	else
	{
		return event->data;
	}
}

void pus_events_setEventAuxData(pusSt05Event_t* event, pusSt05EventAuxData_t data)
{
	if (NULL == event)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	else
	{
		event->data = data;
	}
}


pusStoredParam_t pus_events_getEventAuxData1(const pusSt05EventAuxData_t* data)
{
	if (NULL == data)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return pus_EVENT_DATASTORED_NONE;
	}
	else
	{
		return data->data1;
	}
}

void pus_events_setEventAuxData1(pusSt05EventAuxData_t* data, pusStoredParam_t data1)
{
	if (NULL == data)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	else
	{
		data->data1 = data1;
	}
}

pusStoredParam_t pus_events_getEventAuxData2(const pusSt05EventAuxData_t* data)
{
	if (NULL == data)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return pus_EVENT_DATASTORED_NONE;
	}
	else
	{
		return data->data2;
	}
}

void pus_events_setEventAuxData2(pusSt05EventAuxData_t* data, pusStoredParam_t data2)
{
	if (NULL == data)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	data->data2 = data2;
}


