//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS Packet Queues configuration
// 
// File automatically generated from the pus_packet_queues_config.h.mako template
//
//                     -- DO NOT MODIFY --


#ifndef PUS_PACKET_QUEUES_CONFIG_H
#define PUS_PACKET_QUEUES_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif


#include "pus_error.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

<% count = 0 %>
% for queue in config['queues']:
#define ${queue['label']} ((pusPacketQueueId_t) ${count})
const pusPacketQueueId_t pus_${queue['label']} = ${count};

<% count = count + 1 %>
% endfor
#define PUS_PACKET_QUEUES_LIMIT ((pusPacketQueueId_t) ${count})

//! Table of packetQueues
extern pusPacketQueue_t pus_packetQueue_table[];

//! Size of the packetQueues table
extern const pusPacketQueueId_t pus_packetQueue_tableLenght;

//! Initialize the configuration of the pusPackets queues from mission
pusError_t pus_packetQueues_configure();

#ifdef __cplusplus
}
#endif


#endif