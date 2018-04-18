/* This file was generated automatically: DO NOT MODIFY IT ! */

#include "filemanagement_polyorb_interface.h"

#include "activity.h"
#include "types.h"
#include "po_hi_protected.h"

#include "po_hi_task.h"
#include "filemanagement_vm_if.h"

/*----------------------------------------------------
-- Protected Provided Interface "copy"
----------------------------------------------------*/
void sync_filemanagement_copy()
{
   extern process_package__taste_protected_object filemanagement_protected;
   __po_hi_protected_lock (filemanagement_protected.protected_id);
   filemanagement_copy();
   __po_hi_protected_unlock (filemanagement_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "delete"
----------------------------------------------------*/
void sync_filemanagement_delete()
{
   extern process_package__taste_protected_object filemanagement_protected;
   __po_hi_protected_lock (filemanagement_protected.protected_id);
   filemanagement_delete();
   __po_hi_protected_unlock (filemanagement_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "create"
----------------------------------------------------*/
void sync_filemanagement_create()
{
   extern process_package__taste_protected_object filemanagement_protected;
   __po_hi_protected_lock (filemanagement_protected.protected_id);
   filemanagement_create();
   __po_hi_protected_unlock (filemanagement_protected.protected_id);
}

/*----------------------------------------------------
-- Protected Provided Interface "getAttributes"
----------------------------------------------------*/
void sync_filemanagement_getAttributes()
{
   extern process_package__taste_protected_object filemanagement_protected;
   __po_hi_protected_lock (filemanagement_protected.protected_id);
   filemanagement_getAttributes();
   __po_hi_protected_unlock (filemanagement_protected.protected_id);
}

