/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

#include "test_integration_01.h"



#if defined(RTEMS_POSIX)
#include <bsp.h>
#include <stdlib.h>
#include <stdio.h>
#include <sched.h>

int *POSIX_Init()
#else
int main()
#endif
{
	printf("-- Test integration 01 begin.\n\n");
	printf("%llu %llu\n", TC_QUEUE_ONBOARD, PUS_PACKET_QUEUES_LIMIT);

	pusError_t err;

	// Initializations
	pusMutex_t mutexApid;
	pusMutex_t mutexEvents;
	pusMutex_t mutexHk;
	pusMutex_t mutexSt08;
	pusMutex_t mutexEventAction;
	pusMutex_t mutexPmon;
	pus_mutexInitOk(&mutexApid);
	pus_mutexInitOk(&mutexEvents);
	pus_mutexInitOk(&mutexHk);
	pus_mutexInitOk(&mutexSt08);
	pus_mutexInitOk(&mutexEventAction);
	pus_mutexInitOk(&mutexPmon);

	pusApidInfo_t apid;
	pus_initApidInfo(&apid, 23, &mutexApid);

	pus_packetQueues_initialize();
	pus_events_initialize(&mutexEvents);
	pus_hk_initialize(&mutexHk);
	pus_st08_initialize(&mutexSt08);
	pus_eventAction_initialize(&mutexEventAction);
	pus_pmon_initialize(&mutexPmon);

	//TC creation + push on queue
	pusPacket_t tc;
	err = pus_tc_17_1_createConnectionTestRequest(&tc, apid.apid, pus_getNextPacketCount(&apid));
	pus_setTcAckFlags(&tc, true, false, false, true);
	err = pus_packetQueues_push(&tc, TC_QUEUE_ONBOARD);
	printf("TC_17_1 pushed in TCqueue.\n");

	pus_tc_8_1_createPerformFuctionRequest(&tc, apid.apid, pus_getNextPacketCount(&apid), EXAMPLE_FUNCTION_01);
	pus_packetQueues_push(&tc, TC_QUEUE_ONBOARD);
	printf("TC_8_1 pushed in TCqueue.\n");


	pusSt05Event_t eventInfo, eventLow, eventMid, eventHi;
	pus_events_setEventId(&eventInfo, EVENT_INFO_01);
	pus_events_setEventAuxData1(&eventInfo.data, 10);
	pus_events_setEventAuxData2(&eventInfo.data, 20);
	pus_st05_pushBufferEvent(&eventInfo);

	pus_events_setEventId(&eventLow, EVENT_LOW_02);
	pus_events_setEventAuxData1(&eventLow.data, 10);
	pus_events_setEventAuxData2(&eventLow.data, 20);
	pus_st05_pushBufferEvent(&eventLow);

	pus_events_setEventId(&eventMid, EVENT_MEDIUM_03);
	pus_events_setEventAuxData1(&eventMid.data, 10);
	pus_events_setEventAuxData2(&eventMid.data, 20);
	pus_st05_pushBufferEvent(&eventHi);

	pus_events_setEventId(&eventHi, EVENT_HIGH_04);
	pus_events_setEventAuxData1(&eventHi.data, 10);
	pus_events_setEventAuxData2(&eventHi.data, 20);
	pus_st05_pushBufferEvent(&eventHi);

	pusPacket_t tcAction;
	pus_tc_8_1_createPerformFuctionRequest(&tcAction, apid.apid, pus_getNextPacketCount(&apid), EXAMPLE_FUNCTION_02);
	pus_tc_19_1_createAddEventActionDefinitionsRequest(&tc, apid.apid, pus_getNextPacketCount(&apid), eventInfo.eventId, &tcAction);
	pus_packetQueues_push(&tc, TC_QUEUE_ONBOARD);
	printf("TC_19_1 pushed in TCqueue.\n");

	pus_tc_19_4_createEnableEventActionDefinitions(&tc, apid.apid, pus_getNextPacketCount(&apid), eventInfo.eventId);
	pus_packetQueues_push(&tc, TC_QUEUE_ONBOARD);
	printf("TC_19_4 pushed in TCqueue.\n");

	//Event TM packets to TMqueue
	pusPacket_t tm;

	pus_tm_5_1_createInformativeEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &eventInfo, pus_st05_getEventDestination());
	pus_packetQueues_push(&tm, TM_QUEUE_ONBOARD);
	printf("TM_5_1 pushed in TMqueue.\n");

	pus_tm_5_2_createLowSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &eventLow, pus_st05_getEventDestination());
	pus_packetQueues_push(&tm, TM_QUEUE_ONBOARD);
	printf("TM_5_2 pushed in TMqueue.\n");

	pus_tm_5_3_createMediumSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &eventMid, pus_st05_getEventDestination());
	pus_packetQueues_push(&tm, TM_QUEUE_ONBOARD);
	printf("TM_5_3 pushed in TMqueue.\n");

	pus_tm_5_4_createHighSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &eventHi, pus_st05_getEventDestination());
	pus_packetQueues_push(&tm, TM_QUEUE_ONBOARD);
	printf("TM_5_4 pushed in TMqueue.\n");


	//TC read from queue
	pusPacket_t tcRead;
	//TM read from queue;
	pusPacket_t tmRead;

	int noTc = 0;
	int noTm = 0;

	while (noTc<2 || noTm<2)
	{
		err =  pus_packetQueues_pop(&tcRead, TC_QUEUE_ONBOARD);
		printf("ey %d\n", err);
		if ( PUS_NO_ERROR == err )
		{
			noTc = 0;

			switch(pus_getTcService(&tcRead))
			{
				case 0:
					printf("Packet in TCqueue which is not a TCpacket.\n");
					break;

				case 8:
					printf("TC%llu_%llu received.\n", pus_getTcService(&tcRead), pus_getTcSubtype(&tcRead));

					pus_st08_processTcPacket(&tcRead, &apid);

					break;
				case 12:
					printf("TC%llu_%llu received.\n", pus_getTcService(&tcRead), pus_getTcSubtype(&tcRead));

					pus_st12_processTcPacket(&tcRead, &apid);

					break;
				case 17:
					printf("TC%llu_%llu received.\n", pus_getTcService(&tcRead), pus_getTcSubtype(&tcRead));

					pus_st17_processTcPacket(&tcRead, &apid);

					break;
				case 19:
					printf("TC%llu_%llu received.\n", pus_getTcService(&tcRead), pus_getTcSubtype(&tcRead));
					pus_st19_processTcPacket(&tcRead, &apid);
					break;
				default:
					printf("Exception TC service.\n");
					break;
			}
		}else{
			noTc++;
		}


		if ( PUS_NO_ERROR == pus_packetQueues_pop(&tmRead, TM_QUEUE_ONBOARD) )
		{
			noTm = 0;
			//printf("pus_getTcService(&tmRead): %d", pus_getTmService(&tmRead))
			switch(pus_getTmService(&tmRead))
			{
				case 0:
					printf("Packet in TMqueue which is not a TMpacket.\n");
					break;

				case 1:
					printf("TM%llu_%llu received.\n", pus_getTmService(&tmRead), pus_getTmSubtype(&tmRead));

					break;

				case 3:
					printf("TM%llu_%llu received.\n", pus_getTmService(&tmRead), pus_getTmSubtype(&tmRead));

					break;

				case 5:
					printf("TM%llu_%llu received.\n", pus_getTmService(&tmRead), pus_getTmSubtype(&tmRead));

					break;

				case 17:
					printf("TM%llu_%llu received.\n", pus_getTmService(&tmRead), pus_getTmSubtype(&tmRead));

					break;

				default:
					printf("Exception.\n");
					break;
			}
		}
		else{
			noTm++;
		}
	}
	printf("HKS test\n");
	pus_pmon_enableFunction();
	pus_pmon_enableDefinition(HK_PARAM_INT01);
	pus_hk_setHK_PARAM_INT01(5);
	pus_pmon_enableDefinition(HK_PARAM_REAL01);
	pus_hk_setHK_PARAM_REAL01(8.236);
	pus_pmon_enableDefinition(HK_PARAM_INT02);
	pus_hk_setHK_PARAM_INT02(6);
	pus_hk_setHK_PARAM_UINT01(6);
	pus_hk_setHK_PARAM_BYTE01(4);
	pus_hk_setHK_PARAM_BOOL01(false);
	printf("HKS test %u\n", pus_st12_processPmonDefinitions());


	printf("\n-- Test integration 01 end.\n");
	return 0;
}

