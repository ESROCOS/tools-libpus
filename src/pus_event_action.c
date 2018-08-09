/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_event_action.h"
#ifdef PUS_CONFIGURE_ST19_ENABLED

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

pusError_t pus_eventAction_finalize()
{
	if (!pus_eventAction_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		pus_eventAction_mutex = NULL;
		pus_eventAction_initializedFlag = false;
		return PUS_NO_ERROR;
	}
}

bool pus_eventAction_isInitialized()
{
	return pus_eventAction_initializedFlag;
}


pusError_t pus_eventAction_addEventActionDefinition(pusSt05EventId_t eventID, pusPacket_t* tcAction)
{
	if ( NULL == tcAction)
	{
		return PUS_ERROR_NULLPTR;
	}

	if( ! pus_eventAction_isInitialized() )
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( eventID >= pus_st19_EventActionDefinitionListMaximum )
	{
		return PUS_ERROR_OUT_OF_RANGE;
	}

	if( pus_eventAction_isEventActionDefinitionRegistered(eventID, tcAction) == true )
	{
		return PUS_ERROR_DEFINITION_ALREADY_EXIST;
	}

	if( true == pus_st19_EventActionDefinitionList[eventID].deleted )
	{
		pus_st19_EventActionDefinitionList[eventID].definitionStatus = false;
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

	if( eventID >= pus_st19_EventActionDefinitionListMaximum )
	{
		return PUS_ERROR_OUT_OF_RANGE;
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

	if( eventID >= pus_st19_EventActionDefinitionListMaximum )
	{
		return PUS_ERROR_OUT_OF_RANGE;
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

	if( eventID >= pus_st19_EventActionDefinitionListMaximum )
	{
		return PUS_ERROR_OUT_OF_RANGE;
	}

	if( false == pus_st19_EventActionDefinitionList[eventID].deleted )
	{
		pus_st19_EventActionDefinitionList[eventID].definitionStatus = false;
		return PUS_NO_ERROR;
	}

	return PUS_ERROR_DEFINITION_NOT_FOUND;
}


bool pus_eventAction_isEventActionDefinitionRegistered(pusSt05EventId_t eventID, const pusPacket_t* tcAction)
{
	if( false == pus_st19_EventActionDefinitionList[eventID].deleted )
	{
		if( pus_st19_EventActionDefinitionList[eventID].tcAction.apid == tcAction->apid )
		{
			if( pus_st19_EventActionDefinitionList[eventID].tcAction.data.u.tcData.header.serviceId == tcAction->data.u.tcData.header.serviceId)
			{
				if ( pus_st19_EventActionDefinitionList[eventID].tcAction.data.u.tcData.header.subtypeId == tcAction->data.u.tcData.header.subtypeId)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool pus_eventAction_isEventActionEnabled(pusSt05EventId_t eventID)
{
	if( eventID >= pus_st19_EventActionDefinitionListMaximum )
	{
		PUS_SET_ERROR(PUS_ERROR_OUT_OF_RANGE);
		return false;
	}

	if( false == pus_st19_EventActionDefinitionList[eventID].deleted )
	{
		if(	true == pus_st19_EventActionDefinitionList[eventID].definitionStatus )
		{
			return true;
		}
	}

	return false;
}

pusError_t pus_eventAction_getAction(pusPacket_t* tcAction , pusSt05EventId_t eventID)
{
	if( false == pus_eventAction_isEventActionEnabled(eventID) )
	{
		return PUS_ERROR_NO_ACTION_FOR_EVENT;
	}

	*tcAction =  pus_st19_EventActionDefinitionList[eventID].tcAction;

	return PUS_NO_ERROR;
}

#endif
