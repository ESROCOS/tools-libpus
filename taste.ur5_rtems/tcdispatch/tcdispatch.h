/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_tcdispatch__
#define __USER_CODE_H_tcdispatch__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void tcdispatch_startup();

void tcdispatch_PI_tcTrigger();

extern void tcdispatch_RI_tcRequest(asn1SccPusPacket *,
                                    asn1SccPusSt01FailureCode *);

extern void tcdispatch_RI_tc17(const asn1SccPusPacket *);

extern void tcdispatch_RI_tc08(const asn1SccPusPacket *);

extern void tcdispatch_RI_tc19(const asn1SccPusPacket *);

extern void tcdispatch_RI_tc09(const asn1SccPusPacket *);

extern void tcdispatch_RI_tc12(const asn1SccPusPacket *);

extern void tcdispatch_RI_tc11(const asn1SccPusPacket *);

extern void tcdispatch_RI_tc18(const asn1SccPusPacket *);

extern void tcdispatch_RI_tc23(const asn1SccPusPacket *);

extern void tcdispatch_RI_tc20(const asn1SccPusPacket *);

extern void tcdispatch_RI_tc201(const asn1SccPusPacket *);

#ifdef __cplusplus
}
#endif


#endif
