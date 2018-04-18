/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "vt_trigger_eventreporttrigger_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_task.h"
/* ------------------------------------------------------
-- Asynchronous Provided Interface "artificial_EventReportTrigger"
------------------------------------------------------ */
void po_hi_c_vt_trigger_eventreporttrigger_artificial_eventreporttrigger(__po_hi_task_id e)
{
   sync_trigger_EventReportTrigger ();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "EventReportTrigger"
------------------------------------------------------ */
void vm_vt_trigger_eventreporttrigger_EventReportTrigger()
{
   sync_trigger_EventReportTrigger();
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "tmTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_eventreporttrigger_tmTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_eventreporttrigger_global_outport_tmtrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_local_outport_tmtrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_global_outport_tmtrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "HkReportTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_eventreporttrigger_HkReportTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_eventreporttrigger_global_outport_hkreporttrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_local_outport_hkreporttrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_global_outport_hkreporttrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "PmonTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_eventreporttrigger_PmonTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_eventreporttrigger_global_outport_pmontrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_local_outport_pmontrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_global_outport_pmontrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "EventReportTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_eventreporttrigger_EventReportTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_eventreporttrigger_global_outport_eventreporttrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_local_outport_eventreporttrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_global_outport_eventreporttrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "tcTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_eventreporttrigger_tcTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_eventreporttrigger_global_outport_tctrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_local_outport_tctrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_global_outport_tctrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "debugEventsTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_eventreporttrigger_debugEventsTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_eventreporttrigger_global_outport_debugeventstrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_local_outport_debugeventstrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_global_outport_debugeventstrigger_vt);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "EventActionTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_eventreporttrigger_EventActionTrigger_vt()
{
   __po_hi_request_t request;

   request.port = vt_trigger_eventreporttrigger_global_outport_eventactiontrigger_vt;
   __po_hi_gqueue_store_out(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_local_outport_eventactiontrigger_vt, &request);
   __po_hi_send_output(x86_partition_vt_trigger_eventreporttrigger_k, vt_trigger_eventreporttrigger_global_outport_eventactiontrigger_vt);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_trigger_eventreporttrigger_check_queue_vt(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_trigger_has_pending_msg(res, res_len);
}

