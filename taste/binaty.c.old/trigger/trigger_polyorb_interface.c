/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "trigger_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "trigger_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "HkReportTrigger"
----------------------------------------------------*/
void sync_trigger_HkReportTrigger()
{
   extern process_package__taste_protected_object trigger_protected;
   __po_hi_protected_lock (trigger_protected.protected_id);
   trigger_HkReportTrigger();
   __po_hi_protected_unlock (trigger_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "TmDispatchTrigger"
----------------------------------------------------*/
void sync_trigger_TmDispatchTrigger()
{
   extern process_package__taste_protected_object trigger_protected;
   __po_hi_protected_lock (trigger_protected.protected_id);
   trigger_TmDispatchTrigger();
   __po_hi_protected_unlock (trigger_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "EventActionTrigger"
----------------------------------------------------*/
void sync_trigger_EventActionTrigger()
{
   extern process_package__taste_protected_object trigger_protected;
   __po_hi_protected_lock (trigger_protected.protected_id);
   trigger_EventActionTrigger();
   __po_hi_protected_unlock (trigger_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "TcDispatchTrigger"
----------------------------------------------------*/
void sync_trigger_TcDispatchTrigger()
{
   extern process_package__taste_protected_object trigger_protected;
   __po_hi_protected_lock (trigger_protected.protected_id);
   trigger_TcDispatchTrigger();
   __po_hi_protected_unlock (trigger_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "PmonTrigger"
----------------------------------------------------*/
void sync_trigger_PmonTrigger()
{
   extern process_package__taste_protected_object trigger_protected;
   __po_hi_protected_lock (trigger_protected.protected_id);
   trigger_PmonTrigger();
   __po_hi_protected_unlock (trigger_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "EventReportTrigger"
----------------------------------------------------*/
void sync_trigger_EventReportTrigger()
{
   extern process_package__taste_protected_object trigger_protected;
   __po_hi_protected_lock (trigger_protected.protected_id);
   trigger_EventReportTrigger();
   __po_hi_protected_unlock (trigger_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "debugEventTrigger"
----------------------------------------------------*/
void sync_trigger_debugEventTrigger()
{
   extern process_package__taste_protected_object trigger_protected;
   __po_hi_protected_lock (trigger_protected.protected_id);
   trigger_debugEventTrigger();
   __po_hi_protected_unlock (trigger_protected.protected_id);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "tmTrigger"
------------------------------------------------------ */
void vm_async_trigger_tmTrigger()
{
   switch(__po_hi_get_task_id()) {
      case x86_partition_vt_trigger_hkreporttrigger_k: vm_async_vt_trigger_hkreporttrigger_tmTrigger_vt(); break;
      case x86_partition_vt_trigger_tmdispatchtrigger_k: vm_async_vt_trigger_tmdispatchtrigger_tmTrigger_vt(); break;
      case x86_partition_vt_trigger_eventactiontrigger_k: vm_async_vt_trigger_eventactiontrigger_tmTrigger_vt(); break;
      case x86_partition_vt_trigger_tcdispatchtrigger_k: vm_async_vt_trigger_tcdispatchtrigger_tmTrigger_vt(); break;
      case x86_partition_vt_trigger_pmontrigger_k: vm_async_vt_trigger_pmontrigger_tmTrigger_vt(); break;
      case x86_partition_vt_trigger_eventreporttrigger_k: vm_async_vt_trigger_eventreporttrigger_tmTrigger_vt(); break;
      case x86_partition_vt_trigger_debugeventtrigger_k: vm_async_vt_trigger_debugeventtrigger_tmTrigger_vt(); break;
      default: break;
   }
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "HkReportTrigger"
------------------------------------------------------ */
void vm_async_trigger_HkReportTrigger()
{
   switch(__po_hi_get_task_id()) {
      case x86_partition_vt_trigger_hkreporttrigger_k: vm_async_vt_trigger_hkreporttrigger_HkReportTrigger_vt(); break;
      case x86_partition_vt_trigger_tmdispatchtrigger_k: vm_async_vt_trigger_tmdispatchtrigger_HkReportTrigger_vt(); break;
      case x86_partition_vt_trigger_eventactiontrigger_k: vm_async_vt_trigger_eventactiontrigger_HkReportTrigger_vt(); break;
      case x86_partition_vt_trigger_tcdispatchtrigger_k: vm_async_vt_trigger_tcdispatchtrigger_HkReportTrigger_vt(); break;
      case x86_partition_vt_trigger_pmontrigger_k: vm_async_vt_trigger_pmontrigger_HkReportTrigger_vt(); break;
      case x86_partition_vt_trigger_eventreporttrigger_k: vm_async_vt_trigger_eventreporttrigger_HkReportTrigger_vt(); break;
      case x86_partition_vt_trigger_debugeventtrigger_k: vm_async_vt_trigger_debugeventtrigger_HkReportTrigger_vt(); break;
      default: break;
   }
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "PmonTrigger"
------------------------------------------------------ */
void vm_async_trigger_PmonTrigger()
{
   switch(__po_hi_get_task_id()) {
      case x86_partition_vt_trigger_hkreporttrigger_k: vm_async_vt_trigger_hkreporttrigger_PmonTrigger_vt(); break;
      case x86_partition_vt_trigger_tmdispatchtrigger_k: vm_async_vt_trigger_tmdispatchtrigger_PmonTrigger_vt(); break;
      case x86_partition_vt_trigger_eventactiontrigger_k: vm_async_vt_trigger_eventactiontrigger_PmonTrigger_vt(); break;
      case x86_partition_vt_trigger_tcdispatchtrigger_k: vm_async_vt_trigger_tcdispatchtrigger_PmonTrigger_vt(); break;
      case x86_partition_vt_trigger_pmontrigger_k: vm_async_vt_trigger_pmontrigger_PmonTrigger_vt(); break;
      case x86_partition_vt_trigger_eventreporttrigger_k: vm_async_vt_trigger_eventreporttrigger_PmonTrigger_vt(); break;
      case x86_partition_vt_trigger_debugeventtrigger_k: vm_async_vt_trigger_debugeventtrigger_PmonTrigger_vt(); break;
      default: break;
   }
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "EventReportTrigger"
------------------------------------------------------ */
void vm_async_trigger_EventReportTrigger()
{
   switch(__po_hi_get_task_id()) {
      case x86_partition_vt_trigger_hkreporttrigger_k: vm_async_vt_trigger_hkreporttrigger_EventReportTrigger_vt(); break;
      case x86_partition_vt_trigger_tmdispatchtrigger_k: vm_async_vt_trigger_tmdispatchtrigger_EventReportTrigger_vt(); break;
      case x86_partition_vt_trigger_eventactiontrigger_k: vm_async_vt_trigger_eventactiontrigger_EventReportTrigger_vt(); break;
      case x86_partition_vt_trigger_tcdispatchtrigger_k: vm_async_vt_trigger_tcdispatchtrigger_EventReportTrigger_vt(); break;
      case x86_partition_vt_trigger_pmontrigger_k: vm_async_vt_trigger_pmontrigger_EventReportTrigger_vt(); break;
      case x86_partition_vt_trigger_eventreporttrigger_k: vm_async_vt_trigger_eventreporttrigger_EventReportTrigger_vt(); break;
      case x86_partition_vt_trigger_debugeventtrigger_k: vm_async_vt_trigger_debugeventtrigger_EventReportTrigger_vt(); break;
      default: break;
   }
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "tcTrigger"
------------------------------------------------------ */
void vm_async_trigger_tcTrigger()
{
   switch(__po_hi_get_task_id()) {
      case x86_partition_vt_trigger_hkreporttrigger_k: vm_async_vt_trigger_hkreporttrigger_tcTrigger_vt(); break;
      case x86_partition_vt_trigger_tmdispatchtrigger_k: vm_async_vt_trigger_tmdispatchtrigger_tcTrigger_vt(); break;
      case x86_partition_vt_trigger_eventactiontrigger_k: vm_async_vt_trigger_eventactiontrigger_tcTrigger_vt(); break;
      case x86_partition_vt_trigger_tcdispatchtrigger_k: vm_async_vt_trigger_tcdispatchtrigger_tcTrigger_vt(); break;
      case x86_partition_vt_trigger_pmontrigger_k: vm_async_vt_trigger_pmontrigger_tcTrigger_vt(); break;
      case x86_partition_vt_trigger_eventreporttrigger_k: vm_async_vt_trigger_eventreporttrigger_tcTrigger_vt(); break;
      case x86_partition_vt_trigger_debugeventtrigger_k: vm_async_vt_trigger_debugeventtrigger_tcTrigger_vt(); break;
      default: break;
   }
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "debugEventsTrigger"
------------------------------------------------------ */
void vm_async_trigger_debugEventsTrigger()
{
   switch(__po_hi_get_task_id()) {
      case x86_partition_vt_trigger_hkreporttrigger_k: vm_async_vt_trigger_hkreporttrigger_debugEventsTrigger_vt(); break;
      case x86_partition_vt_trigger_tmdispatchtrigger_k: vm_async_vt_trigger_tmdispatchtrigger_debugEventsTrigger_vt(); break;
      case x86_partition_vt_trigger_eventactiontrigger_k: vm_async_vt_trigger_eventactiontrigger_debugEventsTrigger_vt(); break;
      case x86_partition_vt_trigger_tcdispatchtrigger_k: vm_async_vt_trigger_tcdispatchtrigger_debugEventsTrigger_vt(); break;
      case x86_partition_vt_trigger_pmontrigger_k: vm_async_vt_trigger_pmontrigger_debugEventsTrigger_vt(); break;
      case x86_partition_vt_trigger_eventreporttrigger_k: vm_async_vt_trigger_eventreporttrigger_debugEventsTrigger_vt(); break;
      case x86_partition_vt_trigger_debugeventtrigger_k: vm_async_vt_trigger_debugeventtrigger_debugEventsTrigger_vt(); break;
      default: break;
   }
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "EventActionTrigger"
------------------------------------------------------ */
void vm_async_trigger_EventActionTrigger()
{
   switch(__po_hi_get_task_id()) {
      case x86_partition_vt_trigger_hkreporttrigger_k: vm_async_vt_trigger_hkreporttrigger_EventActionTrigger_vt(); break;
      case x86_partition_vt_trigger_tmdispatchtrigger_k: vm_async_vt_trigger_tmdispatchtrigger_EventActionTrigger_vt(); break;
      case x86_partition_vt_trigger_eventactiontrigger_k: vm_async_vt_trigger_eventactiontrigger_EventActionTrigger_vt(); break;
      case x86_partition_vt_trigger_tcdispatchtrigger_k: vm_async_vt_trigger_tcdispatchtrigger_EventActionTrigger_vt(); break;
      case x86_partition_vt_trigger_pmontrigger_k: vm_async_vt_trigger_pmontrigger_EventActionTrigger_vt(); break;
      case x86_partition_vt_trigger_eventreporttrigger_k: vm_async_vt_trigger_eventreporttrigger_EventActionTrigger_vt(); break;
      case x86_partition_vt_trigger_debugeventtrigger_k: vm_async_vt_trigger_debugeventtrigger_EventActionTrigger_vt(); break;
      default: break;
   }
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_trigger_check_queue(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_trigger_has_pending_msg(res, res_len);
}

