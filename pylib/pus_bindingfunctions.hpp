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

#endif
