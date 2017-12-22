#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
#include <string.h>

#include "pus_stored_param.h"
#include "pus_parameter_management.h"


// Mutex to lock access to the housekeeping parameter tables
pusMutex_t* pus_parameters_mutex = NULL;

// Initialized flag
bool pus_parameters_initializedFlag = false;

// Array with the parameters information, declared in pus_st03_config.c
//extern pusSt03ParamInfo_t pus_st03_paramInfo[];

// Array for parameters values (all stored in 64 bits)
//extern pusStoredParam_t pus_st03_params[];

// First invalid parameter ID
//extern const pusSt03ParamId_t pus_ST03_PARAM_LIMIT;

pusError_t pus_parameters_initialize(pusMutex_t* mutex)
{
	if (pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	pus_parameters_mutex = mutex;

	if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	if (PUS_NO_ERROR != pus_parameters_configure())
	{
		if (NULL != pus_parameters_mutex)
		{
			(void) pus_mutexUnlockOk(pus_parameters_mutex);
		}
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	pus_parameters_initializedFlag = true;
	return PUS_NO_ERROR;
}

pusError_t pus_parameters_finalize()
{
	if (!pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		pus_parameters_mutex = NULL;
		pus_parameters_initializedFlag = false;
		return PUS_NO_ERROR;
	}
}

bool pus_parameters_isInitialized()
{
	return pus_parameters_initializedFlag;
}


