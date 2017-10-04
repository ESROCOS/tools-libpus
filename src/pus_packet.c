#include <assert.h>

// Debug
#include <stddef.h>

#include "pus_packet.h"
#include "pus_error.h"
#include "pus_time.h"


//
// Getters and setters for CCSDS packet
//

pusPacketVersion_t pus_getPacketVersion(const pusPacket_t* packet)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return 0;
    }
    else
    {
    	return packet->packetVersion;
    }
}

void pus_setPacketVersion(pusPacket_t* packet, pusPacketVersion_t version)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return;
    }
    else
    {
    	packet->packetVersion = version;
    }
}

pusPacketType_t pus_getPacketType(const pusPacket_t* packet)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return 0;
    }
    else
    {
    	return packet->packetType;
    }
}

void pus_setPacketType(pusPacket_t* packet, pusPacketType_t type)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return;
    }
    else
    {
    	packet->packetType = type;
    }
}

pusApid_t pus_getApid(const pusPacket_t* packet)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return pus_APID_IDLE;
    }
    else
    {
    	return packet->apid;
    }
}

void pus_setApid(pusPacket_t* packet, pusApid_t apid)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return;
    }
    else
    {
    	packet->apid = apid;
    }
}

bool pus_getSecondaryHeaderFlag(const pusPacket_t* packet)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return false;
    }
    else
    {
    	return packet->secondaryHeaderFlag;
    }
}

void pus_setSecondaryHeaderFlag(pusPacket_t* packet, bool hasIt)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return;
    }
    else
    {
    	packet->secondaryHeaderFlag = hasIt;
    }
}

pusSequenceFlags_t pus_getSequenceFlags(const pusPacket_t* packet)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return pus_STANDALONE_PACKET;
    }
    else
    {
    	return packet->sequenceFlags;
    }
}

void pus_setSequenceFlags(pusPacket_t* packet, pusSequenceFlags_t flags)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return;
    }
    else
    {
    	packet->sequenceFlags = flags;
    }
}

pusSequenceCount_t pus_getSequenceCount(const pusPacket_t* packet)
{
    assert(pusSequenceCount_LIMIT > packet->sequenceCount);
    
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return 0;
    }
    else
    {
    	return packet->sequenceCount;
    }
}

pusSequenceCount_t pus_setSequenceCount(pusPacket_t* packet, pusSequenceCount_t count)
{
    int countWrapped = count;
    
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return 0;
    }

	// Limit should be checked by caller, but wrap just in case
    if (count >= pusSequenceCount_LIMIT)
    {
        countWrapped = count % pusSequenceCount_LIMIT;
        PUS_SET_ERROR(PUS_ERROR_COUNT_WRAP);
    }
    
    packet->sequenceCount = countWrapped;

    return packet->sequenceCount;
}

pusPacketDataLength_t pus_getPacketDataLength(const pusPacket_t* packet)
{
    assert(pusPacketDataLength_LIMIT > packet->dataLength);
    
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return 0;
    }
    else
    {
    	return packet->dataLength;
    }
}

void pus_setPacketDataLength(pusPacket_t* packet, pusPacketDataLength_t length)
{
    assert(NULL != packet);
    assert(pusPacketDataLength_LIMIT > length);
    
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return;
    }
    else if (pusPacketDataLength_LIMIT <= length)
    {
        PUS_SET_ERROR(PUS_ERROR_LIMIT);
        return;
    }
    else
    {
    	packet->dataLength = length;
    }
}

void pus_setPacketDataNone(pusPacket_t* packet)
{
    pus_setPacketDataLength(packet, 0);
    pus_setPacketDataKind(packet, pus_PACKET_DATA_NONE);
}

pusVersion_t pus_getTmPusVersion(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER(packet))
    {
    	return packet->data.u.tmData.header.pusVersion;
    }
    else
    {
    	return pus_INVALID_VERSION;
    }
}

void pus_setTmPusVersion(pusPacket_t* packet, pusVersion_t version)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER(packet))
    {
    	packet->data.u.tmData.header.pusVersion = version;
    }
}

