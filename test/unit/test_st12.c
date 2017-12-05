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

//#include "../../include/pus_st01_packets.h"
//#include "../../include/pus_st03_packets.h"
//#include "../../include/pus_st05_packets.h"
#include "../../include/pus_st12_packets.h"

#include "pus_st12_config.h"



void test_st12_packets()
{
	pusPacket_t tc;
	pusApidInfo_t apid;
	pusSt12PmonId_t pmonId;

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initApidInfo(&apid, 23, NULL));

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, PUS_EXPECT_ST12TC(&tc, pusSubtype_NONE));
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_1_createEnableParameterMonitoringDefinitions(&tc, &apid, 1));
	CU_ASSERT_EQUAL(pus_ST12_onBoardMonitoring, pus_getTcService(&tc));
	CU_ASSERT_EQUAL(pus_TC_12_1_enableParameterMonitoringDefinitions, pus_getTcSubtype(&tc));
	CU_ASSERT_EQUAL(pus_TC_DATA_ST_12_1_2, pus_getTcDataKind(&tc));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_1_2_getPmonId(&tc, &pmonId));
	CU_ASSERT_EQUAL(1,pmonId);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_2_createDisableParameterMonitoringDefinitions(&tc, &apid, 2));
	CU_ASSERT_EQUAL(pus_ST12_onBoardMonitoring, pus_getTcService(&tc));
	CU_ASSERT_EQUAL(pus_TC_12_2_disableParameterMonitoringDefinitions, pus_getTcSubtype(&tc));
	CU_ASSERT_EQUAL(pus_TC_DATA_ST_12_1_2, pus_getTcDataKind(&tc));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_1_2_getPmonId(&tc, &pmonId));
	CU_ASSERT_EQUAL(2,pmonId);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_15_createEnableParameterMonitoring(&tc, &apid));
	CU_ASSERT_EQUAL(pus_ST12_onBoardMonitoring, pus_getTcService(&tc));
	CU_ASSERT_EQUAL(pus_TC_12_15_enableParameterMonitoring, pus_getTcSubtype(&tc));
	CU_ASSERT_EQUAL(pus_TC_DATA_NONE, pus_getTcDataKind(&tc));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_16_createDisableParameterMonitoring(&tc, &apid));
	CU_ASSERT_EQUAL(pus_ST12_onBoardMonitoring, pus_getTcService(&tc));
	CU_ASSERT_EQUAL(pus_TC_12_16_disableParameterMonitoring, pus_getTcSubtype(&tc));
	CU_ASSERT_EQUAL(pus_TC_DATA_NONE, pus_getTcDataKind(&tc));

	pus_setTcDataKind(&tc, 5);
	CU_ASSERT_EQUAL(PUS_ERROR_TC_KIND, PUS_EXPECT_ST12TC(&tc, pusSubtype_NONE));
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST12TC(&tc, 5));
	pus_setTcSubtype(&tc, 5);
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST12TC(&tc, pusSubtype_NONE));

	pus_clearError();

	pus_clearError();
	pus_setTcService(&tc, 1);
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, pus_tc_12_1_2_getPmonId(&tc, &pmonId));
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, pus_tc_12_1_2_setPmonId(&tc, 1));


	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_1_2_getPmonId(NULL, &pmonId));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_1_2_setPmonId(NULL, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_X_createDefaultPacket(NULL, NULL, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_1_createEnableParameterMonitoringDefinitions(NULL, &apid, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_2_createDisableParameterMonitoringDefinitions(NULL, &apid, 2));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_15_createEnableParameterMonitoring(NULL, &apid));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_16_createDisableParameterMonitoring(NULL, &apid));
}

void test_st12()
{
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_finalize());
	CU_ASSERT_FALSE(pus_pmon_isFunctionActivated());
	CU_ASSERT_FALSE(pus_pmon_isInitialized());

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_disableDefinition(1));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_enableDefinition(1));

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_disableFunction());
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_enableFunction());
	pus_pmon_getDefinitionStatus(1);
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, PUS_GET_ERROR());
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_setDefinitionStatus(1, false));


	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_initialize(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_INITIALIZED, pus_pmon_initialize(NULL));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_finalize());

	pusMutex_t mutex;
	CU_ASSERT_TRUE(pus_mutexInitOk(&mutex));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_initialize(&mutex));

	CU_ASSERT_TRUE(pus_pmon_isFunctionActivated());
	CU_ASSERT_TRUE(pus_pmon_isInitialized());

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_disableFunction());
	CU_ASSERT_FALSE(pus_pmon_isFunctionActivated());

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_enableFunction());
	CU_ASSERT_TRUE(pus_pmon_isFunctionActivated());


	CU_ASSERT_TRUE(pus_pmon_getDefinitionStatus(1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR,pus_pmon_setDefinitionStatus(1, false));
	CU_ASSERT_FALSE(pus_pmon_getDefinitionStatus(1));

	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_DISABLED, pus_pmon_disableDefinition(1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_enableDefinition(1));
	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_ENABLED, pus_pmon_enableDefinition(1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_disableDefinition(1));

	pus_pmon_getDefinitionStatus(13);
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, PUS_GET_ERROR());
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_pmon_setDefinitionStatus(13, false));

	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_pmon_disableDefinition(13));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_pmon_enableDefinition(13));




	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_finalize());
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
    if ((NULL == CU_add_test(pSuite, "test_st12_packets", test_st12_packets)) ||
    		(NULL == CU_add_test(pSuite, "test_st12", test_st12)) ||
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
