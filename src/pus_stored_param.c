#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_stored_param.h"
#include <string.h>



//
// Cast parameter to type
//

pusError_t pus_paramToUInt32(uint32_t* outValue, pusStoredParam_t paramValue)
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
