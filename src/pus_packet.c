#include <assert.h>

// Debug
#include <stdio.h>

#include "pus_packet.h"
#include "pus_error.h"
#include "pus_time.h"


// Getters and setters for CCSDS packet

pusPacketVersion_t pus_getPacketVersion(const pusPacket_t* packet)
{
    assert(NULL != packet);
    
    return packet->packetVersion;
}

void pus_setPacketVersion(pusPacket_t* packet, pusPacketVersion_t version)
{
    assert(NULL != packet);
    
    packet->packetVersion = version;
}

pusPacketType_t pus_getPacketType(const pusPacket_t* packet)
{
    assert(NULL != packet);
    
    return packet->packetType;
}

void pus_setPacketType(pusPacket_t* packet, pusPacketType_t type)
{
    assert(NULL != packet);
    
    packet->packetType = type;
}

pusApid_t pus_getApid(const pusPacket_t* packet)
{
    assert(NULL != packet);
    
    return packet->apid;
}

void pus_setApid(pusPacket_t* packet, pusApid_t apid)
{
    assert(NULL != packet);
    
    packet->apid = apid;
}

bool pus_getSecondaryHeaderFlag(const pusPacket_t* packet)
{
    assert(NULL != packet);
    
    return packet->secondaryHeaderFlag;
}

void pus_setSecondaryHeaderFlag(pusPacket_t* packet, bool hasIt)
{
    assert(NULL != packet);
    
    packet->secondaryHeaderFlag = hasIt;
}

pusSequenceFlags_t pus_getSequenceFlags(const pusPacket_t* packet)
{
    assert(NULL != packet);
    
    return packet->sequenceFlags;
}

void pus_setSequenceFlags(pusPacket_t* packet, pusSequenceFlags_t flags)
{
    assert(NULL != packet);
    
    packet->sequenceFlags = flags;
}

pusSequenceCount_t pus_getSequenceCount(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pusSequenceCount_LIMIT > packet->sequenceCount);
    
    return packet->sequenceCount;
}

pusSequenceCount_t pus_setSequenceCount(pusPacket_t* packet, pusSequenceCount_t count)
{
    int countWrapped = count;
    
    assert(NULL != packet);
    assert(pusSequenceCount_LIMIT > count);
    
    // Limit should be checked by caller, but wrap just in case
    if (count >= pusSequenceCount_LIMIT)
    {
        countWrapped = count % pusSequenceCount_LIMIT;
        pus_setError(PUS_ERROR_COUNT_WRAP, PUS_SETSEQUENCECOUNT, 0);
    }
    
    packet->sequenceCount = countWrapped;

    return packet->sequenceCount;
}

pusPacketDataLength_t pus_getPacketDataLength(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pusPacketDataLenght_LIMIT > packet->dataLength);
    
    return packet->dataLength;
}

void pus_setPacketDataLength(pusPacket_t* packet, pusPacketDataLength_t length)
{
    assert(NULL != packet);
    assert(pusPacketDataLenght_LIMIT > length);
    
    if (pusPacketDataLenght_LIMIT <= length)
    {
        pus_setError(PUS_ERROR_LIMIT, PUS_SETPACKETDATALENGTH, 0);
    }

    packet->dataLength = length;
}

void pus_setPacketDataNone(pusPacket_t* packet)
{
    assert(NULL != packet);
    
    pus_setPacketDataLength(packet, 0);
    pus_setPacketDataKind(packet, pus_PACKET_DATA_NONE);
}

pusPacketDataKind_t pus_getPacketDataKind(const pusPacket_t* packet)
{
    assert(NULL != packet);
    
    pusPacketDataKind_t kind = pus_PACKET_DATA_NONE;
    
    switch(packet->data.kind)
    {
    case PusPacketData_NONE:
        kind =  pus_PACKET_DATA_NONE;
        break;
    case tmData_PRESENT:
        kind = pus_TM_DATA;
        break;
    case tmDataNoHeader_PRESENT:
        kind = pus_TM_DATA_NO_HEADER;
        break;
    case tcData_PRESENT:
        kind = pus_TC_DATA;
        break;
    case pus_TC_DATA_NO_HEADER:
        kind = pus_TC_DATA_NO_HEADER;
        break;
    default:
        assert(false);
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETPACKETDATAKIND, 0);
    }

    assert(pus_PACKET_DATA_NONE <= kind && pus_PACKET_DATA_LAST > kind);
    return kind;
}

