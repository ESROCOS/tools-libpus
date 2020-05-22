/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/*
 * Functions to manage the APID
 */

#ifndef PUSSERVICES_APID
#define PUSSERVICES_APID

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void pusservices_initApid(asn1SccPusApid apid);

asn1SccPusApid pusservices_getApid(void);

asn1SccPusSequenceCount pusservices_getTmSequenceCount(void);


#ifdef __cplusplus
}
#endif

#endif
