/* This file was generated automatically: DO NOT MODIFY IT ! */

#include <stdlib.h>
#ifdef __unix__
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#endif

#include "C_ASN1_Types.h"
#include "onboardsoftware_polyorb_interface.h"

void onboardsoftware_RI_setParamValue(const asn1SccPusSt03ParameterId *IN_paramId, const asn1SccPusSt03StoredParam *IN_paramValue)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusSt03ParameterId ("INNERDATA: setParamValue::PusSt03ParameterId::paramId", IN_paramId);
        }
        {
            PrintASN1PusSt03StoredParam ("INNERDATA: setParamValue::PusSt03StoredParam::paramValue", IN_paramValue);
        }
        printf ("\nINNER: onboardsoftware,housekeeping,setParamValue,%lld\n", msc_time);
        fflush(stdout);
    }
#endif

    /* Buffer(s) to put the encoded input parameter(s) */
    static char IN_buf_paramId[sizeof(asn1SccPusSt03ParameterId)] = {0};
    int size_IN_buf_paramId=0;
    static char IN_buf_paramValue[sizeof(asn1SccPusSt03StoredParam)] = {0};
    int size_IN_buf_paramValue=0;

    /* Encode each input parameter */
    size_IN_buf_paramId = Encode_NATIVE_PusSt03ParameterId(IN_buf_paramId, sizeof(asn1SccPusSt03ParameterId), IN_paramId);
    if (-1 == size_IN_buf_paramId) {
#ifdef __unix__
        printf ("** Encoding error in onboardsoftware_RI_setParamValue!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_paramValue = Encode_NATIVE_PusSt03StoredParam(IN_buf_paramValue, sizeof(asn1SccPusSt03StoredParam), IN_paramValue);
    if (-1 == size_IN_buf_paramValue) {
#ifdef __unix__
        printf ("** Encoding error in onboardsoftware_RI_setParamValue!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_onboardsoftware_setParamValue(void *, size_t, void *, size_t);

    vm_onboardsoftware_setParamValue(IN_buf_paramId, size_IN_buf_paramId, IN_buf_paramValue, size_IN_buf_paramValue);

}

void onboardsoftware_RI_getParamValue(const asn1SccPusSt03ParameterId *IN_paramId, asn1SccPusSt03StoredParam *OUT_paramValue, asn1SccPusSt01FailureCode *OUT_isAvailable)
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
        printf ("\nINNER: onboardsoftware,housekeeping,getParamValue,%lld\n", msc_time);
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
        printf ("** Encoding error in onboardsoftware_RI_getParamValue!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_onboardsoftware_getParamValue(void *, size_t, void *, size_t *, void *, size_t *);

    vm_onboardsoftware_getParamValue(IN_buf_paramId, size_IN_buf_paramId, OUT_buf_paramValue, &size_OUT_buf_paramValue, OUT_buf_isAvailable, &size_OUT_buf_isAvailable);

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

void onboardsoftware_RI_pushNewEvent(const asn1SccPusSt05Event *IN_eventInfo)
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
        printf ("\nINNER: onboardsoftware,events,pushNewEvent,%lld\n", msc_time);
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
        printf ("** Encoding error in onboardsoftware_RI_pushNewEvent!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_onboardsoftware_pushNewEvent(void *, size_t);

    vm_onboardsoftware_pushNewEvent(IN_buf_eventInfo, size_IN_buf_eventInfo);

}

void onboardsoftware_RI_setOnBoardParam(const asn1SccPusSt20OnBoardParameterId *IN_paramId, const asn1SccPusSt20StoredParam *IN_paramValue)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusSt20OnBoardParameterId ("INNERDATA: setOnBoardParam::PusSt20OnBoardParameterId::paramId", IN_paramId);
        }
        {
            PrintASN1PusSt20StoredParam ("INNERDATA: setOnBoardParam::PusSt20StoredParam::paramValue", IN_paramValue);
        }
        printf ("\nINNER: onboardsoftware,onboardparams,setOnBoardParam,%lld\n", msc_time);
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
        printf ("** Encoding error in onboardsoftware_RI_setOnBoardParam!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_paramValue = Encode_NATIVE_PusSt20StoredParam(IN_buf_paramValue, sizeof(asn1SccPusSt20StoredParam), IN_paramValue);
    if (-1 == size_IN_buf_paramValue) {
#ifdef __unix__
        printf ("** Encoding error in onboardsoftware_RI_setOnBoardParam!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_onboardsoftware_setOnBoardParam(void *, size_t, void *, size_t);

    vm_onboardsoftware_setOnBoardParam(IN_buf_paramId, size_IN_buf_paramId, IN_buf_paramValue, size_IN_buf_paramValue);

}

void onboardsoftware_RI_getOnBoardParam(const asn1SccPusSt20OnBoardParameterId *IN_paramId, asn1SccPusSt20StoredParam *OUT_paramValue, asn1SccPusSt01FailureCode *OUT_isAvailable)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusSt20OnBoardParameterId ("INNERDATA: getOnBoardParam::PusSt20OnBoardParameterId::paramId", IN_paramId);
        }
        printf ("\nINNER: onboardsoftware,onboardparams,getOnBoardParam,%lld\n", msc_time);
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
        printf ("** Encoding error in onboardsoftware_RI_getOnBoardParam!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_onboardsoftware_getOnBoardParam(void *, size_t, void *, size_t *, void *, size_t *);

    vm_onboardsoftware_getOnBoardParam(IN_buf_paramId, size_IN_buf_paramId, OUT_buf_paramValue, &size_OUT_buf_paramValue, OUT_buf_isAvailable, &size_OUT_buf_isAvailable);

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

void onboardsoftware_RI_check_queue(asn1SccT_Boolean *OUT_res)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: onboardsoftware,x86_partition_taste_api,check_queue,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_res[sizeof(asn1SccT_Boolean)];
    int size_OUT_buf_res=0;

    /* Call to VM callback function */
    extern void vm_onboardsoftware_check_queue(void *, size_t *);

    vm_onboardsoftware_check_queue(OUT_buf_res, &size_OUT_buf_res);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_T_Boolean(OUT_res, OUT_buf_res, size_OUT_buf_res)) {
#ifdef __unix__
        printf("\nError Decoding T_Boolean\n");
#endif
        return;
    }

}

void onboardsoftware_RI_check_queue_vt(asn1SccT_Boolean *OUT_res)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: onboardsoftware,x86_partition_taste_api,check_queue_vt,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_res[sizeof(asn1SccT_Boolean)];
    int size_OUT_buf_res=0;

    /* Call to VM callback function */
    extern void vm_onboardsoftware_check_queue_vt(void *, size_t *);

    vm_onboardsoftware_check_queue_vt(OUT_buf_res, &size_OUT_buf_res);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_T_Boolean(OUT_res, OUT_buf_res, size_OUT_buf_res)) {
#ifdef __unix__
        printf("\nError Decoding T_Boolean\n");
#endif
        return;
    }

}

