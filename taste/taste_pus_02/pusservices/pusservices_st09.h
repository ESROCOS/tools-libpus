/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/*
 * Functions to implement PUS 9 Time Service
 */

#ifndef PUSSERVICES_ST09
#define PUSSERVICES_ST09

#include "pusservices_config.h"

#ifdef __cplusplus
extern "C" {
#endif


void pusservices_initService09(void);

void pusservices_st09notifyTm(void);

void pusservices_processTc09(const pusPacket_t *tcPacket);

#ifdef __cplusplus
}
#endif

#endif