pusVersion_t pus_getTcPusVersion(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER(packet))
	{
    	return packet->data.u.tcData.header.pusVersion;
	}
    else
    {
		return pus_INVALID_VERSION;
    }
}

void pus_setTcPusVersion(pusPacket_t* packet, pusVersion_t version)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER(packet))
    {
    	packet->data.u.tcData.header.pusVersion = version;
    }
}

pusService_t pus_getTmService(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER(packet))
	{
        return packet->data.u.tmData.header.service;
	}
    else
    {
        return pusService_NONE;
    }
}

void pus_setTmService(pusPacket_t* packet, pusService_t service)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER_2(packet, service))
	{
        packet->data.u.tmData.header.service = service;
	}
}

pusSubservice_t pus_getTmSubtype(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER(packet))
	{
        return packet->data.u.tmData.header.subtype;
	}
    else
    {
		return pusSubtype_NONE;
    }
}

void pus_setTmSubtype(pusPacket_t* packet, pusService_t subtype)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER_2(packet, subtype))
	{
        packet->data.u.tmData.header.subtype = subtype;
	}
}

pusService_t pus_getTcService(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER(packet))
	{
        return packet->data.u.tcData.header.service;
	}
    else
    {
		return pusService_NONE;
    }
}

void pus_setTcService(pusPacket_t* packet, pusService_t service)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER_2(packet, service))
	{
        packet->data.u.tcData.header.service = service;
	}
}

pusSubservice_t pus_getTcSubtype(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER(packet))
	{
        return packet->data.u.tcData.header.subtype;
	}
    else
    {
        return pusSubtype_NONE;
    }
}

void pus_setTcSubtype(pusPacket_t* packet, pusService_t subtype)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER_2(packet, subtype))
	{
        packet->data.u.tcData.header.subtype = subtype;
	}
}

pusTimeRefStatus_t pus_getTmTimeReferenceStatus(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER(packet))
	{
        return packet->data.u.tmData.header.timeRefStatus;
	}
    else
    {
        return pus_TIME_REFERENCE_STATUS_NONE;
    }
}

void pus_setTmTimeReferenceStatus(pusPacket_t* packet, pusTimeRefStatus_t status)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER_2(packet, status))
	{
        packet->data.u.tmData.header.timeRefStatus = status;
	}
}

pusMsgTypeCount_t pus_getTmMessageTypeCounter(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER(packet))
	{
        return packet->data.u.tmData.header.msgTypeCount;
	}
    else
    {
		return 0;
    }
}

void pus_setTmMessageTypeCounter(pusPacket_t* packet, pusMsgTypeCount_t count)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER_2(packet, count))
	{
        packet->data.u.tmData.header.msgTypeCount = count;
	}
}

pusApid_t pus_getTmDestination(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER(packet))
	{
        return packet->data.u.tmData.header.destination;
	}
    else
    {
		return pus_APID_IDLE;
    }
}

void pus_setTmDestination(pusPacket_t* packet, pusApid_t destination)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER_2(packet, destination))
	{
        packet->data.u.tmData.header.destination = destination;
	}
}

pusApid_t pus_getTcSource(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER(packet))
	{
        return packet->data.u.tcData.header.source;
	}
    else
    {
        return pus_APID_IDLE;
    }
}

void pus_setTcSource(pusPacket_t* packet, pusApid_t source)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER_2(packet, source))
	{
        packet->data.u.tcData.header.source = source;
	}
}

void pus_getTmPacketTime(pusTime_t* outTime, const pusPacket_t* packet)
{
	if (NULL == outTime)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER(packet))
	{
    	*outTime = packet->data.u.tmData.header.time;
	}
}

void pus_setTmPacketTime(pusPacket_t* packet, const pusTime_t* time)
{
	if (NULL == time)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	else if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER(packet))
	{
        packet->data.u.tmData.header.time = *time;
	}
}

void pus_setTmPacketTimeNow(pusPacket_t* packet)
{
    // Errors set by pus_setTmPacketTime

    pusTime_t now;
    pus_now(&now);
    pus_setTmPacketTime(packet, &now);
}

