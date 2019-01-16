/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_events.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_st05_config.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "../../include/pus_st01_packets.h"
#include "../../include/pus_st03_packets.h"
#include "../../include/pus_st05_packets.h"


//Test Event struct (pusSt05Event_t)
void test_event()
{
	pusSt05Event_t event;

	pusSt05EventAuxData_t auxData;
	pusStoredParam_t auxData1 = 1;
	//pusStoredParam_t auxData2 = 2;

	// PUS_ERROR_NULLPTR TEST
	pus_events_setEventId(NULL, 1);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pus_EVENT_ID_NONE, pus_events_getEventId(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_events_setEventAuxData(NULL, auxData);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pusSt05EventAuxData_t auxDataNoneTest = pus_events_getEventAuxData(NULL);
	CU_ASSERT_EQUAL(pus_EVENT_AUXDATA_NONE.data1, auxDataNoneTest.data1);
	CU_ASSERT_EQUAL(pus_EVENT_AUXDATA_NONE.data2, auxDataNoneTest.data2);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_events_setEventAuxData1(NULL, 1);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pus_EVENT_DATASTORED_NONE, pus_events_getEventAuxData1(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_events_setEventAuxData2(NULL, 2);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pus_EVENT_DATASTORED_NONE, pus_events_getEventAuxData2(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();


	pus_events_setEventId(&event, 1);
	CU_ASSERT_EQUAL(1, pus_events_getEventId(&event));

	pus_events_setEventAuxData1(&auxData, auxData1);
	CU_ASSERT_EQUAL(auxData1, pus_events_getEventAuxData1(&auxData));

	pus_events_setEventAuxData2(&auxData, 2);
	CU_ASSERT_EQUAL(2, pus_events_getEventAuxData2(&auxData));

	pus_events_setEventAuxData(&event, auxData);
	CU_ASSERT_EQUAL(auxData.data1, pus_events_getEventAuxData(&event).data1);
	CU_ASSERT_EQUAL(auxData.data2, pus_events_getEventAuxData(&event).data2);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_events_createEVENT_ST12(&event, 1, 2));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_events_createEVENT_INFO_01(&event, 1, 2));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_events_createEVENT_LOW_02(&event, 1.25, 2));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_events_createEVENT_MEDIUM_03(&event, true, 0x23));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_events_createEVENT_HIGH_04(&event, 3, 4));

	pus_clearError();
}