#if defined(RTEMS_POSIX)
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

#define CONFIGURE_MAXIMUM_POSIX_THREADS              10
#define CONFIGURE_POSIX_INIT_THREAD_TABLE

#define CONFIGURE_INIT
#include <rtems/confdefs.h>
#endif



pusError_t example_function()
{
	pusApidInfo_t apid;
	pus_initApidInfo(&apid, 12, NULL);

	pusSt05Event_t eventInfo;
	pus_events_setEventId(&eventInfo, EVENT_INFO_01);
	pus_events_setEventAuxData1(&eventInfo.data, 10);
	pus_events_setEventAuxData2(&eventInfo.data, 20);

	pusPacket_t tm;

	pus_tm_5_1_createInformativeEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &eventInfo, pus_st05_getEventDestination());
	pus_packetQueues_push(&tm, TM_QUEUE_ONBOARD);
	printf("TM_5_1 pushed in TMqueue FROM function.\n");

	return PUS_NO_ERROR;
}

pusError_t example_function2()
{
	printf("Hello from function2\n");
	return PUS_NO_ERROR;
}

pusError_t example_function3()
{
	printf("Hello from function3\n");
	return PUS_NO_ERROR;
}

pusError_t pus_st08_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid)
{
	bool isST08TcFlag = false;
	bool completion_flag = true;
	pusError_t errorExpect;

	if(PUS_NO_ERROR == (errorExpect = PUS_EXPECT_ST08(tcRead, pus_TC_8_1_performFunction)) )
	{
		isST08TcFlag = true;
	}

	pus_st01_pushTmAceptanceReportIfNeeded(tcRead, apid, isST08TcFlag, errorExpect);

	if( isST08TcFlag )
	{
		if( pus_st08_isInitialized() )
		{
			pusSt08FunctiontId_t functionId;
			pus_tc_8_1_getFunctionId(&functionId, tcRead);
			if( pus_st08_isInFunctionTable(functionId) )
			{
				pus_st08_functionTable[functionId]();
			}
			else
			{
				errorExpect = PUS_ERROR_UNEXPECTED_FUNCTION_ID;
				completion_flag = false;
				PUS_SET_ERROR(PUS_ERROR_UNEXPECTED_FUNCTION_ID);
			}

		}
		else
		{
			PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
		}

	}
	else
	{
		PUS_SET_ERROR(PUS_ERROR_TC_SERVICE);
	}

	pus_st01_pushTmCompletionReportIfNeeded(tcRead, apid, completion_flag, errorExpect);

	return PUS_GET_ERROR();
}


