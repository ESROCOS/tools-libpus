/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef tcdispatch_POLYORB_INTERFACE
#define tcdispatch_POLYORB_INTERFACE
#include <stddef.h>

#include "types.h"
#include "deployment.h"
#include "po_hi_transport.h"
#include "../../tcqueue/tcqueue_polyorb_interface.h"
#include "../../st17/st17_polyorb_interface.h"
#include "../../st08/st08_polyorb_interface.h"
#include "../../st19/st19_polyorb_interface.h"
#include "../../st09/st09_polyorb_interface.h"
#include "../../st12/st12_polyorb_interface.h"
#include "../../st11/st11_polyorb_interface.h"
#include "../../st18/st18_polyorb_interface.h"
#include "../../st23/st23_polyorb_interface.h"
#include "../../st20/st20_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../x86_partition_taste_api/x86_partition_taste_api_polyorb_interface.h"
#include "../../st09/st09_polyorb_interface.h"
#include "../../st01/st01_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../onboardapid/onboardapid_polyorb_interface.h"
#include "../../tmqueue/tmqueue_polyorb_interface.h"
#include "../../events/events_polyorb_interface.h"
#include "../../events/events_polyorb_interface.h"
#include "../../housekeeping/housekeeping_polyorb_interface.h"
#include "../../obcpengine/obcpengine_polyorb_interface.h"
#include "../../obcpengine/obcpengine_polyorb_interface.h"
#include "../../onboardparams/onboardparams_polyorb_interface.h"
#include "../../onboardparams/onboardparams_polyorb_interface.h"
#include "../../filemanagement/filemanagement_polyorb_interface.h"
#include "../../filemanagement/filemanagement_polyorb_interface.h"
#include "../../filemanagement/filemanagement_polyorb_interface.h"
#include "../../filemanagement/filemanagement_polyorb_interface.h"
/*----------------------------------------------------
-- Asynchronous Provided Interface "tcTrigger"
----------------------------------------------------*/
void po_hi_c_tcdispatch_tctrigger(__po_hi_task_id);

/* ------------------------------------------------------
--  Synchronous Required Interface "tcRequest"
------------------------------------------------------ */
void vm_tcdispatch_tcRequest(void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "tc17"
------------------------------------------------------ */
void vm_tcdispatch_tc17(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "tc08"
------------------------------------------------------ */
void vm_tcdispatch_tc08(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "tc19"
------------------------------------------------------ */
void vm_tcdispatch_tc19(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "tc09"
------------------------------------------------------ */
void vm_tcdispatch_tc09(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "tc12"
------------------------------------------------------ */
void vm_tcdispatch_tc12(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "tc11"
------------------------------------------------------ */
void vm_tcdispatch_tc11(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "tc18"
------------------------------------------------------ */
void vm_tcdispatch_tc18(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "tc23"
------------------------------------------------------ */
void vm_tcdispatch_tc23();
/* ------------------------------------------------------
--  Synchronous Required Interface "tc20"
------------------------------------------------------ */
void vm_tcdispatch_tc20(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue"
------------------------------------------------------ */
void vm_tcdispatch_check_queue(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "check_queue_vt"
------------------------------------------------------ */
void vm_tcdispatch_check_queue_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "incCount_vt"
------------------------------------------------------ */
void vm_tcdispatch_incCount_vt(void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "ACK_vt"
------------------------------------------------------ */
void vm_tcdispatch_ACK_vt(void *tcPacket, size_t tcPacket_len, void *reportType, size_t reportType_len, void *error, size_t error_len, void *errorInfo, size_t errorInfo_len, void *step, size_t step_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getApid_vt"
------------------------------------------------------ */
void vm_tcdispatch_getApid_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "getSequenceCount_vt"
------------------------------------------------------ */
void vm_tcdispatch_getSequenceCount_vt(void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "newTm_vt"
------------------------------------------------------ */
void vm_tcdispatch_newTm_vt(void *tmPacket, size_t tmPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getNextEvent_vt"
------------------------------------------------------ */
void vm_tcdispatch_getNextEvent_vt(void *actualCounter, size_t actualCounter_len, void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Asynchronous Required Interface "newTc_vt"
------------------------------------------------------ */
void vm_async_tcdispatch_newTc_vt(void *tcPacket, size_t tcPacket_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "pushNewEvent_vt"
------------------------------------------------------ */
void vm_tcdispatch_pushNewEvent_vt(void *eventInfo, size_t eventInfo_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getParamValue_vt"
------------------------------------------------------ */
void vm_tcdispatch_getParamValue_vt(void *paramId, size_t paramId_len, void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "loadDirect_vt"
------------------------------------------------------ */
void vm_tcdispatch_loadDirect_vt(void *obcpId, size_t obcpId_len, void *obcpCode, size_t obcpCode_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "loadReference_vt"
------------------------------------------------------ */
void vm_tcdispatch_loadReference_vt(void *referenceData, size_t referenceData_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "getOnBoardParam_vt"
------------------------------------------------------ */
void vm_tcdispatch_getOnBoardParam_vt(void *paramId, size_t paramId_len, void *, size_t *, void *, size_t *);
/* ------------------------------------------------------
--  Synchronous Required Interface "setOnBoardParam_vt"
------------------------------------------------------ */
void vm_tcdispatch_setOnBoardParam_vt(void *paramId, size_t paramId_len, void *paramValue, size_t paramValue_len);
/* ------------------------------------------------------
--  Synchronous Required Interface "copy_vt"
------------------------------------------------------ */
void vm_tcdispatch_copy_vt();
/* ------------------------------------------------------
--  Synchronous Required Interface "delete_vt"
------------------------------------------------------ */
void vm_tcdispatch_delete_vt();
/* ------------------------------------------------------
--  Synchronous Required Interface "create_vt"
------------------------------------------------------ */
void vm_tcdispatch_create_vt();
/* ------------------------------------------------------
--  Synchronous Required Interface "getAttributes_vt"
------------------------------------------------------ */
void vm_tcdispatch_getAttributes_vt();
#endif
