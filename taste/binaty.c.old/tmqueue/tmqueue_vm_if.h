/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_tmqueue
#define VM_IF_tmqueue

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_tmqueue();

void tmqueue_tmRequest (void *pmy_tmPacket, size_t *psize_my_tmPacket, void *pmy_isAvailable, size_t *psize_my_isAvailable);
extern void tmqueue_PI_tmRequest (asn1SccPusPacket *, asn1SccT_Boolean *);
void tmqueue_newTm (void *pmy_tmPacket, size_t size_my_tmPacket);
extern void tmqueue_PI_newTm (const asn1SccPusPacket *);
#ifdef __cplusplus
}
#endif

#endif