void pus_setPacketDataKind(pusPacket_t* packet, pusPacketDataKind_t kind)
{
    assert(NULL != packet);
    assert(pus_PACKET_DATA_NONE <= kind && pus_PACKET_DATA_LAST > kind);
    
    switch(kind)
    {
    case pus_PACKET_DATA_NONE:
        packet->data.kind = PusPacketData_NONE;
        break;
    case pus_TM_DATA:
        packet->data.kind = tmData_PRESENT;
        break;
    case pus_TM_DATA_NO_HEADER:
        packet->data.kind = tmDataNoHeader_PRESENT;
        break;
    case pus_TC_DATA:
        packet->data.kind = tcData_PRESENT;
        break;
    case pus_TC_DATA_NO_HEADER:
        packet->data.kind = tcDataNoHeader_PRESENT;
        break;
    default:
        assert(false);
        packet->data.kind = PusPacketData_NONE;
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_SETPACKETDATAKIND, (pusErrorData_t)kind);
    }
}

pusVersion_t pus_getTmPusVersion(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));
    
    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_GETTMPUSVERSION, 0);
        return pus_INVALID_VERSION;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTMPUSVERSION, 0);
        return pus_INVALID_VERSION;
    }
    else
    {
    	return packet->data.u.tmData.header.pusVersion;
    }
}

void pus_setTmPusVersion(pusPacket_t* packet, pusVersion_t version)
{
    assert(NULL != packet);
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));
    
    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_SETTMPUSVERSION, 0);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_SETTMPUSVERSION, 0);
        return;
    }
    else
    {
    	packet->data.u.tmData.header.pusVersion = version;
    }
}

pusVersion_t pus_getTcPusVersion(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_GETTCPUSVERSION, 0);
        return pus_INVALID_VERSION;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTCPUSVERSION, 0);
        return pus_INVALID_VERSION;
    }
    else
    {
    	return packet->data.u.tcData.header.pusVersion;
    }
}

void pus_setTcPusVersion(pusPacket_t* packet, pusVersion_t version)
{
    assert(NULL != packet);
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));
    
    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_SETTCPUSVERSION, 0);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_SETTCPUSVERSION, 0);
        return;
    }
    else
    {
    	packet->data.u.tcData.header.pusVersion = version;
    }
}

pusService_t pus_getTmService(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));
    
    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_GETTMSERVICE, 0);
        return pusService_NONE;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTMSERVICE, 0);
        return pusService_NONE;
    }
    else
    {
        return packet->data.u.tmData.header.service;
    }
}

void pus_setTmService(pusPacket_t* packet, pusService_t service)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_SETTMSERVICE, (pusErrorData_t)service);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTMSERVICE, (pusErrorData_t)service);
        return;
    }
    else
    {
        packet->data.u.tmData.header.service = service;
    }
}

pusSubservice_t pus_getTmSubtype(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_GETTMSUBTYPE, 0);
        return pusService_NONE;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTMSUBTYPE, 0);
        return pusService_NONE;
    }
    else
    {
        return packet->data.u.tmData.header.subtype;
    }
}

void pus_setTmSubtype(pusPacket_t* packet, pusService_t subtype)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_SETTMSUBTYPE, (pusErrorData_t)subtype);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_SETTMSUBTYPE, (pusErrorData_t)subtype);
        return;
    }
    else
    {
        packet->data.u.tmData.header.subtype = subtype;
    }
}

pusService_t pus_getTcService(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_GETTCSERVICE, 0);
        return pusService_NONE;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTCSERVICE, 0);
        return pusService_NONE;
    }
    else
    {
        return packet->data.u.tcData.header.service;
    }
}

void pus_setTcService(pusPacket_t* packet, pusService_t service)
{
    assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_SETTCSERVICE, (pusErrorData_t)service);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTCSERVICE, (pusErrorData_t)service);
        return;
    }
    else
    {
        packet->data.u.tcData.header.service = service;
    }
}

pusSubservice_t pus_getTcSubtype(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_GETTCSUBTYPE, 0);
        return pusService_NONE;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTCSUBTYPE, 0);
        return pusService_NONE;
    }
    else
    {
        return packet->data.u.tcData.header.subtype;
    }
}

void pus_setTcSubtype(pusPacket_t* packet, pusService_t subtype)
{
    assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_SETTCSUBTYPE, (pusErrorData_t)subtype);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_SETTCSUBTYPE, (pusErrorData_t)subtype);
        return;
    }
    else
    {
        packet->data.u.tcData.header.subtype = subtype;
    }
}

pusTimeRefStatus_t pus_getTmTimeReferenceStatus(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_GETTMTIMEREFSTATUS, 0);
        return pusService_NONE;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTMTIMEREFSTATUS, 0);
        return pusService_NONE;
    }
    else
    {
        return packet->data.u.tmData.header.timeRefStatus;
    }
}

