/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef trigger_POLYORB_INTERFACE
#define trigger_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../vt_trigger_hkreporttrigger/vt_trigger_hkreporttrigger_polyorb_interface.h"
#include "../../vt_trigger_tmdispatchtrigger/vt_trigger_tmdispatchtrigger_polyorb_interface.h"
#include "../../vt_trigger_eventactiontrigger/vt_trigger_eventactiontrigger_polyorb_interface.h"
#include "../../vt_trigger_tcdispatchtrigger/vt_trigger_tcdispatchtrigger_polyorb_interface.h"
#include "../../vt_trigger_pmontrigger/vt_trigger_pmontrigger_polyorb_interface.h"
#include "../../vt_trigger_eventreporttrigger/vt_trigger_eventreporttrigger_polyorb_interface.h"
#include "../../vt_trigger_debugeventtrigger/vt_trigger_debugeventtrigger_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "HkReportTrigger"
----------------------------------------------------*/
void sync_trigger_HkReportTrigger();

/*----------------------------------------------------
-- Protected Provided Interface "TmDispatchTrigger"
----------------------------------------------------*/
void sync_trigger_TmDispatchTrigger();

/*----------------------------------------------------
-- Protected Provided Interface "EventActionTrigger"
----------------------------------------------------*/
void sync_trigger_EventActionTrigger();

/*----------------------------------------------------
-- Protected Provided Interface "TcDispatchTrigger"
----------------------------------------------------*/
void sync_trigger_TcDispatchTrigger();

/*----------------------------------------------------
-- Protected Provided Interface "PmonTrigger"
----------------------------------------------------*/
void sync_trigger_PmonTrigger();

/*----------------------------------------------------
-- Protected Provided Interface "EventReportTrigger"
----------------------------------------------------*/
void sync_trigger_EventReportTrigger();

/*----------------------------------------------------
-- Protected Provided Interface "debugEventTrigger"
----------------------------------------------------*/
void sync_trigger_debugEventTrigger();

/* ------------------------------------------------------
--  Asynchronous Required Interface "tmTrigger"
------------------------------------------------------ */
void vm_async_trigger_tmTrigger();
/* ------------------------------------------------------
--  Asynchronous Required Interface "HkReportTrigger"
------------------------------------------------------ */
void vm_async_trigger_HkReportTrigger();
/* ------------------------------------------------------
--  Asynchronous Required Interface "PmonTrigger"
------------------------------------------------------ */
void vm_async_trigger_PmonTrigger();
/* ------------------------------------------------------
--  Asynchronous Required Interface "EventReportTrigger"
------------------------------------------------------ */
void vm_async_trigger_EventReportTrigger();
/* ------------------------------------------------------
--  Asynchronous Required Interface "tcTrigger"
------------------------------------------------------ */
void vm_async_trigger_tcTrigger();
/* ------------------------------------------------------
--  Asynchronous Required Interface "debugEventsTrigger"
------------------------------------------------------ */
void vm_async_trigger_debugEventsTrigger();
/* ------------------------------------------------------
--  Asynchronous Required Interface "EventActionTrigger"
------------------------------------------------------ */
void vm_async_trigger_EventActionTrigger();
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_trigger_check_queue(void *, size_t *);
#endif
