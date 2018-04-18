/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef tmdispatch_POLYORB_INTERFACE
#define tmdispatch_POLYORB_INTERFACE
#include <stddef.h>

#include "types.h"
#include "deployment.h"
#include "po_hi_transport.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../st09/st09_polyorb_interface.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../st01/st01_polyorb_interface.h"
/*----------------------------------------------------
-- Asynchronous Provided Interface "tmTrigger"
----------------------------------------------------*/
void po_hi_c_tmdispatch_tmtrigger(__po_hi_task_id);

/* ------------------------------------------------------
--  Asynchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_async_tmdispatch_newTm(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "tmRequest"
------------------------------------------------------ */
void vm_tmdispatch_tmRequest(void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_tmdispatch_check_queue(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "incCount_vt"
------------------------------------------------------ */
void vm_tmdispatch_incCount_vt(void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "newTm_vt"
------------------------------------------------------ */
void vm_tmdispatch_newTm_vt(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount_vt"
------------------------------------------------------ */
void vm_tmdispatch_getSequenceCount_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getApid_vt"
------------------------------------------------------ */
void vm_tmdispatch_getApid_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "ACK_vt"
------------------------------------------------------ */
void vm_tmdispatch_ACK_vt(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
#endif
