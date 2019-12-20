/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_ground__
#define __USER_CODE_H_ground__

#include "C_ASN1_Types.h"

#ifdef __cplusplus
extern "C" {
#endif

void ground_startup();

void ground_PI_triggerTmGUI();

void ground_PI_newTm(const asn1SccPusPacket *);

extern void ground_RI_newTc(const asn1SccPusPacket *);

#ifdef __cplusplus
}
#endif


#endif
