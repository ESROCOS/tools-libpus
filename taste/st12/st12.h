/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st12__
#define __USER_CODE_H_st12__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st12_startup();

void st12_PI_tc12(const asn1SccPusPacket *);

void st12_PI_trigger();

extern void st12_RI_ACK(const asn1SccPusPacket *,
                        const asn1SccPusSubserviceType *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *,
                        const asn1SccPusStepId *);

extern void st12_RI_getParamValue(const asn1SccPusSt03ParameterId *,
                                  asn1SccPusSt03StoredParam *,
                                  asn1SccPusSt01FailureCode *);

extern void st12_RI_pushNewEvent(const asn1SccPusSt05Event *);

#ifdef __cplusplus
}
#endif


#endif
