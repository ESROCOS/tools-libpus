/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_ground
#define VM_IF_ground

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_ground();

void ground_newTm (void *pmy_tmPacket, size_t size_my_tmPacket);
extern void ground_PI_newTm (const asn1SccPusPacket *);
void ground_triggerTmGUI ();
extern void ground_PI_triggerTmGUI ();
#ifdef __cplusplus
}
#endif

#endif
