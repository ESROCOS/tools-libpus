#ifndef __C_DATAVIEW_UNIQ_H__
#define __C_DATAVIEW_UNIQ_H__

#include <stdlib.h> /* for size_t */

#include "dataview-uniq.h" // Space certified compiler generated

#include "../../system_config.h" // Choose ASN.1 Types to use

#ifdef __NEED_PusTC_19_X_Data_UPER
size_t Encode_UPER_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_X_Data *pSrc);
#endif

#ifdef __NEED_PusTC_19_X_Data_ACN
size_t Encode_ACN_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_19_X_Data *pSrc);
#endif

#ifdef __NEED_PusTC_19_X_Data_NATIVE
size_t Encode_NATIVE_PusTC_19_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_X_Data *pSrc);
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

#ifdef __NEED_PusTime_UPER
size_t Encode_UPER_PusTime(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTime *pSrc);
#endif

#ifdef __NEED_PusTime_ACN
size_t Encode_ACN_PusTime(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTime *pSrc);
#endif

#ifdef __NEED_PusTime_NATIVE
size_t Encode_NATIVE_PusTime(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTime *pSrc);
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

#ifdef __NEED_PusSt18ObcpCode_UPER
size_t Encode_UPER_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpCode *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpCode_ACN
size_t Encode_ACN_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpCode *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpCode_NATIVE
size_t Encode_NATIVE_PusSt18ObcpCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpCode *pSrc);
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

#ifdef __NEED_PusTC_18_3_Data_UPER
size_t Encode_UPER_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_3_Data_ACN
size_t Encode_ACN_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_3_Data_NATIVE
size_t Encode_NATIVE_PusTC_18_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_3_Data *pSrc);
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

#ifdef __NEED_PusTcApplicationData_UPER
size_t Encode_UPER_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationData *pSrc);
#endif

#ifdef __NEED_PusTcApplicationData_ACN
size_t Encode_ACN_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcApplicationData *pSrc);
#endif

#ifdef __NEED_PusTcApplicationData_NATIVE
size_t Encode_NATIVE_PusTcApplicationData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationData *pSrc);
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

#ifdef __NEED_PusSt18ObservabilityLevel_UPER
size_t Encode_UPER_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObservabilityLevel *pSrc);
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_ACN
size_t Encode_ACN_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObservabilityLevel *pSrc);
#endif

#ifdef __NEED_PusSt18ObservabilityLevel_NATIVE
size_t Encode_NATIVE_PusSt18ObservabilityLevel(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObservabilityLevel *pSrc);
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

#ifdef __NEED_PusPacket_UPER
size_t Encode_UPER_PusPacket(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacket *pSrc);
#endif

#ifdef __NEED_PusPacket_ACN
size_t Encode_ACN_PusPacket(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacket *pSrc);
#endif

#ifdef __NEED_PusPacket_NATIVE
size_t Encode_NATIVE_PusPacket(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacket *pSrc);
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

#ifdef __NEED_PusSequenceCount_UPER
size_t Encode_UPER_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceCount *pSrc);
#endif

#ifdef __NEED_PusSequenceCount_ACN
size_t Encode_ACN_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSequenceCount *pSrc);
#endif

#ifdef __NEED_PusSequenceCount_NATIVE
size_t Encode_NATIVE_PusSequenceCount(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceCount *pSrc);
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
size_t Encode_UPER_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataLength *pSrc);
#endif

#ifdef __NEED_PusPacketDataLength_ACN
size_t Encode_ACN_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketDataLength *pSrc);
#endif

#ifdef __NEED_PusPacketDataLength_NATIVE
size_t Encode_NATIVE_PusPacketDataLength(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataLength *pSrc);
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

#ifdef __NEED_PusPacketVersion_UPER
size_t Encode_UPER_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketVersion *pSrc);
#endif

#ifdef __NEED_PusPacketVersion_ACN
size_t Encode_ACN_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketVersion *pSrc);
#endif

#ifdef __NEED_PusPacketVersion_NATIVE
size_t Encode_NATIVE_PusPacketVersion(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketVersion *pSrc);
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

#ifdef __NEED_PusConfigDummyType_UPER
size_t Encode_UPER_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusConfigDummyType *pSrc);
#endif

#ifdef __NEED_PusConfigDummyType_ACN
size_t Encode_ACN_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusConfigDummyType *pSrc);
#endif

#ifdef __NEED_PusConfigDummyType_NATIVE
size_t Encode_NATIVE_PusConfigDummyType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusConfigDummyType *pSrc);
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

