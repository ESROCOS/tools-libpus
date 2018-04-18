#include "po_hi_gqueue.h"
/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "vt_ground_newtm_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_task.h"
/* ------------------------------------------------------
-- Asynchronous Provided Interface "artificial_newTm"
------------------------------------------------------ */
void po_hi_c_vt_ground_newtm_artificial_newtm(__po_hi_task_id e, dataview__puspacket_buffer_impl buf)
{
   sync_ground_newTm (buf.buffer, buf.length);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_vt_ground_newtm_newTm(void *tmPacket, size_t tmPacket_len)
{
   sync_ground_newTm(tmPacket, tmPacket_len);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc_vt"
------------------------------------------------------ */
void vm_async_vt_ground_newtm_newTc_vt(void *tcPacket, size_t tcPacket_len)
{
   __po_hi_request_t request;

   __po_hi_copy_array(&(request.vars.vt_ground_newtm_global_outport_newtc_vt.vt_ground_newtm_global_outport_newtc_vt.buffer), tcPacket, tcPacket_len);
   request.vars.vt_ground_newtm_global_outport_newtc_vt.vt_ground_newtm_global_outport_newtc_vt.length = tcPacket_len;
   request.port = vt_ground_newtm_global_outport_newtc_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_ground_newtm_k, vt_ground_newtm_local_outport_newtc_vt, &request);
   __po_hi_send_output(x86_partition_vt_ground_newtm_k, vt_ground_newtm_global_outport_newtc_vt);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_ground_newtm_check_queue_vt(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_ground_has_pending_msg(res, res_len);
}

