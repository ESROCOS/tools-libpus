/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef vt_tcqueue_newtc_POLYORB_INTERFACE
#define vt_tcqueue_newtc_POLYORB_INTERFACE
#include <stddef.h>

#include "types.h"
#include "deployment.h"
#include "po_hi_transport.h"
#include "../../tcqueue/tcqueue_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
/*----------------------------------------------------
-- Asynchronous Provided Interface "artificial_newTc"
----------------------------------------------------*/
void po_hi_c_vt_tcqueue_newtc_artificial_newtc(__po_hi_task_id, dataview__puspacket_buffer_impl);

/* ------------------------------------------------------
--  Synchronous Required Interface "newTc"
------------------------------------------------------ */
void vm_vt_tcqueue_newtc_newTc(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_tcqueue_newtc_check_queue_vt(void *, size_t *);
#endif
