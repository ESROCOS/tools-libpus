/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */ 
 
#include <stdio.h>
#include "pus_error.h"

pusError_t example_function()
{
    printf("  - Hello world! -  (Function0)\n");
    return PUS_NO_ERROR;
}

pusError_t example_function2()
{
    printf("Hello from function1\n");
    return PUS_NO_ERROR;
}

pusError_t example_function3()
{
    printf("Hello from function2\n");
    return PUS_NO_ERROR;
}

