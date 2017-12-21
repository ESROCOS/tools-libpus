/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st09__
#define __USER_CODE_H_st09__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st09_startup();

void st09_PI_incCount(asn1SccPusPacket *,
                      asn1SccPusSt01FailureCode *);

void st09_PI_tc09(const asn1SccPusPacket *);

#ifdef __cplusplus
}
#endif


#endif
