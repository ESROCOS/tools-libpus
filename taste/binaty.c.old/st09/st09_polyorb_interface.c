/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "st09_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "st09_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "incCount"
----------------------------------------------------*/
void sync_st09_incCount(void *tmPacket, size_t *tmPacket_len, void *isAvailable, size_t *isAvailable_len)
{
   extern process_package__taste_protected_object st09_protected;
   __po_hi_protected_lock (st09_protected.protected_id);
   st09_incCount(tmPacket, tmPacket_len, isAvailable, isAvailable_len);
   __po_hi_protected_unlock (st09_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "tc09"
----------------------------------------------------*/
void sync_st09_tc09(void *tcPacket, size_t tcPacket_len)
{
   extern process_package__taste_protected_object st09_protected;
   __po_hi_protected_lock (st09_protected.protected_id);
   st09_tc09(tcPacket, tcPacket_len);
   __po_hi_protected_unlock (st09_protected.protected_id);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getApid"
------------------------------------------------------ */
void vm_st09_getApid(void *apid, size_t *apid_len)
{
   sync_timereportapid_getApid(apid, apid_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount"
------------------------------------------------------ */
void vm_st09_getSequenceCount(void *sequenceCount, size_t *sequenceCount_len)
{
   sync_timereportapid_getSequenceCount(sequenceCount, sequenceCount_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st09_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

