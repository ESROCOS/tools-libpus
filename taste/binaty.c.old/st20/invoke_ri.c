/* This file was generated automatically: DO NOT MODIFY IT ! */

#include <stdlib.h>
#ifdef __unix__
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#endif

#include "C_ASN1_Types.h"
#include "st20_polyorb_interface.h"

void st20_RI_setOnBoardParam(const asn1SccPusSt20OnBoardParameterId *IN_paramId, const asn1SccPusSt20StoredParam *IN_paramValue)
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
        printf ("\nINNER: st20,onboardparams,setOnBoardParam,%lld\n", msc_time);
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
        printf ("** Encoding error in st20_RI_setOnBoardParam!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_paramValue = Encode_NATIVE_PusSt20StoredParam(IN_buf_paramValue, sizeof(asn1SccPusSt20StoredParam), IN_paramValue);
    if (-1 == size_IN_buf_paramValue) {
#ifdef __unix__
        printf ("** Encoding error in st20_RI_setOnBoardParam!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st20_setOnBoardParam(void *, size_t, void *, size_t);

    vm_st20_setOnBoardParam(IN_buf_paramId, size_IN_buf_paramId, IN_buf_paramValue, size_IN_buf_paramValue);

}

void st20_RI_getOnBoardParam(const asn1SccPusSt20OnBoardParameterId *IN_paramId, asn1SccPusSt20StoredParam *OUT_paramValue, asn1SccPusSt01FailureCode *OUT_isAvailable)
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
        printf ("\nINNER: st20,onboardparams,getOnBoardParam,%lld\n", msc_time);
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
        printf ("** Encoding error in st20_RI_getOnBoardParam!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st20_getOnBoardParam(void *, size_t, void *, size_t *, void *, size_t *);

    vm_st20_getOnBoardParam(IN_buf_paramId, size_IN_buf_paramId, OUT_buf_paramValue, &size_OUT_buf_paramValue, OUT_buf_isAvailable, &size_OUT_buf_isAvailable);

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

void st20_RI_newTm(const asn1SccPusPacket *IN_tmPacket)
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
        printf ("\nINNER: st20,tmqueue,newTm,%lld\n", msc_time);
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
        printf ("** Encoding error in st20_RI_newTm!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st20_newTm(void *, size_t);

    vm_st20_newTm(IN_buf_tmPacket, size_IN_buf_tmPacket);

}

void st20_RI_ACK(const asn1SccPusPacket *IN_tcPacket, const asn1SccPusSubserviceType *IN_reportType, const asn1SccPusSt01FailureCode *IN_error, const asn1SccPusSt01FailureInfo *IN_errorInfo, const asn1SccPusStepId *IN_step)
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
        printf ("\nINNER: st20,st01,ACK,%lld\n", msc_time);
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
        printf ("** Encoding error in st20_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_reportType = Encode_NATIVE_PusSubserviceType(IN_buf_reportType, sizeof(asn1SccPusSubserviceType), IN_reportType);
    if (-1 == size_IN_buf_reportType) {
#ifdef __unix__
        printf ("** Encoding error in st20_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_error = Encode_NATIVE_PusSt01FailureCode(IN_buf_error, sizeof(asn1SccPusSt01FailureCode), IN_error);
    if (-1 == size_IN_buf_error) {
#ifdef __unix__
        printf ("** Encoding error in st20_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_errorInfo = Encode_NATIVE_PusSt01FailureInfo(IN_buf_errorInfo, sizeof(asn1SccPusSt01FailureInfo), IN_errorInfo);
    if (-1 == size_IN_buf_errorInfo) {
#ifdef __unix__
        printf ("** Encoding error in st20_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_step = Encode_NATIVE_PusStepId(IN_buf_step, sizeof(asn1SccPusStepId), IN_step);
    if (-1 == size_IN_buf_step) {
#ifdef __unix__
        printf ("** Encoding error in st20_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st20_ACK(void *, size_t, void *, size_t, void *, size_t, void *, size_t, void *, size_t);

    vm_st20_ACK(IN_buf_tcPacket, size_IN_buf_tcPacket, IN_buf_reportType, size_IN_buf_reportType, IN_buf_error, size_IN_buf_error, IN_buf_errorInfo, size_IN_buf_errorInfo, IN_buf_step, size_IN_buf_step);

}

void st20_RI_getApid(asn1SccPusApid *OUT_apid)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st20,onboardapid,getApid,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_apid[sizeof(asn1SccPusApid)];
    int size_OUT_buf_apid=0;

    /* Call to VM callback function */
    extern void vm_st20_getApid(void *, size_t *);

    vm_st20_getApid(OUT_buf_apid, &size_OUT_buf_apid);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusApid(OUT_apid, OUT_buf_apid, size_OUT_buf_apid)) {
#ifdef __unix__
        printf("\nError Decoding PusApid\n");
#endif
        return;
    }

}

void st20_RI_getSequenceCount(asn1SccPusSequenceCount *OUT_sequenceCount)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: st20,onboardapid,getSequenceCount,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_sequenceCount[sizeof(asn1SccPusSequenceCount)];
    int size_OUT_buf_sequenceCount=0;

    /* Call to VM callback function */
    extern void vm_st20_getSequenceCount(void *, size_t *);

    vm_st20_getSequenceCount(OUT_buf_sequenceCount, &size_OUT_buf_sequenceCount);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_PusSequenceCount(OUT_sequenceCount, OUT_buf_sequenceCount, size_OUT_buf_sequenceCount)) {
#ifdef __unix__
        printf("\nError Decoding PusSequenceCount\n");
#endif
        return;
    }

}

