/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_onboardsw__
#define __USER_CODE_H_onboardsw__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void onboardsw_startup();

void onboardsw_PI_trigger();

extern void onboardsw_RI_pushNewEvent(const asn1SccPusSt05Event *);

extern void onboardsw_RI_setParamValue(const asn1SccPusSt03ParameterId *,
                                       const asn1SccPusSt03StoredParam *);

extern void onboardsw_RI_getParamValue(const asn1SccPusSt03ParameterId *,
                                       asn1SccPusSt03StoredParam *,
                                       asn1SccPusSt01FailureCode *);

extern void onboardsw_RI_setOnBoardParam(const asn1SccPusSt20OnBoardParameterId *,
                                         const asn1SccPusSt20StoredParam *);

extern void onboardsw_RI_getOnBoardParam(const asn1SccPusSt20OnBoardParameterId *,
                                         asn1SccPusSt20StoredParam *,
                                         asn1SccPusSt01FailureCode *);

#ifdef __cplusplus
}
#endif


#endif