#ifdef __NEED_PusTC_18_13_Data_UPER
size_t Encode_UPER_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_13_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_13_Data_ACN
size_t Encode_ACN_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_13_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_13_Data_NATIVE
size_t Encode_NATIVE_PusTC_18_13_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_13_Data *pSrc);
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

#ifdef __NEED_PusTM_3_25_Data_UPER
size_t Encode_UPER_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_3_25_Data *pSrc);
#endif

#ifdef __NEED_PusTM_3_25_Data_ACN
size_t Encode_ACN_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_3_25_Data *pSrc);
#endif

#ifdef __NEED_PusTM_3_25_Data_NATIVE
size_t Encode_NATIVE_PusTM_3_25_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_3_25_Data *pSrc);
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

#ifdef __NEED_PusTM_5_X_Data_UPER
size_t Encode_UPER_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_5_X_Data *pSrc);
#endif

#ifdef __NEED_PusTM_5_X_Data_ACN
size_t Encode_ACN_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_5_X_Data *pSrc);
#endif

#ifdef __NEED_PusTM_5_X_Data_NATIVE
size_t Encode_NATIVE_PusTM_5_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_5_X_Data *pSrc);
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

#ifdef __NEED_PusTC_18_2_6_12_Data_UPER
size_t Encode_UPER_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_2_6_12_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_ACN
size_t Encode_ACN_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_2_6_12_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_2_6_12_Data_NATIVE
size_t Encode_NATIVE_PusTC_18_2_6_12_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_2_6_12_Data *pSrc);
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

#ifdef __NEED_PusSt01RequestId_UPER
size_t Encode_UPER_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01RequestId *pSrc);
#endif

#ifdef __NEED_PusSt01RequestId_ACN
size_t Encode_ACN_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01RequestId *pSrc);
#endif

#ifdef __NEED_PusSt01RequestId_NATIVE
size_t Encode_NATIVE_PusSt01RequestId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01RequestId *pSrc);
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

#ifdef __NEED_PusTC_9_1_Data_UPER
size_t Encode_UPER_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_9_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_9_1_Data_ACN
size_t Encode_ACN_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_9_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_9_1_Data_NATIVE
size_t Encode_NATIVE_PusTC_9_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_9_1_Data *pSrc);
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

#ifdef __NEED_PusUInt14_UPER
size_t Encode_UPER_PusUInt14(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt14 *pSrc);
#endif

#ifdef __NEED_PusUInt14_ACN
size_t Encode_ACN_PusUInt14(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt14 *pSrc);
#endif

#ifdef __NEED_PusUInt14_NATIVE
size_t Encode_NATIVE_PusUInt14(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt14 *pSrc);
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

#ifdef __NEED_PusTC_18_4_5_Data_UPER
size_t Encode_UPER_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_4_5_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_4_5_Data_ACN
size_t Encode_ACN_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_4_5_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_4_5_Data_NATIVE
size_t Encode_NATIVE_PusTC_18_4_5_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_4_5_Data *pSrc);
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

#ifdef __NEED_T_UInt8_UPER
size_t Encode_UPER_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_ACN
size_t Encode_ACN_T_UInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt8 *pSrc);
#endif

#ifdef __NEED_T_UInt8_NATIVE
size_t Encode_NATIVE_T_UInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt8 *pSrc);
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

#ifdef __NEED_PusSt03ParameterArray_UPER
size_t Encode_UPER_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterArray *pSrc);
#endif

#ifdef __NEED_PusSt03ParameterArray_ACN
size_t Encode_ACN_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03ParameterArray *pSrc);
#endif

#ifdef __NEED_PusSt03ParameterArray_NATIVE
size_t Encode_NATIVE_PusSt03ParameterArray(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterArray *pSrc);
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

#ifdef __NEED_PusSecondaryHeaderFlag_UPER
size_t Encode_UPER_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSecondaryHeaderFlag *pSrc);
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_ACN
size_t Encode_ACN_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSecondaryHeaderFlag *pSrc);
#endif

#ifdef __NEED_PusSecondaryHeaderFlag_NATIVE
size_t Encode_NATIVE_PusSecondaryHeaderFlag(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSecondaryHeaderFlag *pSrc);
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

#ifdef __NEED_PusUInt16_UPER
size_t Encode_UPER_PusUInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt16 *pSrc);
#endif

#ifdef __NEED_PusUInt16_ACN
size_t Encode_ACN_PusUInt16(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt16 *pSrc);
#endif

#ifdef __NEED_PusUInt16_NATIVE
size_t Encode_NATIVE_PusUInt16(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt16 *pSrc);
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

