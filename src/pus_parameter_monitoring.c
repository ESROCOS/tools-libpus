#include "pus_parameter_monitoring.h"


// Mutex to lock access to the event tables
pusMutex_t* pus_pmon_mutex = NULL;

// Boolean to check the status of the service
bool pus_pmon_initializedFlag = false;

// Boolean to enable the check of params
bool pus_pmon_functionStatus = false;

//List of PMON definitions
extern pusSt12PmonDefinition pus_pmon_definitionList[];

extern const pusSt12PmonId_t pus_ST12_PARAM_LIMIT;

pusError_t pus_pmon_initialize(pusMutex_t* mutex)
{
	if (pus_pmon_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	pus_pmon_mutex = mutex;

	if (NULL != pus_pmon_mutex && !pus_mutexLockOk(pus_pmon_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	if (PUS_NO_ERROR != pus_pmon_configure())
	{
		if (NULL != pus_pmon_mutex)
		{
			(void) pus_mutexUnlockOk(pus_pmon_mutex);
		}
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	if (NULL != pus_pmon_mutex && !pus_mutexUnlockOk(pus_pmon_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	// Flag service initialized = true
	pus_pmon_initializedFlag = true;
	pus_pmon_functionStatus = true;
	return PUS_NO_ERROR;
}


pusError_t pus_pmon_finalize()
{
	if (!pus_pmon_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		pus_pmon_mutex = NULL;
		pus_pmon_initializedFlag = false;
		pus_pmon_functionStatus = false;
		return PUS_NO_ERROR;
	}
}

bool pus_pmon_isInitialized()
{
	return pus_pmon_initializedFlag;
}

bool pus_pmon_inInDefinitionList(pusSt12PmonId_t id)
{
	return (id < pus_ST12_PARAM_LIMIT);
}

pusError_t pus_pmon_enableDefinition(pusSt12PmonId_t id)
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	if( !pus_pmon_inInDefinitionList(id) )
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}

	if(pus_pmon_definitionList[id].status == true)
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_ENABLED);
	}

	pus_pmon_definitionList[id].status = true;
	return PUS_NO_ERROR;
}

pusError_t pus_pmon_disableDefinition(pusSt12PmonId_t id)
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	if( !pus_pmon_inInDefinitionList(id) )
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}

	if(pus_pmon_definitionList[id].status == false)
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_DISABLED);
	}

	pus_pmon_definitionList[id].status = false;
	return PUS_NO_ERROR;
}

pusError_t pus_pmon_enableFunction()
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	pus_pmon_functionStatus = true;
	return PUS_NO_ERROR;
}

pusError_t pus_pmon_disableFunction()
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	pus_pmon_functionStatus = false;
	return PUS_NO_ERROR;
}



