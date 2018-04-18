/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_tcqueue
#define VM_IF_tcqueue

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_tcqueue();

void tcqueue_newTc (void *pmy_tcPacket, size_t size_my_tcPacket);
extern void tcqueue_PI_newTc (const asn1SccPusPacket *);
void tcqueue_tcRequest (void *pmy_tcPacket, size_t *psize_my_tcPacket, void *pmy_isAvailable, size_t *psize_my_isAvailable);
extern void tcqueue_PI_tcRequest (asn1SccPusPacket *, asn1SccT_Boolean *);
#ifdef __cplusplus
}
#endif

#endif
