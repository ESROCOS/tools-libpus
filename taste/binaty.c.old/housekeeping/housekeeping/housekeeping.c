/* User code: This file will not be overwritten by TASTE. */

#include "housekeeping.h"

#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st03_packets.h"
#include "pus_housekeeping.h"
#include "pus_st03_config.h"

void housekeeping_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	pus_hk_initialize(NULL);

	pus_hk_setHK_PARAM_INT01(5);
	pus_hk_setHK_PARAM_REAL01(-6.58);
	pus_hk_setHK_PARAM_INT02(6);
	pus_hk_setHK_PARAM_UINT01(10);
	pus_hk_setHK_PARAM_BYTE01(0x3);
	pus_hk_setHK_PARAM_BOOL01(true);
}

void housekeeping_PI_getParamValue(const asn1SccPusSt03ParameterId *IN_paramId,
                                   asn1SccPusSt03StoredParam *OUT_paramValue,
                                   asn1SccPusSt01FailureCode *OUT_isAvailable)
{
    /* Write your code here! */
	*OUT_isAvailable = pus_hk_getStoredParam(*IN_paramId, OUT_paramValue);

}

void housekeeping_PI_setParamValue(const asn1SccPusSt03ParameterId *IN_paramId,
                                   const asn1SccPusSt03StoredParam *IN_paramValue)
{
    /* Write your code here! */
	pus_hk_setStoredParam(*IN_paramId, *IN_paramValue);

}

