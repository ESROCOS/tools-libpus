/* This file was generated automatically: DO NOT MODIFY IT ! */

#include <stdlib.h>
#ifdef __unix__
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#endif

#include "C_ASN1_Types.h"
#include "tcdispatch_polyorb_interface.h"

void tcdispatch_RI_tcRequest(asn1SccPusPacket *OUT_tcPacket, asn1SccT_Boolean *OUT_isAvailable)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tcdispatch,tcqueue,tcRequest,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_tcPacket[sizeof(asn1SccPusPacket)];
    int size_OUT_buf_tcPacket=0;
    static char OUT_buf_isAvailable[sizeof(asn1SccT_Boolean)];
    int size_OUT_buf_isAvailable=0;

    /* Call to VM callback function */
    extern void vm_tcdispatch_tcRequest(void *, size_t *, void *, size_t *);

    vm_tcdispatch_tcRequest(OUT_buf_tcPacket, &size_OUT_buf_tcPacket, OUT_buf_isAvailable, &size_OUT_buf_isAvailable);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusPacket(OUT_tcPacket, OUT_buf_tcPacket, size_OUT_buf_tcPacket)) {
#ifdef __unix__
        printf("\nError Decoding PusPacket\n");
#endif
        return;
    }

    if (0 != Decode_NATIVE_T_Boolean(OUT_isAvailable, OUT_buf_isAvailable, size_OUT_buf_isAvailable)) {
#ifdef __unix__
        printf("\nError Decoding T_Boolean\n");
#endif
        return;
    }

}

void tcdispatch_RI_tc17(const asn1SccPusPacket *IN_tcPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: tc17::PusPacket::tcPacket", IN_tcPacket);
        }
        printf ("\nINNER: tcdispatch,st17,tc17,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_tcPacket[sizeof(asn1SccPusPacket)] = {0};
    int size_IN_buf_tcPacket=0;

    /* Encode each input parameter */
    size_IN_buf_tcPacket = Encode_NATIVE_PusPacket(IN_buf_tcPacket, sizeof(asn1SccPusPacket), IN_tcPacket);
    if (-1 == size_IN_buf_tcPacket) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_tc17!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_tc17(void *, size_t);

    vm_tcdispatch_tc17(IN_buf_tcPacket, size_IN_buf_tcPacket);

}

void tcdispatch_RI_tc08(const asn1SccPusPacket *IN_tcPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: tc08::PusPacket::tcPacket", IN_tcPacket);
        }
        printf ("\nINNER: tcdispatch,st08,tc08,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_tcPacket[sizeof(asn1SccPusPacket)] = {0};
    int size_IN_buf_tcPacket=0;

    /* Encode each input parameter */
    size_IN_buf_tcPacket = Encode_NATIVE_PusPacket(IN_buf_tcPacket, sizeof(asn1SccPusPacket), IN_tcPacket);
    if (-1 == size_IN_buf_tcPacket) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_tc08!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_tc08(void *, size_t);

    vm_tcdispatch_tc08(IN_buf_tcPacket, size_IN_buf_tcPacket);

}

void tcdispatch_RI_tc19(const asn1SccPusPacket *IN_tcPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: tc19::PusPacket::tcPacket", IN_tcPacket);
        }
        printf ("\nINNER: tcdispatch,st19,tc19,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_tcPacket[sizeof(asn1SccPusPacket)] = {0};
    int size_IN_buf_tcPacket=0;

    /* Encode each input parameter */
    size_IN_buf_tcPacket = Encode_NATIVE_PusPacket(IN_buf_tcPacket, sizeof(asn1SccPusPacket), IN_tcPacket);
    if (-1 == size_IN_buf_tcPacket) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_tc19!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_tc19(void *, size_t);

    vm_tcdispatch_tc19(IN_buf_tcPacket, size_IN_buf_tcPacket);

}

