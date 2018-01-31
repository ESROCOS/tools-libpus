/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

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

//! Array with parameter information (length = number of parameters)
extern pusSt20ParamInfo_t pus_st20_paramInfo[];

//! Array for parameters values (all stored in 64 bits)
extern pusStoredParam_t pus_st20_params[];

//! ST[20]on board parameters limit
extern const pusSt20OnBoardParamId_t pus_ST20_PARAM_LIMIT;

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


pusError_t pus_parameters_getStoredParam(pusSt20OnBoardParamId_t param, pusStoredParam_t* outValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		*outValue = pus_st20_params[param];

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		return PUS_NO_ERROR;
	}
}

pusError_t pus_parameters_setStoredParam(pusSt20OnBoardParamId_t param, pusStoredParam_t outValue)
{
	if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pus_st20_params[param] = outValue;

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		return PUS_NO_ERROR;
	}
}


pusError_t pus_parameters_getUInt32Param(pusSt20OnBoardParamId_t param, uint32_t* outValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_UINT32 != pus_st20_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			result = pus_paramToUint32(outValue, pus_st20_params[param]);
		}

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_parameters_setUInt32Param(pusSt20OnBoardParamId_t param, uint32_t value)
{
	if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_UINT32 != pus_st20_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			pus_st20_params[param] = (uint64_t)value;
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_parameters_getInt32Param(pusSt20OnBoardParamId_t param, int32_t* outValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_INT32 != pus_st20_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			result = pus_paramToInt32(outValue, pus_st20_params[param]);
		}

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_parameters_setInt32Param(pusSt20OnBoardParamId_t param, int32_t value)
{
	 if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_INT32 != pus_st20_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			int64_t aux = value;
			memcpy(&pus_st20_params[param], &aux, sizeof(int64_t));
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_parameters_getReal64Param(pusSt20OnBoardParamId_t param, double* outValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_REAL64 != pus_st20_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			result = pus_paramToReal64(outValue, pus_st20_params[param]);
		}

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_parameters_setReal64Param(pusSt20OnBoardParamId_t param, double value)
{
	if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_REAL64 != pus_st20_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			double aux = value;
			memcpy(&pus_st20_params[param], &aux, sizeof(double));
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_parameters_getBoolParam(pusSt20OnBoardParamId_t param, bool* outValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_BOOL != pus_st20_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			result = pus_paramToBool(outValue, pus_st20_params[param]);
		}

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_parameters_setBoolParam(pusSt20OnBoardParamId_t param, bool value)
{
	if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_BOOL != pus_st20_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			pus_st20_params[param] = (uint64_t)value;
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_parameters_getByteParam(pusSt20OnBoardParamId_t param, uint8_t* outValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_BYTE != pus_st20_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			result = pus_paramToByte(outValue, pus_st20_params[param]);
		}

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_parameters_setByteParam(pusSt20OnBoardParamId_t param, uint8_t value)
{
	if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_BYTE != pus_st20_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			pus_st20_params[param] = (uint64_t)value;
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_parameters_getParamType(pusSt20OnBoardParamId_t param, pusParamType_t* type)
{
	if (NULL == type)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (! pus_parameters_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	if (param >= pus_ST20_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_parameters_mutex && !pus_mutexLockOk(pus_parameters_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		*type = pus_st20_paramInfo[param].type;


		if (NULL != pus_parameters_mutex && !pus_mutexUnlockOk(pus_parameters_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}
