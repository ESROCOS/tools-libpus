/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef st08_POLYORB_INTERFACE
#define st08_POLYORB_INTERFACE
#include <stddef.h>

#include "deployment.h"
#include "po_hi_transport.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "tc08"
----------------------------------------------------*/
void sync_st08_tc08(void *, size_t);

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st08_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
#endif