#ifdef __NEED_T_Int8_UPER
size_t Encode_UPER_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_ACN
size_t Encode_ACN_T_Int8(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int8 *pSrc);
#endif

#ifdef __NEED_T_Int8_NATIVE
size_t Encode_NATIVE_T_Int8(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int8 *pSrc);
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

#ifdef __NEED_T_Boolean_UPER
size_t Encode_UPER_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_ACN
size_t Encode_ACN_T_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Boolean *pSrc);
#endif

#ifdef __NEED_T_Boolean_NATIVE
size_t Encode_NATIVE_T_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Boolean *pSrc);
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

#ifdef __NEED_PusInt32_UPER
size_t Encode_UPER_PusInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt32 *pSrc);
#endif

#ifdef __NEED_PusInt32_ACN
size_t Encode_ACN_PusInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccPusInt32 *pSrc);
#endif

#ifdef __NEED_PusInt32_NATIVE
size_t Encode_NATIVE_PusInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt32 *pSrc);
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

#ifdef __NEED_PusTcApplicationDataReduced_UPER
size_t Encode_UPER_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationDataReduced *pSrc);
#endif

#ifdef __NEED_PusTcApplicationDataReduced_ACN
size_t Encode_ACN_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcApplicationDataReduced *pSrc);
#endif

#ifdef __NEED_PusTcApplicationDataReduced_NATIVE
size_t Encode_NATIVE_PusTcApplicationDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcApplicationDataReduced *pSrc);
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

#ifdef __NEED_TASTE_Boolean_UPER
size_t Encode_UPER_TASTE_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccTASTE_Boolean *pSrc);
#endif

#ifdef __NEED_TASTE_Boolean_ACN
size_t Encode_ACN_TASTE_Boolean(void *pBuffer, size_t iMaxBufferSize, asn1SccTASTE_Boolean *pSrc);
#endif

#ifdef __NEED_TASTE_Boolean_NATIVE
size_t Encode_NATIVE_TASTE_Boolean(void *pBuffer, size_t iMaxBufferSize, const asn1SccTASTE_Boolean *pSrc);
#endif

#ifdef __NEED_TASTE_Boolean_UPER
int Decode_UPER_TASTE_Boolean(asn1SccTASTE_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TASTE_Boolean_ACN
int Decode_ACN_TASTE_Boolean(asn1SccTASTE_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_TASTE_Boolean_NATIVE
int Decode_NATIVE_TASTE_Boolean(asn1SccTASTE_Boolean *pDst, void *pBuffer, size_t iBufferSize);
#endif

#ifdef __NEED_PusTcHeader_UPER
size_t Encode_UPER_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcHeader *pSrc);
#endif

#ifdef __NEED_PusTcHeader_ACN
size_t Encode_ACN_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcHeader *pSrc);
#endif

#ifdef __NEED_PusTcHeader_NATIVE
size_t Encode_NATIVE_PusTcHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcHeader *pSrc);
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

#ifdef __NEED_PusApid_UPER
size_t Encode_UPER_PusApid(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusApid *pSrc);
#endif

#ifdef __NEED_PusApid_ACN
size_t Encode_ACN_PusApid(void *pBuffer, size_t iMaxBufferSize, asn1SccPusApid *pSrc);
#endif

#ifdef __NEED_PusApid_NATIVE
size_t Encode_NATIVE_PusApid(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusApid *pSrc);
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

#ifdef __NEED_PusSt20StoredParam_UPER
size_t Encode_UPER_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20StoredParam *pSrc);
#endif

#ifdef __NEED_PusSt20StoredParam_ACN
size_t Encode_ACN_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt20StoredParam *pSrc);
#endif

#ifdef __NEED_PusSt20StoredParam_NATIVE
size_t Encode_NATIVE_PusSt20StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20StoredParam *pSrc);
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

#ifdef __NEED_T_Int32_UPER
size_t Encode_UPER_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_ACN
size_t Encode_ACN_T_Int32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_Int32 *pSrc);
#endif

#ifdef __NEED_T_Int32_NATIVE
size_t Encode_NATIVE_T_Int32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_Int32 *pSrc);
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

#ifdef __NEED_PusSt12pmonId_UPER
size_t Encode_UPER_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt12pmonId *pSrc);
#endif

#ifdef __NEED_PusSt12pmonId_ACN
size_t Encode_ACN_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt12pmonId *pSrc);
#endif

#ifdef __NEED_PusSt12pmonId_NATIVE
size_t Encode_NATIVE_PusSt12pmonId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt12pmonId *pSrc);
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

#ifdef __NEED_PusTcScheduledActivity_UPER
size_t Encode_UPER_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcScheduledActivity *pSrc);
#endif

