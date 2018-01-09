/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st23__
#define __USER_CODE_H_st23__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st23_startup();

void st23_PI_tc23();

extern void st23_RI_copy();

extern void st23_RI_delete();

extern void st23_RI_create();

extern void st23_RI_getAttributes();

extern void st23_RI_newTm(const asn1SccPusPacket *);

extern void st23_RI_getApid(asn1SccPusApid *);

extern void st23_RI_getSequenceCount(asn1SccPusSequenceCount *);

#ifdef __cplusplus
}
#endif


#endif
