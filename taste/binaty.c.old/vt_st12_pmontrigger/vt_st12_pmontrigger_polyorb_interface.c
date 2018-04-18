/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "vt_st12_pmontrigger_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_task.h"
/* ------------------------------------------------------
-- Asynchronous Provided Interface "artificial_PmonTrigger"
------------------------------------------------------ */
void po_hi_c_vt_st12_pmontrigger_artificial_pmontrigger(__po_hi_task_id e)
{
   sync_st12_PmonTrigger ();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "PmonTrigger"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_PmonTrigger()
{
   sync_st12_PmonTrigger();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "incCount_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_incCount_vt(void *tmPacket, size_t *tmPacket_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_st09_incCount(tmPacket, tmPacket_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "newTm_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_newTm_vt(void *tmPacket, size_t tmPacket_len)
{
   sync_tmqueue_newTm(tmPacket, tmPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_getSequenceCount_vt(void *sequenceCount, size_t *sequenceCount_len)
{
   sync_onboardapid_getSequenceCount(sequenceCount, sequenceCount_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getApid_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_getApid_vt(void *apid, size_t *apid_len)
{
   sync_onboardapid_getApid(apid, apid_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_ACK_vt(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_check_queue_vt(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_events_has_pending_msg(res, res_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "pushNewEvent_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_pushNewEvent_vt(void *eventInfo, size_t eventInfo_len)
{
   sync_events_pushNewEvent(eventInfo, eventInfo_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getParamValue_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_getParamValue_vt(void *paramId, size_t paramId_len, void *paramValue, size_t *paramValue_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_housekeeping_getParamValue(paramId, paramId_len, paramValue, paramValue_len, isAvailable, isAvailable_len);
}

