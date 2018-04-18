/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_onboardapid
#define VM_IF_onboardapid

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_onboardapid();

void onboardapid_getApid (void *pmy_apid, size_t *psize_my_apid);
extern void onboardapid_PI_getApid (asn1SccPusApid *);
void onboardapid_getSequenceCount (void *pmy_sequenceCount, size_t *psize_my_sequenceCount);
extern void onboardapid_PI_getSequenceCount (asn1SccPusSequenceCount *);
#ifdef __cplusplus
}
#endif

#endif
