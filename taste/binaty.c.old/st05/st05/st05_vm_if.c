/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "st05_vm_if.h"

#include "st05.h"

#include "C_ASN1_Types.h"

void init_st05()
{
    static int init = 0;

    if (!init) {
        init = 1;
        st05_startup();
        extern void init_tmqueue();
        init_tmqueue();
        extern void init_events();
        init_events();
        extern void init_onboardapid();
        init_onboardapid();
        extern void init_onboardapid();
        init_onboardapid();
        extern void init_x86_partition_taste_api();
        init_x86_partition_taste_api();
        extern void init_st09();
        init_st09();
        extern void init_tmqueue();
        init_tmqueue();
        extern void init_onboardapid();
        init_onboardapid();
        extern void init_onboardapid();
        init_onboardapid();
        extern void init_st01();
        init_st01();
        extern void init_x86_partition_taste_api();
        init_x86_partition_taste_api();
    }
}

void st05_EventReportTrigger ()
{
    /* Call to User-defined function */
    st05_PI_EventReportTrigger ();

}
