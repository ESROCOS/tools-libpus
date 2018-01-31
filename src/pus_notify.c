/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_notify.h"

pusPacket_t receivedPacket;
pusMutex_t receivedMutex;

pusPacket_t pus_notify_getPacket()
{
	return receivedPacket;
}

void pus_notify_setPacket(pusPacket_t* packet)
{
	receivedPacket = *packet;
}

void pus_notify_getMutex(pusMutex_t *mutex)
{
	*mutex = receivedMutex;
}

void pus_notify_setMutex(pusMutex_t mutex)
{
	receivedMutex = mutex;
}