bool pus_getTcAckFlagAcceptance(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER(packet))
	{
    	return packet->data.u.tcData.header.ackFlags.acceptanceReportRequested;
	}
    else
    {
		return false;
    }
}

bool pus_getTcAckFlagStart(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER(packet))
	{
    	return packet->data.u.tcData.header.ackFlags.startReportRequested;
	}
    else
    {
		return false;
    }
}

bool pus_getTcAckFlagProgress(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER(packet))
	{
    	return packet->data.u.tcData.header.ackFlags.progressReportRequested;
	}
    else
    {
		return false;
    }
}

bool pus_getTcAckFlagCompletion(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER(packet))
	{
    	return packet->data.u.tcData.header.ackFlags.completionReportRequested;
	}
    else
    {
		return false;
    }
}

void pus_setTcAckFlags(pusPacket_t* packet, bool acceptance, bool start, bool progress, bool completion)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TC_HEADER(packet))
	{
		packet->data.u.tcData.header.ackFlags.acceptanceReportRequested = acceptance;
		packet->data.u.tcData.header.ackFlags.startReportRequested = start;
		packet->data.u.tcData.header.ackFlags.progressReportRequested = progress;
		packet->data.u.tcData.header.ackFlags.completionReportRequested = completion;
	}
}


//
// Getters/setters for union types
//

pusPacketDataKind_t pus_getPacketDataKind(const pusPacket_t* packet)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return pus_PACKET_DATA_NONE;
    }
    else
    {
    	return packet->data.kind;
    }
}

void pus_setPacketDataKind(pusPacket_t* packet, pusPacketDataKind_t kind)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR_2(PUS_ERROR_NULLPTR, kind);
    	return;
    }
    else
    {
    	packet->data.kind = kind;
    }
}

pusTmDataKind_t pus_getTmDataKind(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER(packet))
    {
    	return packet->data.u.tmData.data.kind;
    }
    else
    {
    	return pus_TM_DATA_NONE;
    }
}

void pus_setTmDataKind(pusPacket_t* packet, pusPacketDataKind_t kind)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_HEADER_2(packet, kind))
    {
    	packet->data.u.tmData.data.kind = kind;
    }
}

pusTmDataKind_t pus_getTmNoHeaderDataKind(const pusPacket_t* packet)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_NO_HEADER(packet))
    {
    	return packet->data.u.tmDataNoHeader.kind;
    }
    else
    {
    	return pus_TM_DATA_NONE;
    }
}

void pus_setTmDataNoHeaderKind(pusPacket_t* packet, pusPacketDataKind_t kind)
{
    if (PUS_NO_ERROR == PUS_EXPECT_TM_NO_HEADER_2(packet, kind))
    {
    	packet->data.u.tmDataNoHeader.kind = kind;
    }
}



//
// Utility functions for packet header types
//

pusSequenceCount_t pus_incrementSequenceCount(pusSequenceCount_t count)
{
    return (count + 1) % pusSequenceCount_LIMIT;
}


//
// Packet initialization
//

pusError_t pus_setPacketDefaults(pusPacket_t* packet)
{
    if (NULL == packet)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}

    pus_setPacketVersion(packet, pus_PACKET_VERSION_CURRENT);
    pus_setPacketType(packet, pus_TM);
    pus_setSecondaryHeaderFlag(packet, false);
    pus_setApid(packet, pus_APID_IDLE);
    pus_setSequenceFlags(packet, pus_STANDALONE_PACKET);
    pus_setSequenceCount(packet, 0);
    pus_setPacketDataNone(packet);

    assert(PUS_NO_ERROR == pus_verifyCcsdsHeaderDefaults(packet));

    return PUS_NO_ERROR;
}

