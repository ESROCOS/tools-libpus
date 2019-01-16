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
#include "pus_types.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "../../include/pus_st09_packets.h"

void test_st09_packets()
{
	pusPacket_t tm, tc;
	pusApidInfo_t apid;

	pus_initApidInfo(&apid, 5, NULL); CU_ASSERT_FALSE(PUS_IS_ERROR());
	pus_clearError();

	//TC[9,1]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_9_1_createSetTimeReportRate(&tc, apid.apid, pus_getNextPacketCount(&apid), 3));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST09TC(&tc, pus_TC_9_1_setTimeReportRate));
	CU_ASSERT_EQUAL(5, pus_getApid(&tc));
	CU_ASSERT_EQUAL(0, pus_getSequenceCount(&tc));
	pusSt09ExponentialRate_t rate;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_9_1_getExponentialRate(&rate, &tc));
	CU_ASSERT_EQUAL(3, rate);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_9_1_setExponentialRate(&tc, 4));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_9_1_getExponentialRate(&rate, &tc));
	CU_ASSERT_EQUAL(4, rate);



	pus_clearError();

	//TM[9,2]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_9_2_createCucTimeReport(&tm, apid.apid, pus_getNextPacketCount(&apid)));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST09TM(&tm));
	CU_ASSERT_EQUAL(5, pus_getApid(&tm));
	CU_ASSERT_EQUAL(1, pus_getSequenceCount(&tm));
	pus_clearError();
	pusTime_t timeAux;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_9_2_getDataField(&tm, &timeAux, &rate));



	// ERROR_NULL_PTR
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_9_1_createSetTimeReportRate(NULL, 1, 1, 2));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_9_2_createCucTimeReport(NULL, 1,1));

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_9_1_setExponentialRate(NULL, 4));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_9_1_getExponentialRate(NULL, NULL));

	CU_ASSERT_EQUAL(PUS_ERROR_OUT_OF_RANGE, pus_tc_9_1_setExponentialRate(&tc, 25));

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_9_2_setDataField(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_9_2_getDataField(NULL, NULL, NULL));

	pusPacket_t tm2, tc2;
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST09TC(&tc2, pusSubtype_NONE));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST09TM(&tm2));

	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, pus_tc_9_1_setExponentialRate(&tc2, 4));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, pus_tc_9_1_getExponentialRate(&rate, &tc2));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, pus_tm_9_2_setDataField(&tc2));

	pus_setTcSubtype(&tc, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST09TC(&tc, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST09TC(&tc, 1));

	pus_setTcService(&tc, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, PUS_EXPECT_ST09TC(&tc, 0));

	pus_clearError();
}

void test_st09()
{
	//printf("-- Error %d -- ", PUS_EXPECT_ST09TC(&tc, pus_TC_9_1_setTimeReportRate));
	pusSt09ExponentialRate_t rate;

	CU_ASSERT_EQUAL(PUS_ERROR_OUT_OF_RANGE, pus_time_setReportGenerationExponentialRate(26));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_time_getReportGenerationExponentialRate(NULL));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_time_setReportGenerationExponentialRate(3));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_time_getReportGenerationExponentialRate(&rate));
	CU_ASSERT_EQUAL(3, rate);

	uint64_t result;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_time_getReportGenerationRate(&result));
	CU_ASSERT_EQUAL(8, result);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_time_setReportGenerationExponentialRate(0));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_time_getReportGenerationExponentialRate(&rate));
	CU_ASSERT_EQUAL(0, rate);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_time_getReportGenerationRate(&result));
	CU_ASSERT_EQUAL(1, result);


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
    if ((NULL == CU_add_test(pSuite, "test_st09_packets", test_st09_packets)) ||
		(NULL == CU_add_test(pSuite, "test_st09", test_st09)) ||
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
