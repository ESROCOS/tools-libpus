/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#ifndef PUSSERVICES_ST19
#define PUSSERVICES_ST19

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void pusservices_initService19(void);

void pusservices_processTc19(const asn1SccPusPacket *);

void pusservices_st19_EventActionTrigger(void);

/*extern void st19_RI_getNextEvent(const asn1SccPusUInt64 *,
                                 asn1SccPusSt05Event *,
                                 asn1SccPusUInt64 *);

extern void st19_RI_ACK(const asn1SccPusPacket *,
                        const asn1SccPusSubserviceType *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *,
                        const asn1SccPusStepId *);

extern void st19_RI_newTm(const asn1SccPusPacket *);

extern void st19_RI_newTc(const asn1SccPusPacket *);*/

#ifdef __cplusplus
}
#endif


#endif
