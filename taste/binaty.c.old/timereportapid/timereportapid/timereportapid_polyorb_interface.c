/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "timereportapid_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "timereportapid_vm_if.h"

/*----------------------------------------------------
-- Unprotected Provided Interface "getApid"
----------------------------------------------------*/
void sync_timereportapid_getApid(void *apid, size_t *apid_len)
{
   timereportapid_getApid(apid, apid_len);
}

/*----------------------------------------------------
-- Protected Provided Interface "getSequenceCount"
----------------------------------------------------*/
void sync_timereportapid_getSequenceCount(void *sequenceCount, size_t *sequenceCount_len)
{
   extern process_package__taste_protected_object timereportapid_protected;
   __po_hi_protected_lock (timereportapid_protected.protected_id);
   timereportapid_getSequenceCount(sequenceCount, sequenceCount_len);
   __po_hi_protected_unlock (timereportapid_protected.protected_id);
}

