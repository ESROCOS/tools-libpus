/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "housekeeping_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "housekeeping_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "setParamValue"
----------------------------------------------------*/
void sync_housekeeping_setParamValue(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len)
{
   extern process_package__taste_protected_object housekeeping_protected;
   __po_hi_protected_lock (housekeeping_protected.protected_id);
   housekeeping_setParamValue(paramId, paramId_len, paramValue, paramValue_len);
   __po_hi_protected_unlock (housekeeping_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "getParamValue"
----------------------------------------------------*/
void sync_housekeeping_getParamValue(void *paramId, size_t paramId_len, void *paramValue, size_t *paramValue_len, void *isAvailable, size_t *isAvailable_len)
{
   extern process_package__taste_protected_object housekeeping_protected;
   __po_hi_protected_lock (housekeeping_protected.protected_id);
   housekeeping_getParamValue(paramId, paramId_len, paramValue, paramValue_len, isAvailable, isAvailable_len);
   __po_hi_protected_unlock (housekeeping_protected.protected_id);
}

