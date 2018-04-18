/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "housekeeping_vm_if.h"

#include "housekeeping.h"

#include "C_ASN1_Types.h"

void init_housekeeping()
{
    static int init = 0;

    if (!init) {
        init = 1;
        housekeeping_startup();
    }
}

void housekeeping_setParamValue (void *pmy_paramId, size_t size_my_paramId, void *pmy_paramValue, size_t size_my_paramValue)
{
    /* Decoded input variable(s): developer can use them */
    static asn1SccPusSt03ParameterId IN_paramId;
    static asn1SccPusSt03StoredParam IN_paramValue;

#ifdef __unix__
    asn1SccPusSt03ParameterId_Initialize(&IN_paramId);
    asn1SccPusSt03StoredParam_Initialize(&IN_paramValue);
#endif

    /* Decode each input parameter */
    if (0 != Decode_NATIVE_PusSt03ParameterId (&IN_paramId, pmy_paramId, size_my_paramId)) {
        #ifdef __unix__
            printf("\nError Decoding PusSt03ParameterId\n");
        #endif
        return;
    }

    if (0 != Decode_NATIVE_PusSt03StoredParam (&IN_paramValue, pmy_paramValue, size_my_paramValue)) {
        #ifdef __unix__
            printf("\nError Decoding PusSt03StoredParam\n");
        #endif
        return;
    }

    /* Call to User-defined function */
    housekeeping_PI_setParamValue (&IN_paramId, &IN_paramValue);

}
void housekeeping_getParamValue (void *pmy_paramId, size_t size_my_paramId, void *pmy_paramValue, size_t *psize_my_paramValue, void *pmy_isAvailable, size_t *psize_my_isAvailable)
{
    /* Decoded input variable(s): developer can use them */
    static asn1SccPusSt03ParameterId IN_paramId;

    /* Output variable(s): developer has to fill them */
    static asn1SccPusSt03StoredParam OUT_paramValue;
    static asn1SccPusSt01FailureCode OUT_isAvailable;

#ifdef __unix__
    asn1SccPusSt03ParameterId_Initialize(&IN_paramId);
    asn1SccPusSt03StoredParam_Initialize(&OUT_paramValue);
    asn1SccPusSt01FailureCode_Initialize(&OUT_isAvailable);
#endif

    /* Decode each input parameter */
    if (0 != Decode_NATIVE_PusSt03ParameterId (&IN_paramId, pmy_paramId, size_my_paramId)) {
        #ifdef __unix__
            printf("\nError Decoding PusSt03ParameterId\n");
        #endif
        return;
    }

    /* Call to User-defined function */
    housekeeping_PI_getParamValue (&IN_paramId, &OUT_paramValue, &OUT_isAvailable);

    /* Encode each output parameter */

    *psize_my_paramValue = Encode_NATIVE_PusSt03StoredParam (pmy_paramValue, sizeof (asn1SccPusSt03StoredParam), &OUT_paramValue);
    *psize_my_isAvailable = Encode_NATIVE_PusSt01FailureCode (pmy_isAvailable, sizeof (asn1SccPusSt01FailureCode), &OUT_isAvailable);
}
