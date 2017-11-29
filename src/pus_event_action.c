#include "pus_event_action.h"



pusMutex_t* pus_eventAction_mutex;

bool pus_eventAction_initializedFlag = false;

pusError_t pus_eventAction_initialize(pusMutex_t* mutex)
{
	if (pus_eventAction_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	pus_eventAction_mutex = mutex;

	if (NULL != pus_eventAction_mutex && !pus_mutexLockOk(pus_eventAction_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	if (PUS_NO_ERROR != pus_eventAction_configure())
	{
		if (NULL != pus_eventAction_mutex)
		{
			(void) pus_mutexUnlockOk(pus_eventAction_mutex);
		}
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	if (NULL != pus_eventAction_mutex && !pus_mutexUnlockOk(pus_eventAction_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	// Flag service initialized = true
	pus_eventAction_initializedFlag = true;
	return PUS_NO_ERROR;
}

bool pus_eventAction_isInitialized()
{
	return pus_eventAction_initializedFlag;
}

bool pus_eventAction_checkIfDefinitionExist(pusSt05EventId_t eventID, const pusPacket_t* tcAction)
{
	if( eventID >= pus_st19_EventActionDefinitionListMaximum )
	{
		return false;
	}
	if( false == pus_st19_EventActionDefinitionList[eventID].deleted )
	{
		if( pus_st19_EventActionDefinitionList[eventID].tcAction.apid == tcAction->apid )
		{
			if( pus_st19_EventActionDefinitionList[eventID].tcAction.data.u.tcData.header.service == tcAction->data.u.tcData.header.service)
			{
				if (pus_st19_EventActionDefinitionList[eventID].tcAction.data.u.tcData.header.subtype == tcAction->data.u.tcData.header.subtype)
				{
					return true;
				}
			}
		}
	}

	return false;
}


pusError_t pus_eventAction_addEventActionDefinition(pusSt05EventId_t eventID, pusPacket_t* tcAction)
{
	if( ! pus_eventAction_isInitialized() )
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( pus_eventAction_checkIfDefinitionExist(eventID, tcAction) == true )
	{
		return PUS_ERROR_DEFINITION_ALREADY_EXIST;
	}


	if( true == pus_st19_EventActionDefinitionList[eventID].deleted )
	{
		pus_st19_EventActionDefinitionList[eventID].definitionStatus = true;
		pus_st19_EventActionDefinitionList[eventID].tcAction = *tcAction;
		pus_st19_EventActionDefinitionList[eventID].deleted = false;

		return PUS_NO_ERROR;
	}

	return PUS_ERROR_DEFINITION_ALREADY_EXIST;
}

pusError_t pus_eventAction_deleteEventActionDefinition(pusSt05EventId_t eventID)
{
	if( ! pus_eventAction_isInitialized() )
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( false == pus_st19_EventActionDefinitionList[eventID].deleted )
	{
		pus_st19_EventActionDefinitionList[eventID].deleted = true;
		return PUS_NO_ERROR;
	}

	return PUS_ERROR_DEFINITION_NOT_FOUND;
}

pusError_t pus_eventAction_enableEventActionDefinition(pusSt05EventId_t eventID)
{
	if( ! pus_eventAction_isInitialized() )
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( false == pus_st19_EventActionDefinitionList[eventID].deleted )
	{
		pus_st19_EventActionDefinitionList[eventID].definitionStatus = true;
		return PUS_NO_ERROR;
	}

	return PUS_ERROR_DEFINITION_NOT_FOUND;
}

pusError_t pus_eventAction_disableEventActionDefinition(pusSt05EventId_t eventID)
{
	if( ! pus_eventAction_isInitialized() )
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( false == pus_st19_EventActionDefinitionList[eventID].deleted )
	{
		pus_st19_EventActionDefinitionList[eventID].definitionStatus = false;
		return PUS_NO_ERROR;
	}

	return PUS_ERROR_DEFINITION_NOT_FOUND;
}
