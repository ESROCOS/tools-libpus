/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "st23_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "st23_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "tc23"
----------------------------------------------------*/
void sync_st23_tc23()
{
   extern process_package__taste_protected_object st23_protected;
   __po_hi_protected_lock (st23_protected.protected_id);
   st23_tc23();
   __po_hi_protected_unlock (st23_protected.protected_id);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "copy"
------------------------------------------------------ */
void vm_st23_copy()
{
   sync_filemanagement_copy();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "delete"
------------------------------------------------------ */
void vm_st23_delete()
{
   sync_filemanagement_delete();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "create"
------------------------------------------------------ */
void vm_st23_create()
{
   sync_filemanagement_create();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getAttributes"
------------------------------------------------------ */
void vm_st23_getAttributes()
{
   sync_filemanagement_getAttributes();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_st23_newTm(void *tmPacket, size_t tmPacket_len)
{
   sync_tmqueue_newTm(tmPacket, tmPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getApid"
------------------------------------------------------ */
void vm_st23_getApid(void *apid, size_t *apid_len)
{
   sync_onboardapid_getApid(apid, apid_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount"
------------------------------------------------------ */
void vm_st23_getSequenceCount(void *sequenceCount, size_t *sequenceCount_len)
{
   sync_onboardapid_getSequenceCount(sequenceCount, sequenceCount_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st23_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

