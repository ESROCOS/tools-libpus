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

//#include "../../include/pus_st01_packets.h"
//#include "../../include/pus_st03_packets.h"
//#include "../../include/pus_st05_packets.h"
#include "../../include/pus_st20_packets.h"
#include "pus_parameter_management.h"
#include "pus_st20_config.h"

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

void packets_st20()
{
	pusPacket_t tc, tm;

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_20_1_createParameterValueRequest(NULL, 1, 2, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_20_3_createSetParameterValueRequest(NULL, 1, 2, 1, 2));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_20_2_createParameterValueReport(NULL, 1, 2, 1, 2, 1));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_20_1_createParameterValueRequest(&tc, 1, 2, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST20TC(&tc, pus_TC_20_1_reportParameterValues));
	CU_ASSERT_EQUAL(1, pus_getApid(&tc));
	CU_ASSERT_EQUAL(2, pus_getSequenceCount(&tc));
	CU_ASSERT_EQUAL(1, pus_tc_20_X_getParamId(&tc));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_20_3_createSetParameterValueRequest(&tc, 1, 2, 1, 2));
	CU_ASSERT_EQUAL(1, pus_getApid(&tc));
	CU_ASSERT_EQUAL(2, pus_getSequenceCount(&tc));
	CU_ASSERT_EQUAL(1, pus_tc_20_X_getParamId(&tc));
	CU_ASSERT_EQUAL(2, pus_tc_20_3_getParamValue(&tc));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_20_2_createParameterValueReport(&tm, 1, 2, 1, 1, 2));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST20TM(&tm, pus_TM_20_2_reportParameterValues));
	CU_ASSERT_EQUAL(1, pus_getApid(&tc));
	CU_ASSERT_EQUAL(2, pus_getSequenceCount(&tc));
	CU_ASSERT_EQUAL(1, pus_tm_20_2_getParamId(&tm));
	CU_ASSERT_EQUAL(2, pus_tm_20_2_getParamValue(&tm));

	CU_ASSERT_EQUAL(0, pus_tm_20_2_getParamId(NULL));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_GET_ERROR());

	CU_ASSERT_EQUAL(0, pus_tm_20_2_getParamValue(NULL));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_GET_ERROR());

	CU_ASSERT_EQUAL(0, pus_tc_20_X_getParamId(NULL));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_GET_ERROR());

	CU_ASSERT_EQUAL(0, pus_tc_20_3_getParamValue(NULL));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_GET_ERROR());


	pusPacket_t tm2, tc2;
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST20TM(&tm2, pusSubtype_NONE));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST20TC(&tc2, pusSubtype_NONE));

	pus_setTmSubtype(&tm, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST20TM(&tm, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST20TM(&tm, 1));

	pus_setTmService(&tm, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, PUS_EXPECT_ST20TM(&tm, 0));


	pus_setTcSubtype(&tc, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST20TC(&tc, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST20TC(&tc, 1));

	pus_setTcService(&tc, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, PUS_EXPECT_ST20TC(&tc, 0));

	pus_clearError();
}


void test_st20()
{
	pusApidInfo_t apid;
	pus_initApidInfo(&apid, 5, NULL); CU_ASSERT_FALSE(PUS_IS_ERROR());

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_parameters_finalize());
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_parameters_initialize(NULL));
	CU_ASSERT_TRUE(pus_parameters_isInitialized());
	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_INITIALIZED, pus_parameters_initialize(NULL));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_parameters_finalize());

	pusMutex_t mutex;
	pus_mutexInitOk(&mutex);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_parameters_initialize(&mutex));

	int32_t valInt;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setONBOARD_PARAM_INT01(-23));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_getONBOARD_PARAM_INT01(&valInt));
	CU_ASSERT_EQUAL(-23, valInt);

	double valDou;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setONBOARD_PARAM_REAL01(-23.23));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_getONBOARD_PARAM_REAL01(&valDou));
	CU_ASSERT_EQUAL(-23.23, valDou);

	uint32_t valUint;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setONBOARD_PARAM_UINT01(23));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_getONBOARD_PARAM_UINT01(&valUint));
	CU_ASSERT_EQUAL(23, valUint);

	uint8_t valByte;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setONBOARD_PARAM_BYTE01(0x23));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_getONBOARD_PARAM_BYTE01(&valByte));
	CU_ASSERT_EQUAL(0x23, valByte);

	bool valBool;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_setONBOARD_PARAM_BOOL01(true));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_hk_getONBOARD_PARAM_BOOL01(&valBool));
	CU_ASSERT_EQUAL(true, valBool);

	pusParamType_t type;
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_getParamType(56, &type));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_parameters_getParamType(ONBOARD_PARAM_INT01, &type));
	CU_ASSERT_EQUAL(PUS_INT32, type);

	pusStoredParam_t stored;
	int32_t auxInt;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_parameters_getStoredParam(ONBOARD_PARAM_INT01, &stored));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_paramToInt32(&auxInt, stored));
	CU_ASSERT_EQUAL(-23, auxInt);

	//NULL PTR / invaild id
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_parameters_getStoredParam(1, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_getStoredParam(156, &stored));

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_parameters_getUInt32Param(1, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_getUInt32Param(156, &valUint));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_parameters_getUInt32Param(1, &valUint));

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_parameters_getInt32Param(1, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_getInt32Param(156, &valInt));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_parameters_getInt32Param(1, &valInt));

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_parameters_getReal64Param(1, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_getReal64Param(156, &valDou));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_parameters_getReal64Param(0, &valDou));

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_parameters_getBoolParam(1, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_getBoolParam(156, &valBool));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_parameters_getBoolParam(1, &valBool));

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_parameters_getByteParam(1, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_getByteParam(156, &valByte));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_parameters_getByteParam(1, &valByte));

	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_setUInt32Param(25, valUint));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_setInt32Param(25, valInt));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_setReal64Param(56, valDou));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_setBoolParam(123, valBool));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_parameters_setByteParam(123, valByte));

	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_parameters_setUInt32Param(1, valUint));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_parameters_setInt32Param(1, valInt));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_parameters_setReal64Param(0, valDou));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_parameters_setBoolParam(1, valBool));
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_parameters_setByteParam(1, valByte));


	pus_mutexDestroyOk(&mutex);
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_parameters_setUInt32Param(1, valUint));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_parameters_setInt32Param(1, valInt));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_parameters_setReal64Param(0, valDou));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_parameters_setBoolParam(1, valBool));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_parameters_setByteParam(1, valByte));

	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_parameters_getByteParam(1, &valByte));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_parameters_getBoolParam(1, &valBool));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_parameters_getReal64Param(0, &valDou));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_parameters_getUInt32Param(1, &valUint));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_parameters_getInt32Param(1, &valInt));


	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_parameters_finalize());

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_parameters_setUInt32Param(25, valUint));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_parameters_setInt32Param(25, valInt));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_parameters_setReal64Param(56, valDou));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_parameters_setBoolParam(123, valBool));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_parameters_setByteParam(123, valByte));

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_parameters_setUInt32Param(1, valUint));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_parameters_setInt32Param(1, valInt));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_parameters_setReal64Param(0, valDou));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_parameters_setBoolParam(1, valBool));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_parameters_setByteParam(1, valByte));

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
    if ((NULL == CU_add_test(pSuite, "test_st20", test_st20)) ||
    	(NULL == CU_add_test(pSuite, "packets_st20", packets_st20)) ||
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
