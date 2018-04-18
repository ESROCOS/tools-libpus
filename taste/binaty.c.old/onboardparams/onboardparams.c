/* User code: This file will not be overwritten by TASTE. */

#include "onboardparams.h"

void onboardparams_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void onboardparams_PI_setOnBoardParam(const asn1SccPusSt20OnBoardParameterId *IN_paramId,
                                      const asn1SccPusSt20StoredParam *IN_paramValue)
{
    /* Write your code here! */
}

void onboardparams_PI_getOnBoardParam(const asn1SccPusSt20OnBoardParameterId *IN_paramId,
                                      asn1SccPusSt20StoredParam *OUT_paramValue,
                                      asn1SccPusSt01FailureCode *OUT_isAvailable)
{
    /* Write your code here! */
}

