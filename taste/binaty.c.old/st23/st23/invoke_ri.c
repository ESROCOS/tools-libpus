/* This file was generated automatically: DO NOT MODIFY IT ! */

#include <stdlib.h>
#ifdef __unix__
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#endif

#include "C_ASN1_Types.h"
#include "st23_polyorb_interface.h"

void st23_RI_copy()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st23,filemanagement,copy,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_st23_copy();

    vm_st23_copy();

}

void st23_RI_delete()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st23,filemanagement,delete,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_st23_delete();

    vm_st23_delete();

}

void st23_RI_create()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st23,filemanagement,create,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_st23_create();

    vm_st23_create();

}

void st23_RI_getAttributes()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st23,filemanagement,getAttributes,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_st23_getAttributes();

    vm_st23_getAttributes();

}

void st23_RI_newTm(const asn1SccPusPacket *IN_tmPacket)
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
        printf ("\nINNER: st23,tmqueue,newTm,%lld\n", msc_time);
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
        printf ("** Encoding error in st23_RI_newTm!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st23_newTm(void *, size_t);

    vm_st23_newTm(IN_buf_tmPacket, size_IN_buf_tmPacket);

}

void st23_RI_getApid(asn1SccPusApid *OUT_apid)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st23,onboardapid,getApid,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_apid[sizeof(asn1SccPusApid)];
    int size_OUT_buf_apid=0;

    /* Call to VM callback function */
    extern void vm_st23_getApid(void *, size_t *);

    vm_st23_getApid(OUT_buf_apid, &size_OUT_buf_apid);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusApid(OUT_apid, OUT_buf_apid, size_OUT_buf_apid)) {
#ifdef __unix__
        printf("\nError Decoding PusApid\n");
#endif
        return;
    }

}

void st23_RI_getSequenceCount(asn1SccPusSequenceCount *OUT_sequenceCount)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st23,onboardapid,getSequenceCount,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_sequenceCount[sizeof(asn1SccPusSequenceCount)];
    int size_OUT_buf_sequenceCount=0;

    /* Call to VM callback function */
    extern void vm_st23_getSequenceCount(void *, size_t *);

    vm_st23_getSequenceCount(OUT_buf_sequenceCount, &size_OUT_buf_sequenceCount);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusSequenceCount(OUT_sequenceCount, OUT_buf_sequenceCount, size_OUT_buf_sequenceCount)) {
#ifdef __unix__
        printf("\nError Decoding PusSequenceCount\n");
#endif
        return;
    }

}

void st23_RI_ACK(const asn1SccPusPacket *IN_tcPacket, const asn1SccPusSubserviceType *IN_reportType, const asn1SccPusSt01FailureCode *IN_error, const asn1SccPusSt01FailureInfo *IN_errorInfo, const asn1SccPusStepId *IN_step)
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
        printf ("\nINNER: st23,st01,ACK,%lld\n", msc_time);
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
        printf ("** Encoding error in st23_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_reportType = Encode_NATIVE_PusSubserviceType(IN_buf_reportType, sizeof(asn1SccPusSubserviceType), IN_reportType);
    if (-1 == size_IN_buf_reportType) {
#ifdef __unix__
        printf ("** Encoding error in st23_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_error = Encode_NATIVE_PusSt01FailureCode(IN_buf_error, sizeof(asn1SccPusSt01FailureCode), IN_error);
    if (-1 == size_IN_buf_error) {
#ifdef __unix__
        printf ("** Encoding error in st23_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_errorInfo = Encode_NATIVE_PusSt01FailureInfo(IN_buf_errorInfo, sizeof(asn1SccPusSt01FailureInfo), IN_errorInfo);
    if (-1 == size_IN_buf_errorInfo) {
#ifdef __unix__
        printf ("** Encoding error in st23_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_step = Encode_NATIVE_PusStepId(IN_buf_step, sizeof(asn1SccPusStepId), IN_step);
    if (-1 == size_IN_buf_step) {
#ifdef __unix__
        printf ("** Encoding error in st23_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st23_ACK(void *, size_t, void *, size_t, void *, size_t, void *, size_t, void *, size_t);

    vm_st23_ACK(IN_buf_tcPacket, size_IN_buf_tcPacket, IN_buf_reportType, size_IN_buf_reportType, IN_buf_error, size_IN_buf_error, IN_buf_errorInfo, size_IN_buf_errorInfo, IN_buf_step, size_IN_buf_step);

}

