/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef onboardapid_POLYORB_INTERFACE
#define onboardapid_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
#include "../../tmdispatch/tmdispatch_polyorb_interface.h"
#include "../../vt_st19_eventactiontrigger/vt_st19_eventactiontrigger_polyorb_interface.h"
/*----------------------------------------------------
-- Unprotected Provided Interface "getApid"
----------------------------------------------------*/
void sync_onboardapid_getApid(void *, size_t *);

/*----------------------------------------------------
-- Protected Provided Interface "getSequenceCount"
----------------------------------------------------*/
void sync_onboardapid_getSequenceCount(void *, size_t *);

#endif
