/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_stored_param.h"
#include <string.h>



//
// Cast parameter to type
//

pusError_t pus_paramToUint32(uint32_t* outValue, pusStoredParam_t paramValue)
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

pusError_t pus_paramToInt32(int32_t* outValue, pusStoredParam_t paramValue)
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

pusError_t pus_paramToReal64(double* outValue, pusStoredParam_t paramValue)
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

pusError_t pus_paramToBool(bool* outValue, pusStoredParam_t paramValue)
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

pusError_t pus_paramToByte(uint8_t* outValue, pusStoredParam_t paramValue)
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

pusError_t pus_uint32ToParam(pusStoredParam_t* outParam, uint32_t inValue)
{
	if (NULL == outParam)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	*outParam = (uint64_t)inValue;
	return PUS_NO_ERROR;

}

pusError_t pus_int32ToParam(pusStoredParam_t* outParam, int32_t inValue)
{
	if (NULL == outParam)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	int64_t i64 = (int64_t)inValue;
	memcpy(outParam, &i64, sizeof(int64_t));
	return PUS_NO_ERROR;
}

pusError_t pus_real64ToParam(pusStoredParam_t* outParam, double inValue)
{
	if (NULL == outParam)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	memcpy(outParam, &inValue, sizeof(double));
	return PUS_NO_ERROR;
}

pusError_t pus_boolToParam(pusStoredParam_t* outParam, bool inValue)
{
	if (NULL == outParam)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	*outParam = (uint64_t)inValue;
	return PUS_NO_ERROR;
}

pusError_t pus_byteToParam(pusStoredParam_t* outParam, uint8_t inValue)
{
	if (NULL == outParam)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	*outParam = (uint64_t)inValue;
	return PUS_NO_ERROR;
}
