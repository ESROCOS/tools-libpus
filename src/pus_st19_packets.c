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

		pus_setTmService(outTc, pus_ST19_eventAction);

		// Timestamp
		//pus_setTmPacketTimeNow(outTm);

		return PUS_GET_ERROR();
	}

	return PUS_NO_ERROR;
}

pusError_t pus_createPusPacketReduced(pusPacketReduced_t* outTcR, pusPacket_t* inTc)
{
	outTcR->apid = inTc->apid;
	outTcR->dataLength = inTc->dataLength; //TODO ?
	outTcR->packetType = inTc->packetType;
	outTcR->packetVersion = inTc->packetVersion;
	outTcR->secondaryHeaderFlag = inTc->secondaryHeaderFlag;
	outTcR->sequenceCount = inTc->sequenceCount;
	outTcR->sequenceFlags = inTc->sequenceFlags;

	outTcR->data.kind = inTc->data.kind;
	outTcR->data.u.tcData.header = inTc->data.u.tcData.header;


	/*switch( inTc->data.u.tcData.data.kind ) //TODO memcpy
	{
		case PusTcApplicationData_NONE:

			break;
		case PusTcApplicationData_st_8_1_PRESENT:
			outTcR->data.u.tcData.data.u.st_8_1 = inTc->data.u.tcData.data.u.st_8_1;
			break;
		case st_19_x_PRESENT:
			return PUS_ERROR_TC_KIND;
			break;
		default:
			return PUS_ERROR_TC_KIND;
			break;

	}*/
	//outTcR->data.u.tcData.data = (asn1SccPusTcApplicationDataReduced)inTc->data.u.tcData.data; //no va

	//outTcR->data.u.tcData.data.kind = inTc->data.u.tcData.data.kind; //TODO problem enum

	return PUS_NO_ERROR;
}



pusError_t pus_tc_19_1_createAddEventActionDefinitionsRequest(pusPacket_t* outTc, pusApidInfo_t* apid /*TODO param packet*/)
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



	//TODO set data, A partir de qué crear el paquete.


	return PUS_NO_ERROR;
}

pusError_t pus_tc_19_2_createDeleteEventActionDefinitionsRequest(pusPacket_t* outTc, pusApidInfo_t* apid)
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

	//TODO set data

	return PUS_NO_ERROR;
}

pusError_t pus_tc_19_4_createEnableEventActionDefinitions(pusPacket_t* outTc, pusApidInfo_t* apid)
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

	//TODO set data

	return PUS_NO_ERROR;
}

pusError_t pus_tc_19_5_createDisableEventActionDefinitions(pusPacket_t* outTc, pusApidInfo_t* apid)
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

	//TODO set data

	return PUS_NO_ERROR;
}
