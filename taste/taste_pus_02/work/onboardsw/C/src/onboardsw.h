
/* Header file for function OnBoardSW in C language
 * Generated by TASTE on 2020-09-29 16:52:54
 * Context Parameters present : NO
 * Provided interfaces : trigger
 * Required interfaces : getOnBoardParam, getParamValue, pushNewEvent, setOnBoardParam, setParamValue
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 199364 64408 238261 91808
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

void onboardsw_startup(void);

/* Provided interfaces */
void onboardsw_PI_trigger( void );

/* Required interfaces */
extern void onboardsw_RI_getOnBoardParam( const asn1SccPusSt20OnBoardParameterId *, asn1SccPusSt20StoredParam *, asn1SccPusSt01FailureCode * );
extern void onboardsw_RI_getParamValue( const asn1SccPusSt03ParameterId *, asn1SccPusSt03StoredParam *, asn1SccPusSt01FailureCode * );
extern void onboardsw_RI_pushNewEvent( const asn1SccPusSt05Event * );
extern void onboardsw_RI_setOnBoardParam( const asn1SccPusSt20OnBoardParameterId *, const asn1SccPusSt20StoredParam * );
extern void onboardsw_RI_setParamValue( const asn1SccPusSt03ParameterId *, const asn1SccPusSt03StoredParam * );


#ifdef __cplusplus
}
#endif
