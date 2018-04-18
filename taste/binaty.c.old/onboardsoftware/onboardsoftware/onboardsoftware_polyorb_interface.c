/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "onboardsoftware_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_task.h"
#include "onboardsoftware_vm_if.h"

/* ------------------------------------------------------
-- Asynchronous Provided Interface "debugTrigger"
------------------------------------------------------ */
void po_hi_c_onboardsoftware_debugtrigger(__po_hi_task_id e)
{
   onboardsoftware_debugTrigger();
}

/* ------------------------------------------------------
--  Synchronous Required Interface "setParamValue"
------------------------------------------------------ */
void vm_onboardsoftware_setParamValue(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len)
{
   sync_housekeeping_setParamValue(paramId, paramId_len, paramValue, paramValue_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getParamValue"
------------------------------------------------------ */
void vm_onboardsoftware_getParamValue(void *paramId, size_t paramId_len, void *paramValue, size_t *paramValue_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_housekeeping_getParamValue(paramId, paramId_len, paramValue, paramValue_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "pushNewEvent"
------------------------------------------------------ */
void vm_onboardsoftware_pushNewEvent(void *eventInfo, size_t eventInfo_len)
{
   sync_events_pushNewEvent(eventInfo, eventInfo_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "setOnBoardParam"
------------------------------------------------------ */
void vm_onboardsoftware_setOnBoardParam(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len)
{
   sync_onboardparams_setOnBoardParam(paramId, paramId_len, paramValue, paramValue_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "getOnBoardParam"
------------------------------------------------------ */
void vm_onboardsoftware_getOnBoardParam(void *paramId, size_t paramId_len, void *paramValue, size_t *paramValue_len, void *isAvailable, size_t *isAvailable_len)
{
   sync_onboardparams_getOnBoardParam(paramId, paramId_len, paramValue, paramValue_len, isAvailable, isAvailable_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_onboardsoftware_check_queue(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_onboardsoftware_has_pending_msg(res, res_len);
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_onboardsoftware_check_queue_vt(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_events_has_pending_msg(res, res_len);
}

