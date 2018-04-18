#include "po_hi_gqueue.h"
/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "tcdispatch_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_task.h"
#include "tcdispatch_vm_if.h"

/* ------------------------------------------------------
-- Asynchronous Provided Interface "tcTrigger"
------------------------------------------------------ */
void po_hi_c_tcdispatch_tctrigger(__po_hi_task_id e)
{
   tcdispatch_tcTrigger();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "tcRequest"
------------------------------------------------------ */
void vm_tcdispatch_tcRequest(void *tcPacket, size_t *tcPacket_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_tcqueue_tcRequest(tcPacket, tcPacket_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "tc17"
------------------------------------------------------ */
void vm_tcdispatch_tc17(void *tcPacket, size_t tcPacket_len)
{
   sync_st17_tc17(tcPacket, tcPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "tc08"
------------------------------------------------------ */
void vm_tcdispatch_tc08(void *tcPacket, size_t tcPacket_len)
{
   sync_st08_tc08(tcPacket, tcPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "tc19"
------------------------------------------------------ */
void vm_tcdispatch_tc19(void *tcPacket, size_t tcPacket_len)
{
   sync_st19_tc19(tcPacket, tcPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "tc09"
------------------------------------------------------ */
void vm_tcdispatch_tc09(void *tcPacket, size_t tcPacket_len)
{
   sync_st09_tc09(tcPacket, tcPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "tc12"
------------------------------------------------------ */
void vm_tcdispatch_tc12(void *tcPacket, size_t tcPacket_len)
{
   sync_st12_tc12(tcPacket, tcPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "tc11"
------------------------------------------------------ */
void vm_tcdispatch_tc11(void *tcPacket, size_t tcPacket_len)
{
   sync_st11_tc11(tcPacket, tcPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "tc18"
------------------------------------------------------ */
void vm_tcdispatch_tc18(void *tcPacket, size_t tcPacket_len)
{
   sync_st18_tc18(tcPacket, tcPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "tc23"
------------------------------------------------------ */
void vm_tcdispatch_tc23()
{
   sync_st23_tc23();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "tc20"
------------------------------------------------------ */
void vm_tcdispatch_tc20(void *tcPacket, size_t tcPacket_len)
{
   sync_st20_tc20(tcPacket, tcPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_tcdispatch_check_queue(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_tcdispatch_has_pending_msg(res, res_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_tcdispatch_check_queue_vt(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_tcqueue_has_pending_msg(res, res_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "incCount_vt"
------------------------------------------------------ */
void vm_tcdispatch_incCount_vt(void *tmPacket, size_t *tmPacket_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_st09_incCount(tmPacket, tmPacket_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK_vt"
------------------------------------------------------ */
void vm_tcdispatch_ACK_vt(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getApid_vt"
------------------------------------------------------ */
void vm_tcdispatch_getApid_vt(void *apid, size_t *apid_len)
{
   sync_onboardapid_getApid(apid, apid_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount_vt"
------------------------------------------------------ */
void vm_tcdispatch_getSequenceCount_vt(void *sequenceCount, size_t *sequenceCount_len)
{
   sync_onboardapid_getSequenceCount(sequenceCount, sequenceCount_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "newTm_vt"
------------------------------------------------------ */
void vm_tcdispatch_newTm_vt(void *tmPacket, size_t tmPacket_len)
{
   sync_tmqueue_newTm(tmPacket, tmPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getNextEvent_vt"
------------------------------------------------------ */
void vm_tcdispatch_getNextEvent_vt(void *actualCounter, size_t actualCounter_len, void *eventInfo, size_t *eventInfo_len, void *nextCounter, size_t *nextCounter_len)
{
   sync_events_getNextEvent(actualCounter, actualCounter_len, eventInfo, eventInfo_len, nextCounter, nextCounter_len);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc_vt"
------------------------------------------------------ */
void vm_async_tcdispatch_newTc_vt(void *tcPacket, size_t tcPacket_len)
{
   __po_hi_request_t request;

   __po_hi_copy_array(&(request.vars.tcdispatch_global_outport_newtc_vt.tcdispatch_global_outport_newtc_vt.buffer), tcPacket, tcPacket_len);
   request.vars.tcdispatch_global_outport_newtc_vt.tcdispatch_global_outport_newtc_vt.length = tcPacket_len;
   request.port = tcdispatch_global_outport_newtc_vt;
   __po_hi_gqueue_store_out(x86_partition_tcdispatch_k, tcdispatch_local_outport_newtc_vt, &request);
   __po_hi_send_output(x86_partition_tcdispatch_k, tcdispatch_global_outport_newtc_vt);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "pushNewEvent_vt"
------------------------------------------------------ */
void vm_tcdispatch_pushNewEvent_vt(void *eventInfo, size_t eventInfo_len)
{
   sync_events_pushNewEvent(eventInfo, eventInfo_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getParamValue_vt"
------------------------------------------------------ */
void vm_tcdispatch_getParamValue_vt(void *paramId, size_t paramId_len, void *paramValue, size_t *paramValue_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_housekeeping_getParamValue(paramId, paramId_len, paramValue, paramValue_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "loadDirect_vt"
------------------------------------------------------ */
void vm_tcdispatch_loadDirect_vt(void *obcpId, size_t obcpId_len, void *obcpCode, size_t obcpCode_len)
{
   sync_obcpengine_loadDirect(obcpId, obcpId_len, obcpCode, obcpCode_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "loadReference_vt"
------------------------------------------------------ */
void vm_tcdispatch_loadReference_vt(void *referenceData, size_t referenceData_len)
{
   sync_obcpengine_loadReference(referenceData, referenceData_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getOnBoardParam_vt"
------------------------------------------------------ */
void vm_tcdispatch_getOnBoardParam_vt(void *paramId, size_t paramId_len, void *paramValue, size_t *paramValue_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_onboardparams_getOnBoardParam(paramId, paramId_len, paramValue, paramValue_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "setOnBoardParam_vt"
------------------------------------------------------ */
void vm_tcdispatch_setOnBoardParam_vt(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len)
{
   sync_onboardparams_setOnBoardParam(paramId, paramId_len, paramValue, paramValue_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "copy_vt"
------------------------------------------------------ */
void vm_tcdispatch_copy_vt()
{
   sync_filemanagement_copy();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "delete_vt"
------------------------------------------------------ */
void vm_tcdispatch_delete_vt()
{
   sync_filemanagement_delete();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "create_vt"
------------------------------------------------------ */
void vm_tcdispatch_create_vt()
{
   sync_filemanagement_create();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getAttributes_vt"
------------------------------------------------------ */
void vm_tcdispatch_getAttributes_vt()
{
   sync_filemanagement_getAttributes();
}

