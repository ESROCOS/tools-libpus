/*! \file pus_event_action.h
 *  \brief Management of the event-action definitions table
 *
 *  Defines the functions and structures that manage the event-action definitions table.
 *
 *  Access to the table is optionally protected by a mutex. This allows implementing
 *  the service using external synchronization (by TASTE) or not.
 *
 *  \author GMV
 */


#ifndef PUS_EVENT_ACTION_H
#define PUS_EVENT_ACTION_H


#include "pus_types.h"
#include "pus_error.h"
#include "pus_threads.h"
#include "pus_events.h"

#ifdef __cplusplus
extern "C" {
#endif

//! Type to describe an event-action definition
typedef struct
{
	//pusSt05EventId_t eventID; //Index in array will be eventID
	bool definitionStatus; //!< Status of the definition (enabled or disabled)
	pusPacket_t tcAction; //!< TC action of the definition
	bool deleted; //!< True if definition is deleted
}pusSt19EventActionDefinition_t;

//! List to manage the event-action definitions status
extern pusSt19EventActionDefinition_t pus_st19_EventActionDefinitionList[];

//! Maximun size of the definitions list
extern const size_t pus_st19_EventActionDefinitionListMaximum;

//! Function that configure the basic parameters for the service
extern pusError_t pus_eventAction_configure();

//! Function that initialize the service
pusError_t pus_eventAction_initialize(pusMutex_t* mutex);

//! Function that finalize the service
pusError_t pus_eventAction_finalize();

//! Check if the event action is initialized
bool pus_eventAction_isInitialized();


//! Add a definition to an event-action
pusError_t pus_eventAction_addEventActionDefinition(pusSt05EventId_t eventID, pusPacket_t* tcAction);

//! Delete the definition of an event-action
pusError_t pus_eventAction_deleteEventActionDefinition(pusSt05EventId_t eventID);

//! Enable the definition of an event-action
pusError_t pus_eventAction_enableEventActionDefinition(pusSt05EventId_t eventID);

//! Disable the definition of an event-action
pusError_t pus_eventAction_disableEventActionDefinition(pusSt05EventId_t eventID);

//! Function that check if an event-action definition is in the list
bool pus_eventAction_isEventActionDefinitionRegistered(pusSt05EventId_t eventID, const pusPacket_t* tcAction);

//! Function that check if the action for an event is enabled.
bool pus_eventAction_isEventActionEnabled(pusSt05EventId_t eventID);

//! Get the TC action of an event if possible.
pusError_t pus_eventAction_getAction(pusPacket_t* tcAction , pusSt05EventId_t eventID);


#ifdef __cplusplus
}
#endif


#endif
