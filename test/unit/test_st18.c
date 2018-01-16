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


#include "../../include/pus_st18_packets.h"



void test_st18_packets()
{

	pusPacket_t tc;

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_X_createDefaultRequest(NULL, 1, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_1_createLoadObcpDirectRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_2_createUnloadObcpRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_3_createActivateObcpRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_4_createStopObcpRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_5_createSuspendObcpRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_6_createResumeObcpRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_12_createAbortObcpRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_13_createLoadObcpReferenceRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_21_createStartObcpEngineRequest(NULL, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_22_createStopObcpEngineRequest(NULL, 1, 1));
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_X_createDefaultRequest(&tc, 1, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_1_createLoadObcpDirectRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_2_createUnloadObcpRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_3_createActivateObcpRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_4_createStopObcpRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_5_createSuspendObcpRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_6_createResumeObcpRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_12_createAbortObcpRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_13_createLoadObcpReferenceRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_21_createStartObcpEngineRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_22_createStopObcpEngineRequest(&tc, 1, 1));


	pusPacket_t  tc2;
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST18TC(&tc2, pusSubtype_NONE));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST18TC(&tc, pusSubtype_NONE));
	pus_setTcSubtype(&tc, 7); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST18TC(&tc, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST18TC(&tc, 1));

	pus_setTcService(&tc, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, PUS_EXPECT_ST18TC(&tc, 0));

	pus_clearError();

	pusSt18ObcpId_t id, id2;
	memcpy(id.arr, "OBCPID001\0", 10);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_X_setObcpId(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_18_X_getObcpId(NULL, NULL));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_1_createLoadObcpDirectRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_X_setObcpId(&tc, &id));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_X_getObcpId(&id2, &tc));
	CU_ASSERT_EQUAL(0, memcmp(id.arr, id2.arr, 10));

	memcpy(id.arr, "OBCPID002\0", 10);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_2_createUnloadObcpRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_X_setObcpId(&tc, &id));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_X_getObcpId(&id2, &tc));
	CU_ASSERT_EQUAL(0, memcmp(id.arr, id2.arr, 10));

	memcpy(id.arr, "OBCPID003\0", 10);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_3_createActivateObcpRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_X_setObcpId(&tc, &id));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_X_getObcpId(&id2, &tc));
	CU_ASSERT_EQUAL(0, memcmp(id.arr, id2.arr, 10));

	memcpy(id.arr, "OBCPID004\0", 10);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_4_createStopObcpRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_X_setObcpId(&tc, &id));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_X_getObcpId(&id2, &tc));
	CU_ASSERT_EQUAL(0, memcmp(id.arr, id2.arr, 10));

	memcpy(id.arr, "OBCPID013\0", 10);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_13_createLoadObcpReferenceRequest(&tc, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_X_setObcpId(&tc, &id));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_18_X_getObcpId(&id2, &tc));
	CU_ASSERT_EQUAL(0, memcmp(id.arr, id2.arr, 10));

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
    if ((NULL == CU_add_test(pSuite, "test_st18_packets", test_st18_packets)) ||
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
