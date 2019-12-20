/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_tmdispatch__
#define __USER_CODE_H_tmdispatch__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void tmdispatch_startup();

void tmdispatch_PI_tmTrigger();

extern void tmdispatch_RI_newTm(const asn1SccPusPacket *);

extern void tmdispatch_RI_tmRequest(asn1SccPusPacket *,
                                    asn1SccPusSt01FailureCode *);

#ifdef __cplusplus
}
#endif


#endif
