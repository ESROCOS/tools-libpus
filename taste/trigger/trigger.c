/* User code: This file will not be overwritten by TASTE. */

#include "trigger.h"

void trigger_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void trigger_PI_TmDispatchTrigger()
{
    /* Write your code here! */
    trigger_RI_tmTrigger();
}

void trigger_PI_TcDispatchTrigger()
{
    /* Write your code here! */
    trigger_RI_tcTrigger();
}

void trigger_PI_PmonTrigger()
{
    /* Write your code here! */
	//return;
    trigger_RI_PmonTrigger();
}

void trigger_PI_HkReportTrigger()
{
    /* Write your code here! */
    trigger_RI_HkReportTrigger();
}

void trigger_PI_EventReportTrigger()
{
    /* Write your code here! */

	trigger_RI_EventReportTrigger();
}

void trigger_PI_EventActionTrigger()
{
    /* Write your code here! */
	//return;

    trigger_RI_EventActionTrigger();
}

void trigger_PI_debugEventTrigger()
{
    /* Write your code here! */
	return;
	trigger_RI_debugEventsTrigger();
}

