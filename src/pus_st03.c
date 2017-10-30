#include "pus_st03.h"
#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
#include <string.h>

// Mutex to lock access to the housekeeping parameter tables
pusMutex_t* pus_st03_mutex = NULL;

// Initialized flag
bool pus_st03_initializedFlag = false;

// Array with the parameters information, declared in pus_st03_config.c
extern pusSt03ParamInfo_t pus_st03_paramInfo[];

// Array for parameters values (all stored in 64 bits)
extern pusInternalParam_t pus_st03_params[];

// Structure of the default HK report
extern pusSt03ReportInfo_t pus_st03_defaultHkReportInfo;

// First invalid parameter ID
extern const pusSt03ParamId_t pus_ST03_PARAM_LIMIT;

pusError_t pus_st03_initialize(pusMutex_t* mutex)
{
	size_t numParams = 0;

	if (pus_st03_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	pus_st03_mutex = mutex;

	if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	if (PUS_NO_ERROR != pus_st03_configure(&numParams))
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

pusError_t pus_st03_finalize()
{
	if (!pus_st03_isInitialized())
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

bool pus_st03_isInitialized()
{
	return pus_st03_initializedFlag;
}


pusError_t pus_tm_3_25_createHousekeepingReportDefault(pusPacket_t* outTm, pusApidInfo_t* apid, pusApid_t destination)
{
	return pus_tm_3_25_createHousekeepingReport(outTm, apid, pus_ST03_DEFAULT_HK_REPORT, destination);
}

pusError_t pus_tm_3_25_createHousekeepingReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusSt03HousekeepingReportId_t reportId, pusApid_t destination)
{
	size_t numParams = 0;
	pusSt03ParamId_t* paramIds;

	if (NULL == outTm || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (PUS_IS_ERROR())
	{
		return PUS_ERROR_BEFORE;
	}

	if (!pus_st03_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	// Get the array defining the report contents
	if (pus_ST03_DEFAULT_HK_REPORT == reportId)
	{
		numParams = pus_st03_defaultHkReportInfo.numParams;
		paramIds = pus_st03_defaultHkReportInfo.paramIds;
	}
	// handle here user-defined HK reports (not yet implemented)
	else
	{
		return PUS_SET_ERROR(PUS_ERROR_REPORT_ID_UNKNOWN);
	}

	if (numParams > pus_ST03_MAX_REPORT_LENGTH)
	{
		return PUS_SET_ERROR(PUS_ERROR_REPORT_LENGTH);
	}

	// Build the TM packet

	pus_initTmPacket(outTm);
	pus_setTmDataKind(outTm, pus_TM_DATA_ST_3_25);

	// Source information
	pus_setApid(outTm, pus_getInfoApid(apid));
	pus_setSequenceCount(outTm, pus_getNextTmCount(apid));

	// Data length
	pus_setPacketDataLength(outTm, sizeof(pusPacketData_t));

	// Service identification
	pus_setTmService(outTm, pus_ST03_housekeeping);
	pus_setTmSubtype(outTm, pus_TM_3_25_housekeepingReport);

	// Destination
	pus_setTmDestination(outTm, destination);

	// Timestamp
	pus_setTmPacketTimeNow(outTm);

	// Report contents
	pus_tm_3_25_setReportId(outTm, reportId);
	return (pus_tm_3_25_setParameterValues(outTm, paramIds, numParams));
}


pusError_t pus_st03_getUInt32Param(pusSt03ParamId_t param, uint32_t* outValue)
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
			result = pus_st03_paramToUInt32(outValue, pus_st03_params[param]);
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
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

pusError_t pus_st03_getInt32Param(pusSt03ParamId_t param, int32_t* outValue)
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
			result = pus_st03_paramToInt32(outValue, pus_st03_params[param]);
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
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

pusError_t pus_st03_getReal64Param(pusSt03ParamId_t param, double* outValue)
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
			result = pus_st03_paramToReal64(outValue, pus_st03_params[param]);
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
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

pusError_t pus_st03_getBoolParam(pusSt03ParamId_t param, bool* outValue)
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
			result = pus_st03_paramToBool(outValue, pus_st03_params[param]);
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
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

pusError_t pus_st03_getByteParam(pusSt03ParamId_t param, uint8_t* outValue)
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
			result = pus_st03_paramToByte(outValue, pus_st03_params[param]);
		}

		if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
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

pusSt03HousekeepingReportId_t pus_tm_3_25_getReportId(const pusPacket_t* tm)
{
	if (NULL == tm)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	else if (PUS_NO_ERROR != PUS_EXPECT_ST03(tm, pus_TM_3_25_housekeepingReport))
	{
		return 0;
	}
	else
	{
		return tm->data.u.tmData.data.u.st_3_25.reportId;
	}
}

void pus_tm_3_25_setReportId(pusPacket_t* outTm, pusSt03HousekeepingReportId_t reportId)
{
	if (NULL == outTm)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}
	else if (PUS_NO_ERROR == PUS_EXPECT_ST03(outTm, pus_TM_3_25_housekeepingReport))
	{
		outTm->data.u.tmData.data.u.st_3_25.reportId = reportId;
	}
}

pusError_t pus_tm_3_25_setParameterValues(pusPacket_t* outTm, const pusSt03ParamId_t* paramIds, size_t numParams)
{
	if (NULL == outTm || NULL == paramIds)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (numParams > pus_ST03_MAX_REPORT_LENGTH)
	{
		return PUS_SET_ERROR(PUS_ERROR_REPORT_LENGTH);
	}

	if (PUS_NO_ERROR != PUS_EXPECT_ST03(outTm, pus_TM_3_25_housekeepingReport))
	{
		return PUS_GET_ERROR();
	}

	// Lock access parameters array
	if (NULL != pus_st03_mutex && !pus_mutexLockOk(pus_st03_mutex))
	{
		return PUS_ERROR_THREADS;
	}

	// Copy parameter values to the packet
	for (uint32_t i = 0; i < numParams; i++)
	{
		outTm->data.u.tmData.data.u.st_3_25.parameters.arr[i] = pus_st03_params[paramIds[i]];
	}

	// Set number of parameters in packet
	outTm->data.u.tmData.data.u.st_3_25.parameters.nCount = numParams;

	// Unlock access to parameters array
	if (NULL != pus_st03_mutex && !pus_mutexUnlockOk(pus_st03_mutex))
	{
		return PUS_ERROR_THREADS;
	}

	return PUS_NO_ERROR;
}

pusError_t pus_tm_3_25_getParameterValue(const pusPacket_t* tm, size_t index, pusInternalParam_t* outValue)
{
	if (NULL == tm || NULL == outValue)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (PUS_NO_ERROR != PUS_EXPECT_ST03(tm, pus_TM_3_25_housekeepingReport))
	{
		return PUS_GET_ERROR();
	}

	// Check against maximum and actual size of the packet
	if (index > (size_t)pus_ST03_MAX_REPORT_LENGTH || index > (size_t)tm->data.u.tmData.data.u.st_3_25.parameters.nCount)
	{
		return PUS_SET_ERROR(PUS_ERROR_REPORT_LENGTH);
	}

	*outValue = tm->data.u.tmData.data.u.st_3_25.parameters.arr[index];

	return PUS_NO_ERROR;
}

pusError_t pus_tm_3_25_getNumParameters(const pusPacket_t* tm, size_t* outNumParams)
{
	if (NULL == tm || NULL == outNumParams)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (PUS_NO_ERROR != PUS_EXPECT_ST03(tm, pus_TM_3_25_housekeepingReport))
	{
		return PUS_GET_ERROR();
	}

	*outNumParams = (size_t)tm->data.u.tmData.data.u.st_3_25.parameters.nCount;

	return PUS_NO_ERROR;
}


//
// Cast parameter to type
//

pusError_t pus_st03_paramToUInt32(uint32_t* outValue, pusInternalParam_t paramValue)
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

pusError_t pus_st03_paramToInt32(int32_t* outValue, pusInternalParam_t paramValue)
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

pusError_t pus_st03_paramToReal64(double* outValue, pusInternalParam_t paramValue)
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

pusError_t pus_st03_paramToBool(bool* outValue, pusInternalParam_t paramValue)
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

pusError_t pus_st03_paramToByte(uint8_t* outValue, pusInternalParam_t paramValue)
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


//
// Parameter checking
//

pusError_t pus_expectSt03Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTmHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTmService(packet);
		pusSubservice_t subtype = pus_getTmSubtype(packet);

		if (service != pus_ST03_housekeeping)
		{
			pus_setError(PUS_ERROR_TM_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TM_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[01]
			if ((subtype != pus_TM_3_25_housekeepingReport))
			{
				pus_setError(PUS_ERROR_TM_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TM_SUBTYPE;
			}
		}
		else
		{
			// Check that subtype is as expected
			if (subtype != expectedSubtype)
			{
				pus_setError(PUS_ERROR_TM_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TM_SUBTYPE;

			}
		}

		pusPacketDataKind_t kind = pus_getTmDataKind(packet);
		if (kind != pus_TM_DATA_ST_3_25)
		{
			pus_setError(PUS_ERROR_TM_KIND, function, (pusErrorData_t){.integer=kind});
			return PUS_ERROR_TM_KIND;
		}

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}

