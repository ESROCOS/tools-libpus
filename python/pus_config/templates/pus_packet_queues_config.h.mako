// PUS Packet Queues configuration
// 
// File automatically generated from the pus_packet_queues_config.h.mako template
//
//                     -- DO NOT MODIFY --

#ifndef PUS_PACKET_QUEUES_CONFIG_H
#define PUS_PACKET_QUEUES_CONFIG_H

#include "pus_error.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

extern pusPacketQueue_t pus_packetQueue_tc;

extern pusPacketQueue_t pus_packetQueue_tm;

extern pusPacket_t pus_packetQueue_buffer_tc[];

extern pusPacket_t pus_packetQueue_buffer_tm[];


//! Initialize the configuration of the packet queues from the mission database
pusError_t pus_packetQueues_configure();






#endif