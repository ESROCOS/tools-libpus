/* This file was generated automatically: DO NOT MODIFY IT ! */

#include <stdlib.h>
#ifdef __unix__
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#endif

#include "C_ASN1_Types.h"
#include "st05_polyorb_interface.h"

void st05_RI_newTmNoInherit(const asn1SccPusPacket *IN_tmPacket)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusPacket ("INNERDATA: newTmNoInherit::PusPacket::tmPacket", IN_tmPacket);
        }
        printf ("\nINNER: st05,tmqueue,newTmNoInherit,%lld\n", msc_time);
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
        printf ("** Encoding error in st05_RI_newTmNoInherit!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st05_newTmNoInherit(void *, size_t);

    vm_st05_newTmNoInherit(IN_buf_tmPacket, size_IN_buf_tmPacket);

}

void st05_RI_getNextEvent(const asn1SccPusUInt64 *IN_actualCounter, asn1SccPusSt05Event *OUT_eventInfo, asn1SccPusUInt64 *OUT_nextCounter)
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
        printf ("\nINNER: st05,events,getNextEvent,%lld\n", msc_time);
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
        printf ("** Encoding error in st05_RI_getNextEvent!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st05_getNextEvent(void *, size_t, void *, size_t *, void *, size_t *);

    vm_st05_getNextEvent(IN_buf_actualCounter, size_IN_buf_actualCounter, OUT_buf_eventInfo, &size_OUT_buf_eventInfo, OUT_buf_nextCounter, &size_OUT_buf_nextCounter);

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

void st05_RI_getApid(asn1SccPusApid *OUT_apid)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st05,onboardapid,getApid,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_apid[sizeof(asn1SccPusApid)];
    int size_OUT_buf_apid=0;

    /* Call to VM callback function */
    extern void vm_st05_getApid(void *, size_t *);

    vm_st05_getApid(OUT_buf_apid, &size_OUT_buf_apid);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusApid(OUT_apid, OUT_buf_apid, size_OUT_buf_apid)) {
#ifdef __unix__
        printf("\nError Decoding PusApid\n");
#endif
        return;
    }

}

void st05_RI_getSequenceCount(asn1SccPusSequenceCount *OUT_sequenceCount)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st05,onboardapid,getSequenceCount,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_sequenceCount[sizeof(asn1SccPusSequenceCount)];
    int size_OUT_buf_sequenceCount=0;

    /* Call to VM callback function */
    extern void vm_st05_getSequenceCount(void *, size_t *);

    vm_st05_getSequenceCount(OUT_buf_sequenceCount, &size_OUT_buf_sequenceCount);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusSequenceCount(OUT_sequenceCount, OUT_buf_sequenceCount, size_OUT_buf_sequenceCount)) {
#ifdef __unix__
        printf("\nError Decoding PusSequenceCount\n");
#endif
        return;
    }

}

void st05_RI_check_queue(asn1SccT_Boolean *OUT_res)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st05,x86_partition_taste_api,check_queue,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_res[sizeof(asn1SccT_Boolean)];
    int size_OUT_buf_res=0;

    /* Call to VM callback function */
    extern void vm_st05_check_queue(void *, size_t *);

    vm_st05_check_queue(OUT_buf_res, &size_OUT_buf_res);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_T_Boolean(OUT_res, OUT_buf_res, size_OUT_buf_res)) {
#ifdef __unix__
        printf("\nError Decoding T_Boolean\n");
#endif
        return;
    }

}

void st05_RI_incCount_vt(asn1SccPusPacket *OUT_tmPacket, asn1SccPusSt01FailureCode *OUT_isAvailable)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st05,st09,incCount_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_tmPacket[sizeof(asn1SccPusPacket)];
    int size_OUT_buf_tmPacket=0;
    static char OUT_buf_isAvailable[sizeof(asn1SccPusSt01FailureCode)];
    int size_OUT_buf_isAvailable=0;

    /* Call to VM callback function */
    extern void vm_st05_incCount_vt(void *, size_t *, void *, size_t *);

    vm_st05_incCount_vt(OUT_buf_tmPacket, &size_OUT_buf_tmPacket, OUT_buf_isAvailable, &size_OUT_buf_isAvailable);

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

