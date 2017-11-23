// PUS Packet Queues configuration
// 
// File automatically generated from the pus_packet_queues_config.c.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_packet_queues_config.h"
#include "pus_threads.h"

pusPacketQueue_t pus_packetQueue_tc;

pusPacketQueue_t pus_packetQueue_tm;

pusPacket_t pus_packetQueue_buffer_tc[${config['tcPacketQueueLength']}];

pusPacket_t pus_packetQueue_buffer_tm[${config['tmPacketQueueLength']}];

% if config['isTasteFlag'] == 1:
pusMutex_t mutex_packetQueue_tc;
pusMutex_t mutex_packetQueue_tm;
% endif

pusError_t pus_packetQueues_configure()
{
	pus_packetQueue_tc.buffer = pus_packetQueue_buffer_tc;
	pus_packetQueue_tc.length = ${config['tcPacketQueueLength']};
	pus_packetQueue_tc.out = 0;
	pus_packetQueue_tc.nPacketInside = 0;
	% if config['isTasteFlag'] == 1:
	pus_mutexInitOk(&mutex_packetQueue_tc);
	pus_packetQueue_tc.mutex = &mutex_packetQueue_tc; 
	% else:
	pus_packetQueue_tc.mutex = NULL;
	% endif
	
	
	pus_packetQueue_tm.buffer = pus_packetQueue_buffer_tm;
	pus_packetQueue_tm.length = ${config['tmPacketQueueLength']};
	pus_packetQueue_tm.out = 0;
	pus_packetQueue_tm.nPacketInside = 0;
    % if config['isTasteFlag'] == 1:
    pus_mutexInitOk(&mutex_packetQueue_tm);
	pus_packetQueue_tm.mutex = &mutex_packetQueue_tm; 
	% else:
	pus_packetQueue_tm.mutex = NULL;
	% endif
	
	return PUS_NO_ERROR;
}

