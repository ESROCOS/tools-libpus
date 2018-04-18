/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef obcpengine_POLYORB_INTERFACE
#define obcpengine_POLYORB_INTERFACE
#include <stddef.h>

#include "types.h"
#include "deployment.h"
#include "po_hi_transport.h"
#include "../../onboardparams/onboardparams_polyorb_interface.h"
#include "../../onboardparams/onboardparams_polyorb_interface.h"
#include "../../events/events_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "loadDirect"
----------------------------------------------------*/
void sync_obcpengine_loadDirect(void *, size_t, void *, size_t);

/*----------------------------------------------------
-- Protected Provided Interface "loadReference"
----------------------------------------------------*/
void sync_obcpengine_loadReference(void *, size_t);

/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc"
------------------------------------------------------ */
void vm_async_obcpengine_newTc(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getOnBoardParam"
------------------------------------------------------ */
void vm_obcpengine_getOnBoardParam(void *paramId, size_t paramId_len, void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "setOnBoardParam"
------------------------------------------------------ */
void vm_obcpengine_setOnBoardParam(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "pushNewEvent"
------------------------------------------------------ */
void vm_obcpengine_pushNewEvent(void *eventInfo, size_t eventInfo_len);
#endif
