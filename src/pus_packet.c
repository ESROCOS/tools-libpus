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
        assert(FALSE);
        pus_setError(PUS_ERROR_NO_HEADER, PUS_GETPACKETDATAKIND, 0);
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
        assert(FALSE);
        packet->data.kind = PusPacketData_NONE;
        pus_setError(PUS_ERROR_NO_HEADER, PUS_SETPACKETDATAKIND, (pusErrorData_t)kind);
    }
}

pusVersion_t pus_getPusVersion(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet) || pus_TC_DATA == pus_getPacketDataKind(packet));
    
    pusPacketDataKind_t kind = pus_getPacketDataKind(packet);
    
    if (pus_getSecondaryHeaderFlag(packet))
    {
        if (pus_TM_DATA == kind)
        {
            return packet->data.u.tmData.header.pusVersion;
        }
        else if(pus_TC_DATA == kind)
        {
            return packet->data.u.tcData.header.pusVersion;
        }
        else
        {
            pus_setError(PUS_ERROR_NO_HEADER, PUS_GETPUSVERSION, 1);
            return pus_INVALID_VERSION;
        }
    }
    else
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_GETPUSVERSION, 2);
        return pus_INVALID_VERSION;
    }
}


void pus_setPusVersion(pusPacket_t* packet, pusVersion_t version)
{
    assert(NULL != packet);
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet) || pus_TC_DATA == pus_getPacketDataKind(packet));
    
    pusPacketDataKind_t kind = pus_getPacketDataKind(packet);
    
    if (pus_getSecondaryHeaderFlag(packet))
    {
        if (pus_TM_DATA == kind)
        {
            packet->data.u.tmData.header.pusVersion = version;
        }
        else if(pus_TC_DATA == kind)
        {
            packet->data.u.tcData.header.pusVersion = version;
        }
    }
    else
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_SETPUSVERSION, (pusErrorData_t)version);
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
        pus_setError(PUS_ERROR_NO_HEADER, PUS_GETTMSERVICE, 0);
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
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_GETTMSERVICE, (pusErrorData_t)service);
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
        pus_setError(PUS_ERROR_NO_HEADER, PUS_GETTMSUBTYPE, 0);
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
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_SETTMSUBTYPE, (pusErrorData_t)subtype);
    }
    else
    {
        packet->data.u.tmData.header.subtype = subtype;
    }
}

pusTimeRefStatus_t pus_getTimeReferenceStatus(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_GETTIMEREFSTATUS, 0);
        return pusService_NONE;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_GETTIMEREFSTATUS, 0);
        return pusService_NONE;
    }
    else
    {
        return packet->data.u.tmData.header.timeRefStatus;
    }
}

void pus_setTimeReferenceStatus(pusPacket_t* packet, pusTimeRefStatus_t status)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_SETTIMEREFSTATUS, (pusErrorData_t)status);
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_SETTIMEREFSTATUS, (pusErrorData_t)status);
    }
    else
    {
        packet->data.u.tmData.header.timeRefStatus = status;
    }
}

pusMsgTypeCount_t pus_getMessageTypeCounter(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_GETMESSAGETYPECOUNTER, 0);
        return pusService_NONE;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_GETMESSAGETYPECOUNTER, 0);
        return pusService_NONE;
    }
    else
    {
        return packet->data.u.tmData.header.msgTypeCount;
    }
}

void pus_setMessageTypeCounter(pusPacket_t* packet, pusMsgTypeCount_t count)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_SETMESSAGETYPECOUNTER, (pusErrorData_t)count);
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_SETMESSAGETYPECOUNTER, (pusErrorData_t)count);
    }
    else
    {
        packet->data.u.tmData.header.msgTypeCount = count;
    }
}

pusApid_t pus_getDestination(const pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_GETDESTINATION, 0);
        return pusService_NONE;
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_GETDESTINATION, 0);
        return pusService_NONE;
    }
    else
    {
        return packet->data.u.tmData.header.destination;
    }
}

void pus_setDestination(pusPacket_t* packet, pusApid_t destination)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_SETDESTINATION, (pusErrorData_t)destination);
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_SETDESTINATION, (pusErrorData_t)destination);
    }
    else
    {
        packet->data.u.tmData.header.destination = destination;
    }
}

void pus_getPacketTime(pusTime_t* outTime, const pusPacket_t* packet)
{
	assert(NULL != outTime);
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_GETPACKETTIME, 0);
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_GETPACKETTIME, 0);
    }
    else
    {
    	*outTime = packet->data.u.tmData.header.time;
    }
}

void pus_setPacketTime(pusPacket_t* packet, const pusTime_t* time)
{
    assert(NULL != packet);
    assert(NULL != time);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    if (pus_TM != pus_getPacketType(packet))
    {
        pus_setError(PUS_ERROR_NOT_TM, PUS_SETPACKETTIME, 0);
    }
    else if (!pus_getSecondaryHeaderFlag(packet) || pus_TM_DATA != pus_getPacketDataKind(packet))
    {
        pus_setError(PUS_ERROR_NO_HEADER, PUS_SETPACKETTIME, 0);
    }
    else
    {
        packet->data.u.tmData.header.time = *time;
    }
}

void pus_setPacketTimeNow(pusPacket_t* packet)
{
    assert(NULL != packet);
    assert(pus_TM == pus_getPacketType(packet));
    assert(pus_getSecondaryHeaderFlag(packet));
    assert(pus_TM_DATA == pus_getPacketDataKind(packet));

    pusTime_t now;
    pus_now(&now);
    pus_setPacketTime(packet, &now);
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
    pus_setSecondaryHeaderFlag(packet, FALSE);
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
    pus_setSecondaryHeaderFlag(packet, TRUE);
    pus_setPacketDataKind(packet, pus_TM_DATA);

    // Secondary header fields
    pus_setPusVersion(packet, pus_VERSION_CURRENT);
    pus_setTimeReferenceStatus(packet, pus_TIME_REFERENCE_STATUS_NONE);
    pus_setTmService(packet, pusService_NONE);
    pus_setTmSubtype(packet, pusSubtype_NONE);
    pus_setMessageTypeCounter(packet, pus_MESSAGE_TYPE_COUNTER_NONE);
    pus_setDestination(packet, pus_APID_IDLE);
    pus_setPacketTimeNow(packet);
}

