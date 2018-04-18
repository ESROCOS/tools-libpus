/* This file was generated automatically: DO NOT MODIFY IT ! */

#include <stdlib.h>
#ifdef __unix__
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#endif

#include "C_ASN1_Types.h"
#include "tmqueue_polyorb_interface.h"

void tmqueue_RI_incCount(asn1SccPusPacket *OUT_tmPacket, asn1SccPusSt01FailureCode *OUT_isAvailable)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tmqueue,st09,incCount,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_tmPacket[sizeof(asn1SccPusPacket)];
    int size_OUT_buf_tmPacket=0;
    static char OUT_buf_isAvailable[sizeof(asn1SccPusSt01FailureCode)];
    int size_OUT_buf_isAvailable=0;

    /* Call to VM callback function */
    extern void vm_tmqueue_incCount(void *, size_t *, void *, size_t *);

    vm_tmqueue_incCount(OUT_buf_tmPacket, &size_OUT_buf_tmPacket, OUT_buf_isAvailable, &size_OUT_buf_isAvailable);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusPacket(OUT_tmPacket, OUT_buf_tmPacket, size_OUT_buf_tmPacket)) {
#ifdef __unix__
        printf("\nError Decoding PusPacket\n");
#endif
        return;
    }

    if (0 != Decode_NATIVE_PusSt01FailureCode(OUT_isAvailable, OUT_buf_isAvailable, size_OUT_buf_isAvailable)) {
#ifdef __unix__
        printf("\nError Decoding PusSt01FailureCode\n");
#endif
        return;
    }

}

