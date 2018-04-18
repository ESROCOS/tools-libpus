/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef st01_POLYORB_INTERFACE
#define st01_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
#include "../../tmdispatch/tmdispatch_polyorb_interface.h"
#include "../../vt_st19_eventactiontrigger/vt_st19_eventactiontrigger_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "ACK"
----------------------------------------------------*/
void sync_st01_ACK(void *, size_t, void *, size_t, void *, size_t, void *, size_t, void *, size_t);

/* ------------------------------------------------------
--  Synchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_st01_newTm(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount"
------------------------------------------------------ */
void vm_st01_getSequenceCount(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getApid"
------------------------------------------------------ */
void vm_st01_getApid(void *, size_t *);
#endif
