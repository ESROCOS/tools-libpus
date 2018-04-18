/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "obcpengine_vm_if.h"

#include "obcpengine.h"

#include "C_ASN1_Types.h"

void init_obcpengine()
{
    static int init = 0;

    if (!init) {
        init = 1;
        obcpengine_startup();
        extern void init_onboardparams();
        init_onboardparams();
        extern void init_onboardparams();
        init_onboardparams();
        extern void init_events();
        init_events();
    }
}

void obcpengine_loadDirect (void *pmy_obcpId, size_t size_my_obcpId, void *pmy_obcpCode, size_t size_my_obcpCode)
{
    /* Decoded input variable(s): developer can use them */
    static asn1SccPusSt18ObcpId IN_obcpId;
    static asn1SccPusSt18ObcpCode IN_obcpCode;

#ifdef __unix__
    asn1SccPusSt18ObcpId_Initialize(&IN_obcpId);
    asn1SccPusSt18ObcpCode_Initialize(&IN_obcpCode);
#endif

    /* Decode each input parameter */
    if (0 != Decode_NATIVE_PusSt18ObcpId (&IN_obcpId, pmy_obcpId, size_my_obcpId)) {
        #ifdef __unix__
            printf("\nError Decoding PusSt18ObcpId\n");
        #endif
        return;
    }

    if (0 != Decode_NATIVE_PusSt18ObcpCode (&IN_obcpCode, pmy_obcpCode, size_my_obcpCode)) {
        #ifdef __unix__
            printf("\nError Decoding PusSt18ObcpCode\n");
        #endif
        return;
    }

    /* Call to User-defined function */
    obcpengine_PI_loadDirect (&IN_obcpId, &IN_obcpCode);

}
void obcpengine_loadReference (void *pmy_referenceData, size_t size_my_referenceData)
{
    /* Decoded input variable(s): developer can use them */
    static asn1SccPusTC_18_13_Data IN_referenceData;

#ifdef __unix__
    asn1SccPusTC_18_13_Data_Initialize(&IN_referenceData);
#endif

    /* Decode each input parameter */
    if (0 != Decode_NATIVE_PusTC_18_13_Data (&IN_referenceData, pmy_referenceData, size_my_referenceData)) {
        #ifdef __unix__
            printf("\nError Decoding PusTC_18_13_Data\n");
        #endif
        return;
    }

    /* Call to User-defined function */
    obcpengine_PI_loadReference (&IN_referenceData);

}