pusError_t pus_st09_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid)
{
	bool isST09TcFlag = false;
	bool completion_flag = false;
	pusError_t errorExpect;

	if(PUS_NO_ERROR == (errorExpect = PUS_EXPECT_ST09TC(tcRead, pusSubtype_NONE)) )
	{
		isST09TcFlag = true;
	}

	pus_st01_pushTmAceptanceReportIfNeeded(tcRead, apid, isST09TcFlag, errorExpect);

	if( isST09TcFlag )
	{
		pusSt09ExponentialRate_t expRate;
		pus_tc_9_1_getExponentialRate(&expRate, tcRead);
		pus_time_setReportGenerationExponentialRate(expRate);
	}
	else
	{
		errorExpect = PUS_SET_ERROR(PUS_ERROR_TC_SERVICE);
	}

	if( PUS_NO_ERROR != errorExpect)
	{
		completion_flag = false;
	}
	pus_st01_pushTmCompletionReportIfNeeded(tcRead, apid, completion_flag, errorExpect);

	return PUS_GET_ERROR();
}

pusError_t pus_st17_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid)
{
	bool isST17TcFlag = false;
	pusError_t errorExpect;

	if(PUS_NO_ERROR == (errorExpect = PUS_EXPECT_ST17TC(tcRead, pus_TC_17_1_connectionTest)) )
	{
		isST17TcFlag = true;
	}

	pus_st01_pushTmAceptanceReportIfNeeded(tcRead, apid, isST17TcFlag, errorExpect);

	if( isST17TcFlag )
	{
		pusPacket_t tmResponse;
		pus_st17_createTestResponse(&tmResponse, apid, tcRead);
		pus_packetQueues_push(&tmResponse, TM_QUEUE_ONBOARD);
		printf("TM_17_2(response) pushed in TMqueue.\n");
	}
	else
	{
		return PUS_ERROR_TC_SERVICE;
	}

	pus_st01_pushTmCompletionReportIfNeeded(tcRead, apid, isST17TcFlag, errorExpect);

	return PUS_NO_ERROR;
}