void tcdispatch_RI_tc09(const asn1SccPusPacket *IN_tcPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: tc09::PusPacket::tcPacket", IN_tcPacket);
        }
        printf ("\nINNER: tcdispatch,st09,tc09,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_tcPacket[sizeof(asn1SccPusPacket)] = {0};
    int size_IN_buf_tcPacket=0;

    /* Encode each input parameter */
    size_IN_buf_tcPacket = Encode_NATIVE_PusPacket(IN_buf_tcPacket, sizeof(asn1SccPusPacket), IN_tcPacket);
    if (-1 == size_IN_buf_tcPacket) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_tc09!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_tc09(void *, size_t);

    vm_tcdispatch_tc09(IN_buf_tcPacket, size_IN_buf_tcPacket);

}

void tcdispatch_RI_tc12(const asn1SccPusPacket *IN_tcPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: tc12::PusPacket::tcPacket", IN_tcPacket);
        }
        printf ("\nINNER: tcdispatch,st12,tc12,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_tcPacket[sizeof(asn1SccPusPacket)] = {0};
    int size_IN_buf_tcPacket=0;

    /* Encode each input parameter */
    size_IN_buf_tcPacket = Encode_NATIVE_PusPacket(IN_buf_tcPacket, sizeof(asn1SccPusPacket), IN_tcPacket);
    if (-1 == size_IN_buf_tcPacket) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_tc12!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_tc12(void *, size_t);

    vm_tcdispatch_tc12(IN_buf_tcPacket, size_IN_buf_tcPacket);

}

void tcdispatch_RI_tc11(const asn1SccPusPacket *IN_tcPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: tc11::PusPacket::tcPacket", IN_tcPacket);
        }
        printf ("\nINNER: tcdispatch,st11,tc11,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_tcPacket[sizeof(asn1SccPusPacket)] = {0};
    int size_IN_buf_tcPacket=0;

    /* Encode each input parameter */
    size_IN_buf_tcPacket = Encode_NATIVE_PusPacket(IN_buf_tcPacket, sizeof(asn1SccPusPacket), IN_tcPacket);
    if (-1 == size_IN_buf_tcPacket) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_tc11!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_tc11(void *, size_t);

    vm_tcdispatch_tc11(IN_buf_tcPacket, size_IN_buf_tcPacket);

}

void tcdispatch_RI_tc18(const asn1SccPusPacket *IN_tcPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: tc18::PusPacket::tcPacket", IN_tcPacket);
        }
        printf ("\nINNER: tcdispatch,st18,tc18,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_tcPacket[sizeof(asn1SccPusPacket)] = {0};
    int size_IN_buf_tcPacket=0;

    /* Encode each input parameter */
    size_IN_buf_tcPacket = Encode_NATIVE_PusPacket(IN_buf_tcPacket, sizeof(asn1SccPusPacket), IN_tcPacket);
    if (-1 == size_IN_buf_tcPacket) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_tc18!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_tc18(void *, size_t);

    vm_tcdispatch_tc18(IN_buf_tcPacket, size_IN_buf_tcPacket);

}

void tcdispatch_RI_tc23()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tcdispatch,st23,tc23,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_tcdispatch_tc23();

    vm_tcdispatch_tc23();

}

void tcdispatch_RI_tc20(const asn1SccPusPacket *IN_tcPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: tc20::PusPacket::tcPacket", IN_tcPacket);
        }
        printf ("\nINNER: tcdispatch,st20,tc20,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_tcPacket[sizeof(asn1SccPusPacket)] = {0};
    int size_IN_buf_tcPacket=0;

    /* Encode each input parameter */
    size_IN_buf_tcPacket = Encode_NATIVE_PusPacket(IN_buf_tcPacket, sizeof(asn1SccPusPacket), IN_tcPacket);
    if (-1 == size_IN_buf_tcPacket) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_tc20!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_tc20(void *, size_t);

    vm_tcdispatch_tc20(IN_buf_tcPacket, size_IN_buf_tcPacket);

}

