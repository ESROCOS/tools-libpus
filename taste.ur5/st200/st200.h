/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st200__
#define __USER_CODE_H_st200__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st200_startup();

void st200_PI_tc200(const asn1SccPusPacket *);

void st200_PI_report(const asn1SccPusSt200Observation *);

extern void st200_RI_ACK(const asn1SccPusPacket *,
                         const asn1SccPusSubserviceType *,
                         const asn1SccPusSt01FailureCode *,
                         const asn1SccPusSt01FailureInfo *,
                         const asn1SccPusStepId *);

extern void st200_RI_newTm(const asn1SccPusPacket *);

extern void st200_RI_getSequenceCount(asn1SccPusSequenceCount *);

extern void st200_RI_getApid(asn1SccPusApid *);

extern void st200_RI_operationRequest(const asn1SccPusSt200ControlId *);

#ifdef __cplusplus
}
#endif


#endif
