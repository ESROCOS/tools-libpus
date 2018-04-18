/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_events
#define VM_IF_events

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_events();

void events_getNextEvent (void *pmy_actualCounter, size_t size_my_actualCounter, void *pmy_eventInfo, size_t *psize_my_eventInfo, void *pmy_nextCounter, size_t *psize_my_nextCounter);
extern void events_PI_getNextEvent (const asn1SccPusUInt64 *, asn1SccPusSt05Event *, asn1SccPusUInt64 *);
void events_pushNewEvent (void *pmy_eventInfo, size_t size_my_eventInfo);
extern void events_PI_pushNewEvent (const asn1SccPusSt05Event *);
void events_debugEventsTrigger ();
extern void events_PI_debugEventsTrigger ();
#ifdef __cplusplus
}
#endif

#endif
