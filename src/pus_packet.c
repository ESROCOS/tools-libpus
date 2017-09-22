#include <assert.h>

#include "pus_packet.h"

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
    }
    
    packet->sequenceCount = countWrapped;
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
    pus_setPacketDataLength(packet, 0);
}

//! Initialize a TM packet
void pus_InitTmPacket(pusPacket_t* packet)
{
    assert(NULL != packet);

    // CCSDS header
    pus_setPacketDefaults(packet);
    pus_setPacketType(packet, pus_TM);
    
    
    
    
}

