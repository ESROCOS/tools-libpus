/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef vt_st12_pmontrigger_POLYORB_INTERFACE
#define vt_st12_pmontrigger_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../st12/st12_polyorb_interface.h"
#include "../../st09/st09_polyorb_interface.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../events/events_polyorb_interface.h"
#include "../../housekeeping/housekeeping_polyorb_interface.h"
/*----------------------------------------------------
-- Asynchronous Provided Interface "artificial_PmonTrigger"
----------------------------------------------------*/
void po_hi_c_vt_st12_pmontrigger_artificial_pmontrigger(__po_hi_task_id);

/* ------------------------------------------------------
--  Synchronous Required Interface "PmonTrigger"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_PmonTrigger();
/* ------------------------------------------------------
--  Synchronous Required Interface "incCount_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_incCount_vt(void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "newTm_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_newTm_vt(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_getSequenceCount_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getApid_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_getApid_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "ACK_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_ACK_vt(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_check_queue_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "pushNewEvent_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_pushNewEvent_vt(void *eventInfo, size_t eventInfo_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getParamValue_vt"
------------------------------------------------------ */
void vm_vt_st12_pmontrigger_getParamValue_vt(void *paramId, size_t paramId_len, void *, size_t *, void *, size_t *);
#endif
