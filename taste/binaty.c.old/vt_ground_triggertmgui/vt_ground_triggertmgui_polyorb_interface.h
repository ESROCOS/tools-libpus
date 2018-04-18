/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef vt_ground_triggertmgui_POLYORB_INTERFACE
#define vt_ground_triggertmgui_POLYORB_INTERFACE
#include <stddef.h>

#include "types.h"
#include "deployment.h"
#include "po_hi_transport.h"
#include "../../ground/ground_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
/*----------------------------------------------------
-- Asynchronous Provided Interface "artificial_triggerTmGUI"
----------------------------------------------------*/
void po_hi_c_vt_ground_triggertmgui_artificial_triggertmgui(__po_hi_task_id);

/* ------------------------------------------------------
--  Synchronous Required Interface "triggerTmGUI"
------------------------------------------------------ */
void vm_vt_ground_triggertmgui_triggerTmGUI();
/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc_vt"
------------------------------------------------------ */
void vm_async_vt_ground_triggertmgui_newTc_vt(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_vt_ground_triggertmgui_check_queue_vt(void *, size_t *);
#endif
