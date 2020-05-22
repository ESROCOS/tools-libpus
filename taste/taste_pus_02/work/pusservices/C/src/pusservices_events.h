/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#ifndef PUSSERVICES_EVENTS
#define PUSSERVICES_EVENTS

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

//void events_startup();

void pusservices_events_getNextEvent(const asn1SccPusUInt64 *,
                            asn1SccPusSt05Event *,
                            asn1SccPusUInt64 *);

void pusservices_events_pushNewEvent(const asn1SccPusSt05Event *);

#ifdef __cplusplus
}
#endif


#endif
