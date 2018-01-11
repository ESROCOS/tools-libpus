/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_debug__
#define __USER_CODE_H_debug__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void debug_startup();

void debug_PI_a();

extern void debug_RI_setParamValue(const asn1SccPusSt03StoredParam *,
                                   const asn1SccPusSt03ParameterId *);

extern void debug_RI_getParamValue(const asn1SccPusSt03ParameterId *,
                                   asn1SccPusSt03StoredParam *,
                                   asn1SccPusSt01FailureCode *);

extern void debug_RI_pushNewEvent(const asn1SccPusSt05Event *);

#ifdef __cplusplus
}
#endif


#endif
