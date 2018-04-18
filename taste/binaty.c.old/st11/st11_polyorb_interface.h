/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef st11_POLYORB_INTERFACE
#define st11_POLYORB_INTERFACE
#include <stddef.h>

#include "types.h"
#include "deployment.h"
#include "po_hi_transport.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../tcdispatch/tcdispatch_polyorb_interface.h"
/*----------------------------------------------------
-- Protected Provided Interface "tc11"
----------------------------------------------------*/
void sync_st11_tc11(void *, size_t);

/* ------------------------------------------------------
--  Synchronous Required Interface "ACK"
------------------------------------------------------ */
void vm_st11_ACK(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc"
------------------------------------------------------ */
void vm_async_st11_newTc(void *tcPacket, size_t tcPacket_len);
#endif