void test_reports()
{
	pus_events_finalize();
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_events_initialize(NULL));

	pusPacket_t tm;
	pusApidInfo_t apid;
	pusSt05Event_t event, event2;

	pus_initApidInfo(&apid, 5, NULL); CU_ASSERT_FALSE(PUS_IS_ERROR());

	pus_events_setEventId(&event, 1); CU_ASSERT_FALSE(PUS_IS_ERROR());
	pus_events_setEventAuxData1(&event.data, 1); CU_ASSERT_FALSE(PUS_IS_ERROR());
	pus_events_setEventAuxData2(&event.data, 2); CU_ASSERT_FALSE(PUS_IS_ERROR());

	//TM[5,1]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_1_createInformativeEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST05(&tm, pus_TM_5_1_eventInformative));
	CU_ASSERT_EQUAL(1, pus_getTmDestination(&tm));
	CU_ASSERT_EQUAL(5, pus_getApid(&tm));
	CU_ASSERT_EQUAL(0, pus_getSequenceCount(&tm));
	CU_ASSERT_EQUAL(pus_ST05_eventReporting, pus_getTmService(&tm));
	CU_ASSERT_EQUAL(pus_TM_5_1_eventInformative, pus_getTmSubtype(&tm));
	CU_ASSERT_EQUAL(pus_TM_DATA_ST_5_X, pus_getTmDataKind(&tm));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_X_getTmEventReportData(&tm, &event2));
	CU_ASSERT_EQUAL(pus_events_getEventId(&event), pus_events_getEventId(&event2));
	CU_ASSERT_EQUAL(pus_events_getEventAuxData(&event).data1, pus_events_getEventAuxData(&event2).data1);
	CU_ASSERT_EQUAL(pus_events_getEventAuxData(&event).data2, pus_events_getEventAuxData(&event2).data2);

	//TM[5,2]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_2_createLowSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 2)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST05(&tm, pus_TM_5_2_anomalyLowSeverity));
	CU_ASSERT_EQUAL(2, pus_getTmDestination(&tm));
	CU_ASSERT_EQUAL(5, pus_getApid(&tm));
	CU_ASSERT_EQUAL(1, pus_getSequenceCount(&tm));
	CU_ASSERT_EQUAL(pus_ST05_eventReporting, pus_getTmService(&tm));
	CU_ASSERT_EQUAL(pus_TM_5_2_anomalyLowSeverity, pus_getTmSubtype(&tm));
	CU_ASSERT_EQUAL(pus_TM_DATA_ST_5_X, pus_getTmDataKind(&tm));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_X_getTmEventReportData(&tm, &event2));
	CU_ASSERT_EQUAL(pus_events_getEventId(&event), pus_events_getEventId(&event2));
	CU_ASSERT_EQUAL(pus_events_getEventAuxData(&event).data1, pus_events_getEventAuxData(&event2).data1);
	CU_ASSERT_EQUAL(pus_events_getEventAuxData(&event).data2, pus_events_getEventAuxData(&event2).data2);

	//TM[5,3]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_3_createMediumSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 3)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST05(&tm, pus_TM_5_3_anomalyMediumSeverity));
	CU_ASSERT_EQUAL(3, pus_getTmDestination(&tm));
	CU_ASSERT_EQUAL(5, pus_getApid(&tm));
	CU_ASSERT_EQUAL(2, pus_getSequenceCount(&tm));
	CU_ASSERT_EQUAL(pus_ST05_eventReporting, pus_getTmService(&tm));
	CU_ASSERT_EQUAL(pus_TM_5_3_anomalyMediumSeverity, pus_getTmSubtype(&tm));
	CU_ASSERT_EQUAL(pus_TM_DATA_ST_5_X, pus_getTmDataKind(&tm));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_X_getTmEventReportData(&tm, &event2));
	CU_ASSERT_EQUAL(pus_events_getEventId(&event), pus_events_getEventId(&event2));
	CU_ASSERT_EQUAL(pus_events_getEventAuxData(&event).data1, pus_events_getEventAuxData(&event2).data1);
	CU_ASSERT_EQUAL(pus_events_getEventAuxData(&event).data2, pus_events_getEventAuxData(&event2).data2);

	//TM[5,4]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_4_createHighSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 4)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST05(&tm, pus_TM_5_4_anomalyHighSeverity));
	CU_ASSERT_EQUAL(4, pus_getTmDestination(&tm));
	CU_ASSERT_EQUAL(5, pus_getApid(&tm));
	CU_ASSERT_EQUAL(3, pus_getSequenceCount(&tm));
	CU_ASSERT_EQUAL(pus_ST05_eventReporting, pus_getTmService(&tm));
	CU_ASSERT_EQUAL(pus_TM_5_4_anomalyHighSeverity, pus_getTmSubtype(&tm));
	CU_ASSERT_EQUAL(pus_TM_DATA_ST_5_X, pus_getTmDataKind(&tm));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_X_getTmEventReportData(&tm, &event2));
	CU_ASSERT_EQUAL(pus_events_getEventId(&event), pus_events_getEventId(&event2));
	CU_ASSERT_EQUAL(pus_events_getEventAuxData(&event).data1, pus_events_getEventAuxData(&event2).data1);
	CU_ASSERT_EQUAL(pus_events_getEventAuxData(&event).data2, pus_events_getEventAuxData(&event2).data2);
	pus_clearError();
}


