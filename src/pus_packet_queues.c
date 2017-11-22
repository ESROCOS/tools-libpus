
#include "pus_packet_queues.h"

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_stored_param.h"
#include "pus_types.h"




//from config
//! PacketQueue for TC packets
extern pusPacketQueue_t pus_packetQueue_tc;

//! PacketQueue for TM packets
extern pusPacketQueue_t pus_packetQueue_tm;


pusError_t pus_packetQueues_initialize() {

	if ( pus_packetQueues_isInitialized() )
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	if ( PUS_NO_ERROR != pus_packetQueues_configure() )
	{
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	pus_packetQueues_initializedFlag = true;
	return PUS_NO_ERROR;
}

bool pus_packetQueues_isInitialized()
{
	return pus_packetQueues_initializedFlag;
}

pusError_t pus_packetQueues_push(const pusPacket_t * inPacket, pusPacketQueue_t * queue)
{
	if( NULL == inPacket || NULL == queue )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( ! pus_packetQueues_isInitialized() )
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	if ( ((queue->in + 1) % queue->length) == queue->out )
	{
		return PUS_SET_ERROR(PUS_ERROR_FULL_QUEUE);
	}

	queue->buffer[queue->in] = *inPacket;
	queue->in = (queue->in + 1) % queue->length;

	return PUS_NO_ERROR;
}

pusError_t pus_packetQueues_pop(pusPacket_t * inPacket, pusPacketQueue_t * queue)
{
	if( NULL == inPacket || NULL == queue )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( ! pus_packetQueues_isInitialized() )
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	if( queue->in == queue->out )
	{
		return PUS_SET_ERROR(PUS_ERROR_EMPTY_QUEUE);
	}

	*inPacket = queue->buffer[queue->out];
	queue->out = (queue->out + 1) % queue->length;

	return PUS_NO_ERROR;
}


