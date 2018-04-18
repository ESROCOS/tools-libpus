/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "tmqueue_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "tmqueue_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "tmRequest"
----------------------------------------------------*/
void sync_tmqueue_tmRequest(void *tmPacket, size_t *tmPacket_len, void *isAvailable, size_t *isAvailable_len)
{
   extern process_package__taste_protected_object tmqueue_protected;
   __po_hi_protected_lock (tmqueue_protected.protected_id);
   tmqueue_tmRequest(tmPacket, tmPacket_len, isAvailable, isAvailable_len);
   __po_hi_protected_unlock (tmqueue_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "newTm"
----------------------------------------------------*/
void sync_tmqueue_newTm(void *tmPacket, size_t tmPacket_len)
{
   extern process_package__taste_protected_object tmqueue_protected;
   __po_hi_protected_lock (tmqueue_protected.protected_id);
   tmqueue_newTm(tmPacket, tmPacket_len);
   __po_hi_protected_unlock (tmqueue_protected.protected_id);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "incCount"
------------------------------------------------------ */
void vm_tmqueue_incCount(void *tmPacket, size_t *tmPacket_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_st09_incCount(tmPacket, tmPacket_len, isAvailable, isAvailable_len);
}