uint64_t actualSt19Counter = 0;
pusError_t pus_st19_processEventActionService()
{
	if( pus_eventAction_isInitialized() )
	{
		pusSt05Event_t event;
		if ( PUS_NO_ERROR ==  pus_st05_getNextBufferEvent(&event, &actualSt19Counter) )
		{
			if(pus_eventAction_isEventActionEnabled(event.eventId))
			{
				pusPacket_t tcAction;
				pus_eventAction_getAction(&tcAction, event.eventId);
				pus_packetQueues_push(&tcAction, TC_QUEUE_ONBOARD);
			}
		}

		return PUS_NO_ERROR;
	}
	else
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}
}

pusError_t pus_st19_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid)
{
	bool isST19TcFlag = false;
	bool completion_flag = false;
	pusError_t errorExpect;

	if(PUS_NO_ERROR == (errorExpect = PUS_EXPECT_ST19(tcRead, pusSubtype_NONE)) )
	{
		isST19TcFlag = true;
	}

	pus_st01_pushTmAceptanceReportIfNeeded(tcRead, apid, isST19TcFlag, errorExpect);

	if( isST19TcFlag )
	{
		if( pus_eventAction_isInitialized() )
		{
			pusSt05EventId_t eventID;
			if( PUS_NO_ERROR != pus_tc_19_X_getEventId(&eventID, tcRead))
			{
				errorExpect = PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
			}

			pusSubservice_t subtype = pus_getTcSubtype(tcRead);
			if( pus_TC_19_1_addEventActionDefinitions == subtype )
			{
				pusPacketReduced_t tcActionR;
				pusPacket_t tcAction;
				pus_tc_19_1_getAction(&tcActionR, tcRead);
				pus_packetReduced_createPacketFromPacketReduced(&tcAction, &tcActionR);
				errorExpect =  pus_eventAction_addEventActionDefinition(eventID, &tcAction);
			}
			else if( pus_TC_19_2_deleteEventActionDefinitions == subtype )
			{
				errorExpect = pus_eventAction_deleteEventActionDefinition(eventID);
			}
			else if( pus_TC_19_4_enableEventActionDefinitions == subtype )
			{
				errorExpect = pus_eventAction_enableEventActionDefinition(eventID);

				pus_st19_processEventActionService();//TODO no es el sitio

			}
			else if( pus_TC_19_5_disableEventActionDefinitions == subtype )
			{
				errorExpect = pus_eventAction_enableEventActionDefinition(eventID);
			}
			else
			{
				errorExpect = PUS_SET_ERROR(PUS_ERROR_TC_SUBTYPE);
			}

		}
		else
		{
			errorExpect = PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
		}

	}
	else
	{
		errorExpect = PUS_SET_ERROR(PUS_ERROR_TC_SERVICE);
	}

	if( PUS_NO_ERROR != errorExpect)
	{
		completion_flag = false;
	}
	pus_st01_pushTmCompletionReportIfNeeded(tcRead, apid, completion_flag, errorExpect);

	return PUS_GET_ERROR();
}

pusError_t pus_st12_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid)
{
	bool isST12TcFlag = false;
	bool completion_flag = false;
	pusError_t errorExpect;

	if(PUS_NO_ERROR == (errorExpect = PUS_EXPECT_ST12TC(tcRead, pusSubtype_NONE)) )
	{
		isST12TcFlag = true;
	}

	pus_st01_pushTmAceptanceReportIfNeeded(tcRead, apid, isST12TcFlag, errorExpect);

	if( isST12TcFlag )
	{
		if( pus_pmon_isInitialized() )
		{
			pusSubservice_t subtype = pus_getTcSubtype(tcRead);
			if( pus_TC_12_1_enableParameterMonitoringDefinitions == subtype )
			{
				pusSt12PmonId_t pmonId;
				pus_tc_12_1_2_getPmonId(&pmonId, tcRead);
				pus_pmon_enableDefinition(pmonId);
			}
			else if ( pus_TC_12_2_disableParameterMonitoringDefinitions == subtype )
			{
				pusSt12PmonId_t pmonId;
				pus_tc_12_1_2_getPmonId(&pmonId, tcRead);
				pus_pmon_disableDefinition(pmonId);
			}
			else if ( pus_TC_12_15_enableParameterMonitoring == subtype )
			{
				pus_pmon_enableFunction();
			}
			else if ( pus_TC_12_16_disableParameterMonitoring == subtype )
			{
				pus_pmon_disableFunction();
			}
			else
			{
				errorExpect = PUS_SET_ERROR(PUS_ERROR_TC_SUBTYPE);
			}
		}
		else
		{
			errorExpect = PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
		}

	}
	else
	{
		errorExpect = PUS_SET_ERROR(PUS_ERROR_TC_SERVICE);
	}

	if( PUS_NO_ERROR != errorExpect)
	{
		completion_flag = false;
	}
	pus_st01_pushTmCompletionReportIfNeeded(tcRead, apid, completion_flag, errorExpect);

	return PUS_GET_ERROR();
}

