/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_groundtc__
#define __USER_CODE_H_groundtc__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void groundtc_startup();

void groundtc_PI_GroundTcTrigger();

extern void groundtc_RI_newTc(const asn1SccPusPacket *);

extern void groundtc_RI_getApid(asn1SccPusApid *);

extern void groundtc_RI_getSequenceCounter(asn1SccPusSequenceCount *);

#ifdef __cplusplus
}
#endif


#endif
