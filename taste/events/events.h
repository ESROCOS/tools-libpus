/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_events__
#define __USER_CODE_H_events__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void events_startup();

void events_PI_getNextEvent(const asn1SccPusUInt64 *,
                            asn1SccPusSt05Event *,
                            asn1SccPusUInt64 *);

void events_PI_pushNewEvent(const asn1SccPusSt05Event *);

void events_PI_debugTrigger();

#ifdef __cplusplus
}
#endif


#endif
