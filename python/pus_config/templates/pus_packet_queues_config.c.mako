// PUS Packet Queues configuration
// 
// File automatically generated from the pus_packet_queues_config.c.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_packet_queues_config.h"

pusPacketQueue_t pus_packetQueue_tc;

pusPacketQueue_t pus_packetQueue_tm;

pusPacket_t pus_packetQueue_buffer_tc[${config['tcPacketQueueLength']}];

pusPacket_t pus_packetQueue_buffer_tm[${config['tmPacketQueueLength']}];


pusError_t pus_packetQueues_configure()
{
	pus_packetQueue_tc.buffer = pus_packetQueue_buffer_tc;
	pus_packetQueue_tc.length = ${config['tcPacketQueueLength']+1};
	pus_packetQueue_tc.in = 0;
	pus_packetQueue_tc.out = 0;
	
	
	pus_packetQueue_tm.buffer = pus_packetQueue_buffer_tm;
	pus_packetQueue_tm.length = ${config['tmPacketQueueLength']+1};
	pus_packetQueue_tm.in = 0;
	pus_packetQueue_tm.out = 0;
    
	
	return PUS_NO_ERROR;
}

