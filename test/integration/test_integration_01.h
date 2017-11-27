#ifndef TEST_INTEGRATION_01_H
#define TEST_INTEGRATION_01_H


#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "pus_st01_packets.h"
#include "pus_st03_packets.h"
#include "pus_st05_packets.h"
#include "pus_st08_packets.h"
#include "pus_st17_packets.h"

#include "pus_events.h"
#include "pus_housekeeping.h"

#include "pus_packet_queues_config.h"
#include "pus_st03_config.h"
#include "pus_st05_config.h"
#include "pus_st08_config.h"

//st08
pusError_t pus_st08_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid);

//st17
pusError_t pus_st17_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid);



//st01 ?
pusError_t pus_pushTmAceptanceReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isST07TcFlag, pusError_t error);
pusError_t pus_pushTmCompletionReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isST07TcFlag, pusError_t error);
pusError_t pus_pushTmProgressReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error, pusStepId_t step);
pusError_t pus_pushTmCompletionReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error);


#endif
