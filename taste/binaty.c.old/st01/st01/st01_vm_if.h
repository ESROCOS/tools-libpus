/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_st01
#define VM_IF_st01

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_st01();

void st01_ACK (void *pmy_tcPacket, size_t size_my_tcPacket, void *pmy_reportType, size_t size_my_reportType, void *pmy_error, size_t size_my_error, void *pmy_errorInfo, size_t size_my_errorInfo, void *pmy_step, size_t size_my_step);
extern void st01_PI_ACK (const asn1SccPusPacket *, const asn1SccPusSubserviceType *, const asn1SccPusSt01FailureCode *, const asn1SccPusSt01FailureInfo *, const asn1SccPusStepId *);
#ifdef __cplusplus
}
#endif

#endif
