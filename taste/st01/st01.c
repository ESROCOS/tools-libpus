/* User code: This file will not be overwritten by TASTE. */

#include "st01.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

#include "pus_st01_packets.h"
#include "pus_st17_packets.h"

void st01_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void st01_PI_ACK(const asn1SccPusPacket *IN_tcPacket,
                 const asn1SccPusApid *IN_apid,
                 const asn1SccPusSequenceCount *IN_packetCounter,
                 const asn1SccT_Boolean *IN_isError,
                 const asn1SccPusSt01FailureCode *IN_error,
                 const asn1SccPusSt01FailureInfo *IN_errorInfo)
{
    /* Write your code here! */

	printf(" - ST01 Packet TC%llu_%llu received.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));

}

