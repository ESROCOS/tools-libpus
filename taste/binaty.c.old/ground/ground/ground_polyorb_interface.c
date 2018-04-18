#include "po_hi_gqueue.h"
/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "ground_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "ground_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "newTm"
----------------------------------------------------*/
void sync_ground_newTm(void *tmPacket, size_t tmPacket_len)
{
   extern process_package__taste_protected_object ground_protected;
   __po_hi_protected_lock (ground_protected.protected_id);
   ground_newTm(tmPacket, tmPacket_len);
   __po_hi_protected_unlock (ground_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "triggerTmGUI"
----------------------------------------------------*/
void sync_ground_triggerTmGUI()
{
   extern process_package__taste_protected_object ground_protected;
   __po_hi_protected_lock (ground_protected.protected_id);
   ground_triggerTmGUI();
   __po_hi_protected_unlock (ground_protected.protected_id);
}

/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc"
------------------------------------------------------ */
void vm_async_ground_newTc(void *tcPacket, size_t tcPacket_len)
{
   switch(__po_hi_get_task_id()) {
      case x86_partition_vt_ground_newtm_k: vm_async_vt_ground_newtm_newTc_vt(tcPacket, tcPacket_len); break;
      case x86_partition_vt_ground_triggertmgui_k: vm_async_vt_ground_triggertmgui_newTc_vt(tcPacket, tcPacket_len); break;
      default: break;
   }
}

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_ground_check_queue(void *res, size_t *res_len)
{
   sync_x86_partition_taste_api_ground_has_pending_msg(res, res_len);
}