pusError_t pus_initTmPacket(pusPacket_t* packet)
{
    if (NULL == packet)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}

    // CCSDS header
    pus_setPacketDefaults(packet);
    pus_setPacketType(packet, pus_TM);
    
    // Enable secondary header (for all standard TM packets, except time reports)
    pus_setSecondaryHeaderFlag(packet, true);
    pus_setPacketDataKind(packet, pus_TM_DATA);

    // Secondary header fields
    pus_setTmPusVersion(packet, pus_VERSION_CURRENT);
    pus_setTmTimeReferenceStatus(packet, pus_TIME_REFERENCE_STATUS_NONE);
    pus_setTmService(packet, pusService_NONE);
    pus_setTmSubtype(packet, pusSubtype_NONE);
    pus_setTmMessageTypeCounter(packet, pus_MESSAGE_TYPE_COUNTER_NONE);
    pus_setTmDestination(packet, pus_APID_IDLE);
    pus_setTmPacketTimeNow(packet);

    assert(PUS_NO_ERROR == pus_verifyTmHeaderDefaults(packet));

    return PUS_NO_ERROR;
}

pusError_t pus_initTmPacketNoHeader(pusPacket_t* packet)
{
    if (NULL == packet)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}

    // CCSDS header
    pus_setPacketDefaults(packet);
    pus_setPacketType(packet, pus_TM);
    pus_setSecondaryHeaderFlag(packet, false);
    pus_setPacketDataKind(packet, pus_TM_DATA_NO_HEADER);

    assert(PUS_NO_ERROR == pus_verifyTmHeaderDefaults(packet));

    return PUS_NO_ERROR;
}

pusError_t pus_initTcPacket(pusPacket_t* packet)
{
    if (NULL == packet)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}

	// CCSDS header
	pus_setPacketDefaults(packet);
	pus_setPacketType(packet, pus_TC);

    // Enable secondary header (for all standard packets, except time report TMs)
    pus_setSecondaryHeaderFlag(packet, true);
    pus_setPacketDataKind(packet, pus_TC_DATA);

	// Secondary header field
    pus_setTcPusVersion(packet, pus_VERSION_CURRENT);
    pus_setTcAckFlags(packet, false, false, false, false);
    pus_setTcService(packet, pusService_NONE);
    pus_setTcSubtype(packet, pusSubtype_NONE);
    pus_setTcSource(packet, pus_APID_IDLE);

    assert(PUS_NO_ERROR == pus_verifyTcHeaderDefaults(packet));

    return PUS_NO_ERROR;
}

pusError_t pus_initTcPacketNoHeader(pusPacket_t* packet)
{
    if (NULL == packet)
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}

    // CCSDS header
    pus_setPacketDefaults(packet);
    pus_setPacketType(packet, pus_TC);
    pus_setSecondaryHeaderFlag(packet, false);
    pus_setPacketDataKind(packet, pus_TC_DATA_NO_HEADER);

    assert(PUS_NO_ERROR == pus_verifyTcHeaderDefaults(packet));

    return PUS_NO_ERROR;
}


//
// Packet verification
//

pusError_t pus_verifyCcsdsHeaderDefaults(const pusPacket_t* packet)
{
    if (NULL == packet)
	{
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}
    else if (pus_PACKET_VERSION_CURRENT != pus_getPacketVersion(packet))
	{
    	PUS_SET_ERROR(PUS_ERROR_UNEXPECTED_PACKET_VERSION);
		return PUS_ERROR_UNEXPECTED_PACKET_VERSION;
	}
	else if (pus_STANDALONE_PACKET != pus_getSequenceFlags(packet))
	{
    	PUS_SET_ERROR(PUS_ERROR_UNEXPECTED_SEQUENCE_FLAGS);
		return PUS_ERROR_UNEXPECTED_SEQUENCE_FLAGS;
	}
	else
	{
		return PUS_NO_ERROR;
	}
}