void tcdispatch_RI_check_queue(asn1SccT_Boolean *OUT_res)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tcdispatch,x86_partition_taste_api,check_queue,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_res[sizeof(asn1SccT_Boolean)];
    int size_OUT_buf_res=0;

    /* Call to VM callback function */
    extern void vm_tcdispatch_check_queue(void *, size_t *);

    vm_tcdispatch_check_queue(OUT_buf_res, &size_OUT_buf_res);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_T_Boolean(OUT_res, OUT_buf_res, size_OUT_buf_res)) {
#ifdef __unix__
        printf("\nError Decoding T_Boolean\n");
#endif
        return;
    }

}

void tcdispatch_RI_check_queue_vt(asn1SccT_Boolean *OUT_res)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tcdispatch,x86_partition_taste_api,check_queue_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_res[sizeof(asn1SccT_Boolean)];
    int size_OUT_buf_res=0;

    /* Call to VM callback function */
    extern void vm_tcdispatch_check_queue_vt(void *, size_t *);

    vm_tcdispatch_check_queue_vt(OUT_buf_res, &size_OUT_buf_res);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_T_Boolean(OUT_res, OUT_buf_res, size_OUT_buf_res)) {
#ifdef __unix__
        printf("\nError Decoding T_Boolean\n");
#endif
        return;
    }

}

void tcdispatch_RI_incCount_vt(asn1SccPusPacket *OUT_tmPacket, asn1SccPusSt01FailureCode *OUT_isAvailable)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tcdispatch,st09,incCount_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_tmPacket[sizeof(asn1SccPusPacket)];
    int size_OUT_buf_tmPacket=0;
    static char OUT_buf_isAvailable[sizeof(asn1SccPusSt01FailureCode)];
    int size_OUT_buf_isAvailable=0;

    /* Call to VM callback function */
    extern void vm_tcdispatch_incCount_vt(void *, size_t *, void *, size_t *);

    vm_tcdispatch_incCount_vt(OUT_buf_tmPacket, &size_OUT_buf_tmPacket, OUT_buf_isAvailable, &size_OUT_buf_isAvailable);

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

void tcdispatch_RI_ACK_vt(const asn1SccPusPacket *IN_tcPacket, const asn1SccPusSubserviceType *IN_reportType, const asn1SccPusSt01FailureCode *IN_error, const asn1SccPusSt01FailureInfo *IN_errorInfo, const asn1SccPusStepId *IN_step)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: ACK_vt::PusPacket::tcPacket", IN_tcPacket);
        }
        {
            PrintASN1PusSubserviceType ("INNERDATA: ACK_vt::PusSubserviceType::reportType", IN_reportType);
        }
        {
            PrintASN1PusSt01FailureCode ("INNERDATA: ACK_vt::PusSt01FailureCode::error", IN_error);
        }
        {
            PrintASN1PusSt01FailureInfo ("INNERDATA: ACK_vt::PusSt01FailureInfo::errorInfo", IN_errorInfo);
        }
        {
            PrintASN1PusStepId ("INNERDATA: ACK_vt::PusStepId::step", IN_step);
        }
        printf ("\nINNER: tcdispatch,st01,ACK_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_tcPacket[sizeof(asn1SccPusPacket)] = {0};
    int size_IN_buf_tcPacket=0;
    static char IN_buf_reportType[sizeof(asn1SccPusSubserviceType)] = {0};
    int size_IN_buf_reportType=0;
    static char IN_buf_error[sizeof(asn1SccPusSt01FailureCode)] = {0};
    int size_IN_buf_error=0;
    static char IN_buf_errorInfo[sizeof(asn1SccPusSt01FailureInfo)] = {0};
    int size_IN_buf_errorInfo=0;
    static char IN_buf_step[sizeof(asn1SccPusStepId)] = {0};
    int size_IN_buf_step=0;

    /* Encode each input parameter */
    size_IN_buf_tcPacket = Encode_NATIVE_PusPacket(IN_buf_tcPacket, sizeof(asn1SccPusPacket), IN_tcPacket);
    if (-1 == size_IN_buf_tcPacket) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_ACK_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_reportType = Encode_NATIVE_PusSubserviceType(IN_buf_reportType, sizeof(asn1SccPusSubserviceType), IN_reportType);
    if (-1 == size_IN_buf_reportType) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_ACK_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_error = Encode_NATIVE_PusSt01FailureCode(IN_buf_error, sizeof(asn1SccPusSt01FailureCode), IN_error);
    if (-1 == size_IN_buf_error) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_ACK_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_errorInfo = Encode_NATIVE_PusSt01FailureInfo(IN_buf_errorInfo, sizeof(asn1SccPusSt01FailureInfo), IN_errorInfo);
    if (-1 == size_IN_buf_errorInfo) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_ACK_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_step = Encode_NATIVE_PusStepId(IN_buf_step, sizeof(asn1SccPusStepId), IN_step);
    if (-1 == size_IN_buf_step) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_ACK_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_ACK_vt(void *, size_t, void *, size_t, void *, size_t, void *, size_t, void *, size_t);

    vm_tcdispatch_ACK_vt(IN_buf_tcPacket, size_IN_buf_tcPacket, IN_buf_reportType, size_IN_buf_reportType, IN_buf_error, size_IN_buf_error, IN_buf_errorInfo, size_IN_buf_errorInfo, IN_buf_step, size_IN_buf_step);

}

