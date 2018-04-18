#include "po_hi_gqueue.h"
/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "vt_st19_eventactiontrigger_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_task.h"
/* ------------------------------------------------------
-- Asynchronous Provided Interface "artificial_EventActionTrigger"
------------------------------------------------------ */
void po_hi_c_vt_st19_eventactiontrigger_artificial_eventactiontrigger(__po_hi_task_id e)
{
   sync_st19_EventActionTrigger ();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "EventActionTrigger"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_EventActionTrigger()
{
   sync_st19_EventActionTrigger();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "incCount_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_incCount_vt(void *tmPacket, size_t *tmPacket_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_st09_incCount(tmPacket, tmPacket_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "newTm_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_newTm_vt(void *tmPacket, size_t tmPacket_len)
{
   sync_tmqueue_newTm(tmPacket, tmPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_getSequenceCount_vt(void *sequenceCount, size_t *sequenceCount_len)
{
   sync_onboardapid_getSequenceCount(sequenceCount, sequenceCount_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getApid_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_getApid_vt(void *apid, size_t *apid_len)
{
   sync_onboardapid_getApid(apid, apid_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_ACK_vt(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_check_queue_vt(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_events_has_pending_msg(res, res_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getNextEvent_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_getNextEvent_vt(void *actualCounter, size_t actualCounter_len, void *eventInfo, size_t *eventInfo_len, void *nextCounter, size_t *nextCounter_len)
{
   sync_events_getNextEvent(actualCounter, actualCounter_len, eventInfo, eventInfo_len, nextCounter, nextCounter_len);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc_vt"
------------------------------------------------------ */
void vm_async_vt_st19_eventactiontrigger_newTc_vt(void *tcPacket, size_t tcPacket_len)
{
   __po_hi_request_t request;

   __po_hi_copy_array(&(request.vars.vt_st19_eventactiontrigger_global_outport_newtc_vt.vt_st19_eventactiontrigger_global_outport_newtc_vt.buffer), tcPacket, tcPacket_len);
   request.vars.vt_st19_eventactiontrigger_global_outport_newtc_vt.vt_st19_eventactiontrigger_global_outport_newtc_vt.length = tcPacket_len;
   request.port = vt_st19_eventactiontrigger_global_outport_newtc_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_st19_eventactiontrigger_k, vt_st19_eventactiontrigger_local_outport_newtc_vt, &request);
   __po_hi_send_output(x86_partition_vt_st19_eventactiontrigger_k, vt_st19_eventactiontrigger_global_outport_newtc_vt);
}

