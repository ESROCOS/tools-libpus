#include "po_hi_gqueue.h"
/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "tmdispatch_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_task.h"
#include "tmdispatch_vm_if.h"

/* ------------------------------------------------------
-- Asynchronous Provided Interface "tmTrigger"
------------------------------------------------------ */
void po_hi_c_tmdispatch_tmtrigger(__po_hi_task_id e)
{
   tmdispatch_tmTrigger();
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_async_tmdispatch_newTm(void *tmPacket, size_t tmPacket_len)
{
   __po_hi_request_t request;

   __po_hi_copy_array(&(request.vars.tmdispatch_global_outport_newtm.tmdispatch_global_outport_newtm.buffer), tmPacket, tmPacket_len);
   request.vars.tmdispatch_global_outport_newtm.tmdispatch_global_outport_newtm.length = tmPacket_len;
   request.port = tmdispatch_global_outport_newtm;
   __po_hi_gqueue_store_out(x86_partition_tmdispatch_k, tmdispatch_local_outport_newtm, &request);
   __po_hi_send_output(x86_partition_tmdispatch_k, tmdispatch_global_outport_newtm);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "tmRequest"
------------------------------------------------------ */
void vm_tmdispatch_tmRequest(void *tmPacket, size_t *tmPacket_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_tmqueue_tmRequest(tmPacket, tmPacket_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_tmdispatch_check_queue(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_tmdispatch_has_pending_msg(res, res_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "incCount_vt"
------------------------------------------------------ */
void vm_tmdispatch_incCount_vt(void *tmPacket, size_t *tmPacket_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_st09_incCount(tmPacket, tmPacket_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "newTm_vt"
------------------------------------------------------ */
void vm_tmdispatch_newTm_vt(void *tmPacket, size_t tmPacket_len)
{
   sync_tmqueue_newTm(tmPacket, tmPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount_vt"
------------------------------------------------------ */
void vm_tmdispatch_getSequenceCount_vt(void *sequenceCount, size_t *sequenceCount_len)
{
   sync_onboardapid_getSequenceCount(sequenceCount, sequenceCount_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getApid_vt"
------------------------------------------------------ */
void vm_tmdispatch_getApid_vt(void *apid, size_t *apid_len)
{
   sync_onboardapid_getApid(apid, apid_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK_vt"
------------------------------------------------------ */
void vm_tmdispatch_ACK_vt(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

