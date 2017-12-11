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
#include "pus_st12_packets.h"
#include "pus_st17_packets.h"
#include "pus_st19_packets.h"


#include "pus_events.h"
#include "pus_housekeeping.h"
#include "pus_event_action.h"
#include "pus_parameter_monitoring.h"

#include "pus_packet_queues_config.h"
#include "pus_st03_config.h"
#include "pus_st05_config.h"
#include "pus_st08_config.h"
#include "pus_st12_config.h"



//st08
pusError_t pus_st08_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid);

//st12
pusError_t pus_st12_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid);
pusError_t pus_st12_processPmonDefinitions();

//st17
pusError_t pus_st17_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid);

//st19
pusError_t pus_st19_processEventAction();
pusError_t pus_st19_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid);



#endif
