/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

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

	pus_parameters_setSET_HK_OUT_OF_RANGE_PARAM(false);
	pus_parameters_setSET_THROW_EVENTS_PARAM(false);
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

