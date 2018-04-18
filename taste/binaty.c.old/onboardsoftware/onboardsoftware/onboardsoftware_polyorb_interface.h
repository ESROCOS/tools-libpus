/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef onboardsoftware_POLYORB_INTERFACE
#define onboardsoftware_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../housekeeping/housekeeping_polyorb_interface.h"
#include "../../housekeeping/housekeeping_polyorb_interface.h"
#include "../../events/events_polyorb_interface.h"
#include "../../onboardparams/onboardparams_polyorb_interface.h"
#include "../../onboardparams/onboardparams_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
/*----------------------------------------------------
-- Asynchronous Provided Interface "debugTrigger"
----------------------------------------------------*/
void po_hi_c_onboardsoftware_debugtrigger(__po_hi_task_id);

/* ------------------------------------------------------
--  Synchronous Required Interface "setParamValue"
------------------------------------------------------ */
void vm_onboardsoftware_setParamValue(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getParamValue"
------------------------------------------------------ */
void vm_onboardsoftware_getParamValue(void *paramId, size_t paramId_len, void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "pushNewEvent"
------------------------------------------------------ */
void vm_onboardsoftware_pushNewEvent(void *eventInfo, size_t eventInfo_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "setOnBoardParam"
------------------------------------------------------ */
void vm_onboardsoftware_setOnBoardParam(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getOnBoardParam"
------------------------------------------------------ */
void vm_onboardsoftware_getOnBoardParam(void *paramId, size_t paramId_len, void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_onboardsoftware_check_queue(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_onboardsoftware_check_queue_vt(void *, size_t *);
#endif
