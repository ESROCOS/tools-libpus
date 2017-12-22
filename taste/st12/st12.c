/* User code: This file will not be overwritten by TASTE. */

#include "st12.h"

#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_housekeeping.h"
#include "pus_st03_config.h"
#include "pus_st05_config.h"
#include "pus_st12_config.h"

void st12_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	pus_pmon_initialize(NULL);
}

void st12_PI_tc12(const asn1SccPusPacket *IN_tcPacket)
{
    /* Write your code here! */

}

void st12_PI_trigger()
{
    /* Write your code here! */
	pusStoredParam_t paramValue;
	pusSt01FailureCode_t isAvailable;

	for(pusSt03ParamId_t i = 0; i < PUS_ST12_PARAM_LIMIT; i++)
	{
		st12_RI_getParamValue(&i, &paramValue, &isAvailable);

		if( PUS_NO_ERROR == isAvailable )
		{
			printf("ST12: id: %llu, param:%llu (", i, paramValue);
			pusError_t error;
			switch ( pus_st03_paramInfo[i].type )
			{
				case PUS_INT32:
				{
					int32_t valueInt32;
					pus_paramToInt32(&valueInt32, paramValue);
					printf("%d)\n", valueInt32);
					error = pus_pmon_checkLimitInt32(i, valueInt32);
					break;
				}
				case PUS_UINT32:
				{
					uint32_t valueUint32;
					pus_paramToUint32(&valueUint32, paramValue);
					printf("%u)\n", valueUint32);
					error = pus_pmon_checkLimitUint32(i, valueUint32);
					break;
				}

				case PUS_REAL64:
				{
					double valueReal64;
					pus_paramToReal64(&valueReal64, paramValue);
					printf("%f)\n", valueReal64);
					error = pus_pmon_checkLimitReal64(i, valueReal64);
					break;
				}

				case PUS_BYTE:
				{
					uint8_t valueByte;
					pus_paramToByte(&valueByte, paramValue);
					printf("0x%x)\n", valueByte);
					error = pus_pmon_checkLimitByte(i, valueByte);
					break;
				}

				case PUS_BOOL:
				{
					bool valueBool;
					pus_paramToBool(&valueBool, paramValue);
					printf("%d)\n", valueBool);
					error = pus_pmon_checkLimitBool(i, valueBool);
					break;
				}

			}
			if( PUS_NO_ERROR !=  error)
			{
				printf("Error en PMON %llu, %d\n", i, error);
				pusSt05Event_t event;
				pus_events_createEVENT_ST12(&event, i, error);
				st12_RI_pushNewEvent(&event);
			}
		}
		else
		{
			printf("param not available\n");
		}
	}
}

