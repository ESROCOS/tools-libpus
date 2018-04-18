/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "onboardparams_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "onboardparams_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "setOnBoardParam"
----------------------------------------------------*/
void sync_onboardparams_setOnBoardParam(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len)
{
   extern process_package__taste_protected_object onboardparams_protected;
   __po_hi_protected_lock (onboardparams_protected.protected_id);
   onboardparams_setOnBoardParam(paramId, paramId_len, paramValue, paramValue_len);
   __po_hi_protected_unlock (onboardparams_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "getOnBoardParam"
----------------------------------------------------*/
void sync_onboardparams_getOnBoardParam(void *paramId, size_t paramId_len, void *paramValue, size_t *paramValue_len, void *isAvailable, size_t *isAvailable_len)
{
   extern process_package__taste_protected_object onboardparams_protected;
   __po_hi_protected_lock (onboardparams_protected.protected_id);
   onboardparams_getOnBoardParam(paramId, paramId_len, paramValue, paramValue_len, isAvailable, isAvailable_len);
   __po_hi_protected_unlock (onboardparams_protected.protected_id);
}

