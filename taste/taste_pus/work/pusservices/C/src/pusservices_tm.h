/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/*
 * Functions to manage the APID
 */

#ifndef PUSSERVICES_TM
#define PUSSERVICES_TM

#include "pusservices_config.h"

#ifdef __cplusplus
extern "C" {
#endif


pusError_t pusservices_queueTm(const pusPacket_t *tmPacket);

void pusservices_sendNextTm(void);


#ifdef __cplusplus
}
#endif

#endif
