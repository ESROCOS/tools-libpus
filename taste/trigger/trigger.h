/* This file was generated automatically: DO NOT MODIFY IT ! */

/* Declaration of the functions that have to be provided by the user */

#ifndef __USER_CODE_H_trigger__
#define __USER_CODE_H_trigger__

#ifdef __cplusplus
extern "C" {
#endif

void trigger_startup();

void trigger_PI_HkReportTrigger();

void trigger_PI_TmDispatchTrigger();

void trigger_PI_EventActionTrigger();

void trigger_PI_TcDispatchTrigger();

void trigger_PI_PmonTrigger();

void trigger_PI_EventReportTrigger();

void trigger_PI_debugEventTrigger();

extern void trigger_RI_tmTrigger();

extern void trigger_RI_HkReportTrigger();

extern void trigger_RI_PmonTrigger();

extern void trigger_RI_EventReportTrigger();

extern void trigger_RI_tcTrigger();

extern void trigger_RI_debugEventsTrigger();

extern void trigger_RI_EventActionTrigger();

#ifdef __cplusplus
}
#endif


#endif
