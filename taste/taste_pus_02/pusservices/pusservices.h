/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_pusservices__
#define __USER_CODE_H_pusservices__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void pusservices_startup();

void pusservices_PI_newTc(const asn1SccPusPacket *);

void pusservices_PI_trigger();

void pusservices_PI_ack(const asn1SccPusPacket *,
                        const asn1SccPusSubserviceType *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *,
                        const asn1SccPusStepId *);

void pusservices_PI_addTm(const asn1SccPusPacket *);

void pusservices_PI_addTc(const asn1SccPusPacket *);

void pusservices_PI_pushNewEvent(const asn1SccPusSt05Event *);

void pusservices_PI_setParamValue(const asn1SccPusSt03ParameterId *,
                                  const asn1SccPusSt03StoredParam *);

void pusservices_PI_getParamValue(const asn1SccPusSt03ParameterId *,
                                  asn1SccPusSt03StoredParam *,
                                  asn1SccPusSt01FailureCode *);

void pusservices_PI_setOnBoardParam(const asn1SccPusSt20OnBoardParameterId *,
                                    const asn1SccPusSt20StoredParam *);

void pusservices_PI_getOnBoardParam(const asn1SccPusSt20OnBoardParameterId *,
                                    asn1SccPusSt20StoredParam *,
                                    asn1SccPusSt01FailureCode *);

extern void pusservices_RI_newTm(const asn1SccPusPacket *);

extern void pusservices_RI_ack(const asn1SccPusPacket *,
                               const asn1SccPusSubserviceType *,
                               const asn1SccPusSt01FailureCode *,
                               const asn1SccPusSt01FailureInfo *,
                               const asn1SccPusStepId *);

extern void pusservices_RI_addTm(const asn1SccPusPacket *);

extern void pusservices_RI_addTc(const asn1SccPusPacket *);

#ifdef __cplusplus
}
#endif


#endif
