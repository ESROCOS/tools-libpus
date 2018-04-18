/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "st12_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "st12_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "PmonTrigger"
----------------------------------------------------*/
void sync_st12_PmonTrigger()
{
   extern process_package__taste_protected_object st12_protected;
   __po_hi_protected_lock (st12_protected.protected_id);
   st12_PmonTrigger();
   __po_hi_protected_unlock (st12_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "tc12"
----------------------------------------------------*/
void sync_st12_tc12(void *tcPacket, size_t tcPacket_len)
{
   extern process_package__taste_protected_object st12_protected;
   __po_hi_protected_lock (st12_protected.protected_id);
   st12_tc12(tcPacket, tcPacket_len);
   __po_hi_protected_unlock (st12_protected.protected_id);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "pushNewEvent"
------------------------------------------------------ */
void vm_st12_pushNewEvent(void *eventInfo, size_t eventInfo_len)
{
   sync_events_pushNewEvent(eventInfo, eventInfo_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getParamValue"
------------------------------------------------------ */
void vm_st12_getParamValue(void *paramId, size_t paramId_len, void *paramValue, size_t *paramValue_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_housekeeping_getParamValue(paramId, paramId_len, paramValue, paramValue_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st12_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_st12_check_queue(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_st12_has_pending_msg(res, res_len);
}

