/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_onboardparams__
#define __USER_CODE_H_onboardparams__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void onboardparams_startup();

void onboardparams_PI_setOnBoardParam(const asn1SccPusSt20OnBoardParameterId *,
                                      const asn1SccPusSt20StoredParam *);

void onboardparams_PI_getOnBoardParam(const asn1SccPusSt20OnBoardParameterId *,
                                      asn1SccPusSt20StoredParam *,
                                      asn1SccPusSt01FailureCode *);

#ifdef __cplusplus
}
#endif


#endif
