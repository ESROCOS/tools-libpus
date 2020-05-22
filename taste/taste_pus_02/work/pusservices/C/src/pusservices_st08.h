/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/*
 * Functions to process PUS 8 TCs
 */

#ifndef PUSSERVICES_ST08
#define PUSSERVICES_ST08

#include "pusservices_config.h"

#ifdef __cplusplus
extern "C" {
#endif

void pusservices_initService08(void);

void pusservices_processTc08(const pusPacket_t *tcPacket);

#ifdef __cplusplus
}
#endif

#endif
