/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "events_vm_if.h"

#include "events.h"

#include "C_ASN1_Types.h"

void init_events()
{
    static int init = 0;

    if (!init) {
        init = 1;
        events_startup();
        extern void init_x86_partition_taste_api();
        init_x86_partition_taste_api();
    }
}

void events_getNextEvent (void *pmy_actualCounter, size_t size_my_actualCounter, void *pmy_eventInfo, size_t *psize_my_eventInfo, void *pmy_nextCounter, size_t *psize_my_nextCounter)
{
    /* Decoded input variable(s): developer can use them */
    static asn1SccPusUInt64 IN_actualCounter;

    /* Output variable(s): developer has to fill them */
    static asn1SccPusSt05Event OUT_eventInfo;
    static asn1SccPusUInt64 OUT_nextCounter;

#ifdef __unix__
    asn1SccPusUInt64_Initialize(&IN_actualCounter);
    asn1SccPusSt05Event_Initialize(&OUT_eventInfo);
    asn1SccPusUInt64_Initialize(&OUT_nextCounter);
#endif

    /* Decode each input parameter */
    if (0 != Decode_NATIVE_PusUInt64 (&IN_actualCounter, pmy_actualCounter, size_my_actualCounter)) {
        #ifdef __unix__
            printf("\nError Decoding PusUInt64\n");
        #endif
        return;
    }

    /* Call to User-defined function */
    events_PI_getNextEvent (&IN_actualCounter, &OUT_eventInfo, &OUT_nextCounter);

    /* Encode each output parameter */

    *psize_my_eventInfo = Encode_NATIVE_PusSt05Event (pmy_eventInfo, sizeof (asn1SccPusSt05Event), &OUT_eventInfo);
    *psize_my_nextCounter = Encode_NATIVE_PusUInt64 (pmy_nextCounter, sizeof (asn1SccPusUInt64), &OUT_nextCounter);
}
void events_pushNewEvent (void *pmy_eventInfo, size_t size_my_eventInfo)
{
    /* Decoded input variable(s): developer can use them */
    static asn1SccPusSt05Event IN_eventInfo;

#ifdef __unix__
    asn1SccPusSt05Event_Initialize(&IN_eventInfo);
#endif

    /* Decode each input parameter */
    if (0 != Decode_NATIVE_PusSt05Event (&IN_eventInfo, pmy_eventInfo, size_my_eventInfo)) {
        #ifdef __unix__
            printf("\nError Decoding PusSt05Event\n");
        #endif
        return;
    }

    /* Call to User-defined function */
    events_PI_pushNewEvent (&IN_eventInfo);

}
void events_debugEventsTrigger ()
{
    /* Call to User-defined function */
    events_PI_debugEventsTrigger ();

}
