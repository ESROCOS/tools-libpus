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
#include "../../include/pus_st08_packets.h"
#include "pus_st08_config.h"

pusError_t example_function()
{
	printf("  - Hello world! -  ");
	return PUS_NO_ERROR;
}


void test_st08()
{

	pusMutex_t mutex;

	CU_ASSERT_TRUE(pus_mutexInitOk(&mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	// Initialization
	CU_ASSERT_FALSE(pus_st08_isInitialized());
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st08_initialize(&mutex));
	CU_ASSERT_TRUE(pus_st08_isInitialized());
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_INITIALIZED, pus_st08_initialize(NULL));
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st08_functionTable[EXAMPLE_FUNCTION_01]());
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st08_functionTable[EXAMPLE_FUNCTION_02]());
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st08_functionTable[EXAMPLE_FUNCTION_03]());

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_8_1_createPerformFuctionRequest(NULL, NULL, EXAMPLE_FUNCTION_01));
	pus_clearError();


	pusPacket_t tc;
	pusApidInfo_t apid;
	pus_initApidInfo(&apid, 5, NULL); CU_ASSERT_FALSE(PUS_IS_ERROR());
	pus_clearError();


	CU_ASSERT_EQUAL(PUS_ERROR_UNEXPECTED_FUNCTION_ID, pus_tc_8_1_createPerformFuctionRequest(&tc, &apid, 45));
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_8_1_createPerformFuctionRequest(&tc, &apid, EXAMPLE_FUNCTION_01));
	CU_ASSERT_EQUAL(pus_TC_DATA, pus_getPacketDataKind(&tc));
	CU_ASSERT_EQUAL(pus_TC_DATA_ST_8_1, pus_getTcDataKind(&tc));
	pusSt08FunctiontId_t functionID;
	pus_tc_8_1_getFunctionId(&functionID, &tc);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_GET_ERROR());
	pus_tc_8_1_getFunctionId(NULL, NULL);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());

	CU_ASSERT_EQUAL(EXAMPLE_FUNCTION_01, functionID);

	pus_tc_8_1_setFunctionId(NULL, 2);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());

	pusPacket_t tc2;
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST08(&tc2, pusSubtype_NONE));
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_8_1_createPerformFuctionRequest(&tc2, &apid, EXAMPLE_FUNCTION_01));


	pus_setTcSubtype(&tc2, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST08(&tc2, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST08(&tc2, 0));

	pus_setTcService(&tc, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, PUS_EXPECT_ST08(&tc, 0));





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
    if ((NULL == CU_add_test(pSuite, "test_st08", test_st08)) ||
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