pusError_t pus_st12_processPmonDefinitions()
{
	if( pus_pmon_isInitialized() )
	{
		if ( pus_pmon_isFunctionActivated() )
		{
			for(pusSt12PmonId_t i = 0; i < pus_ST12_PARAM_LIMIT; i++)
			{
				if( PUS_NO_ERROR != pus_pmon_checkParameter(i))
				{
					//TODO create event, data? severity?
					//pus_events_createEVENT_ST12(event, idPMON, NONE);
					printf("Error in pmon %llu, error: %d\n", i, pus_pmon_checkParameter(i));
				}
			}
		}
		else
		{
			return PUS_ERROR_FUNCTION_NOT_ACTIVATED;
		}

		return PUS_NO_ERROR;
	}
	else
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}
}


//push to queue
pusError_t pus_st01_pushTmAceptanceReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error)
{
	if(pus_getTcAckFlagAcceptance(tcRead))
	{
		//get next sequence count

		pusPacket_t tmAcceptance;
		if( isCorrect )
		{
			pus_tm_1_1_createAcceptanceReportSuccess(&tmAcceptance, apid->apid, pus_getNextPacketCount(apid), tcRead);
		}
		else
		{
			pus_tm_1_2_createAcceptanceReportFailure(&tmAcceptance, apid->apid, pus_getNextPacketCount(apid), tcRead, error, NULL); //TODO error info Null
		}
		return pus_packetQueues_push(&tmAcceptance, TM_QUEUE_ONBOARD);
	}
	return PUS_NO_ERROR;
}


pusError_t pus_st01_pushTmStartReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error)
{
	if(pus_getTcAckFlagStart(tcRead))
	{
		pusPacket_t tmCompletion;
		if( isCorrect )
		{
			pus_tm_1_3_createStartReportSuccess(&tmCompletion, apid->apid, pus_getNextPacketCount(apid), tcRead);
		}
		else
		{
			pus_tm_1_4_createStartReportFailure(&tmCompletion, apid->apid, pus_getNextPacketCount(apid), tcRead, error, NULL);
		}
		return pus_packetQueues_push(&tmCompletion, TM_QUEUE_ONBOARD);
	}
	return PUS_NO_ERROR;
}


pusError_t pus_st01_pushTmProgressReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error, pusStepId_t step)
{
	if(pus_getTcAckFlagProgress(tcRead))
	{
		//get next sequence count
		pusPacket_t tmCompletion;
		if( isCorrect )
		{
			pus_tm_1_5_createProgressReportSuccess(&tmCompletion, apid->apid, pus_getNextPacketCount(apid), tcRead, step);
		}
		else
		{
			pus_tm_1_6_createProgressReportFailure(&tmCompletion, apid->apid, pus_getNextPacketCount(apid), tcRead, step, error, NULL);
		}
		return pus_packetQueues_push(&tmCompletion, TM_QUEUE_ONBOARD);
	}
	return PUS_NO_ERROR;
}


pusError_t pus_st01_pushTmCompletionReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error)
{
	if(pus_getTcAckFlagCompletion(tcRead))
	{
		//get next sequence count
		pusPacket_t tmCompletion;
		if( isCorrect )
		{
			pus_tm_1_7_createCompletionReportSuccess(&tmCompletion, apid->apid, pus_getNextPacketCount(apid), tcRead);
		}
		else
		{
			pus_tm_1_8_createCompletionReportFailure(&tmCompletion, apid->apid, pus_getNextPacketCount(apid), tcRead, error, NULL);
		}
		return pus_packetQueues_push(&tmCompletion, TM_QUEUE_ONBOARD);
	}
	return PUS_NO_ERROR;
}
