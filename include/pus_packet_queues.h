/*! \file pus_packet_queues.h
 *  \brief Functions for managing PUS TM/TC packets queues.
 *
 *  This module contains functions to
 *
 *  \author GMV
 */

#ifndef PUS_PACKET_QUEUES
#define PUS_PACKET_QUEUES


#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_stored_param.h"
#include "pus_types.h"

typedef struct{
	pusPacket_t * buffer;
	size_t length;
	size_t in;
	size_t out;
}pusPacketQueue_t;

//! Flag to check if the
bool pus_packetQueues_initializedFlag = false;

extern pusError_t pus_packetQueues_configure(); //TODO necesario


//! Initialize the packet queues (TM and TC)
/*! Initialize the packet queues (TM and TC)
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_packetQueues_initialize();


//! Chech if the queues are initialized
bool pus_packetQueues_isInitialized();


//! Push a packet into its queue
/*! Push a packet into its queue checking if it is possible
 *  \param[in] inPacket Packet that is going to be pushed
 *  \param queue Queue where the packet is going to be pushed
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_packetQueues_push(const pusPacket_t * inPacket, pusPacketQueue_t * queue);


//! Pop packet from its queue
/*! Pop packet from its queue checking if it is possible
 * 	\param[out] outPacket Packet that is going to be popped
 * 	\param queue Queue where the packet is going to be popped
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_packetQueues_pop(pusPacket_t *outPacket, pusPacketQueue_t * queue);

#endif
