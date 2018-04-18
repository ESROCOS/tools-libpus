/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_st19
#define VM_IF_st19

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_st19();

void st19_tc19 (void *pmy_tcPacket, size_t size_my_tcPacket);
extern void st19_PI_tc19 (const asn1SccPusPacket *);
void st19_EventActionTrigger ();
extern void st19_PI_EventActionTrigger ();
#ifdef __cplusplus
}
#endif

#endif