void test_buffer()
{
	pus_events_finalize(); pus_clearError();
	CU_ASSERT_EQUAL(PUS_NO_ERROR , pus_events_initialize(NULL));
	CU_ASSERT_TRUE(pus_events_isInitialized());

	CU_ASSERT_EQUAL(1, pus_st05_getEventBufferCounter());
	CU_ASSERT_EQUAL(0, pus_st05_getEventBufferIn());

	pusSt05Event_t event;
	event.eventId = 1;
	event.data.data1 = 1;
	event.data.data2 = 2;

	CU_ASSERT_EQUAL(false, pus_events_isInInfoList(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());


	CU_ASSERT_EQUAL(true, pus_events_isInInfoList(&event));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_GET_ERROR());

	event.eventId = 15;
	CU_ASSERT_EQUAL(false, pus_events_isInInfoList(&event));
	CU_ASSERT_EQUAL(PUS_ERROR_EVENT_NOT_FOUND, PUS_GET_ERROR());


	//some insert
	for(size_t i = 0; i < 19; i++)
	{
		CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st05_pushBufferEvent(&event));
		//printf("-last counter %lu\n", pus_events_getLastEventCounter());
	}
	pus_clearError();

	size_t actualCounter = 14;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st05_getNextBufferEvent(&event, &actualCounter));
	CU_ASSERT_EQUAL(15, actualCounter);

	actualCounter = 15;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st05_getNextBufferEvent(&event, &actualCounter));
	CU_ASSERT_EQUAL(16, actualCounter);

	actualCounter = 19;
	CU_ASSERT_EQUAL(PUS_ERROR_NEXT_EVENT_NOT_FOUND, pus_st05_getNextBufferEvent(&event, &actualCounter));
	CU_ASSERT_EQUAL(19, actualCounter);

	/*actualCounter = 50;
	CU_ASSERT_EQUAL(PUS_ERROR_NEXT_EVENT_NOT_FOUND, pus_st05_getNextBufferEvent(&event, &actualCounter)); pus_clearError();*/

	pus_clearError();


	//ERROR NULL PTR
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st05_getNextBufferEvent(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st05_pushBufferEvent(NULL));

	//getters/setters
	pus_st05_setEventBufferIn(3);
	CU_ASSERT_EQUAL(3, pus_st05_getEventBufferIn());

	pus_st05_setEventBufferCounter(300);
	CU_ASSERT_EQUAL(300, pus_st05_getEventBufferCounter());
	pus_clearError();

	//others
	pus_st05_setEventBufferCounter(1);
	CU_ASSERT_EQUAL(PUS_ERROR_EMPTY_BUFFER, pus_st05_getNextBufferEvent(&event, &actualCounter));


	CU_ASSERT_EQUAL(pus_st05_eventBufferLength, pus_st05_getEventBufferLength());
	CU_ASSERT_EQUAL(pus_st05_eventReportDestination, pus_st05_getEventDestination());
	CU_ASSERT_EQUAL(pus_st05_eventInfoListLength, pus_st05_getEventInfoListLength());

}

