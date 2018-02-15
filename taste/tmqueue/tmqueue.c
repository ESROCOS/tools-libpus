/* User code: This file will not be overwritten by TASTE. */

#include "tmqueue.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

#include "pus_st01_packets.h"

#include "pus_packet_queues_config.h"

void tmqueue_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}



void tmqueue_PI_tmRequest(asn1SccPusPacket *OUT_tmPacket, asn1SccT_Boolean *OUT_isAvailable)
{
	*OUT_isAvailable = false;

	pusError_t error = pus_packetQueues_pop(OUT_tmPacket, pus_TM_QUEUE_ONBOARD);
	if ( PUS_NO_ERROR == error )
	{
		//printf("TmQUEUE: TM%llu_%llu to TcDispatch.\n", pus_getTmService(OUT_tmPacket), pus_getTmSubtype(OUT_tmPacket));
		*OUT_isAvailable = true;
	}
	else if ( PUS_ERROR_EMPTY_QUEUE == error)
	{
		//printf("Error in tmqueue_PI_tmRequest EMPTY QUEUE, %d (no exit)\n", error);
		pus_clearError();
	}
	else
	{
		printf("Error in tmqueue_PI_tmRequest, %d\n", error);
		return;
	}
}

void tmqueue_PI_newTm(const asn1SccPusPacket *IN_tmPacket)
{
    /* Write your code here! */
	pusError_t error = PUS_EXPECT_TM(IN_tmPacket);
	if( PUS_NO_ERROR != error )
	{
		printf("Error in tmqueue_PI_newTm, %d (no exit)\n", error);
		return;
	}


	error = pus_packetQueues_push(IN_tmPacket, pus_TM_QUEUE_ONBOARD);
	if( PUS_NO_ERROR == error )
	{
		printf("TmQUEUE: TM%llu_%llu inserted in TmQueue.\n", pus_getTmService(IN_tmPacket), pus_getTmSubtype(IN_tmPacket));
		pusSt01FailureCode_t available = PUS_ERROR_NULLPTR;
		pusPacket_t tmPacket;
		tmqueue_RI_incCount(&tmPacket, &available);
		if( PUS_NO_ERROR == available)
		{
			while(PUS_NO_ERROR != pus_packetQueues_push(&tmPacket, pus_TM_QUEUE_ONBOARD));
			pus_clearError();
		}
	}
	else if (PUS_ERROR_FULL_QUEUE == error )
	{
		printf("TmQUEUE: PUS_ERROR_FULL_QUEUE, %d (no exit)\n", error);
		pus_clearError();
	}
	else
	{
		printf("Error in tmqueue_PI_newTm, %d (no exit)\n", error);
		pus_clearError();
		return;
	}
}
