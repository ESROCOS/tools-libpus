/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef st20_POLYORB_INTERFACE
#define st20_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../onboardparams/onboardparams_polyorb_interface.h"
#include "../../onboardparams/onboardparams_polyorb_interface.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "tc20"
----------------------------------------------------*/
void sync_st20_tc20(void *, size_t);

/* ------------------------------------------------------
--  Synchronous Required Interface "setOnBoardParam"
------------------------------------------------------ */
void vm_st20_setOnBoardParam(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getOnBoardParam"
------------------------------------------------------ */
void vm_st20_getOnBoardParam(void *paramId, size_t paramId_len, void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "newTm"
------------------------------------------------------ */
void vm_st20_newTm(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st20_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getApid"
------------------------------------------------------ */
void vm_st20_getApid(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount"
------------------------------------------------------ */
void vm_st20_getSequenceCount(void *, size_t *);
#endif
