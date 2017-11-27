#include "test_integration_01.h"



int main()
{
	printf("-- Test integration 01 begin.\n\n");

	// Initializations
	pusMutex_t mutexApid;
	pusMutex_t mutexEvents;
	pusMutex_t mutexHk;
	pusMutex_t mutexSt08;
	pus_mutexInitOk(&mutexApid);
	pus_mutexInitOk(&mutexEvents);
	pus_mutexInitOk(&mutexHk);
	pus_mutexInitOk(&mutexSt08);


	pusApidInfo_t apid;
	pus_initApidInfo(&apid, 23, &mutexApid);

	pus_packetQueues_initialize();
	pus_events_initialize(&mutexEvents);
	pus_hk_initialize(&mutexHk);
	pus_st08_initialize(&mutexSt08);

	//TC creation + push on queue
	pusPacket_t tc;
	pus_tc_17_1_createConnectionTestRequest(&tc, &apid);
	pus_setTcAckFlags(&tc, true, false, false, true);
	pus_packetQueues_push(&tc, &pus_packetQueue_tc);
	printf("TC_17_1 pushed in TCqueue.\n");

	pus_tc_8_1_createPerformFuctionRequest(&tc, &apid, EXAMPLE_FUNCTION_01);
	pus_packetQueues_push(&tc, &pus_packetQueue_tc);
	printf("TC_8_1 pushed in TCqueue.\n");

	pusSt05Event_t eventInfo, eventLow, eventMid, eventHi;
	pus_tm_5_X_setEventId(&eventInfo, EVENT_INFO_01);
	pus_tm_5_X_setEventAuxData1(&eventInfo.data, 10);
	pus_tm_5_X_setEventAuxData2(&eventInfo.data, 20);

	pus_tm_5_X_setEventId(&eventLow, EVENT_LOW_02);
	pus_tm_5_X_setEventAuxData1(&eventLow.data, 10);
	pus_tm_5_X_setEventAuxData2(&eventLow.data, 20);

	pus_tm_5_X_setEventId(&eventMid, EVENT_MEDIUM_03);
	pus_tm_5_X_setEventAuxData1(&eventMid.data, 10);
	pus_tm_5_X_setEventAuxData2(&eventMid.data, 20);

	pus_tm_5_X_setEventId(&eventHi, EVENT_HIGH_04);
	pus_tm_5_X_setEventAuxData1(&eventHi.data, 10);
	pus_tm_5_X_setEventAuxData2(&eventHi.data, 20);


	//Event TM packets to TMqueue
	pusPacket_t tm;

	pus_tm_5_1_createInformativeEventReport(&tm, &apid, &eventInfo, pus_st05_getEventDestination());
	pus_packetQueues_push(&tm, &pus_packetQueue_tm);
	printf("TM_5_1 pushed in TMqueue.\n");

	pus_tm_5_2_createLowSeverityEventReport(&tm, &apid, &eventLow, pus_st05_getEventDestination());
	pus_packetQueues_push(&tm, &pus_packetQueue_tm);
	printf("TM_5_2 pushed in TMqueue.\n");

	pus_tm_5_3_createMediumSeverityEventReport(&tm, &apid, &eventMid, pus_st05_getEventDestination());
	pus_packetQueues_push(&tm, &pus_packetQueue_tm);
	printf("TM_5_3 pushed in TMqueue.\n");

	pus_tm_5_4_createHighSeverityEventReport(&tm, &apid, &eventHi, pus_st05_getEventDestination());
	pus_packetQueues_push(&tm, &pus_packetQueue_tm);
	printf("TM_5_4 pushed in TMqueue.\n");


	//TC read from queue
	pusPacket_t tcRead;
	while ( PUS_NO_ERROR == pus_packetQueues_pop(&tcRead, &pus_packetQueue_tc) )
	{
		switch(pus_getTcService(&tcRead))
		{
			case 0:
				printf("Packet in TCqueue which is not a TCpacket.\n");
				break;

			case 8:
				printf("TC%llu_%llu received.\n", pus_getTcService(&tcRead), pus_getTcSubtype(&tcRead));

				pus_st08_processTcPacket(&tcRead, &apid);

				break;

			case 17:
				printf("TC%llu_%llu received.\n", pus_getTcService(&tcRead), pus_getTcSubtype(&tcRead));

				pus_st17_processTcPacket(&tcRead, &apid);

				break;

			default:
				printf("Exception.\n");
				break;
		}
	}




	//TM read from queue;
	pusPacket_t tmRead;
	while ( PUS_NO_ERROR == pus_packetQueues_pop(&tmRead, &pus_packetQueue_tm) )
	{
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



	printf("\n-- Test integration 01 end.\n");
	return 0;
}

pusError_t example_function() //TODO crear un .h para las funciones en ...¿?
{
	pusApidInfo_t apid;
	pus_initApidInfo(&apid, 12, NULL); //TODO param

	pusSt05Event_t eventInfo;
	pus_tm_5_X_setEventId(&eventInfo, EVENT_INFO_01);
	pus_tm_5_X_setEventAuxData1(&eventInfo.data, 10);
	pus_tm_5_X_setEventAuxData2(&eventInfo.data, 20);

	pusPacket_t tm;

	pus_tm_5_1_createInformativeEventReport(&tm, &apid, &eventInfo, pus_st05_getEventDestination());
	pus_packetQueues_push(&tm, &pus_packetQueue_tm);
	printf("TM_5_1 pushed in TMqueue FROM function.\n");

	return PUS_NO_ERROR;
}

pusError_t pus_st08_processTcPacket(pusPacket_t* tcRead, pusApidInfo_t* apid)
{
	bool isST08TcFlag = false;
	pusError_t errorExpect;

	if(PUS_NO_ERROR == (errorExpect = PUS_EXPECT_ST08(tcRead, pus_TC_8_1_performFunction)) )
	{
		isST08TcFlag = true;
	}

	pus_pushTmAceptanceReportIfNeeded(tcRead, apid, isST08TcFlag, errorExpect);

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
				pus_pushTmCompletionReportIfNeeded(tcRead, apid, isST08TcFlag, PUS_ERROR_UNEXPECTED_FUNCTION_ID);
			}

		}
		else
		{
			printf("ST08 not initialized\n");
		}

	}
	else
	{
		PUS_SET_ERROR(PUS_ERROR_TC_SERVICE);
	}

	pus_pushTmCompletionReportIfNeeded(tcRead, apid, isST08TcFlag, errorExpect);

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

	pus_pushTmAceptanceReportIfNeeded(tcRead, apid, isST17TcFlag, errorExpect);

	if( isST17TcFlag )
	{
		pusPacket_t tmResponse;
		pus_st17_createTestResponse(&tmResponse, apid, tcRead);
		pus_packetQueues_push(&tmResponse, &pus_packetQueue_tm);
		printf("TM_17_2(response) pushed in TMqueue.\n");
	}
	else
	{
		return PUS_ERROR_TC_SERVICE;
	}

	pus_pushTmCompletionReportIfNeeded(tcRead, apid, isST17TcFlag, errorExpect);

	return PUS_NO_ERROR;
}