void test_st05()
{
	//pus_events test
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED , pus_events_finalize());
	CU_ASSERT_EQUAL(PUS_NO_ERROR , pus_events_initialize(NULL));
	CU_ASSERT_TRUE(pus_events_isInitialized());
	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_INITIALIZED , pus_events_initialize(NULL));
	CU_ASSERT_EQUAL(PUS_NO_ERROR , pus_events_finalize());
	CU_ASSERT_FALSE(pus_events_isInitialized());
	pus_clearError();


	pusMutex_t mutex;
	pus_mutexInitOk(&mutex);
	pus_mutexDestroyOk(&mutex);
	CU_ASSERT_EQUAL(PUS_ERROR_INITIALIZATION , pus_events_initialize(&mutex));
	pus_clearError();

	CU_ASSERT_TRUE(pus_mutexInitOk(&mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_events_initialize(&mutex));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_events_finalize());
	pus_clearError();


	//NULLPTR eventReport
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_5_X_createEventReport(NULL, 1, 1, NULL, 1, 1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_5_1_createInformativeEventReport(NULL, 1, 1, NULL, 1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_5_2_createLowSeverityEventReport(NULL, 1, 1, NULL, 1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_5_3_createMediumSeverityEventReport(NULL, 1, 1, NULL, 1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_5_4_createHighSeverityEventReport(NULL, 1, 1, NULL, 1)); pus_clearError();

	pusPacket_t tm;
	pusApidInfo_t apid;
	pusSt05Event_t event;

	pus_initApidInfo(&apid, 5, NULL);
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	pus_events_finalize(); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_tm_5_X_createEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1, 1));
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_events_initialize(NULL));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_X_createEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_1_createInformativeEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_2_createLowSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_3_createMediumSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_4_createHighSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1));


	PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_5_1_createInformativeEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_5_2_createLowSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_5_3_createMediumSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_5_4_createHighSeverityEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1));
	pus_events_finalize(); pus_clearError();

	//Event report data
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_events_initialize(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_5_X_setTmEventReportData(NULL, NULL));
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_X_createEventReport(&tm, apid.apid, pus_getNextPacketCount(&apid), &event, 1, 2));
	pus_setTmService(&tm, pusService_NONE); pus_clearError();
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, pus_tm_5_X_setTmEventReportData(&tm, &event));
	pus_setTmService(&tm, pus_ST05_eventReporting); pus_clearError();

	pusSt05Event_t event2;
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_5_X_getTmEventReportData(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_5_X_getTmEventReportData(&tm, &event2));
	CU_ASSERT_EQUAL(event.data.data1, event2.data.data1);
	CU_ASSERT_EQUAL(event.data.data2, event2.data.data2);
	pus_setTmService(&tm, pusService_NONE); pus_clearError();
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, pus_tm_5_X_getTmEventReportData(&tm, &event));
	pus_setTmService(&tm, pus_ST05_eventReporting); pus_clearError();


	pusPacket_t tm2;
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST05(&tm2, pusSubtype_NONE));
	pus_setTmSubtype(&tm, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST05(&tm, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST05(&tm, 1));

	pus_setTmSubtype(&tm, 1);
	pus_setTmDataKind(&tm, pus_TM_DATA_NONE);
	CU_ASSERT_EQUAL(PUS_ERROR_TM_KIND, PUS_EXPECT_ST05(&tm, 0));
	pus_clearError();

	//no se donde meter esto

	pus_getPacketDataLength(&tm);
	CU_ASSERT_FALSE(PUS_IS_ERROR()); pus_clearError();


	pusPacket_t tmAux;

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initTcPacket(&tmAux));

	pus_getTmTimeReferenceStatus(&tmAux);
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_GET_ERROR());pus_clearError();

	pus_getTmMessageTypeCounter(&tmAux);
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_GET_ERROR());pus_clearError();

	pus_getTmDestination(&tmAux);
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_GET_ERROR());pus_clearError();

	pus_getTmPacketTime(NULL, NULL);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());pus_clearError();

	pus_setTmPacketTime(NULL, NULL);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());pus_clearError();

	pus_clearError();
}



int main()
{
    CU_pSuite pSuite = NULL;
    unsigned int numFailures = 0;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    /* add a suite to the registry */
    pSuite = CU_add_suite("suite_pusPacket", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test_st05", test_st05)) ||
    	(NULL == CU_add_test(pSuite, "test_event", test_event)) ||
		(NULL == CU_add_test(pSuite, "test_reports", test_reports)) ||
		(NULL == CU_add_test(pSuite, "test_buffer", test_buffer)) ||
		0)
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

    /* Run all tests using the basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    // Other run options

    /* Run all tests using the automated interface */
    //CU_automated_run_tests();
    //CU_list_tests_to_file();

    /* Run all tests using the console interface */
    //CU_console_run_tests();

    /* get failures (cleanup deletes them) */
    numFailures = CU_get_number_of_failure_records();

    /* Clean up registry and return */
    CU_cleanup_registry();

    /* return, 0 if all passed */
    return numFailures;
}
