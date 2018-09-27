/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_parameter_monitoring.h"
#ifdef PUS_CONFIGURE_ST12_ENABLED


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
	pus_pmon_functionStatus = false;
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



pusError_t pus_pmon_enableDefinition(pusSt12PmonId_t id)
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	if( !pus_pmon_isInDefinitionList(id) )
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

	if( !pus_pmon_isInDefinitionList(id) )
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

bool pus_pmon_isInitialized()
{
	return pus_pmon_initializedFlag;
}

bool pus_pmon_isFunctionActivated()
{
	return pus_pmon_functionStatus;
}

bool pus_pmon_getDefinitionStatus(pusSt12PmonId_t id)
{
	if( ! pus_pmon_isInitialized())
	{
		PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
		return false;
	}

	if( ! pus_pmon_isFunctionActivated())
	{
		PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
		return false;
	}

	if( ! pus_pmon_isInDefinitionList(id))
	{
		PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
		return false;
	}

	PUS_SET_ERROR(PUS_NO_ERROR);
	return pus_pmon_definitionList[id].status;
}


pusError_t pus_pmon_setDefinitionStatus(pusSt12PmonId_t id, bool status)
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( ! pus_pmon_isInDefinitionList(id))
	{
		return PUS_ERROR_INVALID_ID;
	}

	pus_pmon_definitionList[id].status = status;
	return PUS_NO_ERROR;
}

bool pus_pmon_isInDefinitionList(pusSt12PmonId_t id)
{
	return (id < pus_ST12_PARAM_LIMIT);
}

//! Check if a value is valid
pusError_t pus_pmon_checkParameter(pusSt12PmonId_t id)
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( ! pus_pmon_isFunctionActivated())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( ! pus_pmon_isInDefinitionList(id) )
	{
		return PUS_ERROR_INVALID_ID;
	}

	if ( ! pus_pmon_getDefinitionStatus(id) )
	{
		return PUS_ERROR_DEFINITION_DISABLED;
	}

	pusParamType_t type;
	pus_hk_getParamType(id, &type);
	switch(type)
	{
		case PUS_INT32:
		{
			int32_t value;
			pus_hk_getInt32Param(id, &value);
			return pus_pmon_checkLimitInt32(id, value);
		}
		case PUS_UINT32:
		{
			uint32_t value;
			pus_hk_getUInt32Param(id, &value);
			return pus_pmon_checkLimitUint32(id, value);
		}
		case PUS_REAL64:
		{
			double value;
			pus_hk_getReal64Param(id, &value);
			return pus_pmon_checkLimitReal64(id, value);
		}
		case PUS_BYTE:
		{
			uint8_t value;
			pus_hk_getByteParam(id, &value);
			return pus_pmon_checkLimitByte(id, value);
		}
		case PUS_BOOL:
		{
			bool value;
			pus_hk_getBoolParam(id, &value);
			return pus_pmon_checkLimitBool(id, value);
		}
		default:
			return PUS_ERROR_UNEXPECTED_PARAM_TYPE;
			break;
	}
}

pusError_t pus_pmon_checkLimitInt32(pusSt12PmonId_t id, int32_t value)
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( ! pus_pmon_isInDefinitionList(id) )
	{
		return PUS_ERROR_INVALID_ID;
	}

	if( value > pus_pmon_definitionList[id].check.high_limit.INT32 )
	{
		return PUS_ERROR_ABOVE_HIGH_LIMIT;
	}
	else if ( value < pus_pmon_definitionList[id].check.low_limit.INT32 )
	{
		return PUS_ERROR_BELOW_LOW_LIMIT;
	}
	else
	{
		return PUS_NO_ERROR;
	}
}

pusError_t pus_pmon_checkLimitUint32(pusSt12PmonId_t id, uint32_t value)
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( ! pus_pmon_isInDefinitionList(id) )
	{
		return PUS_ERROR_INVALID_ID;
	}

	if( value > pus_pmon_definitionList[id].check.high_limit.UINT32 )
	{
		return PUS_ERROR_ABOVE_HIGH_LIMIT;
	}
	else if ( value < pus_pmon_definitionList[id].check.low_limit.UINT32 )
	{
		return PUS_ERROR_BELOW_LOW_LIMIT;
	}
	else
	{
		return PUS_NO_ERROR;
	}
}

pusError_t pus_pmon_checkLimitReal64(pusSt12PmonId_t id, double value)
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( ! pus_pmon_isInDefinitionList(id) )
	{
		return PUS_ERROR_INVALID_ID;
	}

	if( value > pus_pmon_definitionList[id].check.high_limit.REAL64 )
	{
		return PUS_ERROR_ABOVE_HIGH_LIMIT;
	}
	else if ( value < pus_pmon_definitionList[id].check.low_limit.REAL64 )
	{
		return PUS_ERROR_BELOW_LOW_LIMIT;
	}
	else
	{
		return PUS_NO_ERROR;
	}
}

pusError_t pus_pmon_checkLimitByte(pusSt12PmonId_t id, uint8_t value)
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( ! pus_pmon_isInDefinitionList(id) )
	{
		return PUS_ERROR_INVALID_ID;
	}

	if( value > pus_pmon_definitionList[id].check.high_limit.BOOL )
	{
		return PUS_ERROR_ABOVE_HIGH_LIMIT;
	}
	else if ( value < pus_pmon_definitionList[id].check.low_limit.BOOL )
	{
		return PUS_ERROR_BELOW_LOW_LIMIT;
	}
	else
	{
		return PUS_NO_ERROR;
	}
}

pusError_t pus_pmon_checkLimitBool(pusSt12PmonId_t id, bool value)
{
	if( ! pus_pmon_isInitialized())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( ! pus_pmon_isInDefinitionList(id) )
	{
		return PUS_ERROR_INVALID_ID;
	}

	if( value > pus_pmon_definitionList[id].check.high_limit.BOOL )
	{
		return PUS_ERROR_ABOVE_HIGH_LIMIT;
	}
	else if ( value < pus_pmon_definitionList[id].check.low_limit.BOOL )
	{
		return PUS_ERROR_BELOW_LOW_LIMIT;
	}
	else
	{
		return PUS_NO_ERROR;
	}
}

#endif
