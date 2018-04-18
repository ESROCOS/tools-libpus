/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef vt_ground_newtm_POLYORB_INTERFACE
#define vt_ground_newtm_POLYORB_INTERFACE
#include <stddef.h>

#include "types.h"
#include "deployment.h"
#include "po_hi_transport.h"
#include "../../ground/ground_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
/*----------------------------------------------------
-- Asynchronous Provided Interface "artificial_newTm"
----------------------------------------------------*/
void po_hi_c_vt_ground_newtm_artificial_newtm(__po_hi_task_id, dataview__puspacket_buffer_impl);

/* ------------------------------------------------------
--  Synchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_vt_ground_newtm_newTm(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc_vt"
------------------------------------------------------ */
void vm_async_vt_ground_newtm_newTc_vt(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_ground_newtm_check_queue_vt(void *, size_t *);
#endif
