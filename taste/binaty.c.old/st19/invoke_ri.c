/* This file was generated automatically: DO NOT MODIFY IT ! */

#include <stdlib.h>
#ifdef __unix__
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#endif

#include "C_ASN1_Types.h"
#include "st19_polyorb_interface.h"

void st19_RI_getNextEvent(const asn1SccPusUInt64 *IN_actualCounter, asn1SccPusSt05Event *OUT_eventInfo, asn1SccPusUInt64 *OUT_nextCounter)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusUInt64 ("INNERDATA: getNextEvent::PusUInt64::actualCounter", IN_actualCounter);
        }
        printf ("\nINNER: st19,events,getNextEvent,%lld\n", msc_time);
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
        printf ("** Encoding error in st19_RI_getNextEvent!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st19_getNextEvent(void *, size_t, void *, size_t *, void *, size_t *);

    vm_st19_getNextEvent(IN_buf_actualCounter, size_IN_buf_actualCounter, OUT_buf_eventInfo, &size_OUT_buf_eventInfo, OUT_buf_nextCounter, &size_OUT_buf_nextCounter);

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

void st19_RI_ACK(const asn1SccPusPacket *IN_tcPacket, const asn1SccPusSubserviceType *IN_reportType, const asn1SccPusSt01FailureCode *IN_error, const asn1SccPusSt01FailureInfo *IN_errorInfo, const asn1SccPusStepId *IN_step)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: ACK::PusPacket::tcPacket", IN_tcPacket);
        }
        {
            PrintASN1PusSubserviceType ("INNERDATA: ACK::PusSubserviceType::reportType", IN_reportType);
        }
        {
            PrintASN1PusSt01FailureCode ("INNERDATA: ACK::PusSt01FailureCode::error", IN_error);
        }
        {
            PrintASN1PusSt01FailureInfo ("INNERDATA: ACK::PusSt01FailureInfo::errorInfo", IN_errorInfo);
        }
        {
            PrintASN1PusStepId ("INNERDATA: ACK::PusStepId::step", IN_step);
        }
        printf ("\nINNER: st19,st01,ACK,%lld\n", msc_time);
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
        printf ("** Encoding error in st19_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_reportType = Encode_NATIVE_PusSubserviceType(IN_buf_reportType, sizeof(asn1SccPusSubserviceType), IN_reportType);
    if (-1 == size_IN_buf_reportType) {
#ifdef __unix__
        printf ("** Encoding error in st19_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_error = Encode_NATIVE_PusSt01FailureCode(IN_buf_error, sizeof(asn1SccPusSt01FailureCode), IN_error);
    if (-1 == size_IN_buf_error) {
#ifdef __unix__
        printf ("** Encoding error in st19_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_errorInfo = Encode_NATIVE_PusSt01FailureInfo(IN_buf_errorInfo, sizeof(asn1SccPusSt01FailureInfo), IN_errorInfo);
    if (-1 == size_IN_buf_errorInfo) {
#ifdef __unix__
        printf ("** Encoding error in st19_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_step = Encode_NATIVE_PusStepId(IN_buf_step, sizeof(asn1SccPusStepId), IN_step);
    if (-1 == size_IN_buf_step) {
#ifdef __unix__
        printf ("** Encoding error in st19_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st19_ACK(void *, size_t, void *, size_t, void *, size_t, void *, size_t, void *, size_t);

    vm_st19_ACK(IN_buf_tcPacket, size_IN_buf_tcPacket, IN_buf_reportType, size_IN_buf_reportType, IN_buf_error, size_IN_buf_error, IN_buf_errorInfo, size_IN_buf_errorInfo, IN_buf_step, size_IN_buf_step);

}

void st19_RI_newTm(const asn1SccPusPacket *IN_tmPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: newTm::PusPacket::tmPacket", IN_tmPacket);
        }
        printf ("\nINNER: st19,tmqueue,newTm,%lld\n", msc_time);
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
        printf ("** Encoding error in st19_RI_newTm!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st19_newTm(void *, size_t);

    vm_st19_newTm(IN_buf_tmPacket, size_IN_buf_tmPacket);

}

void st19_RI_newTc(const asn1SccPusPacket *IN_tcPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: newTc::PusPacket::tcPacket", IN_tcPacket);
        }
        printf ("\nINNER: st19,tcqueue,newTc,%lld\n", msc_time);
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
        printf ("** Encoding error in st19_RI_newTc!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_async_st19_newTc(void *, size_t);

    vm_async_st19_newTc(IN_buf_tcPacket, size_IN_buf_tcPacket);

}

void st19_RI_check_queue(asn1SccT_Boolean *OUT_res)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st19,x86_partition_taste_api,check_queue,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_res[sizeof(asn1SccT_Boolean)];
    int size_OUT_buf_res=0;

    /* Call to VM callback function */
    extern void vm_st19_check_queue(void *, size_t *);

    vm_st19_check_queue(OUT_buf_res, &size_OUT_buf_res);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_T_Boolean(OUT_res, OUT_buf_res, size_OUT_buf_res)) {
#ifdef __unix__
        printf("\nError Decoding T_Boolean\n");
#endif
        return;
    }

}