void tcdispatch_RI_getApid_vt(asn1SccPusApid *OUT_apid)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tcdispatch,onboardapid,getApid_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_apid[sizeof(asn1SccPusApid)];
    int size_OUT_buf_apid=0;

    /* Call to VM callback function */
    extern void vm_tcdispatch_getApid_vt(void *, size_t *);

    vm_tcdispatch_getApid_vt(OUT_buf_apid, &size_OUT_buf_apid);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusApid(OUT_apid, OUT_buf_apid, size_OUT_buf_apid)) {
#ifdef __unix__
        printf("\nError Decoding PusApid\n");
#endif
        return;
    }

}

void tcdispatch_RI_getSequenceCount_vt(asn1SccPusSequenceCount *OUT_sequenceCount)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tcdispatch,onboardapid,getSequenceCount_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_sequenceCount[sizeof(asn1SccPusSequenceCount)];
    int size_OUT_buf_sequenceCount=0;

    /* Call to VM callback function */
    extern void vm_tcdispatch_getSequenceCount_vt(void *, size_t *);

    vm_tcdispatch_getSequenceCount_vt(OUT_buf_sequenceCount, &size_OUT_buf_sequenceCount);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusSequenceCount(OUT_sequenceCount, OUT_buf_sequenceCount, size_OUT_buf_sequenceCount)) {
#ifdef __unix__
        printf("\nError Decoding PusSequenceCount\n");
#endif
        return;
    }

}

void tcdispatch_RI_newTm_vt(const asn1SccPusPacket *IN_tmPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: newTm_vt::PusPacket::tmPacket", IN_tmPacket);
        }
        printf ("\nINNER: tcdispatch,tmqueue,newTm_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_tmPacket[sizeof(asn1SccPusPacket)] = {0};
    int size_IN_buf_tmPacket=0;

    /* Encode each input parameter */
    size_IN_buf_tmPacket = Encode_NATIVE_PusPacket(IN_buf_tmPacket, sizeof(asn1SccPusPacket), IN_tmPacket);
    if (-1 == size_IN_buf_tmPacket) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_newTm_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_newTm_vt(void *, size_t);

    vm_tcdispatch_newTm_vt(IN_buf_tmPacket, size_IN_buf_tmPacket);

}

