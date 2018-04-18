/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "tcdispatch_vm_if.h"

#include "tcdispatch.h"

#include "C_ASN1_Types.h"

void init_tcdispatch()
{
    static int init = 0;

    if (!init) {
        init = 1;
        tcdispatch_startup();
        extern void init_tcqueue();
        init_tcqueue();
        extern void init_st17();
        init_st17();
        extern void init_st08();
        init_st08();
        extern void init_st19();
        init_st19();
        extern void init_st09();
        init_st09();
        extern void init_st12();
        init_st12();
        extern void init_st11();
        init_st11();
        extern void init_st18();
        init_st18();
        extern void init_st23();
        init_st23();
        extern void init_st20();
        init_st20();
        extern void init_x86_partition_taste_api();
        init_x86_partition_taste_api();
        extern void init_x86_partition_taste_api();
        init_x86_partition_taste_api();
        extern void init_st09();
        init_st09();
        extern void init_st01();
        init_st01();
        extern void init_onboardapid();
        init_onboardapid();
        extern void init_onboardapid();
        init_onboardapid();
        extern void init_tmqueue();
        init_tmqueue();
        extern void init_events();
        init_events();
        extern void init_events();
        init_events();
        extern void init_housekeeping();
        init_housekeeping();
        extern void init_obcpengine();
        init_obcpengine();
        extern void init_obcpengine();
        init_obcpengine();
        extern void init_onboardparams();
        init_onboardparams();
        extern void init_onboardparams();
        init_onboardparams();
        extern void init_filemanagement();
        init_filemanagement();
        extern void init_filemanagement();
        init_filemanagement();
        extern void init_filemanagement();
        init_filemanagement();
        extern void init_filemanagement();
        init_filemanagement();
    }
}

void tcdispatch_tcTrigger ()
{
    /* Call to User-defined function */
    tcdispatch_PI_tcTrigger ();

}
