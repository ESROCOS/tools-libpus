/* User code: This file will not be overwritten by TASTE. */

#include "groundtm.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

void groundtm_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void groundtm_PI_newTm(const asn1SccPusPacket *IN_tmPacket)
{
    /* Write your code here! */


	printf("TM%llu_%llu in TmGround.\n", pus_getTmService(IN_tmPacket), pus_getTmSubtype(IN_tmPacket));
}

