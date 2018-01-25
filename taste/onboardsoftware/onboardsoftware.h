/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_onboardsoftware__
#define __USER_CODE_H_onboardsoftware__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void onboardsoftware_startup();

void onboardsoftware_PI_debugTrigger();

extern void onboardsoftware_RI_setParamValue(const asn1SccPusSt03StoredParam *,
                                             const asn1SccPusSt03ParameterId *);

extern void onboardsoftware_RI_getParamValue(const asn1SccPusSt03ParameterId *,
                                             asn1SccPusSt03StoredParam *,
                                             asn1SccPusSt01FailureCode *);

extern void onboardsoftware_RI_pushNewEvent(const asn1SccPusSt05Event *);

extern void onboardsoftware_RI_setOnBoardParam();

extern void onboardsoftware_RI_getOnBoardParam();

#ifdef __cplusplus
}
#endif


#endif