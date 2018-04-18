/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_obcpengine
#define VM_IF_obcpengine

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_obcpengine();

void obcpengine_loadDirect (void *pmy_obcpId, size_t size_my_obcpId, void *pmy_obcpCode, size_t size_my_obcpCode);
extern void obcpengine_PI_loadDirect (const asn1SccPusSt18ObcpId *, const asn1SccPusSt18ObcpCode *);
void obcpengine_loadReference (void *pmy_referenceData, size_t size_my_referenceData);
extern void obcpengine_PI_loadReference (const asn1SccPusTC_18_13_Data *);
#ifdef __cplusplus
}
#endif

#endif
