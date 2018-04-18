/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "onboardapid_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "onboardapid_vm_if.h"

/*----------------------------------------------------
-- Unprotected Provided Interface "getApid"
----------------------------------------------------*/
void sync_onboardapid_getApid(void *apid, size_t *apid_len)
{
   onboardapid_getApid(apid, apid_len);
}

/*----------------------------------------------------
-- Protected Provided Interface "getSequenceCount"
----------------------------------------------------*/
void sync_onboardapid_getSequenceCount(void *sequenceCount, size_t *sequenceCount_len)
{
   extern process_package__taste_protected_object onboardapid_protected;
   __po_hi_protected_lock (onboardapid_protected.protected_id);
   onboardapid_getSequenceCount(sequenceCount, sequenceCount_len);
   __po_hi_protected_unlock (onboardapid_protected.protected_id);
}

