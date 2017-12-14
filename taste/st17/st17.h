/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st17__
#define __USER_CODE_H_st17__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st17_startup();

void st17_PI_tc17(const asn1SccPusPacket *);

extern void st17_RI_newTm(const asn1SccPusPacket *);

extern void st17_RI_ACK(const asn1SccPusPacket *,
                        const asn1SccPusApid *,
                        const asn1SccPusSequenceCount *,
                        const asn1SccT_Boolean *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *);

#ifdef __cplusplus
}
#endif


#endif
