/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/*
 * Functions to generate PUS 3 TMs
 */

#ifndef PUSSERVICES_ST03
#define PUSSERVICES_ST03

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void pusservices_initService03(void);

void pusservices_st03HkReportTrigger(void);

void pusservices_processTc03(const pusPacket_t *tcPacket);

#ifdef __cplusplus
}
#endif


#endif

