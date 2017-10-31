#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
#include <string.h>
#include "pus_housekeeping.h"

// Mutex to lock access to the housekeeping parameter tables
pusMutex_t* pus_st03_mutex = NULL;

// Initialized flag
bool pus_st03_initializedFlag = false;

// Array with the parameters information, declared in pus_st03_config.c
extern pusSt03ParamInfo_t pus_st03_paramInfo[];

// Array for parameters values (all stored in 64 bits)
extern pusStoredParam_t pus_st03_params[];

// First invalid parameter ID
extern const pusSt03ParamId_t pus_ST03_PARAM_LIMIT;

pusError_t pus_hk_initialize(pusMutex_t* mutex)
{
	size_t numParams = 0;

	if (pus_hk_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	pus_st03_mutex = mutex;

	if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	if (PUS_NO_ERROR != pus_hk_configure(&numParams))
	{
		if (NULL != pus_st03_mutex)
		{
			(void) pus_mutexUnlockOk(pus_st03_mutex);
		}
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	pus_st03_initializedFlag = true;
	return PUS_NO_ERROR;
}

pusError_t pus_hk_finalize()
{
	if (!pus_hk_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		pus_st03_mutex = NULL;
		pus_st03_initializedFlag = false;
		return PUS_NO_ERROR;
	}
}

bool pus_hk_isInitialized()
{
	return pus_st03_initializedFlag;
}


pusError_t pus_hk_getUInt32Param(pusSt03ParamId_t param, uint32_t* outValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (param >= pus_ST03_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_UINT32 != pus_st03_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			result = pus_hk_paramToUInt32(outValue, pus_st03_params[param]);
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_hk_setUInt32Param(pusSt03ParamId_t param, uint32_t value)
{
	if (param >= pus_ST03_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_UINT32 != pus_st03_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			pus_st03_params[param] = (uint64_t)value;
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_hk_getInt32Param(pusSt03ParamId_t param, int32_t* outValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (param >= pus_ST03_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_INT32 != pus_st03_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			result = pus_hk_paramToInt32(outValue, pus_st03_params[param]);
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_hk_setInt32Param(pusSt03ParamId_t param, int32_t value)
{
	if (param >= pus_ST03_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_INT32 != pus_st03_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			int64_t aux = value;
			memcpy(&pus_st03_params[param], &aux, sizeof(int64_t));
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_hk_getReal64Param(pusSt03ParamId_t param, double* outValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (param >= pus_ST03_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_REAL64 != pus_st03_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			result = pus_hk_paramToReal64(outValue, pus_st03_params[param]);
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_hk_setReal64Param(pusSt03ParamId_t param, double value)
{
	if (param >= pus_ST03_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_REAL64 != pus_st03_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			double aux = value;
			memcpy(&pus_st03_params[param], &aux, sizeof(double));
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_hk_getBoolParam(pusSt03ParamId_t param, bool* outValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (param >= pus_ST03_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_BOOL != pus_st03_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			result = pus_hk_paramToBool(outValue, pus_st03_params[param]);
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_hk_setBoolParam(pusSt03ParamId_t param, bool value)
{
	if (param >= pus_ST03_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_BOOL != pus_st03_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			pus_st03_params[param] = (uint64_t)value;
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_hk_getByteParam(pusSt03ParamId_t param, uint8_t* outValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (param >= pus_ST03_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_BYTE != pus_st03_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			result = pus_hk_paramToByte(outValue, pus_st03_params[param]);
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_hk_setByteParam(pusSt03ParamId_t param, uint8_t value)
{
	if (param >= pus_ST03_PARAM_LIMIT)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_BYTE != pus_st03_paramInfo[param].type)
		{
			result = PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
		}
		else
		{
			pus_st03_params[param] = (uint64_t)value;
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

//
// Cast parameter to type
//

pusError_t pus_hk_paramToUInt32(uint32_t* outValue, pusStoredParam_t paramValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (paramValue > UINT32_MAX)
	{
		return PUS_SET_ERROR(PUS_ERROR_LIMIT);
	}
	else
	{
		*outValue = (uint32_t)paramValue;
		return PUS_NO_ERROR;
	}
}

pusError_t pus_hk_paramToInt32(int32_t* outValue, pusStoredParam_t paramValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		int64_t i64 = 0;
		memcpy(&i64, &paramValue, sizeof(int64_t));

		if (i64 < INT32_MIN || i64 > INT32_MAX)
		{
			return PUS_SET_ERROR(PUS_ERROR_LIMIT);
		}
		else
		{
			*outValue = (int32_t)i64;
			return PUS_NO_ERROR;
		}
	}
}

pusError_t pus_hk_paramToReal64(double* outValue, pusStoredParam_t paramValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		memcpy(outValue, &paramValue, sizeof(double));
		return PUS_NO_ERROR;
	}
}

pusError_t pus_hk_paramToBool(bool* outValue, pusStoredParam_t paramValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		*outValue = (bool)paramValue;
		return PUS_NO_ERROR;
	}
}

pusError_t pus_hk_paramToByte(uint8_t* outValue, pusStoredParam_t paramValue)
{
	if (NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (paramValue > UINT8_MAX)
	{
		return PUS_SET_ERROR(PUS_ERROR_LIMIT);
	}
	else
	{
		*outValue = (uint8_t)paramValue;
		return PUS_NO_ERROR;
	}
}


