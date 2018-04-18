/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "st20_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "st20_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "tc20"
----------------------------------------------------*/
void sync_st20_tc20(void *tcPacket, size_t tcPacket_len)
{
   extern process_package__taste_protected_object st20_protected;
   __po_hi_protected_lock (st20_protected.protected_id);
   st20_tc20(tcPacket, tcPacket_len);
   __po_hi_protected_unlock (st20_protected.protected_id);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "setOnBoardParam"
------------------------------------------------------ */
void vm_st20_setOnBoardParam(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len)
{
   sync_onboardparams_setOnBoardParam(paramId, paramId_len, paramValue, paramValue_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getOnBoardParam"
------------------------------------------------------ */
void vm_st20_getOnBoardParam(void *paramId, size_t paramId_len, void *paramValue, size_t *paramValue_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_onboardparams_getOnBoardParam(paramId, paramId_len, paramValue, paramValue_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_st20_newTm(void *tmPacket, size_t tmPacket_len)
{
   sync_tmqueue_newTm(tmPacket, tmPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st20_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getApid"
------------------------------------------------------ */
void vm_st20_getApid(void *apid, size_t *apid_len)
{
   sync_onboardapid_getApid(apid, apid_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount"
------------------------------------------------------ */
void vm_st20_getSequenceCount(void *sequenceCount, size_t *sequenceCount_len)
{
   sync_onboardapid_getSequenceCount(sequenceCount, sequenceCount_len);
}

