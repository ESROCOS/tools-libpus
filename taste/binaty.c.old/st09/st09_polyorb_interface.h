/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef st09_POLYORB_INTERFACE
#define st09_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../timereportapid/timereportapid_polyorb_interface.h"
#include "../../timereportapid/timereportapid_polyorb_interface.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
#include "../../tmdispatch/tmdispatch_polyorb_interface.h"
#include "../../vt_st19_eventactiontrigger/vt_st19_eventactiontrigger_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "incCount"
----------------------------------------------------*/
void sync_st09_incCount(void *, size_t *, void *, size_t *);

/*----------------------------------------------------
-- Protected Provided Interface "tc09"
----------------------------------------------------*/
void sync_st09_tc09(void *, size_t);

/* ------------------------------------------------------
--  Synchronous Required Interface "getApid"
------------------------------------------------------ */
void vm_st09_getApid(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount"
------------------------------------------------------ */
void vm_st09_getSequenceCount(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st09_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
#endif
