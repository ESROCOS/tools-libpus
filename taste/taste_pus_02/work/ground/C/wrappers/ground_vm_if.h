/* Header file for function Ground in C language
 * Generated by TASTE on 2020-09-29 16:52:54
 * Context Parameters present : NO
 * Provided interfaces : newTm, triggerTmGUI
 * Required interfaces : newTc
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 79368 65667 105509 89131
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

#include "ground.h"

// Function initialization - calls user startup code of all dependent functions
void init_ground(void);


/* Provided interfaces */
void ground_newTm
      (const char *IN_tmpacket, size_t IN_tmpacket_len);

void ground_triggerTmGUI(void);


#ifdef __cplusplus
}
#endif