#ifdef __NEED_PusTcScheduledActivity_ACN
size_t Encode_ACN_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTcScheduledActivity *pSrc);
#endif

#ifdef __NEED_PusTcScheduledActivity_NATIVE
size_t Encode_NATIVE_PusTcScheduledActivity(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTcScheduledActivity *pSrc);
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

#ifdef __NEED_PusSt05EventAuxData_UPER
size_t Encode_UPER_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventAuxData *pSrc);
#endif

#ifdef __NEED_PusSt05EventAuxData_ACN
size_t Encode_ACN_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05EventAuxData *pSrc);
#endif

#ifdef __NEED_PusSt05EventAuxData_NATIVE
size_t Encode_NATIVE_PusSt05EventAuxData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventAuxData *pSrc);
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

#ifdef __NEED_PusSt05EventId_UPER
size_t Encode_UPER_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventId *pSrc);
#endif

#ifdef __NEED_PusSt05EventId_ACN
size_t Encode_ACN_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05EventId *pSrc);
#endif

#ifdef __NEED_PusSt05EventId_NATIVE
size_t Encode_NATIVE_PusSt05EventId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05EventId *pSrc);
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

#ifdef __NEED_PusUInt32_UPER
size_t Encode_UPER_PusUInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt32 *pSrc);
#endif

#ifdef __NEED_PusUInt32_ACN
size_t Encode_ACN_PusUInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt32 *pSrc);
#endif

#ifdef __NEED_PusUInt32_NATIVE
size_t Encode_NATIVE_PusUInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt32 *pSrc);
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

#ifdef __NEED_PusSt03ParameterId_UPER
size_t Encode_UPER_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterId *pSrc);
#endif

#ifdef __NEED_PusSt03ParameterId_ACN
size_t Encode_ACN_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03ParameterId *pSrc);
#endif

#ifdef __NEED_PusSt03ParameterId_NATIVE
size_t Encode_NATIVE_PusSt03ParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03ParameterId *pSrc);
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

#ifdef __NEED_PusChecksum_UPER
size_t Encode_UPER_PusChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusChecksum *pSrc);
#endif

#ifdef __NEED_PusChecksum_ACN
size_t Encode_ACN_PusChecksum(void *pBuffer, size_t iMaxBufferSize, asn1SccPusChecksum *pSrc);
#endif

#ifdef __NEED_PusChecksum_NATIVE
size_t Encode_NATIVE_PusChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusChecksum *pSrc);
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

#ifdef __NEED_PusSt03HousekeepingReportId_UPER
size_t Encode_UPER_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03HousekeepingReportId *pSrc);
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_ACN
size_t Encode_ACN_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03HousekeepingReportId *pSrc);
#endif

#ifdef __NEED_PusSt03HousekeepingReportId_NATIVE
size_t Encode_NATIVE_PusSt03HousekeepingReportId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03HousekeepingReportId *pSrc);
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

#ifdef __NEED_PusSt05Event_UPER
size_t Encode_UPER_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05Event *pSrc);
#endif

#ifdef __NEED_PusSt05Event_ACN
size_t Encode_ACN_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt05Event *pSrc);
#endif

#ifdef __NEED_PusSt05Event_NATIVE
size_t Encode_NATIVE_PusSt05Event(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt05Event *pSrc);
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

#ifdef __NEED_PusMessageTypeCounter_UPER
size_t Encode_UPER_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMessageTypeCounter *pSrc);
#endif

#ifdef __NEED_PusMessageTypeCounter_ACN
size_t Encode_ACN_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, asn1SccPusMessageTypeCounter *pSrc);
#endif

#ifdef __NEED_PusMessageTypeCounter_NATIVE
size_t Encode_NATIVE_PusMessageTypeCounter(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMessageTypeCounter *pSrc);
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

#ifdef __NEED_PusTmHeaderData_UPER
size_t Encode_UPER_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeaderData *pSrc);
#endif

#ifdef __NEED_PusTmHeaderData_ACN
size_t Encode_ACN_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmHeaderData *pSrc);
#endif

#ifdef __NEED_PusTmHeaderData_NATIVE
size_t Encode_NATIVE_PusTmHeaderData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeaderData *pSrc);
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

#ifdef __NEED_PusSt01FailureInfo_UPER
size_t Encode_UPER_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureInfo *pSrc);
#endif

#ifdef __NEED_PusSt01FailureInfo_ACN
size_t Encode_ACN_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01FailureInfo *pSrc);
#endif

#ifdef __NEED_PusSt01FailureInfo_NATIVE
size_t Encode_NATIVE_PusSt01FailureInfo(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureInfo *pSrc);
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

