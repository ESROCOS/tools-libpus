/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st05__
#define __USER_CODE_H_st05__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st05_startup();

void st05_PI_EventReportTrigger();

extern void st05_RI_newTmNoInherit(const asn1SccPusPacket *);

extern void st05_RI_getNextEvent(const asn1SccPusUInt64 *,
                                 asn1SccPusSt05Event *,
                                 asn1SccPusUInt64 *);

extern void st05_RI_getApid(asn1SccPusApid *);

extern void st05_RI_getSequenceCount(asn1SccPusSequenceCount *);

#ifdef __cplusplus
}
#endif


#endif
