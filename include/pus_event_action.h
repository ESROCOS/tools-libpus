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
	pusSt05EventId_t eventID;
	bool definitionStatus;
	pusPacket_t tcAction; //action TC?
	bool deleted;
}pusSt19EventActionDefinition_t;

//from config TODO
extern pusSt19EventActionDefinition_t pus_st19_EventActionDefinitionList[];
extern const size_t pus_st19_EventActionDefinitionListMaximum;

extern pusError_t pus_eventAction_configure();

pusError_t pus_eventAction_addEventActionDefinition()
{
	//reject if
	// 	- same event/action
	//  - maximum reached
	//  - action fail
	// then generate failed start of execution

	//TODO The event-action subservice shall process any valid instruction that is contained
	//within a request to add event-action definitions regardless of the presence of faulty instructions.


	//accept if
	//  -
	for(int i = 0; i < pus_st19_EventActionDefinitionListMaximum; i++)
	{
		//check if exist
		//if()
	}
	return PUS_NO_ERROR;
}

pusError_t pus_eventAction_deleteEventActionDefinition()
{

	return PUS_NO_ERROR;
}

pusError_t pus_eventAction_enableEventActionDefinition()
{

	return PUS_NO_ERROR;
}

pusError_t pus_eventAction_disableEventActionDefinition()
{

	return PUS_NO_ERROR;
}

#ifdef __cplusplus
}
#endif


#endif
