/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

#ifndef PUS_BINDINGFUNCTIONS_HPP
#define PUS_BINDINGFUNCTIONS_HPP
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "pus_packet.h"
#include "pus_apid.h"
#include "pus_time.h"
#include "pus_st01_packets.h"
#include "pus_st03_packets.h"
#include "pus_st05_packets.h"
#include "pus_st08_packets.h"
#include "pus_st09_packets.h"
#include "pus_st11_packets.h"
#include "pus_st12_packets.h"
#include "pus_st17_packets.h"
#include "pus_st18_packets.h"
#include "pus_st19_packets.h"
#include "pus_st20_packets.h"
#include "pus_st23_packets.h"
#include "pus_st03_config.h"
#include "pus_st05_config.h"
#include "pus_st20_config.h"
#include "pus_events.h"
#include "pus_threads.h"
#include "pus_notify.h"
#include <vector>

typedef unsigned int uint;
typedef unsigned long long int ull;
typedef long long int ll;

time_t pus_time2posix_(pusTime_t* outPusTime);
pusTime_t pus_posix2time_(time_t time);

pusError_t pus_initApidInfo_null(pusApidInfo_t* obj, pusApid_t apid);
uint pus_getPacketVersion_(const pusPacket_t* packet);
void pus_setPacketVersion_(pusPacket_t* packet, uint version);
uint pus_getPacketType_(const pusPacket_t* packet);
void pus_setPacketType_(pusPacket_t *packet, uint type_);
uint pus_getSequenceFlags_(const pusPacket_t* packet);
void pus_setSequenceFlags_(pusPacket_t *packet, uint seqflags);
uint pus_getTmPusVersion_(const pusPacket_t* packet);
void pus_setTmPusVersion_(pusPacket_t *packet, uint version);
uint pus_getTcPusVersion_(const pusPacket_t* packet);
void pus_setTcPusVersion_(pusPacket_t *packet, uint version);
time_t pus_getTmPacketTime_(const pusPacket_t* packet);
void pus_setTmPacketTime_(pusPacket_t *packet, time_t time_);

uint pus_tm_1_X_getPacketVersionNumber_(pusPacket_t *tm);
void pus_tm_1_X_setPacketVersionNumber_(pusPacket_t *tm, uint version);
uint pus_tm_1_X_getPacketType_(pusPacket_t* tm);
void pus_tm_1_X_setPacketType_(pusPacket_t* tm, uint type);
uint pus_tm_1_X_getSequenceFlags_(pusPacket_t* tm);
void pus_tm_1_X_setSequenceFlags_(pusPacket_t* tm, uint seq_flags);
ull pus_tm_1_X_getFailureCode_(const pusPacket_t *tm);
ll pus_getSt01FailureSubcode_(const pusPacket_t *tm);
ll pus_getSt01FailureData_(const pusPacket_t *tm);
ull pus_getSt01FailureAddress_(const pusPacket_t *tm);
void pus_setSt01FailureInfo_(pusPacket_t *tm, ull code, ll subcode, ll data, ull address);

pusError_t pus_hk_initialize_null_();
pusStoredParam_t pus_tm_3_25_getParameterValue_(const pusPacket_t* tm, size_t index);
size_t pus_tm_3_25_getNumParameters_(const pusPacket_t* tm);
char *pus_st03_getHkReportInfoName(pusSt03ParamId_t paramIndex);
pusParamType_t pus_st03_getHkReportInfoType(pusSt03ParamId_t paramIndex);
pusSt03ParamId_t pus_st03_getHkInfoNameFromReport(pusSt03HousekeepingReportId_t reportId, pusSt03ParamId_t reportIdx);

uint32_t pus_paramToUint32_(pusStoredParam_t paramValue);
int32_t pus_paramToInt32_(pusStoredParam_t paramValue);
double pus_paramToReal64_(pusStoredParam_t paramValue);
bool pus_paramToBool_(pusStoredParam_t paramValue);
std::string pus_paramToByte_(pusStoredParam_t paramValue);
pusStoredParam_t pus_uint32ToParam_(uint32_t inValue);
pusStoredParam_t pus_int32ToParam_(int32_t inValue);
pusStoredParam_t pus_real64ToParam_(double inValue);
pusStoredParam_t pus_boolToParam_(bool inValue);
pusStoredParam_t pus_byteToParam_(uint8_t inValue);

typedef struct
{
	ull event_id;
	struct{
		ull data1;
		ull data2;
	} auxdata;
}st05Event;

st05Event pus_event_init_struct_(ull event_id, ull auxdata1, ull auxdata2);
pusSt05Event_t parse_pusSt05EventStruct_(st05Event event);

pusError_t pus_tm_5_X_createEventReport_(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const st05Event* event, pusApid_t destination, pusSubservice_t subtype);
pusError_t pus_tm_5_1_createInformativeEventReport_(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const st05Event* event, pusApid_t destination);
pusError_t pus_tm_5_2_createLowSeverityEventReport_(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const st05Event* event, pusApid_t destination);
pusError_t pus_tm_5_3_createMediumSeverityEventReport_(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const st05Event* event, pusApid_t destination);
pusError_t pus_tm_5_4_createHighSeverityEventReport_(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const st05Event* event, pusApid_t destination);

