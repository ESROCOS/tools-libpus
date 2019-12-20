/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_tmqueue__
#define __USER_CODE_H_tmqueue__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void tmqueue_startup();

void tmqueue_PI_tmRequest(asn1SccPusPacket *,
                          asn1SccPusSt01FailureCode *);

void tmqueue_PI_newTm(const asn1SccPusPacket *);

extern void tmqueue_RI_incCount(asn1SccPusPacket *,
                                asn1SccPusSt01FailureCode *);

#ifdef __cplusplus
}
#endif


#endif
