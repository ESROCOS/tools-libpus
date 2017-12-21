#include "pus_packet_reduced.h"


pusError_t pus_packetReduced_createPacketReducedFromPacket(pusPacketReduced_t* outTcR, const pusPacket_t* inTc)
{
	if (NULL == outTcR || NULL == inTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	outTcR->apid = inTc->apid;
	outTcR->dataLength = inTc->dataLength;
	outTcR->packetType = inTc->packetType;
	outTcR->packetVersion = inTc->packetVersion;
	outTcR->secondaryHeaderFlag = inTc->secondaryHeaderFlag;
	outTcR->sequenceCount = inTc->sequenceCount;
	outTcR->sequenceFlags = inTc->sequenceFlags;

	outTcR->data.kind = inTc->data.kind;
	outTcR->data.u.tcData.header = inTc->data.u.tcData.header;

	if ( PUS_NO_ERROR == pus_packetReduced_setDataFromPacketToPacketReduced(outTcR, inTc) )
	{
		outTcR->data.u.tcData.data.kind = inTc->data.u.tcData.data.kind;
	}
	return PUS_GET_ERROR();
}

pusError_t pus_packetReduced_createPacketFromPacketReduced(pusPacket_t* outTc, const pusPacketReduced_t* inTcR)
{
	if (NULL == outTc || NULL == inTcR)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	outTc->apid = inTcR->apid;
	outTc->dataLength = inTcR->dataLength;
	outTc->packetType = inTcR->packetType;
	outTc->packetVersion = inTcR->packetVersion;
	outTc->secondaryHeaderFlag = inTcR->secondaryHeaderFlag;
	outTc->sequenceCount = inTcR->sequenceCount;
	outTc->sequenceFlags = inTcR->sequenceFlags;

	outTc->data.kind = inTcR->data.kind;
	outTc->data.u.tcData.header = inTcR->data.u.tcData.header;

	if ( PUS_NO_ERROR == pus_packetReduced_setDataFromPacketReducedToPacket(outTc, inTcR) )
	{
		outTc->data.u.tcData.data.kind = inTcR->data.u.tcData.data.kind;
	}
	return PUS_GET_ERROR();
}

pusError_t pus_packetReduced_setDataFromPacketToPacketReduced(pusPacketReduced_t* outTcR, const pusPacket_t* inTc)
{
	if (NULL == outTcR || NULL == inTc)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	switch( inTc->data.u.tcData.data.kind )
	{
		case pus_TC_DATA_NONE:
			return PUS_SET_ERROR(PUS_NO_ERROR);
			break;
		case pus_TC_DATA_ST_8_1:
			outTcR->data.u.tcData.data.u.st_8_1 = inTc->data.u.tcData.data.u.st_8_1;
			return PUS_SET_ERROR(PUS_NO_ERROR);
			break;
		case pus_TC_DATA_ST_12_1_2:
			outTcR->data.u.tcData.data.u.st_12_1_2 = inTc->data.u.tcData.data.u.st_12_1_2;
			return PUS_SET_ERROR(PUS_NO_ERROR);
			break;
		case pus_TC_DATA_ST_19_X:
			outTcR->data.u.tcData.data.u.st_19_X = inTc->data.u.tcData.data.u.st_19_X;
			return PUS_SET_ERROR(PUS_NO_ERROR);
			break;
		default:
			return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
			break;
	}
}


pusError_t pus_packetReduced_setDataFromPacketReducedToPacket(pusPacket_t* outTc, const pusPacketReduced_t* inTcR)
{
	if (NULL == outTc || NULL == inTcR)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	switch( inTcR->data.u.tcData.data.kind )
	{
		case pus_TC_DATA_NONE:
			return PUS_SET_ERROR(PUS_NO_ERROR);
			break;
		case pus_TC_DATA_ST_8_1:
			outTc->data.u.tcData.data.u.st_8_1 = inTcR->data.u.tcData.data.u.st_8_1;
			return PUS_SET_ERROR(PUS_NO_ERROR);
			break;
		case pus_TC_DATA_ST_12_1_2:
			outTc->data.u.tcData.data.u.st_12_1_2 = inTcR->data.u.tcData.data.u.st_12_1_2;
			return PUS_SET_ERROR(PUS_NO_ERROR);
			break;
		case pus_TC_DATA_ST_19_X:
			outTc->data.u.tcData.data.u.st_19_X = inTcR->data.u.tcData.data.u.st_19_X;
			return PUS_SET_ERROR(PUS_NO_ERROR);
			break;
		default:
			return PUS_SET_ERROR(PUS_ERROR_TC_KIND);
			break;
	}
}
