/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef st19_POLYORB_INTERFACE
#define st19_POLYORB_INTERFACE
#include <stddef.h>

#include "types.h"
#include "deployment.h"
#include "po_hi_transport.h"
#include "../../events/events_polyorb_interface.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
#include "../../vt_st19_eventactiontrigger/vt_st19_eventactiontrigger_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "tc19"
----------------------------------------------------*/
void sync_st19_tc19(void *, size_t);

/*----------------------------------------------------
-- Protected Provided Interface "EventActionTrigger"
----------------------------------------------------*/
void sync_st19_EventActionTrigger();

/* ------------------------------------------------------
--  Synchronous Required Interface "getNextEvent"
------------------------------------------------------ */
void vm_st19_getNextEvent(void *actualCounter, size_t actualCounter_len, void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st19_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_st19_newTm(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc"
------------------------------------------------------ */
void vm_async_st19_newTc(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_st19_check_queue(void *, size_t *);
#endif
