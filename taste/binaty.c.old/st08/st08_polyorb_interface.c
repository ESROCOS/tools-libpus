/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "st08_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "st08_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "tc08"
----------------------------------------------------*/
void sync_st08_tc08(void *tcPacket, size_t tcPacket_len)
{
   extern process_package__taste_protected_object st08_protected;
   __po_hi_protected_lock (st08_protected.protected_id);
   st08_tc08(tcPacket, tcPacket_len);
   __po_hi_protected_unlock (st08_protected.protected_id);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st08_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

