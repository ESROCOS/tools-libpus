#ifndef PUS_BINDINGFUNCTIONS_HPP
#define PUS_BINDINGFUNCTIONS_HPP
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include "pus_packet.h"
#include "pus_apid.h"
#include "pus_st01_packets.h"
#include "pus_st03_packets.h"
#include "pus_st05_packets.h"
#include "pus_st08_packets.h"
#include "pus_st17_packets.h"
#include "pus_st19_packets.h"
#include "pus_events.h"

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;


pusError_t pus_initApidInfo_(pusApidInfo_t* obj, pusApid_t apid);
uint pus_getPacketVersion_(const pusPacket_t* packet);
uint pus_getPacketType_(const pusPacket_t* packet);
uint pus_getSequenceFlags_(const pusPacket_t* packet);
uint pus_getTmPusVersion_(const pusPacket_t* packet);
uint pus_getTcPusVersion_(const pusPacket_t* packet);
time_t pus_getTmPacketTime_(const pusPacket_t* packet);
uint pus_tm_1_X_getPacketVersionNumber_(pusPacket_t *tm);
uint pus_tm_1_X_getPacketType_(pusPacket_t* tm);
uint pus_tm_1_X_getSequenceFlags_(pusPacket_t* tm);
ll pus_tm_1_X_getFailureCode_(const pusPacket_t *tm);


ll pus_getSt01FailureSubcode_(const pusPacket_t *tm);
ll pus_getSt01FailureData_(const pusPacket_t *tm);
ull pus_getSt01FailureAddress_(const pusPacket_t *tm);
pusError_t pus_hk_initialize_null_();


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

pusError_t pus_tm_5_X_createEventReport_(pusPacket_t* outTm, pusApidInfo_t* apid, const st05Event* event, pusApid_t destination, pusSubservice_t subtype);
pusError_t pus_tm_5_1_createInformativeEventReport_(pusPacket_t* outTm, pusApidInfo_t* apid, const st05Event* event, pusApid_t destination);
pusError_t pus_tm_5_2_createLowSeverityEventReport_(pusPacket_t* outTm, pusApidInfo_t* apid, const st05Event* event, pusApid_t destination);
pusError_t pus_tm_5_3_createMediumSeverityEventReport_(pusPacket_t* outTm, pusApidInfo_t* apid, const st05Event* event, pusApid_t destination);
pusError_t pus_tm_5_4_createHighSeverityEventReport_(pusPacket_t* outTm, pusApidInfo_t* apid, const st05Event* event, pusApid_t destination);

pusError_t pus_tm_get_5_X_event_id_(const pusPacket_t *packet, ull *eventId);
pusError_t pus_tm_get_5_X_event_auxdata1_(const pusPacket_t *packet, ull *auxdata1);
pusError_t pus_tm_get_5_X_event_auxdata2_(const pusPacket_t *packet, ull *auxdata2);
pusError_t pus_events_initialize_null_();

#endif
