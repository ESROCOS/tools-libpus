/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_obcpengine__
#define __USER_CODE_H_obcpengine__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void obcpengine_startup();

void obcpengine_PI_loadDirect(const asn1SccPusSt18ObcpId *,
                              const asn1SccPusSt18ObcpCode *);

void obcpengine_PI_loadReference(const asn1SccPusTC_18_13_Data *);

extern void obcpengine_RI_newTc(const asn1SccPusPacket *);

#ifdef __cplusplus
}
#endif


#endif
