/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st19__
#define __USER_CODE_H_st19__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st19_startup();

void st19_PI_tc19(const asn1SccPusPacket *);

void st19_PI_trigger();

extern void st19_RI_getNextEvent(const asn1SccPusUInt64 *,
                                 asn1SccPusSt05Event *,
                                 asn1SccPusUInt64 *);

extern void st19_RI_ACK(const asn1SccPusPacket *,
                        const asn1SccPusSubserviceType *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *,
                        const asn1SccPusStepId *);

extern void st19_RI_newTm(const asn1SccPusPacket *);

extern void st19_RI_newTc(const asn1SccPusPacket *);

#ifdef __cplusplus
}
#endif


#endif