ull pus_tm_get_5_X_event_id_(const pusPacket_t *packet);
ull pus_tm_get_5_X_event_auxdata1_(const pusPacket_t *packet);
ull pus_tm_get_5_X_event_auxdata2_(const pusPacket_t *packet);
char *pus_st05_getEventName(pusSt05EventId_t eventIndex);
pusSt05EventId_t pus_st05_getEventId(char *eventName);
int pus_st05_getDataType1(pusSt05EventId_t eventIndex);
int pus_st05_getDataType2(pusSt05EventId_t eventIndex);

pusSt08FunctiontId_t pus_tc_8_1_getFunctionId_(pusPacket_t *packet);

pusSt12PmonId_t  pus_tc_12_1_2_getPmonId_(pusPacket_t* tcPacket);

pusSt09ExponentialRate_t pus_tc_9_1_getExponentialRate_(pusPacket_t* tcPacket);
pusSt09ExponentialRate_t pus_tm_9_2_getDataField_(const pusPacket_t* tm, pusTime_t* time);

void pus_tc_11_4_get_request(long index, const pusPacket_t *inTc, pusPacket_t *outTc, long max);
time_t pus_tc_11_4_get_release_time(long index, const pusPacket_t *inTc, long max);

pusError_t pus_tc_18_1_createLoadObcpDirectRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char* obcpId, const std::vector<uint8_t>code, const size_t codelength);
pusError_t pus_tc_18_2_createUnloadObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char* id);
pusError_t pus_tc_18_3_createActivateObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char *id, int observability);
pusError_t pus_tc_18_4_createStopObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* id, pusSt18ObcpStepId_t step);
pusError_t pus_tc_18_5_createSuspendObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* id, pusSt18ObcpStepId_t step);
pusError_t pus_tc_18_6_createResumeObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char *obcpId);
pusError_t pus_tc_18_12_createAbortObcpRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char* id);
pusError_t pus_tc_18_13_createLoadObcpReferenceRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* id, const char* repository, const char* fileName);
pusError_t pus_tc_18_X_setObcpId_(pusPacket_t* outTc, const char* obcpId);
char *pus_tc_18_X_getObcpId_(char* id, const pusPacket_t* outTc);
pusError_t pus_tc_18_1_setObcpCode_(pusPacket_t* outTc, const std::vector<uint8_t> code, const size_t codelength);
std::vector<uint8_t> pus_tc_18_1_getObcpCode_(char* code, const pusPacket_t* outTc);
pusError_t pus_tc_18_3_setObservabilityLevel_(pusPacket_t* outTc, int observability);
int pus_tc_18_3_getObservabilityLevel_(const pusPacket_t* outTc);
pusSt18ObcpStepId_t pus_tc_18_4_5_getObcpStepId_(const pusPacket_t* outTc);
pusError_t pus_tc_18_13_setFileName_(pusPacket_t* outTc, const char* fileName);
char *pus_tc_18_13_getFileName_(char* fileName, const pusPacket_t* outTc);
pusError_t pus_tc_18_13_setRepositoryPath_(pusPacket_t* outTc, const char* repository);
char *pus_tc_18_13_getRepositoryPath_(char* repository, const pusPacket_t* outTc);

pusSt05EventId_t pus_tc_19_X_getEventId_(const pusPacket_t* outTc);

char *pus_st20_getOnBoardReportInfoName(pusSt20OnBoardParamId_t paramId);
pusParamType_t pus_st20_getOnBoardReportInfoType(pusSt20OnBoardParamId_t paramId);

pusError_t pus_tc_23_1_createCreateFileRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, std::string repository, std::string fileName, pusSt23MaximumSize_t maxSize);
pusError_t pus_tc_23_2_createDeleteFileRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char* repository, const char* fileName);
pusError_t pus_tc_23_3_createReportFileAtributesRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const char* repository, const char* fileName);
pusError_t pus_tc_23_14_createCopyFileRequest_(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const char* sourceRepository, const char* sourceFileName, const char* targetRepository, const char* targetFileName);

pusError_t pus_tc_tm_23_X_setFileName_(pusPacket_t* outTc, const char* file);
pusError_t pus_tc_tm_23_X_setRepositoryPath_(pusPacket_t* outTc, const char* repository);
pusError_t pus_tc_23_14_setSourceFileName_(pusPacket_t* outTc, const char* file);
pusError_t pus_tc_23_14_setTargetFileName_(pusPacket_t* outTc, const char* fileName);
pusError_t pus_tc_23_14_setSourceRepositoryPath_(pusPacket_t* outTc, const char* repository);
pusError_t pus_tc_23_14_setTargetRepositoryPath_(pusPacket_t* outTc, const char* repository);
char *pus_tc_tm_23_X_getRepositoryPath_(char* repository, const pusPacket_t* outTc);
char *pus_tc_tm_23_X_getFileName_(char* file, const pusPacket_t* outTc);
char *pus_tc_23_14_getSourceFileName_(const pusPacket_t* outTc);
char *pus_tc_23_14_getTargetFileName_(const pusPacket_t* outTc);
char *pus_tc_23_14_getSourceRepositoryPath_(const pusPacket_t* outTc);
char *pus_tc_23_14_getTargetRepositoryPath_(const pusPacket_t* outTc);
pusSt23MaximumSize_t pus_tc_tm_23_1_4_getMaximumSize_(const pusPacket_t* outTc);


#endif
