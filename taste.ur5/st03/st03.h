/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st03__
#define __USER_CODE_H_st03__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st03_startup();

void st03_PI_HkReportTrigger();

extern void st03_RI_newTm(const asn1SccPusPacket *);

extern void st03_RI_getParamValue(const asn1SccPusSt03ParameterId *,
                                  asn1SccPusSt03StoredParam *,
                                  asn1SccPusSt01FailureCode *);

extern void st03_RI_getApid(asn1SccPusApid *);

extern void st03_RI_getSequenceCount(asn1SccPusSequenceCount *);

#ifdef __cplusplus
}
#endif


#endif
