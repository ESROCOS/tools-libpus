/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "st23_vm_if.h"

#include "st23.h"

#include "C_ASN1_Types.h"

void init_st23()
{
    static int init = 0;

    if (!init) {
        init = 1;
        st23_startup();
        extern void init_filemanagement();
        init_filemanagement();
        extern void init_filemanagement();
        init_filemanagement();
        extern void init_filemanagement();
        init_filemanagement();
        extern void init_filemanagement();
        init_filemanagement();
        extern void init_tmqueue();
        init_tmqueue();
        extern void init_onboardapid();
        init_onboardapid();
        extern void init_onboardapid();
        init_onboardapid();
        extern void init_st01();
        init_st01();
    }
}

void st23_tc23 ()
{
    /* Call to User-defined function */
    st23_PI_tc23 ();

}
