#include "functions.h"

#include <stdio.h>
#include "pus_types.h"
#include "pus_error.h"

pusError_t example_function()
{
	printf("Hello from function1 !!!!!!!!!!!!!!!!!!!!!!!!!\n");

	return PUS_NO_ERROR;
}

pusError_t example_function2()
{
	printf("Hello from function2\n");
	return PUS_NO_ERROR;
}

pusError_t example_function3()
{
	printf("Hello from function3\n");
	return PUS_NO_ERROR;
}
