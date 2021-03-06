/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/*
 * Functions to process PUS 17 TCs
 */

#ifndef PUSSERVICES_ST17
#define PUSSERVICES_ST17

#include "pusservices_config.h"

#ifdef __cplusplus
extern "C" {
#endif

void pusservices_initService17(void);

void pusservices_processTc17(const pusPacket_t *tcPacket);

#ifdef __cplusplus
}
#endif

#endif
