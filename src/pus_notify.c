/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "pus_notify.h"


#define PUS_BUFFER_QUEUE_LENGHT ((size_t) 10)

pusPacketQueue_t pus_queueTmGUI;
pusPacketQueue_t pus_queueTcGUI;

pusMutex_t tmGuiMutex; // needed to add/remove data from the buffer
pusMutex_t tcGuiMutex; // needed to add/remove data from the buffer

pusPacket_t bufferTmGui[PUS_BUFFER_QUEUE_LENGHT];
pusPacket_t bufferTcGui[PUS_BUFFER_QUEUE_LENGHT];

pusError_t pus_notify_initialize()
{
	if ( true != pus_mutexInitOk(&tmGuiMutex) )
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}
	if ( true != pus_mutexInitOk(&tcGuiMutex) )
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}

	pus_queueTmGUI.buffer = bufferTmGui;
	pus_queueTmGUI.length = PUS_BUFFER_QUEUE_LENGHT;
	pus_queueTmGUI.nPacketInside = 0;
	pus_queueTmGUI.out = 0;
	pus_queueTmGUI.mutex = &tmGuiMutex;

	pus_queueTcGUI.buffer = bufferTcGui;
	pus_queueTcGUI.length = PUS_BUFFER_QUEUE_LENGHT;
	pus_queueTcGUI.nPacketInside = 0;
	pus_queueTcGUI.out = 0;
	pus_queueTcGUI.mutex = &tcGuiMutex;

	printf("Notify init \n");

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_notify_finalize()
{
	if ( true != pus_mutexDestroyOk(&tmGuiMutex) )
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}
	if ( true != pus_mutexDestroyOk(&tcGuiMutex) )
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_notify_writeTm(pusPacket_t *packet)
{
	return pus_packetQueues_pushGeneric(packet, &pus_queueTmGUI);
}

pusError_t pus_notify_readTm(pusPacket_t *packet)
{
	return pus_packetQueues_popGeneric(packet, &pus_queueTmGUI);
}

pusError_t pus_notify_writeTc(pusPacket_t *packet)
{
	return pus_packetQueues_pushGeneric(packet, &pus_queueTcGUI);
}

pusError_t pus_notify_readTc(pusPacket_t *packet)
{
	return pus_packetQueues_popGeneric(packet, &pus_queueTcGUI);
}

pusError_t pus_notify_sendPacket(pusPacket_t *packet)
{
	return pus_notify_writeTc(packet);
}

size_t pus_notify_getTmQueueNumPackets()
{
	return pus_queueTmGUI.nPacketInside;
}


