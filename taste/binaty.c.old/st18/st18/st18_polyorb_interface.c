/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "st18_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "st18_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "tc18"
----------------------------------------------------*/
void sync_st18_tc18(void *tcPacket, size_t tcPacket_len)
{
   extern process_package__taste_protected_object st18_protected;
   __po_hi_protected_lock (st18_protected.protected_id);
   st18_tc18(tcPacket, tcPacket_len);
   __po_hi_protected_unlock (st18_protected.protected_id);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st18_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "loadDirect"
------------------------------------------------------ */
void vm_st18_loadDirect(void *obcpId, size_t obcpId_len, void *obcpCode, size_t obcpCode_len)
{
   sync_obcpengine_loadDirect(obcpId, obcpId_len, obcpCode, obcpCode_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "loadReference"
------------------------------------------------------ */
void vm_st18_loadReference(void *referenceData, size_t referenceData_len)
{
   sync_obcpengine_loadReference(referenceData, referenceData_len);
}

