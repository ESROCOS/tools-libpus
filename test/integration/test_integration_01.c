#include "test_integration_01.h"



int main()
{
	printf("-- Test integration 01 begin.\n\n");

	// Initializations
	pusMutex_t mutexApid;
	pusMutex_t mutexEvents;
	pus_mutexInitOk(&mutexApid);
	pus_mutexInitOk(&mutexEvents);

	pusApidInfo_t apid;
	pus_initApidInfo(&apid, 23, &mutexApid);

	pus_packetQueues_initialize();
	pus_events_initialize(&mutexEvents);

	//TC creation + push on queue
	pusPacket_t tc;
	pus_tc_17_1_createConnectionTestRequest(&tc, &apid);
	pus_setTcAckFlags(&tc, true, false, false, true);
	pus_packetQueues_push(&tc, &pus_packetQueue_tc);
	printf("TC_17_1 pushed in TCqueue.\n");

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

			case 17:
				printf("TC%llu_%llu received.\n", pus_getTcService(&tcRead), pus_getTcSubtype(&tcRead));

				pus_st05(&apid, &tcRead);

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


pusError_t pus_st05(pusApidInfo_t* apid, pusPacket_t* tcRead)
{
	bool isST07TcFlag = false;
	pusError_t errorExpect;

	if(PUS_NO_ERROR == (errorExpect = PUS_EXPECT_ST17TC(tcRead, pus_TC_17_1_connectionTest)) )
	{
		isST07TcFlag = true;
	}

	if(pus_getTcAckFlagAcceptance(tcRead)) //todo cambiar por funcion (paquete, flag, error)
	{
		pusPacket_t tmAcceptance;
		if( isST07TcFlag )
		{
			//generate ACCEPTANCE SUCCES
			pus_tm_1_1_createAcceptanceReportSuccess(&tmAcceptance, apid, tcRead);
		}
		else
		{
			//generate ACCEPTANCE FAIL
			pus_tm_1_2_createAcceptanceReportFailure(&tmAcceptance, apid, tcRead, errorExpect, NULL); //TODO error info Null
		}
		pus_packetQueues_push(&tmAcceptance, &pus_packetQueue_tm);
	}

	if( isST07TcFlag )
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

	//pusError_t pus_createCompletionReport(pusPacket_t* tc, pusAp);
	if(pus_getTcAckFlagCompletion(tcRead))
	{
		pusPacket_t tmCompletion;
		if( isST07TcFlag )
		{
			//generate Completion SUCCES
			pus_tm_1_7_createCompletionReportSuccess(&tmCompletion, apid, tcRead);
		}
		else
		{
			//generate Completion FAIL
			pus_tm_1_8_createCompletionReportFailure(&tmCompletion, apid, tcRead, errorExpect, NULL);
		}
		pus_packetQueues_push(&tmCompletion, &pus_packetQueue_tm);
	}

	return PUS_NO_ERROR;
}

