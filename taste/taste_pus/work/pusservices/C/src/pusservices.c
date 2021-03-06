/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

/* User code: This file will not be overwritten by TASTE. */

#include "pusservices.h"

/* Function static data is declared in this file : */
#include "Context-pusservices.h"

#include "pusservices_config.h"
#include "pusservices_apid.h"
#include "pusservices_st01.h"
#include "pusservices_st03.h"
#include "pusservices_st05.h"
#include "pusservices_st08.h"
#include "pusservices_st09.h"
#include "pusservices_st11.h"
#include "pusservices_st17.h"
#include "pusservices_st18.h"
#include "pusservices_st20.h"
#include "pusservices_st23.h"
#include "pusservices_tcdispatch.h"
#include "pusservices_tm.h"
#include "pus_packet_queues.h"
#include "pus_packet_queues_config.h"


/* Counter for activation of the different actions */
unsigned int g_trigger_count = 0;

/*! TASTE function initialization */
void pusservices_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */

    /* Initialize APID */
    pusservices_initApid(pusservices_ctxt.apid);
    
    /* Event debug */
    pusservices_events_debugEventsTrigger();

    /* Initialize TC/TM queues */
	pus_packetQueues_initialize();


    /* Initialize services */
    pusservices_initService01();
    pusservices_initService03();
    pusservices_initService05();
    pusservices_initService08();
    pusservices_initService09();
    pusservices_initService11();
    pusservices_initService12();
    pusservices_initService17();
    pusservices_initService18();
    pusservices_initService19();
    pusservices_initService20();
    pusservices_initService23();

    // #ifdef PUSSERVICES_DISPATCH_OTHER_TC_ENABLED
    // pusservices_initOtherServices();
    // #endif

}

/*! TASTE PI: ack (protected)
 * 
 * Send a PUS 1 ACK report. 
 * 
 * This function is exposed as a PI so that external functions 
 * implementing mission-specific services can emit PUS 1 TM.
 *
 * The code of the PusServices function uses the same function to
 * ensure protected access to internal data.
 */
void pusservices_PI_ack(const asn1SccPusPacket *IN_tcPacket, 
                        const asn1SccPusSubserviceType *IN_reportType,
                        const asn1SccPusSt01FailureCode *IN_error,
                        const asn1SccPusSt01FailureInfo *IN_errorInfo,
                        const asn1SccPusStepId *IN_step)
{
    pusservices_st01Ack(IN_tcPacket, *IN_reportType, *IN_error, IN_errorInfo, *IN_step);
}


/*! TASTE PI: addTC (protected)
 * 
 * Add a Tc packet to the queue to be dispatched and executed.
 * 
 * This function is exposed as a PI so that external functions 
 * implementing mission-specific services can emit TCs.
 *
 * The code of the PusServices function uses the same function to
 * ensure protected access to internal data.
 */
