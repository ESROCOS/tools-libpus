/* User code: This file will not be overwritten by TASTE. */

#include "onboardparams.h"
#include "pus_types.h"
#include "pus_error.h"

#include "pus_parameter_management.h"
#include "pus_st20_config.h"


void onboardparams_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	pus_parameters_initialize(NULL);

	pus_hk_setONBOARD_PARAM_INT01(-23);
	pus_hk_setONBOARD_PARAM_REAL01(3.35);
	pus_hk_setONBOARD_PARAM_UINT01(36);
	pus_hk_setONBOARD_PARAM_BYTE01(0x23);
	pus_hk_setONBOARD_PARAM_BOOL01(true);
}

void onboardparams_PI_setOnBoardParam(const asn1SccPusSt20OnBoardParameterId *IN_paramId,
                                      const asn1SccPusSt20StoredParam *IN_paramValue)
{
    /* Write your code here! */
	pus_parameters_setStoredParam(*IN_paramId, *IN_paramValue);
}

void onboardparams_PI_getOnBoardParam(const asn1SccPusSt20OnBoardParameterId *IN_paramId,
                                      asn1SccPusSt20StoredParam *OUT_paramValue,
                                      asn1SccPusSt01FailureCode *OUT_isAvailable)
{
    /* Write your code here! */
	*OUT_isAvailable = pus_parameters_getStoredParam(*IN_paramId, OUT_paramValue);
}

