/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef st18_POLYORB_INTERFACE
#define st18_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../obcpengine/obcpengine_polyorb_interface.h"
#include "../../obcpengine/obcpengine_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "tc18"
----------------------------------------------------*/
void sync_st18_tc18(void *, size_t);

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st18_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "loadDirect"
------------------------------------------------------ */
void vm_st18_loadDirect(void *obcpId, size_t obcpId_len, void *obcpCode, size_t obcpCode_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "loadReference"
------------------------------------------------------ */
void vm_st18_loadReference(void *referenceData, size_t referenceData_len);
#endif
