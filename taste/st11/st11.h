/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st11__
#define __USER_CODE_H_st11__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st11_startup();

void st11_PI_tc11(const asn1SccPusPacket *);

void st11_PI_schedulingTrigger();

extern void st11_RI_ACK(const asn1SccPusPacket *,
                        const asn1SccPusSubserviceType *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *,
                        const asn1SccPusStepId *);

extern void st11_RI_newTc(const asn1SccPusPacket *);

#ifdef __cplusplus
}
#endif


#endif
