/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_trigger
#define VM_IF_trigger

#ifdef __cplusplus
extern "C" {
#endif

#include "C_ASN1_Types.h"

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_trigger();

void trigger_HkReportTrigger ();
extern void trigger_PI_HkReportTrigger ();
void trigger_TmDispatchTrigger ();
extern void trigger_PI_TmDispatchTrigger ();
void trigger_EventActionTrigger ();
extern void trigger_PI_EventActionTrigger ();
void trigger_TcDispatchTrigger ();
extern void trigger_PI_TcDispatchTrigger ();
void trigger_PmonTrigger ();
extern void trigger_PI_PmonTrigger ();
void trigger_EventReportTrigger ();
extern void trigger_PI_EventReportTrigger ();
void trigger_debugEventTrigger ();
extern void trigger_PI_debugEventTrigger ();
#ifdef __cplusplus
}
#endif

#endif