void st05_RI_newTm_vt(const asn1SccPusPacket *IN_tmPacket)
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
        printf ("\nINNER: st05,tmqueue,newTm_vt,%lld\n", msc_time);
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
        printf ("** Encoding error in st05_RI_newTm_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st05_newTm_vt(void *, size_t);

    vm_st05_newTm_vt(IN_buf_tmPacket, size_IN_buf_tmPacket);

}

void st05_RI_getSequenceCount_vt(asn1SccPusSequenceCount *OUT_sequenceCount)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st05,onboardapid,getSequenceCount_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_sequenceCount[sizeof(asn1SccPusSequenceCount)];
    int size_OUT_buf_sequenceCount=0;

    /* Call to VM callback function */
    extern void vm_st05_getSequenceCount_vt(void *, size_t *);

    vm_st05_getSequenceCount_vt(OUT_buf_sequenceCount, &size_OUT_buf_sequenceCount);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusSequenceCount(OUT_sequenceCount, OUT_buf_sequenceCount, size_OUT_buf_sequenceCount)) {
#ifdef __unix__
        printf("\nError Decoding PusSequenceCount\n");
#endif
        return;
    }

}

void st05_RI_getApid_vt(asn1SccPusApid *OUT_apid)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st05,onboardapid,getApid_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_apid[sizeof(asn1SccPusApid)];
    int size_OUT_buf_apid=0;

    /* Call to VM callback function */
    extern void vm_st05_getApid_vt(void *, size_t *);

    vm_st05_getApid_vt(OUT_buf_apid, &size_OUT_buf_apid);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusApid(OUT_apid, OUT_buf_apid, size_OUT_buf_apid)) {
#ifdef __unix__
        printf("\nError Decoding PusApid\n");
#endif
        return;
    }

}

void st05_RI_ACK_vt(const asn1SccPusPacket *IN_tcPacket, const asn1SccPusSubserviceType *IN_reportType, const asn1SccPusSt01FailureCode *IN_error, const asn1SccPusSt01FailureInfo *IN_errorInfo, const asn1SccPusStepId *IN_step)
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
        printf ("\nINNER: st05,st01,ACK_vt,%lld\n", msc_time);
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
        printf ("** Encoding error in st05_RI_ACK_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_reportType = Encode_NATIVE_PusSubserviceType(IN_buf_reportType, sizeof(asn1SccPusSubserviceType), IN_reportType);
    if (-1 == size_IN_buf_reportType) {
#ifdef __unix__
        printf ("** Encoding error in st05_RI_ACK_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_error = Encode_NATIVE_PusSt01FailureCode(IN_buf_error, sizeof(asn1SccPusSt01FailureCode), IN_error);
    if (-1 == size_IN_buf_error) {
#ifdef __unix__
        printf ("** Encoding error in st05_RI_ACK_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_errorInfo = Encode_NATIVE_PusSt01FailureInfo(IN_buf_errorInfo, sizeof(asn1SccPusSt01FailureInfo), IN_errorInfo);
    if (-1 == size_IN_buf_errorInfo) {
#ifdef __unix__
        printf ("** Encoding error in st05_RI_ACK_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_step = Encode_NATIVE_PusStepId(IN_buf_step, sizeof(asn1SccPusStepId), IN_step);
    if (-1 == size_IN_buf_step) {
#ifdef __unix__
        printf ("** Encoding error in st05_RI_ACK_vt!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st05_ACK_vt(void *, size_t, void *, size_t, void *, size_t, void *, size_t, void *, size_t);

    vm_st05_ACK_vt(IN_buf_tcPacket, size_IN_buf_tcPacket, IN_buf_reportType, size_IN_buf_reportType, IN_buf_error, size_IN_buf_error, IN_buf_errorInfo, size_IN_buf_errorInfo, IN_buf_step, size_IN_buf_step);

}

void st05_RI_check_queue_vt(asn1SccT_Boolean *OUT_res)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st05,x86_partition_taste_api,check_queue_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_res[sizeof(asn1SccT_Boolean)];
    int size_OUT_buf_res=0;

    /* Call to VM callback function */
    extern void vm_st05_check_queue_vt(void *, size_t *);

    vm_st05_check_queue_vt(OUT_buf_res, &size_OUT_buf_res);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_T_Boolean(OUT_res, OUT_buf_res, size_OUT_buf_res)) {
#ifdef __unix__
        printf("\nError Decoding T_Boolean\n");
#endif
        return;
    }

}