pusError_t pus_verifyPacketDataKind(const pusPacket_t* packet)
{
    if (NULL == packet)
	{
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return PUS_ERROR_NULLPTR;
	}
    else if (pus_TM == pus_getPacketType(packet))
	{
		if (pus_getSecondaryHeaderFlag(packet))
		{
			if (pus_TM_DATA == pus_getPacketDataKind(packet))
			{
				return PUS_NO_ERROR;
			}
			else
			{
		    	PUS_SET_ERROR(PUS_ERROR_HEADER_MISMATCH);
				return PUS_ERROR_HEADER_MISMATCH;
			}
		}
		else
		{
			if (pus_TM_DATA_NO_HEADER == pus_getPacketDataKind(packet))
			{
				return PUS_NO_ERROR;
			}
			else
			{
		    	PUS_SET_ERROR(PUS_ERROR_HEADER_MISMATCH);
				return PUS_ERROR_HEADER_MISMATCH;
			}
		}
	}
	else if (pus_TC == pus_getPacketType(packet))
	{
		if (pus_getSecondaryHeaderFlag(packet))
		{
			if (pus_TC_DATA == pus_getPacketDataKind(packet))
			{
				return PUS_NO_ERROR;
			}
			else
			{
		    	PUS_SET_ERROR(PUS_ERROR_HEADER_MISMATCH);
				return PUS_ERROR_HEADER_MISMATCH;
			}
		}
		else
		{
			if (pus_TC_DATA_NO_HEADER == pus_getPacketDataKind(packet))
			{
				return PUS_NO_ERROR;
			}
			else
			{
		    	PUS_SET_ERROR(PUS_ERROR_HEADER_MISMATCH);
				return PUS_ERROR_HEADER_MISMATCH;
			}
		}
	}
	else
	{
    	PUS_SET_ERROR(PUS_ERROR_PACKET_TYPE);
		return PUS_ERROR_PACKET_TYPE;
	}
}

pusError_t pus_verifyTmSecondaryHeaderDefaults(const pusPacket_t* packet)
{
	pusError_t expectResult = PUS_EXPECT_TM_HEADER(packet);
    if (PUS_NO_ERROR == expectResult)
    {
		if (pus_VERSION_CURRENT != pus_getTmPusVersion(packet))
		{
	    	PUS_SET_ERROR(PUS_ERROR_UNEXPECTED_PUS_VERSION);
			return PUS_ERROR_UNEXPECTED_PUS_VERSION;
		}
		else
		{
			return PUS_NO_ERROR;
		}
    }
    else
    {
    	// Return the error set by PUS_EXPECT_TM_HEADER
    	return expectResult;
    }
}

pusError_t pus_verifyTmHeaderDefaults(const pusPacket_t* packet)
{
	pusError_t expectResult = PUS_EXPECT_TM(packet);
    if (PUS_NO_ERROR == expectResult)
    {
		pusError_t ccsdsCheck = pus_verifyCcsdsHeaderDefaults(packet);
		if (PUS_NO_ERROR != ccsdsCheck)
		{
			return ccsdsCheck;
		}

		pusError_t kindCheck = pus_verifyPacketDataKind(packet);
		if (PUS_NO_ERROR != kindCheck)
		{
			return kindCheck;
		}

		if (pus_getSecondaryHeaderFlag(packet))
		{
			return pus_verifyTmSecondaryHeaderDefaults(packet);
		}
		else
		{
			return PUS_NO_ERROR;
		}
    }
    else
    {
    	// Return the error set by PUS_EXPECT_TM_HEADER
    	return expectResult;
    }
}

pusError_t pus_verifyTcSecondaryHeaderDefaults(const pusPacket_t* packet)
{
	pusError_t expectResult = PUS_EXPECT_TC_HEADER(packet);
    if (PUS_NO_ERROR == expectResult)
    {
		if (pus_VERSION_CURRENT != pus_getTcPusVersion(packet))
		{
	    	PUS_SET_ERROR(PUS_ERROR_UNEXPECTED_PUS_VERSION);
			return PUS_ERROR_UNEXPECTED_PUS_VERSION;
		}
		else
		{
			return PUS_NO_ERROR;
		}
    }
    else
    {
    	// Return the error set by PUS_EXPECT_TM_HEADER
    	return expectResult;
    }
}

