/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_timereportapid
#define VM_IF_timereportapid

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_timereportapid();

void timereportapid_getApid (void *pmy_apid, size_t *psize_my_apid);
extern void timereportapid_PI_getApid (asn1SccPusApid *);
void timereportapid_getSequenceCount (void *pmy_sequenceCount, size_t *psize_my_sequenceCount);
extern void timereportapid_PI_getSequenceCount (asn1SccPusSequenceCount *);
#ifdef __cplusplus
}
#endif

#endif
