/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef events_POLYORB_INTERFACE
#define events_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
#include "../../vt_st19_eventactiontrigger/vt_st19_eventactiontrigger_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "getNextEvent"
----------------------------------------------------*/
void sync_events_getNextEvent(void *, size_t, void *, size_t *, void *, size_t *);

/*----------------------------------------------------
-- Protected Provided Interface "pushNewEvent"
----------------------------------------------------*/
void sync_events_pushNewEvent(void *, size_t);

/*----------------------------------------------------
-- Protected Provided Interface "debugEventsTrigger"
----------------------------------------------------*/
void sync_events_debugEventsTrigger();

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_events_check_queue(void *, size_t *);
#endif
