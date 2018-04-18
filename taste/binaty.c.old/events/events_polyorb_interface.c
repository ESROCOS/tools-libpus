/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "events_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "events_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "getNextEvent"
----------------------------------------------------*/
void sync_events_getNextEvent(void *actualCounter, size_t actualCounter_len, void *eventInfo, size_t *eventInfo_len, void *nextCounter, size_t *nextCounter_len)
{
   extern process_package__taste_protected_object events_protected;
   __po_hi_protected_lock (events_protected.protected_id);
   events_getNextEvent(actualCounter, actualCounter_len, eventInfo, eventInfo_len, nextCounter, nextCounter_len);
   __po_hi_protected_unlock (events_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "pushNewEvent"
----------------------------------------------------*/
void sync_events_pushNewEvent(void *eventInfo, size_t eventInfo_len)
{
   extern process_package__taste_protected_object events_protected;
   __po_hi_protected_lock (events_protected.protected_id);
   events_pushNewEvent(eventInfo, eventInfo_len);
   __po_hi_protected_unlock (events_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "debugEventsTrigger"
----------------------------------------------------*/
void sync_events_debugEventsTrigger()
{
   extern process_package__taste_protected_object events_protected;
   __po_hi_protected_lock (events_protected.protected_id);
   events_debugEventsTrigger();
   __po_hi_protected_unlock (events_protected.protected_id);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_events_check_queue(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_events_has_pending_msg(res, res_len);
}