pusError_t pus_pushTmAceptanceReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error)
{
	if(pus_getTcAckFlagAcceptance(tcRead))
	{
		pusPacket_t tmAcceptance;
		if( isCorrect )
		{
			pus_tm_1_1_createAcceptanceReportSuccess(&tmAcceptance, apid, tcRead);
		}
		else
		{
			pus_tm_1_2_createAcceptanceReportFailure(&tmAcceptance, apid, tcRead, error, NULL); //TODO error info Null
		}
		return pus_packetQueues_push(&tmAcceptance, &pus_packetQueue_tm);
	}
	return PUS_NO_ERROR;
}


pusError_t pus_pushTmStartReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error)
{
	if(pus_getTcAckFlagStart(tcRead))
	{
		pusPacket_t tmCompletion;
		if( isCorrect )
		{
			pus_tm_1_3_createStartReportSuccess(&tmCompletion, apid, tcRead);
		}
		else
		{
			pus_tm_1_4_createStartReportFailure(&tmCompletion, apid, tcRead, error, NULL);
		}
		return pus_packetQueues_push(&tmCompletion, &pus_packetQueue_tm);
	}
	return PUS_NO_ERROR;
}


pusError_t pus_pushTmProgressReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error, pusStepId_t step)
{
	if(pus_getTcAckFlagProgress(tcRead))
	{
		pusPacket_t tmCompletion;
		if( isCorrect )
		{
			pus_tm_1_5_createProgressReportSuccess(&tmCompletion, apid, tcRead, step);
		}
		else
		{
			pus_tm_1_6_createProgressReportFailure(&tmCompletion, apid, tcRead, step, error, NULL);
		}
		return pus_packetQueues_push(&tmCompletion, &pus_packetQueue_tm);
	}
	return PUS_NO_ERROR;
}


pusError_t pus_pushTmCompletionReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error)
{
	if(pus_getTcAckFlagCompletion(tcRead))
	{
		pusPacket_t tmCompletion;
		if( isCorrect )
		{
			pus_tm_1_7_createCompletionReportSuccess(&tmCompletion, apid, tcRead);
		}
		else
		{
			pus_tm_1_8_createCompletionReportFailure(&tmCompletion, apid, tcRead, error, NULL);
		}
		return pus_packetQueues_push(&tmCompletion, &pus_packetQueue_tm);
	}
	return PUS_NO_ERROR;
}


