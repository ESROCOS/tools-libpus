
/* Header file for function PusServices in C language
 * Generated by TASTE on 2020-09-29 16:52:54
 * Context Parameters present : YES
 * Provided interfaces : ack, addTc, addTm, getOnBoardParam, getParamValue, newTc, pushNewEvent, setOnBoardParam, setParamValue, trigger
 * Required interfaces : forwardTc, newTm
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 133885 62204 179396 91179
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __unix__
   #include <stdlib.h>
   #include <stdio.h>
#endif

void pusservices_startup(void);

/* Provided interfaces */
void pusservices_PI_ack( const asn1SccPusPacket *, const asn1SccPusSubserviceType *, const asn1SccPusSt01FailureCode *, const asn1SccPusSt01FailureInfo *, const asn1SccPusStepId * );
void pusservices_PI_addTc( const asn1SccPusPacket * );
void pusservices_PI_addTm( const asn1SccPusPacket * );
void pusservices_PI_getOnBoardParam( const asn1SccPusSt20OnBoardParameterId *, asn1SccPusSt20StoredParam *, asn1SccPusSt01FailureCode * );
void pusservices_PI_getParamValue( const asn1SccPusSt03ParameterId *, asn1SccPusSt03StoredParam *, asn1SccPusSt01FailureCode * );
void pusservices_PI_newTc( const asn1SccPusPacket * );
void pusservices_PI_pushNewEvent( const asn1SccPusSt05Event * );
void pusservices_PI_setOnBoardParam( const asn1SccPusSt20OnBoardParameterId *, const asn1SccPusSt20StoredParam * );
void pusservices_PI_setParamValue( const asn1SccPusSt03ParameterId *, const asn1SccPusSt03StoredParam * );
void pusservices_PI_trigger( void );

/* Required interfaces */
extern void pusservices_RI_forwardTc( const asn1SccPusPacket * );
extern void pusservices_RI_newTm( const asn1SccPusPacket * );


#ifdef __cplusplus
}
#endif
