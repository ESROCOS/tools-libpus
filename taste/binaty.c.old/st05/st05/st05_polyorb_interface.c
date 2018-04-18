/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "st05_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_task.h"
#include "st05_vm_if.h"

/* ------------------------------------------------------
-- Asynchronous Provided Interface "EventReportTrigger"
------------------------------------------------------ */
void po_hi_c_st05_eventreporttrigger(__po_hi_task_id e)
{
   st05_EventReportTrigger();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "newTmNoInherit"
------------------------------------------------------ */
void vm_st05_newTmNoInherit(void *tmPacket, size_t tmPacket_len)
{
   sync_tmqueue_newTm(tmPacket, tmPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getNextEvent"
------------------------------------------------------ */
void vm_st05_getNextEvent(void *actualCounter, size_t actualCounter_len, void *eventInfo, size_t *eventInfo_len, void *nextCounter, size_t *nextCounter_len)
{
   sync_events_getNextEvent(actualCounter, actualCounter_len, eventInfo, eventInfo_len, nextCounter, nextCounter_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getApid"
------------------------------------------------------ */
void vm_st05_getApid(void *apid, size_t *apid_len)
{
   sync_onboardapid_getApid(apid, apid_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount"
------------------------------------------------------ */
void vm_st05_getSequenceCount(void *sequenceCount, size_t *sequenceCount_len)
{
   sync_onboardapid_getSequenceCount(sequenceCount, sequenceCount_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_st05_check_queue(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_st05_has_pending_msg(res, res_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "incCount_vt"
------------------------------------------------------ */
void vm_st05_incCount_vt(void *tmPacket, size_t *tmPacket_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_st09_incCount(tmPacket, tmPacket_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "newTm_vt"
------------------------------------------------------ */
void vm_st05_newTm_vt(void *tmPacket, size_t tmPacket_len)
{
   sync_tmqueue_newTm(tmPacket, tmPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount_vt"
------------------------------------------------------ */
void vm_st05_getSequenceCount_vt(void *sequenceCount, size_t *sequenceCount_len)
{
   sync_onboardapid_getSequenceCount(sequenceCount, sequenceCount_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getApid_vt"
------------------------------------------------------ */
void vm_st05_getApid_vt(void *apid, size_t *apid_len)
{
   sync_onboardapid_getApid(apid, apid_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK_vt"
------------------------------------------------------ */
void vm_st05_ACK_vt(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_st05_check_queue_vt(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_events_has_pending_msg(res, res_len);
}

