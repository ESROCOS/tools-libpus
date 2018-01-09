/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st18__
#define __USER_CODE_H_st18__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st18_startup();

void st18_PI_tc18(const asn1SccPusPacket *);

extern void st18_RI_ACK(const asn1SccPusPacket *,
                        const asn1SccPusSubserviceType *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *,
                        const asn1SccPusStepId *);

#ifdef __cplusplus
}
#endif


#endif
