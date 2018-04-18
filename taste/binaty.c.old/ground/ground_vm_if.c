/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "ground_vm_if.h"

#include "ground.h"

#include "C_ASN1_Types.h"

void init_ground()
{
    static int init = 0;

    if (!init) {
        init = 1;
        ground_startup();
        extern void init_x86_partition_taste_api();
        init_x86_partition_taste_api();
    }
}

void ground_newTm (void *pmy_tmPacket, size_t size_my_tmPacket)
{
    /* Decoded input variable(s): developer can use them */
    static asn1SccPusPacket IN_tmPacket;

#ifdef __unix__
    asn1SccPusPacket_Initialize(&IN_tmPacket);
#endif

    /* Decode each input parameter */
    if (0 != Decode_NATIVE_PusPacket (&IN_tmPacket, pmy_tmPacket, size_my_tmPacket)) {
        #ifdef __unix__
            printf("\nError Decoding PusPacket\n");
        #endif
        return;
    }

    /* Call to User-defined function */
    ground_PI_newTm (&IN_tmPacket);

}
void ground_triggerTmGUI ()
{
    /* Call to User-defined function */
    ground_PI_triggerTmGUI ();

}