void tcdispatch_RI_getNextEvent_vt(const asn1SccPusUInt64 *IN_actualCounter, asn1SccPusSt05Event *OUT_eventInfo, asn1SccPusUInt64 *OUT_nextCounter)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusUInt64 ("INNERDATA: getNextEvent_vt::PusUInt64::actualCounter", IN_actualCounter);
        }
        printf ("\nINNER: tcdispatch,events,getNextEvent_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_actualCounter[sizeof(asn1SccPusUInt64)] = {0};
    int size_IN_buf_actualCounter=0;

    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_eventInfo[sizeof(asn1SccPusSt05Event)];
    int size_OUT_buf_eventInfo=0;
    static char OUT_buf_nextCounter[sizeof(asn1SccPusUInt64)];
    int size_OUT_buf_nextCounter=0;

    /* Encode each input parameter */
    size_IN_buf_actualCounter = Encode_NATIVE_PusUInt64(IN_buf_actualCounter, sizeof(asn1SccPusUInt64), IN_actualCounter);
    if (-1 == size_IN_buf_actualCounter) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_getNextEvent_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_getNextEvent_vt(void *, size_t, void *, size_t *, void *, size_t *);

    vm_tcdispatch_getNextEvent_vt(IN_buf_actualCounter, size_IN_buf_actualCounter, OUT_buf_eventInfo, &size_OUT_buf_eventInfo, OUT_buf_nextCounter, &size_OUT_buf_nextCounter);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusSt05Event(OUT_eventInfo, OUT_buf_eventInfo, size_OUT_buf_eventInfo)) {
#ifdef __unix__
        printf("\nError Decoding PusSt05Event\n");
#endif
        return;
    }

    if (0 != Decode_NATIVE_PusUInt64(OUT_nextCounter, OUT_buf_nextCounter, size_OUT_buf_nextCounter)) {
#ifdef __unix__
        printf("\nError Decoding PusUInt64\n");
#endif
        return;
    }

}

void tcdispatch_RI_newTc_vt(const asn1SccPusPacket *IN_tcPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: newTc_vt::PusPacket::tcPacket", IN_tcPacket);
        }
        printf ("\nINNER: tcdispatch,tcqueue,newTc_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_tcPacket[sizeof(asn1SccPusPacket)] = {0};
    int size_IN_buf_tcPacket=0;

    /* Encode each input parameter */
    size_IN_buf_tcPacket = Encode_NATIVE_PusPacket(IN_buf_tcPacket, sizeof(asn1SccPusPacket), IN_tcPacket);
    if (-1 == size_IN_buf_tcPacket) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_newTc_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_async_tcdispatch_newTc_vt(void *, size_t);

    vm_async_tcdispatch_newTc_vt(IN_buf_tcPacket, size_IN_buf_tcPacket);

}

void tcdispatch_RI_pushNewEvent_vt(const asn1SccPusSt05Event *IN_eventInfo)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusSt05Event ("INNERDATA: pushNewEvent_vt::PusSt05Event::eventInfo", IN_eventInfo);
        }
        printf ("\nINNER: tcdispatch,events,pushNewEvent_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_eventInfo[sizeof(asn1SccPusSt05Event)] = {0};
    int size_IN_buf_eventInfo=0;

    /* Encode each input parameter */
    size_IN_buf_eventInfo = Encode_NATIVE_PusSt05Event(IN_buf_eventInfo, sizeof(asn1SccPusSt05Event), IN_eventInfo);
    if (-1 == size_IN_buf_eventInfo) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_pushNewEvent_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_pushNewEvent_vt(void *, size_t);

    vm_tcdispatch_pushNewEvent_vt(IN_buf_eventInfo, size_IN_buf_eventInfo);

}

