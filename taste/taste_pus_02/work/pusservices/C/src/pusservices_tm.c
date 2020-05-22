/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */


#include "pusservices_config.h"
#include "pusservices.h"
#include "pusservices_tm.h"
#include "pusservices_st09.h"
#include "pus_packet_queues_config.h"


/*! Queue a TM for sending to Ground */
pusError_t pusservices_queueTm(const pusPacket_t *tmPacket)
{
	pusError_t error = PUS_EXPECT_TM(tmPacket);
	if (PUS_NO_ERROR != error )
	{
		printf("ERROR pusservices_dispatchTc: wrong TM, code %d (continue)\n", error);
		return error;
	}

	error = pus_packetQueues_push(tmPacket, TM_QUEUE_ONBOARD);
	if (PUS_NO_ERROR == error )
	{
		printf("pusservices_dispatchTc: TM%llu_%llu inserted in TmQueue.\n", pus_getTmService(tmPacket), pus_getTmSubtype(tmPacket));
        
        #ifdef PUSSERVICES_09_ENABLED
		pusservices_st09notifyTm();
        #endif
	}
	else if (PUS_ERROR_FULL_QUEUE == error )
	{
		printf("ERROR pusservices_dispatchTc: PUS_ERROR_FULL_QUEUE, %d (continue)\n", error);
		pus_clearError();
	}
	else
	{
		printf("ERROR pusservices_dispatchTc: code %d (continue)\n", error);
		pus_clearError();
		return error;
	}
    
    return PUS_NO_ERROR;
}


/*! Get the next TM from the TM queue 
 * 
 * Return PUS_NO_ERROR if success, PUS_ERROR_EMPTY_QUEUE if no TM 
 * available, or other error code.
 */
pusError_t pusservices_getNextTm(pusPacket_t *out_tmPacket)
{
	pusError_t error = pus_packetQueues_pop(out_tmPacket, TM_QUEUE_ONBOARD);

	if ( PUS_ERROR_EMPTY_QUEUE == error)
	{
		//printf("pusservices_getNextTm EMPTY QUEUE(continue)\n");
		pus_clearError();
        return PUS_ERROR_EMPTY_QUEUE;
	}
	else
	{
		//printf("ERROR pusservices_getNextTm: code %d\n", error);
		pus_clearError();
		return error;
	}
    
    return PUS_NO_ERROR;
}


/*! Send one TM (if available) to Ground */
void pusservices_sendNextTm(void)
{
	pusPacket_t tm;
    pusError_t error = pusservices_getNextTm(&tm);

    if ( PUS_ERROR_EMPTY_QUEUE == error )
    {
		//printf("pusservices_send_tm: NO TM TO SEND\n");
		pus_clearError();
		return;
    }
    else if (PUS_NO_ERROR != error )
	{
		printf("ERROR pusservices_send_tm: code %d (continue)\n", error);
		pus_clearError();
		return;
	}

	error = PUS_EXPECT_TM(&tm);
	if ( PUS_NO_ERROR == error)
	{
		printf("pusservices_send_tm send TM%llu_%llu\n", pus_getTmService(&tm), pus_getTmSubtype(&tm));
		pusservices_RI_newTm(&tm);
	}
	else
	{
		printf("ERROR pusservices_send_tm: wront TM, code %d (continue)\n", error);
		pus_clearError();
	}
}

