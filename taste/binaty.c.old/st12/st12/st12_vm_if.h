/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_st12
#define VM_IF_st12

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_st12();

void st12_PmonTrigger ();
extern void st12_PI_PmonTrigger ();
void st12_tc12 (void *pmy_tcPacket, size_t size_my_tcPacket);
extern void st12_PI_tc12 (const asn1SccPusPacket *);
#ifdef __cplusplus
}
#endif

#endif
