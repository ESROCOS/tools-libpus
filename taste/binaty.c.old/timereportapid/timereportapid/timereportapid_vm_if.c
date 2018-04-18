/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifdef __unix__
    #include <stdlib.h>
    #include <stdio.h>
#else
    typedef unsigned size_t;
#endif

#include "timereportapid_vm_if.h"

#include "timereportapid.h"

#include "C_ASN1_Types.h"

void init_timereportapid()
{
    static int init = 0;

    if (!init) {
        init = 1;
        timereportapid_startup();
    }
}

void timereportapid_getApid (void *pmy_apid, size_t *psize_my_apid)
{

    /* Output variable(s): developer has to fill them */
    asn1SccPusApid OUT_apid;

#ifdef __unix__
    asn1SccPusApid_Initialize(&OUT_apid);
#endif
    /* Call to User-defined function */
    timereportapid_PI_getApid (&OUT_apid);

    /* Encode each output parameter */

    *psize_my_apid = Encode_NATIVE_PusApid (pmy_apid, sizeof (asn1SccPusApid), &OUT_apid);
}
void timereportapid_getSequenceCount (void *pmy_sequenceCount, size_t *psize_my_sequenceCount)
{

    /* Output variable(s): developer has to fill them */
    static asn1SccPusSequenceCount OUT_sequenceCount;

#ifdef __unix__
    asn1SccPusSequenceCount_Initialize(&OUT_sequenceCount);
#endif
    /* Call to User-defined function */
    timereportapid_PI_getSequenceCount (&OUT_sequenceCount);

    /* Encode each output parameter */

    *psize_my_sequenceCount = Encode_NATIVE_PusSequenceCount (pmy_sequenceCount, sizeof (asn1SccPusSequenceCount), &OUT_sequenceCount);
}
