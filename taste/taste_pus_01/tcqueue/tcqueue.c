/* User code: This file will not be overwritten by TASTE. */

#include "tcqueue.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

#include "pus_packet_queues_config.h"

void tcqueue_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */

	pus_packetQueues_initialize(); // just one time, not in TmQueue
}

void tcqueue_PI_newTc(const asn1SccPusPacket *IN_tcPacket)
{
    /* Write your code here! */
	pusError_t error = PUS_EXPECT_TC(IN_tcPacket);
	if( PUS_NO_ERROR != error )
	{
		printf("Error in tcqueue_PI_newTc, %d (exit)\n", error);
		return;
	}

	error = pus_packetQueues_push(IN_tcPacket, TC_QUEUE_ONBOARD);
	if( PUS_NO_ERROR == error )
	{
		printf("TcQUEUE: TC%llu_%llu inserted in TcQueue.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
	}
	else if (PUS_ERROR_FULL_QUEUE == error )
	{
		printf("TcQUEUE: PUS_ERROR_FULL_QUEUE, %d\n", error);
	}
	else
	{
		printf("Error in tcqueue_PI_newTc, %d\n", error);
		return;
	}
}

void tcqueue_PI_tcRequest(asn1SccPusPacket *OUT_tcPacket, asn1SccPusSt01FailureCode *OUT_isAvailable)
{
    /* Write your code here! */


	pusError_t error = pus_packetQueues_pop(OUT_tcPacket, TC_QUEUE_ONBOARD);
	*OUT_isAvailable = error;

	if ( PUS_ERROR_EMPTY_QUEUE == error)
	{
		//printf("Error in tcqueue_PI_tcRequest EMPTY QUEUE, %d (no exit)\n", error);
		pus_clearError();
	}
	else
	{
		printf("Error in tcqueue_PI_tcRequest, %d\n", error);
		pus_clearError();
		return;
	}
}