#ifdef __NEED_PusSt08FunctionId_UPER
size_t Encode_UPER_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt08FunctionId *pSrc);
#endif

#ifdef __NEED_PusSt08FunctionId_ACN
size_t Encode_ACN_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt08FunctionId *pSrc);
#endif

#ifdef __NEED_PusSt08FunctionId_NATIVE
size_t Encode_NATIVE_PusSt08FunctionId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt08FunctionId *pSrc);
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

#ifdef __NEED_PusUInt11_UPER
size_t Encode_UPER_PusUInt11(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt11 *pSrc);
#endif

#ifdef __NEED_PusUInt11_ACN
size_t Encode_ACN_PusUInt11(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt11 *pSrc);
#endif

#ifdef __NEED_PusUInt11_NATIVE
size_t Encode_NATIVE_PusUInt11(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt11 *pSrc);
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

#ifdef __NEED_PusTimeReferenceStatus_UPER
size_t Encode_UPER_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTimeReferenceStatus *pSrc);
#endif

#ifdef __NEED_PusTimeReferenceStatus_ACN
size_t Encode_ACN_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTimeReferenceStatus *pSrc);
#endif

#ifdef __NEED_PusTimeReferenceStatus_NATIVE
size_t Encode_NATIVE_PusTimeReferenceStatus(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTimeReferenceStatus *pSrc);
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

#ifdef __NEED_PusMemAddr_UPER
size_t Encode_UPER_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMemAddr *pSrc);
#endif

#ifdef __NEED_PusMemAddr_ACN
size_t Encode_ACN_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, asn1SccPusMemAddr *pSrc);
#endif

#ifdef __NEED_PusMemAddr_NATIVE
size_t Encode_NATIVE_PusMemAddr(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusMemAddr *pSrc);
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

#ifdef __NEED_PusSt01Failure_UPER
size_t Encode_UPER_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01Failure *pSrc);
#endif

#ifdef __NEED_PusSt01Failure_ACN
size_t Encode_ACN_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01Failure *pSrc);
#endif

#ifdef __NEED_PusSt01Failure_NATIVE
size_t Encode_NATIVE_PusSt01Failure(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01Failure *pSrc);
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

#ifdef __NEED_PusSt18ObcpChecksum_UPER
size_t Encode_UPER_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpChecksum *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpChecksum_ACN
size_t Encode_ACN_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpChecksum *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpChecksum_NATIVE
size_t Encode_NATIVE_PusSt18ObcpChecksum(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpChecksum *pSrc);
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

#ifdef __NEED_PusUInt3_UPER
size_t Encode_UPER_PusUInt3(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt3 *pSrc);
#endif

#ifdef __NEED_PusUInt3_ACN
size_t Encode_ACN_PusUInt3(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt3 *pSrc);
#endif

#ifdef __NEED_PusUInt3_NATIVE
size_t Encode_NATIVE_PusUInt3(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt3 *pSrc);
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

#ifdef __NEED_PusTC_TM_20_X_Data_UPER
size_t Encode_UPER_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_20_X_Data *pSrc);
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_ACN
size_t Encode_ACN_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_TM_20_X_Data *pSrc);
#endif

#ifdef __NEED_PusTC_TM_20_X_Data_NATIVE
size_t Encode_NATIVE_PusTC_TM_20_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_20_X_Data *pSrc);
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

#ifdef __NEED_PusTC_23_2_3_Data_UPER
size_t Encode_UPER_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_2_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_23_2_3_Data_ACN
size_t Encode_ACN_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_23_2_3_Data *pSrc);
#endif

#ifdef __NEED_PusTC_23_2_3_Data_NATIVE
size_t Encode_NATIVE_PusTC_23_2_3_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_2_3_Data *pSrc);
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

#ifdef __NEED_PusSt18ObcpId_UPER
size_t Encode_UPER_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpId *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpId_ACN
size_t Encode_ACN_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt18ObcpId *pSrc);
#endif

#ifdef __NEED_PusSt18ObcpId_NATIVE
size_t Encode_NATIVE_PusSt18ObcpId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt18ObcpId *pSrc);
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

#ifdef __NEED_PusSt23RepositoryDomain_UPER
size_t Encode_UPER_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryDomain *pSrc);
#endif

#ifdef __NEED_PusSt23RepositoryDomain_ACN
size_t Encode_ACN_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23RepositoryDomain *pSrc);
#endif

#ifdef __NEED_PusSt23RepositoryDomain_NATIVE
size_t Encode_NATIVE_PusSt23RepositoryDomain(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryDomain *pSrc);
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

