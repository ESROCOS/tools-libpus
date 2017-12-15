/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_groundtm__
#define __USER_CODE_H_groundtm__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void groundtm_startup();

void groundtm_PI_newTm(const asn1SccPusPacket *);

extern void groundtm_RI_getApid(asn1SccPusApid *);

extern void groundtm_RI_getSequenceCounter(asn1SccPusSequenceCount *);

#ifdef __cplusplus
}
#endif


#endif
