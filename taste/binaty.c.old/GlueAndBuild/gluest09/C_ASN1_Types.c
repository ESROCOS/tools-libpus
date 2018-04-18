#include <stdio.h>
#include <string.h>

#include <assert.h>

#include "C_ASN1_Types.h"

#ifdef __NEED_PusPacket_UPER
size_t Encode_UPER_PusPacket(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacket *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacket_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacket (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacket_ACN
size_t Encode_ACN_PusPacket(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacket *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacket_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacket (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacket_NATIVE
size_t Encode_NATIVE_PusPacket(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacket *pSrc)
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
	fprintf(stderr, "Could not decode PusPacket (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusPacket (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt18ObcpChecksum_UPER
size_t Encode_UPER_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpChecksum *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpChecksum_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt18ObcpChecksum (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpChecksum_ACN
size_t Encode_ACN_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpChecksum *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpChecksum_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt18ObcpChecksum (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpChecksum_NATIVE
size_t Encode_NATIVE_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpChecksum *pSrc)
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
	fprintf(stderr, "Could not decode PusSt18ObcpChecksum (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt18ObcpChecksum (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusUInt16_UPER
size_t Encode_UPER_PusUInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt16_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt16_ACN
size_t Encode_ACN_PusUInt16(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt16 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt16_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt16 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt16_NATIVE
size_t Encode_NATIVE_PusUInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt16 *pSrc)
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
	fprintf(stderr, "Could not decode PusUInt16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusUInt16 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_9_1_Data_UPER
size_t Encode_UPER_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_9_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_9_1_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-9-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_9_1_Data_ACN
size_t Encode_ACN_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_9_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_9_1_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-9-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_9_1_Data_NATIVE
size_t Encode_NATIVE_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_9_1_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-9-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-9-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTM_3_25_Data_UPER
size_t Encode_UPER_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_3_25_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_3_25_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTM-3-25-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_3_25_Data_ACN
size_t Encode_ACN_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_3_25_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_3_25_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTM-3-25-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_3_25_Data_NATIVE
size_t Encode_NATIVE_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_3_25_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTM-3-25-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTM-3-25-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt20StoredParam_UPER
size_t Encode_UPER_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20StoredParam *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt20StoredParam_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt20StoredParam (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt20StoredParam_ACN
size_t Encode_ACN_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt20StoredParam *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt20StoredParam_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt20StoredParam (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt20StoredParam_NATIVE
size_t Encode_NATIVE_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20StoredParam *pSrc)
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
	fprintf(stderr, "Could not decode PusSt20StoredParam (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt20StoredParam (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt23RepositoryDomain_UPER
size_t Encode_UPER_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryDomain *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23RepositoryDomain_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt23RepositoryDomain (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryDomain_ACN
size_t Encode_ACN_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23RepositoryDomain *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23RepositoryDomain_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt23RepositoryDomain (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryDomain_NATIVE
size_t Encode_NATIVE_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryDomain *pSrc)
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
	fprintf(stderr, "Could not decode PusSt23RepositoryDomain (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt23RepositoryDomain (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt12pmonId_UPER
size_t Encode_UPER_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt12pmonId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt12pmonId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt12pmonId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt12pmonId_ACN
size_t Encode_ACN_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt12pmonId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt12pmonId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt12pmonId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt12pmonId_NATIVE
size_t Encode_NATIVE_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt12pmonId *pSrc)
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
	fprintf(stderr, "Could not decode PusSt12pmonId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt12pmonId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusPacketVersion_UPER
size_t Encode_UPER_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketVersion *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketVersion_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketVersion (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketVersion_ACN
size_t Encode_ACN_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketVersion *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketVersion_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketVersion (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketVersion_NATIVE
size_t Encode_NATIVE_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketVersion *pSrc)
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
	fprintf(stderr, "Could not decode PusPacketVersion (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusPacketVersion (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_18_3_Data_UPER
size_t Encode_UPER_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_3_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-18-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_3_Data_ACN
size_t Encode_ACN_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_3_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-18-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_3_Data_NATIVE
size_t Encode_NATIVE_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_3_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-18-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-18-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt03ParameterArray_UPER
size_t Encode_UPER_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterArray *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03ParameterArray_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt03ParameterArray (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03ParameterArray_ACN
size_t Encode_ACN_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03ParameterArray *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03ParameterArray_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt03ParameterArray (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03ParameterArray_NATIVE
size_t Encode_NATIVE_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterArray *pSrc)
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
	fprintf(stderr, "Could not decode PusSt03ParameterArray (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt03ParameterArray (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTM_1_X_Data_UPER
size_t Encode_UPER_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_1_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_1_X_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTM-1-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_1_X_Data_ACN
size_t Encode_ACN_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_1_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_1_X_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTM-1-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_1_X_Data_NATIVE
size_t Encode_NATIVE_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_1_X_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTM-1-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTM-1-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_TM_23_1_4_Data_UPER
size_t Encode_UPER_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_23_1_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_TM_23_1_4_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-TM-23-1-4-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_ACN
size_t Encode_ACN_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_TM_23_1_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_TM_23_1_4_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-TM-23-1-4-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_NATIVE
size_t Encode_NATIVE_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_23_1_4_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-TM-23-1-4-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-TM-23-1-4-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt18ObservabilityLevel_UPER
size_t Encode_UPER_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObservabilityLevel *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObservabilityLevel_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt18ObservabilityLevel (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_ACN
size_t Encode_ACN_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObservabilityLevel *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObservabilityLevel_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt18ObservabilityLevel (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_NATIVE
size_t Encode_NATIVE_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObservabilityLevel *pSrc)
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
	fprintf(stderr, "Could not decode PusSt18ObservabilityLevel (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt18ObservabilityLevel (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt05EventId_UPER
size_t Encode_UPER_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05EventId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt05EventId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05EventId_ACN
size_t Encode_ACN_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05EventId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05EventId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt05EventId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05EventId_NATIVE
size_t Encode_NATIVE_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventId *pSrc)
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
	fprintf(stderr, "Could not decode PusSt05EventId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt05EventId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_TM_20_X_Data_UPER
size_t Encode_UPER_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_20_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_TM_20_X_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-TM-20-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_ACN
size_t Encode_ACN_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_TM_20_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_TM_20_X_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-TM-20-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_NATIVE
size_t Encode_NATIVE_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_20_X_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-TM-20-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-TM-20-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSubserviceType_UPER
size_t Encode_UPER_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSubserviceType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSubserviceType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSubserviceType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSubserviceType_ACN
size_t Encode_ACN_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSubserviceType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSubserviceType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSubserviceType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSubserviceType_NATIVE
size_t Encode_NATIVE_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSubserviceType *pSrc)
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
	fprintf(stderr, "Could not decode PusSubserviceType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSubserviceType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusVersionNumber_UPER
size_t Encode_UPER_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusVersionNumber *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusVersionNumber_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusVersionNumber (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusVersionNumber_ACN
size_t Encode_ACN_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, asn1SccPusVersionNumber *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusVersionNumber_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusVersionNumber (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusVersionNumber_NATIVE
size_t Encode_NATIVE_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusVersionNumber *pSrc)
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
	fprintf(stderr, "Could not decode PusVersionNumber (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusVersionNumber (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_T_UInt8_UPER
size_t Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_ACN
size_t Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode T-UInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt8_NATIVE
size_t Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc)
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
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode T-UInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt18ObcpCode_UPER
size_t Encode_UPER_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpCode *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpCode_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt18ObcpCode (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpCode_ACN
size_t Encode_ACN_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpCode *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpCode_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt18ObcpCode (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpCode_NATIVE
size_t Encode_NATIVE_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpCode *pSrc)
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
	fprintf(stderr, "Could not decode PusSt18ObcpCode (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt18ObcpCode (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTmHeaderData_UPER
size_t Encode_UPER_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeaderData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmHeaderData_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTmHeaderData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmHeaderData_ACN
size_t Encode_ACN_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmHeaderData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmHeaderData_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTmHeaderData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmHeaderData_NATIVE
size_t Encode_NATIVE_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeaderData *pSrc)
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
	fprintf(stderr, "Could not decode PusTmHeaderData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTmHeaderData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTM_5_X_Data_UPER
size_t Encode_UPER_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_5_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_5_X_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTM-5-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_5_X_Data_ACN
size_t Encode_ACN_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_5_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_5_X_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTM-5-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_5_X_Data_NATIVE
size_t Encode_NATIVE_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_5_X_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTM-5-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTM-5-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_23_2_3_Data_UPER
size_t Encode_UPER_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_2_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_23_2_3_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-23-2-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_23_2_3_Data_ACN
size_t Encode_ACN_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_23_2_3_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_23_2_3_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-23-2-3-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_23_2_3_Data_NATIVE
size_t Encode_NATIVE_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_2_3_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-23-2-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-23-2-3-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSequenceCount_UPER
size_t Encode_UPER_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceCount *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSequenceCount_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSequenceCount (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSequenceCount_ACN
size_t Encode_ACN_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSequenceCount *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSequenceCount_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSequenceCount (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSequenceCount_NATIVE
size_t Encode_NATIVE_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceCount *pSrc)
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
	fprintf(stderr, "Could not decode PusSequenceCount (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSequenceCount (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusUInt3_UPER
size_t Encode_UPER_PusUInt3(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt3 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt3_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt3 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt3_ACN
size_t Encode_ACN_PusUInt3(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt3 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt3_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt3 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt3_NATIVE
size_t Encode_NATIVE_PusUInt3(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt3 *pSrc)
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
	fprintf(stderr, "Could not decode PusUInt3 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusUInt3 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTcApplicationData_UPER
size_t Encode_UPER_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcApplicationData_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTcApplicationData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcApplicationData_ACN
size_t Encode_ACN_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcApplicationData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcApplicationData_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTcApplicationData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcApplicationData_NATIVE
size_t Encode_NATIVE_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationData *pSrc)
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
	fprintf(stderr, "Could not decode PusTcApplicationData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTcApplicationData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusServiceType_UPER
size_t Encode_UPER_PusServiceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusServiceType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusServiceType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusServiceType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusServiceType_ACN
size_t Encode_ACN_PusServiceType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusServiceType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusServiceType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusServiceType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusServiceType_NATIVE
size_t Encode_NATIVE_PusServiceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusServiceType *pSrc)
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
	fprintf(stderr, "Could not decode PusServiceType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusServiceType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_T_Boolean_UPER
size_t Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_ACN
size_t Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Boolean_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode T-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Boolean_NATIVE
size_t Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc)
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
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode T-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt03HousekeepingReportId_UPER
size_t Encode_UPER_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03HousekeepingReportId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03HousekeepingReportId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt03HousekeepingReportId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_ACN
size_t Encode_ACN_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03HousekeepingReportId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03HousekeepingReportId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt03HousekeepingReportId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_NATIVE
size_t Encode_NATIVE_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03HousekeepingReportId *pSrc)
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
	fprintf(stderr, "Could not decode PusSt03HousekeepingReportId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt03HousekeepingReportId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt08FunctionId_UPER
size_t Encode_UPER_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt08FunctionId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt08FunctionId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt08FunctionId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt08FunctionId_ACN
size_t Encode_ACN_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt08FunctionId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt08FunctionId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt08FunctionId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt08FunctionId_NATIVE
size_t Encode_NATIVE_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt08FunctionId *pSrc)
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
	fprintf(stderr, "Could not decode PusSt08FunctionId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt08FunctionId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_12_1_2_Data_UPER
size_t Encode_UPER_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_12_1_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_12_1_2_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-12-1-2-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_12_1_2_Data_ACN
size_t Encode_ACN_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_12_1_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_12_1_2_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-12-1-2-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_12_1_2_Data_NATIVE
size_t Encode_NATIVE_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_12_1_2_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-12-1-2-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-12-1-2-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt09ExponentialRate_UPER
size_t Encode_UPER_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt09ExponentialRate *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt09ExponentialRate_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt09ExponentialRate (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt09ExponentialRate_ACN
size_t Encode_ACN_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt09ExponentialRate *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt09ExponentialRate_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt09ExponentialRate (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt09ExponentialRate_NATIVE
size_t Encode_NATIVE_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt09ExponentialRate *pSrc)
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
	fprintf(stderr, "Could not decode PusSt09ExponentialRate (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt09ExponentialRate (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt01RequestId_UPER
size_t Encode_UPER_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01RequestId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01RequestId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt01RequestId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01RequestId_ACN
size_t Encode_ACN_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01RequestId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01RequestId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt01RequestId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01RequestId_NATIVE
size_t Encode_NATIVE_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01RequestId *pSrc)
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
	fprintf(stderr, "Could not decode PusSt01RequestId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt01RequestId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt03ParameterId_UPER
size_t Encode_UPER_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03ParameterId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt03ParameterId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03ParameterId_ACN
size_t Encode_ACN_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03ParameterId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03ParameterId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt03ParameterId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03ParameterId_NATIVE
size_t Encode_NATIVE_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterId *pSrc)
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
	fprintf(stderr, "Could not decode PusSt03ParameterId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt03ParameterId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusPacketDataReduced_UPER
size_t Encode_UPER_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketDataReduced_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketDataReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketDataReduced_ACN
size_t Encode_ACN_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketDataReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketDataReduced_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketDataReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketDataReduced_NATIVE
size_t Encode_NATIVE_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataReduced *pSrc)
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
	fprintf(stderr, "Could not decode PusPacketDataReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusPacketDataReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusUInt64_UPER
size_t Encode_UPER_PusUInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt64_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt64_ACN
size_t Encode_ACN_PusUInt64(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt64_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt64_NATIVE
size_t Encode_NATIVE_PusUInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt64 *pSrc)
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
	fprintf(stderr, "Could not decode PusUInt64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusUInt64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt05Event_UPER
size_t Encode_UPER_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05Event *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05Event_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt05Event (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05Event_ACN
size_t Encode_ACN_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05Event *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05Event_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt05Event (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05Event_NATIVE
size_t Encode_NATIVE_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05Event *pSrc)
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
	fprintf(stderr, "Could not decode PusSt05Event (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt05Event (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusUInt32_UPER
size_t Encode_UPER_PusUInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt32_ACN
size_t Encode_ACN_PusUInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt32_NATIVE
size_t Encode_NATIVE_PusUInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt32 *pSrc)
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
	fprintf(stderr, "Could not decode PusUInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusUInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusMemAddr_UPER
size_t Encode_UPER_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMemAddr *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusMemAddr_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusMemAddr (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusMemAddr_ACN
size_t Encode_ACN_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, asn1SccPusMemAddr *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusMemAddr_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusMemAddr (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusMemAddr_NATIVE
size_t Encode_NATIVE_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMemAddr *pSrc)
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
	fprintf(stderr, "Could not decode PusMemAddr (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusMemAddr (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusUInt14_UPER
size_t Encode_UPER_PusUInt14(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt14 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt14_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt14 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt14_ACN
size_t Encode_ACN_PusUInt14(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt14 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt14_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt14 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt14_NATIVE
size_t Encode_NATIVE_PusUInt14(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt14 *pSrc)
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
	fprintf(stderr, "Could not decode PusUInt14 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusUInt14 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt01FailureCode_UPER
size_t Encode_UPER_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureCode *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01FailureCode_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt01FailureCode (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01FailureCode_ACN
size_t Encode_ACN_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01FailureCode *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01FailureCode_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt01FailureCode (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01FailureCode_NATIVE
size_t Encode_NATIVE_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureCode *pSrc)
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
	fprintf(stderr, "Could not decode PusSt01FailureCode (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt01FailureCode (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt18ObcpId_UPER
size_t Encode_UPER_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt18ObcpId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpId_ACN
size_t Encode_ACN_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt18ObcpId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt18ObcpId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt18ObcpId_NATIVE
size_t Encode_NATIVE_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpId *pSrc)
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
	fprintf(stderr, "Could not decode PusSt18ObcpId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt18ObcpId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusUInt8_UPER
size_t Encode_UPER_PusUInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt8_ACN
size_t Encode_ACN_PusUInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt8_NATIVE
size_t Encode_NATIVE_PusUInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt8 *pSrc)
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
	fprintf(stderr, "Could not decode PusUInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusUInt8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTmHeader_UPER
size_t Encode_UPER_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeader *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmHeader_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTmHeader (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmHeader_ACN
size_t Encode_ACN_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmHeader *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmHeader_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTmHeader (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmHeader_NATIVE
size_t Encode_NATIVE_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeader *pSrc)
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
	fprintf(stderr, "Could not decode PusTmHeader (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTmHeader (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusPacketType_UPER
size_t Encode_UPER_PusPacketType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketType_ACN
size_t Encode_ACN_PusPacketType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketType_NATIVE
size_t Encode_NATIVE_PusPacketType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketType *pSrc)
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
	fprintf(stderr, "Could not decode PusPacketType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusPacketType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTcApplicationDataReduced_UPER
size_t Encode_UPER_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationDataReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcApplicationDataReduced_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTcApplicationDataReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcApplicationDataReduced_ACN
size_t Encode_ACN_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcApplicationDataReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcApplicationDataReduced_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTcApplicationDataReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcApplicationDataReduced_NATIVE
size_t Encode_NATIVE_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationDataReduced *pSrc)
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
	fprintf(stderr, "Could not decode PusTcApplicationDataReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTcApplicationDataReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_T_Int8_UPER
size_t Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_ACN
size_t Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int8_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode T-Int8 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int8_NATIVE
size_t Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc)
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
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode T-Int8 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt05EventAuxData_UPER
size_t Encode_UPER_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventAuxData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05EventAuxData_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt05EventAuxData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05EventAuxData_ACN
size_t Encode_ACN_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05EventAuxData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt05EventAuxData_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt05EventAuxData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt05EventAuxData_NATIVE
size_t Encode_NATIVE_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventAuxData *pSrc)
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
	fprintf(stderr, "Could not decode PusSt05EventAuxData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt05EventAuxData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt01Failure_UPER
size_t Encode_UPER_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01Failure *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01Failure_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt01Failure (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01Failure_ACN
size_t Encode_ACN_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01Failure *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01Failure_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt01Failure (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01Failure_NATIVE
size_t Encode_NATIVE_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01Failure *pSrc)
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
	fprintf(stderr, "Could not decode PusSt01Failure (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt01Failure (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusAcknowledgementFlags_UPER
size_t Encode_UPER_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusAcknowledgementFlags *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusAcknowledgementFlags_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusAcknowledgementFlags (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusAcknowledgementFlags_ACN
size_t Encode_ACN_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, asn1SccPusAcknowledgementFlags *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusAcknowledgementFlags_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusAcknowledgementFlags (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusAcknowledgementFlags_NATIVE
size_t Encode_NATIVE_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusAcknowledgementFlags *pSrc)
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
	fprintf(stderr, "Could not decode PusAcknowledgementFlags (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusAcknowledgementFlags (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusInt32_UPER
size_t Encode_UPER_PusInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusInt32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusInt32_ACN
size_t Encode_ACN_PusInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccPusInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusInt32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusInt32_NATIVE
size_t Encode_NATIVE_PusInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt32 *pSrc)
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
	fprintf(stderr, "Could not decode PusInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusUInt11_UPER
size_t Encode_UPER_PusUInt11(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt11 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt11_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt11 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt11_ACN
size_t Encode_ACN_PusUInt11(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt11 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt11_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt11 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt11_NATIVE
size_t Encode_NATIVE_PusUInt11(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt11 *pSrc)
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
	fprintf(stderr, "Could not decode PusUInt11 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusUInt11 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTcHeader_UPER
size_t Encode_UPER_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcHeader *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcHeader_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTcHeader (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcHeader_ACN
size_t Encode_ACN_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcHeader *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcHeader_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTcHeader (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcHeader_NATIVE
size_t Encode_NATIVE_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcHeader *pSrc)
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
	fprintf(stderr, "Could not decode PusTcHeader (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTcHeader (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusPacketReduced_UPER
size_t Encode_UPER_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketReduced_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketReduced_ACN
size_t Encode_ACN_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketReduced *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketReduced_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketReduced (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketReduced_NATIVE
size_t Encode_NATIVE_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketReduced *pSrc)
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
	fprintf(stderr, "Could not decode PusPacketReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusPacketReduced (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt03StoredParam_UPER
size_t Encode_UPER_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03StoredParam *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03StoredParam_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt03StoredParam (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03StoredParam_ACN
size_t Encode_ACN_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03StoredParam *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt03StoredParam_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt03StoredParam (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt03StoredParam_NATIVE
size_t Encode_NATIVE_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03StoredParam *pSrc)
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
	fprintf(stderr, "Could not decode PusSt03StoredParam (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt03StoredParam (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusUInt4_UPER
size_t Encode_UPER_PusUInt4(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt4 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt4_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt4 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt4_ACN
size_t Encode_ACN_PusUInt4(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt4 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusUInt4_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusUInt4 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusUInt4_NATIVE
size_t Encode_NATIVE_PusUInt4(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt4 *pSrc)
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
	fprintf(stderr, "Could not decode PusUInt4 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusUInt4 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTcScheduledActivity_UPER
size_t Encode_UPER_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcScheduledActivity *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcScheduledActivity_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTcScheduledActivity (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcScheduledActivity_ACN
size_t Encode_ACN_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcScheduledActivity *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTcScheduledActivity_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTcScheduledActivity (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTcScheduledActivity_NATIVE
size_t Encode_NATIVE_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcScheduledActivity *pSrc)
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
	fprintf(stderr, "Could not decode PusTcScheduledActivity (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTcScheduledActivity (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_18_13_Data_UPER
size_t Encode_UPER_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_13_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_13_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-18-13-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_13_Data_ACN
size_t Encode_ACN_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_13_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_13_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-18-13-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_13_Data_NATIVE
size_t Encode_NATIVE_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_13_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-18-13-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-18-13-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTime_UPER
size_t Encode_UPER_PusTime(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTime *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTime_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTime (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTime_ACN
size_t Encode_ACN_PusTime(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTime *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTime_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTime (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTime_NATIVE
size_t Encode_NATIVE_PusTime(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTime *pSrc)
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
	fprintf(stderr, "Could not decode PusTime (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTime (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusApid_UPER
size_t Encode_UPER_PusApid(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusApid *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusApid_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusApid (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusApid_ACN
size_t Encode_ACN_PusApid(void *pBuffer, size_t iMaxBufferSize, asn1SccPusApid *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusApid_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusApid (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusApid_NATIVE
size_t Encode_NATIVE_PusApid(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusApid *pSrc)
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
	fprintf(stderr, "Could not decode PusApid (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusApid (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_23_14_Data_UPER
size_t Encode_UPER_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_14_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_23_14_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-23-14-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_23_14_Data_ACN
size_t Encode_ACN_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_23_14_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_23_14_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-23-14-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_23_14_Data_NATIVE
size_t Encode_NATIVE_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_14_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-23-14-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-23-14-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSequenceFlags_UPER
size_t Encode_UPER_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceFlags *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSequenceFlags_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSequenceFlags (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSequenceFlags_ACN
size_t Encode_ACN_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSequenceFlags *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSequenceFlags_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSequenceFlags (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSequenceFlags_NATIVE
size_t Encode_NATIVE_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceFlags *pSrc)
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
	fprintf(stderr, "Could not decode PusSequenceFlags (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSequenceFlags (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt20OnBoardParameterId_UPER
size_t Encode_UPER_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20OnBoardParameterId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt20OnBoardParameterId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt20OnBoardParameterId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_ACN
size_t Encode_ACN_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt20OnBoardParameterId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt20OnBoardParameterId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt20OnBoardParameterId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_NATIVE
size_t Encode_NATIVE_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20OnBoardParameterId *pSrc)
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
	fprintf(stderr, "Could not decode PusSt20OnBoardParameterId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt20OnBoardParameterId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusChecksum_UPER
size_t Encode_UPER_PusChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusChecksum *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusChecksum_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusChecksum (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusChecksum_ACN
size_t Encode_ACN_PusChecksum(void *pBuffer, size_t iMaxBufferSize, asn1SccPusChecksum *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusChecksum_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusChecksum (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusChecksum_NATIVE
size_t Encode_NATIVE_PusChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusChecksum *pSrc)
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
	fprintf(stderr, "Could not decode PusChecksum (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusChecksum (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTM_9_2_Data_UPER
size_t Encode_UPER_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_9_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_9_2_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTM-9-2-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_9_2_Data_ACN
size_t Encode_ACN_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_9_2_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTM_9_2_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTM-9-2-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTM_9_2_Data_NATIVE
size_t Encode_NATIVE_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_9_2_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTM-9-2-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTM-9-2-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusMessageTypeCounter_UPER
size_t Encode_UPER_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMessageTypeCounter *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusMessageTypeCounter_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusMessageTypeCounter (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusMessageTypeCounter_ACN
size_t Encode_ACN_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, asn1SccPusMessageTypeCounter *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusMessageTypeCounter_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusMessageTypeCounter (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusMessageTypeCounter_NATIVE
size_t Encode_NATIVE_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMessageTypeCounter *pSrc)
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
	fprintf(stderr, "Could not decode PusMessageTypeCounter (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusMessageTypeCounter (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_T_UInt32_UPER
size_t Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_ACN
size_t Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_UInt32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode T-UInt32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_UInt32_NATIVE
size_t Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc)
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
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode T-UInt32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTimeReferenceStatus_UPER
size_t Encode_UPER_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTimeReferenceStatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTimeReferenceStatus_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTimeReferenceStatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTimeReferenceStatus_ACN
size_t Encode_ACN_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTimeReferenceStatus *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTimeReferenceStatus_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTimeReferenceStatus (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTimeReferenceStatus_NATIVE
size_t Encode_NATIVE_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTimeReferenceStatus *pSrc)
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
	fprintf(stderr, "Could not decode PusTimeReferenceStatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTimeReferenceStatus (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_19_1_Data_UPER
size_t Encode_UPER_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_19_1_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-19-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_19_1_Data_ACN
size_t Encode_ACN_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_19_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_19_1_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-19-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_19_1_Data_NATIVE
size_t Encode_NATIVE_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_1_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-19-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-19-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusStepId_UPER
size_t Encode_UPER_PusStepId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusStepId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusStepId_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusStepId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusStepId_ACN
size_t Encode_ACN_PusStepId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusStepId *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusStepId_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusStepId (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusStepId_NATIVE
size_t Encode_NATIVE_PusStepId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusStepId *pSrc)
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
	fprintf(stderr, "Could not decode PusStepId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusStepId (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
size_t Encode_UPER_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusConfigDummyType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusConfigDummyType_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusConfigDummyType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusConfigDummyType_ACN
size_t Encode_ACN_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusConfigDummyType *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusConfigDummyType_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusConfigDummyType (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusConfigDummyType_NATIVE
size_t Encode_NATIVE_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusConfigDummyType *pSrc)
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
	fprintf(stderr, "Could not decode PusConfigDummyType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusConfigDummyType (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTmSourceData_UPER
size_t Encode_UPER_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmSourceData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmSourceData_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTmSourceData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmSourceData_ACN
size_t Encode_ACN_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmSourceData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTmSourceData_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTmSourceData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTmSourceData_NATIVE
size_t Encode_NATIVE_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmSourceData *pSrc)
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
	fprintf(stderr, "Could not decode PusTmSourceData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTmSourceData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_T_Int32_UPER
size_t Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_ACN
size_t Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccT_Int32_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode T-Int32 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_T_Int32_NATIVE
size_t Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc)
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
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode T-Int32 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_8_1_Data_UPER
size_t Encode_UPER_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_8_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_8_1_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-8-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_8_1_Data_ACN
size_t Encode_ACN_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_8_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_8_1_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-8-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_8_1_Data_NATIVE
size_t Encode_NATIVE_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_8_1_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-8-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-8-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_18_1_Data_UPER
size_t Encode_UPER_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_1_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-18-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_1_Data_ACN
size_t Encode_ACN_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_1_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_1_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-18-1-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_1_Data_NATIVE
size_t Encode_NATIVE_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_1_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-18-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-18-1-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusPacketData_UPER
size_t Encode_UPER_PusPacketData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketData_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketData_ACN
size_t Encode_ACN_PusPacketData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketData *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketData_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketData (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketData_NATIVE
size_t Encode_NATIVE_PusPacketData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketData *pSrc)
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
	fprintf(stderr, "Could not decode PusPacketData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusPacketData (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt01FailureInfo_UPER
size_t Encode_UPER_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureInfo *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01FailureInfo_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt01FailureInfo (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01FailureInfo_ACN
size_t Encode_ACN_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01FailureInfo *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt01FailureInfo_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt01FailureInfo (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt01FailureInfo_NATIVE
size_t Encode_NATIVE_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureInfo *pSrc)
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
	fprintf(stderr, "Could not decode PusSt01FailureInfo (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt01FailureInfo (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_TASTE_Boolean_UPER
size_t Encode_UPER_TASTE_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccTASTE_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTASTE_Boolean_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode TASTE-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TASTE_Boolean_ACN
size_t Encode_ACN_TASTE_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccTASTE_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccTASTE_Boolean_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode TASTE-Boolean (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_TASTE_Boolean_NATIVE
size_t Encode_NATIVE_TASTE_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccTASTE_Boolean *pSrc)
{
    (void)iMaxBufferSize;
    memcpy(pBuffer, pSrc, sizeof(asn1SccTASTE_Boolean) );
    return sizeof(asn1SccTASTE_Boolean);
}
#endif

#ifdef __NEED_TASTE_Boolean_UPER
int Decode_UPER_TASTE_Boolean(asn1SccTASTE_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTASTE_Boolean_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
	fprintf(stderr, "Could not decode TASTE-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    }
}
#endif

#ifdef __NEED_TASTE_Boolean_ACN
int Decode_ACN_TASTE_Boolean(asn1SccTASTE_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    int errorCode;

    STATIC BitStream strm;

    BitStream_AttachBuffer(&strm, pBuffer, iBufferSize);

    if (asn1SccTASTE_Boolean_ACN_Decode(pDst, &strm, &errorCode)) {
        /* Decoding succeeded */
        return 0;
    } else {
	fprintf(stderr, "Could not decode TASTE-Boolean (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    }
}
#endif

#ifdef __NEED_TASTE_Boolean_NATIVE
int Decode_NATIVE_TASTE_Boolean(asn1SccTASTE_Boolean *pDst, void *pBuffer, size_t iBufferSize)
{
    (void)iBufferSize;
    *pDst = *(asn1SccTASTE_Boolean *) pBuffer;
    {
        return 0;
    }
}
#endif

#ifdef __NEED_PusPacketDataLength_UPER
size_t Encode_UPER_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataLength *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketDataLength_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketDataLength (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketDataLength_ACN
size_t Encode_ACN_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketDataLength *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusPacketDataLength_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusPacketDataLength (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusPacketDataLength_NATIVE
size_t Encode_NATIVE_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataLength *pSrc)
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
	fprintf(stderr, "Could not decode PusPacketDataLength (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusPacketDataLength (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusInt64_UPER
size_t Encode_UPER_PusInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusInt64_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusInt64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusInt64_ACN
size_t Encode_ACN_PusInt64(void *pBuffer, size_t iMaxBufferSize, asn1SccPusInt64 *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusInt64_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusInt64 (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusInt64_NATIVE
size_t Encode_NATIVE_PusInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt64 *pSrc)
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
	fprintf(stderr, "Could not decode PusInt64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusInt64 (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_19_X_Data_UPER
size_t Encode_UPER_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_19_X_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-19-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_19_X_Data_ACN
size_t Encode_ACN_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_19_X_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_19_X_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-19-X-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_19_X_Data_NATIVE
size_t Encode_NATIVE_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_X_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-19-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-19-X-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_18_2_6_12_Data_UPER
size_t Encode_UPER_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_2_6_12_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_2_6_12_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-18-2-6-12-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_ACN
size_t Encode_ACN_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_2_6_12_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_2_6_12_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-18-2-6-12-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_NATIVE
size_t Encode_NATIVE_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_2_6_12_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-18-2-6-12-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-18-2-6-12-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_18_4_5_Data_UPER
size_t Encode_UPER_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_4_5_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_4_5_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-18-4-5-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_4_5_Data_ACN
size_t Encode_ACN_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_4_5_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_18_4_5_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-18-4-5-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_18_4_5_Data_NATIVE
size_t Encode_NATIVE_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_4_5_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-18-4-5-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-18-4-5-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSt23RepositoryPath_UPER
size_t Encode_UPER_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryPath *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23RepositoryPath_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt23RepositoryPath (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryPath_ACN
size_t Encode_ACN_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23RepositoryPath *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23RepositoryPath_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt23RepositoryPath (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23RepositoryPath_NATIVE
size_t Encode_NATIVE_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryPath *pSrc)
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
	fprintf(stderr, "Could not decode PusSt23RepositoryPath (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt23RepositoryPath (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
size_t Encode_UPER_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23FileName *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23FileName_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt23FileName (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23FileName_ACN
size_t Encode_ACN_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23FileName *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSt23FileName_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSt23FileName (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSt23FileName_NATIVE
size_t Encode_NATIVE_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23FileName *pSrc)
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
	fprintf(stderr, "Could not decode PusSt23FileName (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSt23FileName (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusSecondaryHeaderFlag_UPER
size_t Encode_UPER_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSecondaryHeaderFlag *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSecondaryHeaderFlag_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSecondaryHeaderFlag (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_ACN
size_t Encode_ACN_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSecondaryHeaderFlag *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusSecondaryHeaderFlag_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusSecondaryHeaderFlag (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_NATIVE
size_t Encode_NATIVE_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSecondaryHeaderFlag *pSrc)
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
	fprintf(stderr, "Could not decode PusSecondaryHeaderFlag (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusSecondaryHeaderFlag (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

#ifdef __NEED_PusTC_11_4_Data_UPER
size_t Encode_UPER_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_11_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_11_4_Data_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-11-4-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_11_4_Data_ACN
size_t Encode_ACN_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_11_4_Data *pSrc)
{
    (void)iMaxBufferSize;
    int errorCode;
    STATIC BitStream strm;

    BitStream_Init(&strm, pBuffer, iMaxBufferSize);
    if (asn1SccPusTC_11_4_Data_ACN_Encode(pSrc, &strm, &errorCode, TRUE) == FALSE) {
	fprintf(stderr, "Could not encode PusTC-11-4-Data (at %s, %d), errorCode was %d\n", __FILE__, __LINE__, errorCode);
        return -1;
    } else {
        return BitStream_GetLength(&strm);
    }
}
#endif

#ifdef __NEED_PusTC_11_4_Data_NATIVE
size_t Encode_NATIVE_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_11_4_Data *pSrc)
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
	fprintf(stderr, "Could not decode PusTC-11-4-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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
	fprintf(stderr, "Could not decode PusTC-11-4-Data (at %s, %d), error code was %d\n", __FILE__, __LINE__, errorCode);
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

