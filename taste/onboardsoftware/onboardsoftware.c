/* User code: This file will not be overwritten by TASTE. */

#include "onboardsoftware.h"
#include <stdio.h>
#include "pus_error.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include "pus_st05_config.h"

void onboardsoftware_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void onboardsoftware_PI_debugTrigger()
{
    /* Write your code here! */
	int test = 0;

	switch(test)
	{
		case 0:
		{
			printf(" - ON BOARD SOFTWARE: Event raised\n");
			pusSt05Event_t event;
			pus_events_createEVENT_INFO_01(&event, 23, 54);
			onboardsoftware_RI_pushNewEvent(&event);
			break;
		}
		case 1:
		{

		}
		default:
			printf("No test\n");
	}


}

