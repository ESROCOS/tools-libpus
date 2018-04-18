/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "trigger_vm_if.h"

#include "trigger.h"

#include "C_ASN1_Types.h"

void init_trigger()
{
    static int init = 0;

    if (!init) {
        init = 1;
        trigger_startup();
        extern void init_x86_partition_taste_api();
        init_x86_partition_taste_api();
    }
}

void trigger_HkReportTrigger ()
{
    /* Call to User-defined function */
    trigger_PI_HkReportTrigger ();

}
void trigger_TmDispatchTrigger ()
{
    /* Call to User-defined function */
    trigger_PI_TmDispatchTrigger ();

}
void trigger_EventActionTrigger ()
{
    /* Call to User-defined function */
    trigger_PI_EventActionTrigger ();

}
void trigger_TcDispatchTrigger ()
{
    /* Call to User-defined function */
    trigger_PI_TcDispatchTrigger ();

}
void trigger_PmonTrigger ()
{
    /* Call to User-defined function */
    trigger_PI_PmonTrigger ();

}
void trigger_EventReportTrigger ()
{
    /* Call to User-defined function */
    trigger_PI_EventReportTrigger ();

}
void trigger_debugEventTrigger ()
{
    /* Call to User-defined function */
    trigger_PI_debugEventTrigger ();

}
