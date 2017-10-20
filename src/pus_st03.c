#include "pus_st03.h"
#include "pus_threads.h"
#include "pus_error.h"
#include <string.h>

// Mutex to lock access to the housekeeping parameter tables
pusMutex_t* pus_st03_mutex = NULL;

// Initialized flag
bool pus_st03_initializedFlag = false;

// Array with the parameters information, declared in pus_st03_config.c
extern pusSt03ParamInfo_t pus_st03_paramInfo[];

// Array for parameters values (all stored in 64 bits)
extern pusInternalParam_t pus_st03_params[];

// First invalid parameter ID
extern const pusSt03ParamId_t pus_ST03_PARAM_LIMIT;


pusError_t pus_st03_initialize(pusMutex_t* mutex)
{
	size_t numParams = 0;

	if (pus_st03_isInitialized())
	{
		return PUS_ERROR_ALREADY_INITIALIZED;
	}

	pus_st03_mutex = mutex;

	if (NULL != pus_st03_mutex && !pus_mutexLock(pus_st03_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	if (PUS_NO_ERROR != pus_st03_configure(&numParams))
	{
		if (NULL != pus_st03_mutex)
		{
			(void*) pus_mutexUnlock(pus_st03_mutex);
		}
		return PUS_ERROR_INITIALIZATION;
	}

	if (NULL != pus_st03_mutex && !pus_mutexUnlock(pus_st03_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	pus_st03_initializedFlag = true;
	return PUS_NO_ERROR;
}

pusError_t pus_st03_finalize()
{
	if (!pus_st03_isInitialized())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}
	else
	{
		pus_st03_mutex = NULL;
		pus_st03_initializedFlag = false;
		return PUS_NO_ERROR;
	}
}

bool pus_st03_isInitialized()
{
	return pus_st03_initializedFlag;
}


pusError_t pus_tm_3_25_createHousekeepingReportDefault(pusPacket_t* outTm, pusApidInfo_t* apid)
{
	return pus_tm_3_25_createHousekeepingReport(outTm, apid, pus_ST03_DEFAULT_HK_REPORT);
}

pusError_t pus_tm_3_25_createHousekeepingReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusSt03HousekeepingReportId_t reportId)
{
	if (!pus_st03_isInitialized())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	return PUS_ERROR_NOT_IMPLEMENTED;
}


pusError_t pus_st03_getUInt32Param(pusSt03ParamId_t param, uint32_t* outValue)
{
	if (NULL == outValue)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}
	else if (param >= pus_ST03_PARAM_LIMIT)
	{
		PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
		return PUS_ERROR_INVALID_ID;
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLock(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_UINT32 != pus_st03_paramInfo[param].type)
		{
			PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
			result = PUS_ERROR_INVALID_TYPE;
		}
		else
		{
			pusInternalParam_t value = pus_st03_params[param];

			if (UINT32_MAX >= value)
			{
				*outValue = (uint32_t)value;
				result = PUS_NO_ERROR;
			}
			else
			{
				return PUS_ERROR_LIMIT;
			}
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlock(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_st03_setUInt32Param(pusSt03ParamId_t param, uint32_t value)
{
	if (param >= pus_ST03_PARAM_LIMIT)
	{
		PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
		return PUS_ERROR_INVALID_ID;
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLock(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_UINT32 != pus_st03_paramInfo[param].type)
		{
			PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
			result = PUS_ERROR_INVALID_TYPE;
		}
		else
		{
			pus_st03_params[param] = (uint64_t)value;
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlock(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_st03_getInt32Param(pusSt03ParamId_t param, int32_t* outValue)
{
	if (NULL == outValue)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}
	else if (param >= pus_ST03_PARAM_LIMIT)
	{
		PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
		return PUS_ERROR_INVALID_ID;
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLock(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_INT32 != pus_st03_paramInfo[param].type)
		{
			PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
			result = PUS_ERROR_INVALID_TYPE;
		}
		else
		{
			int64_t value = 0;
			memcpy(&value, &pus_st03_params[param], sizeof(int64_t));

			if (INT32_MIN <= value && INT32_MAX >= value)
			{
				*outValue = value;
				result = PUS_NO_ERROR;
			}
			else
			{
				return PUS_ERROR_LIMIT;
			}
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlock(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_st03_setInt32Param(pusSt03ParamId_t param, int32_t value)
{
	if (param >= pus_ST03_PARAM_LIMIT)
	{
		PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
		return PUS_ERROR_INVALID_ID;
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLock(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_INT32 != pus_st03_paramInfo[param].type)
		{
			PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
			result = PUS_ERROR_INVALID_TYPE;
		}
		else
		{
			int64_t aux = value;
			memcpy(&pus_st03_params[param], &aux, sizeof(int64_t));
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlock(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_st03_getReal64Param(pusSt03ParamId_t param, double* outValue)
{
	if (NULL == outValue)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}
	else if (param >= pus_ST03_PARAM_LIMIT)
	{
		PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
		return PUS_ERROR_INVALID_ID;
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLock(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_REAL64 != pus_st03_paramInfo[param].type)
		{
			PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
			result = PUS_ERROR_INVALID_TYPE;
		}
		else
		{
			double value = 0.0;
			memcpy(&value, &pus_st03_params[param], sizeof(double));
			*outValue = value;
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlock(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_st03_setReal64Param(pusSt03ParamId_t param, double value)
{
	if (param >= pus_ST03_PARAM_LIMIT)
	{
		PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
		return PUS_ERROR_INVALID_ID;
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLock(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_REAL64 != pus_st03_paramInfo[param].type)
		{
			PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
			result = PUS_ERROR_INVALID_TYPE;
		}
		else
		{
			double aux = value;
			memcpy(&pus_st03_params[param], &aux, sizeof(double));
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlock(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_st03_getBoolParam(pusSt03ParamId_t param, bool* outValue)
{
	if (NULL == outValue)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}
	else if (param >= pus_ST03_PARAM_LIMIT)
	{
		PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
		return PUS_ERROR_INVALID_ID;
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLock(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_BOOL != pus_st03_paramInfo[param].type)
		{
			PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
			result = PUS_ERROR_INVALID_TYPE;
		}
		else
		{
			*outValue = (bool)pus_st03_params[param];
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlock(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_st03_setBoolParam(pusSt03ParamId_t param, bool value)
{
	if (param >= pus_ST03_PARAM_LIMIT)
	{
		PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
		return PUS_ERROR_INVALID_ID;
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLock(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_BOOL != pus_st03_paramInfo[param].type)
		{
			PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
			result = PUS_ERROR_INVALID_TYPE;
		}
		else
		{
			pus_st03_params[param] = (uint64_t)value;
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlock(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_st03_getByteParam(pusSt03ParamId_t param, uint8_t* outValue)
{
	if (NULL == outValue)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}
	else if (param >= pus_ST03_PARAM_LIMIT)
	{
		PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
		return PUS_ERROR_INVALID_ID;
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLock(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_BYTE != pus_st03_paramInfo[param].type)
		{
			PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
			result = PUS_ERROR_INVALID_TYPE;
		}
		else
		{
			uint64_t value = pus_st03_params[param];

			if (UINT8_MAX >= value)
			{
				*outValue = (uint8_t)value;
				result = PUS_NO_ERROR;
			}
			else
			{
				return PUS_ERROR_LIMIT;
			}
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlock(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

pusError_t pus_st03_setByteParam(pusSt03ParamId_t param, uint8_t value)
{
	if (param >= pus_ST03_PARAM_LIMIT)
	{
		PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
		return PUS_ERROR_INVALID_ID;
	}
	else
	{
		if (NULL != pus_st03_mutex && !pus_mutexLock(pus_st03_mutex))
		{
			return PUS_ERROR_THREADS;
		}

		pusError_t result = PUS_NO_ERROR;

		if (PUS_ST03_BYTE != pus_st03_paramInfo[param].type)
		{
			PUS_SET_ERROR(PUS_ERROR_INVALID_TYPE);
			result = PUS_ERROR_INVALID_TYPE;
		}
		else
		{
			pus_st03_params[param] = (uint64_t)value;
			result = PUS_NO_ERROR;
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlock(pus_st03_mutex))
		{
			result = PUS_ERROR_THREADS;
		}

		return result;
	}
}