void tcdispatch_RI_getParamValue_vt(const asn1SccPusSt03ParameterId *IN_paramId, asn1SccPusSt03StoredParam *OUT_paramValue, asn1SccPusSt01FailureCode *OUT_isAvailable)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusSt03ParameterId ("INNERDATA: getParamValue_vt::PusSt03ParameterId::paramId", IN_paramId);
        }
        printf ("\nINNER: tcdispatch,housekeeping,getParamValue_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_paramId[sizeof(asn1SccPusSt03ParameterId)] = {0};
    int size_IN_buf_paramId=0;

    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_paramValue[sizeof(asn1SccPusSt03StoredParam)];
    int size_OUT_buf_paramValue=0;
    static char OUT_buf_isAvailable[sizeof(asn1SccPusSt01FailureCode)];
    int size_OUT_buf_isAvailable=0;

    /* Encode each input parameter */
    size_IN_buf_paramId = Encode_NATIVE_PusSt03ParameterId(IN_buf_paramId, sizeof(asn1SccPusSt03ParameterId), IN_paramId);
    if (-1 == size_IN_buf_paramId) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_getParamValue_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_getParamValue_vt(void *, size_t, void *, size_t *, void *, size_t *);

    vm_tcdispatch_getParamValue_vt(IN_buf_paramId, size_IN_buf_paramId, OUT_buf_paramValue, &size_OUT_buf_paramValue, OUT_buf_isAvailable, &size_OUT_buf_isAvailable);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusSt03StoredParam(OUT_paramValue, OUT_buf_paramValue, size_OUT_buf_paramValue)) {
#ifdef __unix__
        printf("\nError Decoding PusSt03StoredParam\n");
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

void tcdispatch_RI_loadDirect_vt(const asn1SccPusSt18ObcpId *IN_obcpId, const asn1SccPusSt18ObcpCode *IN_obcpCode)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusSt18ObcpId ("INNERDATA: loadDirect_vt::PusSt18ObcpId::obcpId", IN_obcpId);
        }
        {
            PrintASN1PusSt18ObcpCode ("INNERDATA: loadDirect_vt::PusSt18ObcpCode::obcpCode", IN_obcpCode);
        }
        printf ("\nINNER: tcdispatch,obcpengine,loadDirect_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_obcpId[sizeof(asn1SccPusSt18ObcpId)] = {0};
    int size_IN_buf_obcpId=0;
    static char IN_buf_obcpCode[sizeof(asn1SccPusSt18ObcpCode)] = {0};
    int size_IN_buf_obcpCode=0;

    /* Encode each input parameter */
    size_IN_buf_obcpId = Encode_NATIVE_PusSt18ObcpId(IN_buf_obcpId, sizeof(asn1SccPusSt18ObcpId), IN_obcpId);
    if (-1 == size_IN_buf_obcpId) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_loadDirect_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_obcpCode = Encode_NATIVE_PusSt18ObcpCode(IN_buf_obcpCode, sizeof(asn1SccPusSt18ObcpCode), IN_obcpCode);
    if (-1 == size_IN_buf_obcpCode) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_loadDirect_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_loadDirect_vt(void *, size_t, void *, size_t);

    vm_tcdispatch_loadDirect_vt(IN_buf_obcpId, size_IN_buf_obcpId, IN_buf_obcpCode, size_IN_buf_obcpCode);

}

void tcdispatch_RI_loadReference_vt(const asn1SccPusTC_18_13_Data *IN_referenceData)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusTC_18_13_Data ("INNERDATA: loadReference_vt::PusTC_18_13_Data::referenceData", IN_referenceData);
        }
        printf ("\nINNER: tcdispatch,obcpengine,loadReference_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_referenceData[sizeof(asn1SccPusTC_18_13_Data)] = {0};
    int size_IN_buf_referenceData=0;

    /* Encode each input parameter */
    size_IN_buf_referenceData = Encode_NATIVE_PusTC_18_13_Data(IN_buf_referenceData, sizeof(asn1SccPusTC_18_13_Data), IN_referenceData);
    if (-1 == size_IN_buf_referenceData) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_loadReference_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_loadReference_vt(void *, size_t);

    vm_tcdispatch_loadReference_vt(IN_buf_referenceData, size_IN_buf_referenceData);

}