#ifdef __NEED_PusTmSourceData_UPER
size_t Encode_UPER_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmSourceData *pSrc);
#endif

#ifdef __NEED_PusTmSourceData_ACN
size_t Encode_ACN_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmSourceData *pSrc);
#endif

#ifdef __NEED_PusTmSourceData_NATIVE
size_t Encode_NATIVE_PusTmSourceData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmSourceData *pSrc);
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

#ifdef __NEED_PusStepId_UPER
size_t Encode_UPER_PusStepId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusStepId *pSrc);
#endif

#ifdef __NEED_PusStepId_ACN
size_t Encode_ACN_PusStepId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusStepId *pSrc);
#endif

#ifdef __NEED_PusStepId_NATIVE
size_t Encode_NATIVE_PusStepId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusStepId *pSrc);
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

#ifdef __NEED_PusSubserviceType_UPER
size_t Encode_UPER_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSubserviceType *pSrc);
#endif

#ifdef __NEED_PusSubserviceType_ACN
size_t Encode_ACN_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSubserviceType *pSrc);
#endif

#ifdef __NEED_PusSubserviceType_NATIVE
size_t Encode_NATIVE_PusSubserviceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSubserviceType *pSrc);
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

#ifdef __NEED_PusSt20OnBoardParameterId_UPER
size_t Encode_UPER_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20OnBoardParameterId *pSrc);
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_ACN
size_t Encode_ACN_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt20OnBoardParameterId *pSrc);
#endif

#ifdef __NEED_PusSt20OnBoardParameterId_NATIVE
size_t Encode_NATIVE_PusSt20OnBoardParameterId(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt20OnBoardParameterId *pSrc);
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

#ifdef __NEED_PusTC_23_14_Data_UPER
size_t Encode_UPER_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_14_Data *pSrc);
#endif

#ifdef __NEED_PusTC_23_14_Data_ACN
size_t Encode_ACN_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_23_14_Data *pSrc);
#endif

#ifdef __NEED_PusTC_23_14_Data_NATIVE
size_t Encode_NATIVE_PusTC_23_14_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_23_14_Data *pSrc);
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

#ifdef __NEED_PusTmHeader_UPER
size_t Encode_UPER_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeader *pSrc);
#endif

#ifdef __NEED_PusTmHeader_ACN
size_t Encode_ACN_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTmHeader *pSrc);
#endif

#ifdef __NEED_PusTmHeader_NATIVE
size_t Encode_NATIVE_PusTmHeader(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTmHeader *pSrc);
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

#ifdef __NEED_PusTC_19_1_Data_UPER
size_t Encode_UPER_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_19_1_Data_ACN
size_t Encode_ACN_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_19_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_19_1_Data_NATIVE
size_t Encode_NATIVE_PusTC_19_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_19_1_Data *pSrc);
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

#ifdef __NEED_T_UInt32_UPER
size_t Encode_UPER_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_ACN
size_t Encode_ACN_T_UInt32(void *pBuffer, size_t iMaxBufferSize, asn1SccT_UInt32 *pSrc);
#endif

#ifdef __NEED_T_UInt32_NATIVE
size_t Encode_NATIVE_T_UInt32(void *pBuffer, size_t iMaxBufferSize, const asn1SccT_UInt32 *pSrc);
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

#ifdef __NEED_PusSequenceFlags_UPER
size_t Encode_UPER_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceFlags *pSrc);
#endif

#ifdef __NEED_PusSequenceFlags_ACN
size_t Encode_ACN_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSequenceFlags *pSrc);
#endif

#ifdef __NEED_PusSequenceFlags_NATIVE
size_t Encode_NATIVE_PusSequenceFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSequenceFlags *pSrc);
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

#ifdef __NEED_PusSt03StoredParam_UPER
size_t Encode_UPER_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03StoredParam *pSrc);
#endif

#ifdef __NEED_PusSt03StoredParam_ACN
size_t Encode_ACN_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt03StoredParam *pSrc);
#endif

#ifdef __NEED_PusSt03StoredParam_NATIVE
size_t Encode_NATIVE_PusSt03StoredParam(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt03StoredParam *pSrc);
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

#ifdef __NEED_PusUInt4_UPER
size_t Encode_UPER_PusUInt4(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt4 *pSrc);
#endif

#ifdef __NEED_PusUInt4_ACN
size_t Encode_ACN_PusUInt4(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt4 *pSrc);
#endif

#ifdef __NEED_PusUInt4_NATIVE
size_t Encode_NATIVE_PusUInt4(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt4 *pSrc);
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

#ifdef __NEED_PusSt01FailureCode_UPER
size_t Encode_UPER_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureCode *pSrc);
#endif

