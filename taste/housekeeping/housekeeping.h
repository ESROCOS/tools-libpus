/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_housekeeping__
#define __USER_CODE_H_housekeeping__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void housekeeping_startup();

void housekeeping_PI_getParamValue(const asn1SccPusSt03ParameterId *,
                                   asn1SccPusSt03StoredParam *,
                                   asn1SccPusSt01FailureCode *);

void housekeeping_PI_setParamValue(const asn1SccPusSt03ParameterId *,
                                   const asn1SccPusSt03StoredParam *);

#ifdef __cplusplus
}
#endif


#endif
