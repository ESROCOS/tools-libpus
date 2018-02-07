//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS Packet Queues configuration
// 
// File automatically generated from the pus_packet_queues_config.c.mako template
//
//                     -- DO NOT MODIFY --


#include "pus_packet_queues_config.h"
#include "pus_threads.h"

pusPacketQueue_t pus_packetQueue_table[PUS_PACKET_QUEUES_LIMIT];

const pusPacketQueueId_t pus_packetQueue_tableLenght = PUS_PACKET_QUEUES_LIMIT;

% for queue in config['queues']:
pusPacket_t pus_packetQueue_buffer${queue['label']}[${queue['length']}];
% if config['isTasteFlag'] != 1:
pusMutex_t pus_packetQueue_mutex${queue['label']};
% endif
	
% endfor



pusError_t pus_packetQueues_configure()
{
	% for queue in config['queues']:
	pus_packetQueue_table[${queue['label']}].buffer = pus_packetQueue_buffer${queue['label']};
	pus_packetQueue_table[${queue['label']}].length = ${queue['length']};
	pus_packetQueue_table[${queue['label']}].out = 0;
	pus_packetQueue_table[${queue['label']}].nPacketInside = 0;
	% if config['isTasteFlag'] != 1:
	pus_mutexInitOk(&pus_packetQueue_mutex${queue['label']});
	pus_packetQueue_table[${queue['label']}].mutex = &pus_packetQueue_mutex${queue['label']}; 
	% else:
	pus_packetQueue_table[${queue['label']}].mutex = NULL;
	% endif
	
	% endfor
	
	return PUS_NO_ERROR;
}

