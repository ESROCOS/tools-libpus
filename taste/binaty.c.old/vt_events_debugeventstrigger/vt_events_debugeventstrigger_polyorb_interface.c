/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "vt_events_debugeventstrigger_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_task.h"
/* ------------------------------------------------------
-- Asynchronous Provided Interface "artificial_debugEventsTrigger"
------------------------------------------------------ */
void po_hi_c_vt_events_debugeventstrigger_artificial_debugeventstrigger(__po_hi_task_id e)
{
   sync_events_debugEventsTrigger ();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "debugEventsTrigger"
------------------------------------------------------ */
void vm_vt_events_debugeventstrigger_debugEventsTrigger()
{
   sync_events_debugEventsTrigger();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_events_debugeventstrigger_check_queue_vt(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_events_has_pending_msg(res, res_len);
}

