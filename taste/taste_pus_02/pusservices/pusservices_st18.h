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

void pusservices_initService018(void);

void st18_tc18(const asn1SccPusPacket *);

/*extern void st18_RI_ACK(const asn1SccPusPacket *,
                        const asn1SccPusSubserviceType *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *,
                        const asn1SccPusStepId *);*/

#ifdef __cplusplus
}
#endif


#endif
