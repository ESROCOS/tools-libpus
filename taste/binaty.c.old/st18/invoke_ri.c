/* This file was generated automatically: DO NOT MODIFY IT ! */

#include <stdlib.h>
#ifdef __unix__
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#endif

#include "C_ASN1_Types.h"
#include "st18_polyorb_interface.h"

void st18_RI_ACK(const asn1SccPusPacket *IN_tcPacket, const asn1SccPusSubserviceType *IN_reportType, const asn1SccPusSt01FailureCode *IN_error, const asn1SccPusSt01FailureInfo *IN_errorInfo, const asn1SccPusStepId *IN_step)
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
        printf ("\nINNER: st18,st01,ACK,%lld\n", msc_time);
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
        printf ("** Encoding error in st18_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_reportType = Encode_NATIVE_PusSubserviceType(IN_buf_reportType, sizeof(asn1SccPusSubserviceType), IN_reportType);
    if (-1 == size_IN_buf_reportType) {
#ifdef __unix__
        printf ("** Encoding error in st18_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_error = Encode_NATIVE_PusSt01FailureCode(IN_buf_error, sizeof(asn1SccPusSt01FailureCode), IN_error);
    if (-1 == size_IN_buf_error) {
#ifdef __unix__
        printf ("** Encoding error in st18_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_errorInfo = Encode_NATIVE_PusSt01FailureInfo(IN_buf_errorInfo, sizeof(asn1SccPusSt01FailureInfo), IN_errorInfo);
    if (-1 == size_IN_buf_errorInfo) {
#ifdef __unix__
        printf ("** Encoding error in st18_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_step = Encode_NATIVE_PusStepId(IN_buf_step, sizeof(asn1SccPusStepId), IN_step);
    if (-1 == size_IN_buf_step) {
#ifdef __unix__
        printf ("** Encoding error in st18_RI_ACK!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st18_ACK(void *, size_t, void *, size_t, void *, size_t, void *, size_t, void *, size_t);

    vm_st18_ACK(IN_buf_tcPacket, size_IN_buf_tcPacket, IN_buf_reportType, size_IN_buf_reportType, IN_buf_error, size_IN_buf_error, IN_buf_errorInfo, size_IN_buf_errorInfo, IN_buf_step, size_IN_buf_step);

}

void st18_RI_loadDirect(const asn1SccPusSt18ObcpId *IN_obcpId, const asn1SccPusSt18ObcpCode *IN_obcpCode)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusSt18ObcpId ("INNERDATA: loadDirect::PusSt18ObcpId::obcpId", IN_obcpId);
        }
        {
            PrintASN1PusSt18ObcpCode ("INNERDATA: loadDirect::PusSt18ObcpCode::obcpCode", IN_obcpCode);
        }
        printf ("\nINNER: st18,obcpengine,loadDirect,%lld\n", msc_time);
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
        printf ("** Encoding error in st18_RI_loadDirect!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }
    size_IN_buf_obcpCode = Encode_NATIVE_PusSt18ObcpCode(IN_buf_obcpCode, sizeof(asn1SccPusSt18ObcpCode), IN_obcpCode);
    if (-1 == size_IN_buf_obcpCode) {
#ifdef __unix__
        printf ("** Encoding error in st18_RI_loadDirect!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st18_loadDirect(void *, size_t, void *, size_t);

    vm_st18_loadDirect(IN_buf_obcpId, size_IN_buf_obcpId, IN_buf_obcpCode, size_IN_buf_obcpCode);

}

void st18_RI_loadReference(const asn1SccPusTC_18_13_Data *IN_referenceData)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        {
            PrintASN1PusTC_18_13_Data ("INNERDATA: loadReference::PusTC_18_13_Data::referenceData", IN_referenceData);
        }
        printf ("\nINNER: st18,obcpengine,loadReference,%lld\n", msc_time);
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
        printf ("** Encoding error in st18_RI_loadReference!!\n");
#endif
        /* Crash the application due to message loss */
        extern void abort (void);
        abort();
    }

    /* Call to VM callback function */
    extern void vm_st18_loadReference(void *, size_t);

    vm_st18_loadReference(IN_buf_referenceData, size_IN_buf_referenceData);

}

