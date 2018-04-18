/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "vt_trigger_pmontrigger_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_task.h"
/* ------------------------------------------------------
-- Asynchronous Provided Interface "artificial_PmonTrigger"
------------------------------------------------------ */
void po_hi_c_vt_trigger_pmontrigger_artificial_pmontrigger(__po_hi_task_id e)
{
   sync_trigger_PmonTrigger ();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "PmonTrigger"
------------------------------------------------------ */
void vm_vt_trigger_pmontrigger_PmonTrigger()
{
   sync_trigger_PmonTrigger();
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "tmTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_pmontrigger_tmTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_pmontrigger_global_outport_tmtrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_local_outport_tmtrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_global_outport_tmtrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "HkReportTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_pmontrigger_HkReportTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_pmontrigger_global_outport_hkreporttrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_local_outport_hkreporttrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_global_outport_hkreporttrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "PmonTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_pmontrigger_PmonTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_pmontrigger_global_outport_pmontrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_local_outport_pmontrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_global_outport_pmontrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "EventReportTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_pmontrigger_EventReportTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_pmontrigger_global_outport_eventreporttrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_local_outport_eventreporttrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_global_outport_eventreporttrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "tcTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_pmontrigger_tcTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_pmontrigger_global_outport_tctrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_local_outport_tctrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_global_outport_tctrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "debugEventsTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_pmontrigger_debugEventsTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_pmontrigger_global_outport_debugeventstrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_local_outport_debugeventstrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_global_outport_debugeventstrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "EventActionTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_pmontrigger_EventActionTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_pmontrigger_global_outport_eventactiontrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_local_outport_eventactiontrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_pmontrigger_k, vt_trigger_pmontrigger_global_outport_eventactiontrigger_vt);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_trigger_pmontrigger_check_queue_vt(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_trigger_has_pending_msg(res, res_len);
}

