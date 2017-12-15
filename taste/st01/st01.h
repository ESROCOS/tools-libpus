/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st01__
#define __USER_CODE_H_st01__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st01_startup();

void st01_PI_ACK(const asn1SccPusPacket *,
                 const asn1SccPusSubserviceType *,
                 const asn1SccPusSt01FailureCode *,
                 const asn1SccPusSt01FailureInfo *,
                 const asn1SccPusStepId *);

extern void st01_RI_newTm(const asn1SccPusPacket *);

extern void st01_RI_getSequenceCount(asn1SccPusSequenceCount *);

extern void st01_RI_getApid(asn1SccPusApid *);

#ifdef __cplusplus
}
#endif


#endif
