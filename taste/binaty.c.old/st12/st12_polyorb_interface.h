/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef st12_POLYORB_INTERFACE
#define st12_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../events/events_polyorb_interface.h"
#include "../../housekeeping/housekeeping_polyorb_interface.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "PmonTrigger"
----------------------------------------------------*/
void sync_st12_PmonTrigger();

/*----------------------------------------------------
-- Protected Provided Interface "tc12"
----------------------------------------------------*/
void sync_st12_tc12(void *, size_t);

/* ------------------------------------------------------
--  Synchronous Required Interface "pushNewEvent"
------------------------------------------------------ */
void vm_st12_pushNewEvent(void *eventInfo, size_t eventInfo_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getParamValue"
------------------------------------------------------ */
void vm_st12_getParamValue(void *paramId, size_t paramId_len, void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st12_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_st12_check_queue(void *, size_t *);
#endif