pusError_t pus_verifyTcHeaderDefaults(const pusPacket_t* packet)
{
	pusError_t expectResult = PUS_EXPECT_TC(packet);
    if (PUS_NO_ERROR == expectResult)
    {
		pusError_t ccsdsCheck = pus_verifyCcsdsHeaderDefaults(packet);
		if (PUS_NO_ERROR != ccsdsCheck)
		{
			return ccsdsCheck;
		}

		pusError_t kindCheck = pus_verifyPacketDataKind(packet);
		if (PUS_NO_ERROR != kindCheck)
		{
			return kindCheck;
		}

		if (pus_getSecondaryHeaderFlag(packet))
		{
			return pus_verifyTcSecondaryHeaderDefaults(packet);
		}
		else
		{
			return PUS_NO_ERROR;
		}
	}
    else
    {
    	// Return the error set by PUS_EXPECT_TM_HEADER
    	return expectResult;
    }
}


//
// Parameter checking
//

pusError_t pus_expectTm(const pusPacket_t* packet, const char* function, pusErrorData_t data)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return PUS_ERROR_NULLPTR;
    }
    else if (pus_TM != pus_getPacketType(packet))
    {
        PUS_SET_ERROR(PUS_ERROR_NOT_TM);
        return PUS_ERROR_NOT_TM;
    }
    else
    {
    	return PUS_NO_ERROR;
    }
}

pusError_t pus_expectTmHeader(const pusPacket_t* packet, const char* function, pusErrorData_t data)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return PUS_ERROR_NULLPTR;
    }
    else if (pus_TM != pus_getPacketType(packet))
    {
        PUS_SET_ERROR(PUS_ERROR_NOT_TM);
        return PUS_ERROR_NOT_TM;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        PUS_SET_ERROR(PUS_ERROR_HEADER_MISMATCH);
        return PUS_ERROR_HEADER_MISMATCH;
    }
    else
    {
    	return PUS_NO_ERROR;
    }
}

pusError_t pus_expectTmNoHeader(const pusPacket_t* packet, const char* function, pusErrorData_t data)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return PUS_ERROR_NULLPTR;
    }
    else if (pus_TM != pus_getPacketType(packet))
    {
        PUS_SET_ERROR(PUS_ERROR_NOT_TM);
        return PUS_ERROR_NOT_TM;
    }
    else if (pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA_NO_HEADER != pus_getPacketDataKind(packet))
    {
        PUS_SET_ERROR(PUS_ERROR_HEADER_MISMATCH);
        return PUS_ERROR_HEADER_MISMATCH;
    }
    else
    {
    	return PUS_NO_ERROR;
    }
}

pusError_t pus_expectTc(const pusPacket_t* packet, const char* function, pusErrorData_t data)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return PUS_ERROR_NULLPTR;
    }
    else if (pus_TC != pus_getPacketType(packet))
    {
        PUS_SET_ERROR(PUS_ERROR_NOT_TC);
        return PUS_ERROR_NOT_TC;
    }
    else
    {
    	return PUS_NO_ERROR;
    }
}

pusError_t pus_expectTcHeader(const pusPacket_t* packet, const char* function, pusErrorData_t data)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return PUS_ERROR_NULLPTR;
    }
    else if (pus_TC != pus_getPacketType(packet))
    {
        PUS_SET_ERROR(PUS_ERROR_NOT_TC);
        return PUS_ERROR_NOT_TC;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        PUS_SET_ERROR(PUS_ERROR_HEADER_MISMATCH);
        return PUS_ERROR_HEADER_MISMATCH;
    }
    else
    {
    	return PUS_NO_ERROR;
    }
}

pusError_t pus_expectTcNoHeader(const pusPacket_t* packet, const char* function, pusErrorData_t data)
{
    if (NULL == packet)
    {
    	PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    	return PUS_ERROR_NULLPTR;
    }
    else if (pus_TC != pus_getPacketType(packet))
    {
        PUS_SET_ERROR(PUS_ERROR_NOT_TC);
        return PUS_ERROR_NOT_TC;
    }
    else if (pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA_NO_HEADER != pus_getPacketDataKind(packet))
    {
        PUS_SET_ERROR(PUS_ERROR_HEADER_MISMATCH);
        return PUS_ERROR_HEADER_MISMATCH;
    }
    else
    {
    	return PUS_NO_ERROR;
    }
}

