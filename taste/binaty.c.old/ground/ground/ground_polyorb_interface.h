/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef ground_POLYORB_INTERFACE
#define ground_POLYORB_INTERFACE
#include <stddef.h>

#include "types.h"
#include "deployment.h"
#include "po_hi_transport.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../vt_ground_newtm/vt_ground_newtm_polyorb_interface.h"
#include "../../vt_ground_triggertmgui/vt_ground_triggertmgui_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "newTm"
----------------------------------------------------*/
void sync_ground_newTm(void *, size_t);

/*----------------------------------------------------
-- Protected Provided Interface "triggerTmGUI"
----------------------------------------------------*/
void sync_ground_triggerTmGUI();

/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc"
------------------------------------------------------ */
void vm_async_ground_newTc(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_ground_check_queue(void *, size_t *);
#endif
