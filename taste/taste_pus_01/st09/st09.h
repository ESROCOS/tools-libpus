/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st09__
#define __USER_CODE_H_st09__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st09_startup();

void st09_PI_incCount(asn1SccPusPacket *,
                      asn1SccPusSt01FailureCode *);

void st09_PI_tc09(const asn1SccPusPacket *);

extern void st09_RI_getApid(asn1SccPusApid *);

extern void st09_RI_getSequenceCount(asn1SccPusSequenceCount *);

extern void st09_RI_ACK(const asn1SccPusPacket *,
                        const asn1SccPusSubserviceType *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *,
                        const asn1SccPusStepId *);

#ifdef __cplusplus
}
#endif


#endif