void pusservices_PI_addTc(const asn1SccPusPacket *IN_tcPacket)
{
	pusError_t error = PUS_EXPECT_TC(IN_tcPacket);
	if (PUS_NO_ERROR != error )
	{
		printf("ERROR pusservices_PI_newTc: wrong TC, code %d\n", error);
		return;
	}

	error = pus_packetQueues_push(IN_tcPacket, TC_QUEUE_ONBOARD);
	if (PUS_NO_ERROR == error )
	{
		printf("INFO pusservices_PI_newTc: TC%llu_%llu inserted in TcQueue.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));
	}
	else if (PUS_ERROR_FULL_QUEUE == error )
	{
		printf("ERROR pusservices_PI_newTc: PUS_ERROR_FULL_QUEUE, %d\n", error);
	}
	else
	{
		printf("ERROR pusservices_PI_newTc: cannot push, code %d\n", error);
		return;
	}
}


/*! TASTE PI: addTm (protected)
 * 
 * Add a TM packet to the queue to be sent to ground.
 * 
 * This function is exposed as a PI so that external functions 
 * implementing mission-specific services can emit TM.
 *
 * The code of the PusServices function uses the same function to
 * ensure protected access to internal data.
 */
void pusservices_PI_addTm(const asn1SccPusPacket *IN_tmPacket)
{
    pusError_t error = pusservices_queueTm(IN_tmPacket);
    if (PUS_NO_ERROR != error)
    {
        printf("ERROR pusservices_PI_addTm: code %d (continue)\n", error);
    }
}


/*! TASTE PI: newTc
 * 
 * Receive a TC request from Ground. The TC is enqueued using the 
 * protected PI/RI addTc.
 */
void pusservices_PI_newTc(const asn1SccPusPacket *IN_tcPacket)
{
    pusservices_PI_addTc(IN_tcPacket);
}


void pusservices_PI_trigger()
{
    int count = 0;
    
    /* Process TCs */
    if (g_trigger_count % PUSSERVICES_TC_FREQUENCY == PUSSERVICES_TC_OFFSET)
    {
        for(count = 0; count < PUSSERVICES_TC_COUNT; count++)
        {
            pusservices_dispatchTc();
        }
    }

    /* Service 3 */
    if (g_trigger_count % PUSSERVICES_PUS03_FREQUENCY == PUSSERVICES_PUS03_OFFSET)
    {
        for(count = 0; count < PUSSERVICES_PUS03_COUNT; count++)
        {
            // pusservices_st03HkReportTrigger();
        }
    }


    /* Service 5 */
    if (g_trigger_count % PUSSERVICES_PUS05_FREQUENCY == PUSSERVICES_PUS05_OFFSET)
    {
        for(count = 0; count < PUSSERVICES_PUS05_COUNT; count++)
        {
            // pusservices_st05_EventReportTrigger();
        }
    }
    
    /* Service 11 */
    if (g_trigger_count % PUSSERVICES_PUS11_FREQUENCY == PUSSERVICES_PUS11_OFFSET)
    {
        for(count = 0; count < PUSSERVICES_PUS11_COUNT; count++)
        {
            // pusservices_st11runNextTc();
        }
    }

    /* Service 12 */
    if (g_trigger_count % PUSSERVICES_PUS12_FREQUENCY == PUSSERVICES_PUS12_OFFSET)
    {
        for(count = 0; count < PUSSERVICES_PUS12_COUNT; count++)
        {   
            // pusservices_st12_PmonTrigger();
        }
    }

    /* Service 19 */
    if (g_trigger_count % PUSSERVICES_PUS19_FREQUENCY == PUSSERVICES_PUS19_OFFSET)
    {
        for(count = 0; count < PUSSERVICES_PUS19_COUNT; count++)
        {   
            // pusservices_st19_EventActionTrigger();
        }
    }
    
    
    
    /* Send TMs */
    if (g_trigger_count % PUSSERVICES_TM_FREQUENCY == PUSSERVICES_TM_OFFSET)
    {
        for(count = 0; count < PUSSERVICES_TM_COUNT; count++)
        {
            pusservices_sendNextTm();
        }
    }
    
    /* Increment counter */
    g_trigger_count++;
}

void pusservices_PI_pushNewEvent(const asn1SccPusSt05Event *IN_eventInfo)
{
    pusservices_events_pushNewEvent(*IN_eventInfo);
}

void pusservices_PI_setParamValue(const asn1SccPusSt03ParameterId * IN_paramId,
                                  const asn1SccPusSt03StoredParam * IN_paramValue)
{
    pus_hk_setStoredParam(*IN_paramId, *IN_paramValue);
}

void pusservices_PI_getParamValue(const asn1SccPusSt03ParameterId * IN_paramId,
                                  asn1SccPusSt03StoredParam * OUT_paramValue,
                                  asn1SccPusSt01FailureCode * OUT_isAvailable)
{
    *OUT_isAvailable = pus_hk_getStoredParam(*IN_paramId, *OUT_paramValue); //TODO: check availability
}

void pusservices_PI_setOnBoardParam(const asn1SccPusSt20OnBoardParameterId * IN_paramId,
                                    const asn1SccPusSt20StoredParam * IN_paramValue)
{
    pus_parameters_setStoredParam(*IN_paramId, *IN_paramValue);
}

void pusservices_PI_getOnBoardParam(const asn1SccPusSt20OnBoardParameterId * IN_paramId,
                                    asn1SccPusSt20StoredParam * OUT_paramValue,
                                    asn1SccPusSt01FailureCode * OUT_isAvailable)
{
    *OUT_isAvailable = pus_parameters_getStoredParam(*IN_paramId, OUT_paramValue);
}

