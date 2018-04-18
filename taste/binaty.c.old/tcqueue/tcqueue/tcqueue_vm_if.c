/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "tcqueue_vm_if.h"

#include "tcqueue.h"

#include "C_ASN1_Types.h"

void init_tcqueue()
{
    static int init = 0;

    if (!init) {
        init = 1;
        tcqueue_startup();
        extern void init_x86_partition_taste_api();
        init_x86_partition_taste_api();
    }
}

void tcqueue_newTc (void *pmy_tcPacket, size_t size_my_tcPacket)
{
    /* Decoded input variable(s): developer can use them */
    static asn1SccPusPacket IN_tcPacket;

#ifdef __unix__
    asn1SccPusPacket_Initialize(&IN_tcPacket);
#endif

    /* Decode each input parameter */
    if (0 != Decode_NATIVE_PusPacket (&IN_tcPacket, pmy_tcPacket, size_my_tcPacket)) {
        #ifdef __unix__
            printf("\nError Decoding PusPacket\n");
        #endif
        return;
    }

    /* Call to User-defined function */
    tcqueue_PI_newTc (&IN_tcPacket);

}
void tcqueue_tcRequest (void *pmy_tcPacket, size_t *psize_my_tcPacket, void *pmy_isAvailable, size_t *psize_my_isAvailable)
{

    /* Output variable(s): developer has to fill them */
    static asn1SccPusPacket OUT_tcPacket;
    static asn1SccT_Boolean OUT_isAvailable;

#ifdef __unix__
    asn1SccPusPacket_Initialize(&OUT_tcPacket);
    asn1SccT_Boolean_Initialize(&OUT_isAvailable);
#endif
    /* Call to User-defined function */
    tcqueue_PI_tcRequest (&OUT_tcPacket, &OUT_isAvailable);

    /* Encode each output parameter */

    *psize_my_tcPacket = Encode_NATIVE_PusPacket (pmy_tcPacket, sizeof (asn1SccPusPacket), &OUT_tcPacket);
    *psize_my_isAvailable = Encode_NATIVE_T_Boolean (pmy_isAvailable, sizeof (asn1SccT_Boolean), &OUT_isAvailable);
}
