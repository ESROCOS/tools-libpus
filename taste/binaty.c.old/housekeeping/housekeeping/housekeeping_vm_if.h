/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_housekeeping
#define VM_IF_housekeeping

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_housekeeping();

void housekeeping_setParamValue (void *pmy_paramId, size_t size_my_paramId, void *pmy_paramValue, size_t size_my_paramValue);
extern void housekeeping_PI_setParamValue (const asn1SccPusSt03ParameterId *, const asn1SccPusSt03StoredParam *);
void housekeeping_getParamValue (void *pmy_paramId, size_t size_my_paramId, void *pmy_paramValue, size_t *psize_my_paramValue, void *pmy_isAvailable, size_t *psize_my_isAvailable);
extern void housekeeping_PI_getParamValue (const asn1SccPusSt03ParameterId *, asn1SccPusSt03StoredParam *, asn1SccPusSt01FailureCode *);
#ifdef __cplusplus
}
#endif

#endif