void pus_setTmTimeReferenceStatus(pusPacket_t* packet, pusTimeRefStatus_t status)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_SETTMTIMEREFSTATUS, (pusErrorData_t)status);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_SETTMTIMEREFSTATUS, (pusErrorData_t)status);
        return;
    }
    else
    {
        packet->data.u.tmData.header.timeRefStatus = status;
    }
}

pusMsgTypeCount_t pus_getTmMessageTypeCounter(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_GETTMMESSAGETYPECOUNTER, 0);
        return pusService_NONE;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTMMESSAGETYPECOUNTER, 0);
        return pusService_NONE;
    }
    else
    {
        return packet->data.u.tmData.header.msgTypeCount;
    }
}

void pus_setTmMessageTypeCounter(pusPacket_t* packet, pusMsgTypeCount_t count)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_SETTMMESSAGETYPECOUNTER, (pusErrorData_t)count);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_SETTMMESSAGETYPECOUNTER, (pusErrorData_t)count);
        return;
    }
    else
    {
        packet->data.u.tmData.header.msgTypeCount = count;
    }
}

pusApid_t pus_getTmDestination(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_GETTMDESTINATION, 0);
        return pusService_NONE;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTMDESTINATION, 0);
        return pusService_NONE;
    }
    else
    {
        return packet->data.u.tmData.header.destination;
    }
}

void pus_setTmDestination(pusPacket_t* packet, pusApid_t destination)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_SETTMDESTINATION, (pusErrorData_t)destination);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_SETTMDESTINATION, (pusErrorData_t)destination);
        return;
    }
    else
    {
        packet->data.u.tmData.header.destination = destination;
    }
}

pusApid_t pus_getTcSource(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_GETTCSOURCE, 0);
        return pusService_NONE;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTCSOURCE, 0);
        return pusService_NONE;
    }
    else
    {
        return packet->data.u.tcData.header.source;
    }
}

void pus_setTcSource(pusPacket_t* packet, pusApid_t source)
{
    assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_SETTCSOURCE, (pusErrorData_t)source);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_SETTCSOURCE, (pusErrorData_t)source);
        return;
    }
    else
    {
        packet->data.u.tcData.header.source = source;
    }
}

void pus_getTmPacketTime(pusTime_t* outTime, const pusPacket_t* packet)
{
	assert(NULL != outTime);
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_GETTMPACKETTIME, 0);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTMPACKETTIME, 0);
        return;
    }
    else
    {
    	*outTime = packet->data.u.tmData.header.time;
    }
}

void pus_setTmPacketTime(pusPacket_t* packet, const pusTime_t* time)
{
    assert(NULL != packet);
    assert(NULL != time);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_SETTMPACKETTIME, 0);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_SETTMPACKETTIME, 0);
        return;
    }
    else
    {
        packet->data.u.tmData.header.time = *time;
    }
}

void pus_setTmPacketTimeNow(pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    // Errors set by pus_setTmPacketTime

    pusTime_t now;
    pus_now(&now);
    pus_setTmPacketTime(packet, &now);
}

bool pus_getTcAckFlagAcceptance(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_GETTCACKFLAGACCEPTANCE, 0);
        return false;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTCACKFLAGACCEPTANCE, 0);
        return false;
    }
    else
    {
    	return packet->data.u.tcData.header.ackFlags.acceptanceReportRequested;
    }
}

bool pus_getTcAckFlagStart(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_GETTCACKFLAGSTART, 0);
        return false;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTCACKFLAGSTART, 0);
        return false;
    }
    else
    {
    	return packet->data.u.tcData.header.ackFlags.startReportRequested;
    }
}

bool pus_getTcAckFlagProgress(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_GETTCACKFLAGPROGRESS, 0);
        return false;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTCACKFLAGPROGRESS, 0);
        return false;
    }
    else
    {
    	return packet->data.u.tcData.header.ackFlags.progressReportRequested;
    }
}

bool pus_getTcAckFlagCompletion(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_GETTCACKFLAGCOMPLETION, 0);
        return false;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_GETTCACKFLAGCOMPLETION, 0);
        return false;
    }
    else
    {
    	return packet->data.u.tcData.header.ackFlags.completionReportRequested;
    }
}

void pus_setTcAckFlags(pusPacket_t* packet, bool acceptance, bool start, bool progress, bool completion)
{
    assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TC, PUS_SETTCACKFLAGS, 0);
        return;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_HEADER_MISMATCH, PUS_SETTCACKFLAGS, 0);
        return;
    }
    else
    {
		packet->data.u.tcData.header.ackFlags.acceptanceReportRequested = acceptance;
		packet->data.u.tcData.header.ackFlags.startReportRequested = start;
		packet->data.u.tcData.header.ackFlags.progressReportRequested = progress;
		packet->data.u.tcData.header.ackFlags.completionReportRequested = completion;
    }
}


