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
	pusPacket_t tcAction; //action TC? or reduced
	bool deleted;
}pusSt19EventActionDefinition_t;

//from config TODO
extern pusSt19EventActionDefinition_t pus_st19_EventActionDefinitionList[];
extern const size_t pus_st19_EventActionDefinitionListMaximum;

extern pusError_t pus_eventAction_configure();

pusError_t pus_eventAction_addEventActionDefinition(pusSt05EventId_t eventID, pusPacket_t* tcAction)
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

	int i;
	for(i = 0; i < pus_st19_EventActionDefinitionListMaximum; i++)
	{
		//check if exist

		if( false == pus_st19_EventActionDefinitionList[i].deleted )
		{
			pus_st19_EventActionDefinitionList[i].eventID = eventID;
			pus_st19_EventActionDefinitionList[i].definitionStatus = true;
			pus_st19_EventActionDefinitionList[i].tcAction = *tcAction;
			pus_st19_EventActionDefinitionList[i].deleted = false;

		}
	}

	if(i == pus_st19_EventActionDefinitionListMaximum)
	{
		return PUS_ERROR_FULL_EVENT_ACTION_LIST;
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