#ifdef __NEED_PusSt01FailureCode_ACN
size_t Encode_ACN_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt01FailureCode *pSrc);
#endif

#ifdef __NEED_PusSt01FailureCode_NATIVE
size_t Encode_NATIVE_PusSt01FailureCode(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt01FailureCode *pSrc);
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

#ifdef __NEED_PusTC_8_1_Data_UPER
size_t Encode_UPER_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_8_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_8_1_Data_ACN
size_t Encode_ACN_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_8_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_8_1_Data_NATIVE
size_t Encode_NATIVE_PusTC_8_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_8_1_Data *pSrc);
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

#ifdef __NEED_PusPacketReduced_UPER
size_t Encode_UPER_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketReduced *pSrc);
#endif

#ifdef __NEED_PusPacketReduced_ACN
size_t Encode_ACN_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketReduced *pSrc);
#endif

#ifdef __NEED_PusPacketReduced_NATIVE
size_t Encode_NATIVE_PusPacketReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketReduced *pSrc);
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

#ifdef __NEED_PusVersionNumber_UPER
size_t Encode_UPER_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusVersionNumber *pSrc);
#endif

#ifdef __NEED_PusVersionNumber_ACN
size_t Encode_ACN_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, asn1SccPusVersionNumber *pSrc);
#endif

#ifdef __NEED_PusVersionNumber_NATIVE
size_t Encode_NATIVE_PusVersionNumber(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusVersionNumber *pSrc);
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

#ifdef __NEED_PusUInt8_UPER
size_t Encode_UPER_PusUInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt8 *pSrc);
#endif

#ifdef __NEED_PusUInt8_ACN
size_t Encode_ACN_PusUInt8(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt8 *pSrc);
#endif

#ifdef __NEED_PusUInt8_NATIVE
size_t Encode_NATIVE_PusUInt8(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt8 *pSrc);
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

#ifdef __NEED_PusTC_12_1_2_Data_UPER
size_t Encode_UPER_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_12_1_2_Data *pSrc);
#endif

#ifdef __NEED_PusTC_12_1_2_Data_ACN
size_t Encode_ACN_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_12_1_2_Data *pSrc);
#endif

#ifdef __NEED_PusTC_12_1_2_Data_NATIVE
size_t Encode_NATIVE_PusTC_12_1_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_12_1_2_Data *pSrc);
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

#ifdef __NEED_PusInt64_UPER
size_t Encode_UPER_PusInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt64 *pSrc);
#endif

#ifdef __NEED_PusInt64_ACN
size_t Encode_ACN_PusInt64(void *pBuffer, size_t iMaxBufferSize, asn1SccPusInt64 *pSrc);
#endif

#ifdef __NEED_PusInt64_NATIVE
size_t Encode_NATIVE_PusInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusInt64 *pSrc);
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

#ifdef __NEED_PusTC_11_4_Data_UPER
size_t Encode_UPER_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_11_4_Data *pSrc);
#endif

#ifdef __NEED_PusTC_11_4_Data_ACN
size_t Encode_ACN_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_11_4_Data *pSrc);
#endif

#ifdef __NEED_PusTC_11_4_Data_NATIVE
size_t Encode_NATIVE_PusTC_11_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_11_4_Data *pSrc);
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

#ifdef __NEED_PusTM_1_X_Data_UPER
size_t Encode_UPER_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_1_X_Data *pSrc);
#endif

#ifdef __NEED_PusTM_1_X_Data_ACN
size_t Encode_ACN_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_1_X_Data *pSrc);
#endif

#ifdef __NEED_PusTM_1_X_Data_NATIVE
size_t Encode_NATIVE_PusTM_1_X_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_1_X_Data *pSrc);
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

#ifdef __NEED_PusAcknowledgementFlags_UPER
size_t Encode_UPER_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusAcknowledgementFlags *pSrc);
#endif

#ifdef __NEED_PusAcknowledgementFlags_ACN
size_t Encode_ACN_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, asn1SccPusAcknowledgementFlags *pSrc);
#endif

#ifdef __NEED_PusAcknowledgementFlags_NATIVE
size_t Encode_NATIVE_PusAcknowledgementFlags(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusAcknowledgementFlags *pSrc);
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

#ifdef __NEED_PusSt09ExponentialRate_UPER
size_t Encode_UPER_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt09ExponentialRate *pSrc);
#endif

#ifdef __NEED_PusSt09ExponentialRate_ACN
size_t Encode_ACN_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt09ExponentialRate *pSrc);
#endif

