/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_st19_packets.h"



pusError_t pus_tc_19_X_createDefaultEventActionRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount)
{
	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTcPacket(outTc);

		// Source information
		pus_setApid(outTc, apid);
		pus_setSequenceCount(outTc, sequenceCount);

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		pus_setTcService(outTc, pus_ST19_eventAction);
		pus_setTcSource(outTc, apid);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}



pusError_t pus_tc_19_1_createAddEventActionDefinitionsRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt05EventId_t eventId, pusPacket_t* tcAction)
{
	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( PUS_NO_ERROR !=  pus_tc_19_X_createDefaultEventActionRequest(outTc, apid, sequenceCount) )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcSubtype(outTc, pus_TC_19_1_addEventActionDefinitions);
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_19_1);

	pusPacketReduced_t tcActionR;
	pus_packetReduced_createPacketReducedFromPacket(&tcActionR, tcAction);

	pus_tc_19_1_setAction(outTc, &tcActionR);
	pus_tc_19_X_setEventId(outTc, eventId);
	return PUS_NO_ERROR;
}


pusError_t pus_tc_19_2_createDeleteEventActionDefinitionsRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt05EventId_t eventId)
{
	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( PUS_NO_ERROR !=  pus_tc_19_X_createDefaultEventActionRequest(outTc, apid, sequenceCount) )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcSubtype(outTc, pus_TC_19_2_deleteEventActionDefinitions);
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_19_X);

	pus_tc_19_X_setEventId(outTc, eventId);

	return PUS_NO_ERROR;
}

pusError_t pus_tc_19_4_createEnableEventActionDefinitions(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt05EventId_t eventId)
{
	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( PUS_NO_ERROR !=  pus_tc_19_X_createDefaultEventActionRequest(outTc, apid, sequenceCount) )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcSubtype(outTc, pus_TC_19_4_enableEventActionDefinitions);
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_19_X);

	pus_tc_19_X_setEventId(outTc, eventId);

	return PUS_NO_ERROR;
}

pusError_t pus_tc_19_5_createDisableEventActionDefinitions(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt05EventId_t eventId)
{
	if (NULL == outTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( PUS_NO_ERROR !=  pus_tc_19_X_createDefaultEventActionRequest(outTc, apid, sequenceCount) )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcSubtype(outTc, pus_TC_19_5_disableEventActionDefinitions);
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_19_X);

	pus_tc_19_X_setEventId(outTc, eventId);

	return PUS_NO_ERROR;
}


void pus_tc_19_1_setAction(pusPacket_t* outTc, pusPacketReduced_t* actionR)
{
    if ( NULL == outTc || NULL == actionR )
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return;
    }
    else
    {
    	outTc->data.u.tcData.data.u.st_19_1.packetReduced = *actionR;
    }
}

void pus_tc_19_1_getAction(pusPacketReduced_t* action, const pusPacket_t* tc)
{
    if ( NULL == tc)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return;
    }
    else
    {
    	*action = tc->data.u.tcData.data.u.st_19_1.packetReduced;
    }
}

pusError_t pus_tc_19_X_setEventId(pusPacket_t* packet, pusSt05EventId_t eventId)
{
	if ( NULL == packet )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( pus_getTcDataKind(packet) == pus_TC_DATA_ST_19_1)
	{
		packet->data.u.tcData.data.u.st_19_1.eventId = eventId;
	}
	else if( pus_TC_DATA_NONE != pus_getTcDataKind(packet) )
	{
		packet->data.u.tcData.data.u.st_19_X.eventId = eventId;
	}
	return PUS_NO_ERROR;
}

pusError_t pus_tc_19_X_getEventId(pusSt05EventId_t* eventID, const pusPacket_t* packet)
{
	if ( NULL == packet )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( pus_getTcDataKind(packet) == pus_TC_DATA_ST_19_1)
	{
		*eventID = packet->data.u.tcData.data.u.st_19_1.eventId;
	}
	else if( pus_TC_DATA_NONE != pus_getTcDataKind(packet) )
	{
		*eventID = packet->data.u.tcData.data.u.st_19_X.eventId;
	}
	return PUS_NO_ERROR;
}

//
// Parameter checking
//
pusError_t pus_expectSt19Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function)
{
	pusError_t expectResult = pus_expectTcHeader(packet, function, (pusErrorData_t){.integer=0});
	if (PUS_NO_ERROR == expectResult)
	{
		pusService_t service = pus_getTcService(packet);
		pusSubservice_t subtype = pus_getTcSubtype(packet);

		if (service != pus_ST19_eventAction)
		{
			pus_setError(PUS_ERROR_TC_SERVICE, function, (pusErrorData_t){.integer=service});
			return PUS_ERROR_TC_SERVICE;
		}

		if (expectedSubtype == pusSubtype_NONE)
		{
			// Check that subtype corresponds to ST[01]
			if ((subtype != pus_TC_19_1_addEventActionDefinitions) &&
				(subtype != pus_TC_19_2_deleteEventActionDefinitions) &&
				(subtype != pus_TC_19_4_enableEventActionDefinitions) &&
				(subtype != pus_TC_19_5_disableEventActionDefinitions))
			{
				pus_setError(PUS_ERROR_TC_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TC_SUBTYPE;
			}
		}
		else
		{
			// Check that subtype is as expected
			if (subtype != expectedSubtype)
			{
				pus_setError(PUS_ERROR_TC_SUBTYPE, function, (pusErrorData_t){.integer=subtype});
				return PUS_ERROR_TC_SUBTYPE;

			}
		}

		pusPacketDataKind_t kind = pus_getTcDataKind(packet);
		if (kind != pus_TC_DATA_ST_19_1 && kind != pus_TC_DATA_ST_19_X)
		{
			pus_setError(PUS_ERROR_TC_KIND, function, (pusErrorData_t){.integer=kind});
			return PUS_ERROR_TC_KIND;
		}

		return PUS_NO_ERROR;
	}
	else
	{
		return expectResult;
	}
}
