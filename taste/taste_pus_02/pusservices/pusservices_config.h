/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#ifndef PUSSERVICES_CONFIG
#define PUSSERVICES_CONFIG

#include <stdio.h>
#include "C_ASN1_Types.h"
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"


#ifdef __cplusplus
extern "C" {
#endif


#include "pus_error.h"


/*
 * This file enables the configuration of the PusServices TASTE 
 * function:
 * 
 * - Enable/disable the standard services
 * - Enable/disable dispatching of mission-specific services (other TC)
 * - Frequency and offset of activation of each function
 * - Number of TCs, events, etc. to process in each activation
 */


/* 
 * Enable flags for standard PUS services
 * (comment to disable the service)
 * Note thas PUS01 is always enabled for TC verification.
 */

#define PUSSERVICES_03_ENABLED
#define PUSSERVICES_05_ENABLED
#define PUSSERVICES_08_ENABLED
#define PUSSERVICES_09_ENABLED
#define PUSSERVICES_11_ENABLED
#define PUSSERVICES_12_ENABLED
#define PUSSERVICES_17_ENABLED
#define PUSSERVICES_18_ENABLED
#define PUSSERVICES_19_ENABLED
#define PUSSERVICES_20_ENABLED
#define PUSSERVICES_23_ENABLED


/*
 * Enable forwarding of TCs for mission-specific services
 * (comment to disable dispatching)
 * 
 * If enabled, services not provided by the library will be dispatched
 * by calling a user-provided function with the signature indicated 
 * below.
 * 
 * Where return value is 0 if TC can be dispatched (known service 
 * number, etc)
 */

//#define PUSSERVICES_DISPATCH_OTHER_TC_ENABLED


/*! Signature of user-provided function to dispatch mission-specific TCs
 * 
 * Function to be provided by the user.
 * 
 * Called by dispatch_tc if PUSSERVICES_DISPATCH_OTHER_TC_ENABLED defined.
 * Will normally call a user library function or TASTE PI.
 * 
 * Must return PUS_NO_ERROR if dispatch successful.
 */
pusError_t pusservices_dispatchOtherTc(const asn1SccPusPacket *tcPacket);


/*! Signature of the function to initialize mission-specific services
 *
 * Function to be provided by the user.
 * 
 * Called by pusservices_startup if PUSSERVICES_DISPATCH_OTHER_TC_ENABLED 
 * defined.
 */
void pusservices_initOtherServices(void);


/*
 * Define the frequency of activation for each function
 * 
 * Each function is activated every FREQUENCY x triggerPus frequency,
 * with an offset of OFFSET x triggerPus frequency
 * (triggerPus is the cyclic PI of the PusServices TASTE function).
 * 
 * At each activation, when applicable, COUNT elements are processed.
 */

/* Process TCs */
#define PUSSERVICES_TC_FREQUENCY 1
#define PUSSERVICES_TC_OFFSET 0
#define PUSSERVICES_TC_COUNT 1

/* PUS service 11 */
#define PUSSERVICES_PUS11_FREQUENCY 1
#define PUSSERVICES_PUS11_OFFSET 0
#define PUSSERVICES_PUS11_COUNT 1



/* Send TMs */
#define PUSSERVICES_TM_FREQUENCY 1
#define PUSSERVICES_TM_OFFSET 0
#define PUSSERVICES_TM_COUNT 3


/* PUS09 Time Report generation: generate 1 PUS[9,2] Time Report every 2^N TMs */
#define PUSSERVICES_TIME_REPORT_EXP_RATE 3


#ifdef __cplusplus
}
#endif

#endif
