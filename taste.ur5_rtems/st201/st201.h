/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st201__
#define __USER_CODE_H_st201__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st201_startup();

void st201_PI_tc201(const asn1SccPusPacket *);

void st201_PI_report(const asn1SccPusSt201PlanObservation *);

extern void st201_RI_getSequenceCount(asn1SccPusSequenceCount *);

extern void st201_RI_getApid(asn1SccPusApid *);

extern void st201_RI_ACK(const asn1SccPusPacket *,
                         const asn1SccPusSubserviceType *,
                         const asn1SccPusSt01FailureCode *,
                         const asn1SccPusSt01FailureInfo *,
                         const asn1SccPusStepId *);

extern void st201_RI_newTm(const asn1SccPusPacket *);

extern void st201_RI_setHome(const asn1SccPusTC_201_1_3_Data *);

extern void st201_RI_planHomeRequest();

extern void st201_RI_planMoveRequest(const asn1SccPusTC_201_1_3_Data *);

#ifdef __cplusplus
}
#endif


#endif