// Utility functions for packet header types

pusSequenceCount_t pus_incrementSequenceCount(pusSequenceCount_t count)
{
    return (count + 1) % pusSequenceCount_LIMIT;
}



// CCSDS packet initialization

void pus_setPacketDefaults(pusPacket_t* packet)
{
    assert(NULL != packet);

    pus_setPacketVersion(packet, pus_PACKET_VERSION_CURRENT);
    pus_setPacketType(packet, pus_TM);
    pus_setSecondaryHeaderFlag(packet, false);
    pus_setApid(packet, pus_APID_IDLE);
    pus_setSequenceFlags(packet, pus_STANDALONE_PACKET);
    pus_setSequenceCount(packet, 0);
    pus_setPacketDataNone(packet);
}

void pus_initTmPacket(pusPacket_t* packet)
{
    assert(NULL != packet);

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
}

void pus_initTmPacketNoHeader(pusPacket_t* packet)
{
    assert(NULL != packet);

    // CCSDS header
    pus_setPacketDefaults(packet);
    pus_setPacketType(packet, pus_TM);
    pus_setSecondaryHeaderFlag(packet, false);
    pus_setPacketDataKind(packet, pus_TM_DATA_NO_HEADER);
}

void pus_initTcPacket(pusPacket_t* packet)
{
	assert(NULL != packet);

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
}

void pus_initTcPacketNoHeader(pusPacket_t* packet)
{
    assert(NULL != packet);

    // CCSDS header
    pus_setPacketDefaults(packet);
    pus_setPacketType(packet, pus_TC);
    pus_setSecondaryHeaderFlag(packet, false);
    pus_setPacketDataKind(packet, pus_TC_DATA_NO_HEADER);
}




// Verification of packets

pusError_t pus_verifyCcsdsHeaderDefaults(const pusPacket_t* packet)
{
	assert(NULL != packet);

	if (pus_PACKET_VERSION_CURRENT != pus_getPacketVersion(packet))
	{
		return PUS_ERROR_UNEXPECTED_PACKET_VERSION;
	}
	else if (pus_STANDALONE_PACKET != pus_getSequenceFlags(packet))
	{
		return PUS_ERROR_UNEXPECTED_SEQUENCE_FLAGS;
	}
	else
	{
		return PUS_NO_ERROR;
	}
}

pusError_t pus_verifyPacketDataKind(const pusPacket_t* packet)
{
	assert(NULL != packet);

	if (pus_TM == pus_getPacketType(packet))
	{
		if (pus_getSecondaryHeaderFlag(packet))
		{
			if (pus_TM_DATA == pus_getPacketDataKind(packet))
			{
				return PUS_NO_ERROR;
			}
			else
			{
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
				return PUS_ERROR_HEADER_MISMATCH;
			}
		}
	}
	else
	{
		assert(false);
		return PUS_ERROR_PACKET_TYPE;
	}
}

pusError_t pus_verifyTmSecondaryHeaderDefaults(const pusPacket_t* packet)
{
	assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
    	return PUS_ERROR_NOT_TM;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        return PUS_ERROR_HEADER_MISMATCH;
    }
    else
    {
		if (pus_VERSION_CURRENT != pus_getTmPusVersion(packet))
		{
			return PUS_ERROR_UNEXPECTED_PUS_VERSION;
		}
		else
		{
			return PUS_NO_ERROR;
		}
    }
}

pusError_t pus_verifyTmHeaderDefaults(const pusPacket_t* packet)
{
	assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        return PUS_ERROR_NOT_TM;
    }

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

pusError_t pus_verifyTcSecondaryHeaderDefaults(const pusPacket_t* packet)
{
	assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TC_DATA == pus_getPacketDataKind(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
    	return PUS_ERROR_NOT_TC;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TC_DATA != pus_getPacketDataKind(packet))
    {
        return PUS_ERROR_HEADER_MISMATCH;
    }
    else
    {
		if (pus_VERSION_CURRENT != pus_getTcPusVersion(packet))
		{
			return PUS_ERROR_UNEXPECTED_PUS_VERSION;
		}
		else
		{
			return PUS_NO_ERROR;
		}
    }
}

pusError_t pus_verifyTcHeaderDefaults(const pusPacket_t* packet)
{
	assert(NULL != packet);
    assert(pus_TC == pus_getPacketType(packet));

    if (pus_TC != pus_getPacketType(packet))
    {
        return PUS_ERROR_NOT_TC;
    }

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




