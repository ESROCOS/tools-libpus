/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef tcqueue_POLYORB_INTERFACE
#define tcqueue_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "newTc"
----------------------------------------------------*/
void sync_tcqueue_newTc(void *, size_t);

/*----------------------------------------------------
-- Protected Provided Interface "tcRequest"
----------------------------------------------------*/
void sync_tcqueue_tcRequest(void *, size_t *, void *, size_t *);

/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_tcqueue_check_queue(void *, size_t *);
#endif
