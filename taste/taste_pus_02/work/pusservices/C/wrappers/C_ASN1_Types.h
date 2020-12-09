#ifndef __C_DATAVIEW_UNIQ_H__
#define __C_DATAVIEW_UNIQ_H__

#ifdef __unix__
#include <stdlib.h> /* for size_t */
#else
typedef unsigned size_t;
#endif

#ifndef STATIC
#define STATIC
#endif


#include "dataview-uniq.h" // Space certified compiler generated

#include "../../system_config.h" // Choose ASN.1 Types to use

#ifdef __NEED_PusTM_TC_Dummy_Data_UPER
int Encode_UPER_PusTM_TC_Dummy_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_TC_Dummy_Data *pSrc);
#endif

#ifdef __NEED_PusTM_TC_Dummy_Data_ACN
int Encode_ACN_PusTM_TC_Dummy_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_TC_Dummy_Data *pSrc);
#endif

#ifdef __NEED_PusTM_TC_Dummy_Data_NATIVE
int Encode_NATIVE_PusTM_TC_Dummy_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_TC_Dummy_Data *pSrc);
#endif

#ifdef __NEED_PusTM_TC_Dummy_Data_UPER
int Decode_UPER_PusTM_TC_Dummy_Data(asn1SccPusTM_TC_Dummy_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_TC_Dummy_Data_ACN
int Decode_ACN_PusTM_TC_Dummy_Data(asn1SccPusTM_TC_Dummy_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_TC_Dummy_Data_NATIVE
int Decode_NATIVE_PusTM_TC_Dummy_Data(asn1SccPusTM_TC_Dummy_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTmHeader_UPER
int Encode_UPER_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeader *pSrc);
#endif

#ifdef __NEED_PusTmHeader_ACN
int Encode_ACN_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmHeader *pSrc);
#endif

#ifdef __NEED_PusTmHeader_NATIVE
int Encode_NATIVE_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeader *pSrc);
#endif

#ifdef __NEED_PusTmHeader_UPER
int Decode_UPER_PusTmHeader(asn1SccPusTmHeader *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTmHeader_ACN
int Decode_ACN_PusTmHeader(asn1SccPusTmHeader *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTmHeader_NATIVE
int Decode_NATIVE_PusTmHeader(asn1SccPusTmHeader *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTmSourceData_UPER
int Encode_UPER_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmSourceData *pSrc);
#endif

#ifdef __NEED_PusTmSourceData_ACN
int Encode_ACN_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmSourceData *pSrc);
#endif

#ifdef __NEED_PusTmSourceData_NATIVE
int Encode_NATIVE_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmSourceData *pSrc);
#endif

#ifdef __NEED_PusTmSourceData_UPER
int Decode_UPER_PusTmSourceData(asn1SccPusTmSourceData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTmSourceData_ACN
int Decode_ACN_PusTmSourceData(asn1SccPusTmSourceData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTmSourceData_NATIVE
int Decode_NATIVE_PusTmSourceData(asn1SccPusTmSourceData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcHeader_UPER
int Encode_UPER_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcHeader *pSrc);
#endif

#ifdef __NEED_PusTcHeader_ACN
int Encode_ACN_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcHeader *pSrc);
#endif

#ifdef __NEED_PusTcHeader_NATIVE
int Encode_NATIVE_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcHeader *pSrc);
#endif

