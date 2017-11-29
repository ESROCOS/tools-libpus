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
#include "../../include/pus_st19_packets.h"

#include "pus_events.h"
#include "pus_event_action.h"

//test action TC 8
#include "../../include/pus_st08_packets.h"
#include "pus_st08_config.h"

pusError_t example_function()
{
	printf("  - Hello world! -  ");
	return PUS_NO_ERROR;
}

void packets_st19()
{
	pusPacket_t tc, tcAction;
	pusApidInfo_t apid;

	pus_initApidInfo(&apid, 5, NULL); CU_ASSERT_FALSE(PUS_IS_ERROR());

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_8_1_createPerformFuctionRequest(&tcAction, &apid, EXAMPLE_FUNCTION_01));

	//TC[19,1]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_19_1_createAddEventActionDefinitionsRequest(&tc, &apid, 1, &tcAction));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST19(&tc, pus_TC_19_1_addEventActionDefinitions));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST19(&tc, pusSubtype_NONE));


		//PusExpect fails
		CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_EXPECT_ST19(NULL, 0));

		pus_setTcDataKind(&tc, 1);
		CU_ASSERT_EQUAL(PUS_ERROR_TC_KIND, PUS_EXPECT_ST19(&tc, 0));
		CU_ASSERT_EQUAL(PUS_ERROR_TC_KIND, PUS_EXPECT_ST19(&tc, 1));

		pus_setTcSubtype(&tc, 6); pus_clearError();
		CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST19(&tc, 0));
		CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST19(&tc, 1));

		pus_setTcService(&tc, 2); pus_clearError();
		CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, PUS_EXPECT_ST19(&tc, 0));
	//TODO check tcAction

	pus_clearError();

	//TM[19,2]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_19_2_createDeleteEventActionDefinitionsRequest(&tc, &apid, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST19(&tc, pus_TC_19_2_deleteEventActionDefinitions));
	pus_clearError();

	//TM[19,4]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_19_4_createEnableEventActionDefinitions(&tc, &apid, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST19(&tc, pus_TC_19_4_enableEventActionDefinitions));
	pus_clearError();

	//TM[19,5]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_19_5_createDisableEventActionDefinitions(&tc, &apid, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST19(&tc, pus_TC_19_5_disableEventActionDefinitions));
	pus_clearError();

	//NULL PTR
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_19_X_createDefaultEventActionRequest(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_19_1_createAddEventActionDefinitionsRequest(NULL, &apid, 1, &tcAction));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_19_2_createDeleteEventActionDefinitionsRequest(NULL, &apid, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_19_4_createEnableEventActionDefinitions(NULL, &apid, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_19_5_createDisableEventActionDefinitions(NULL, &apid, 1));

	pus_tc_19_1_setAction(NULL, NULL); CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_tc_19_x_setEventId(NULL, 2); CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());




	pusPacketReduced_t tcRed;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_createPusPacketReduced(&tcRed, &tcAction));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReducedSetTcData(&tcRed, &tcAction));

	pus_setTcDataKind(&tcAction, pus_TC_DATA_NONE);
	CU_ASSERT_EQUAL(PUS_ERROR_TC_KIND, pus_packetReducedSetTcData(&tcRed, &tcAction));

	pus_setTcDataKind(&tcAction, pus_TC_DATA_ST_19_1);
	CU_ASSERT_EQUAL(PUS_ERROR_TC_KIND, pus_packetReducedSetTcData(&tcRed, &tcAction));

	pus_setTcDataKind(&tcAction, pus_TC_DATA_ST_19_X);
	CU_ASSERT_EQUAL(PUS_ERROR_TC_KIND, pus_packetReducedSetTcData(&tcRed, &tcAction));

	pus_setTcDataKind(&tcAction, 23);
	CU_ASSERT_EQUAL(PUS_ERROR_TC_KIND, pus_packetReducedSetTcData(&tcRed, &tcAction));


}


void test_st19()
{



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
    if ((NULL == CU_add_test(pSuite, "test_st17", test_st19)) ||
    	(NULL == CU_add_test(pSuite, "packets_st17", packets_st19)) ||
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
