/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef vt_st19_eventactiontrigger_POLYORB_INTERFACE
#define vt_st19_eventactiontrigger_POLYORB_INTERFACE
#include <stddef.h>

#include "types.h"
#include "deployment.h"
#include "po_hi_transport.h"
#include "../../st19/st19_polyorb_interface.h"
#include "../../st09/st09_polyorb_interface.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../events/events_polyorb_interface.h"
/*----------------------------------------------------
-- Asynchronous Provided Interface "artificial_EventActionTrigger"
----------------------------------------------------*/
void po_hi_c_vt_st19_eventactiontrigger_artificial_eventactiontrigger(__po_hi_task_id);

/* ------------------------------------------------------
--  Synchronous Required Interface "EventActionTrigger"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_EventActionTrigger();
/* ------------------------------------------------------
--  Synchronous Required Interface "incCount_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_incCount_vt(void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "newTm_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_newTm_vt(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_getSequenceCount_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getApid_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_getApid_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "ACK_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_ACK_vt(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_check_queue_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getNextEvent_vt"
------------------------------------------------------ */
void vm_vt_st19_eventactiontrigger_getNextEvent_vt(void *actualCounter, size_t actualCounter_len, void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc_vt"
------------------------------------------------------ */
void vm_async_vt_st19_eventactiontrigger_newTc_vt(void *tcPacket, size_t tcPacket_len);
#endif
