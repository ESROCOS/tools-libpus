/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "tmqueue_vm_if.h"

#include "tmqueue.h"

#include "C_ASN1_Types.h"

void init_tmqueue()
{
    static int init = 0;

    if (!init) {
        init = 1;
        tmqueue_startup();
        extern void init_st09();
        init_st09();
    }
}

void tmqueue_tmRequest (void *pmy_tmPacket, size_t *psize_my_tmPacket, void *pmy_isAvailable, size_t *psize_my_isAvailable)
{

    /* Output variable(s): developer has to fill them */
    static asn1SccPusPacket OUT_tmPacket;
    static asn1SccT_Boolean OUT_isAvailable;

#ifdef __unix__
    asn1SccPusPacket_Initialize(&OUT_tmPacket);
    asn1SccT_Boolean_Initialize(&OUT_isAvailable);
#endif
    /* Call to User-defined function */
    tmqueue_PI_tmRequest (&OUT_tmPacket, &OUT_isAvailable);

    /* Encode each output parameter */

    *psize_my_tmPacket = Encode_NATIVE_PusPacket (pmy_tmPacket, sizeof (asn1SccPusPacket), &OUT_tmPacket);
    *psize_my_isAvailable = Encode_NATIVE_T_Boolean (pmy_isAvailable, sizeof (asn1SccT_Boolean), &OUT_isAvailable);
}
void tmqueue_newTm (void *pmy_tmPacket, size_t size_my_tmPacket)
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
    tmqueue_PI_newTm (&IN_tmPacket);

}