#ifdef __NEED_PusSt09ExponentialRate_NATIVE
size_t Encode_NATIVE_PusSt09ExponentialRate(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt09ExponentialRate *pSrc);
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

#ifdef __NEED_PusTM_9_2_Data_UPER
size_t Encode_UPER_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_9_2_Data *pSrc);
#endif

#ifdef __NEED_PusTM_9_2_Data_ACN
size_t Encode_ACN_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTM_9_2_Data *pSrc);
#endif

#ifdef __NEED_PusTM_9_2_Data_NATIVE
size_t Encode_NATIVE_PusTM_9_2_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTM_9_2_Data *pSrc);
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

#ifdef __NEED_PusPacketData_UPER
size_t Encode_UPER_PusPacketData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketData *pSrc);
#endif

#ifdef __NEED_PusPacketData_ACN
size_t Encode_ACN_PusPacketData(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketData *pSrc);
#endif

#ifdef __NEED_PusPacketData_NATIVE
size_t Encode_NATIVE_PusPacketData(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketData *pSrc);
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

#ifdef __NEED_PusServiceType_UPER
size_t Encode_UPER_PusServiceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusServiceType *pSrc);
#endif

#ifdef __NEED_PusServiceType_ACN
size_t Encode_ACN_PusServiceType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusServiceType *pSrc);
#endif

#ifdef __NEED_PusServiceType_NATIVE
size_t Encode_NATIVE_PusServiceType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusServiceType *pSrc);
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

#ifdef __NEED_PusUInt64_UPER
size_t Encode_UPER_PusUInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt64 *pSrc);
#endif

#ifdef __NEED_PusUInt64_ACN
size_t Encode_ACN_PusUInt64(void *pBuffer, size_t iMaxBufferSize, asn1SccPusUInt64 *pSrc);
#endif

#ifdef __NEED_PusUInt64_NATIVE
size_t Encode_NATIVE_PusUInt64(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusUInt64 *pSrc);
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

#ifdef __NEED_PusPacketType_UPER
size_t Encode_UPER_PusPacketType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketType *pSrc);
#endif

#ifdef __NEED_PusPacketType_ACN
size_t Encode_ACN_PusPacketType(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketType *pSrc);
#endif

#ifdef __NEED_PusPacketType_NATIVE
size_t Encode_NATIVE_PusPacketType(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketType *pSrc);
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

#ifdef __NEED_PusSt23RepositoryPath_UPER
size_t Encode_UPER_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryPath *pSrc);
#endif

#ifdef __NEED_PusSt23RepositoryPath_ACN
size_t Encode_ACN_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23RepositoryPath *pSrc);
#endif

#ifdef __NEED_PusSt23RepositoryPath_NATIVE
size_t Encode_NATIVE_PusSt23RepositoryPath(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23RepositoryPath *pSrc);
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

#ifdef __NEED_PusTC_18_1_Data_UPER
size_t Encode_UPER_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_1_Data_ACN
size_t Encode_ACN_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_18_1_Data *pSrc);
#endif

#ifdef __NEED_PusTC_18_1_Data_NATIVE
size_t Encode_NATIVE_PusTC_18_1_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_18_1_Data *pSrc);
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

#ifdef __NEED_PusSt23FileName_UPER
size_t Encode_UPER_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23FileName *pSrc);
#endif

#ifdef __NEED_PusSt23FileName_ACN
size_t Encode_ACN_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, asn1SccPusSt23FileName *pSrc);
#endif

#ifdef __NEED_PusSt23FileName_NATIVE
size_t Encode_NATIVE_PusSt23FileName(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusSt23FileName *pSrc);
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

#ifdef __NEED_PusPacketDataReduced_UPER
size_t Encode_UPER_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataReduced *pSrc);
#endif

#ifdef __NEED_PusPacketDataReduced_ACN
size_t Encode_ACN_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, asn1SccPusPacketDataReduced *pSrc);
#endif

#ifdef __NEED_PusPacketDataReduced_NATIVE
size_t Encode_NATIVE_PusPacketDataReduced(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusPacketDataReduced *pSrc);
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

#ifdef __NEED_PusTC_TM_23_1_4_Data_UPER
size_t Encode_UPER_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_23_1_4_Data *pSrc);
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_ACN
size_t Encode_ACN_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, asn1SccPusTC_TM_23_1_4_Data *pSrc);
#endif

#ifdef __NEED_PusTC_TM_23_1_4_Data_NATIVE
size_t Encode_NATIVE_PusTC_TM_23_1_4_Data(void *pBuffer, size_t iMaxBufferSize, const asn1SccPusTC_TM_23_1_4_Data *pSrc);
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


#endif
