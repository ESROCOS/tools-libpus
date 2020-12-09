#ifdef __unix__
#include <stdio.h>
#include <assert.h>
#endif

#include <string.h>

#include "C_ASN1_Types.h"

#ifdef __NEED_PusTM_TC_Dummy_Data_UPER
int Encode_UPER_PusTM_TC_Dummy_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_TC_Dummy_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_TC_Dummy_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-TC-Dummy-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_TC_Dummy_Data_ACN
int Encode_ACN_PusTM_TC_Dummy_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_TC_Dummy_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_TC_Dummy_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-TC-Dummy-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_TC_Dummy_Data_NATIVE
int Encode_NATIVE_PusTM_TC_Dummy_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_TC_Dummy_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_TC_Dummy_Data) );
    return sizeof(asn1SccPusTM_TC_Dummy_Data);
}
#endif

#ifdef __NEED_PusTM_TC_Dummy_Data_UPER
int Decode_UPER_PusTM_TC_Dummy_Data(asn1SccPusTM_TC_Dummy_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_TC_Dummy_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-TC-Dummy-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_TC_Dummy_Data_ACN
int Decode_ACN_PusTM_TC_Dummy_Data(asn1SccPusTM_TC_Dummy_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_TC_Dummy_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-TC-Dummy-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_TC_Dummy_Data_NATIVE
int Decode_NATIVE_PusTM_TC_Dummy_Data(asn1SccPusTM_TC_Dummy_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_TC_Dummy_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTmHeader_UPER
int Encode_UPER_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeader *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmHeader_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTmHeader (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmHeader_ACN
int Encode_ACN_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmHeader *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmHeader_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTmHeader (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmHeader_NATIVE
int Encode_NATIVE_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeader *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTmHeader) );
    return sizeof(asn1SccPusTmHeader);
}
#endif

#ifdef __NEED_PusTmHeader_UPER
int Decode_UPER_PusTmHeader(asn1SccPusTmHeader *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTmHeader_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTmHeader (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTmHeader_ACN
int Decode_ACN_PusTmHeader(asn1SccPusTmHeader *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTmHeader_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTmHeader (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTmHeader_NATIVE
int Decode_NATIVE_PusTmHeader(asn1SccPusTmHeader *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTmHeader *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTmSourceData_UPER
int Encode_UPER_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmSourceData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmSourceData_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTmSourceData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmSourceData_ACN
int Encode_ACN_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmSourceData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmSourceData_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTmSourceData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmSourceData_NATIVE
int Encode_NATIVE_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmSourceData *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTmSourceData) );
    return sizeof(asn1SccPusTmSourceData);
}
#endif

#ifdef __NEED_PusTmSourceData_UPER
int Decode_UPER_PusTmSourceData(asn1SccPusTmSourceData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTmSourceData_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTmSourceData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTmSourceData_ACN
int Decode_ACN_PusTmSourceData(asn1SccPusTmSourceData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTmSourceData_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTmSourceData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTmSourceData_NATIVE
int Decode_NATIVE_PusTmSourceData(asn1SccPusTmSourceData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTmSourceData *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTcHeader_UPER
int Encode_UPER_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcHeader *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcHeader_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTcHeader (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcHeader_ACN
int Encode_ACN_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcHeader *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcHeader_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTcHeader (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcHeader_NATIVE
int Encode_NATIVE_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcHeader *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTcHeader) );
    return sizeof(asn1SccPusTcHeader);
}
#endif

#ifdef __NEED_PusTcHeader_UPER
int Decode_UPER_PusTcHeader(asn1SccPusTcHeader *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTcHeader_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTcHeader (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTcHeader_ACN
int Decode_ACN_PusTcHeader(asn1SccPusTcHeader *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTcHeader_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTcHeader (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTcHeader_NATIVE
int Decode_NATIVE_PusTcHeader(asn1SccPusTcHeader *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTcHeader *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_19_1_Data_UPER
int Encode_UPER_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_19_1_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-19-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_19_1_Data_ACN
int Encode_ACN_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_19_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_19_1_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-19-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_19_1_Data_NATIVE
int Encode_NATIVE_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_19_1_Data) );
    return sizeof(asn1SccPusTC_19_1_Data);
}
#endif

#ifdef __NEED_PusTC_19_1_Data_UPER
int Decode_UPER_PusTC_19_1_Data(asn1SccPusTC_19_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_19_1_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-19-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_19_1_Data_ACN
int Decode_ACN_PusTC_19_1_Data(asn1SccPusTC_19_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_19_1_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-19-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_19_1_Data_NATIVE
int Decode_NATIVE_PusTC_19_1_Data(asn1SccPusTC_19_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_19_1_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTcScheduledActivity_UPER
int Encode_UPER_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcScheduledActivity *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcScheduledActivity_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTcScheduledActivity (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcScheduledActivity_ACN
int Encode_ACN_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcScheduledActivity *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcScheduledActivity_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTcScheduledActivity (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcScheduledActivity_NATIVE
int Encode_NATIVE_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcScheduledActivity *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTcScheduledActivity) );
    return sizeof(asn1SccPusTcScheduledActivity);
}
#endif

#ifdef __NEED_PusTcScheduledActivity_UPER
int Decode_UPER_PusTcScheduledActivity(asn1SccPusTcScheduledActivity *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTcScheduledActivity_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTcScheduledActivity (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTcScheduledActivity_ACN
int Decode_ACN_PusTcScheduledActivity(asn1SccPusTcScheduledActivity *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTcScheduledActivity_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTcScheduledActivity (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTcScheduledActivity_NATIVE
int Decode_NATIVE_PusTcScheduledActivity(asn1SccPusTcScheduledActivity *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTcScheduledActivity *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_11_4_Data_UPER
int Encode_UPER_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_11_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_11_4_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-11-4-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_11_4_Data_ACN
int Encode_ACN_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_11_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_11_4_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-11-4-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_11_4_Data_NATIVE
int Encode_NATIVE_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_11_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_11_4_Data) );
    return sizeof(asn1SccPusTC_11_4_Data);
}
#endif

#ifdef __NEED_PusTC_11_4_Data_UPER
int Decode_UPER_PusTC_11_4_Data(asn1SccPusTC_11_4_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_11_4_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-11-4-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_11_4_Data_ACN
int Decode_ACN_PusTC_11_4_Data(asn1SccPusTC_11_4_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_11_4_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-11-4-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_11_4_Data_NATIVE
int Decode_NATIVE_PusTC_11_4_Data(asn1SccPusTC_11_4_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_11_4_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTcApplicationData_UPER
int Encode_UPER_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcApplicationData_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTcApplicationData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcApplicationData_ACN
int Encode_ACN_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcApplicationData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcApplicationData_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTcApplicationData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcApplicationData_NATIVE
int Encode_NATIVE_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationData *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTcApplicationData) );
    return sizeof(asn1SccPusTcApplicationData);
}
#endif

#ifdef __NEED_PusTcApplicationData_UPER
int Decode_UPER_PusTcApplicationData(asn1SccPusTcApplicationData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTcApplicationData_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTcApplicationData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTcApplicationData_ACN
int Decode_ACN_PusTcApplicationData(asn1SccPusTcApplicationData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTcApplicationData_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTcApplicationData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTcApplicationData_NATIVE
int Decode_NATIVE_PusTcApplicationData(asn1SccPusTcApplicationData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTcApplicationData *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTcApplicationDataReduced_UPER
int Encode_UPER_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationDataReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcApplicationDataReduced_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTcApplicationDataReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcApplicationDataReduced_ACN
int Encode_ACN_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcApplicationDataReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcApplicationDataReduced_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTcApplicationDataReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcApplicationDataReduced_NATIVE
int Encode_NATIVE_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationDataReduced *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTcApplicationDataReduced) );
    return sizeof(asn1SccPusTcApplicationDataReduced);
}
#endif

#ifdef __NEED_PusTcApplicationDataReduced_UPER
int Decode_UPER_PusTcApplicationDataReduced(asn1SccPusTcApplicationDataReduced *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTcApplicationDataReduced_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTcApplicationDataReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTcApplicationDataReduced_ACN
int Decode_ACN_PusTcApplicationDataReduced(asn1SccPusTcApplicationDataReduced *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTcApplicationDataReduced_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTcApplicationDataReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTcApplicationDataReduced_NATIVE
int Decode_NATIVE_PusTcApplicationDataReduced(asn1SccPusTcApplicationDataReduced *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTcApplicationDataReduced *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTmHeaderData_UPER
int Encode_UPER_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeaderData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmHeaderData_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTmHeaderData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmHeaderData_ACN
int Encode_ACN_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmHeaderData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmHeaderData_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTmHeaderData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmHeaderData_NATIVE
int Encode_NATIVE_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeaderData *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTmHeaderData) );
    return sizeof(asn1SccPusTmHeaderData);
}
#endif

#ifdef __NEED_PusTmHeaderData_UPER
int Decode_UPER_PusTmHeaderData(asn1SccPusTmHeaderData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTmHeaderData_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTmHeaderData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTmHeaderData_ACN
int Decode_ACN_PusTmHeaderData(asn1SccPusTmHeaderData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTmHeaderData_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTmHeaderData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTmHeaderData_NATIVE
int Decode_NATIVE_PusTmHeaderData(asn1SccPusTmHeaderData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTmHeaderData *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusPacketData_UPER
int Encode_UPER_PusPacketData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketData_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketData_ACN
int Encode_ACN_PusPacketData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketData_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketData_NATIVE
int Encode_NATIVE_PusPacketData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketData *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusPacketData) );
    return sizeof(asn1SccPusPacketData);
}
#endif

#ifdef __NEED_PusPacketData_UPER
int Decode_UPER_PusPacketData(asn1SccPusPacketData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketData_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketData_ACN
int Decode_ACN_PusPacketData(asn1SccPusPacketData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketData_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketData_NATIVE
int Decode_NATIVE_PusPacketData(asn1SccPusPacketData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusPacketData *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusPacketDataReduced_UPER
int Encode_UPER_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketDataReduced_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketDataReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketDataReduced_ACN
int Encode_ACN_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketDataReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketDataReduced_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketDataReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketDataReduced_NATIVE
int Encode_NATIVE_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataReduced *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusPacketDataReduced) );
    return sizeof(asn1SccPusPacketDataReduced);
}
#endif

#ifdef __NEED_PusPacketDataReduced_UPER
int Decode_UPER_PusPacketDataReduced(asn1SccPusPacketDataReduced *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketDataReduced_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketDataReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketDataReduced_ACN
int Decode_ACN_PusPacketDataReduced(asn1SccPusPacketDataReduced *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketDataReduced_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketDataReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketDataReduced_NATIVE
int Decode_NATIVE_PusPacketDataReduced(asn1SccPusPacketDataReduced *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusPacketDataReduced *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusPacket_UPER
int Encode_UPER_PusPacket(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacket *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacket_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacket (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacket_ACN
int Encode_ACN_PusPacket(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacket *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacket_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacket (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacket_NATIVE
int Encode_NATIVE_PusPacket(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacket *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusPacket) );
    return sizeof(asn1SccPusPacket);
}
#endif

#ifdef __NEED_PusPacket_UPER
int Decode_UPER_PusPacket(asn1SccPusPacket *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacket_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacket (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacket_ACN
int Decode_ACN_PusPacket(asn1SccPusPacket *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacket_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacket (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacket_NATIVE
int Decode_NATIVE_PusPacket(asn1SccPusPacket *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusPacket *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusPacketReduced_UPER
int Encode_UPER_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketReduced_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketReduced_ACN
int Encode_ACN_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketReduced_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketReduced_NATIVE
int Encode_NATIVE_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketReduced *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusPacketReduced) );
    return sizeof(asn1SccPusPacketReduced);
}
#endif

#ifdef __NEED_PusPacketReduced_UPER
int Decode_UPER_PusPacketReduced(asn1SccPusPacketReduced *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketReduced_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketReduced_ACN
int Decode_ACN_PusPacketReduced(asn1SccPusPacketReduced *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketReduced_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketReduced_NATIVE
int Decode_NATIVE_PusPacketReduced(asn1SccPusPacketReduced *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusPacketReduced *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusPacketVersion_UPER
int Encode_UPER_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketVersion *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketVersion_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketVersion (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketVersion_ACN
int Encode_ACN_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketVersion *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketVersion_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketVersion (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketVersion_NATIVE
int Encode_NATIVE_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketVersion *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusPacketVersion) );
    return sizeof(asn1SccPusPacketVersion);
}
#endif

#ifdef __NEED_PusPacketVersion_UPER
int Decode_UPER_PusPacketVersion(asn1SccPusPacketVersion *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketVersion_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketVersion (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketVersion_ACN
int Decode_ACN_PusPacketVersion(asn1SccPusPacketVersion *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketVersion_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketVersion (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketVersion_NATIVE
int Decode_NATIVE_PusPacketVersion(asn1SccPusPacketVersion *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusPacketVersion *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusPacketType_UPER
int Encode_UPER_PusPacketType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketType_ACN
int Encode_ACN_PusPacketType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketType_NATIVE
int Encode_NATIVE_PusPacketType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketType *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusPacketType) );
    return sizeof(asn1SccPusPacketType);
}
#endif

#ifdef __NEED_PusPacketType_UPER
int Decode_UPER_PusPacketType(asn1SccPusPacketType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketType_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketType_ACN
int Decode_ACN_PusPacketType(asn1SccPusPacketType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketType_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketType_NATIVE
int Decode_NATIVE_PusPacketType(asn1SccPusPacketType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusPacketType *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_UPER
int Encode_UPER_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSecondaryHeaderFlag *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSecondaryHeaderFlag_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSecondaryHeaderFlag (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_ACN
int Encode_ACN_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSecondaryHeaderFlag *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSecondaryHeaderFlag_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSecondaryHeaderFlag (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_NATIVE
int Encode_NATIVE_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSecondaryHeaderFlag *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSecondaryHeaderFlag) );
    return sizeof(asn1SccPusSecondaryHeaderFlag);
}
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_UPER
int Decode_UPER_PusSecondaryHeaderFlag(asn1SccPusSecondaryHeaderFlag *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSecondaryHeaderFlag_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSecondaryHeaderFlag (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_ACN
int Decode_ACN_PusSecondaryHeaderFlag(asn1SccPusSecondaryHeaderFlag *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSecondaryHeaderFlag_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSecondaryHeaderFlag (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_NATIVE
int Decode_NATIVE_PusSecondaryHeaderFlag(asn1SccPusSecondaryHeaderFlag *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSecondaryHeaderFlag *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusApid_UPER
int Encode_UPER_PusApid(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusApid *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusApid_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusApid (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusApid_ACN
int Encode_ACN_PusApid(void *pBuffer, size_t iMaxBufferSize, asn1SccPusApid *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusApid_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusApid (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusApid_NATIVE
int Encode_NATIVE_PusApid(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusApid *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusApid) );
    return sizeof(asn1SccPusApid);
}
#endif

#ifdef __NEED_PusApid_UPER
int Decode_UPER_PusApid(asn1SccPusApid *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusApid_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusApid (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusApid_ACN
int Decode_ACN_PusApid(asn1SccPusApid *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusApid_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusApid (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusApid_NATIVE
int Decode_NATIVE_PusApid(asn1SccPusApid *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusApid *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSequenceFlags_UPER
int Encode_UPER_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceFlags *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSequenceFlags_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSequenceFlags (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSequenceFlags_ACN
int Encode_ACN_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSequenceFlags *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSequenceFlags_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSequenceFlags (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSequenceFlags_NATIVE
int Encode_NATIVE_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceFlags *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSequenceFlags) );
    return sizeof(asn1SccPusSequenceFlags);
}
#endif

#ifdef __NEED_PusSequenceFlags_UPER
int Decode_UPER_PusSequenceFlags(asn1SccPusSequenceFlags *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSequenceFlags_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSequenceFlags (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSequenceFlags_ACN
int Decode_ACN_PusSequenceFlags(asn1SccPusSequenceFlags *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSequenceFlags_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSequenceFlags (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSequenceFlags_NATIVE
int Decode_NATIVE_PusSequenceFlags(asn1SccPusSequenceFlags *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSequenceFlags *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSequenceCount_UPER
int Encode_UPER_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceCount *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSequenceCount_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSequenceCount (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSequenceCount_ACN
int Encode_ACN_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSequenceCount *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSequenceCount_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSequenceCount (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSequenceCount_NATIVE
int Encode_NATIVE_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceCount *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSequenceCount) );
    return sizeof(asn1SccPusSequenceCount);
}
#endif

#ifdef __NEED_PusSequenceCount_UPER
int Decode_UPER_PusSequenceCount(asn1SccPusSequenceCount *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSequenceCount_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSequenceCount (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSequenceCount_ACN
int Decode_ACN_PusSequenceCount(asn1SccPusSequenceCount *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSequenceCount_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSequenceCount (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSequenceCount_NATIVE
int Decode_NATIVE_PusSequenceCount(asn1SccPusSequenceCount *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSequenceCount *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusPacketDataLength_UPER
int Encode_UPER_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataLength *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketDataLength_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketDataLength (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketDataLength_ACN
int Encode_ACN_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketDataLength *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketDataLength_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusPacketDataLength (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketDataLength_NATIVE
int Encode_NATIVE_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataLength *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusPacketDataLength) );
    return sizeof(asn1SccPusPacketDataLength);
}
#endif

#ifdef __NEED_PusPacketDataLength_UPER
int Decode_UPER_PusPacketDataLength(asn1SccPusPacketDataLength *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketDataLength_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketDataLength (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketDataLength_ACN
int Decode_ACN_PusPacketDataLength(asn1SccPusPacketDataLength *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusPacketDataLength_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusPacketDataLength (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusPacketDataLength_NATIVE
int Decode_NATIVE_PusPacketDataLength(asn1SccPusPacketDataLength *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusPacketDataLength *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusVersionNumber_UPER
int Encode_UPER_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusVersionNumber *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusVersionNumber_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusVersionNumber (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusVersionNumber_ACN
int Encode_ACN_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, asn1SccPusVersionNumber *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusVersionNumber_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusVersionNumber (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusVersionNumber_NATIVE
int Encode_NATIVE_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusVersionNumber *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusVersionNumber) );
    return sizeof(asn1SccPusVersionNumber);
}
#endif

#ifdef __NEED_PusVersionNumber_UPER
int Decode_UPER_PusVersionNumber(asn1SccPusVersionNumber *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusVersionNumber_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusVersionNumber (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusVersionNumber_ACN
int Decode_ACN_PusVersionNumber(asn1SccPusVersionNumber *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusVersionNumber_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusVersionNumber (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusVersionNumber_NATIVE
int Decode_NATIVE_PusVersionNumber(asn1SccPusVersionNumber *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusVersionNumber *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTimeReferenceStatus_UPER
int Encode_UPER_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTimeReferenceStatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTimeReferenceStatus_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTimeReferenceStatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTimeReferenceStatus_ACN
int Encode_ACN_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTimeReferenceStatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTimeReferenceStatus_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTimeReferenceStatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTimeReferenceStatus_NATIVE
int Encode_NATIVE_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTimeReferenceStatus *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTimeReferenceStatus) );
    return sizeof(asn1SccPusTimeReferenceStatus);
}
#endif

#ifdef __NEED_PusTimeReferenceStatus_UPER
int Decode_UPER_PusTimeReferenceStatus(asn1SccPusTimeReferenceStatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTimeReferenceStatus_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTimeReferenceStatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTimeReferenceStatus_ACN
int Decode_ACN_PusTimeReferenceStatus(asn1SccPusTimeReferenceStatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTimeReferenceStatus_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTimeReferenceStatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTimeReferenceStatus_NATIVE
int Decode_NATIVE_PusTimeReferenceStatus(asn1SccPusTimeReferenceStatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTimeReferenceStatus *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusMessageTypeCounter_UPER
int Encode_UPER_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMessageTypeCounter *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusMessageTypeCounter_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusMessageTypeCounter (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusMessageTypeCounter_ACN
int Encode_ACN_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, asn1SccPusMessageTypeCounter *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusMessageTypeCounter_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusMessageTypeCounter (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusMessageTypeCounter_NATIVE
int Encode_NATIVE_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMessageTypeCounter *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusMessageTypeCounter) );
    return sizeof(asn1SccPusMessageTypeCounter);
}
#endif

#ifdef __NEED_PusMessageTypeCounter_UPER
int Decode_UPER_PusMessageTypeCounter(asn1SccPusMessageTypeCounter *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusMessageTypeCounter_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusMessageTypeCounter (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusMessageTypeCounter_ACN
int Decode_ACN_PusMessageTypeCounter(asn1SccPusMessageTypeCounter *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusMessageTypeCounter_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusMessageTypeCounter (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusMessageTypeCounter_NATIVE
int Decode_NATIVE_PusMessageTypeCounter(asn1SccPusMessageTypeCounter *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusMessageTypeCounter *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusAcknowledgementFlags_UPER
int Encode_UPER_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusAcknowledgementFlags *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusAcknowledgementFlags_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusAcknowledgementFlags (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusAcknowledgementFlags_ACN
int Encode_ACN_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, asn1SccPusAcknowledgementFlags *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusAcknowledgementFlags_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusAcknowledgementFlags (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusAcknowledgementFlags_NATIVE
int Encode_NATIVE_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusAcknowledgementFlags *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusAcknowledgementFlags) );
    return sizeof(asn1SccPusAcknowledgementFlags);
}
#endif

#ifdef __NEED_PusAcknowledgementFlags_UPER
int Decode_UPER_PusAcknowledgementFlags(asn1SccPusAcknowledgementFlags *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusAcknowledgementFlags_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusAcknowledgementFlags (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusAcknowledgementFlags_ACN
int Decode_ACN_PusAcknowledgementFlags(asn1SccPusAcknowledgementFlags *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusAcknowledgementFlags_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusAcknowledgementFlags (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusAcknowledgementFlags_NATIVE
int Decode_NATIVE_PusAcknowledgementFlags(asn1SccPusAcknowledgementFlags *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusAcknowledgementFlags *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusChecksum_UPER
int Encode_UPER_PusChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusChecksum *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusChecksum_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusChecksum (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusChecksum_ACN
int Encode_ACN_PusChecksum(void *pBuffer, size_t iMaxBufferSize, asn1SccPusChecksum *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusChecksum_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusChecksum (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusChecksum_NATIVE
int Encode_NATIVE_PusChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusChecksum *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusChecksum) );
    return sizeof(asn1SccPusChecksum);
}
#endif

#ifdef __NEED_PusChecksum_UPER
int Decode_UPER_PusChecksum(asn1SccPusChecksum *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusChecksum_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusChecksum (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusChecksum_ACN
int Decode_ACN_PusChecksum(asn1SccPusChecksum *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusChecksum_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusChecksum (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusChecksum_NATIVE
int Decode_NATIVE_PusChecksum(asn1SccPusChecksum *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusChecksum *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusStepId_UPER
int Encode_UPER_PusStepId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusStepId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusStepId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusStepId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusStepId_ACN
int Encode_ACN_PusStepId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusStepId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusStepId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusStepId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusStepId_NATIVE
int Encode_NATIVE_PusStepId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusStepId *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusStepId) );
    return sizeof(asn1SccPusStepId);
}
#endif

#ifdef __NEED_PusStepId_UPER
int Decode_UPER_PusStepId(asn1SccPusStepId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusStepId_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusStepId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusStepId_ACN
int Decode_ACN_PusStepId(asn1SccPusStepId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusStepId_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusStepId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusStepId_NATIVE
int Decode_NATIVE_PusStepId(asn1SccPusStepId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusStepId *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusConfigDummyType_UPER
int Encode_UPER_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusConfigDummyType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusConfigDummyType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusConfigDummyType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusConfigDummyType_ACN
int Encode_ACN_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusConfigDummyType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusConfigDummyType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusConfigDummyType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusConfigDummyType_NATIVE
int Encode_NATIVE_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusConfigDummyType *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusConfigDummyType) );
    return sizeof(asn1SccPusConfigDummyType);
}
#endif

#ifdef __NEED_PusConfigDummyType_UPER
int Decode_UPER_PusConfigDummyType(asn1SccPusConfigDummyType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusConfigDummyType_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusConfigDummyType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusConfigDummyType_ACN
int Decode_ACN_PusConfigDummyType(asn1SccPusConfigDummyType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusConfigDummyType_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusConfigDummyType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusConfigDummyType_NATIVE
int Decode_NATIVE_PusConfigDummyType(asn1SccPusConfigDummyType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusConfigDummyType *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusServiceType_UPER
int Encode_UPER_PusServiceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusServiceType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusServiceType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusServiceType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusServiceType_ACN
int Encode_ACN_PusServiceType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusServiceType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusServiceType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusServiceType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusServiceType_NATIVE
int Encode_NATIVE_PusServiceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusServiceType *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusServiceType) );
    return sizeof(asn1SccPusServiceType);
}
#endif

#ifdef __NEED_PusServiceType_UPER
int Decode_UPER_PusServiceType(asn1SccPusServiceType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusServiceType_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusServiceType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusServiceType_ACN
int Decode_ACN_PusServiceType(asn1SccPusServiceType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusServiceType_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusServiceType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusServiceType_NATIVE
int Decode_NATIVE_PusServiceType(asn1SccPusServiceType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusServiceType *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSubserviceType_UPER
int Encode_UPER_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSubserviceType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSubserviceType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSubserviceType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSubserviceType_ACN
int Encode_ACN_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSubserviceType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSubserviceType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSubserviceType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSubserviceType_NATIVE
int Encode_NATIVE_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSubserviceType *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSubserviceType) );
    return sizeof(asn1SccPusSubserviceType);
}
#endif

#ifdef __NEED_PusSubserviceType_UPER
int Decode_UPER_PusSubserviceType(asn1SccPusSubserviceType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSubserviceType_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSubserviceType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSubserviceType_ACN
int Decode_ACN_PusSubserviceType(asn1SccPusSubserviceType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSubserviceType_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSubserviceType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSubserviceType_NATIVE
int Decode_NATIVE_PusSubserviceType(asn1SccPusSubserviceType *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSubserviceType *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt01FailureCode_UPER
int Encode_UPER_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureCode *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01FailureCode_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt01FailureCode (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01FailureCode_ACN
int Encode_ACN_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01FailureCode *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01FailureCode_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt01FailureCode (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01FailureCode_NATIVE
int Encode_NATIVE_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureCode *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt01FailureCode) );
    return sizeof(asn1SccPusSt01FailureCode);
}
#endif

#ifdef __NEED_PusSt01FailureCode_UPER
int Decode_UPER_PusSt01FailureCode(asn1SccPusSt01FailureCode *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt01FailureCode_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt01FailureCode (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt01FailureCode_ACN
int Decode_ACN_PusSt01FailureCode(asn1SccPusSt01FailureCode *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt01FailureCode_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt01FailureCode (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt01FailureCode_NATIVE
int Decode_NATIVE_PusSt01FailureCode(asn1SccPusSt01FailureCode *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt01FailureCode *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt01FailureInfo_UPER
int Encode_UPER_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureInfo *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01FailureInfo_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt01FailureInfo (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01FailureInfo_ACN
int Encode_ACN_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01FailureInfo *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01FailureInfo_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt01FailureInfo (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01FailureInfo_NATIVE
int Encode_NATIVE_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureInfo *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt01FailureInfo) );
    return sizeof(asn1SccPusSt01FailureInfo);
}
#endif

#ifdef __NEED_PusSt01FailureInfo_UPER
int Decode_UPER_PusSt01FailureInfo(asn1SccPusSt01FailureInfo *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt01FailureInfo_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt01FailureInfo (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt01FailureInfo_ACN
int Decode_ACN_PusSt01FailureInfo(asn1SccPusSt01FailureInfo *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt01FailureInfo_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt01FailureInfo (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt01FailureInfo_NATIVE
int Decode_NATIVE_PusSt01FailureInfo(asn1SccPusSt01FailureInfo *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt01FailureInfo *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt01RequestId_UPER
int Encode_UPER_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01RequestId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01RequestId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt01RequestId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01RequestId_ACN
int Encode_ACN_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01RequestId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01RequestId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt01RequestId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01RequestId_NATIVE
int Encode_NATIVE_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01RequestId *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt01RequestId) );
    return sizeof(asn1SccPusSt01RequestId);
}
#endif

#ifdef __NEED_PusSt01RequestId_UPER
int Decode_UPER_PusSt01RequestId(asn1SccPusSt01RequestId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt01RequestId_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt01RequestId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt01RequestId_ACN
int Decode_ACN_PusSt01RequestId(asn1SccPusSt01RequestId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt01RequestId_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt01RequestId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt01RequestId_NATIVE
int Decode_NATIVE_PusSt01RequestId(asn1SccPusSt01RequestId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt01RequestId *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt01Failure_UPER
int Encode_UPER_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01Failure *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01Failure_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt01Failure (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01Failure_ACN
int Encode_ACN_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01Failure *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01Failure_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt01Failure (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01Failure_NATIVE
int Encode_NATIVE_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01Failure *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt01Failure) );
    return sizeof(asn1SccPusSt01Failure);
}
#endif

#ifdef __NEED_PusSt01Failure_UPER
int Decode_UPER_PusSt01Failure(asn1SccPusSt01Failure *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt01Failure_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt01Failure (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt01Failure_ACN
int Decode_ACN_PusSt01Failure(asn1SccPusSt01Failure *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt01Failure_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt01Failure (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt01Failure_NATIVE
int Decode_NATIVE_PusSt01Failure(asn1SccPusSt01Failure *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt01Failure *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_1_X_Data_UPER
int Encode_UPER_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_1_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_1_X_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-1-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_1_X_Data_ACN
int Encode_ACN_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_1_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_1_X_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-1-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_1_X_Data_NATIVE
int Encode_NATIVE_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_1_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_1_X_Data) );
    return sizeof(asn1SccPusTM_1_X_Data);
}
#endif

#ifdef __NEED_PusTM_1_X_Data_UPER
int Decode_UPER_PusTM_1_X_Data(asn1SccPusTM_1_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_1_X_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-1-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_1_X_Data_ACN
int Decode_ACN_PusTM_1_X_Data(asn1SccPusTM_1_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_1_X_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-1-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_1_X_Data_NATIVE
int Decode_NATIVE_PusTM_1_X_Data(asn1SccPusTM_1_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_1_X_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt03StoredParam_UPER
int Encode_UPER_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03StoredParam *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03StoredParam_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt03StoredParam (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03StoredParam_ACN
int Encode_ACN_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03StoredParam *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03StoredParam_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt03StoredParam (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03StoredParam_NATIVE
int Encode_NATIVE_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03StoredParam *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt03StoredParam) );
    return sizeof(asn1SccPusSt03StoredParam);
}
#endif

#ifdef __NEED_PusSt03StoredParam_UPER
int Decode_UPER_PusSt03StoredParam(asn1SccPusSt03StoredParam *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt03StoredParam_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt03StoredParam (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt03StoredParam_ACN
int Decode_ACN_PusSt03StoredParam(asn1SccPusSt03StoredParam *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt03StoredParam_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt03StoredParam (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt03StoredParam_NATIVE
int Decode_NATIVE_PusSt03StoredParam(asn1SccPusSt03StoredParam *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt03StoredParam *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_UPER
int Encode_UPER_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03HousekeepingReportId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03HousekeepingReportId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt03HousekeepingReportId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_ACN
int Encode_ACN_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03HousekeepingReportId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03HousekeepingReportId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt03HousekeepingReportId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_NATIVE
int Encode_NATIVE_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03HousekeepingReportId *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt03HousekeepingReportId) );
    return sizeof(asn1SccPusSt03HousekeepingReportId);
}
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_UPER
int Decode_UPER_PusSt03HousekeepingReportId(asn1SccPusSt03HousekeepingReportId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt03HousekeepingReportId_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt03HousekeepingReportId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_ACN
int Decode_ACN_PusSt03HousekeepingReportId(asn1SccPusSt03HousekeepingReportId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt03HousekeepingReportId_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt03HousekeepingReportId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_NATIVE
int Decode_NATIVE_PusSt03HousekeepingReportId(asn1SccPusSt03HousekeepingReportId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt03HousekeepingReportId *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt03ParameterId_UPER
int Encode_UPER_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03ParameterId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt03ParameterId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03ParameterId_ACN
int Encode_ACN_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03ParameterId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03ParameterId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt03ParameterId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03ParameterId_NATIVE
int Encode_NATIVE_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterId *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt03ParameterId) );
    return sizeof(asn1SccPusSt03ParameterId);
}
#endif

#ifdef __NEED_PusSt03ParameterId_UPER
int Decode_UPER_PusSt03ParameterId(asn1SccPusSt03ParameterId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt03ParameterId_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt03ParameterId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt03ParameterId_ACN
int Decode_ACN_PusSt03ParameterId(asn1SccPusSt03ParameterId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt03ParameterId_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt03ParameterId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt03ParameterId_NATIVE
int Decode_NATIVE_PusSt03ParameterId(asn1SccPusSt03ParameterId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt03ParameterId *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt03ParameterArray_UPER
int Encode_UPER_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterArray *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03ParameterArray_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt03ParameterArray (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03ParameterArray_ACN
int Encode_ACN_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03ParameterArray *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03ParameterArray_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt03ParameterArray (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03ParameterArray_NATIVE
int Encode_NATIVE_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterArray *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt03ParameterArray) );
    return sizeof(asn1SccPusSt03ParameterArray);
}
#endif

#ifdef __NEED_PusSt03ParameterArray_UPER
int Decode_UPER_PusSt03ParameterArray(asn1SccPusSt03ParameterArray *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt03ParameterArray_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt03ParameterArray (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt03ParameterArray_ACN
int Decode_ACN_PusSt03ParameterArray(asn1SccPusSt03ParameterArray *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt03ParameterArray_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt03ParameterArray (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt03ParameterArray_NATIVE
int Decode_NATIVE_PusSt03ParameterArray(asn1SccPusSt03ParameterArray *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt03ParameterArray *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_3_25_Data_UPER
int Encode_UPER_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_3_25_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_3_25_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-3-25-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_3_25_Data_ACN
int Encode_ACN_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_3_25_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_3_25_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-3-25-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_3_25_Data_NATIVE
int Encode_NATIVE_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_3_25_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_3_25_Data) );
    return sizeof(asn1SccPusTM_3_25_Data);
}
#endif

#ifdef __NEED_PusTM_3_25_Data_UPER
int Decode_UPER_PusTM_3_25_Data(asn1SccPusTM_3_25_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_3_25_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-3-25-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_3_25_Data_ACN
int Decode_ACN_PusTM_3_25_Data(asn1SccPusTM_3_25_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_3_25_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-3-25-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_3_25_Data_NATIVE
int Decode_NATIVE_PusTM_3_25_Data(asn1SccPusTM_3_25_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_3_25_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt05EventId_UPER
int Encode_UPER_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05EventId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt05EventId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05EventId_ACN
int Encode_ACN_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05EventId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05EventId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt05EventId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05EventId_NATIVE
int Encode_NATIVE_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventId *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt05EventId) );
    return sizeof(asn1SccPusSt05EventId);
}
#endif

#ifdef __NEED_PusSt05EventId_UPER
int Decode_UPER_PusSt05EventId(asn1SccPusSt05EventId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt05EventId_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt05EventId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt05EventId_ACN
int Decode_ACN_PusSt05EventId(asn1SccPusSt05EventId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt05EventId_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt05EventId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt05EventId_NATIVE
int Decode_NATIVE_PusSt05EventId(asn1SccPusSt05EventId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt05EventId *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt05EventAuxData_UPER
int Encode_UPER_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventAuxData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05EventAuxData_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt05EventAuxData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05EventAuxData_ACN
int Encode_ACN_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05EventAuxData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05EventAuxData_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt05EventAuxData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05EventAuxData_NATIVE
int Encode_NATIVE_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventAuxData *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt05EventAuxData) );
    return sizeof(asn1SccPusSt05EventAuxData);
}
#endif

#ifdef __NEED_PusSt05EventAuxData_UPER
int Decode_UPER_PusSt05EventAuxData(asn1SccPusSt05EventAuxData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt05EventAuxData_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt05EventAuxData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt05EventAuxData_ACN
int Decode_ACN_PusSt05EventAuxData(asn1SccPusSt05EventAuxData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt05EventAuxData_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt05EventAuxData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt05EventAuxData_NATIVE
int Decode_NATIVE_PusSt05EventAuxData(asn1SccPusSt05EventAuxData *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt05EventAuxData *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt05Event_UPER
int Encode_UPER_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05Event *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05Event_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt05Event (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05Event_ACN
int Encode_ACN_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05Event *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05Event_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt05Event (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05Event_NATIVE
int Encode_NATIVE_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05Event *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt05Event) );
    return sizeof(asn1SccPusSt05Event);
}
#endif

#ifdef __NEED_PusSt05Event_UPER
int Decode_UPER_PusSt05Event(asn1SccPusSt05Event *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt05Event_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt05Event (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt05Event_ACN
int Decode_ACN_PusSt05Event(asn1SccPusSt05Event *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt05Event_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt05Event (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt05Event_NATIVE
int Decode_NATIVE_PusSt05Event(asn1SccPusSt05Event *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt05Event *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_5_X_Data_UPER
int Encode_UPER_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_5_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_5_X_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-5-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_5_X_Data_ACN
int Encode_ACN_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_5_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_5_X_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-5-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_5_X_Data_NATIVE
int Encode_NATIVE_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_5_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_5_X_Data) );
    return sizeof(asn1SccPusTM_5_X_Data);
}
#endif

#ifdef __NEED_PusTM_5_X_Data_UPER
int Decode_UPER_PusTM_5_X_Data(asn1SccPusTM_5_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_5_X_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-5-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_5_X_Data_ACN
int Decode_ACN_PusTM_5_X_Data(asn1SccPusTM_5_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_5_X_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-5-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_5_X_Data_NATIVE
int Decode_NATIVE_PusTM_5_X_Data(asn1SccPusTM_5_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_5_X_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt08FunctionId_UPER
int Encode_UPER_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt08FunctionId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt08FunctionId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt08FunctionId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt08FunctionId_ACN
int Encode_ACN_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt08FunctionId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt08FunctionId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt08FunctionId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt08FunctionId_NATIVE
int Encode_NATIVE_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt08FunctionId *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt08FunctionId) );
    return sizeof(asn1SccPusSt08FunctionId);
}
#endif

#ifdef __NEED_PusSt08FunctionId_UPER
int Decode_UPER_PusSt08FunctionId(asn1SccPusSt08FunctionId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt08FunctionId_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt08FunctionId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt08FunctionId_ACN
int Decode_ACN_PusSt08FunctionId(asn1SccPusSt08FunctionId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt08FunctionId_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt08FunctionId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt08FunctionId_NATIVE
int Decode_NATIVE_PusSt08FunctionId(asn1SccPusSt08FunctionId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt08FunctionId *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_8_1_Data_UPER
int Encode_UPER_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_8_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_8_1_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-8-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_8_1_Data_ACN
int Encode_ACN_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_8_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_8_1_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-8-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_8_1_Data_NATIVE
int Encode_NATIVE_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_8_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_8_1_Data) );
    return sizeof(asn1SccPusTC_8_1_Data);
}
#endif

#ifdef __NEED_PusTC_8_1_Data_UPER
int Decode_UPER_PusTC_8_1_Data(asn1SccPusTC_8_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_8_1_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-8-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_8_1_Data_ACN
int Decode_ACN_PusTC_8_1_Data(asn1SccPusTC_8_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_8_1_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-8-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_8_1_Data_NATIVE
int Decode_NATIVE_PusTC_8_1_Data(asn1SccPusTC_8_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_8_1_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt09ExponentialRate_UPER
int Encode_UPER_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt09ExponentialRate *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt09ExponentialRate_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt09ExponentialRate (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt09ExponentialRate_ACN
int Encode_ACN_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt09ExponentialRate *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt09ExponentialRate_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt09ExponentialRate (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt09ExponentialRate_NATIVE
int Encode_NATIVE_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt09ExponentialRate *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt09ExponentialRate) );
    return sizeof(asn1SccPusSt09ExponentialRate);
}
#endif

#ifdef __NEED_PusSt09ExponentialRate_UPER
int Decode_UPER_PusSt09ExponentialRate(asn1SccPusSt09ExponentialRate *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt09ExponentialRate_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt09ExponentialRate (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt09ExponentialRate_ACN
int Decode_ACN_PusSt09ExponentialRate(asn1SccPusSt09ExponentialRate *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt09ExponentialRate_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt09ExponentialRate (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt09ExponentialRate_NATIVE
int Decode_NATIVE_PusSt09ExponentialRate(asn1SccPusSt09ExponentialRate *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt09ExponentialRate *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_9_1_Data_UPER
int Encode_UPER_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_9_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_9_1_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-9-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_9_1_Data_ACN
int Encode_ACN_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_9_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_9_1_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-9-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_9_1_Data_NATIVE
int Encode_NATIVE_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_9_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_9_1_Data) );
    return sizeof(asn1SccPusTC_9_1_Data);
}
#endif

#ifdef __NEED_PusTC_9_1_Data_UPER
int Decode_UPER_PusTC_9_1_Data(asn1SccPusTC_9_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_9_1_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-9-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_9_1_Data_ACN
int Decode_ACN_PusTC_9_1_Data(asn1SccPusTC_9_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_9_1_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-9-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_9_1_Data_NATIVE
int Decode_NATIVE_PusTC_9_1_Data(asn1SccPusTC_9_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_9_1_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_9_2_Data_UPER
int Encode_UPER_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_9_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_9_2_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-9-2-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_9_2_Data_ACN
int Encode_ACN_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_9_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_9_2_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-9-2-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_9_2_Data_NATIVE
int Encode_NATIVE_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_9_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_9_2_Data) );
    return sizeof(asn1SccPusTM_9_2_Data);
}
#endif

#ifdef __NEED_PusTM_9_2_Data_UPER
int Decode_UPER_PusTM_9_2_Data(asn1SccPusTM_9_2_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_9_2_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-9-2-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_9_2_Data_ACN
int Decode_ACN_PusTM_9_2_Data(asn1SccPusTM_9_2_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_9_2_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-9-2-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_9_2_Data_NATIVE
int Decode_NATIVE_PusTM_9_2_Data(asn1SccPusTM_9_2_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_9_2_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt12pmonId_UPER
int Encode_UPER_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt12pmonId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt12pmonId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt12pmonId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt12pmonId_ACN
int Encode_ACN_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt12pmonId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt12pmonId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt12pmonId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt12pmonId_NATIVE
int Encode_NATIVE_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt12pmonId *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt12pmonId) );
    return sizeof(asn1SccPusSt12pmonId);
}
#endif

#ifdef __NEED_PusSt12pmonId_UPER
int Decode_UPER_PusSt12pmonId(asn1SccPusSt12pmonId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt12pmonId_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt12pmonId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt12pmonId_ACN
int Decode_ACN_PusSt12pmonId(asn1SccPusSt12pmonId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt12pmonId_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt12pmonId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt12pmonId_NATIVE
int Decode_NATIVE_PusSt12pmonId(asn1SccPusSt12pmonId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt12pmonId *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_12_1_2_Data_UPER
int Encode_UPER_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_12_1_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_12_1_2_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-12-1-2-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_12_1_2_Data_ACN
int Encode_ACN_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_12_1_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_12_1_2_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-12-1-2-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_12_1_2_Data_NATIVE
int Encode_NATIVE_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_12_1_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_12_1_2_Data) );
    return sizeof(asn1SccPusTC_12_1_2_Data);
}
#endif

#ifdef __NEED_PusTC_12_1_2_Data_UPER
int Decode_UPER_PusTC_12_1_2_Data(asn1SccPusTC_12_1_2_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_12_1_2_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-12-1-2-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_12_1_2_Data_ACN
int Decode_ACN_PusTC_12_1_2_Data(asn1SccPusTC_12_1_2_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_12_1_2_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-12-1-2-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_12_1_2_Data_NATIVE
int Decode_NATIVE_PusTC_12_1_2_Data(asn1SccPusTC_12_1_2_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_12_1_2_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt18ObcpId_UPER
int Encode_UPER_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt18ObcpId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpId_ACN
int Encode_ACN_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt18ObcpId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpId_NATIVE
int Encode_NATIVE_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpId *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt18ObcpId) );
    return sizeof(asn1SccPusSt18ObcpId);
}
#endif

#ifdef __NEED_PusSt18ObcpId_UPER
int Decode_UPER_PusSt18ObcpId(asn1SccPusSt18ObcpId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt18ObcpId_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt18ObcpId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt18ObcpId_ACN
int Decode_ACN_PusSt18ObcpId(asn1SccPusSt18ObcpId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt18ObcpId_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt18ObcpId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt18ObcpId_NATIVE
int Decode_NATIVE_PusSt18ObcpId(asn1SccPusSt18ObcpId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt18ObcpId *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt18ObcpCode_UPER
int Encode_UPER_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpCode *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpCode_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt18ObcpCode (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpCode_ACN
int Encode_ACN_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpCode *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpCode_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt18ObcpCode (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpCode_NATIVE
int Encode_NATIVE_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpCode *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt18ObcpCode) );
    return sizeof(asn1SccPusSt18ObcpCode);
}
#endif

#ifdef __NEED_PusSt18ObcpCode_UPER
int Decode_UPER_PusSt18ObcpCode(asn1SccPusSt18ObcpCode *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt18ObcpCode_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt18ObcpCode (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt18ObcpCode_ACN
int Decode_ACN_PusSt18ObcpCode(asn1SccPusSt18ObcpCode *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt18ObcpCode_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt18ObcpCode (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt18ObcpCode_NATIVE
int Decode_NATIVE_PusSt18ObcpCode(asn1SccPusSt18ObcpCode *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt18ObcpCode *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt18ObcpChecksum_UPER
int Encode_UPER_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpChecksum *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpChecksum_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt18ObcpChecksum (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpChecksum_ACN
int Encode_ACN_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpChecksum *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpChecksum_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt18ObcpChecksum (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpChecksum_NATIVE
int Encode_NATIVE_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpChecksum *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt18ObcpChecksum) );
    return sizeof(asn1SccPusSt18ObcpChecksum);
}
#endif

#ifdef __NEED_PusSt18ObcpChecksum_UPER
int Decode_UPER_PusSt18ObcpChecksum(asn1SccPusSt18ObcpChecksum *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt18ObcpChecksum_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt18ObcpChecksum (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt18ObcpChecksum_ACN
int Decode_ACN_PusSt18ObcpChecksum(asn1SccPusSt18ObcpChecksum *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt18ObcpChecksum_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt18ObcpChecksum (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt18ObcpChecksum_NATIVE
int Decode_NATIVE_PusSt18ObcpChecksum(asn1SccPusSt18ObcpChecksum *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt18ObcpChecksum *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_UPER
int Encode_UPER_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObservabilityLevel *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObservabilityLevel_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt18ObservabilityLevel (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_ACN
int Encode_ACN_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObservabilityLevel *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObservabilityLevel_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt18ObservabilityLevel (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_NATIVE
int Encode_NATIVE_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObservabilityLevel *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt18ObservabilityLevel) );
    return sizeof(asn1SccPusSt18ObservabilityLevel);
}
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_UPER
int Decode_UPER_PusSt18ObservabilityLevel(asn1SccPusSt18ObservabilityLevel *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt18ObservabilityLevel_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt18ObservabilityLevel (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_ACN
int Decode_ACN_PusSt18ObservabilityLevel(asn1SccPusSt18ObservabilityLevel *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt18ObservabilityLevel_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt18ObservabilityLevel (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_NATIVE
int Decode_NATIVE_PusSt18ObservabilityLevel(asn1SccPusSt18ObservabilityLevel *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt18ObservabilityLevel *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_18_1_Data_UPER
int Encode_UPER_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_1_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-18-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_1_Data_ACN
int Encode_ACN_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_1_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-18-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_1_Data_NATIVE
int Encode_NATIVE_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_18_1_Data) );
    return sizeof(asn1SccPusTC_18_1_Data);
}
#endif

#ifdef __NEED_PusTC_18_1_Data_UPER
int Decode_UPER_PusTC_18_1_Data(asn1SccPusTC_18_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_18_1_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-18-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_18_1_Data_ACN
int Decode_ACN_PusTC_18_1_Data(asn1SccPusTC_18_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_18_1_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-18-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_18_1_Data_NATIVE
int Decode_NATIVE_PusTC_18_1_Data(asn1SccPusTC_18_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_18_1_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_UPER
int Encode_UPER_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_2_6_12_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_2_6_12_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-18-2-6-12-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_ACN
int Encode_ACN_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_2_6_12_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_2_6_12_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-18-2-6-12-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_NATIVE
int Encode_NATIVE_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_2_6_12_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_18_2_6_12_Data) );
    return sizeof(asn1SccPusTC_18_2_6_12_Data);
}
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_UPER
int Decode_UPER_PusTC_18_2_6_12_Data(asn1SccPusTC_18_2_6_12_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_18_2_6_12_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-18-2-6-12-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_ACN
int Decode_ACN_PusTC_18_2_6_12_Data(asn1SccPusTC_18_2_6_12_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_18_2_6_12_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-18-2-6-12-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_NATIVE
int Decode_NATIVE_PusTC_18_2_6_12_Data(asn1SccPusTC_18_2_6_12_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_18_2_6_12_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_18_3_Data_UPER
int Encode_UPER_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_3_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-18-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_3_Data_ACN
int Encode_ACN_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_3_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-18-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_3_Data_NATIVE
int Encode_NATIVE_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_18_3_Data) );
    return sizeof(asn1SccPusTC_18_3_Data);
}
#endif

#ifdef __NEED_PusTC_18_3_Data_UPER
int Decode_UPER_PusTC_18_3_Data(asn1SccPusTC_18_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_18_3_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-18-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_18_3_Data_ACN
int Decode_ACN_PusTC_18_3_Data(asn1SccPusTC_18_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_18_3_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-18-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_18_3_Data_NATIVE
int Decode_NATIVE_PusTC_18_3_Data(asn1SccPusTC_18_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_18_3_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_18_4_5_Data_UPER
int Encode_UPER_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_4_5_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_4_5_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-18-4-5-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_4_5_Data_ACN
int Encode_ACN_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_4_5_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_4_5_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-18-4-5-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_4_5_Data_NATIVE
int Encode_NATIVE_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_4_5_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_18_4_5_Data) );
    return sizeof(asn1SccPusTC_18_4_5_Data);
}
#endif

#ifdef __NEED_PusTC_18_4_5_Data_UPER
int Decode_UPER_PusTC_18_4_5_Data(asn1SccPusTC_18_4_5_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_18_4_5_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-18-4-5-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_18_4_5_Data_ACN
int Decode_ACN_PusTC_18_4_5_Data(asn1SccPusTC_18_4_5_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_18_4_5_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-18-4-5-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_18_4_5_Data_NATIVE
int Decode_NATIVE_PusTC_18_4_5_Data(asn1SccPusTC_18_4_5_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_18_4_5_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_18_13_Data_UPER
int Encode_UPER_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_13_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_13_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-18-13-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_13_Data_ACN
int Encode_ACN_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_13_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_13_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-18-13-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_13_Data_NATIVE
int Encode_NATIVE_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_13_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_18_13_Data) );
    return sizeof(asn1SccPusTC_18_13_Data);
}
#endif

#ifdef __NEED_PusTC_18_13_Data_UPER
int Decode_UPER_PusTC_18_13_Data(asn1SccPusTC_18_13_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_18_13_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-18-13-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_18_13_Data_ACN
int Decode_ACN_PusTC_18_13_Data(asn1SccPusTC_18_13_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_18_13_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-18-13-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_18_13_Data_NATIVE
int Decode_NATIVE_PusTC_18_13_Data(asn1SccPusTC_18_13_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_18_13_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_19_X_Data_UPER
int Encode_UPER_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_19_X_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-19-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_19_X_Data_ACN
int Encode_ACN_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_19_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_19_X_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-19-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_19_X_Data_NATIVE
int Encode_NATIVE_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_19_X_Data) );
    return sizeof(asn1SccPusTC_19_X_Data);
}
#endif

#ifdef __NEED_PusTC_19_X_Data_UPER
int Decode_UPER_PusTC_19_X_Data(asn1SccPusTC_19_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_19_X_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-19-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_19_X_Data_ACN
int Decode_ACN_PusTC_19_X_Data(asn1SccPusTC_19_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_19_X_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-19-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_19_X_Data_NATIVE
int Decode_NATIVE_PusTC_19_X_Data(asn1SccPusTC_19_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_19_X_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_UPER
int Encode_UPER_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20OnBoardParameterId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt20OnBoardParameterId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt20OnBoardParameterId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_ACN
int Encode_ACN_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt20OnBoardParameterId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt20OnBoardParameterId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt20OnBoardParameterId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_NATIVE
int Encode_NATIVE_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20OnBoardParameterId *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt20OnBoardParameterId) );
    return sizeof(asn1SccPusSt20OnBoardParameterId);
}
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_UPER
int Decode_UPER_PusSt20OnBoardParameterId(asn1SccPusSt20OnBoardParameterId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt20OnBoardParameterId_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt20OnBoardParameterId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_ACN
int Decode_ACN_PusSt20OnBoardParameterId(asn1SccPusSt20OnBoardParameterId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt20OnBoardParameterId_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt20OnBoardParameterId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_NATIVE
int Decode_NATIVE_PusSt20OnBoardParameterId(asn1SccPusSt20OnBoardParameterId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt20OnBoardParameterId *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt20StoredParam_UPER
int Encode_UPER_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20StoredParam *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt20StoredParam_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt20StoredParam (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt20StoredParam_ACN
int Encode_ACN_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt20StoredParam *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt20StoredParam_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt20StoredParam (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt20StoredParam_NATIVE
int Encode_NATIVE_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20StoredParam *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt20StoredParam) );
    return sizeof(asn1SccPusSt20StoredParam);
}
#endif

#ifdef __NEED_PusSt20StoredParam_UPER
int Decode_UPER_PusSt20StoredParam(asn1SccPusSt20StoredParam *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt20StoredParam_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt20StoredParam (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt20StoredParam_ACN
int Decode_ACN_PusSt20StoredParam(asn1SccPusSt20StoredParam *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt20StoredParam_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt20StoredParam (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt20StoredParam_NATIVE
int Decode_NATIVE_PusSt20StoredParam(asn1SccPusSt20StoredParam *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt20StoredParam *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_UPER
int Encode_UPER_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_20_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_TM_20_X_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-TM-20-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_ACN
int Encode_ACN_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_TM_20_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_TM_20_X_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-TM-20-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_NATIVE
int Encode_NATIVE_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_20_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_TM_20_X_Data) );
    return sizeof(asn1SccPusTC_TM_20_X_Data);
}
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_UPER
int Decode_UPER_PusTC_TM_20_X_Data(asn1SccPusTC_TM_20_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_TM_20_X_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-TM-20-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_ACN
int Decode_ACN_PusTC_TM_20_X_Data(asn1SccPusTC_TM_20_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_TM_20_X_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-TM-20-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_NATIVE
int Decode_NATIVE_PusTC_TM_20_X_Data(asn1SccPusTC_TM_20_X_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_TM_20_X_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_200_2_Data_UPER
int Encode_UPER_PusTM_200_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_2_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-2-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_2_Data_ACN
int Encode_ACN_PusTM_200_2_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_2_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-2-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_2_Data_NATIVE
int Encode_NATIVE_PusTM_200_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_200_2_Data) );
    return sizeof(asn1SccPusTM_200_2_Data);
}
#endif

#ifdef __NEED_PusTM_200_2_Data_UPER
int Decode_UPER_PusTM_200_2_Data(asn1SccPusTM_200_2_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_2_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-2-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_2_Data_ACN
int Decode_ACN_PusTM_200_2_Data(asn1SccPusTM_200_2_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_2_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-2-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_2_Data_NATIVE
int Decode_NATIVE_PusTM_200_2_Data(asn1SccPusTM_200_2_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_200_2_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_200_3_Data_UPER
int Encode_UPER_PusTC_200_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_200_3_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-200-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_200_3_Data_ACN
int Encode_ACN_PusTC_200_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_200_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_200_3_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-200-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_200_3_Data_NATIVE
int Encode_NATIVE_PusTC_200_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_200_3_Data) );
    return sizeof(asn1SccPusTC_200_3_Data);
}
#endif

#ifdef __NEED_PusTC_200_3_Data_UPER
int Decode_UPER_PusTC_200_3_Data(asn1SccPusTC_200_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_200_3_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-200-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_200_3_Data_ACN
int Decode_ACN_PusTC_200_3_Data(asn1SccPusTC_200_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_200_3_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-200-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_200_3_Data_NATIVE
int Decode_NATIVE_PusTC_200_3_Data(asn1SccPusTC_200_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_200_3_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_200_4_Data_UPER
int Encode_UPER_PusTM_200_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_4_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-4-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_4_Data_ACN
int Encode_ACN_PusTM_200_4_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_4_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-4-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_4_Data_NATIVE
int Encode_NATIVE_PusTM_200_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_200_4_Data) );
    return sizeof(asn1SccPusTM_200_4_Data);
}
#endif

#ifdef __NEED_PusTM_200_4_Data_UPER
int Decode_UPER_PusTM_200_4_Data(asn1SccPusTM_200_4_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_4_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-4-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_4_Data_ACN
int Decode_ACN_PusTM_200_4_Data(asn1SccPusTM_200_4_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_4_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-4-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_4_Data_NATIVE
int Decode_NATIVE_PusTM_200_4_Data(asn1SccPusTM_200_4_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_200_4_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_200_5_Data_UPER
int Encode_UPER_PusTC_200_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_5_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_200_5_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-200-5-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_200_5_Data_ACN
int Encode_ACN_PusTC_200_5_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_200_5_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_200_5_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-200-5-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_200_5_Data_NATIVE
int Encode_NATIVE_PusTC_200_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_5_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_200_5_Data) );
    return sizeof(asn1SccPusTC_200_5_Data);
}
#endif

#ifdef __NEED_PusTC_200_5_Data_UPER
int Decode_UPER_PusTC_200_5_Data(asn1SccPusTC_200_5_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_200_5_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-200-5-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_200_5_Data_ACN
int Decode_ACN_PusTC_200_5_Data(asn1SccPusTC_200_5_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_200_5_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-200-5-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_200_5_Data_NATIVE
int Decode_NATIVE_PusTC_200_5_Data(asn1SccPusTC_200_5_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_200_5_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_200_6_Data_UPER
int Encode_UPER_PusTM_200_6_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_6_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_6_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-6-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_6_Data_ACN
int Encode_ACN_PusTM_200_6_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_6_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_6_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-6-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_6_Data_NATIVE
int Encode_NATIVE_PusTM_200_6_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_6_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_200_6_Data) );
    return sizeof(asn1SccPusTM_200_6_Data);
}
#endif

#ifdef __NEED_PusTM_200_6_Data_UPER
int Decode_UPER_PusTM_200_6_Data(asn1SccPusTM_200_6_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_6_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-6-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_6_Data_ACN
int Decode_ACN_PusTM_200_6_Data(asn1SccPusTM_200_6_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_6_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-6-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_6_Data_NATIVE
int Decode_NATIVE_PusTM_200_6_Data(asn1SccPusTM_200_6_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_200_6_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_200_8_Data_UPER
int Encode_UPER_PusTM_200_8_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_8_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_8_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-8-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_8_Data_ACN
int Encode_ACN_PusTM_200_8_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_8_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_8_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-8-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_8_Data_NATIVE
int Encode_NATIVE_PusTM_200_8_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_8_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_200_8_Data) );
    return sizeof(asn1SccPusTM_200_8_Data);
}
#endif

#ifdef __NEED_PusTM_200_8_Data_UPER
int Decode_UPER_PusTM_200_8_Data(asn1SccPusTM_200_8_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_8_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-8-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_8_Data_ACN
int Decode_ACN_PusTM_200_8_Data(asn1SccPusTM_200_8_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_8_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-8-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_8_Data_NATIVE
int Decode_NATIVE_PusTM_200_8_Data(asn1SccPusTM_200_8_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_200_8_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_200_9_Data_UPER
int Encode_UPER_PusTC_200_9_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_9_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_200_9_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-200-9-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_200_9_Data_ACN
int Encode_ACN_PusTC_200_9_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_200_9_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_200_9_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-200-9-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_200_9_Data_NATIVE
int Encode_NATIVE_PusTC_200_9_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_9_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_200_9_Data) );
    return sizeof(asn1SccPusTC_200_9_Data);
}
#endif

#ifdef __NEED_PusTC_200_9_Data_UPER
int Decode_UPER_PusTC_200_9_Data(asn1SccPusTC_200_9_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_200_9_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-200-9-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_200_9_Data_ACN
int Decode_ACN_PusTC_200_9_Data(asn1SccPusTC_200_9_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_200_9_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-200-9-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_200_9_Data_NATIVE
int Decode_NATIVE_PusTC_200_9_Data(asn1SccPusTC_200_9_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_200_9_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_200_10_Data_UPER
int Encode_UPER_PusTM_200_10_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_10_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_10_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-10-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_10_Data_ACN
int Encode_ACN_PusTM_200_10_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_10_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_10_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-10-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_10_Data_NATIVE
int Encode_NATIVE_PusTM_200_10_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_10_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_200_10_Data) );
    return sizeof(asn1SccPusTM_200_10_Data);
}
#endif

#ifdef __NEED_PusTM_200_10_Data_UPER
int Decode_UPER_PusTM_200_10_Data(asn1SccPusTM_200_10_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_10_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-10-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_10_Data_ACN
int Decode_ACN_PusTM_200_10_Data(asn1SccPusTM_200_10_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_10_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-10-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_10_Data_NATIVE
int Decode_NATIVE_PusTM_200_10_Data(asn1SccPusTM_200_10_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_200_10_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_200_11_Data_UPER
int Encode_UPER_PusTC_200_11_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_11_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_200_11_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-200-11-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_200_11_Data_ACN
int Encode_ACN_PusTC_200_11_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_200_11_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_200_11_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-200-11-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_200_11_Data_NATIVE
int Encode_NATIVE_PusTC_200_11_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_11_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_200_11_Data) );
    return sizeof(asn1SccPusTC_200_11_Data);
}
#endif

#ifdef __NEED_PusTC_200_11_Data_UPER
int Decode_UPER_PusTC_200_11_Data(asn1SccPusTC_200_11_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_200_11_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-200-11-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_200_11_Data_ACN
int Decode_ACN_PusTC_200_11_Data(asn1SccPusTC_200_11_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_200_11_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-200-11-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_200_11_Data_NATIVE
int Decode_NATIVE_PusTC_200_11_Data(asn1SccPusTC_200_11_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_200_11_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_200_12_Data_UPER
int Encode_UPER_PusTM_200_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_12_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_12_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-12-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_12_Data_ACN
int Encode_ACN_PusTM_200_12_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_12_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_12_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-12-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_12_Data_NATIVE
int Encode_NATIVE_PusTM_200_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_12_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_200_12_Data) );
    return sizeof(asn1SccPusTM_200_12_Data);
}
#endif

#ifdef __NEED_PusTM_200_12_Data_UPER
int Decode_UPER_PusTM_200_12_Data(asn1SccPusTM_200_12_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_12_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-12-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_12_Data_ACN
int Decode_ACN_PusTM_200_12_Data(asn1SccPusTM_200_12_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_12_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-12-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_12_Data_NATIVE
int Decode_NATIVE_PusTM_200_12_Data(asn1SccPusTM_200_12_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_200_12_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_200_13_Data_UPER
int Encode_UPER_PusTC_200_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_13_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_200_13_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-200-13-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_200_13_Data_ACN
int Encode_ACN_PusTC_200_13_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_200_13_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_200_13_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-200-13-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_200_13_Data_NATIVE
int Encode_NATIVE_PusTC_200_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_13_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_200_13_Data) );
    return sizeof(asn1SccPusTC_200_13_Data);
}
#endif

#ifdef __NEED_PusTC_200_13_Data_UPER
int Decode_UPER_PusTC_200_13_Data(asn1SccPusTC_200_13_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_200_13_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-200-13-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_200_13_Data_ACN
int Decode_ACN_PusTC_200_13_Data(asn1SccPusTC_200_13_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_200_13_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-200-13-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_200_13_Data_NATIVE
int Decode_NATIVE_PusTC_200_13_Data(asn1SccPusTC_200_13_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_200_13_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_200_14_Data_UPER
int Encode_UPER_PusTM_200_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_14_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_14_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-14-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_14_Data_ACN
int Encode_ACN_PusTM_200_14_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_14_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_200_14_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-200-14-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_200_14_Data_NATIVE
int Encode_NATIVE_PusTM_200_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_14_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_200_14_Data) );
    return sizeof(asn1SccPusTM_200_14_Data);
}
#endif

#ifdef __NEED_PusTM_200_14_Data_UPER
int Decode_UPER_PusTM_200_14_Data(asn1SccPusTM_200_14_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_14_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-14-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_14_Data_ACN
int Decode_ACN_PusTM_200_14_Data(asn1SccPusTM_200_14_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_200_14_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-200-14-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_200_14_Data_NATIVE
int Decode_NATIVE_PusTM_200_14_Data(asn1SccPusTM_200_14_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_200_14_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_IntegerIntervalDomain_UPER
int Encode_UPER_IntegerIntervalDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccIntegerIntervalDomain *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccIntegerIntervalDomain_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode IntegerIntervalDomain (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_IntegerIntervalDomain_ACN
int Encode_ACN_IntegerIntervalDomain(void *pBuffer, size_t iMaxBufferSize, asn1SccIntegerIntervalDomain *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccIntegerIntervalDomain_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode IntegerIntervalDomain (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_IntegerIntervalDomain_NATIVE
int Encode_NATIVE_IntegerIntervalDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccIntegerIntervalDomain *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccIntegerIntervalDomain) );
    return sizeof(asn1SccIntegerIntervalDomain);
}
#endif

#ifdef __NEED_IntegerIntervalDomain_UPER
int Decode_UPER_IntegerIntervalDomain(asn1SccIntegerIntervalDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccIntegerIntervalDomain_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode IntegerIntervalDomain (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_IntegerIntervalDomain_ACN
int Decode_ACN_IntegerIntervalDomain(asn1SccIntegerIntervalDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccIntegerIntervalDomain_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode IntegerIntervalDomain (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_IntegerIntervalDomain_NATIVE
int Decode_NATIVE_IntegerIntervalDomain(asn1SccIntegerIntervalDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccIntegerIntervalDomain *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_FloatIntervalDomain_UPER
int Encode_UPER_FloatIntervalDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccFloatIntervalDomain *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccFloatIntervalDomain_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode FloatIntervalDomain (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_FloatIntervalDomain_ACN
int Encode_ACN_FloatIntervalDomain(void *pBuffer, size_t iMaxBufferSize, asn1SccFloatIntervalDomain *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccFloatIntervalDomain_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode FloatIntervalDomain (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_FloatIntervalDomain_NATIVE
int Encode_NATIVE_FloatIntervalDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccFloatIntervalDomain *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccFloatIntervalDomain) );
    return sizeof(asn1SccFloatIntervalDomain);
}
#endif

#ifdef __NEED_FloatIntervalDomain_UPER
int Decode_UPER_FloatIntervalDomain(asn1SccFloatIntervalDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccFloatIntervalDomain_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode FloatIntervalDomain (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_FloatIntervalDomain_ACN
int Decode_ACN_FloatIntervalDomain(asn1SccFloatIntervalDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccFloatIntervalDomain_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode FloatIntervalDomain (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_FloatIntervalDomain_NATIVE
int Decode_NATIVE_FloatIntervalDomain(asn1SccFloatIntervalDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccFloatIntervalDomain *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_EnumDomain_UPER
int Encode_UPER_EnumDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccEnumDomain *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccEnumDomain_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode EnumDomain (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_EnumDomain_ACN
int Encode_ACN_EnumDomain(void *pBuffer, size_t iMaxBufferSize, asn1SccEnumDomain *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccEnumDomain_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode EnumDomain (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_EnumDomain_NATIVE
int Encode_NATIVE_EnumDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccEnumDomain *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccEnumDomain) );
    return sizeof(asn1SccEnumDomain);
}
#endif

#ifdef __NEED_EnumDomain_UPER
int Decode_UPER_EnumDomain(asn1SccEnumDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccEnumDomain_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode EnumDomain (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_EnumDomain_ACN
int Decode_ACN_EnumDomain(asn1SccEnumDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccEnumDomain_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode EnumDomain (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_EnumDomain_NATIVE
int Decode_NATIVE_EnumDomain(asn1SccEnumDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccEnumDomain *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_HotdockcmdPred_UPER
int Encode_UPER_HotdockcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockcmdPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHotdockcmdPred_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode HotdockcmdPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_HotdockcmdPred_ACN
int Encode_ACN_HotdockcmdPred(void *pBuffer, size_t iMaxBufferSize, asn1SccHotdockcmdPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHotdockcmdPred_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode HotdockcmdPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_HotdockcmdPred_NATIVE
int Encode_NATIVE_HotdockcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockcmdPred *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccHotdockcmdPred) );
    return sizeof(asn1SccHotdockcmdPred);
}
#endif

#ifdef __NEED_HotdockcmdPred_UPER
int Decode_UPER_HotdockcmdPred(asn1SccHotdockcmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHotdockcmdPred_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode HotdockcmdPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_HotdockcmdPred_ACN
int Decode_ACN_HotdockcmdPred(asn1SccHotdockcmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHotdockcmdPred_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode HotdockcmdPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_HotdockcmdPred_NATIVE
int Decode_NATIVE_HotdockcmdPred(asn1SccHotdockcmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccHotdockcmdPred *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_HotdockstatusPred_UPER
int Encode_UPER_HotdockstatusPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockstatusPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHotdockstatusPred_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode HotdockstatusPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_HotdockstatusPred_ACN
int Encode_ACN_HotdockstatusPred(void *pBuffer, size_t iMaxBufferSize, asn1SccHotdockstatusPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHotdockstatusPred_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode HotdockstatusPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_HotdockstatusPred_NATIVE
int Encode_NATIVE_HotdockstatusPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockstatusPred *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccHotdockstatusPred) );
    return sizeof(asn1SccHotdockstatusPred);
}
#endif

#ifdef __NEED_HotdockstatusPred_UPER
int Decode_UPER_HotdockstatusPred(asn1SccHotdockstatusPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHotdockstatusPred_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode HotdockstatusPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_HotdockstatusPred_ACN
int Decode_ACN_HotdockstatusPred(asn1SccHotdockstatusPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHotdockstatusPred_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode HotdockstatusPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_HotdockstatusPred_NATIVE
int Decode_NATIVE_HotdockstatusPred(asn1SccHotdockstatusPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccHotdockstatusPred *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_WmcmdPred_UPER
int Encode_UPER_WmcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccWmcmdPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccWmcmdPred_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode WmcmdPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_WmcmdPred_ACN
int Encode_ACN_WmcmdPred(void *pBuffer, size_t iMaxBufferSize, asn1SccWmcmdPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccWmcmdPred_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode WmcmdPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_WmcmdPred_NATIVE
int Encode_NATIVE_WmcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccWmcmdPred *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccWmcmdPred) );
    return sizeof(asn1SccWmcmdPred);
}
#endif

#ifdef __NEED_WmcmdPred_UPER
int Decode_UPER_WmcmdPred(asn1SccWmcmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccWmcmdPred_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode WmcmdPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_WmcmdPred_ACN
int Decode_ACN_WmcmdPred(asn1SccWmcmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccWmcmdPred_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode WmcmdPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_WmcmdPred_NATIVE
int Decode_NATIVE_WmcmdPred(asn1SccWmcmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccWmcmdPred *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_BasecmdPred_UPER
int Encode_UPER_BasecmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccBasecmdPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccBasecmdPred_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode BasecmdPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_BasecmdPred_ACN
int Encode_ACN_BasecmdPred(void *pBuffer, size_t iMaxBufferSize, asn1SccBasecmdPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccBasecmdPred_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode BasecmdPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_BasecmdPred_NATIVE
int Encode_NATIVE_BasecmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccBasecmdPred *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccBasecmdPred) );
    return sizeof(asn1SccBasecmdPred);
}
#endif

#ifdef __NEED_BasecmdPred_UPER
int Decode_UPER_BasecmdPred(asn1SccBasecmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccBasecmdPred_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode BasecmdPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_BasecmdPred_ACN
int Decode_ACN_BasecmdPred(asn1SccBasecmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccBasecmdPred_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode BasecmdPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_BasecmdPred_NATIVE
int Decode_NATIVE_BasecmdPred(asn1SccBasecmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccBasecmdPred *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_EfcmdPred_UPER
int Encode_UPER_EfcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccEfcmdPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccEfcmdPred_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode EfcmdPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_EfcmdPred_ACN
int Encode_ACN_EfcmdPred(void *pBuffer, size_t iMaxBufferSize, asn1SccEfcmdPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccEfcmdPred_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode EfcmdPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_EfcmdPred_NATIVE
int Encode_NATIVE_EfcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccEfcmdPred *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccEfcmdPred) );
    return sizeof(asn1SccEfcmdPred);
}
#endif

#ifdef __NEED_EfcmdPred_UPER
int Decode_UPER_EfcmdPred(asn1SccEfcmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccEfcmdPred_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode EfcmdPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_EfcmdPred_ACN
int Decode_ACN_EfcmdPred(asn1SccEfcmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccEfcmdPred_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode EfcmdPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_EfcmdPred_NATIVE
int Decode_NATIVE_EfcmdPred(asn1SccEfcmdPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccEfcmdPred *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PlannerPred_UPER
int Encode_UPER_PlannerPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccPlannerPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPlannerPred_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PlannerPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PlannerPred_ACN
int Encode_ACN_PlannerPred(void *pBuffer, size_t iMaxBufferSize, asn1SccPlannerPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPlannerPred_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PlannerPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PlannerPred_NATIVE
int Encode_NATIVE_PlannerPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccPlannerPred *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPlannerPred) );
    return sizeof(asn1SccPlannerPred);
}
#endif

#ifdef __NEED_PlannerPred_UPER
int Decode_UPER_PlannerPred(asn1SccPlannerPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPlannerPred_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PlannerPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PlannerPred_ACN
int Decode_ACN_PlannerPred(asn1SccPlannerPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPlannerPred_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PlannerPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PlannerPred_NATIVE
int Decode_NATIVE_PlannerPred(asn1SccPlannerPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPlannerPred *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_MissionPred_UPER
int Encode_UPER_MissionPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccMissionPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMissionPred_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode MissionPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_MissionPred_ACN
int Encode_ACN_MissionPred(void *pBuffer, size_t iMaxBufferSize, asn1SccMissionPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMissionPred_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode MissionPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_MissionPred_NATIVE
int Encode_NATIVE_MissionPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccMissionPred *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccMissionPred) );
    return sizeof(asn1SccMissionPred);
}
#endif

#ifdef __NEED_MissionPred_UPER
int Decode_UPER_MissionPred(asn1SccMissionPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMissionPred_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode MissionPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_MissionPred_ACN
int Decode_ACN_MissionPred(asn1SccMissionPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMissionPred_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode MissionPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_MissionPred_NATIVE
int Decode_NATIVE_MissionPred(asn1SccMissionPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccMissionPred *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_AutonomyPred_UPER
int Encode_UPER_AutonomyPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccAutonomyPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAutonomyPred_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AutonomyPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AutonomyPred_ACN
int Encode_ACN_AutonomyPred(void *pBuffer, size_t iMaxBufferSize, asn1SccAutonomyPred *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAutonomyPred_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode AutonomyPred (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_AutonomyPred_NATIVE
int Encode_NATIVE_AutonomyPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccAutonomyPred *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAutonomyPred) );
    return sizeof(asn1SccAutonomyPred);
}
#endif

#ifdef __NEED_AutonomyPred_UPER
int Decode_UPER_AutonomyPred(asn1SccAutonomyPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAutonomyPred_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AutonomyPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AutonomyPred_ACN
int Decode_ACN_AutonomyPred(asn1SccAutonomyPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAutonomyPred_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode AutonomyPred (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_AutonomyPred_NATIVE
int Decode_NATIVE_AutonomyPred(asn1SccAutonomyPred *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAutonomyPred *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Boold_UPER
int Encode_UPER_Boold(void *pBuffer, size_t iMaxBufferSize, const asn1SccBoold *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccBoold_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Boold (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Boold_ACN
int Encode_ACN_Boold(void *pBuffer, size_t iMaxBufferSize, asn1SccBoold *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccBoold_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Boold (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Boold_NATIVE
int Encode_NATIVE_Boold(void *pBuffer, size_t iMaxBufferSize, const asn1SccBoold *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccBoold) );
    return sizeof(asn1SccBoold);
}
#endif

#ifdef __NEED_Boold_UPER
int Decode_UPER_Boold(asn1SccBoold *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccBoold_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Boold (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Boold_ACN
int Decode_ACN_Boold(asn1SccBoold *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccBoold_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Boold (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Boold_NATIVE
int Decode_NATIVE_Boold(asn1SccBoold *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccBoold *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Intd_UPER
int Encode_UPER_Intd(void *pBuffer, size_t iMaxBufferSize, const asn1SccIntd *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccIntd_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Intd (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Intd_ACN
int Encode_ACN_Intd(void *pBuffer, size_t iMaxBufferSize, asn1SccIntd *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccIntd_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Intd (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Intd_NATIVE
int Encode_NATIVE_Intd(void *pBuffer, size_t iMaxBufferSize, const asn1SccIntd *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccIntd) );
    return sizeof(asn1SccIntd);
}
#endif

#ifdef __NEED_Intd_UPER
int Decode_UPER_Intd(asn1SccIntd *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccIntd_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Intd (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Intd_ACN
int Decode_ACN_Intd(asn1SccIntd *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccIntd_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Intd (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Intd_NATIVE
int Decode_NATIVE_Intd(asn1SccIntd *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccIntd *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Floatd_UPER
int Encode_UPER_Floatd(void *pBuffer, size_t iMaxBufferSize, const asn1SccFloatd *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccFloatd_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Floatd (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Floatd_ACN
int Encode_ACN_Floatd(void *pBuffer, size_t iMaxBufferSize, asn1SccFloatd *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccFloatd_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Floatd (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Floatd_NATIVE
int Encode_NATIVE_Floatd(void *pBuffer, size_t iMaxBufferSize, const asn1SccFloatd *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccFloatd) );
    return sizeof(asn1SccFloatd);
}
#endif

#ifdef __NEED_Floatd_UPER
int Decode_UPER_Floatd(asn1SccFloatd *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccFloatd_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Floatd (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Floatd_ACN
int Decode_ACN_Floatd(asn1SccFloatd *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccFloatd_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Floatd (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Floatd_NATIVE
int Decode_NATIVE_Floatd(asn1SccFloatd *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccFloatd *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Stringd_UPER
int Encode_UPER_Stringd(void *pBuffer, size_t iMaxBufferSize, const asn1SccStringd *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccStringd_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Stringd (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Stringd_ACN
int Encode_ACN_Stringd(void *pBuffer, size_t iMaxBufferSize, asn1SccStringd *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccStringd_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Stringd (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Stringd_NATIVE
int Encode_NATIVE_Stringd(void *pBuffer, size_t iMaxBufferSize, const asn1SccStringd *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccStringd) );
    return sizeof(asn1SccStringd);
}
#endif

#ifdef __NEED_Stringd_UPER
int Decode_UPER_Stringd(asn1SccStringd *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccStringd_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Stringd (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Stringd_ACN
int Decode_ACN_Stringd(asn1SccStringd *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccStringd_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Stringd (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Stringd_NATIVE
int Decode_NATIVE_Stringd(asn1SccStringd *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccStringd *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Int2d_UPER
int Encode_UPER_Int2d(void *pBuffer, size_t iMaxBufferSize, const asn1SccInt2d *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccInt2d_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Int2d (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Int2d_ACN
int Encode_ACN_Int2d(void *pBuffer, size_t iMaxBufferSize, asn1SccInt2d *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccInt2d_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Int2d (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Int2d_NATIVE
int Encode_NATIVE_Int2d(void *pBuffer, size_t iMaxBufferSize, const asn1SccInt2d *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccInt2d) );
    return sizeof(asn1SccInt2d);
}
#endif

#ifdef __NEED_Int2d_UPER
int Decode_UPER_Int2d(asn1SccInt2d *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccInt2d_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Int2d (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Int2d_ACN
int Decode_ACN_Int2d(asn1SccInt2d *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccInt2d_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Int2d (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Int2d_NATIVE
int Decode_NATIVE_Int2d(asn1SccInt2d *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccInt2d *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Slotid_UPER
int Encode_UPER_Slotid(void *pBuffer, size_t iMaxBufferSize, const asn1SccSlotid *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSlotid_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Slotid (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Slotid_ACN
int Encode_ACN_Slotid(void *pBuffer, size_t iMaxBufferSize, asn1SccSlotid *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccSlotid_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Slotid (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Slotid_NATIVE
int Encode_NATIVE_Slotid(void *pBuffer, size_t iMaxBufferSize, const asn1SccSlotid *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccSlotid) );
    return sizeof(asn1SccSlotid);
}
#endif

#ifdef __NEED_Slotid_UPER
int Decode_UPER_Slotid(asn1SccSlotid *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSlotid_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Slotid (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Slotid_ACN
int Decode_ACN_Slotid(asn1SccSlotid *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccSlotid_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Slotid (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Slotid_NATIVE
int Decode_NATIVE_Slotid(asn1SccSlotid *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccSlotid *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Position3D_UPER
int Encode_UPER_Position3D(void *pBuffer, size_t iMaxBufferSize, const asn1SccPosition3D *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPosition3D_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Position3D (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Position3D_ACN
int Encode_ACN_Position3D(void *pBuffer, size_t iMaxBufferSize, asn1SccPosition3D *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPosition3D_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Position3D (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Position3D_NATIVE
int Encode_NATIVE_Position3D(void *pBuffer, size_t iMaxBufferSize, const asn1SccPosition3D *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPosition3D) );
    return sizeof(asn1SccPosition3D);
}
#endif

#ifdef __NEED_Position3D_UPER
int Decode_UPER_Position3D(asn1SccPosition3D *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPosition3D_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Position3D (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Position3D_ACN
int Decode_ACN_Position3D(asn1SccPosition3D *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPosition3D_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Position3D (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Position3D_NATIVE
int Decode_NATIVE_Position3D(asn1SccPosition3D *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPosition3D *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Quaterniond_UPER
int Encode_UPER_Quaterniond(void *pBuffer, size_t iMaxBufferSize, const asn1SccQuaterniond *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccQuaterniond_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Quaterniond (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Quaterniond_ACN
int Encode_ACN_Quaterniond(void *pBuffer, size_t iMaxBufferSize, asn1SccQuaterniond *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccQuaterniond_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Quaterniond (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Quaterniond_NATIVE
int Encode_NATIVE_Quaterniond(void *pBuffer, size_t iMaxBufferSize, const asn1SccQuaterniond *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccQuaterniond) );
    return sizeof(asn1SccQuaterniond);
}
#endif

#ifdef __NEED_Quaterniond_UPER
int Decode_UPER_Quaterniond(asn1SccQuaterniond *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccQuaterniond_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Quaterniond (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Quaterniond_ACN
int Decode_ACN_Quaterniond(asn1SccQuaterniond *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccQuaterniond_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Quaterniond (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Quaterniond_NATIVE
int Decode_NATIVE_Quaterniond(asn1SccQuaterniond *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccQuaterniond *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Hotdockcmdstatus_UPER
int Encode_UPER_Hotdockcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockcmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHotdockcmdstatus_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Hotdockcmdstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Hotdockcmdstatus_ACN
int Encode_ACN_Hotdockcmdstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccHotdockcmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHotdockcmdstatus_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Hotdockcmdstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Hotdockcmdstatus_NATIVE
int Encode_NATIVE_Hotdockcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockcmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccHotdockcmdstatus) );
    return sizeof(asn1SccHotdockcmdstatus);
}
#endif

#ifdef __NEED_Hotdockcmdstatus_UPER
int Decode_UPER_Hotdockcmdstatus(asn1SccHotdockcmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHotdockcmdstatus_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Hotdockcmdstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Hotdockcmdstatus_ACN
int Decode_ACN_Hotdockcmdstatus(asn1SccHotdockcmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHotdockcmdstatus_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Hotdockcmdstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Hotdockcmdstatus_NATIVE
int Decode_NATIVE_Hotdockcmdstatus(asn1SccHotdockcmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccHotdockcmdstatus *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Hotdockstatusstatus_UPER
int Encode_UPER_Hotdockstatusstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockstatusstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHotdockstatusstatus_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Hotdockstatusstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Hotdockstatusstatus_ACN
int Encode_ACN_Hotdockstatusstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccHotdockstatusstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccHotdockstatusstatus_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Hotdockstatusstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Hotdockstatusstatus_NATIVE
int Encode_NATIVE_Hotdockstatusstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockstatusstatus *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccHotdockstatusstatus) );
    return sizeof(asn1SccHotdockstatusstatus);
}
#endif

#ifdef __NEED_Hotdockstatusstatus_UPER
int Decode_UPER_Hotdockstatusstatus(asn1SccHotdockstatusstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHotdockstatusstatus_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Hotdockstatusstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Hotdockstatusstatus_ACN
int Decode_ACN_Hotdockstatusstatus(asn1SccHotdockstatusstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccHotdockstatusstatus_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Hotdockstatusstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Hotdockstatusstatus_NATIVE
int Decode_NATIVE_Hotdockstatusstatus(asn1SccHotdockstatusstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccHotdockstatusstatus *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Wmcmdstatus_UPER
int Encode_UPER_Wmcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccWmcmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccWmcmdstatus_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Wmcmdstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Wmcmdstatus_ACN
int Encode_ACN_Wmcmdstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccWmcmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccWmcmdstatus_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Wmcmdstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Wmcmdstatus_NATIVE
int Encode_NATIVE_Wmcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccWmcmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccWmcmdstatus) );
    return sizeof(asn1SccWmcmdstatus);
}
#endif

#ifdef __NEED_Wmcmdstatus_UPER
int Decode_UPER_Wmcmdstatus(asn1SccWmcmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccWmcmdstatus_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Wmcmdstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Wmcmdstatus_ACN
int Decode_ACN_Wmcmdstatus(asn1SccWmcmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccWmcmdstatus_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Wmcmdstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Wmcmdstatus_NATIVE
int Decode_NATIVE_Wmcmdstatus(asn1SccWmcmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccWmcmdstatus *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Basecmdstatus_UPER
int Encode_UPER_Basecmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccBasecmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccBasecmdstatus_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Basecmdstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Basecmdstatus_ACN
int Encode_ACN_Basecmdstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccBasecmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccBasecmdstatus_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Basecmdstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Basecmdstatus_NATIVE
int Encode_NATIVE_Basecmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccBasecmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccBasecmdstatus) );
    return sizeof(asn1SccBasecmdstatus);
}
#endif

#ifdef __NEED_Basecmdstatus_UPER
int Decode_UPER_Basecmdstatus(asn1SccBasecmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccBasecmdstatus_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Basecmdstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Basecmdstatus_ACN
int Decode_ACN_Basecmdstatus(asn1SccBasecmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccBasecmdstatus_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Basecmdstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Basecmdstatus_NATIVE
int Decode_NATIVE_Basecmdstatus(asn1SccBasecmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccBasecmdstatus *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Efcmdstatus_UPER
int Encode_UPER_Efcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccEfcmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccEfcmdstatus_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Efcmdstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Efcmdstatus_ACN
int Encode_ACN_Efcmdstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccEfcmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccEfcmdstatus_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Efcmdstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Efcmdstatus_NATIVE
int Encode_NATIVE_Efcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccEfcmdstatus *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccEfcmdstatus) );
    return sizeof(asn1SccEfcmdstatus);
}
#endif

#ifdef __NEED_Efcmdstatus_UPER
int Decode_UPER_Efcmdstatus(asn1SccEfcmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccEfcmdstatus_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Efcmdstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Efcmdstatus_ACN
int Decode_ACN_Efcmdstatus(asn1SccEfcmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccEfcmdstatus_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Efcmdstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Efcmdstatus_NATIVE
int Decode_NATIVE_Efcmdstatus(asn1SccEfcmdstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccEfcmdstatus *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Plannerstatus_UPER
int Encode_UPER_Plannerstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPlannerstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPlannerstatus_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Plannerstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Plannerstatus_ACN
int Encode_ACN_Plannerstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccPlannerstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPlannerstatus_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Plannerstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Plannerstatus_NATIVE
int Encode_NATIVE_Plannerstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPlannerstatus *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPlannerstatus) );
    return sizeof(asn1SccPlannerstatus);
}
#endif

#ifdef __NEED_Plannerstatus_UPER
int Decode_UPER_Plannerstatus(asn1SccPlannerstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPlannerstatus_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Plannerstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Plannerstatus_ACN
int Decode_ACN_Plannerstatus(asn1SccPlannerstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPlannerstatus_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Plannerstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Plannerstatus_NATIVE
int Decode_NATIVE_Plannerstatus(asn1SccPlannerstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPlannerstatus *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Missionstatus_UPER
int Encode_UPER_Missionstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccMissionstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMissionstatus_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Missionstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Missionstatus_ACN
int Encode_ACN_Missionstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccMissionstatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccMissionstatus_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Missionstatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Missionstatus_NATIVE
int Encode_NATIVE_Missionstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccMissionstatus *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccMissionstatus) );
    return sizeof(asn1SccMissionstatus);
}
#endif

#ifdef __NEED_Missionstatus_UPER
int Decode_UPER_Missionstatus(asn1SccMissionstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMissionstatus_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Missionstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Missionstatus_ACN
int Decode_ACN_Missionstatus(asn1SccMissionstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccMissionstatus_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Missionstatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Missionstatus_NATIVE
int Decode_NATIVE_Missionstatus(asn1SccMissionstatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccMissionstatus *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Autonomystatus_UPER
int Encode_UPER_Autonomystatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccAutonomystatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAutonomystatus_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Autonomystatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Autonomystatus_ACN
int Encode_ACN_Autonomystatus(void *pBuffer, size_t iMaxBufferSize, asn1SccAutonomystatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccAutonomystatus_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Autonomystatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Autonomystatus_NATIVE
int Encode_NATIVE_Autonomystatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccAutonomystatus *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccAutonomystatus) );
    return sizeof(asn1SccAutonomystatus);
}
#endif

#ifdef __NEED_Autonomystatus_UPER
int Decode_UPER_Autonomystatus(asn1SccAutonomystatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAutonomystatus_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Autonomystatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Autonomystatus_ACN
int Decode_ACN_Autonomystatus(asn1SccAutonomystatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccAutonomystatus_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Autonomystatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Autonomystatus_NATIVE
int Decode_NATIVE_Autonomystatus(asn1SccAutonomystatus *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccAutonomystatus *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Pus_220_StateId_UPER
int Encode_UPER_Pus_220_StateId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPus_220_StateId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPus_220_StateId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Pus-220-StateId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Pus_220_StateId_ACN
int Encode_ACN_Pus_220_StateId(void *pBuffer, size_t iMaxBufferSize, asn1SccPus_220_StateId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPus_220_StateId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Pus-220-StateId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Pus_220_StateId_NATIVE
int Encode_NATIVE_Pus_220_StateId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPus_220_StateId *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPus_220_StateId) );
    return sizeof(asn1SccPus_220_StateId);
}
#endif

#ifdef __NEED_Pus_220_StateId_UPER
int Decode_UPER_Pus_220_StateId(asn1SccPus_220_StateId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPus_220_StateId_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Pus-220-StateId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Pus_220_StateId_ACN
int Decode_ACN_Pus_220_StateId(asn1SccPus_220_StateId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPus_220_StateId_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Pus-220-StateId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Pus_220_StateId_NATIVE
int Decode_NATIVE_Pus_220_StateId(asn1SccPus_220_StateId *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPus_220_StateId *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_220_1_Data_UPER
int Encode_UPER_PusTC_220_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_220_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_220_1_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-220-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_220_1_Data_ACN
int Encode_ACN_PusTC_220_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_220_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_220_1_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-220-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_220_1_Data_NATIVE
int Encode_NATIVE_PusTC_220_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_220_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_220_1_Data) );
    return sizeof(asn1SccPusTC_220_1_Data);
}
#endif

#ifdef __NEED_PusTC_220_1_Data_UPER
int Decode_UPER_PusTC_220_1_Data(asn1SccPusTC_220_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_220_1_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-220-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_220_1_Data_ACN
int Decode_ACN_PusTC_220_1_Data(asn1SccPusTC_220_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_220_1_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-220-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_220_1_Data_NATIVE
int Decode_NATIVE_PusTC_220_1_Data(asn1SccPusTC_220_1_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_220_1_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTM_220_3_Data_UPER
int Encode_UPER_PusTM_220_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_220_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_220_3_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-220-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_220_3_Data_ACN
int Encode_ACN_PusTM_220_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_220_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_220_3_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTM-220-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_220_3_Data_NATIVE
int Encode_NATIVE_PusTM_220_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_220_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTM_220_3_Data) );
    return sizeof(asn1SccPusTM_220_3_Data);
}
#endif

#ifdef __NEED_PusTM_220_3_Data_UPER
int Decode_UPER_PusTM_220_3_Data(asn1SccPusTM_220_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_220_3_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-220-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_220_3_Data_ACN
int Decode_ACN_PusTM_220_3_Data(asn1SccPusTM_220_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTM_220_3_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTM-220-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTM_220_3_Data_NATIVE
int Decode_NATIVE_PusTM_220_3_Data(asn1SccPusTM_220_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTM_220_3_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_Pus_220_ActiveIds_UPER
int Encode_UPER_Pus_220_ActiveIds(void *pBuffer, size_t iMaxBufferSize, const asn1SccPus_220_ActiveIds *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPus_220_ActiveIds_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Pus-220-ActiveIds (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Pus_220_ActiveIds_ACN
int Encode_ACN_Pus_220_ActiveIds(void *pBuffer, size_t iMaxBufferSize, asn1SccPus_220_ActiveIds *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPus_220_ActiveIds_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode Pus-220-ActiveIds (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_Pus_220_ActiveIds_NATIVE
int Encode_NATIVE_Pus_220_ActiveIds(void *pBuffer, size_t iMaxBufferSize, const asn1SccPus_220_ActiveIds *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPus_220_ActiveIds) );
    return sizeof(asn1SccPus_220_ActiveIds);
}
#endif

#ifdef __NEED_Pus_220_ActiveIds_UPER
int Decode_UPER_Pus_220_ActiveIds(asn1SccPus_220_ActiveIds *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPus_220_ActiveIds_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Pus-220-ActiveIds (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Pus_220_ActiveIds_ACN
int Decode_ACN_Pus_220_ActiveIds(asn1SccPus_220_ActiveIds *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPus_220_ActiveIds_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode Pus-220-ActiveIds (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_Pus_220_ActiveIds_NATIVE
int Decode_NATIVE_Pus_220_ActiveIds(asn1SccPus_220_ActiveIds *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPus_220_ActiveIds *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryPath_UPER
int Encode_UPER_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryPath *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23RepositoryPath_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt23RepositoryPath (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryPath_ACN
int Encode_ACN_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23RepositoryPath *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23RepositoryPath_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt23RepositoryPath (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryPath_NATIVE
int Encode_NATIVE_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryPath *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt23RepositoryPath) );
    return sizeof(asn1SccPusSt23RepositoryPath);
}
#endif

#ifdef __NEED_PusSt23RepositoryPath_UPER
int Decode_UPER_PusSt23RepositoryPath(asn1SccPusSt23RepositoryPath *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt23RepositoryPath_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt23RepositoryPath (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryPath_ACN
int Decode_ACN_PusSt23RepositoryPath(asn1SccPusSt23RepositoryPath *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt23RepositoryPath_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt23RepositoryPath (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryPath_NATIVE
int Decode_NATIVE_PusSt23RepositoryPath(asn1SccPusSt23RepositoryPath *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt23RepositoryPath *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt23FileName_UPER
int Encode_UPER_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23FileName *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23FileName_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt23FileName (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23FileName_ACN
int Encode_ACN_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23FileName *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23FileName_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt23FileName (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23FileName_NATIVE
int Encode_NATIVE_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23FileName *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt23FileName) );
    return sizeof(asn1SccPusSt23FileName);
}
#endif

#ifdef __NEED_PusSt23FileName_UPER
int Decode_UPER_PusSt23FileName(asn1SccPusSt23FileName *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt23FileName_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt23FileName (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt23FileName_ACN
int Decode_ACN_PusSt23FileName(asn1SccPusSt23FileName *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt23FileName_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt23FileName (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt23FileName_NATIVE
int Decode_NATIVE_PusSt23FileName(asn1SccPusSt23FileName *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt23FileName *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryDomain_UPER
int Encode_UPER_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryDomain *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23RepositoryDomain_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt23RepositoryDomain (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryDomain_ACN
int Encode_ACN_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23RepositoryDomain *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23RepositoryDomain_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusSt23RepositoryDomain (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryDomain_NATIVE
int Encode_NATIVE_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryDomain *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusSt23RepositoryDomain) );
    return sizeof(asn1SccPusSt23RepositoryDomain);
}
#endif

#ifdef __NEED_PusSt23RepositoryDomain_UPER
int Decode_UPER_PusSt23RepositoryDomain(asn1SccPusSt23RepositoryDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt23RepositoryDomain_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt23RepositoryDomain (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryDomain_ACN
int Decode_ACN_PusSt23RepositoryDomain(asn1SccPusSt23RepositoryDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusSt23RepositoryDomain_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusSt23RepositoryDomain (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryDomain_NATIVE
int Decode_NATIVE_PusSt23RepositoryDomain(asn1SccPusSt23RepositoryDomain *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusSt23RepositoryDomain *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_UPER
int Encode_UPER_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_23_1_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_TM_23_1_4_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-TM-23-1-4-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_ACN
int Encode_ACN_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_TM_23_1_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_TM_23_1_4_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-TM-23-1-4-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_NATIVE
int Encode_NATIVE_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_23_1_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_TM_23_1_4_Data) );
    return sizeof(asn1SccPusTC_TM_23_1_4_Data);
}
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_UPER
int Decode_UPER_PusTC_TM_23_1_4_Data(asn1SccPusTC_TM_23_1_4_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_TM_23_1_4_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-TM-23-1-4-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_ACN
int Decode_ACN_PusTC_TM_23_1_4_Data(asn1SccPusTC_TM_23_1_4_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_TM_23_1_4_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-TM-23-1-4-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_NATIVE
int Decode_NATIVE_PusTC_TM_23_1_4_Data(asn1SccPusTC_TM_23_1_4_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_TM_23_1_4_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_23_2_3_Data_UPER
int Encode_UPER_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_2_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_23_2_3_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-23-2-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_23_2_3_Data_ACN
int Encode_ACN_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_23_2_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_23_2_3_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-23-2-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_23_2_3_Data_NATIVE
int Encode_NATIVE_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_2_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_23_2_3_Data) );
    return sizeof(asn1SccPusTC_23_2_3_Data);
}
#endif

#ifdef __NEED_PusTC_23_2_3_Data_UPER
int Decode_UPER_PusTC_23_2_3_Data(asn1SccPusTC_23_2_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_23_2_3_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-23-2-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_23_2_3_Data_ACN
int Decode_ACN_PusTC_23_2_3_Data(asn1SccPusTC_23_2_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_23_2_3_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-23-2-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_23_2_3_Data_NATIVE
int Decode_NATIVE_PusTC_23_2_3_Data(asn1SccPusTC_23_2_3_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_23_2_3_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTC_23_14_Data_UPER
int Encode_UPER_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_14_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_23_14_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-23-14-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_23_14_Data_ACN
int Encode_ACN_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_23_14_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_23_14_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTC-23-14-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_23_14_Data_NATIVE
int Encode_NATIVE_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_14_Data *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTC_23_14_Data) );
    return sizeof(asn1SccPusTC_23_14_Data);
}
#endif

#ifdef __NEED_PusTC_23_14_Data_UPER
int Decode_UPER_PusTC_23_14_Data(asn1SccPusTC_23_14_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_23_14_Data_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-23-14-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_23_14_Data_ACN
int Decode_ACN_PusTC_23_14_Data(asn1SccPusTC_23_14_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTC_23_14_Data_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTC-23-14-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTC_23_14_Data_NATIVE
int Decode_NATIVE_PusTC_23_14_Data(asn1SccPusTC_23_14_Data *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTC_23_14_Data *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Double_UPER
int Encode_UPER_T_Double(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Double *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Double_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Double (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Double_ACN
int Encode_ACN_T_Double(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Double *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Double_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Double (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Double_NATIVE
int Encode_NATIVE_T_Double(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Double *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Double) );
    return sizeof(asn1SccT_Double);
}
#endif

#ifdef __NEED_T_Double_UPER
int Decode_UPER_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Double_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Double (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Double_ACN
int Decode_ACN_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Double_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Double (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Double_NATIVE
int Decode_NATIVE_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Double *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Float_UPER
int Encode_UPER_T_Float(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Float *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Float_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Float (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Float_ACN
int Encode_ACN_T_Float(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Float *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Float_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Float (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Float_NATIVE
int Encode_NATIVE_T_Float(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Float *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Float) );
    return sizeof(asn1SccT_Float);
}
#endif

#ifdef __NEED_T_Float_UPER
int Decode_UPER_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Float_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Float (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Float_ACN
int Decode_ACN_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Float_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Float (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Float_NATIVE
int Decode_NATIVE_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Float *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int16_UPER
int Encode_UPER_T_Int16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int16_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int16_ACN
int Encode_ACN_T_Int16(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int16_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int16_NATIVE
int Encode_NATIVE_T_Int16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int16 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int16) );
    return sizeof(asn1SccT_Int16);
}
#endif

#ifdef __NEED_T_Int16_UPER
int Decode_UPER_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int16_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int16_ACN
int Decode_ACN_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int16_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int16_NATIVE
int Decode_NATIVE_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int16 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt16_UPER
int Encode_UPER_T_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt16_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt16_ACN
int Encode_ACN_T_UInt16(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt16_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt16_NATIVE
int Encode_NATIVE_T_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt16 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt16) );
    return sizeof(asn1SccT_UInt16);
}
#endif

#ifdef __NEED_T_UInt16_UPER
int Decode_UPER_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt16_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt16_ACN
int Decode_ACN_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt16_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt16_NATIVE
int Decode_NATIVE_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt16 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt64_UPER
int Encode_UPER_T_UInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt64_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt64_ACN
int Encode_ACN_T_UInt64(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt64_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt64_NATIVE
int Encode_NATIVE_T_UInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt64 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt64) );
    return sizeof(asn1SccT_UInt64);
}
#endif

#ifdef __NEED_T_UInt64_UPER
int Decode_UPER_T_UInt64(asn1SccT_UInt64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt64_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt64_ACN
int Decode_ACN_T_UInt64(asn1SccT_UInt64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt64_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt64_NATIVE
int Decode_NATIVE_T_UInt64(asn1SccT_UInt64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt64 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int64_UPER
int Encode_UPER_T_Int64(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int64_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int64_ACN
int Encode_ACN_T_Int64(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int64_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int64_NATIVE
int Encode_NATIVE_T_Int64(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int64 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int64) );
    return sizeof(asn1SccT_Int64);
}
#endif

#ifdef __NEED_T_Int64_UPER
int Decode_UPER_T_Int64(asn1SccT_Int64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int64_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int64_ACN
int Decode_ACN_T_Int64(asn1SccT_Int64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int64_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int64_NATIVE
int Decode_NATIVE_T_Int64(asn1SccT_Int64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int64 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_String_UPER
int Encode_UPER_T_String(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_String *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_String_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-String (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_String_ACN
int Encode_ACN_T_String(void *pBuffer, size_t iMaxBufferSize, asn1SccT_String *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_String_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-String (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_String_NATIVE
int Encode_NATIVE_T_String(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_String *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_String) );
    return sizeof(asn1SccT_String);
}
#endif

#ifdef __NEED_T_String_UPER
int Decode_UPER_T_String(asn1SccT_String *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_String_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-String (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_String_ACN
int Decode_ACN_T_String(asn1SccT_String *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_String_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-String (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_String_NATIVE
int Decode_NATIVE_T_String(asn1SccT_String *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_String *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Time_UPER
int Encode_UPER_T_Time(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Time *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Time_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Time (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Time_ACN
int Encode_ACN_T_Time(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Time *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Time_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Time (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Time_NATIVE
int Encode_NATIVE_T_Time(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Time *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Time) );
    return sizeof(asn1SccT_Time);
}
#endif

#ifdef __NEED_T_Time_UPER
int Decode_UPER_T_Time(asn1SccT_Time *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Time_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Time (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Time_ACN
int Decode_ACN_T_Time(asn1SccT_Time *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Time_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Time (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Time_NATIVE
int Decode_NATIVE_T_Time(asn1SccT_Time *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Time *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusTime_UPER
int Encode_UPER_PusTime(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTime *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTime_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTime (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTime_ACN
int Encode_ACN_PusTime(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTime *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTime_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusTime (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTime_NATIVE
int Encode_NATIVE_PusTime(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTime *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusTime) );
    return sizeof(asn1SccPusTime);
}
#endif

#ifdef __NEED_PusTime_UPER
int Decode_UPER_PusTime(asn1SccPusTime *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTime_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTime (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTime_ACN
int Decode_ACN_PusTime(asn1SccPusTime *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusTime_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusTime (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusTime_NATIVE
int Decode_NATIVE_PusTime(asn1SccPusTime *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusTime *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusUInt3_UPER
int Encode_UPER_PusUInt3(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt3 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt3_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt3 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt3_ACN
int Encode_ACN_PusUInt3(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt3 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt3_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt3 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt3_NATIVE
int Encode_NATIVE_PusUInt3(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt3 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusUInt3) );
    return sizeof(asn1SccPusUInt3);
}
#endif

#ifdef __NEED_PusUInt3_UPER
int Decode_UPER_PusUInt3(asn1SccPusUInt3 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt3_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt3 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt3_ACN
int Decode_ACN_PusUInt3(asn1SccPusUInt3 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt3_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt3 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt3_NATIVE
int Decode_NATIVE_PusUInt3(asn1SccPusUInt3 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusUInt3 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusUInt4_UPER
int Encode_UPER_PusUInt4(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt4 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt4_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt4 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt4_ACN
int Encode_ACN_PusUInt4(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt4 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt4_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt4 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt4_NATIVE
int Encode_NATIVE_PusUInt4(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt4 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusUInt4) );
    return sizeof(asn1SccPusUInt4);
}
#endif

#ifdef __NEED_PusUInt4_UPER
int Decode_UPER_PusUInt4(asn1SccPusUInt4 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt4_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt4 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt4_ACN
int Decode_ACN_PusUInt4(asn1SccPusUInt4 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt4_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt4 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt4_NATIVE
int Decode_NATIVE_PusUInt4(asn1SccPusUInt4 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusUInt4 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusUInt8_UPER
int Encode_UPER_PusUInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt8_ACN
int Encode_ACN_PusUInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt8_NATIVE
int Encode_NATIVE_PusUInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusUInt8) );
    return sizeof(asn1SccPusUInt8);
}
#endif

#ifdef __NEED_PusUInt8_UPER
int Decode_UPER_PusUInt8(asn1SccPusUInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt8_ACN
int Decode_ACN_PusUInt8(asn1SccPusUInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt8_NATIVE
int Decode_NATIVE_PusUInt8(asn1SccPusUInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusUInt8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusUInt11_UPER
int Encode_UPER_PusUInt11(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt11 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt11_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt11 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt11_ACN
int Encode_ACN_PusUInt11(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt11 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt11_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt11 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt11_NATIVE
int Encode_NATIVE_PusUInt11(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt11 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusUInt11) );
    return sizeof(asn1SccPusUInt11);
}
#endif

#ifdef __NEED_PusUInt11_UPER
int Decode_UPER_PusUInt11(asn1SccPusUInt11 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt11_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt11 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt11_ACN
int Decode_ACN_PusUInt11(asn1SccPusUInt11 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt11_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt11 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt11_NATIVE
int Decode_NATIVE_PusUInt11(asn1SccPusUInt11 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusUInt11 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusUInt14_UPER
int Encode_UPER_PusUInt14(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt14 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt14_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt14 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt14_ACN
int Encode_ACN_PusUInt14(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt14 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt14_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt14 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt14_NATIVE
int Encode_NATIVE_PusUInt14(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt14 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusUInt14) );
    return sizeof(asn1SccPusUInt14);
}
#endif

#ifdef __NEED_PusUInt14_UPER
int Decode_UPER_PusUInt14(asn1SccPusUInt14 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt14_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt14 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt14_ACN
int Decode_ACN_PusUInt14(asn1SccPusUInt14 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt14_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt14 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt14_NATIVE
int Decode_NATIVE_PusUInt14(asn1SccPusUInt14 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusUInt14 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusUInt16_UPER
int Encode_UPER_PusUInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt16_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt16_ACN
int Encode_ACN_PusUInt16(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt16_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt16_NATIVE
int Encode_NATIVE_PusUInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt16 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusUInt16) );
    return sizeof(asn1SccPusUInt16);
}
#endif

#ifdef __NEED_PusUInt16_UPER
int Decode_UPER_PusUInt16(asn1SccPusUInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt16_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt16_ACN
int Decode_ACN_PusUInt16(asn1SccPusUInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt16_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt16_NATIVE
int Decode_NATIVE_PusUInt16(asn1SccPusUInt16 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusUInt16 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusUInt32_UPER
int Encode_UPER_PusUInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt32_ACN
int Encode_ACN_PusUInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt32_NATIVE
int Encode_NATIVE_PusUInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusUInt32) );
    return sizeof(asn1SccPusUInt32);
}
#endif

#ifdef __NEED_PusUInt32_UPER
int Decode_UPER_PusUInt32(asn1SccPusUInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt32_ACN
int Decode_ACN_PusUInt32(asn1SccPusUInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt32_NATIVE
int Decode_NATIVE_PusUInt32(asn1SccPusUInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusUInt32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusUInt64_UPER
int Encode_UPER_PusUInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt64_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt64_ACN
int Encode_ACN_PusUInt64(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt64_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusUInt64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt64_NATIVE
int Encode_NATIVE_PusUInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt64 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusUInt64) );
    return sizeof(asn1SccPusUInt64);
}
#endif

#ifdef __NEED_PusUInt64_UPER
int Decode_UPER_PusUInt64(asn1SccPusUInt64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt64_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt64_ACN
int Decode_ACN_PusUInt64(asn1SccPusUInt64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusUInt64_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusUInt64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusUInt64_NATIVE
int Decode_NATIVE_PusUInt64(asn1SccPusUInt64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusUInt64 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusInt32_UPER
int Encode_UPER_PusInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusInt32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusInt32_ACN
int Encode_ACN_PusInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccPusInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusInt32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusInt32_NATIVE
int Encode_NATIVE_PusInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusInt32) );
    return sizeof(asn1SccPusInt32);
}
#endif

#ifdef __NEED_PusInt32_UPER
int Decode_UPER_PusInt32(asn1SccPusInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusInt32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusInt32_ACN
int Decode_ACN_PusInt32(asn1SccPusInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusInt32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusInt32_NATIVE
int Decode_NATIVE_PusInt32(asn1SccPusInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusInt32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusInt64_UPER
int Encode_UPER_PusInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusInt64_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusInt64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusInt64_ACN
int Encode_ACN_PusInt64(void *pBuffer, size_t iMaxBufferSize, asn1SccPusInt64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusInt64_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusInt64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusInt64_NATIVE
int Encode_NATIVE_PusInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt64 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusInt64) );
    return sizeof(asn1SccPusInt64);
}
#endif

#ifdef __NEED_PusInt64_UPER
int Decode_UPER_PusInt64(asn1SccPusInt64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusInt64_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusInt64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusInt64_ACN
int Decode_ACN_PusInt64(asn1SccPusInt64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusInt64_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusInt64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusInt64_NATIVE
int Decode_NATIVE_PusInt64(asn1SccPusInt64 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusInt64 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusDouble_UPER
int Encode_UPER_PusDouble(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusDouble *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusDouble_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusDouble (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusDouble_ACN
int Encode_ACN_PusDouble(void *pBuffer, size_t iMaxBufferSize, asn1SccPusDouble *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusDouble_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusDouble (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusDouble_NATIVE
int Encode_NATIVE_PusDouble(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusDouble *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusDouble) );
    return sizeof(asn1SccPusDouble);
}
#endif

#ifdef __NEED_PusDouble_UPER
int Decode_UPER_PusDouble(asn1SccPusDouble *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusDouble_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusDouble (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusDouble_ACN
int Decode_ACN_PusDouble(asn1SccPusDouble *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusDouble_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusDouble (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusDouble_NATIVE
int Decode_NATIVE_PusDouble(asn1SccPusDouble *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusDouble *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusMemAddr_UPER
int Encode_UPER_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMemAddr *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusMemAddr_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusMemAddr (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusMemAddr_ACN
int Encode_ACN_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, asn1SccPusMemAddr *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusMemAddr_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode PusMemAddr (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusMemAddr_NATIVE
int Encode_NATIVE_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMemAddr *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccPusMemAddr) );
    return sizeof(asn1SccPusMemAddr);
}
#endif

#ifdef __NEED_PusMemAddr_UPER
int Decode_UPER_PusMemAddr(asn1SccPusMemAddr *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusMemAddr_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusMemAddr (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusMemAddr_ACN
int Decode_ACN_PusMemAddr(asn1SccPusMemAddr *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccPusMemAddr_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode PusMemAddr (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_PusMemAddr_NATIVE
int Decode_NATIVE_PusMemAddr(asn1SccPusMemAddr *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccPusMemAddr *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int32_UPER
int Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_ACN
int Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_NATIVE
int Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int32) );
    return sizeof(asn1SccT_Int32);
}
#endif

#ifdef __NEED_T_Int32_UPER
int Decode_UPER_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int32_ACN
int Decode_ACN_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int32_NATIVE
int Decode_NATIVE_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt32_UPER
int Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_ACN
int Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt32) );
    return sizeof(asn1SccT_UInt32);
}
#endif

#ifdef __NEED_T_UInt32_UPER
int Decode_UPER_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt32_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt32_ACN
int Decode_ACN_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt32_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Decode_NATIVE_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt32 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Int8_UPER
int Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_ACN
int Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_NATIVE
int Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Int8) );
    return sizeof(asn1SccT_Int8);
}
#endif

#ifdef __NEED_T_Int8_UPER
int Decode_UPER_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int8_ACN
int Decode_ACN_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Int8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Int8_NATIVE
int Decode_NATIVE_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Int8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_UInt8_UPER
int Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_ACN
int Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_UInt8) );
    return sizeof(asn1SccT_UInt8);
}
#endif

#ifdef __NEED_T_UInt8_UPER
int Decode_UPER_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt8_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt8_ACN
int Decode_ACN_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_UInt8_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Decode_NATIVE_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_UInt8 *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_T_Boolean_UPER
int Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_ACN
int Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
#ifdef __unix__
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccT_Boolean) );
    return sizeof(asn1SccT_Boolean);
}
#endif

#ifdef __NEED_T_Boolean_UPER
int Decode_UPER_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Boolean_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Boolean_ACN
int Decode_ACN_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccT_Boolean_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
#ifdef __unix__
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
#endif
        return -1;
    }
}
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Decode_NATIVE_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccT_Boolean *) pBuffer;
    {
        return 0;
    }
}
#endif

