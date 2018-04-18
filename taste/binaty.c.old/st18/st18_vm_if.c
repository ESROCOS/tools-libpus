/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "st18_vm_if.h"

#include "st18.h"

#include "C_ASN1_Types.h"

void init_st18()
{
    static int init = 0;

    if (!init) {
        init = 1;
        st18_startup();
        extern void init_st01();
        init_st01();
        extern void init_obcpengine();
        init_obcpengine();
        extern void init_obcpengine();
        init_obcpengine();
    }
}

void st18_tc18 (void *pmy_tcPacket, size_t size_my_tcPacket)
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
    st18_PI_tc18 (&IN_tcPacket);

}
