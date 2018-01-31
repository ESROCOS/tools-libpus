/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_apid.h"
#include "pus_packet.h"


pusError_t pus_initApidInfo(pusApidInfo_t* obj, pusApid_t apid, pusMutex_t* mutex)
{
	if (NULL == obj)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		obj->apid = apid;
		obj->packetCount = 0;
		obj->mutex = mutex;

		return PUS_NO_ERROR;
	}
}

pusApid_t pus_getInfoApid(const pusApidInfo_t* obj)
{
	if (NULL == obj)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return pus_APID_IDLE;
	}
	else
	{
		return obj->apid;
	}
}

pusSequenceCount_t pus_getNextPacketCount(pusApidInfo_t* obj)
{
	if (NULL == obj)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return 0;
	}
	else
	{
		int next = 0;

		if (NULL != obj->mutex && !pus_mutexLockOk(obj->mutex))
		{
			// PUS_SET_ERROR called by pus_mutexLock
			return 0;
		}

		// Get next and increment with function to wrap counter if needed
		next = obj->packetCount;
		obj->packetCount = pus_incrementSequenceCount(obj->packetCount);

		if (NULL != obj->mutex)
		{
			(void) pus_mutexUnlockOk(obj->mutex);
			// PUS_SET_ERROR called by pus_mutexLock; if error, continue and return next
		}

		return next;
	}
}

