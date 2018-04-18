/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "st01_vm_if.h"

#include "st01.h"

#include "C_ASN1_Types.h"

void init_st01()
{
    static int init = 0;

    if (!init) {
        init = 1;
        st01_startup();
        extern void init_tmqueue();
        init_tmqueue();
        extern void init_onboardapid();
        init_onboardapid();
        extern void init_onboardapid();
        init_onboardapid();
    }
}

void st01_ACK (void *pmy_tcPacket, size_t size_my_tcPacket, void *pmy_reportType, size_t size_my_reportType, void *pmy_error, size_t size_my_error, void *pmy_errorInfo, size_t size_my_errorInfo, void *pmy_step, size_t size_my_step)
{
    /* Decoded input variable(s): developer can use them */
    static asn1SccPusPacket IN_tcPacket;
    static asn1SccPusSubserviceType IN_reportType;
    static asn1SccPusSt01FailureCode IN_error;
    static asn1SccPusSt01FailureInfo IN_errorInfo;
    static asn1SccPusStepId IN_step;

#ifdef __unix__
    asn1SccPusPacket_Initialize(&IN_tcPacket);
    asn1SccPusSubserviceType_Initialize(&IN_reportType);
    asn1SccPusSt01FailureCode_Initialize(&IN_error);
    asn1SccPusSt01FailureInfo_Initialize(&IN_errorInfo);
    asn1SccPusStepId_Initialize(&IN_step);
#endif

    /* Decode each input parameter */
    if (0 != Decode_NATIVE_PusPacket (&IN_tcPacket, pmy_tcPacket, size_my_tcPacket)) {
        #ifdef __unix__
            printf("\nError Decoding PusPacket\n");
        #endif
        return;
    }

    if (0 != Decode_NATIVE_PusSubserviceType (&IN_reportType, pmy_reportType, size_my_reportType)) {
        #ifdef __unix__
            printf("\nError Decoding PusSubserviceType\n");
        #endif
        return;
    }

    if (0 != Decode_NATIVE_PusSt01FailureCode (&IN_error, pmy_error, size_my_error)) {
        #ifdef __unix__
            printf("\nError Decoding PusSt01FailureCode\n");
        #endif
        return;
    }

    if (0 != Decode_NATIVE_PusSt01FailureInfo (&IN_errorInfo, pmy_errorInfo, size_my_errorInfo)) {
        #ifdef __unix__
            printf("\nError Decoding PusSt01FailureInfo\n");
        #endif
        return;
    }

    if (0 != Decode_NATIVE_PusStepId (&IN_step, pmy_step, size_my_step)) {
        #ifdef __unix__
            printf("\nError Decoding PusStepId\n");
        #endif
        return;
    }

    /* Call to User-defined function */
    st01_PI_ACK (&IN_tcPacket, &IN_reportType, &IN_error, &IN_errorInfo, &IN_step);

}
