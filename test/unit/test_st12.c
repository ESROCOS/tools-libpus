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

pusError_t example_function()
{
	// DUmmy function
	return PUS_NO_ERROR;
}

pusError_t example_function2()
{
	// DUmmy function
	return PUS_NO_ERROR;
}

pusError_t example_function3()
{
	// DUmmy function
	return PUS_NO_ERROR;
}

void test_st12_packets()
{
	pusPacket_t tc;
	pusApidInfo_t apid;
	pusSt12PmonId_t pmonId;

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initApidInfo(&apid, 23, NULL));

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, PUS_EXPECT_ST12TC(&tc, pusSubtype_NONE));
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_1_createEnableParameterMonitoringDefinitions(&tc, apid.apid, pus_getNextPacketCount(&apid), 1));
	CU_ASSERT_EQUAL(pus_ST12_onBoardMonitoring, pus_getTcService(&tc));
	CU_ASSERT_EQUAL(pus_TC_12_1_enableParameterMonitoringDefinitions, pus_getTcSubtype(&tc));
	CU_ASSERT_EQUAL(pus_TC_DATA_ST_12_1_2, pus_getTcDataKind(&tc));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_1_2_getPmonId(&pmonId, &tc));
	CU_ASSERT_EQUAL(1,pmonId);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_2_createDisableParameterMonitoringDefinitions(&tc, apid.apid, pus_getNextPacketCount(&apid), 2));
	CU_ASSERT_EQUAL(pus_ST12_onBoardMonitoring, pus_getTcService(&tc));
	CU_ASSERT_EQUAL(pus_TC_12_2_disableParameterMonitoringDefinitions, pus_getTcSubtype(&tc));
	CU_ASSERT_EQUAL(pus_TC_DATA_ST_12_1_2, pus_getTcDataKind(&tc));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_1_2_getPmonId(&pmonId, &tc));
	CU_ASSERT_EQUAL(2,pmonId);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_15_createEnableParameterMonitoring(&tc, apid.apid, pus_getNextPacketCount(&apid)));
	CU_ASSERT_EQUAL(pus_ST12_onBoardMonitoring, pus_getTcService(&tc));
	CU_ASSERT_EQUAL(pus_TC_12_15_enableParameterMonitoring, pus_getTcSubtype(&tc));
	CU_ASSERT_EQUAL(pus_TC_DATA_NONE, pus_getTcDataKind(&tc));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_12_16_createDisableParameterMonitoring(&tc, apid.apid, pus_getNextPacketCount(&apid)));
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
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, pus_tc_12_1_2_getPmonId(&pmonId, &tc));
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, pus_tc_12_1_2_setPmonId(&tc, 1));


	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_1_2_getPmonId(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_1_2_setPmonId(NULL, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_X_createDefaultPacket(NULL, 1, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_1_createEnableParameterMonitoringDefinitions(NULL, apid.apid, pus_getNextPacketCount(&apid), 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_2_createDisableParameterMonitoringDefinitions(NULL, apid.apid, pus_getNextPacketCount(&apid), 2));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_15_createEnableParameterMonitoring(NULL, apid.apid, pus_getNextPacketCount(&apid)));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_12_16_createDisableParameterMonitoring(NULL, apid.apid, pus_getNextPacketCount(&apid)));
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

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_enableFunction());
	for(pusSt03ParamId_t i = 0; i < PUS_ST12_PARAM_LIMIT; i++)
	{
		CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_enableDefinition(i));
	}

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

void test_checks()
{
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_checkParameter(HK_PARAM_INT01));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_checkLimitInt32(0, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_checkLimitUint32(0, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_checkLimitBool(0, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_checkLimitReal64(0, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_pmon_checkLimitByte(0, 1));

	pus_pmon_finalize(); pus_clearError();
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_initialize(NULL));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_enableFunction());
	for(pusSt03ParamId_t i = 0; i < PUS_ST12_PARAM_LIMIT; i++)
	{
		CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_enableDefinition(i));
	}

	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_pmon_checkParameter(456));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_pmon_checkLimitInt32(23, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_pmon_checkLimitUint32(34, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_pmon_checkLimitBool(23, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_pmon_checkLimitReal64(23, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_pmon_checkLimitByte(23, 1));

	pus_hk_finalize();
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_initialize(NULL));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_INT01(5));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_checkParameter(HK_PARAM_INT01));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_INT01(15));
	CU_ASSERT_EQUAL(PUS_ERROR_ABOVE_HIGH_LIMIT, pus_pmon_checkParameter(HK_PARAM_INT01));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_INT01(2));
	CU_ASSERT_EQUAL(PUS_ERROR_BELOW_LOW_LIMIT, pus_pmon_checkParameter(HK_PARAM_INT01));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_INT02(5));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_checkParameter(HK_PARAM_INT02));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_INT02(15));
	CU_ASSERT_EQUAL(PUS_ERROR_ABOVE_HIGH_LIMIT, pus_pmon_checkParameter(HK_PARAM_INT02));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_INT02(-2));
	CU_ASSERT_EQUAL(PUS_ERROR_BELOW_LOW_LIMIT, pus_pmon_checkParameter(HK_PARAM_INT02));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_REAL01(8.236));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_checkParameter(HK_PARAM_REAL01));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_REAL01(63.24));
	CU_ASSERT_EQUAL(PUS_ERROR_ABOVE_HIGH_LIMIT, pus_pmon_checkParameter(HK_PARAM_REAL01));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_REAL01(-36.21));
	CU_ASSERT_EQUAL(PUS_ERROR_BELOW_LOW_LIMIT, pus_pmon_checkParameter(HK_PARAM_REAL01));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_UINT01(5));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_checkParameter(HK_PARAM_UINT01));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_UINT01(15));
	CU_ASSERT_EQUAL(PUS_ERROR_ABOVE_HIGH_LIMIT, pus_pmon_checkParameter(HK_PARAM_UINT01));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_UINT01(2));
	CU_ASSERT_EQUAL(PUS_ERROR_BELOW_LOW_LIMIT, pus_pmon_checkParameter(HK_PARAM_UINT01));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_BOOL01(false));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_checkParameter(HK_PARAM_BOOL01));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_BOOL01(true));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, pus_pmon_checkParameter(HK_PARAM_BOOL01));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_BYTE01(0x09));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_pmon_checkParameter(HK_PARAM_BYTE01));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_BYTE01(0x0B));
	CU_ASSERT_EQUAL(PUS_ERROR_ABOVE_HIGH_LIMIT, pus_pmon_checkParameter(HK_PARAM_BYTE01));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setHK_PARAM_BYTE01(0x01));
	CU_ASSERT_EQUAL(PUS_ERROR_BELOW_LOW_LIMIT, pus_pmon_checkParameter(HK_PARAM_BYTE01));

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
    if ((NULL == CU_add_test(pSuite, "test_st12_packets", test_st12_packets)) ||
    		(NULL == CU_add_test(pSuite, "test_st12", test_st12)) ||
			(NULL == CU_add_test(pSuite, "test_checks", test_checks)) ||
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
