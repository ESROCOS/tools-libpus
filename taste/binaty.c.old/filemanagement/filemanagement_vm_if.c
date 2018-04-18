/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "filemanagement_vm_if.h"

#include "filemanagement.h"

void init_filemanagement()
{
    static int init = 0;

    if (!init) {
        init = 1;
        filemanagement_startup();
    }
}

void filemanagement_copy ()
{
    /* Call to User-defined function */
    filemanagement_PI_copy ();

}
void filemanagement_delete ()
{
    /* Call to User-defined function */
    filemanagement_PI_delete ();

}
void filemanagement_create ()
{
    /* Call to User-defined function */
    filemanagement_PI_create ();

}
void filemanagement_getAttributes ()
{
    /* Call to User-defined function */
    filemanagement_PI_getAttributes ();

}
