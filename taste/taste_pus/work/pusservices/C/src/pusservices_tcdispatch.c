/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pusservices_tcdispatch.h"
#include "pusservices_config.h"
#include "pusservices_st03.h"
#include "pusservices_st08.h"
#include "pusservices_st09.h"
#include "pusservices_st11.h"
#include "pusservices_st17.h"
#include "pus_packet_queues_config.h"


/*! Pop the first available TC from the TC queue
 * 
 * Returns PUS_NO_ERROR if success, PUS_ERROR_EMPTY_QUEUE if no TCs,
 * error code otherwise.
 */
pusError_t pusservices_popTc(asn1SccPusPacket *outTcPacket)
{
	pusError_t result = pus_packetQueues_pop(outTcPacket, TC_QUEUE_ONBOARD);

	if (PUS_NO_ERROR != result)
    {
        if (PUS_ERROR_EMPTY_QUEUE == result)
        {
            //printf("pusservices_popTc EMPTY QUEUE (continue)\n");
        }
        else
        {
            printf("ERROR pusservices_popTc: code %d (continue)\n", result);
        }
    }
    
    return result;
}



/*! Dispatch next TC
 * 
 * Get the next TC packet from the TC queue, check the header and 
 * dispatch for execution by the corresponding service (by the PUS
 * library of a user-provided function.
 */
void pusservices_dispatchTc(void)
{
    /* Write your code here! */
	pusPacket_t tc;
	pusError_t isAvailable;

	//printf("pusservices_dispatchTc\n");

	isAvailable = pusservices_popTc(&tc);
	if (PUS_NO_ERROR != isAvailable )
	{
		//printf("PusServices.dispatch_tc NO DATA READ (continue)\n");
		pus_clearError();
		return;
	}

	pusError_t error = PUS_EXPECT_TC(&tc);
	if ( PUS_NO_ERROR == error)
	{
		printf("pusservices_dispatchTc: TC%llu_%llu\n", pus_getTcService(&tc), pus_getTcSubtype(&tc));

		switch(pus_getTcService(&tc))
		{
			#ifdef PUSSERVICES_03_ENABLED
			case 3:
				pusservices_processTc03(&tc);
				break;
            #endif
            #ifdef PUSSERVICES_08_ENABLED
			case 8:
				pusservices_processTc08(&tc);
				break;
            #endif

            #ifdef PUSSERVICES_09_ENABLED
			case 9:
				pusservices_processTc09(&tc);
				break;
            #endif

            #ifdef PUSSERVICES_11_ENABLED
			case 11:
				pusservices_processTc11(&tc);
				break;
            #endif

            #ifdef PUSSERVICES_12_ENABLED
			case 12:
				pusservices_processTc12(&tc);
				break;
            #endif

            #ifdef PUSSERVICES_17_ENABLED
			case 17:
				pusservices_processTc17((pusPacket_t*)&tc);
				break;
            #endif

            #ifdef PUSSERVICES_18_ENABLED
			case 18:
				pusservices_processTc18(&tc);
				break;
            #endif

            #ifdef PUSSERVICES_19_ENABLED
			case 19:
				pusservices_processTc19(&tc);
				break;
            #endif

            #ifdef PUSSERVICES_20_ENABLED
			case 20:
				pusservices_processTc20(&tc);
				break;
            #endif

            #ifdef PUSSERVICES_23_ENABLED
			case 23:
				pusservices_processTc23(&tc);
				break;
            #endif

			default:
                #ifdef PUSSERVICES_DISPATCH_OTHER_TC_ENABLED
                pusError_t result = pusservices_dispatchOtherTc(&tc);
                if (PUS_NO_ERROR != result)
                {
                    printf("ERROR pusservices_dispatchTc, cannot dispatch TC of service %llu, code %d (continue)\n", pus_getTcService(&tc), result);
                }
                #else
                printf("ERROR pusservices_dispatchTc, wrong service %llu (continue)\n", pus_getTcService(&tc));
                #endif
				return;
		}

	}
	else
	{
		printf("ERROR pusservices_dispatchTc, wrong TC packet - code %d (continue)\n", error);
		pus_clearError();
	}
}
