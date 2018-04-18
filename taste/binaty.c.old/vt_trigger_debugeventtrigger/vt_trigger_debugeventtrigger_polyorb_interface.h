/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef vt_trigger_debugeventtrigger_POLYORB_INTERFACE
#define vt_trigger_debugeventtrigger_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../trigger/trigger_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
/*----------------------------------------------------
-- Asynchronous Provided Interface "artificial_debugEventTrigger"
----------------------------------------------------*/
void po_hi_c_vt_trigger_debugeventtrigger_artificial_debugeventtrigger(__po_hi_task_id);

/* ------------------------------------------------------
--  Synchronous Required Interface "debugEventTrigger"
------------------------------------------------------ */
void vm_vt_trigger_debugeventtrigger_debugEventTrigger();
/* ------------------------------------------------------
--  Asynchronous Required Interface "tmTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_debugeventtrigger_tmTrigger_vt();
/* ------------------------------------------------------
--  Asynchronous Required Interface "HkReportTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_debugeventtrigger_HkReportTrigger_vt();
/* ------------------------------------------------------
--  Asynchronous Required Interface "PmonTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_debugeventtrigger_PmonTrigger_vt();
/* ------------------------------------------------------
--  Asynchronous Required Interface "EventReportTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_debugeventtrigger_EventReportTrigger_vt();
/* ------------------------------------------------------
--  Asynchronous Required Interface "tcTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_debugeventtrigger_tcTrigger_vt();
/* ------------------------------------------------------
--  Asynchronous Required Interface "debugEventsTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_debugeventtrigger_debugEventsTrigger_vt();
/* ------------------------------------------------------
--  Asynchronous Required Interface "EventActionTrigger_vt"
------------------------------------------------------ */
void vm_async_vt_trigger_debugeventtrigger_EventActionTrigger_vt();
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_trigger_debugeventtrigger_check_queue_vt(void *, size_t *);
#endif
