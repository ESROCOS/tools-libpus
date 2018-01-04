/*! \file pus_events.h
 *  \brief Management of the events table used by several services
 *
 *  Defines the parameters table used by the service ST[05], ST[18] and ST[19].
 *
 *  The table contains the last N events. This allows that each of the services that
 *  have to process the event can do it in turn, provided that there are not too
 *  many events. Each service passes a counter of the last event processed when
 *  requesting the next event available. It is possible that several activations of
 *  the same event are in the table at the same time.
 *
 *  Access to the table is optionally protected by a mutex. This allows implementing
 *  the service using external synchronization (by TASTE) or not.
 *
 *  \author GMV
 */

#ifndef PUS_EVENTS_H
#define PUS_EVENTS_H

#include "pus_types.h"
#include "pus_error.h"
#include "pus_apid.h"
#include "pus_threads.h"
#include "pus_stored_param.h"

#ifdef  __cplusplus
extern "C" {
#endif

// Severity Type enum
typedef enum
{
	PUS_ST05_SEVERITY_INFO,
	PUS_ST05_SEVERITY_LOW,
	PUS_ST05_SEVERITY_MEDIUM,
	PUS_ST05_SEVERITY_HIGH
} pusSt05SeverityType_t;


typedef struct
{
	pusParamType_t dataType1; //!< Name of the event, for debugging purposes
	pusParamType_t dataType2; //!< Severity type
} pusSt05EventReportData_t;

//! Type to describe a event: label, severity, dataTypes (the parameter ID gives its location in the array)
typedef struct
{
	const char* label; //!< Name of the event, for debugging purposes
	pusSt05SeverityType_t defaultSeverity; //!< Severity type
	pusSt05EventReportData_t data; //!< Data type
} pusSt05EventInfo_t;

//! Buffer list
typedef struct {
	pusSt05Event_t event;
    size_t eventBufferCounter;
} pusSt05EventInBuffer_t;



//! Pointer for buffer in
extern size_t pus_st05_eventBufferIn;


#define PUS_ST05_EVENT_BUFFER_COUNTER_LIMIT UINT32_MAX
//! Counter of the events that has been inserted
extern size_t pus_st05_eventBufferCounter;


//
// Service initialization and tear down
//

//! Function to initialize the event manager used by service ST[05] and several others
/*! This function is generated from the mission database, and it should be declared
 *  in \ref pus_st05_config.h
 */
extern pusError_t pus_events_configure();

//! Initialize the data structures of the event manager
/*! Create the parameter tables from the configuration and initializes a mutex.
 *  Alternatively, can pass NULL as mutex if access protection is provided externally,
 *  for instance, by TASTE.
 *  \param[inout] mutex Mutex to be initialized; if NULL, access protection is disabled
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_events_initialize(pusMutex_t* mutex);

//! Release the resources allocated by the event manager
/*! \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_events_finalize();

//! Check if the event manager is initialized
bool pus_events_isInitialized();



bool pus_events_isInInfoList(pusSt05Event_t * event);

//
// Buffer control
//

//! Function to push an event into the buffer
/*! Insert an event into the buffer, preparing the pointer and counter for the next insert.
 * \param[in] event Event that is going to be inserted into the buffer
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st05_pushBufferEvent(const pusSt05Event_t * event);


//! Function that return the next event in buffer.
/*! Look for the next event in buffer
 * \param[out] event The next event in buffer.
 * \param[inout] event Event that is going to be inserted into the buffer
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st05_getNextBufferEvent(pusSt05Event_t *next, uint64_t *actualCounter);

//! getter pus_st05_eventBufferIn
size_t pus_st05_getEventBufferIn();

//! setter pus_st05_eventBufferIn
void pus_st05_setEventBufferIn(size_t bufferIn);

//! getter pus_st05_eventBufferIn
size_t pus_st05_getEventBufferCounter();

//! setter pus_st05_eventBufferIn
void pus_st05_setEventBufferCounter(size_t counter);

//! getter pus_st05_eventBufferLength
size_t pus_st05_getEventBufferLength();

//! getter pus_st05_eventDestination
pusApid_t pus_st05_getEventDestination() ;

//! getter pus_st05_eventInfoListLength
size_t pus_st05_getEventInfoListLength();

// Getters/Setters pusSt05Event_t
//! Getter for eventId in event structure
pusSt05EventId_t pus_events_getEventId(const pusSt05Event_t* event);

//! Setter for eventId in event structure
void pus_events_setEventId(pusSt05Event_t* event, pusSt05EventId_t eventId);

//! Getter for data in event structure
pusSt05EventAuxData_t pus_events_getEventAuxData(const pusSt05Event_t* event);

//! Setter for data in event structure
void pus_events_setEventAuxData(pusSt05Event_t* event, pusSt05EventAuxData_t data);

//! Getter for data1 in data structure
pusStoredParam_t pus_events_getEventAuxData1(const pusSt05EventAuxData_t* data);

//! Setter for data1 in data structure
void pus_events_setEventAuxData1(pusSt05EventAuxData_t* data, pusStoredParam_t data1);

//! Getter for data2 in data structure
pusStoredParam_t pus_events_getEventAuxData2(const pusSt05EventAuxData_t* data);

//! setter for data2 in data structure
void pus_events_setEventAuxData2(pusSt05EventAuxData_t* data, pusStoredParam_t data2);

#ifdef  __cplusplus
}
#endif

#endif // PUS_EVENTS_H
