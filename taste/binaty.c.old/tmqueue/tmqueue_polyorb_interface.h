/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef tmqueue_POLYORB_INTERFACE
#define tmqueue_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../st09/st09_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
#include "../../tmdispatch/tmdispatch_polyorb_interface.h"
#include "../../vt_st19_eventactiontrigger/vt_st19_eventactiontrigger_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "tmRequest"
----------------------------------------------------*/
void sync_tmqueue_tmRequest(void *, size_t *, void *, size_t *);

/*----------------------------------------------------
-- Protected Provided Interface "newTm"
----------------------------------------------------*/
void sync_tmqueue_newTm(void *, size_t);

/* ------------------------------------------------------
--  Synchronous Required Interface "incCount"
------------------------------------------------------ */
void vm_tmqueue_incCount(void *, size_t *, void *, size_t *);
#endif
