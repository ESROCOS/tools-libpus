/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef vt_events_debugeventstrigger_POLYORB_INTERFACE
#define vt_events_debugeventstrigger_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../events/events_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
/*----------------------------------------------------
-- Asynchronous Provided Interface "artificial_debugEventsTrigger"
----------------------------------------------------*/
void po_hi_c_vt_events_debugeventstrigger_artificial_debugeventstrigger(__po_hi_task_id);

/* ------------------------------------------------------
--  Synchronous Required Interface "debugEventsTrigger"
------------------------------------------------------ */
void vm_vt_events_debugeventstrigger_debugEventsTrigger();
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_events_debugeventstrigger_check_queue_vt(void *, size_t *);
#endif
