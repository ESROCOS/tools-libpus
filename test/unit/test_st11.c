#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_types.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "pus_st11_packets.h"
#include "pus_timebased_scheduling.h"

//testing Activity
#include "pus_st17_packets.h"
#include "pus_st11_config.h"

void test_st11_packets()
{

	pusPacket_t tc;
	pusApidInfo_t apid;

	pus_initApidInfo(&apid, 5, NULL); CU_ASSERT_FALSE(PUS_IS_ERROR());
	pus_clearError();



	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_11_1_createEnableTimeBasedSchedule(&tc, apid.apid, pus_getNextPacketCount(&apid)));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST11TC(&tc, pus_TC_11_1_enableTimeBasedScheduling));
	CU_ASSERT_EQUAL(5, pus_getApid(&tc));
	CU_ASSERT_EQUAL(0, pus_getSequenceCount(&tc));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_11_2_createDisableTimeBasedSchedule(&tc, apid.apid, pus_getNextPacketCount(&apid)));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST11TC(&tc, pus_TC_11_2_disableTimeBasedScheduling));
	CU_ASSERT_EQUAL(5, pus_getApid(&tc));
	CU_ASSERT_EQUAL(1, pus_getSequenceCount(&tc));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_11_3_createResetTimeBasedSchedule(&tc, apid.apid, pus_getNextPacketCount(&apid)));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST11TC(&tc, pus_TC_11_3_resetTimeBasedSchedule));
	CU_ASSERT_EQUAL(5, pus_getApid(&tc));
	CU_ASSERT_EQUAL(2, pus_getSequenceCount(&tc));


	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_11_X_createDefaultPacket(NULL, apid.apid, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_11_1_createEnableTimeBasedSchedule(NULL, apid.apid, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_11_2_createDisableTimeBasedSchedule(NULL, apid.apid,1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_11_3_createResetTimeBasedSchedule(NULL, apid.apid, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_11_4_createInsertActivityIntoSchedule(NULL, 1, 1));

	/*CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_11_4_createInsertActivityIntoSchedule(outTc, apid, sequenceCount));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST11TC(&tc, pus_TC_11_3_resetTimeBasedSchedule));
	CU_ASSERT_EQUAL(5, pus_getApid(&tc));
	CU_ASSERT_EQUAL(2, pus_getSequenceCount(&tc));*/

	pusPacket_t tc2;
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST11TC(&tc2, pusSubtype_NONE));
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_11_1_createEnableTimeBasedSchedule(&tc2, apid.apid, pus_getNextPacketCount(&apid)));


	pus_setTcSubtype(&tc2, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST11TC(&tc2, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST11TC(&tc2, 0));

	pus_setTcService(&tc, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, PUS_EXPECT_ST11TC(&tc, 0));

	pus_clearError();
}

void test_st11()
{
	pusPacket_t tc;
	pusTime_t time;
	pus_now(&time);

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_scheduling_finalize());
	CU_ASSERT_FALSE(pus_scheduling_isFunctionEnable());
	CU_ASSERT_FALSE(pus_scheduling_isInitialized());

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_scheduling_resetFunction());
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_scheduling_disableFunction());
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_scheduling_enableFunction());
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_scheduling_setFunctionFlag(true));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_scheduling_insertActivity(&tc, &time));


	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_initialize(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_INITIALIZED, pus_scheduling_initialize(NULL));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_finalize());

	pusMutex_t mutex;
	pus_mutexInitOk(&mutex);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_initialize(&mutex));

	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_DISABLED, pus_scheduling_disableFunction());
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_enableFunction());
	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_ENABLED, pus_scheduling_enableFunction());
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_disableFunction());

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_resetFunction());
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_enableFunction());

	CU_ASSERT_EQUAL(PUS_ERROR_DEFINITION_NOT_FOUND, pus_scheduling_getScheduledActivity(&tc, &time));
	pus_tc_17_1_createConnectionTestRequest(&tc, 1, 2);
	pus_now(&time);
	//printf("a: %lu, %lu\n", time.tv_sec, time.tv_nsec);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_scheduling_insertActivity(NULL, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_insertActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_insertActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_insertActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_insertActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_insertActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_insertActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_insertActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_insertActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_insertActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_insertActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_ERROR_MAXIMUM_REACHED, pus_scheduling_insertActivity(&tc, &time));

	pus_now(&time);
	//printf("b: %lu, %lu\n", time.tv_sec, time.tv_nsec);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_scheduling_getScheduledActivity(NULL, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_ERROR_DEFINITION_NOT_FOUND, pus_scheduling_getScheduledActivity(&tc, &time));

	pus_clearError();

	pusPacket_t tcAction;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_11_1_createEnableTimeBasedSchedule(&tcAction, 1, 2));

	pus_now( &time );
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_11_4_createInsertActivityIntoSchedule(&tc, 1, 2));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_11_4_setActivity(&tc, &tcAction, &time));
	CU_ASSERT_EQUAL(1, pus_tc_11_4_getNCount(&tc));


	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_tc_11_4_packetToTable(&tc));
	pus_now(&time);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_scheduling_getScheduledActivity(&tc, &time));
	CU_ASSERT_EQUAL(PUS_ERROR_DEFINITION_NOT_FOUND, pus_scheduling_getScheduledActivity(&tc, &time));





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
    if ((NULL == CU_add_test(pSuite, "test_st11_packets", test_st11_packets)) ||
		(NULL == CU_add_test(pSuite, "test_st11", test_st11)) ||
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
