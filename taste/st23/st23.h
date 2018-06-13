/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_st23__
#define __USER_CODE_H_st23__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void st23_startup();

void st23_PI_tc23(const asn1SccPusPacket *);

extern void st23_RI_copy(const asn1SccPusSt23RepositoryPath *,
                         const asn1SccPusSt23FileName *,
                         const asn1SccPusSt23RepositoryPath *,
                         const asn1SccPusSt23FileName *,
                         asn1SccPusSt01FailureCode *);

extern void st23_RI_delete(const asn1SccPusSt23RepositoryPath *,
                           const asn1SccPusSt23FileName *,
                           asn1SccPusSt01FailureCode *);

extern void st23_RI_create(const asn1SccPusSt23RepositoryPath *,
                           const asn1SccPusSt23FileName *,
                           const asn1SccPusUInt64 *,
                           asn1SccPusSt01FailureCode *);

extern void st23_RI_getAttributes(const asn1SccPusSt23RepositoryPath *,
                                  const asn1SccPusSt23FileName *,
                                  asn1SccPusUInt64 *,
                                  asn1SccPusSt01FailureCode *);

extern void st23_RI_newTm(const asn1SccPusPacket *);

extern void st23_RI_getApid(asn1SccPusApid *);

extern void st23_RI_getSequenceCount(asn1SccPusSequenceCount *);

extern void st23_RI_ACK(const asn1SccPusPacket *,
                        const asn1SccPusSubserviceType *,
                        const asn1SccPusSt01FailureCode *,
                        const asn1SccPusSt01FailureInfo *,
                        const asn1SccPusStepId *);

#ifdef __cplusplus
}
#endif


#endif
