/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "onboardparams_vm_if.h"

#include "onboardparams.h"

#include "C_ASN1_Types.h"

void init_onboardparams()
{
    static int init = 0;

    if (!init) {
        init = 1;
        onboardparams_startup();
    }
}

void onboardparams_setOnBoardParam (void *pmy_paramId, size_t size_my_paramId, void *pmy_paramValue, size_t size_my_paramValue)
{
    /* Decoded input variable(s): developer can use them */
    static asn1SccPusSt20OnBoardParameterId IN_paramId;
    static asn1SccPusSt20StoredParam IN_paramValue;

#ifdef __unix__
    asn1SccPusSt20OnBoardParameterId_Initialize(&IN_paramId);
    asn1SccPusSt20StoredParam_Initialize(&IN_paramValue);
#endif

    /* Decode each input parameter */
    if (0 != Decode_NATIVE_PusSt20OnBoardParameterId (&IN_paramId, pmy_paramId, size_my_paramId)) {
        #ifdef __unix__
            printf("\nError Decoding PusSt20OnBoardParameterId\n");
        #endif
        return;
    }

    if (0 != Decode_NATIVE_PusSt20StoredParam (&IN_paramValue, pmy_paramValue, size_my_paramValue)) {
        #ifdef __unix__
            printf("\nError Decoding PusSt20StoredParam\n");
        #endif
        return;
    }

    /* Call to User-defined function */
    onboardparams_PI_setOnBoardParam (&IN_paramId, &IN_paramValue);

}
void onboardparams_getOnBoardParam (void *pmy_paramId, size_t size_my_paramId, void *pmy_paramValue, size_t *psize_my_paramValue, void *pmy_isAvailable, size_t *psize_my_isAvailable)
{
    /* Decoded input variable(s): developer can use them */
    static asn1SccPusSt20OnBoardParameterId IN_paramId;

    /* Output variable(s): developer has to fill them */
    static asn1SccPusSt20StoredParam OUT_paramValue;
    static asn1SccPusSt01FailureCode OUT_isAvailable;

#ifdef __unix__
    asn1SccPusSt20OnBoardParameterId_Initialize(&IN_paramId);
    asn1SccPusSt20StoredParam_Initialize(&OUT_paramValue);
    asn1SccPusSt01FailureCode_Initialize(&OUT_isAvailable);
#endif

    /* Decode each input parameter */
    if (0 != Decode_NATIVE_PusSt20OnBoardParameterId (&IN_paramId, pmy_paramId, size_my_paramId)) {
        #ifdef __unix__
            printf("\nError Decoding PusSt20OnBoardParameterId\n");
        #endif
        return;
    }

    /* Call to User-defined function */
    onboardparams_PI_getOnBoardParam (&IN_paramId, &OUT_paramValue, &OUT_isAvailable);

    /* Encode each output parameter */

    *psize_my_paramValue = Encode_NATIVE_PusSt20StoredParam (pmy_paramValue, sizeof (asn1SccPusSt20StoredParam), &OUT_paramValue);
    *psize_my_isAvailable = Encode_NATIVE_PusSt01FailureCode (pmy_isAvailable, sizeof (asn1SccPusSt01FailureCode), &OUT_isAvailable);
}
