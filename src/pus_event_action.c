#include "pus_event_action.h"


bool pus_eventAction_checkIfDefinitionExist(pusSt05EventId_t eventID, const pusPacket_t* tcAction)
{
	for(int i = 0; i < pus_st19_EventActionDefinitionListMaximum; i++)
	{
		if( (eventID == pus_st19_EventActionDefinitionList[i].eventID) && (false == pus_st19_EventActionDefinitionList[i].deleted) )
		{
			if( pus_st19_EventActionDefinitionList[i].tcAction.apid == tcAction->apid)
			{
				/*if(pus_st19_EventActionDefinitionList[i].tcAction.sequenceCount == tcAction->sequenceCount){
					return true;
				}*/ //TODO
			}
		}
	}


	return false;
}


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
	if( pus_eventAction_checkIfDefinitionExist(eventID, tcAction) == true )
	{
		return PUS_ERROR_DEFINITION_ALREADY_EXIST;
	}


	for(int i = 0; i < pus_st19_EventActionDefinitionListMaximum; i++)
	{
		//check if exist

		if( true == pus_st19_EventActionDefinitionList[i].deleted )
		{
			pus_st19_EventActionDefinitionList[i].eventID = eventID;
			pus_st19_EventActionDefinitionList[i].definitionStatus = true;
			pus_st19_EventActionDefinitionList[i].tcAction = *tcAction;
			pus_st19_EventActionDefinitionList[i].deleted = false;

			return PUS_NO_ERROR;
		}
	}


	return PUS_ERROR_FULL_EVENT_ACTION_LIST;
}

pusError_t pus_eventAction_deleteEventActionDefinition(pusSt05EventId_t eventID, pusPacket_t* tcAction)
{
	for(int i = 0; i < pus_st19_EventActionDefinitionListMaximum; i++)
	{
		//check if exist

		if( (eventID == pus_st19_EventActionDefinitionList[i].eventID) && (false == pus_st19_EventActionDefinitionList[i].deleted) )
		{
			pus_st19_EventActionDefinitionList[i].deleted = true;
			return PUS_NO_ERROR;
		}
	}

	return PUS_ERROR_DEFINITION_NOT_FOUND;
}

pusError_t pus_eventAction_enableEventActionDefinition(pusSt05EventId_t eventID, pusPacket_t* tcAction)
{

	for(int i = 0; i < pus_st19_EventActionDefinitionListMaximum; i++)
	{
		//check if exist

		if( (eventID == pus_st19_EventActionDefinitionList[i].eventID) && (false == pus_st19_EventActionDefinitionList[i].deleted) )
		{
			pus_st19_EventActionDefinitionList[i].definitionStatus = true;
			return PUS_NO_ERROR;
		}
	}
	return PUS_ERROR_DEFINITION_NOT_FOUND;
}

pusError_t pus_eventAction_disableEventActionDefinition(pusSt05EventId_t eventID, pusPacket_t* tcAction)
{

	for(int i = 0; i < pus_st19_EventActionDefinitionListMaximum; i++)
	{
		//check if exist

		if( (eventID == pus_st19_EventActionDefinitionList[i].eventID) && (false == pus_st19_EventActionDefinitionList[i].deleted) )
		{
			pus_st19_EventActionDefinitionList[i].definitionStatus = false;
			return PUS_NO_ERROR;
		}
	}
	return PUS_ERROR_DEFINITION_NOT_FOUND;
}
