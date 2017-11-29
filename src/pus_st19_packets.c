#include "pus_st19_packets.h"



pusError_t pus_tc_19_X_createDefaultEventActionRequest(pusPacket_t* outTc, pusApidInfo_t* apid)
{
	if (NULL == outTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else
	{
		pus_initTcPacket(outTc);
		//pus_setTmDataKind(outTm, pus_TM_DATA_ST_1_X);

		// Source information
		pus_setApid(outTc, pus_getInfoApid(apid));
		pus_setSequenceCount(outTc, pus_getNextPacketCount(apid));

		// Data length
		pus_setPacketDataLength(outTc, sizeof(pusPacketData_t));

		pus_setTcService(outTc, pus_ST19_eventAction);

		// Timestamp
		//pus_setTmPacketTimeNow(outTm);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}



pusError_t pus_tc_19_1_createAddEventActionDefinitionsRequest(pusPacket_t* outTc, pusApidInfo_t* apid, pusSt05EventId_t eventId, pusPacket_t* tcAction)
{
	if (NULL == outTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( PUS_NO_ERROR !=  pus_tc_19_X_createDefaultEventActionRequest(outTc, apid) )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcSubtype(outTc, pus_TC_19_1_addEventActionDefinitions);
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_19_1);

	pusPacketReduced_t tcActionR;

	pus_tc_19_X_createPusPacketReduced(&tcActionR, tcAction);

	pus_tc_19_1_setAction(outTc, &tcActionR);
	pus_tc_19_x_setEventId(outTc, eventId);

	return PUS_NO_ERROR;
}


pusError_t pus_tc_19_2_createDeleteEventActionDefinitionsRequest(pusPacket_t* outTc, pusApidInfo_t* apid, pusSt05EventId_t eventId)
{
	if (NULL == outTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( PUS_NO_ERROR !=  pus_tc_19_X_createDefaultEventActionRequest(outTc, apid) )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcSubtype(outTc, pus_TC_19_2_deleteEventActionDefinitions);
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_19_X);

	pus_tc_19_x_setEventId(outTc, eventId);

	return PUS_NO_ERROR;
}

pusError_t pus_tc_19_4_createEnableEventActionDefinitions(pusPacket_t* outTc, pusApidInfo_t* apid, pusSt05EventId_t eventId)
{
	if (NULL == outTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( PUS_NO_ERROR !=  pus_tc_19_X_createDefaultEventActionRequest(outTc, apid) )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcSubtype(outTc, pus_TC_19_4_enableEventActionDefinitions);
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_19_X);

	pus_tc_19_x_setEventId(outTc, eventId);

	return PUS_NO_ERROR;
}

pusError_t pus_tc_19_5_createDisableEventActionDefinitions(pusPacket_t* outTc, pusApidInfo_t* apid, pusSt05EventId_t eventId)
{
	if (NULL == outTc || NULL == apid)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if( PUS_NO_ERROR !=  pus_tc_19_X_createDefaultEventActionRequest(outTc, apid) )
	{
		return PUS_GET_ERROR();
	}

	pus_setTcSubtype(outTc, pus_TC_19_5_disableEventActionDefinitions);
	pus_setTcDataKind(outTc, pus_TC_DATA_ST_19_X);

	pus_tc_19_x_setEventId(outTc, eventId);

	return PUS_NO_ERROR;
}

pusError_t pus_tc_19_X_setPacketReducedTcData(pusPacketReduced_t* outPacket, pusPacket_t* inTc)
{
	switch( inTc->data.u.tcData.data.kind )
	{
		case pus_TC_DATA_NONE:
			return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
			break;
		case pus_TC_DATA_ST_8_1:
			outPacket->data.u.tcData.data.u.st_8_1 = inTc->data.u.tcData.data.u.st_8_1;
			return PUS_SET_ERROR(PUS_NO_ERROR);
			break;
		case pus_TC_DATA_ST_19_1:
			return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
			break;
		case pus_TC_DATA_ST_19_X:
			return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
			break;
		default:
			return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
			break;
	}
}

pusError_t pus_tc_19_X_createPusPacketReduced(pusPacketReduced_t* outTcR, pusPacket_t* inTc)
{
	outTcR->apid = inTc->apid;
	outTcR->dataLength = inTc->dataLength;
	outTcR->packetType = inTc->packetType;
	outTcR->packetVersion = inTc->packetVersion;
	outTcR->secondaryHeaderFlag = inTc->secondaryHeaderFlag;
	outTcR->sequenceCount = inTc->sequenceCount;
	outTcR->sequenceFlags = inTc->sequenceFlags;

	outTcR->data.kind = inTc->data.kind;
	outTcR->data.u.tcData.header = inTc->data.u.tcData.header;

	if ( PUS_NO_ERROR == pus_tc_19_X_setPacketReducedTcData(outTcR, inTc) )
	{
		outTcR->data.u.tcData.data.kind = inTc->data.u.tcData.data.kind;
	}
	return PUS_GET_ERROR();
}

pusError_t pus_tc_19_X_setPacketTcData(pusPacket_t* outTc, pusPacketReduced_t* inTcR)
{
	switch( inTcR->data.u.tcData.data.kind )
	{
		case pus_TC_DATA_NONE:
			return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
			break;
		case pus_TC_DATA_ST_8_1:
			outTc->data.u.tcData.data.u.st_8_1 = inTcR->data.u.tcData.data.u.st_8_1;
			return PUS_SET_ERROR(PUS_NO_ERROR);
			break;
		case pus_TC_DATA_ST_19_X:
			return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
			break;
		default:
			return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
			break;
	}
}

pusError_t pus_tc_19_X_getPacketFromPacketReduced(pusPacket_t* outTc, pusPacketReduced_t* inTcR)
{
	outTc->apid = inTcR->apid;
	outTc->dataLength = inTcR->dataLength;
	outTc->packetType = inTcR->packetType;
	outTc->packetVersion = inTcR->packetVersion;
	outTc->secondaryHeaderFlag = inTcR->secondaryHeaderFlag;
	outTc->sequenceCount = inTcR->sequenceCount;
	outTc->sequenceFlags = inTcR->sequenceFlags;

	outTc->data.kind = inTcR->data.kind;
	outTc->data.u.tcData.header = inTcR->data.u.tcData.header;

	if ( PUS_NO_ERROR == pus_tc_19_X_setPacketTcData(outTc, inTcR) )
	{
		outTc->data.u.tcData.data.kind = inTcR->data.u.tcData.data.kind;
	}
	return PUS_GET_ERROR();
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

void pus_tc_19_1_getAction(pusPacketReduced_t* action, pusPacket_t* tc)
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

void pus_tc_19_x_setEventId(pusPacket_t* outTc, pusSt05EventId_t eventId)
{
	if ( NULL == outTc )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return;
	}

	if( pus_getTcDataKind(outTc) == pus_TC_DATA_ST_19_1)
	{
		outTc->data.u.tcData.data.u.st_19_1.eventId = eventId;
	}
	else if( pus_TC_DATA_NONE != pus_getTcDataKind(outTc) )
	{
		outTc->data.u.tcData.data.u.st_19_X.eventId = eventId;
	}
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
