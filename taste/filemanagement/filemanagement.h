/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_filemanagement__
#define __USER_CODE_H_filemanagement__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void filemanagement_startup();

void filemanagement_PI_copy(const asn1SccPusSt23RepositoryPath *,
                            const asn1SccPusSt23FileName *,
                            const asn1SccPusSt23RepositoryPath *,
                            const asn1SccPusSt23FileName *,
                            asn1SccPusSt01FailureCode *);

void filemanagement_PI_delete(const asn1SccPusSt23RepositoryPath *,
                              const asn1SccPusSt23FileName *,
                              asn1SccPusSt01FailureCode *);

void filemanagement_PI_create(const asn1SccPusSt23RepositoryPath *,
                              const asn1SccPusSt23FileName *,
                              const asn1SccPusUInt64 *,
                              asn1SccPusSt01FailureCode *);

void filemanagement_PI_getAttributes(const asn1SccPusSt23RepositoryPath *,
                                     const asn1SccPusSt23FileName *,
                                     asn1SccPusUInt64 *,
                                     asn1SccPusSt01FailureCode *);

#ifdef __cplusplus
}
#endif


#endif
