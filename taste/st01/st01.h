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
                 const asn1SccPusApid *,
                 const asn1SccPusSequenceCount *,
                 const asn1SccT_Boolean *,
                 const asn1SccPusSt01FailureCode *,
                 const asn1SccPusSt01FailureInfo *);

extern void st01_RI_newTm(const asn1SccPusPacket *);

#ifdef __cplusplus
}
#endif


#endif
