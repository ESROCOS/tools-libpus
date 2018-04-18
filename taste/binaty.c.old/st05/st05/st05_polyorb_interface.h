/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef st05_POLYORB_INTERFACE
#define st05_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../events/events_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../st09/st09_polyorb_interface.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
/*----------------------------------------------------
-- Asynchronous Provided Interface "EventReportTrigger"
----------------------------------------------------*/
void po_hi_c_st05_eventreporttrigger(__po_hi_task_id);

/* ------------------------------------------------------
--  Synchronous Required Interface "newTmNoInherit"
------------------------------------------------------ */
void vm_st05_newTmNoInherit(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getNextEvent"
------------------------------------------------------ */
void vm_st05_getNextEvent(void *actualCounter, size_t actualCounter_len, void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getApid"
------------------------------------------------------ */
void vm_st05_getApid(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount"
------------------------------------------------------ */
void vm_st05_getSequenceCount(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_st05_check_queue(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "incCount_vt"
------------------------------------------------------ */
void vm_st05_incCount_vt(void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "newTm_vt"
------------------------------------------------------ */
void vm_st05_newTm_vt(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount_vt"
------------------------------------------------------ */
void vm_st05_getSequenceCount_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getApid_vt"
------------------------------------------------------ */
void vm_st05_getApid_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "ACK_vt"
------------------------------------------------------ */
void vm_st05_ACK_vt(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_st05_check_queue_vt(void *, size_t *);
#endif
