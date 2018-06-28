/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_packet_queues.h"

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include <stdio.h>

//! Table of packetQueues
extern pusPacketQueue_t pus_packetQueue_table[];

//! Size of the packetQueues table
extern const pusPacketQueueId_t pus_packetQueue_tableLenght;


//! Flag to check if the
bool pus_packetQueues_initializedFlag = false;


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

pusError_t pus_packetQueues_push(const pusPacket_t * inPacket, pusPacketQueueId_t queueId)
{
	if( NULL == inPacket )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if( ! pus_packetQueues_isInitialized() )
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if( queueId >= pus_packetQueue_tableLenght )
	{
		printf("PUSH %llu %llu\n", queueId, pus_packetQueue_tableLenght);
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}

	return pus_packetQueues_pushGeneric(inPacket,  &pus_packetQueue_table[queueId]);
}

pusError_t pus_packetQueues_pop(pusPacket_t * outPacket, pusPacketQueueId_t queueId)
{
	if( NULL == outPacket )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if( ! pus_packetQueues_isInitialized() )
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else if( queueId >= pus_packetQueue_tableLenght )
	{
		printf("POP %llu %llu\n", queueId, pus_packetQueue_tableLenght);
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}

	return pus_packetQueues_popGeneric(outPacket,  &pus_packetQueue_table[queueId]);
}

pusError_t pus_packetQueues_pushGeneric(const pusPacket_t * inPacket, pusPacketQueue_t * queue)
{
	if( NULL == inPacket || NULL == queue )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (NULL != queue->mutex && !pus_mutexLockOk(queue->mutex))
	{
		return PUS_ERROR_THREADS;
	}

	pusError_t error = PUS_NO_ERROR;
	if( NULL == queue->buffer )
	{
		error = PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		if ( queue->length == queue->nPacketInside )
		{
			error = PUS_SET_ERROR(PUS_ERROR_FULL_QUEUE);
		}
		else
		{
			queue->buffer[(queue->out + queue->nPacketInside) % queue->length] = *inPacket;
			queue->nPacketInside = (queue->nPacketInside + 1);
		}
	}

	if (NULL != queue->mutex && !pus_mutexUnlockOk(queue->mutex))
	{
		return PUS_ERROR_THREADS;
	}

	return error;
}

pusError_t pus_packetQueues_popGeneric(pusPacket_t * outPacket, pusPacketQueue_t * queue)
{
	if( NULL == outPacket || NULL == queue )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (NULL != queue->mutex && !pus_mutexLockOk(queue->mutex))
	{
		return PUS_ERROR_THREADS;
	}

	pusError_t error = PUS_NO_ERROR;
	if( NULL == queue->buffer )
	{
		error = PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		if( 0 == queue->nPacketInside )
		{
			error = PUS_SET_ERROR(PUS_ERROR_EMPTY_QUEUE);
		}
		else
		{
			*outPacket = queue->buffer[queue->out];
			queue->out = (queue->out + 1) % queue->length;
			queue->nPacketInside = queue->nPacketInside - 1;
		}
	}

	if (NULL != queue->mutex && !pus_mutexUnlockOk(queue->mutex))
	{
		return PUS_ERROR_THREADS;
	}

	return error;
}

