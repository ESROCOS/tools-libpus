#include "po_hi_gqueue.h"
/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "vt_tcqueue_newtc_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_task.h"
/* ------------------------------------------------------
-- Asynchronous Provided Interface "artificial_newTc"
------------------------------------------------------ */
void po_hi_c_vt_tcqueue_newtc_artificial_newtc(__po_hi_task_id e, dataview__puspacket_buffer_impl buf)
{
   sync_tcqueue_newTc (buf.buffer, buf.length);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "newTc"
------------------------------------------------------ */
void vm_vt_tcqueue_newtc_newTc(void *tcPacket, size_t tcPacket_len)
{
   sync_tcqueue_newTc(tcPacket, tcPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_tcqueue_newtc_check_queue_vt(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_tcqueue_has_pending_msg(res, res_len);
}