void tcdispatch_RI_getOnBoardParam_vt(const asn1SccPusSt20OnBoardParameterId *IN_paramId, asn1SccPusSt20StoredParam *OUT_paramValue, asn1SccPusSt01FailureCode *OUT_isAvailable)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusSt20OnBoardParameterId ("INNERDATA: getOnBoardParam_vt::PusSt20OnBoardParameterId::paramId", IN_paramId);
        }
        printf ("\nINNER: tcdispatch,onboardparams,getOnBoardParam_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_paramId[sizeof(asn1SccPusSt20OnBoardParameterId)] = {0};
    int size_IN_buf_paramId=0;

    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_paramValue[sizeof(asn1SccPusSt20StoredParam)];
    int size_OUT_buf_paramValue=0;
    static char OUT_buf_isAvailable[sizeof(asn1SccPusSt01FailureCode)];
    int size_OUT_buf_isAvailable=0;

    /* Encode each input parameter */
    size_IN_buf_paramId = Encode_NATIVE_PusSt20OnBoardParameterId(IN_buf_paramId, sizeof(asn1SccPusSt20OnBoardParameterId), IN_paramId);
    if (-1 == size_IN_buf_paramId) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_getOnBoardParam_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_getOnBoardParam_vt(void *, size_t, void *, size_t *, void *, size_t *);

    vm_tcdispatch_getOnBoardParam_vt(IN_buf_paramId, size_IN_buf_paramId, OUT_buf_paramValue, &size_OUT_buf_paramValue, OUT_buf_isAvailable, &size_OUT_buf_isAvailable);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusSt20StoredParam(OUT_paramValue, OUT_buf_paramValue, size_OUT_buf_paramValue)) {
#ifdef __unix__
        printf("\nError Decoding PusSt20StoredParam\n");
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

void tcdispatch_RI_setOnBoardParam_vt(const asn1SccPusSt20OnBoardParameterId *IN_paramId, const asn1SccPusSt20StoredParam *IN_paramValue)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusSt20OnBoardParameterId ("INNERDATA: setOnBoardParam_vt::PusSt20OnBoardParameterId::paramId", IN_paramId);
        }
        {
            PrintASN1PusSt20StoredParam ("INNERDATA: setOnBoardParam_vt::PusSt20StoredParam::paramValue", IN_paramValue);
        }
        printf ("\nINNER: tcdispatch,onboardparams,setOnBoardParam_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_paramId[sizeof(asn1SccPusSt20OnBoardParameterId)] = {0};
    int size_IN_buf_paramId=0;
    static char IN_buf_paramValue[sizeof(asn1SccPusSt20StoredParam)] = {0};
    int size_IN_buf_paramValue=0;

    /* Encode each input parameter */
    size_IN_buf_paramId = Encode_NATIVE_PusSt20OnBoardParameterId(IN_buf_paramId, sizeof(asn1SccPusSt20OnBoardParameterId), IN_paramId);
    if (-1 == size_IN_buf_paramId) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_setOnBoardParam_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_paramValue = Encode_NATIVE_PusSt20StoredParam(IN_buf_paramValue, sizeof(asn1SccPusSt20StoredParam), IN_paramValue);
    if (-1 == size_IN_buf_paramValue) {
#ifdef __unix__
        printf ("** Encoding error in tcdispatch_RI_setOnBoardParam_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_tcdispatch_setOnBoardParam_vt(void *, size_t, void *, size_t);

    vm_tcdispatch_setOnBoardParam_vt(IN_buf_paramId, size_IN_buf_paramId, IN_buf_paramValue, size_IN_buf_paramValue);

}

void tcdispatch_RI_copy_vt()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tcdispatch,filemanagement,copy_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_tcdispatch_copy_vt();

    vm_tcdispatch_copy_vt();

}

void tcdispatch_RI_delete_vt()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tcdispatch,filemanagement,delete_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_tcdispatch_delete_vt();

    vm_tcdispatch_delete_vt();

}

void tcdispatch_RI_create_vt()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tcdispatch,filemanagement,create_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_tcdispatch_create_vt();

    vm_tcdispatch_create_vt();

}

void tcdispatch_RI_getAttributes_vt()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: tcdispatch,filemanagement,getAttributes_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_tcdispatch_getAttributes_vt();

    vm_tcdispatch_getAttributes_vt();

}

