#include "po_hi_gqueue.h"
/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "obcpengine_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "obcpengine_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "loadDirect"
----------------------------------------------------*/
void sync_obcpengine_loadDirect(void *obcpId, size_t obcpId_len, void *obcpCode, size_t obcpCode_len)
{
   extern process_package__taste_protected_object obcpengine_protected;
   __po_hi_protected_lock (obcpengine_protected.protected_id);
   obcpengine_loadDirect(obcpId, obcpId_len, obcpCode, obcpCode_len);
   __po_hi_protected_unlock (obcpengine_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "loadReference"
----------------------------------------------------*/
void sync_obcpengine_loadReference(void *referenceData, size_t referenceData_len)
{
   extern process_package__taste_protected_object obcpengine_protected;
   __po_hi_protected_lock (obcpengine_protected.protected_id);
   obcpengine_loadReference(referenceData, referenceData_len);
   __po_hi_protected_unlock (obcpengine_protected.protected_id);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc"
------------------------------------------------------ */
void vm_async_obcpengine_newTc(void *tcPacket, size_t tcPacket_len)
{
   vm_async_tcdispatch_newTc_vt(tcPacket, tcPacket_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getOnBoardParam"
------------------------------------------------------ */
void vm_obcpengine_getOnBoardParam(void *paramId, size_t paramId_len, void *paramValue, size_t *paramValue_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_onboardparams_getOnBoardParam(paramId, paramId_len, paramValue, paramValue_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "setOnBoardParam"
------------------------------------------------------ */
void vm_obcpengine_setOnBoardParam(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len)
{
   sync_onboardparams_setOnBoardParam(paramId, paramId_len, paramValue, paramValue_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "pushNewEvent"
------------------------------------------------------ */
void vm_obcpengine_pushNewEvent(void *eventInfo, size_t eventInfo_len)
{
   sync_events_pushNewEvent(eventInfo, eventInfo_len);
}

