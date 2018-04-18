/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "onboardsoftware_vm_if.h"

#include "onboardsoftware.h"

#include "C_ASN1_Types.h"

void init_onboardsoftware()
{
    static int init = 0;

    if (!init) {
        init = 1;
        onboardsoftware_startup();
        extern void init_housekeeping();
        init_housekeeping();
        extern void init_housekeeping();
        init_housekeeping();
        extern void init_events();
        init_events();
        extern void init_onboardparams();
        init_onboardparams();
        extern void init_onboardparams();
        init_onboardparams();
        extern void init_x86_partition_taste_api();
        init_x86_partition_taste_api();
        extern void init_x86_partition_taste_api();
        init_x86_partition_taste_api();
    }
}

void onboardsoftware_debugTrigger ()
{
    /* Call to User-defined function */
    onboardsoftware_PI_debugTrigger ();

}
