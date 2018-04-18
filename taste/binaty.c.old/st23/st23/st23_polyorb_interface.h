/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef st23_POLYORB_INTERFACE
#define st23_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../filemanagement/filemanagement_polyorb_interface.h"
#include "../../filemanagement/filemanagement_polyorb_interface.h"
#include "../../filemanagement/filemanagement_polyorb_interface.h"
#include "../../filemanagement/filemanagement_polyorb_interface.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "tc23"
----------------------------------------------------*/
void sync_st23_tc23();

/* ------------------------------------------------------
--  Synchronous Required Interface "copy"
------------------------------------------------------ */
void vm_st23_copy();
/* ------------------------------------------------------
--  Synchronous Required Interface "delete"
------------------------------------------------------ */
void vm_st23_delete();
/* ------------------------------------------------------
--  Synchronous Required Interface "create"
------------------------------------------------------ */
void vm_st23_create();
/* ------------------------------------------------------
--  Synchronous Required Interface "getAttributes"
------------------------------------------------------ */
void vm_st23_getAttributes();
/* ------------------------------------------------------
--  Synchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_st23_newTm(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getApid"
------------------------------------------------------ */
void vm_st23_getApid(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount"
------------------------------------------------------ */
void vm_st23_getSequenceCount(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st23_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
#endif
