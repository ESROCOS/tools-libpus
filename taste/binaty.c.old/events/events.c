/* User code: This file will not be overwritten by TASTE. */

#include "events.h"

void events_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void events_PI_getNextEvent(const asn1SccPusUInt64 *IN_actualCounter,
                            asn1SccPusSt05Event *OUT_eventInfo,
                            asn1SccPusUInt64 *OUT_nextCounter)
{
    /* Write your code here! */
}

void events_PI_pushNewEvent(const asn1SccPusSt05Event *IN_eventInfo)
{
    /* Write your code here! */
}

void events_PI_debugEventsTrigger()
{
    /* Write your code here! */
}

