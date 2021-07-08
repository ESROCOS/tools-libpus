/* Header file for function PusServices in C language
 * Generated by TASTE on 2021-07-05 17:17:23
 * Context Parameters present : YES
 * Provided interfaces : ack, addTc, addTm, getOnBoardParam, getParamValue, newTc, pushNewEvent, setOnBoardParam, setParamValue, trigger
 * Required interfaces : forwardTc, newTm
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 133885 62204 179396 91179
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

/* The purpose of this file is to provide a wrapper around the user code,
 * with a single interface that is independent of the implementation language
 * of the function. The parameters of each PI are blackboxes encoded
 * in the form specified in the interface view (Native, uPER, or ACN)
*/

#pragma once
#if defined(__unix__) || defined (__MSP430__)
   #include <stdlib.h>
   #include <stdio.h>
#else
   typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "pusservices.h"

// Function initialization - calls user startup code of all dependent functions
void init_pusservices(void);


/* Provided interfaces */
void pusservices_ack
      (const char *IN_tcpacket, size_t IN_tcpacket_len,
       const char *IN_reporttype, size_t IN_reporttype_len,
       const char *IN_error, size_t IN_error_len,
       const char *IN_errorinfo, size_t IN_errorinfo_len,
       const char *IN_step, size_t IN_step_len);

void pusservices_addTc
      (const char *IN_tcpacket, size_t IN_tcpacket_len);

void pusservices_addTm
      (const char *IN_tmpacket, size_t IN_tmpacket_len);

void pusservices_getOnBoardParam
      (const char *IN_paramid, size_t IN_paramid_len,
       char *OUT_paramvalue, size_t *OUT_paramvalue_len,
       char *OUT_isavailable, size_t *OUT_isavailable_len);

void pusservices_getParamValue
      (const char *IN_paramid, size_t IN_paramid_len,
       char *OUT_paramvalue, size_t *OUT_paramvalue_len,
       char *OUT_isavailable, size_t *OUT_isavailable_len);

void pusservices_newTc
      (const char *IN_tcpacket, size_t IN_tcpacket_len);

void pusservices_pushNewEvent
      (const char *IN_eveninfo, size_t IN_eveninfo_len);

void pusservices_setOnBoardParam
      (const char *IN_paramid, size_t IN_paramid_len,
       const char *IN_paramvalue, size_t IN_paramvalue_len);

void pusservices_setParamValue
      (const char *IN_paramid, size_t IN_paramid_len,
       const char *IN_paramvalue, size_t IN_paramvalue_len);

void pusservices_trigger(void);


#ifdef __cplusplus
}
#endif
