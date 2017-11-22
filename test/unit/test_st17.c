#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//#include "../../include/pus_st01_packets.h"
//#include "../../include/pus_st03_packets.h"
//#include "../../include/pus_st05_packets.h"
#include "../../include/pus_st17_packets.h"


//Test Event struct (pusSt05Event_t)

void test_st17()
{

	pusPacket_t tm, tc;
	pusApidInfo_t apid;

	pus_initApidInfo(&apid, 5, NULL); CU_ASSERT_FALSE(PUS_IS_ERROR());

	//TC[17,1]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_17_1_createConnectionTestRequest(&tc, &apid));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST17TC(&tc, pus_TC_17_1_connectionTest));
	CU_ASSERT_EQUAL(5, pus_getApid(&tc));
	CU_ASSERT_EQUAL(0, pus_getSequenceCount(&tc));


	pus_clearError();

	//TM[17,2]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_17_2_createConnectionTestReport(&tm, &apid, 2));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST17TM(&tm, pus_TM_17_2_connectionTest));
	CU_ASSERT_EQUAL(5, pus_getApid(&tm));
	CU_ASSERT_EQUAL(1, pus_getSequenceCount(&tm));
	CU_ASSERT_EQUAL(2, pus_getTmDestination(&tm));
	pus_clearError();

	//response
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_17_1_createConnectionTestRequest(&tc, &apid));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st17_createTestResponse(&tm, &apid, &tc));
	CU_ASSERT_EQUAL(pus_getTmDestination(&tm), tc.apid);

	pus_clearError();
	// ERROR_NULL_PTR
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_17_1_createConnectionTestRequest(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_17_2_createConnectionTestReport(NULL, NULL, 2));

	pus_clearError();

	//
	pusPacket_t tm2, tc2;
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST17TM(&tm2, pusSubtype_NONE));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST17TC(&tc2, pusSubtype_NONE));

	pus_setTmSubtype(&tm, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST17TM(&tm, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST17TM(&tm, 1));

	pus_setTmService(&tm, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, PUS_EXPECT_ST17TM(&tm, 0));


	pus_setTcSubtype(&tc, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST17TC(&tc, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST17TC(&tc, 1));

	pus_setTcService(&tc, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, PUS_EXPECT_ST17TC(&tc, 0));
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
    if ((NULL == CU_add_test(pSuite, "test_st17", test_st17)) ||
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
