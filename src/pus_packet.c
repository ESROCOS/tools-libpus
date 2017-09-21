#include "pus_packet.h"


int dummy(int a)
{
    pusPacket_t p;
    p.apid = a;
    return p.apid;
}


//! Set default values for a CCDS packet
pus_result_t pus_setPacketDefaults(pusPacket_t* packet)
{
    pus_result_t result = PUS_FAIL;
    
    if (NULL == packet)
    {
        result = PUS_NULLPTR;
    }
    else
    {
        packet->packetVersion = pusPacketVersionCurrent;
        packet->packetType = pusTm;
        packet->secondaryHeaderFlag = FALSE;
        packet->apid = pusApidIdle;
        packet->sequenceFlags = pusStandalonePacket;
        packet->sequenceCount = 0;
        packet->dataLength = 0;
        
        result = PUS_SUCCESS;
    }

    return result;
}



