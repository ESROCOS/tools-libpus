/* This file was generated automatically: DO NOT MODIFY IT ! */

#include <stdlib.h>
#ifdef __unix__
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#endif

#include "C_ASN1_Types.h"
#include "st12_polyorb_interface.h"

void st12_RI_pushNewEvent(const asn1SccPusSt05Event *IN_eventInfo)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusSt05Event ("INNERDATA: pushNewEvent::PusSt05Event::eventInfo", IN_eventInfo);
        }
        printf ("\nINNER: st12,events,pushNewEvent,%lld\n", msc_time);
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
        printf ("** Encoding error in st12_RI_pushNewEvent!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st12_pushNewEvent(void *, size_t);

    vm_st12_pushNewEvent(IN_buf_eventInfo, size_IN_buf_eventInfo);

}

void st12_RI_getParamValue(const asn1SccPusSt03ParameterId *IN_paramId, asn1SccPusSt03StoredParam *OUT_paramValue, asn1SccPusSt01FailureCode *OUT_isAvailable)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusSt03ParameterId ("INNERDATA: getParamValue::PusSt03ParameterId::paramId", IN_paramId);
        }
        printf ("\nINNER: st12,housekeeping,getParamValue,%lld\n", msc_time);
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
        printf ("** Encoding error in st12_RI_getParamValue!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st12_getParamValue(void *, size_t, void *, size_t *, void *, size_t *);

    vm_st12_getParamValue(IN_buf_paramId, size_IN_buf_paramId, OUT_buf_paramValue, &size_OUT_buf_paramValue, OUT_buf_isAvailable, &size_OUT_buf_isAvailable);

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

void st12_RI_ACK(const asn1SccPusPacket *IN_tcPacket, const asn1SccPusSubserviceType *IN_reportType, const asn1SccPusSt01FailureCode *IN_error, const asn1SccPusSt01FailureInfo *IN_errorInfo, const asn1SccPusStepId *IN_step)
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
        printf ("\nINNER: st12,st01,ACK,%lld\n", msc_time);
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
        printf ("** Encoding error in st12_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_reportType = Encode_NATIVE_PusSubserviceType(IN_buf_reportType, sizeof(asn1SccPusSubserviceType), IN_reportType);
    if (-1 == size_IN_buf_reportType) {
#ifdef __unix__
        printf ("** Encoding error in st12_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_error = Encode_NATIVE_PusSt01FailureCode(IN_buf_error, sizeof(asn1SccPusSt01FailureCode), IN_error);
    if (-1 == size_IN_buf_error) {
#ifdef __unix__
        printf ("** Encoding error in st12_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_errorInfo = Encode_NATIVE_PusSt01FailureInfo(IN_buf_errorInfo, sizeof(asn1SccPusSt01FailureInfo), IN_errorInfo);
    if (-1 == size_IN_buf_errorInfo) {
#ifdef __unix__
        printf ("** Encoding error in st12_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_step = Encode_NATIVE_PusStepId(IN_buf_step, sizeof(asn1SccPusStepId), IN_step);
    if (-1 == size_IN_buf_step) {
#ifdef __unix__
        printf ("** Encoding error in st12_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st12_ACK(void *, size_t, void *, size_t, void *, size_t, void *, size_t, void *, size_t);

    vm_st12_ACK(IN_buf_tcPacket, size_IN_buf_tcPacket, IN_buf_reportType, size_IN_buf_reportType, IN_buf_error, size_IN_buf_error, IN_buf_errorInfo, size_IN_buf_errorInfo, IN_buf_step, size_IN_buf_step);

}

void st12_RI_check_queue(asn1SccT_Boolean *OUT_res)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st12,x86_partition_taste_api,check_queue,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_res[sizeof(asn1SccT_Boolean)];
    int size_OUT_buf_res=0;

    /* Call to VM callback function */
    extern void vm_st12_check_queue(void *, size_t *);

    vm_st12_check_queue(OUT_buf_res, &size_OUT_buf_res);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_T_Boolean(OUT_res, OUT_buf_res, size_OUT_buf_res)) {
#ifdef __unix__
        printf("\nError Decoding T_Boolean\n");
#endif
        return;
    }

}

