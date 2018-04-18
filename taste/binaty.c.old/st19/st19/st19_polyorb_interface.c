#include "po_hi_gqueue.h"
/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "st19_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "st19_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "tc19"
----------------------------------------------------*/
void sync_st19_tc19(void *tcPacket, size_t tcPacket_len)
{
   extern process_package__taste_protected_object st19_protected;
   __po_hi_protected_lock (st19_protected.protected_id);
   st19_tc19(tcPacket, tcPacket_len);
   __po_hi_protected_unlock (st19_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "EventActionTrigger"
----------------------------------------------------*/
void sync_st19_EventActionTrigger()
{
   extern process_package__taste_protected_object st19_protected;
   __po_hi_protected_lock (st19_protected.protected_id);
   st19_EventActionTrigger();
   __po_hi_protected_unlock (st19_protected.protected_id);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getNextEvent"
------------------------------------------------------ */
void vm_st19_getNextEvent(void *actualCounter, size_t actualCounter_len, void *eventInfo, size_t *eventInfo_len, void *nextCounter, size_t *nextCounter_len)
{
   sync_events_getNextEvent(actualCounter, actualCounter_len, eventInfo, eventInfo_len, nextCounter, nextCounter_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st19_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_st19_newTm(void *tmPacket, size_t tmPacket_len)
{
   sync_tmqueue_newTm(tmPacket, tmPacket_len);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc"
------------------------------------------------------ */
void vm_async_st19_newTc(void *tcPacket, size_t tcPacket_len)
{
   switch(__po_hi_get_task_id()) {
      case x86_partition_tcdispatch_k: vm_async_tcdispatch_newTc_vt(tcPacket, tcPacket_len); break;
      case x86_partition_vt_st19_eventactiontrigger_k: vm_async_vt_st19_eventactiontrigger_newTc_vt(tcPacket, tcPacket_len); break;
      default: break;
   }
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_st19_check_queue(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_st19_has_pending_msg(res, res_len);
}

