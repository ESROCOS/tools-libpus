/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/*
 * Functions to process PUS 11 TCs
 */

#ifndef PUSSERVICES_ST11
#define PUSSERVICES_ST11

#include "pusservices_config.h"

#ifdef __cplusplus
extern "C" {
#endif

void pusservices_initService11(void);

void pusservices_processTc11(const pusPacket_t *tcPacket);

pusError_t pusservices_st11runNextTc();

#ifdef __cplusplus
}
#endif

#endif
