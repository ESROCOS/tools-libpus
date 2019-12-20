/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/*
 * Functions to generate PUS 1 TMs
 */

#ifndef PUSSERVICES_ST01
#define PUSSERVICES_ST01

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif


void pusservices_initService01(void);

void pusservices_st01Ack(const asn1SccPusPacket *tcPacket, 
                         asn1SccPusSubserviceType reportType,
                         asn1SccPusSt01FailureCode error,
                         const asn1SccPusSt01FailureInfo *errorInfo,
                         asn1SccPusStepId step);


#ifdef __cplusplus
}
#endif

#endif
