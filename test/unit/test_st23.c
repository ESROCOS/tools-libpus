#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_reduced.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


#include "../../include/pus_st23_packets.h"


void packets_st23()
{
	pusPacket_t tc, tm;

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_X_createDefaultRequest(NULL, 1, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_1_createCreateFileRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_2_createDeleteFileRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_3_createReportFileAtributesRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_23_4_createReportFileAtributesReport(NULL, 1, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_14_createCopyFileRequest(NULL, 1, 1));
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_X_createDefaultRequest(&tc, 1, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_1_createCreateFileRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_2_createDeleteFileRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_3_createReportFileAtributesRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_23_4_createReportFileAtributesReport(&tm, 1, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_14_createCopyFileRequest(&tc, 1, 1));

	pus_clearError();

	pusPacket_t tm2, tc2;
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST23TM(&tm2, pusSubtype_NONE));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST23TC(&tc2, pusSubtype_NONE));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST23TM(&tm, pusSubtype_NONE));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST23TC(&tc, pusSubtype_NONE));

	pus_setTmSubtype(&tm, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST23TM(&tm, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST23TM(&tm, 1));

	pus_setTmService(&tm, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, PUS_EXPECT_ST23TM(&tm, 0));


	pus_setTcSubtype(&tc, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST23TC(&tc, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST23TC(&tc, 1));

	pus_setTcService(&tc, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, PUS_EXPECT_ST23TC(&tc, 0));
	pus_clearError();
}


void test_st23()
{

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
    if ((NULL == CU_add_test(pSuite, "test_st23", test_st23)) ||
    	(NULL == CU_add_test(pSuite, "packets_st23", packets_st23)) ||
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
