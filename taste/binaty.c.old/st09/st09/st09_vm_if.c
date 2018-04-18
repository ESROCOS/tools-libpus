/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "st09_vm_if.h"

#include "st09.h"

#include "C_ASN1_Types.h"

void init_st09()
{
    static int init = 0;

    if (!init) {
        init = 1;
        st09_startup();
        extern void init_timereportapid();
        init_timereportapid();
        extern void init_timereportapid();
        init_timereportapid();
        extern void init_st01();
        init_st01();
    }
}

void st09_incCount (void *pmy_tmPacket, size_t *psize_my_tmPacket, void *pmy_isAvailable, size_t *psize_my_isAvailable)
{

    /* Output variable(s): developer has to fill them */
    static asn1SccPusPacket OUT_tmPacket;
    static asn1SccPusSt01FailureCode OUT_isAvailable;

#ifdef __unix__
    asn1SccPusPacket_Initialize(&OUT_tmPacket);
    asn1SccPusSt01FailureCode_Initialize(&OUT_isAvailable);
#endif
    /* Call to User-defined function */
    st09_PI_incCount (&OUT_tmPacket, &OUT_isAvailable);

    /* Encode each output parameter */

    *psize_my_tmPacket = Encode_NATIVE_PusPacket (pmy_tmPacket, sizeof (asn1SccPusPacket), &OUT_tmPacket);
    *psize_my_isAvailable = Encode_NATIVE_PusSt01FailureCode (pmy_isAvailable, sizeof (asn1SccPusSt01FailureCode), &OUT_isAvailable);
}
void st09_tc09 (void *pmy_tcPacket, size_t size_my_tcPacket)
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
    st09_PI_tc09 (&IN_tcPacket);

}
