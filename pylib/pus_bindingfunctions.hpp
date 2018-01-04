#ifndef PUS_BINDINGFUNCTIONS_HPP
#define PUS_BINDINGFUNCTIONS_HPP
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include "pus_packet.h"
#include "pus_apid.h"
#include "pus_time.h"
#include "pus_st01_packets.h"
#include "pus_st03_packets.h"
#include "pus_st05_packets.h"
#include "pus_st08_packets.h"
#include "pus_st09_packets.h"
#include "pus_st12_packets.h"
#include "pus_st17_packets.h"
#include "pus_st19_packets.h"
#include "pus_events.h"
#include <time.h>

typedef unsigned int uint;
typedef unsigned long long int ull;
typedef long long int ll;

int ret_packets(pusPacket_t *tm, int i);

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

pusError_t pus_tm_get_5_X_event_id_(const pusPacket_t *packet, ull *eventId);
pusError_t pus_tm_get_5_X_event_auxdata1_(const pusPacket_t *packet, ull *auxdata1);
pusError_t pus_tm_get_5_X_event_auxdata2_(const pusPacket_t *packet, ull *auxdata2);
pusError_t pus_events_initialize_null_();

pusSt08FunctiontId_t pus_tc_8_1_getFunctionId_(pusPacket_t *packet);

pusSt12PmonId_t  pus_tc_12_1_2_getPmonId_(pusPacket_t* tcPacket);

pusSt09ExponentialRate_t pus_tc_9_1_getExponentialRate_(pusPacket_t* tcPacket);

#endif