#ifdef __NEED_PusTcHeader_UPER
int Decode_UPER_PusTcHeader(asn1SccPusTcHeader *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcHeader_ACN
int Decode_ACN_PusTcHeader(asn1SccPusTcHeader *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcHeader_NATIVE
int Decode_NATIVE_PusTcHeader(asn1SccPusTcHeader *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_19_1_Data_UPER
int Encode_UPER_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_19_1_Data_ACN
int Encode_ACN_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_19_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_19_1_Data_NATIVE
int Encode_NATIVE_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_19_1_Data_UPER
int Decode_UPER_PusTC_19_1_Data(asn1SccPusTC_19_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_19_1_Data_ACN
int Decode_ACN_PusTC_19_1_Data(asn1SccPusTC_19_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_19_1_Data_NATIVE
int Decode_NATIVE_PusTC_19_1_Data(asn1SccPusTC_19_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcScheduledActivity_UPER
int Encode_UPER_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcScheduledActivity *pSrc);
#endif

#ifdef __NEED_PusTcScheduledActivity_ACN
int Encode_ACN_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcScheduledActivity *pSrc);
#endif

#ifdef __NEED_PusTcScheduledActivity_NATIVE
int Encode_NATIVE_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcScheduledActivity *pSrc);
#endif

#ifdef __NEED_PusTcScheduledActivity_UPER
int Decode_UPER_PusTcScheduledActivity(asn1SccPusTcScheduledActivity *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcScheduledActivity_ACN
int Decode_ACN_PusTcScheduledActivity(asn1SccPusTcScheduledActivity *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcScheduledActivity_NATIVE
int Decode_NATIVE_PusTcScheduledActivity(asn1SccPusTcScheduledActivity *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_11_4_Data_UPER
int Encode_UPER_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_11_4_Data *pSrc);
#endif

#ifdef __NEED_PusTC_11_4_Data_ACN
int Encode_ACN_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_11_4_Data *pSrc);
#endif

#ifdef __NEED_PusTC_11_4_Data_NATIVE
int Encode_NATIVE_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_11_4_Data *pSrc);
#endif

#ifdef __NEED_PusTC_11_4_Data_UPER
int Decode_UPER_PusTC_11_4_Data(asn1SccPusTC_11_4_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_11_4_Data_ACN
int Decode_ACN_PusTC_11_4_Data(asn1SccPusTC_11_4_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_11_4_Data_NATIVE
int Decode_NATIVE_PusTC_11_4_Data(asn1SccPusTC_11_4_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcApplicationData_UPER
int Encode_UPER_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationData *pSrc);
#endif

#ifdef __NEED_PusTcApplicationData_ACN
int Encode_ACN_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcApplicationData *pSrc);
#endif

#ifdef __NEED_PusTcApplicationData_NATIVE
int Encode_NATIVE_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationData *pSrc);
#endif

#ifdef __NEED_PusTcApplicationData_UPER
int Decode_UPER_PusTcApplicationData(asn1SccPusTcApplicationData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcApplicationData_ACN
int Decode_ACN_PusTcApplicationData(asn1SccPusTcApplicationData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcApplicationData_NATIVE
int Decode_NATIVE_PusTcApplicationData(asn1SccPusTcApplicationData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcApplicationDataReduced_UPER
int Encode_UPER_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationDataReduced *pSrc);
#endif

#ifdef __NEED_PusTcApplicationDataReduced_ACN
int Encode_ACN_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcApplicationDataReduced *pSrc);
#endif

#ifdef __NEED_PusTcApplicationDataReduced_NATIVE
int Encode_NATIVE_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationDataReduced *pSrc);
#endif

#ifdef __NEED_PusTcApplicationDataReduced_UPER
int Decode_UPER_PusTcApplicationDataReduced(asn1SccPusTcApplicationDataReduced *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcApplicationDataReduced_ACN
int Decode_ACN_PusTcApplicationDataReduced(asn1SccPusTcApplicationDataReduced *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcApplicationDataReduced_NATIVE
int Decode_NATIVE_PusTcApplicationDataReduced(asn1SccPusTcApplicationDataReduced *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTmHeaderData_UPER
int Encode_UPER_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeaderData *pSrc);
#endif

#ifdef __NEED_PusTmHeaderData_ACN
int Encode_ACN_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmHeaderData *pSrc);
#endif

#ifdef __NEED_PusTmHeaderData_NATIVE
int Encode_NATIVE_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeaderData *pSrc);
#endif

#ifdef __NEED_PusTmHeaderData_UPER
int Decode_UPER_PusTmHeaderData(asn1SccPusTmHeaderData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTmHeaderData_ACN
int Decode_ACN_PusTmHeaderData(asn1SccPusTmHeaderData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTmHeaderData_NATIVE
int Decode_NATIVE_PusTmHeaderData(asn1SccPusTmHeaderData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketData_UPER
int Encode_UPER_PusPacketData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketData *pSrc);
#endif

#ifdef __NEED_PusPacketData_ACN
int Encode_ACN_PusPacketData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketData *pSrc);
#endif

#ifdef __NEED_PusPacketData_NATIVE
int Encode_NATIVE_PusPacketData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketData *pSrc);
#endif

#ifdef __NEED_PusPacketData_UPER
int Decode_UPER_PusPacketData(asn1SccPusPacketData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketData_ACN
int Decode_ACN_PusPacketData(asn1SccPusPacketData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketData_NATIVE
int Decode_NATIVE_PusPacketData(asn1SccPusPacketData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketDataReduced_UPER
int Encode_UPER_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataReduced *pSrc);
#endif

#ifdef __NEED_PusPacketDataReduced_ACN
int Encode_ACN_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketDataReduced *pSrc);
#endif

#ifdef __NEED_PusPacketDataReduced_NATIVE
int Encode_NATIVE_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataReduced *pSrc);
#endif

#ifdef __NEED_PusPacketDataReduced_UPER
int Decode_UPER_PusPacketDataReduced(asn1SccPusPacketDataReduced *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketDataReduced_ACN
int Decode_ACN_PusPacketDataReduced(asn1SccPusPacketDataReduced *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketDataReduced_NATIVE
int Decode_NATIVE_PusPacketDataReduced(asn1SccPusPacketDataReduced *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacket_UPER
int Encode_UPER_PusPacket(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacket *pSrc);
#endif

#ifdef __NEED_PusPacket_ACN
int Encode_ACN_PusPacket(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacket *pSrc);
#endif

#ifdef __NEED_PusPacket_NATIVE
int Encode_NATIVE_PusPacket(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacket *pSrc);
#endif

#ifdef __NEED_PusPacket_UPER
int Decode_UPER_PusPacket(asn1SccPusPacket *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacket_ACN
int Decode_ACN_PusPacket(asn1SccPusPacket *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacket_NATIVE
int Decode_NATIVE_PusPacket(asn1SccPusPacket *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketReduced_UPER
int Encode_UPER_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketReduced *pSrc);
#endif

#ifdef __NEED_PusPacketReduced_ACN
int Encode_ACN_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketReduced *pSrc);
#endif

#ifdef __NEED_PusPacketReduced_NATIVE
int Encode_NATIVE_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketReduced *pSrc);
#endif

#ifdef __NEED_PusPacketReduced_UPER
int Decode_UPER_PusPacketReduced(asn1SccPusPacketReduced *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketReduced_ACN
int Decode_ACN_PusPacketReduced(asn1SccPusPacketReduced *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketReduced_NATIVE
int Decode_NATIVE_PusPacketReduced(asn1SccPusPacketReduced *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketVersion_UPER
int Encode_UPER_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketVersion *pSrc);
#endif

#ifdef __NEED_PusPacketVersion_ACN
int Encode_ACN_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketVersion *pSrc);
#endif

#ifdef __NEED_PusPacketVersion_NATIVE
int Encode_NATIVE_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketVersion *pSrc);
#endif

#ifdef __NEED_PusPacketVersion_UPER
int Decode_UPER_PusPacketVersion(asn1SccPusPacketVersion *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketVersion_ACN
int Decode_ACN_PusPacketVersion(asn1SccPusPacketVersion *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketVersion_NATIVE
int Decode_NATIVE_PusPacketVersion(asn1SccPusPacketVersion *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketType_UPER
int Encode_UPER_PusPacketType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketType *pSrc);
#endif

#ifdef __NEED_PusPacketType_ACN
int Encode_ACN_PusPacketType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketType *pSrc);
#endif

#ifdef __NEED_PusPacketType_NATIVE
int Encode_NATIVE_PusPacketType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketType *pSrc);
#endif

#ifdef __NEED_PusPacketType_UPER
int Decode_UPER_PusPacketType(asn1SccPusPacketType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketType_ACN
int Decode_ACN_PusPacketType(asn1SccPusPacketType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketType_NATIVE
int Decode_NATIVE_PusPacketType(asn1SccPusPacketType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_UPER
int Encode_UPER_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSecondaryHeaderFlag *pSrc);
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_ACN
int Encode_ACN_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSecondaryHeaderFlag *pSrc);
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_NATIVE
int Encode_NATIVE_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSecondaryHeaderFlag *pSrc);
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_UPER
int Decode_UPER_PusSecondaryHeaderFlag(asn1SccPusSecondaryHeaderFlag *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_ACN
int Decode_ACN_PusSecondaryHeaderFlag(asn1SccPusSecondaryHeaderFlag *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_NATIVE
int Decode_NATIVE_PusSecondaryHeaderFlag(asn1SccPusSecondaryHeaderFlag *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusApid_UPER
int Encode_UPER_PusApid(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusApid *pSrc);
#endif

#ifdef __NEED_PusApid_ACN
int Encode_ACN_PusApid(void *pBuffer, size_t iMaxBufferSize, asn1SccPusApid *pSrc);
#endif

#ifdef __NEED_PusApid_NATIVE
int Encode_NATIVE_PusApid(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusApid *pSrc);
#endif

#ifdef __NEED_PusApid_UPER
int Decode_UPER_PusApid(asn1SccPusApid *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusApid_ACN
int Decode_ACN_PusApid(asn1SccPusApid *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusApid_NATIVE
int Decode_NATIVE_PusApid(asn1SccPusApid *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSequenceFlags_UPER
int Encode_UPER_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceFlags *pSrc);
#endif

#ifdef __NEED_PusSequenceFlags_ACN
int Encode_ACN_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSequenceFlags *pSrc);
#endif

#ifdef __NEED_PusSequenceFlags_NATIVE
int Encode_NATIVE_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceFlags *pSrc);
#endif

#ifdef __NEED_PusSequenceFlags_UPER
int Decode_UPER_PusSequenceFlags(asn1SccPusSequenceFlags *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSequenceFlags_ACN
int Decode_ACN_PusSequenceFlags(asn1SccPusSequenceFlags *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSequenceFlags_NATIVE
int Decode_NATIVE_PusSequenceFlags(asn1SccPusSequenceFlags *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSequenceCount_UPER
int Encode_UPER_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceCount *pSrc);
#endif

#ifdef __NEED_PusSequenceCount_ACN
int Encode_ACN_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSequenceCount *pSrc);
#endif

#ifdef __NEED_PusSequenceCount_NATIVE
int Encode_NATIVE_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceCount *pSrc);
#endif

#ifdef __NEED_PusSequenceCount_UPER
int Decode_UPER_PusSequenceCount(asn1SccPusSequenceCount *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSequenceCount_ACN
int Decode_ACN_PusSequenceCount(asn1SccPusSequenceCount *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSequenceCount_NATIVE
int Decode_NATIVE_PusSequenceCount(asn1SccPusSequenceCount *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketDataLength_UPER
int Encode_UPER_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataLength *pSrc);
#endif

#ifdef __NEED_PusPacketDataLength_ACN
int Encode_ACN_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketDataLength *pSrc);
#endif

#ifdef __NEED_PusPacketDataLength_NATIVE
int Encode_NATIVE_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataLength *pSrc);
#endif

#ifdef __NEED_PusPacketDataLength_UPER
int Decode_UPER_PusPacketDataLength(asn1SccPusPacketDataLength *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketDataLength_ACN
int Decode_ACN_PusPacketDataLength(asn1SccPusPacketDataLength *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusPacketDataLength_NATIVE
int Decode_NATIVE_PusPacketDataLength(asn1SccPusPacketDataLength *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusVersionNumber_UPER
int Encode_UPER_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusVersionNumber *pSrc);
#endif

#ifdef __NEED_PusVersionNumber_ACN
int Encode_ACN_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, asn1SccPusVersionNumber *pSrc);
#endif

#ifdef __NEED_PusVersionNumber_NATIVE
int Encode_NATIVE_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusVersionNumber *pSrc);
#endif

#ifdef __NEED_PusVersionNumber_UPER
int Decode_UPER_PusVersionNumber(asn1SccPusVersionNumber *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusVersionNumber_ACN
int Decode_ACN_PusVersionNumber(asn1SccPusVersionNumber *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusVersionNumber_NATIVE
int Decode_NATIVE_PusVersionNumber(asn1SccPusVersionNumber *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTimeReferenceStatus_UPER
int Encode_UPER_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTimeReferenceStatus *pSrc);
#endif

#ifdef __NEED_PusTimeReferenceStatus_ACN
int Encode_ACN_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTimeReferenceStatus *pSrc);
#endif

#ifdef __NEED_PusTimeReferenceStatus_NATIVE
int Encode_NATIVE_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTimeReferenceStatus *pSrc);
#endif

#ifdef __NEED_PusTimeReferenceStatus_UPER
int Decode_UPER_PusTimeReferenceStatus(asn1SccPusTimeReferenceStatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTimeReferenceStatus_ACN
int Decode_ACN_PusTimeReferenceStatus(asn1SccPusTimeReferenceStatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTimeReferenceStatus_NATIVE
int Decode_NATIVE_PusTimeReferenceStatus(asn1SccPusTimeReferenceStatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusMessageTypeCounter_UPER
int Encode_UPER_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMessageTypeCounter *pSrc);
#endif

#ifdef __NEED_PusMessageTypeCounter_ACN
int Encode_ACN_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, asn1SccPusMessageTypeCounter *pSrc);
#endif

#ifdef __NEED_PusMessageTypeCounter_NATIVE
int Encode_NATIVE_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMessageTypeCounter *pSrc);
#endif

#ifdef __NEED_PusMessageTypeCounter_UPER
int Decode_UPER_PusMessageTypeCounter(asn1SccPusMessageTypeCounter *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusMessageTypeCounter_ACN
int Decode_ACN_PusMessageTypeCounter(asn1SccPusMessageTypeCounter *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusMessageTypeCounter_NATIVE
int Decode_NATIVE_PusMessageTypeCounter(asn1SccPusMessageTypeCounter *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusAcknowledgementFlags_UPER
int Encode_UPER_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusAcknowledgementFlags *pSrc);
#endif

#ifdef __NEED_PusAcknowledgementFlags_ACN
int Encode_ACN_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, asn1SccPusAcknowledgementFlags *pSrc);
#endif

#ifdef __NEED_PusAcknowledgementFlags_NATIVE
int Encode_NATIVE_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusAcknowledgementFlags *pSrc);
#endif

#ifdef __NEED_PusAcknowledgementFlags_UPER
int Decode_UPER_PusAcknowledgementFlags(asn1SccPusAcknowledgementFlags *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusAcknowledgementFlags_ACN
int Decode_ACN_PusAcknowledgementFlags(asn1SccPusAcknowledgementFlags *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusAcknowledgementFlags_NATIVE
int Decode_NATIVE_PusAcknowledgementFlags(asn1SccPusAcknowledgementFlags *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusChecksum_UPER
int Encode_UPER_PusChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusChecksum *pSrc);
#endif

#ifdef __NEED_PusChecksum_ACN
int Encode_ACN_PusChecksum(void *pBuffer, size_t iMaxBufferSize, asn1SccPusChecksum *pSrc);
#endif

#ifdef __NEED_PusChecksum_NATIVE
int Encode_NATIVE_PusChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusChecksum *pSrc);
#endif

#ifdef __NEED_PusChecksum_UPER
int Decode_UPER_PusChecksum(asn1SccPusChecksum *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusChecksum_ACN
int Decode_ACN_PusChecksum(asn1SccPusChecksum *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusChecksum_NATIVE
int Decode_NATIVE_PusChecksum(asn1SccPusChecksum *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusStepId_UPER
int Encode_UPER_PusStepId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusStepId *pSrc);
#endif

#ifdef __NEED_PusStepId_ACN
int Encode_ACN_PusStepId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusStepId *pSrc);
#endif

#ifdef __NEED_PusStepId_NATIVE
int Encode_NATIVE_PusStepId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusStepId *pSrc);
#endif

#ifdef __NEED_PusStepId_UPER
int Decode_UPER_PusStepId(asn1SccPusStepId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusStepId_ACN
int Decode_ACN_PusStepId(asn1SccPusStepId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusStepId_NATIVE
int Decode_NATIVE_PusStepId(asn1SccPusStepId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusConfigDummyType_UPER
int Encode_UPER_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusConfigDummyType *pSrc);
#endif

#ifdef __NEED_PusConfigDummyType_ACN
int Encode_ACN_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusConfigDummyType *pSrc);
#endif

#ifdef __NEED_PusConfigDummyType_NATIVE
int Encode_NATIVE_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusConfigDummyType *pSrc);
#endif

#ifdef __NEED_PusConfigDummyType_UPER
int Decode_UPER_PusConfigDummyType(asn1SccPusConfigDummyType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusConfigDummyType_ACN
int Decode_ACN_PusConfigDummyType(asn1SccPusConfigDummyType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusConfigDummyType_NATIVE
int Decode_NATIVE_PusConfigDummyType(asn1SccPusConfigDummyType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusServiceType_UPER
int Encode_UPER_PusServiceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusServiceType *pSrc);
#endif

#ifdef __NEED_PusServiceType_ACN
int Encode_ACN_PusServiceType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusServiceType *pSrc);
#endif

#ifdef __NEED_PusServiceType_NATIVE
int Encode_NATIVE_PusServiceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusServiceType *pSrc);
#endif

#ifdef __NEED_PusServiceType_UPER
int Decode_UPER_PusServiceType(asn1SccPusServiceType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusServiceType_ACN
int Decode_ACN_PusServiceType(asn1SccPusServiceType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusServiceType_NATIVE
int Decode_NATIVE_PusServiceType(asn1SccPusServiceType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSubserviceType_UPER
int Encode_UPER_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSubserviceType *pSrc);
#endif

#ifdef __NEED_PusSubserviceType_ACN
int Encode_ACN_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSubserviceType *pSrc);
#endif

#ifdef __NEED_PusSubserviceType_NATIVE
int Encode_NATIVE_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSubserviceType *pSrc);
#endif

#ifdef __NEED_PusSubserviceType_UPER
int Decode_UPER_PusSubserviceType(asn1SccPusSubserviceType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSubserviceType_ACN
int Decode_ACN_PusSubserviceType(asn1SccPusSubserviceType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSubserviceType_NATIVE
int Decode_NATIVE_PusSubserviceType(asn1SccPusSubserviceType *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01FailureCode_UPER
int Encode_UPER_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureCode *pSrc);
#endif

#ifdef __NEED_PusSt01FailureCode_ACN
int Encode_ACN_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01FailureCode *pSrc);
#endif

#ifdef __NEED_PusSt01FailureCode_NATIVE
int Encode_NATIVE_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureCode *pSrc);
#endif

#ifdef __NEED_PusSt01FailureCode_UPER
int Decode_UPER_PusSt01FailureCode(asn1SccPusSt01FailureCode *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01FailureCode_ACN
int Decode_ACN_PusSt01FailureCode(asn1SccPusSt01FailureCode *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01FailureCode_NATIVE
int Decode_NATIVE_PusSt01FailureCode(asn1SccPusSt01FailureCode *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01FailureInfo_UPER
int Encode_UPER_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureInfo *pSrc);
#endif

#ifdef __NEED_PusSt01FailureInfo_ACN
int Encode_ACN_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01FailureInfo *pSrc);
#endif

#ifdef __NEED_PusSt01FailureInfo_NATIVE
int Encode_NATIVE_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureInfo *pSrc);
#endif

#ifdef __NEED_PusSt01FailureInfo_UPER
int Decode_UPER_PusSt01FailureInfo(asn1SccPusSt01FailureInfo *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01FailureInfo_ACN
int Decode_ACN_PusSt01FailureInfo(asn1SccPusSt01FailureInfo *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01FailureInfo_NATIVE
int Decode_NATIVE_PusSt01FailureInfo(asn1SccPusSt01FailureInfo *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01RequestId_UPER
int Encode_UPER_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01RequestId *pSrc);
#endif

#ifdef __NEED_PusSt01RequestId_ACN
int Encode_ACN_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01RequestId *pSrc);
#endif

#ifdef __NEED_PusSt01RequestId_NATIVE
int Encode_NATIVE_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01RequestId *pSrc);
#endif

#ifdef __NEED_PusSt01RequestId_UPER
int Decode_UPER_PusSt01RequestId(asn1SccPusSt01RequestId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01RequestId_ACN
int Decode_ACN_PusSt01RequestId(asn1SccPusSt01RequestId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01RequestId_NATIVE
int Decode_NATIVE_PusSt01RequestId(asn1SccPusSt01RequestId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01Failure_UPER
int Encode_UPER_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01Failure *pSrc);
#endif

#ifdef __NEED_PusSt01Failure_ACN
int Encode_ACN_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01Failure *pSrc);
#endif

#ifdef __NEED_PusSt01Failure_NATIVE
int Encode_NATIVE_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01Failure *pSrc);
#endif

#ifdef __NEED_PusSt01Failure_UPER
int Decode_UPER_PusSt01Failure(asn1SccPusSt01Failure *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01Failure_ACN
int Decode_ACN_PusSt01Failure(asn1SccPusSt01Failure *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt01Failure_NATIVE
int Decode_NATIVE_PusSt01Failure(asn1SccPusSt01Failure *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_1_X_Data_UPER
int Encode_UPER_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_1_X_Data *pSrc);
#endif

#ifdef __NEED_PusTM_1_X_Data_ACN
int Encode_ACN_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_1_X_Data *pSrc);
#endif

#ifdef __NEED_PusTM_1_X_Data_NATIVE
int Encode_NATIVE_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_1_X_Data *pSrc);
#endif

#ifdef __NEED_PusTM_1_X_Data_UPER
int Decode_UPER_PusTM_1_X_Data(asn1SccPusTM_1_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_1_X_Data_ACN
int Decode_ACN_PusTM_1_X_Data(asn1SccPusTM_1_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_1_X_Data_NATIVE
int Decode_NATIVE_PusTM_1_X_Data(asn1SccPusTM_1_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03StoredParam_UPER
int Encode_UPER_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03StoredParam *pSrc);
#endif

#ifdef __NEED_PusSt03StoredParam_ACN
int Encode_ACN_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03StoredParam *pSrc);
#endif

#ifdef __NEED_PusSt03StoredParam_NATIVE
int Encode_NATIVE_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03StoredParam *pSrc);
#endif

#ifdef __NEED_PusSt03StoredParam_UPER
int Decode_UPER_PusSt03StoredParam(asn1SccPusSt03StoredParam *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03StoredParam_ACN
int Decode_ACN_PusSt03StoredParam(asn1SccPusSt03StoredParam *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03StoredParam_NATIVE
int Decode_NATIVE_PusSt03StoredParam(asn1SccPusSt03StoredParam *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_UPER
int Encode_UPER_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03HousekeepingReportId *pSrc);
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_ACN
int Encode_ACN_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03HousekeepingReportId *pSrc);
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_NATIVE
int Encode_NATIVE_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03HousekeepingReportId *pSrc);
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_UPER
int Decode_UPER_PusSt03HousekeepingReportId(asn1SccPusSt03HousekeepingReportId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_ACN
int Decode_ACN_PusSt03HousekeepingReportId(asn1SccPusSt03HousekeepingReportId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_NATIVE
int Decode_NATIVE_PusSt03HousekeepingReportId(asn1SccPusSt03HousekeepingReportId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03ParameterId_UPER
int Encode_UPER_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterId *pSrc);
#endif

#ifdef __NEED_PusSt03ParameterId_ACN
int Encode_ACN_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03ParameterId *pSrc);
#endif

#ifdef __NEED_PusSt03ParameterId_NATIVE
int Encode_NATIVE_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterId *pSrc);
#endif

#ifdef __NEED_PusSt03ParameterId_UPER
int Decode_UPER_PusSt03ParameterId(asn1SccPusSt03ParameterId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03ParameterId_ACN
int Decode_ACN_PusSt03ParameterId(asn1SccPusSt03ParameterId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03ParameterId_NATIVE
int Decode_NATIVE_PusSt03ParameterId(asn1SccPusSt03ParameterId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03ParameterArray_UPER
int Encode_UPER_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterArray *pSrc);
#endif

#ifdef __NEED_PusSt03ParameterArray_ACN
int Encode_ACN_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03ParameterArray *pSrc);
#endif

#ifdef __NEED_PusSt03ParameterArray_NATIVE
int Encode_NATIVE_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterArray *pSrc);
#endif

#ifdef __NEED_PusSt03ParameterArray_UPER
int Decode_UPER_PusSt03ParameterArray(asn1SccPusSt03ParameterArray *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03ParameterArray_ACN
int Decode_ACN_PusSt03ParameterArray(asn1SccPusSt03ParameterArray *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt03ParameterArray_NATIVE
int Decode_NATIVE_PusSt03ParameterArray(asn1SccPusSt03ParameterArray *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_3_25_Data_UPER
int Encode_UPER_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_3_25_Data *pSrc);
#endif

#ifdef __NEED_PusTM_3_25_Data_ACN
int Encode_ACN_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_3_25_Data *pSrc);
#endif

#ifdef __NEED_PusTM_3_25_Data_NATIVE
int Encode_NATIVE_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_3_25_Data *pSrc);
#endif

#ifdef __NEED_PusTM_3_25_Data_UPER
int Decode_UPER_PusTM_3_25_Data(asn1SccPusTM_3_25_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_3_25_Data_ACN
int Decode_ACN_PusTM_3_25_Data(asn1SccPusTM_3_25_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_3_25_Data_NATIVE
int Decode_NATIVE_PusTM_3_25_Data(asn1SccPusTM_3_25_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt05EventId_UPER
int Encode_UPER_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventId *pSrc);
#endif

#ifdef __NEED_PusSt05EventId_ACN
int Encode_ACN_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05EventId *pSrc);
#endif

#ifdef __NEED_PusSt05EventId_NATIVE
int Encode_NATIVE_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventId *pSrc);
#endif

#ifdef __NEED_PusSt05EventId_UPER
int Decode_UPER_PusSt05EventId(asn1SccPusSt05EventId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt05EventId_ACN
int Decode_ACN_PusSt05EventId(asn1SccPusSt05EventId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt05EventId_NATIVE
int Decode_NATIVE_PusSt05EventId(asn1SccPusSt05EventId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt05EventAuxData_UPER
int Encode_UPER_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventAuxData *pSrc);
#endif

#ifdef __NEED_PusSt05EventAuxData_ACN
int Encode_ACN_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05EventAuxData *pSrc);
#endif

#ifdef __NEED_PusSt05EventAuxData_NATIVE
int Encode_NATIVE_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventAuxData *pSrc);
#endif

#ifdef __NEED_PusSt05EventAuxData_UPER
int Decode_UPER_PusSt05EventAuxData(asn1SccPusSt05EventAuxData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt05EventAuxData_ACN
int Decode_ACN_PusSt05EventAuxData(asn1SccPusSt05EventAuxData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt05EventAuxData_NATIVE
int Decode_NATIVE_PusSt05EventAuxData(asn1SccPusSt05EventAuxData *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt05Event_UPER
int Encode_UPER_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05Event *pSrc);
#endif

#ifdef __NEED_PusSt05Event_ACN
int Encode_ACN_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05Event *pSrc);
#endif

#ifdef __NEED_PusSt05Event_NATIVE
int Encode_NATIVE_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05Event *pSrc);
#endif

#ifdef __NEED_PusSt05Event_UPER
int Decode_UPER_PusSt05Event(asn1SccPusSt05Event *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt05Event_ACN
int Decode_ACN_PusSt05Event(asn1SccPusSt05Event *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt05Event_NATIVE
int Decode_NATIVE_PusSt05Event(asn1SccPusSt05Event *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_5_X_Data_UPER
int Encode_UPER_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_5_X_Data *pSrc);
#endif

#ifdef __NEED_PusTM_5_X_Data_ACN
int Encode_ACN_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_5_X_Data *pSrc);
#endif

#ifdef __NEED_PusTM_5_X_Data_NATIVE
int Encode_NATIVE_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_5_X_Data *pSrc);
#endif

#ifdef __NEED_PusTM_5_X_Data_UPER
int Decode_UPER_PusTM_5_X_Data(asn1SccPusTM_5_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_5_X_Data_ACN
int Decode_ACN_PusTM_5_X_Data(asn1SccPusTM_5_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_5_X_Data_NATIVE
int Decode_NATIVE_PusTM_5_X_Data(asn1SccPusTM_5_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt08FunctionId_UPER
int Encode_UPER_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt08FunctionId *pSrc);
#endif

#ifdef __NEED_PusSt08FunctionId_ACN
int Encode_ACN_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt08FunctionId *pSrc);
#endif

#ifdef __NEED_PusSt08FunctionId_NATIVE
int Encode_NATIVE_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt08FunctionId *pSrc);
#endif

#ifdef __NEED_PusSt08FunctionId_UPER
int Decode_UPER_PusSt08FunctionId(asn1SccPusSt08FunctionId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt08FunctionId_ACN
int Decode_ACN_PusSt08FunctionId(asn1SccPusSt08FunctionId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt08FunctionId_NATIVE
int Decode_NATIVE_PusSt08FunctionId(asn1SccPusSt08FunctionId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_8_1_Data_UPER
int Encode_UPER_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_8_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_8_1_Data_ACN
int Encode_ACN_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_8_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_8_1_Data_NATIVE
int Encode_NATIVE_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_8_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_8_1_Data_UPER
int Decode_UPER_PusTC_8_1_Data(asn1SccPusTC_8_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_8_1_Data_ACN
int Decode_ACN_PusTC_8_1_Data(asn1SccPusTC_8_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_8_1_Data_NATIVE
int Decode_NATIVE_PusTC_8_1_Data(asn1SccPusTC_8_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt09ExponentialRate_UPER
int Encode_UPER_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt09ExponentialRate *pSrc);
#endif

#ifdef __NEED_PusSt09ExponentialRate_ACN
int Encode_ACN_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt09ExponentialRate *pSrc);
#endif

#ifdef __NEED_PusSt09ExponentialRate_NATIVE
int Encode_NATIVE_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt09ExponentialRate *pSrc);
#endif

#ifdef __NEED_PusSt09ExponentialRate_UPER
int Decode_UPER_PusSt09ExponentialRate(asn1SccPusSt09ExponentialRate *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt09ExponentialRate_ACN
int Decode_ACN_PusSt09ExponentialRate(asn1SccPusSt09ExponentialRate *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt09ExponentialRate_NATIVE
int Decode_NATIVE_PusSt09ExponentialRate(asn1SccPusSt09ExponentialRate *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_9_1_Data_UPER
int Encode_UPER_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_9_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_9_1_Data_ACN
int Encode_ACN_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_9_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_9_1_Data_NATIVE
int Encode_NATIVE_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_9_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_9_1_Data_UPER
int Decode_UPER_PusTC_9_1_Data(asn1SccPusTC_9_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_9_1_Data_ACN
int Decode_ACN_PusTC_9_1_Data(asn1SccPusTC_9_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_9_1_Data_NATIVE
int Decode_NATIVE_PusTC_9_1_Data(asn1SccPusTC_9_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_9_2_Data_UPER
int Encode_UPER_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_9_2_Data *pSrc);
#endif

#ifdef __NEED_PusTM_9_2_Data_ACN
int Encode_ACN_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_9_2_Data *pSrc);
#endif

#ifdef __NEED_PusTM_9_2_Data_NATIVE
int Encode_NATIVE_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_9_2_Data *pSrc);
#endif

#ifdef __NEED_PusTM_9_2_Data_UPER
int Decode_UPER_PusTM_9_2_Data(asn1SccPusTM_9_2_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_9_2_Data_ACN
int Decode_ACN_PusTM_9_2_Data(asn1SccPusTM_9_2_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_9_2_Data_NATIVE
int Decode_NATIVE_PusTM_9_2_Data(asn1SccPusTM_9_2_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt12pmonId_UPER
int Encode_UPER_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt12pmonId *pSrc);
#endif

#ifdef __NEED_PusSt12pmonId_ACN
int Encode_ACN_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt12pmonId *pSrc);
#endif

#ifdef __NEED_PusSt12pmonId_NATIVE
int Encode_NATIVE_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt12pmonId *pSrc);
#endif

#ifdef __NEED_PusSt12pmonId_UPER
int Decode_UPER_PusSt12pmonId(asn1SccPusSt12pmonId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt12pmonId_ACN
int Decode_ACN_PusSt12pmonId(asn1SccPusSt12pmonId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt12pmonId_NATIVE
int Decode_NATIVE_PusSt12pmonId(asn1SccPusSt12pmonId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_12_1_2_Data_UPER
int Encode_UPER_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_12_1_2_Data *pSrc);
#endif

#ifdef __NEED_PusTC_12_1_2_Data_ACN
int Encode_ACN_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_12_1_2_Data *pSrc);
#endif

#ifdef __NEED_PusTC_12_1_2_Data_NATIVE
int Encode_NATIVE_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_12_1_2_Data *pSrc);
#endif

#ifdef __NEED_PusTC_12_1_2_Data_UPER
int Decode_UPER_PusTC_12_1_2_Data(asn1SccPusTC_12_1_2_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_12_1_2_Data_ACN
int Decode_ACN_PusTC_12_1_2_Data(asn1SccPusTC_12_1_2_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_12_1_2_Data_NATIVE
int Decode_NATIVE_PusTC_12_1_2_Data(asn1SccPusTC_12_1_2_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObcpId_UPER
int Encode_UPER_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpId *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpId_ACN
int Encode_ACN_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpId *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpId_NATIVE
int Encode_NATIVE_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpId *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpId_UPER
int Decode_UPER_PusSt18ObcpId(asn1SccPusSt18ObcpId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObcpId_ACN
int Decode_ACN_PusSt18ObcpId(asn1SccPusSt18ObcpId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObcpId_NATIVE
int Decode_NATIVE_PusSt18ObcpId(asn1SccPusSt18ObcpId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObcpCode_UPER
int Encode_UPER_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpCode *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpCode_ACN
int Encode_ACN_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpCode *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpCode_NATIVE
int Encode_NATIVE_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpCode *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpCode_UPER
int Decode_UPER_PusSt18ObcpCode(asn1SccPusSt18ObcpCode *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObcpCode_ACN
int Decode_ACN_PusSt18ObcpCode(asn1SccPusSt18ObcpCode *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObcpCode_NATIVE
int Decode_NATIVE_PusSt18ObcpCode(asn1SccPusSt18ObcpCode *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObcpChecksum_UPER
int Encode_UPER_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpChecksum *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpChecksum_ACN
int Encode_ACN_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpChecksum *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpChecksum_NATIVE
int Encode_NATIVE_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpChecksum *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpChecksum_UPER
int Decode_UPER_PusSt18ObcpChecksum(asn1SccPusSt18ObcpChecksum *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObcpChecksum_ACN
int Decode_ACN_PusSt18ObcpChecksum(asn1SccPusSt18ObcpChecksum *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObcpChecksum_NATIVE
int Decode_NATIVE_PusSt18ObcpChecksum(asn1SccPusSt18ObcpChecksum *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_UPER
int Encode_UPER_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObservabilityLevel *pSrc);
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_ACN
int Encode_ACN_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObservabilityLevel *pSrc);
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_NATIVE
int Encode_NATIVE_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObservabilityLevel *pSrc);
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_UPER
int Decode_UPER_PusSt18ObservabilityLevel(asn1SccPusSt18ObservabilityLevel *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_ACN
int Decode_ACN_PusSt18ObservabilityLevel(asn1SccPusSt18ObservabilityLevel *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_NATIVE
int Decode_NATIVE_PusSt18ObservabilityLevel(asn1SccPusSt18ObservabilityLevel *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_1_Data_UPER
int Encode_UPER_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_1_Data_ACN
int Encode_ACN_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_1_Data_NATIVE
int Encode_NATIVE_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_1_Data_UPER
int Decode_UPER_PusTC_18_1_Data(asn1SccPusTC_18_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_1_Data_ACN
int Decode_ACN_PusTC_18_1_Data(asn1SccPusTC_18_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_1_Data_NATIVE
int Decode_NATIVE_PusTC_18_1_Data(asn1SccPusTC_18_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_UPER
int Encode_UPER_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_2_6_12_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_ACN
int Encode_ACN_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_2_6_12_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_NATIVE
int Encode_NATIVE_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_2_6_12_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_UPER
int Decode_UPER_PusTC_18_2_6_12_Data(asn1SccPusTC_18_2_6_12_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_ACN
int Decode_ACN_PusTC_18_2_6_12_Data(asn1SccPusTC_18_2_6_12_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_NATIVE
int Decode_NATIVE_PusTC_18_2_6_12_Data(asn1SccPusTC_18_2_6_12_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_3_Data_UPER
int Encode_UPER_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_3_Data_ACN
int Encode_ACN_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_3_Data_NATIVE
int Encode_NATIVE_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_3_Data_UPER
int Decode_UPER_PusTC_18_3_Data(asn1SccPusTC_18_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_3_Data_ACN
int Decode_ACN_PusTC_18_3_Data(asn1SccPusTC_18_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_3_Data_NATIVE
int Decode_NATIVE_PusTC_18_3_Data(asn1SccPusTC_18_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_4_5_Data_UPER
int Encode_UPER_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_4_5_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_4_5_Data_ACN
int Encode_ACN_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_4_5_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_4_5_Data_NATIVE
int Encode_NATIVE_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_4_5_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_4_5_Data_UPER
int Decode_UPER_PusTC_18_4_5_Data(asn1SccPusTC_18_4_5_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_4_5_Data_ACN
int Decode_ACN_PusTC_18_4_5_Data(asn1SccPusTC_18_4_5_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_4_5_Data_NATIVE
int Decode_NATIVE_PusTC_18_4_5_Data(asn1SccPusTC_18_4_5_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_13_Data_UPER
int Encode_UPER_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_13_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_13_Data_ACN
int Encode_ACN_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_13_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_13_Data_NATIVE
int Encode_NATIVE_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_13_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_13_Data_UPER
int Decode_UPER_PusTC_18_13_Data(asn1SccPusTC_18_13_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_13_Data_ACN
int Decode_ACN_PusTC_18_13_Data(asn1SccPusTC_18_13_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_18_13_Data_NATIVE
int Decode_NATIVE_PusTC_18_13_Data(asn1SccPusTC_18_13_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_19_X_Data_UPER
int Encode_UPER_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_X_Data *pSrc);
#endif

#ifdef __NEED_PusTC_19_X_Data_ACN
int Encode_ACN_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_19_X_Data *pSrc);
#endif

#ifdef __NEED_PusTC_19_X_Data_NATIVE
int Encode_NATIVE_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_X_Data *pSrc);
#endif

#ifdef __NEED_PusTC_19_X_Data_UPER
int Decode_UPER_PusTC_19_X_Data(asn1SccPusTC_19_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_19_X_Data_ACN
int Decode_ACN_PusTC_19_X_Data(asn1SccPusTC_19_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_19_X_Data_NATIVE
int Decode_NATIVE_PusTC_19_X_Data(asn1SccPusTC_19_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_UPER
int Encode_UPER_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20OnBoardParameterId *pSrc);
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_ACN
int Encode_ACN_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt20OnBoardParameterId *pSrc);
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_NATIVE
int Encode_NATIVE_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20OnBoardParameterId *pSrc);
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_UPER
int Decode_UPER_PusSt20OnBoardParameterId(asn1SccPusSt20OnBoardParameterId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_ACN
int Decode_ACN_PusSt20OnBoardParameterId(asn1SccPusSt20OnBoardParameterId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_NATIVE
int Decode_NATIVE_PusSt20OnBoardParameterId(asn1SccPusSt20OnBoardParameterId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt20StoredParam_UPER
int Encode_UPER_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20StoredParam *pSrc);
#endif

#ifdef __NEED_PusSt20StoredParam_ACN
int Encode_ACN_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt20StoredParam *pSrc);
#endif

#ifdef __NEED_PusSt20StoredParam_NATIVE
int Encode_NATIVE_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20StoredParam *pSrc);
#endif

#ifdef __NEED_PusSt20StoredParam_UPER
int Decode_UPER_PusSt20StoredParam(asn1SccPusSt20StoredParam *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt20StoredParam_ACN
int Decode_ACN_PusSt20StoredParam(asn1SccPusSt20StoredParam *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt20StoredParam_NATIVE
int Decode_NATIVE_PusSt20StoredParam(asn1SccPusSt20StoredParam *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_UPER
int Encode_UPER_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_20_X_Data *pSrc);
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_ACN
int Encode_ACN_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_TM_20_X_Data *pSrc);
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_NATIVE
int Encode_NATIVE_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_20_X_Data *pSrc);
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_UPER
int Decode_UPER_PusTC_TM_20_X_Data(asn1SccPusTC_TM_20_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_ACN
int Decode_ACN_PusTC_TM_20_X_Data(asn1SccPusTC_TM_20_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_NATIVE
int Decode_NATIVE_PusTC_TM_20_X_Data(asn1SccPusTC_TM_20_X_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_2_Data_UPER
int Encode_UPER_PusTM_200_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_2_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_2_Data_ACN
int Encode_ACN_PusTM_200_2_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_2_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_2_Data_NATIVE
int Encode_NATIVE_PusTM_200_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_2_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_2_Data_UPER
int Decode_UPER_PusTM_200_2_Data(asn1SccPusTM_200_2_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_2_Data_ACN
int Decode_ACN_PusTM_200_2_Data(asn1SccPusTM_200_2_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_2_Data_NATIVE
int Decode_NATIVE_PusTM_200_2_Data(asn1SccPusTM_200_2_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_3_Data_UPER
int Encode_UPER_PusTC_200_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_3_Data_ACN
int Encode_ACN_PusTC_200_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_200_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_3_Data_NATIVE
int Encode_NATIVE_PusTC_200_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_3_Data_UPER
int Decode_UPER_PusTC_200_3_Data(asn1SccPusTC_200_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_3_Data_ACN
int Decode_ACN_PusTC_200_3_Data(asn1SccPusTC_200_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_3_Data_NATIVE
int Decode_NATIVE_PusTC_200_3_Data(asn1SccPusTC_200_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_4_Data_UPER
int Encode_UPER_PusTM_200_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_4_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_4_Data_ACN
int Encode_ACN_PusTM_200_4_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_4_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_4_Data_NATIVE
int Encode_NATIVE_PusTM_200_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_4_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_4_Data_UPER
int Decode_UPER_PusTM_200_4_Data(asn1SccPusTM_200_4_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_4_Data_ACN
int Decode_ACN_PusTM_200_4_Data(asn1SccPusTM_200_4_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_4_Data_NATIVE
int Decode_NATIVE_PusTM_200_4_Data(asn1SccPusTM_200_4_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_5_Data_UPER
int Encode_UPER_PusTC_200_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_5_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_5_Data_ACN
int Encode_ACN_PusTC_200_5_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_200_5_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_5_Data_NATIVE
int Encode_NATIVE_PusTC_200_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_5_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_5_Data_UPER
int Decode_UPER_PusTC_200_5_Data(asn1SccPusTC_200_5_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_5_Data_ACN
int Decode_ACN_PusTC_200_5_Data(asn1SccPusTC_200_5_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_5_Data_NATIVE
int Decode_NATIVE_PusTC_200_5_Data(asn1SccPusTC_200_5_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_6_Data_UPER
int Encode_UPER_PusTM_200_6_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_6_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_6_Data_ACN
int Encode_ACN_PusTM_200_6_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_6_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_6_Data_NATIVE
int Encode_NATIVE_PusTM_200_6_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_6_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_6_Data_UPER
int Decode_UPER_PusTM_200_6_Data(asn1SccPusTM_200_6_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_6_Data_ACN
int Decode_ACN_PusTM_200_6_Data(asn1SccPusTM_200_6_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_6_Data_NATIVE
int Decode_NATIVE_PusTM_200_6_Data(asn1SccPusTM_200_6_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_8_Data_UPER
int Encode_UPER_PusTM_200_8_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_8_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_8_Data_ACN
int Encode_ACN_PusTM_200_8_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_8_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_8_Data_NATIVE
int Encode_NATIVE_PusTM_200_8_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_8_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_8_Data_UPER
int Decode_UPER_PusTM_200_8_Data(asn1SccPusTM_200_8_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_8_Data_ACN
int Decode_ACN_PusTM_200_8_Data(asn1SccPusTM_200_8_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_8_Data_NATIVE
int Decode_NATIVE_PusTM_200_8_Data(asn1SccPusTM_200_8_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_9_Data_UPER
int Encode_UPER_PusTC_200_9_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_9_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_9_Data_ACN
int Encode_ACN_PusTC_200_9_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_200_9_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_9_Data_NATIVE
int Encode_NATIVE_PusTC_200_9_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_9_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_9_Data_UPER
int Decode_UPER_PusTC_200_9_Data(asn1SccPusTC_200_9_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_9_Data_ACN
int Decode_ACN_PusTC_200_9_Data(asn1SccPusTC_200_9_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_9_Data_NATIVE
int Decode_NATIVE_PusTC_200_9_Data(asn1SccPusTC_200_9_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_10_Data_UPER
int Encode_UPER_PusTM_200_10_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_10_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_10_Data_ACN
int Encode_ACN_PusTM_200_10_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_10_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_10_Data_NATIVE
int Encode_NATIVE_PusTM_200_10_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_10_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_10_Data_UPER
int Decode_UPER_PusTM_200_10_Data(asn1SccPusTM_200_10_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_10_Data_ACN
int Decode_ACN_PusTM_200_10_Data(asn1SccPusTM_200_10_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_10_Data_NATIVE
int Decode_NATIVE_PusTM_200_10_Data(asn1SccPusTM_200_10_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_11_Data_UPER
int Encode_UPER_PusTC_200_11_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_11_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_11_Data_ACN
int Encode_ACN_PusTC_200_11_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_200_11_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_11_Data_NATIVE
int Encode_NATIVE_PusTC_200_11_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_11_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_11_Data_UPER
int Decode_UPER_PusTC_200_11_Data(asn1SccPusTC_200_11_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_11_Data_ACN
int Decode_ACN_PusTC_200_11_Data(asn1SccPusTC_200_11_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_11_Data_NATIVE
int Decode_NATIVE_PusTC_200_11_Data(asn1SccPusTC_200_11_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_12_Data_UPER
int Encode_UPER_PusTM_200_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_12_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_12_Data_ACN
int Encode_ACN_PusTM_200_12_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_12_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_12_Data_NATIVE
int Encode_NATIVE_PusTM_200_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_12_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_12_Data_UPER
int Decode_UPER_PusTM_200_12_Data(asn1SccPusTM_200_12_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_12_Data_ACN
int Decode_ACN_PusTM_200_12_Data(asn1SccPusTM_200_12_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_12_Data_NATIVE
int Decode_NATIVE_PusTM_200_12_Data(asn1SccPusTM_200_12_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_13_Data_UPER
int Encode_UPER_PusTC_200_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_13_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_13_Data_ACN
int Encode_ACN_PusTC_200_13_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_200_13_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_13_Data_NATIVE
int Encode_NATIVE_PusTC_200_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_200_13_Data *pSrc);
#endif

#ifdef __NEED_PusTC_200_13_Data_UPER
int Decode_UPER_PusTC_200_13_Data(asn1SccPusTC_200_13_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_13_Data_ACN
int Decode_ACN_PusTC_200_13_Data(asn1SccPusTC_200_13_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_200_13_Data_NATIVE
int Decode_NATIVE_PusTC_200_13_Data(asn1SccPusTC_200_13_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_14_Data_UPER
int Encode_UPER_PusTM_200_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_14_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_14_Data_ACN
int Encode_ACN_PusTM_200_14_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_200_14_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_14_Data_NATIVE
int Encode_NATIVE_PusTM_200_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_200_14_Data *pSrc);
#endif

#ifdef __NEED_PusTM_200_14_Data_UPER
int Decode_UPER_PusTM_200_14_Data(asn1SccPusTM_200_14_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_14_Data_ACN
int Decode_ACN_PusTM_200_14_Data(asn1SccPusTM_200_14_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_200_14_Data_NATIVE
int Decode_NATIVE_PusTM_200_14_Data(asn1SccPusTM_200_14_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_IntegerIntervalDomain_UPER
int Encode_UPER_IntegerIntervalDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccIntegerIntervalDomain *pSrc);
#endif

#ifdef __NEED_IntegerIntervalDomain_ACN
int Encode_ACN_IntegerIntervalDomain(void *pBuffer, size_t iMaxBufferSize, asn1SccIntegerIntervalDomain *pSrc);
#endif

#ifdef __NEED_IntegerIntervalDomain_NATIVE
int Encode_NATIVE_IntegerIntervalDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccIntegerIntervalDomain *pSrc);
#endif

#ifdef __NEED_IntegerIntervalDomain_UPER
int Decode_UPER_IntegerIntervalDomain(asn1SccIntegerIntervalDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_IntegerIntervalDomain_ACN
int Decode_ACN_IntegerIntervalDomain(asn1SccIntegerIntervalDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_IntegerIntervalDomain_NATIVE
int Decode_NATIVE_IntegerIntervalDomain(asn1SccIntegerIntervalDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FloatIntervalDomain_UPER
int Encode_UPER_FloatIntervalDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccFloatIntervalDomain *pSrc);
#endif

#ifdef __NEED_FloatIntervalDomain_ACN
int Encode_ACN_FloatIntervalDomain(void *pBuffer, size_t iMaxBufferSize, asn1SccFloatIntervalDomain *pSrc);
#endif

#ifdef __NEED_FloatIntervalDomain_NATIVE
int Encode_NATIVE_FloatIntervalDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccFloatIntervalDomain *pSrc);
#endif

#ifdef __NEED_FloatIntervalDomain_UPER
int Decode_UPER_FloatIntervalDomain(asn1SccFloatIntervalDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FloatIntervalDomain_ACN
int Decode_ACN_FloatIntervalDomain(asn1SccFloatIntervalDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_FloatIntervalDomain_NATIVE
int Decode_NATIVE_FloatIntervalDomain(asn1SccFloatIntervalDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EnumDomain_UPER
int Encode_UPER_EnumDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccEnumDomain *pSrc);
#endif

#ifdef __NEED_EnumDomain_ACN
int Encode_ACN_EnumDomain(void *pBuffer, size_t iMaxBufferSize, asn1SccEnumDomain *pSrc);
#endif

#ifdef __NEED_EnumDomain_NATIVE
int Encode_NATIVE_EnumDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccEnumDomain *pSrc);
#endif

#ifdef __NEED_EnumDomain_UPER
int Decode_UPER_EnumDomain(asn1SccEnumDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EnumDomain_ACN
int Decode_ACN_EnumDomain(asn1SccEnumDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EnumDomain_NATIVE
int Decode_NATIVE_EnumDomain(asn1SccEnumDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HotdockcmdPred_UPER
int Encode_UPER_HotdockcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockcmdPred *pSrc);
#endif

#ifdef __NEED_HotdockcmdPred_ACN
int Encode_ACN_HotdockcmdPred(void *pBuffer, size_t iMaxBufferSize, asn1SccHotdockcmdPred *pSrc);
#endif

#ifdef __NEED_HotdockcmdPred_NATIVE
int Encode_NATIVE_HotdockcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockcmdPred *pSrc);
#endif

#ifdef __NEED_HotdockcmdPred_UPER
int Decode_UPER_HotdockcmdPred(asn1SccHotdockcmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HotdockcmdPred_ACN
int Decode_ACN_HotdockcmdPred(asn1SccHotdockcmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HotdockcmdPred_NATIVE
int Decode_NATIVE_HotdockcmdPred(asn1SccHotdockcmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HotdockstatusPred_UPER
int Encode_UPER_HotdockstatusPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockstatusPred *pSrc);
#endif

#ifdef __NEED_HotdockstatusPred_ACN
int Encode_ACN_HotdockstatusPred(void *pBuffer, size_t iMaxBufferSize, asn1SccHotdockstatusPred *pSrc);
#endif

#ifdef __NEED_HotdockstatusPred_NATIVE
int Encode_NATIVE_HotdockstatusPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockstatusPred *pSrc);
#endif

#ifdef __NEED_HotdockstatusPred_UPER
int Decode_UPER_HotdockstatusPred(asn1SccHotdockstatusPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HotdockstatusPred_ACN
int Decode_ACN_HotdockstatusPred(asn1SccHotdockstatusPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_HotdockstatusPred_NATIVE
int Decode_NATIVE_HotdockstatusPred(asn1SccHotdockstatusPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_WmcmdPred_UPER
int Encode_UPER_WmcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccWmcmdPred *pSrc);
#endif

#ifdef __NEED_WmcmdPred_ACN
int Encode_ACN_WmcmdPred(void *pBuffer, size_t iMaxBufferSize, asn1SccWmcmdPred *pSrc);
#endif

#ifdef __NEED_WmcmdPred_NATIVE
int Encode_NATIVE_WmcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccWmcmdPred *pSrc);
#endif

#ifdef __NEED_WmcmdPred_UPER
int Decode_UPER_WmcmdPred(asn1SccWmcmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_WmcmdPred_ACN
int Decode_ACN_WmcmdPred(asn1SccWmcmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_WmcmdPred_NATIVE
int Decode_NATIVE_WmcmdPred(asn1SccWmcmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_BasecmdPred_UPER
int Encode_UPER_BasecmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccBasecmdPred *pSrc);
#endif

#ifdef __NEED_BasecmdPred_ACN
int Encode_ACN_BasecmdPred(void *pBuffer, size_t iMaxBufferSize, asn1SccBasecmdPred *pSrc);
#endif

#ifdef __NEED_BasecmdPred_NATIVE
int Encode_NATIVE_BasecmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccBasecmdPred *pSrc);
#endif

#ifdef __NEED_BasecmdPred_UPER
int Decode_UPER_BasecmdPred(asn1SccBasecmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_BasecmdPred_ACN
int Decode_ACN_BasecmdPred(asn1SccBasecmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_BasecmdPred_NATIVE
int Decode_NATIVE_BasecmdPred(asn1SccBasecmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EfcmdPred_UPER
int Encode_UPER_EfcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccEfcmdPred *pSrc);
#endif

#ifdef __NEED_EfcmdPred_ACN
int Encode_ACN_EfcmdPred(void *pBuffer, size_t iMaxBufferSize, asn1SccEfcmdPred *pSrc);
#endif

#ifdef __NEED_EfcmdPred_NATIVE
int Encode_NATIVE_EfcmdPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccEfcmdPred *pSrc);
#endif

#ifdef __NEED_EfcmdPred_UPER
int Decode_UPER_EfcmdPred(asn1SccEfcmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EfcmdPred_ACN
int Decode_ACN_EfcmdPred(asn1SccEfcmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_EfcmdPred_NATIVE
int Decode_NATIVE_EfcmdPred(asn1SccEfcmdPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PlannerPred_UPER
int Encode_UPER_PlannerPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccPlannerPred *pSrc);
#endif

#ifdef __NEED_PlannerPred_ACN
int Encode_ACN_PlannerPred(void *pBuffer, size_t iMaxBufferSize, asn1SccPlannerPred *pSrc);
#endif

#ifdef __NEED_PlannerPred_NATIVE
int Encode_NATIVE_PlannerPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccPlannerPred *pSrc);
#endif

#ifdef __NEED_PlannerPred_UPER
int Decode_UPER_PlannerPred(asn1SccPlannerPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PlannerPred_ACN
int Decode_ACN_PlannerPred(asn1SccPlannerPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PlannerPred_NATIVE
int Decode_NATIVE_PlannerPred(asn1SccPlannerPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MissionPred_UPER
int Encode_UPER_MissionPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccMissionPred *pSrc);
#endif

#ifdef __NEED_MissionPred_ACN
int Encode_ACN_MissionPred(void *pBuffer, size_t iMaxBufferSize, asn1SccMissionPred *pSrc);
#endif

#ifdef __NEED_MissionPred_NATIVE
int Encode_NATIVE_MissionPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccMissionPred *pSrc);
#endif

#ifdef __NEED_MissionPred_UPER
int Decode_UPER_MissionPred(asn1SccMissionPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MissionPred_ACN
int Decode_ACN_MissionPred(asn1SccMissionPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_MissionPred_NATIVE
int Decode_NATIVE_MissionPred(asn1SccMissionPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AutonomyPred_UPER
int Encode_UPER_AutonomyPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccAutonomyPred *pSrc);
#endif

#ifdef __NEED_AutonomyPred_ACN
int Encode_ACN_AutonomyPred(void *pBuffer, size_t iMaxBufferSize, asn1SccAutonomyPred *pSrc);
#endif

#ifdef __NEED_AutonomyPred_NATIVE
int Encode_NATIVE_AutonomyPred(void *pBuffer, size_t iMaxBufferSize, const asn1SccAutonomyPred *pSrc);
#endif

#ifdef __NEED_AutonomyPred_UPER
int Decode_UPER_AutonomyPred(asn1SccAutonomyPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AutonomyPred_ACN
int Decode_ACN_AutonomyPred(asn1SccAutonomyPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_AutonomyPred_NATIVE
int Decode_NATIVE_AutonomyPred(asn1SccAutonomyPred *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Boold_UPER
int Encode_UPER_Boold(void *pBuffer, size_t iMaxBufferSize, const asn1SccBoold *pSrc);
#endif

#ifdef __NEED_Boold_ACN
int Encode_ACN_Boold(void *pBuffer, size_t iMaxBufferSize, asn1SccBoold *pSrc);
#endif

#ifdef __NEED_Boold_NATIVE
int Encode_NATIVE_Boold(void *pBuffer, size_t iMaxBufferSize, const asn1SccBoold *pSrc);
#endif

#ifdef __NEED_Boold_UPER
int Decode_UPER_Boold(asn1SccBoold *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Boold_ACN
int Decode_ACN_Boold(asn1SccBoold *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Boold_NATIVE
int Decode_NATIVE_Boold(asn1SccBoold *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Intd_UPER
int Encode_UPER_Intd(void *pBuffer, size_t iMaxBufferSize, const asn1SccIntd *pSrc);
#endif

#ifdef __NEED_Intd_ACN
int Encode_ACN_Intd(void *pBuffer, size_t iMaxBufferSize, asn1SccIntd *pSrc);
#endif

#ifdef __NEED_Intd_NATIVE
int Encode_NATIVE_Intd(void *pBuffer, size_t iMaxBufferSize, const asn1SccIntd *pSrc);
#endif

#ifdef __NEED_Intd_UPER
int Decode_UPER_Intd(asn1SccIntd *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Intd_ACN
int Decode_ACN_Intd(asn1SccIntd *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Intd_NATIVE
int Decode_NATIVE_Intd(asn1SccIntd *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Floatd_UPER
int Encode_UPER_Floatd(void *pBuffer, size_t iMaxBufferSize, const asn1SccFloatd *pSrc);
#endif

#ifdef __NEED_Floatd_ACN
int Encode_ACN_Floatd(void *pBuffer, size_t iMaxBufferSize, asn1SccFloatd *pSrc);
#endif

#ifdef __NEED_Floatd_NATIVE
int Encode_NATIVE_Floatd(void *pBuffer, size_t iMaxBufferSize, const asn1SccFloatd *pSrc);
#endif

#ifdef __NEED_Floatd_UPER
int Decode_UPER_Floatd(asn1SccFloatd *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Floatd_ACN
int Decode_ACN_Floatd(asn1SccFloatd *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Floatd_NATIVE
int Decode_NATIVE_Floatd(asn1SccFloatd *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Stringd_UPER
int Encode_UPER_Stringd(void *pBuffer, size_t iMaxBufferSize, const asn1SccStringd *pSrc);
#endif

#ifdef __NEED_Stringd_ACN
int Encode_ACN_Stringd(void *pBuffer, size_t iMaxBufferSize, asn1SccStringd *pSrc);
#endif

#ifdef __NEED_Stringd_NATIVE
int Encode_NATIVE_Stringd(void *pBuffer, size_t iMaxBufferSize, const asn1SccStringd *pSrc);
#endif

#ifdef __NEED_Stringd_UPER
int Decode_UPER_Stringd(asn1SccStringd *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Stringd_ACN
int Decode_ACN_Stringd(asn1SccStringd *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Stringd_NATIVE
int Decode_NATIVE_Stringd(asn1SccStringd *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Int2d_UPER
int Encode_UPER_Int2d(void *pBuffer, size_t iMaxBufferSize, const asn1SccInt2d *pSrc);
#endif

#ifdef __NEED_Int2d_ACN
int Encode_ACN_Int2d(void *pBuffer, size_t iMaxBufferSize, asn1SccInt2d *pSrc);
#endif

#ifdef __NEED_Int2d_NATIVE
int Encode_NATIVE_Int2d(void *pBuffer, size_t iMaxBufferSize, const asn1SccInt2d *pSrc);
#endif

#ifdef __NEED_Int2d_UPER
int Decode_UPER_Int2d(asn1SccInt2d *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Int2d_ACN
int Decode_ACN_Int2d(asn1SccInt2d *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Int2d_NATIVE
int Decode_NATIVE_Int2d(asn1SccInt2d *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Slotid_UPER
int Encode_UPER_Slotid(void *pBuffer, size_t iMaxBufferSize, const asn1SccSlotid *pSrc);
#endif

#ifdef __NEED_Slotid_ACN
int Encode_ACN_Slotid(void *pBuffer, size_t iMaxBufferSize, asn1SccSlotid *pSrc);
#endif

#ifdef __NEED_Slotid_NATIVE
int Encode_NATIVE_Slotid(void *pBuffer, size_t iMaxBufferSize, const asn1SccSlotid *pSrc);
#endif

#ifdef __NEED_Slotid_UPER
int Decode_UPER_Slotid(asn1SccSlotid *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Slotid_ACN
int Decode_ACN_Slotid(asn1SccSlotid *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Slotid_NATIVE
int Decode_NATIVE_Slotid(asn1SccSlotid *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Position3D_UPER
int Encode_UPER_Position3D(void *pBuffer, size_t iMaxBufferSize, const asn1SccPosition3D *pSrc);
#endif

#ifdef __NEED_Position3D_ACN
int Encode_ACN_Position3D(void *pBuffer, size_t iMaxBufferSize, asn1SccPosition3D *pSrc);
#endif

#ifdef __NEED_Position3D_NATIVE
int Encode_NATIVE_Position3D(void *pBuffer, size_t iMaxBufferSize, const asn1SccPosition3D *pSrc);
#endif

#ifdef __NEED_Position3D_UPER
int Decode_UPER_Position3D(asn1SccPosition3D *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Position3D_ACN
int Decode_ACN_Position3D(asn1SccPosition3D *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Position3D_NATIVE
int Decode_NATIVE_Position3D(asn1SccPosition3D *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Quaterniond_UPER
int Encode_UPER_Quaterniond(void *pBuffer, size_t iMaxBufferSize, const asn1SccQuaterniond *pSrc);
#endif

#ifdef __NEED_Quaterniond_ACN
int Encode_ACN_Quaterniond(void *pBuffer, size_t iMaxBufferSize, asn1SccQuaterniond *pSrc);
#endif

#ifdef __NEED_Quaterniond_NATIVE
int Encode_NATIVE_Quaterniond(void *pBuffer, size_t iMaxBufferSize, const asn1SccQuaterniond *pSrc);
#endif

#ifdef __NEED_Quaterniond_UPER
int Decode_UPER_Quaterniond(asn1SccQuaterniond *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Quaterniond_ACN
int Decode_ACN_Quaterniond(asn1SccQuaterniond *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Quaterniond_NATIVE
int Decode_NATIVE_Quaterniond(asn1SccQuaterniond *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Hotdockcmdstatus_UPER
int Encode_UPER_Hotdockcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockcmdstatus *pSrc);
#endif

#ifdef __NEED_Hotdockcmdstatus_ACN
int Encode_ACN_Hotdockcmdstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccHotdockcmdstatus *pSrc);
#endif

#ifdef __NEED_Hotdockcmdstatus_NATIVE
int Encode_NATIVE_Hotdockcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockcmdstatus *pSrc);
#endif

#ifdef __NEED_Hotdockcmdstatus_UPER
int Decode_UPER_Hotdockcmdstatus(asn1SccHotdockcmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Hotdockcmdstatus_ACN
int Decode_ACN_Hotdockcmdstatus(asn1SccHotdockcmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Hotdockcmdstatus_NATIVE
int Decode_NATIVE_Hotdockcmdstatus(asn1SccHotdockcmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Hotdockstatusstatus_UPER
int Encode_UPER_Hotdockstatusstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockstatusstatus *pSrc);
#endif

#ifdef __NEED_Hotdockstatusstatus_ACN
int Encode_ACN_Hotdockstatusstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccHotdockstatusstatus *pSrc);
#endif

#ifdef __NEED_Hotdockstatusstatus_NATIVE
int Encode_NATIVE_Hotdockstatusstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccHotdockstatusstatus *pSrc);
#endif

#ifdef __NEED_Hotdockstatusstatus_UPER
int Decode_UPER_Hotdockstatusstatus(asn1SccHotdockstatusstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Hotdockstatusstatus_ACN
int Decode_ACN_Hotdockstatusstatus(asn1SccHotdockstatusstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Hotdockstatusstatus_NATIVE
int Decode_NATIVE_Hotdockstatusstatus(asn1SccHotdockstatusstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Wmcmdstatus_UPER
int Encode_UPER_Wmcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccWmcmdstatus *pSrc);
#endif

#ifdef __NEED_Wmcmdstatus_ACN
int Encode_ACN_Wmcmdstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccWmcmdstatus *pSrc);
#endif

#ifdef __NEED_Wmcmdstatus_NATIVE
int Encode_NATIVE_Wmcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccWmcmdstatus *pSrc);
#endif

#ifdef __NEED_Wmcmdstatus_UPER
int Decode_UPER_Wmcmdstatus(asn1SccWmcmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Wmcmdstatus_ACN
int Decode_ACN_Wmcmdstatus(asn1SccWmcmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Wmcmdstatus_NATIVE
int Decode_NATIVE_Wmcmdstatus(asn1SccWmcmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Basecmdstatus_UPER
int Encode_UPER_Basecmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccBasecmdstatus *pSrc);
#endif

#ifdef __NEED_Basecmdstatus_ACN
int Encode_ACN_Basecmdstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccBasecmdstatus *pSrc);
#endif

#ifdef __NEED_Basecmdstatus_NATIVE
int Encode_NATIVE_Basecmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccBasecmdstatus *pSrc);
#endif

#ifdef __NEED_Basecmdstatus_UPER
int Decode_UPER_Basecmdstatus(asn1SccBasecmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Basecmdstatus_ACN
int Decode_ACN_Basecmdstatus(asn1SccBasecmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Basecmdstatus_NATIVE
int Decode_NATIVE_Basecmdstatus(asn1SccBasecmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Efcmdstatus_UPER
int Encode_UPER_Efcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccEfcmdstatus *pSrc);
#endif

#ifdef __NEED_Efcmdstatus_ACN
int Encode_ACN_Efcmdstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccEfcmdstatus *pSrc);
#endif

#ifdef __NEED_Efcmdstatus_NATIVE
int Encode_NATIVE_Efcmdstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccEfcmdstatus *pSrc);
#endif

#ifdef __NEED_Efcmdstatus_UPER
int Decode_UPER_Efcmdstatus(asn1SccEfcmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Efcmdstatus_ACN
int Decode_ACN_Efcmdstatus(asn1SccEfcmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Efcmdstatus_NATIVE
int Decode_NATIVE_Efcmdstatus(asn1SccEfcmdstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Plannerstatus_UPER
int Encode_UPER_Plannerstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPlannerstatus *pSrc);
#endif

#ifdef __NEED_Plannerstatus_ACN
int Encode_ACN_Plannerstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccPlannerstatus *pSrc);
#endif

#ifdef __NEED_Plannerstatus_NATIVE
int Encode_NATIVE_Plannerstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPlannerstatus *pSrc);
#endif

#ifdef __NEED_Plannerstatus_UPER
int Decode_UPER_Plannerstatus(asn1SccPlannerstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Plannerstatus_ACN
int Decode_ACN_Plannerstatus(asn1SccPlannerstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Plannerstatus_NATIVE
int Decode_NATIVE_Plannerstatus(asn1SccPlannerstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Missionstatus_UPER
int Encode_UPER_Missionstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccMissionstatus *pSrc);
#endif

#ifdef __NEED_Missionstatus_ACN
int Encode_ACN_Missionstatus(void *pBuffer, size_t iMaxBufferSize, asn1SccMissionstatus *pSrc);
#endif

#ifdef __NEED_Missionstatus_NATIVE
int Encode_NATIVE_Missionstatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccMissionstatus *pSrc);
#endif

#ifdef __NEED_Missionstatus_UPER
int Decode_UPER_Missionstatus(asn1SccMissionstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Missionstatus_ACN
int Decode_ACN_Missionstatus(asn1SccMissionstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Missionstatus_NATIVE
int Decode_NATIVE_Missionstatus(asn1SccMissionstatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Autonomystatus_UPER
int Encode_UPER_Autonomystatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccAutonomystatus *pSrc);
#endif

#ifdef __NEED_Autonomystatus_ACN
int Encode_ACN_Autonomystatus(void *pBuffer, size_t iMaxBufferSize, asn1SccAutonomystatus *pSrc);
#endif

#ifdef __NEED_Autonomystatus_NATIVE
int Encode_NATIVE_Autonomystatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccAutonomystatus *pSrc);
#endif

#ifdef __NEED_Autonomystatus_UPER
int Decode_UPER_Autonomystatus(asn1SccAutonomystatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Autonomystatus_ACN
int Decode_ACN_Autonomystatus(asn1SccAutonomystatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Autonomystatus_NATIVE
int Decode_NATIVE_Autonomystatus(asn1SccAutonomystatus *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Pus_220_StateId_UPER
int Encode_UPER_Pus_220_StateId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPus_220_StateId *pSrc);
#endif

#ifdef __NEED_Pus_220_StateId_ACN
int Encode_ACN_Pus_220_StateId(void *pBuffer, size_t iMaxBufferSize, asn1SccPus_220_StateId *pSrc);
#endif

#ifdef __NEED_Pus_220_StateId_NATIVE
int Encode_NATIVE_Pus_220_StateId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPus_220_StateId *pSrc);
#endif

#ifdef __NEED_Pus_220_StateId_UPER
int Decode_UPER_Pus_220_StateId(asn1SccPus_220_StateId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Pus_220_StateId_ACN
int Decode_ACN_Pus_220_StateId(asn1SccPus_220_StateId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Pus_220_StateId_NATIVE
int Decode_NATIVE_Pus_220_StateId(asn1SccPus_220_StateId *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_220_1_Data_UPER
int Encode_UPER_PusTC_220_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_220_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_220_1_Data_ACN
int Encode_ACN_PusTC_220_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_220_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_220_1_Data_NATIVE
int Encode_NATIVE_PusTC_220_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_220_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_220_1_Data_UPER
int Decode_UPER_PusTC_220_1_Data(asn1SccPusTC_220_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_220_1_Data_ACN
int Decode_ACN_PusTC_220_1_Data(asn1SccPusTC_220_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_220_1_Data_NATIVE
int Decode_NATIVE_PusTC_220_1_Data(asn1SccPusTC_220_1_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_220_3_Data_UPER
int Encode_UPER_PusTM_220_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_220_3_Data *pSrc);
#endif

#ifdef __NEED_PusTM_220_3_Data_ACN
int Encode_ACN_PusTM_220_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_220_3_Data *pSrc);
#endif

#ifdef __NEED_PusTM_220_3_Data_NATIVE
int Encode_NATIVE_PusTM_220_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_220_3_Data *pSrc);
#endif

#ifdef __NEED_PusTM_220_3_Data_UPER
int Decode_UPER_PusTM_220_3_Data(asn1SccPusTM_220_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_220_3_Data_ACN
int Decode_ACN_PusTM_220_3_Data(asn1SccPusTM_220_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTM_220_3_Data_NATIVE
int Decode_NATIVE_PusTM_220_3_Data(asn1SccPusTM_220_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Pus_220_ActiveIds_UPER
int Encode_UPER_Pus_220_ActiveIds(void *pBuffer, size_t iMaxBufferSize, const asn1SccPus_220_ActiveIds *pSrc);
#endif

#ifdef __NEED_Pus_220_ActiveIds_ACN
int Encode_ACN_Pus_220_ActiveIds(void *pBuffer, size_t iMaxBufferSize, asn1SccPus_220_ActiveIds *pSrc);
#endif

#ifdef __NEED_Pus_220_ActiveIds_NATIVE
int Encode_NATIVE_Pus_220_ActiveIds(void *pBuffer, size_t iMaxBufferSize, const asn1SccPus_220_ActiveIds *pSrc);
#endif

#ifdef __NEED_Pus_220_ActiveIds_UPER
int Decode_UPER_Pus_220_ActiveIds(asn1SccPus_220_ActiveIds *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Pus_220_ActiveIds_ACN
int Decode_ACN_Pus_220_ActiveIds(asn1SccPus_220_ActiveIds *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_Pus_220_ActiveIds_NATIVE
int Decode_NATIVE_Pus_220_ActiveIds(asn1SccPus_220_ActiveIds *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt23RepositoryPath_UPER
int Encode_UPER_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryPath *pSrc);
#endif

#ifdef __NEED_PusSt23RepositoryPath_ACN
int Encode_ACN_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23RepositoryPath *pSrc);
#endif

#ifdef __NEED_PusSt23RepositoryPath_NATIVE
int Encode_NATIVE_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryPath *pSrc);
#endif

#ifdef __NEED_PusSt23RepositoryPath_UPER
int Decode_UPER_PusSt23RepositoryPath(asn1SccPusSt23RepositoryPath *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt23RepositoryPath_ACN
int Decode_ACN_PusSt23RepositoryPath(asn1SccPusSt23RepositoryPath *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt23RepositoryPath_NATIVE
int Decode_NATIVE_PusSt23RepositoryPath(asn1SccPusSt23RepositoryPath *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt23FileName_UPER
int Encode_UPER_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23FileName *pSrc);
#endif

#ifdef __NEED_PusSt23FileName_ACN
int Encode_ACN_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23FileName *pSrc);
#endif

#ifdef __NEED_PusSt23FileName_NATIVE
int Encode_NATIVE_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23FileName *pSrc);
#endif

#ifdef __NEED_PusSt23FileName_UPER
int Decode_UPER_PusSt23FileName(asn1SccPusSt23FileName *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt23FileName_ACN
int Decode_ACN_PusSt23FileName(asn1SccPusSt23FileName *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt23FileName_NATIVE
int Decode_NATIVE_PusSt23FileName(asn1SccPusSt23FileName *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt23RepositoryDomain_UPER
int Encode_UPER_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryDomain *pSrc);
#endif

#ifdef __NEED_PusSt23RepositoryDomain_ACN
int Encode_ACN_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23RepositoryDomain *pSrc);
#endif

#ifdef __NEED_PusSt23RepositoryDomain_NATIVE
int Encode_NATIVE_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryDomain *pSrc);
#endif

#ifdef __NEED_PusSt23RepositoryDomain_UPER
int Decode_UPER_PusSt23RepositoryDomain(asn1SccPusSt23RepositoryDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt23RepositoryDomain_ACN
int Decode_ACN_PusSt23RepositoryDomain(asn1SccPusSt23RepositoryDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusSt23RepositoryDomain_NATIVE
int Decode_NATIVE_PusSt23RepositoryDomain(asn1SccPusSt23RepositoryDomain *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_UPER
int Encode_UPER_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_23_1_4_Data *pSrc);
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_ACN
int Encode_ACN_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_TM_23_1_4_Data *pSrc);
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_NATIVE
int Encode_NATIVE_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_23_1_4_Data *pSrc);
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_UPER
int Decode_UPER_PusTC_TM_23_1_4_Data(asn1SccPusTC_TM_23_1_4_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_ACN
int Decode_ACN_PusTC_TM_23_1_4_Data(asn1SccPusTC_TM_23_1_4_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_NATIVE
int Decode_NATIVE_PusTC_TM_23_1_4_Data(asn1SccPusTC_TM_23_1_4_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_23_2_3_Data_UPER
int Encode_UPER_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_2_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_23_2_3_Data_ACN
int Encode_ACN_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_23_2_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_23_2_3_Data_NATIVE
int Encode_NATIVE_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_2_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_23_2_3_Data_UPER
int Decode_UPER_PusTC_23_2_3_Data(asn1SccPusTC_23_2_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_23_2_3_Data_ACN
int Decode_ACN_PusTC_23_2_3_Data(asn1SccPusTC_23_2_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_23_2_3_Data_NATIVE
int Decode_NATIVE_PusTC_23_2_3_Data(asn1SccPusTC_23_2_3_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_23_14_Data_UPER
int Encode_UPER_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_14_Data *pSrc);
#endif

#ifdef __NEED_PusTC_23_14_Data_ACN
int Encode_ACN_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_23_14_Data *pSrc);
#endif

#ifdef __NEED_PusTC_23_14_Data_NATIVE
int Encode_NATIVE_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_14_Data *pSrc);
#endif

#ifdef __NEED_PusTC_23_14_Data_UPER
int Decode_UPER_PusTC_23_14_Data(asn1SccPusTC_23_14_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_23_14_Data_ACN
int Decode_ACN_PusTC_23_14_Data(asn1SccPusTC_23_14_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTC_23_14_Data_NATIVE
int Decode_NATIVE_PusTC_23_14_Data(asn1SccPusTC_23_14_Data *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Double_UPER
int Encode_UPER_T_Double(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Double *pSrc);
#endif

#ifdef __NEED_T_Double_ACN
int Encode_ACN_T_Double(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Double *pSrc);
#endif

#ifdef __NEED_T_Double_NATIVE
int Encode_NATIVE_T_Double(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Double *pSrc);
#endif

#ifdef __NEED_T_Double_UPER
int Decode_UPER_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Double_ACN
int Decode_ACN_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Double_NATIVE
int Decode_NATIVE_T_Double(asn1SccT_Double *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Float_UPER
int Encode_UPER_T_Float(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Float *pSrc);
#endif

#ifdef __NEED_T_Float_ACN
int Encode_ACN_T_Float(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Float *pSrc);
#endif

#ifdef __NEED_T_Float_NATIVE
int Encode_NATIVE_T_Float(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Float *pSrc);
#endif

#ifdef __NEED_T_Float_UPER
int Decode_UPER_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Float_ACN
int Decode_ACN_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Float_NATIVE
int Decode_NATIVE_T_Float(asn1SccT_Float *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int16_UPER
int Encode_UPER_T_Int16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int16 *pSrc);
#endif

#ifdef __NEED_T_Int16_ACN
int Encode_ACN_T_Int16(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int16 *pSrc);
#endif

#ifdef __NEED_T_Int16_NATIVE
int Encode_NATIVE_T_Int16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int16 *pSrc);
#endif

#ifdef __NEED_T_Int16_UPER
int Decode_UPER_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int16_ACN
int Decode_ACN_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int16_NATIVE
int Decode_NATIVE_T_Int16(asn1SccT_Int16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt16_UPER
int Encode_UPER_T_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt16 *pSrc);
#endif

#ifdef __NEED_T_UInt16_ACN
int Encode_ACN_T_UInt16(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt16 *pSrc);
#endif

#ifdef __NEED_T_UInt16_NATIVE
int Encode_NATIVE_T_UInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt16 *pSrc);
#endif

#ifdef __NEED_T_UInt16_UPER
int Decode_UPER_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt16_ACN
int Decode_ACN_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt16_NATIVE
int Decode_NATIVE_T_UInt16(asn1SccT_UInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt64_UPER
int Encode_UPER_T_UInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt64 *pSrc);
#endif

#ifdef __NEED_T_UInt64_ACN
int Encode_ACN_T_UInt64(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt64 *pSrc);
#endif

#ifdef __NEED_T_UInt64_NATIVE
int Encode_NATIVE_T_UInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt64 *pSrc);
#endif

#ifdef __NEED_T_UInt64_UPER
int Decode_UPER_T_UInt64(asn1SccT_UInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt64_ACN
int Decode_ACN_T_UInt64(asn1SccT_UInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt64_NATIVE
int Decode_NATIVE_T_UInt64(asn1SccT_UInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int64_UPER
int Encode_UPER_T_Int64(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int64 *pSrc);
#endif

#ifdef __NEED_T_Int64_ACN
int Encode_ACN_T_Int64(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int64 *pSrc);
#endif

#ifdef __NEED_T_Int64_NATIVE
int Encode_NATIVE_T_Int64(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int64 *pSrc);
#endif

#ifdef __NEED_T_Int64_UPER
int Decode_UPER_T_Int64(asn1SccT_Int64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int64_ACN
int Decode_ACN_T_Int64(asn1SccT_Int64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int64_NATIVE
int Decode_NATIVE_T_Int64(asn1SccT_Int64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_String_UPER
int Encode_UPER_T_String(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_String *pSrc);
#endif

#ifdef __NEED_T_String_ACN
int Encode_ACN_T_String(void *pBuffer, size_t iMaxBufferSize, asn1SccT_String *pSrc);
#endif

#ifdef __NEED_T_String_NATIVE
int Encode_NATIVE_T_String(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_String *pSrc);
#endif

#ifdef __NEED_T_String_UPER
int Decode_UPER_T_String(asn1SccT_String *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_String_ACN
int Decode_ACN_T_String(asn1SccT_String *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_String_NATIVE
int Decode_NATIVE_T_String(asn1SccT_String *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Time_UPER
int Encode_UPER_T_Time(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Time *pSrc);
#endif

#ifdef __NEED_T_Time_ACN
int Encode_ACN_T_Time(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Time *pSrc);
#endif

#ifdef __NEED_T_Time_NATIVE
int Encode_NATIVE_T_Time(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Time *pSrc);
#endif

#ifdef __NEED_T_Time_UPER
int Decode_UPER_T_Time(asn1SccT_Time *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Time_ACN
int Decode_ACN_T_Time(asn1SccT_Time *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Time_NATIVE
int Decode_NATIVE_T_Time(asn1SccT_Time *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTime_UPER
int Encode_UPER_PusTime(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTime *pSrc);
#endif

#ifdef __NEED_PusTime_ACN
int Encode_ACN_PusTime(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTime *pSrc);
#endif

#ifdef __NEED_PusTime_NATIVE
int Encode_NATIVE_PusTime(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTime *pSrc);
#endif

#ifdef __NEED_PusTime_UPER
int Decode_UPER_PusTime(asn1SccPusTime *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTime_ACN
int Decode_ACN_PusTime(asn1SccPusTime *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTime_NATIVE
int Decode_NATIVE_PusTime(asn1SccPusTime *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt3_UPER
int Encode_UPER_PusUInt3(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt3 *pSrc);
#endif

#ifdef __NEED_PusUInt3_ACN
int Encode_ACN_PusUInt3(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt3 *pSrc);
#endif

#ifdef __NEED_PusUInt3_NATIVE
int Encode_NATIVE_PusUInt3(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt3 *pSrc);
#endif

#ifdef __NEED_PusUInt3_UPER
int Decode_UPER_PusUInt3(asn1SccPusUInt3 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt3_ACN
int Decode_ACN_PusUInt3(asn1SccPusUInt3 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt3_NATIVE
int Decode_NATIVE_PusUInt3(asn1SccPusUInt3 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt4_UPER
int Encode_UPER_PusUInt4(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt4 *pSrc);
#endif

#ifdef __NEED_PusUInt4_ACN
int Encode_ACN_PusUInt4(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt4 *pSrc);
#endif

#ifdef __NEED_PusUInt4_NATIVE
int Encode_NATIVE_PusUInt4(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt4 *pSrc);
#endif

#ifdef __NEED_PusUInt4_UPER
int Decode_UPER_PusUInt4(asn1SccPusUInt4 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt4_ACN
int Decode_ACN_PusUInt4(asn1SccPusUInt4 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt4_NATIVE
int Decode_NATIVE_PusUInt4(asn1SccPusUInt4 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt8_UPER
int Encode_UPER_PusUInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt8 *pSrc);
#endif

#ifdef __NEED_PusUInt8_ACN
int Encode_ACN_PusUInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt8 *pSrc);
#endif

#ifdef __NEED_PusUInt8_NATIVE
int Encode_NATIVE_PusUInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt8 *pSrc);
#endif

#ifdef __NEED_PusUInt8_UPER
int Decode_UPER_PusUInt8(asn1SccPusUInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt8_ACN
int Decode_ACN_PusUInt8(asn1SccPusUInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt8_NATIVE
int Decode_NATIVE_PusUInt8(asn1SccPusUInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt11_UPER
int Encode_UPER_PusUInt11(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt11 *pSrc);
#endif

#ifdef __NEED_PusUInt11_ACN
int Encode_ACN_PusUInt11(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt11 *pSrc);
#endif

#ifdef __NEED_PusUInt11_NATIVE
int Encode_NATIVE_PusUInt11(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt11 *pSrc);
#endif

#ifdef __NEED_PusUInt11_UPER
int Decode_UPER_PusUInt11(asn1SccPusUInt11 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt11_ACN
int Decode_ACN_PusUInt11(asn1SccPusUInt11 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt11_NATIVE
int Decode_NATIVE_PusUInt11(asn1SccPusUInt11 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt14_UPER
int Encode_UPER_PusUInt14(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt14 *pSrc);
#endif

#ifdef __NEED_PusUInt14_ACN
int Encode_ACN_PusUInt14(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt14 *pSrc);
#endif

#ifdef __NEED_PusUInt14_NATIVE
int Encode_NATIVE_PusUInt14(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt14 *pSrc);
#endif

#ifdef __NEED_PusUInt14_UPER
int Decode_UPER_PusUInt14(asn1SccPusUInt14 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt14_ACN
int Decode_ACN_PusUInt14(asn1SccPusUInt14 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt14_NATIVE
int Decode_NATIVE_PusUInt14(asn1SccPusUInt14 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt16_UPER
int Encode_UPER_PusUInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt16 *pSrc);
#endif

#ifdef __NEED_PusUInt16_ACN
int Encode_ACN_PusUInt16(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt16 *pSrc);
#endif

#ifdef __NEED_PusUInt16_NATIVE
int Encode_NATIVE_PusUInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt16 *pSrc);
#endif

#ifdef __NEED_PusUInt16_UPER
int Decode_UPER_PusUInt16(asn1SccPusUInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt16_ACN
int Decode_ACN_PusUInt16(asn1SccPusUInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt16_NATIVE
int Decode_NATIVE_PusUInt16(asn1SccPusUInt16 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt32_UPER
int Encode_UPER_PusUInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt32 *pSrc);
#endif

#ifdef __NEED_PusUInt32_ACN
int Encode_ACN_PusUInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt32 *pSrc);
#endif

#ifdef __NEED_PusUInt32_NATIVE
int Encode_NATIVE_PusUInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt32 *pSrc);
#endif

#ifdef __NEED_PusUInt32_UPER
int Decode_UPER_PusUInt32(asn1SccPusUInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt32_ACN
int Decode_ACN_PusUInt32(asn1SccPusUInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt32_NATIVE
int Decode_NATIVE_PusUInt32(asn1SccPusUInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt64_UPER
int Encode_UPER_PusUInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt64 *pSrc);
#endif

#ifdef __NEED_PusUInt64_ACN
int Encode_ACN_PusUInt64(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt64 *pSrc);
#endif

#ifdef __NEED_PusUInt64_NATIVE
int Encode_NATIVE_PusUInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt64 *pSrc);
#endif

#ifdef __NEED_PusUInt64_UPER
int Decode_UPER_PusUInt64(asn1SccPusUInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt64_ACN
int Decode_ACN_PusUInt64(asn1SccPusUInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusUInt64_NATIVE
int Decode_NATIVE_PusUInt64(asn1SccPusUInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusInt32_UPER
int Encode_UPER_PusInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt32 *pSrc);
#endif

#ifdef __NEED_PusInt32_ACN
int Encode_ACN_PusInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccPusInt32 *pSrc);
#endif

#ifdef __NEED_PusInt32_NATIVE
int Encode_NATIVE_PusInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt32 *pSrc);
#endif

#ifdef __NEED_PusInt32_UPER
int Decode_UPER_PusInt32(asn1SccPusInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusInt32_ACN
int Decode_ACN_PusInt32(asn1SccPusInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusInt32_NATIVE
int Decode_NATIVE_PusInt32(asn1SccPusInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusInt64_UPER
int Encode_UPER_PusInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt64 *pSrc);
#endif

#ifdef __NEED_PusInt64_ACN
int Encode_ACN_PusInt64(void *pBuffer, size_t iMaxBufferSize, asn1SccPusInt64 *pSrc);
#endif

#ifdef __NEED_PusInt64_NATIVE
int Encode_NATIVE_PusInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt64 *pSrc);
#endif

#ifdef __NEED_PusInt64_UPER
int Decode_UPER_PusInt64(asn1SccPusInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusInt64_ACN
int Decode_ACN_PusInt64(asn1SccPusInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusInt64_NATIVE
int Decode_NATIVE_PusInt64(asn1SccPusInt64 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusDouble_UPER
int Encode_UPER_PusDouble(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusDouble *pSrc);
#endif

#ifdef __NEED_PusDouble_ACN
int Encode_ACN_PusDouble(void *pBuffer, size_t iMaxBufferSize, asn1SccPusDouble *pSrc);
#endif

#ifdef __NEED_PusDouble_NATIVE
int Encode_NATIVE_PusDouble(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusDouble *pSrc);
#endif

#ifdef __NEED_PusDouble_UPER
int Decode_UPER_PusDouble(asn1SccPusDouble *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusDouble_ACN
int Decode_ACN_PusDouble(asn1SccPusDouble *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusDouble_NATIVE
int Decode_NATIVE_PusDouble(asn1SccPusDouble *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusMemAddr_UPER
int Encode_UPER_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMemAddr *pSrc);
#endif

#ifdef __NEED_PusMemAddr_ACN
int Encode_ACN_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, asn1SccPusMemAddr *pSrc);
#endif

#ifdef __NEED_PusMemAddr_NATIVE
int Encode_NATIVE_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMemAddr *pSrc);
#endif

#ifdef __NEED_PusMemAddr_UPER
int Decode_UPER_PusMemAddr(asn1SccPusMemAddr *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusMemAddr_ACN
int Decode_ACN_PusMemAddr(asn1SccPusMemAddr *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusMemAddr_NATIVE
int Decode_NATIVE_PusMemAddr(asn1SccPusMemAddr *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_UPER
int Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_ACN
int Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_UPER
int Decode_UPER_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_ACN
int Decode_ACN_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int32_NATIVE
int Decode_NATIVE_T_Int32(asn1SccT_Int32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_UPER
int Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_ACN
int Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_UPER
int Decode_UPER_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_ACN
int Decode_ACN_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt32_NATIVE
int Decode_NATIVE_T_UInt32(asn1SccT_UInt32 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_UPER
int Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_ACN
int Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_UPER
int Decode_UPER_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_ACN
int Decode_ACN_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Int8_NATIVE
int Decode_NATIVE_T_Int8(asn1SccT_Int8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_UPER
int Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_ACN
int Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_UPER
int Decode_UPER_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_ACN
int Decode_ACN_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_UInt8_NATIVE
int Decode_NATIVE_T_UInt8(asn1SccT_UInt8 *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_UPER
int Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_ACN
int Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_UPER
int Decode_UPER_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_ACN
int Decode_ACN_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_T_Boolean_NATIVE
int Decode_NATIVE_T_Boolean(asn1SccT_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif


#endif
