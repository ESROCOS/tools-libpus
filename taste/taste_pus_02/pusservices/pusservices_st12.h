/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef PUSSERVICES_ST12
#define PUSSERVICES_ST12

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void pusservices_initService12(void);

void pusservices_processTc12(const asn1SccPusPacket *);

void pusservices_st12_PmonTrigger(void);

/*extern void st12_RI_pushNewEvent(const asn1SccPusSt05Event *);

extern void st12_RI_getParamValue(const asn1SccPusSt03ParameterId *,
                                  asn1SccPusSt03StoredParam *,
                                  asn1SccPusSt01FailureCode *);

extern void st12_RI_ACK(const asn1SccPusPacket *,
                        const asn1SccPusSubserviceType *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *,
                        const asn1SccPusStepId *);*/

#ifdef __cplusplus
}
#endif


#endif
