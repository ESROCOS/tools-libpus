/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_tcqueue__
#define __USER_CODE_H_tcqueue__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void tcqueue_startup();

void tcqueue_PI_newTc(const asn1SccPusPacket *);

void tcqueue_PI_tcRequest(asn1SccPusPacket *,
                          asn1SccPusSt01FailureCode *);

#ifdef __cplusplus
}
#endif


#endif
