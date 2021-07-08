/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
 
/*Functions to generate new Events PUS05*/ 

#ifndef PUSSERVICES_ST05
#define PUSSERVIICES_ST05

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void pusservices_initService05(void);

void pusservices_st05_EventReportTrigger(void);


/*extern void st05_RI_newTmNoInherit(const asn1SccPusPacket *);

extern void st05_RI_getNextEvent(const asn1SccPusUInt64 *,
                                 asn1SccPusSt05Event *,
                                 asn1SccPusUInt64 *);

extern void st05_RI_getApid(asn1SccPusApid *);

extern void st05_RI_getSequenceCount(asn1SccPusSequenceCount *);*/

#ifdef __cplusplus
}
#endif


#endif
