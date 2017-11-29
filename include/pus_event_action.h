//header


#ifndef PUS_EVENT_ACTION_H
#define PUS_EVENT_ACTION_H


#include "pus_types.h"
#include "pus_error.h"
#include "pus_threads.h"
#include "pus_events.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	//pusSt05EventId_t eventID; //Index in array will be eventID
	bool definitionStatus;
	pusPacket_t tcAction; //action TC? or reduced
	bool deleted;
}pusSt19EventActionDefinition_t;

//! List to manage the event-action definitions status
extern pusSt19EventActionDefinition_t pus_st19_EventActionDefinitionList[];

//! Maximun size of the definitions list
extern const size_t pus_st19_EventActionDefinitionListMaximum;

//! Function that configure the basic parameters for the service
extern pusError_t pus_eventAction_configure();

//! Function that initialize the service
pusError_t pus_eventAction_initialize(pusMutex_t* mutex);

pusError_t pus_eventAction_finalize();

//!
bool pus_eventAction_isInitialized();




pusError_t pus_eventAction_addEventActionDefinition(pusSt05EventId_t eventID, pusPacket_t* tcAction);

pusError_t pus_eventAction_deleteEventActionDefinition(pusSt05EventId_t eventID);

pusError_t pus_eventAction_enableEventActionDefinition(pusSt05EventId_t eventID);

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
