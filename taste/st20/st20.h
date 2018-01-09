/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st20__
#define __USER_CODE_H_st20__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st20_startup();

void st20_PI_tc20(const asn1SccPusPacket *);

extern void st20_RI_setParam();

extern void st20_RI_getParam();

extern void st20_RI_newTm(const asn1SccPusPacket *);

extern void st20_RI_ACK(const asn1SccPusPacket *,
                        const asn1SccPusSubserviceType *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *,
                        const asn1SccPusStepId *);

extern void st20_RI_getApid(asn1SccPusApid *);

extern void st20_RI_getSequenceCount(asn1SccPusSequenceCount *);

#ifdef __cplusplus
}
#endif


#endif
