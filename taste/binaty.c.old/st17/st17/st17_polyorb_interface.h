/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef st17_POLYORB_INTERFACE
#define st17_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "tc17"
----------------------------------------------------*/
void sync_st17_tc17(void *, size_t);

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st17_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getApid"
------------------------------------------------------ */
void vm_st17_getApid(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount"
------------------------------------------------------ */
void vm_st17_getSequenceCount(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_st17_newTm(void *tmPacket, size_t tmPacket_len);
#endif
