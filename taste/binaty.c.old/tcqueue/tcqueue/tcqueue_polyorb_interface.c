/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "tcqueue_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "tcqueue_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "newTc"
----------------------------------------------------*/
void sync_tcqueue_newTc(void *tcPacket, size_t tcPacket_len)
{
   extern process_package__taste_protected_object tcqueue_protected;
   __po_hi_protected_lock (tcqueue_protected.protected_id);
   tcqueue_newTc(tcPacket, tcPacket_len);
   __po_hi_protected_unlock (tcqueue_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "tcRequest"
----------------------------------------------------*/
void sync_tcqueue_tcRequest(void *tcPacket, size_t *tcPacket_len, void *isAvailable, size_t *isAvailable_len)
{
   extern process_package__taste_protected_object tcqueue_protected;
   __po_hi_protected_lock (tcqueue_protected.protected_id);
   tcqueue_tcRequest(tcPacket, tcPacket_len, isAvailable, isAvailable_len);
   __po_hi_protected_unlock (tcqueue_protected.protected_id);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_tcqueue_check_queue(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_tcqueue_has_pending_msg(res, res_len);
}

