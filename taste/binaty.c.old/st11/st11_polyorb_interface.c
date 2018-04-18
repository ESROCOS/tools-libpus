#include "po_hi_gqueue.h"
/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "st11_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "st11_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "tc11"
----------------------------------------------------*/
void sync_st11_tc11(void *tcPacket, size_t tcPacket_len)
{
   extern process_package__taste_protected_object st11_protected;
   __po_hi_protected_lock (st11_protected.protected_id);
   st11_tc11(tcPacket, tcPacket_len);
   __po_hi_protected_unlock (st11_protected.protected_id);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st11_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len)
{
   sync_st01_ACK(tcPacket, tcPacket_len, reportType, reportType_len, error, error_len, errorInfo, errorInfo_len, step, step_len);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc"
------------------------------------------------------ */
void vm_async_st11_newTc(void *tcPacket, size_t tcPacket_len)
{
   vm_async_tcdispatch_newTc_vt(tcPacket, tcPacket_len);
}

