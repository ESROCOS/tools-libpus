/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_st09
#define VM_IF_st09

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_st09();

void st09_incCount (void *pmy_tmPacket, size_t *psize_my_tmPacket, void *pmy_isAvailable, size_t *psize_my_isAvailable);
extern void st09_PI_incCount (asn1SccPusPacket *, asn1SccPusSt01FailureCode *);
void st09_tc09 (void *pmy_tcPacket, size_t size_my_tcPacket);
extern void st09_PI_tc09 (const asn1SccPusPacket *);
#ifdef __cplusplus
}
#endif

#endif
