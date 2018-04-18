/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_onboardparams
#define VM_IF_onboardparams

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_onboardparams();

void onboardparams_setOnBoardParam (void *pmy_paramId, size_t size_my_paramId, void *pmy_paramValue, size_t size_my_paramValue);
extern void onboardparams_PI_setOnBoardParam (const asn1SccPusSt20OnBoardParameterId *, const asn1SccPusSt20StoredParam *);
void onboardparams_getOnBoardParam (void *pmy_paramId, size_t size_my_paramId, void *pmy_paramValue, size_t *psize_my_paramValue, void *pmy_isAvailable, size_t *psize_my_isAvailable);
extern void onboardparams_PI_getOnBoardParam (const asn1SccPusSt20OnBoardParameterId *, asn1SccPusSt20StoredParam *, asn1SccPusSt01FailureCode *);
#ifdef __cplusplus
}
#endif

#endif
