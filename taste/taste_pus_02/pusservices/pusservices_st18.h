/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/*
 * Functions to process PUS 18 TCs
 */

#ifndef PUSSERVICES_ST18
#define PUSSERVICES_ST18

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void pusservices_initService18(void);

void pusservices_processTc18(const asn1SccPusPacket *);


#ifdef __cplusplus
}
#endif


#endif
