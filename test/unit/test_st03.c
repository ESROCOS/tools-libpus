#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_st01.h"
#include "pus_st03.h"
#include "pus_st03_config.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Sample init and clean functions
/*
int init_suite_pusPacket(void) { return 0; }
int clean_suite_pusPacket(void) { return 0; }
*/

void test_st03()
{
	pusMutex_t mutex;
	uint32_t ui1 = 0;
	int32_t i1 = 0;
	int32_t i2 = 0;
	double d1 = 0;
	uint8_t c1 = 0;
	bool b1 = false;

	CU_ASSERT_TRUE(pus_mutexInit(&mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	// Initialization
	CU_ASSERT_FALSE(pus_st03_isInitialized());
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_initialize(&mutex));
	CU_ASSERT_TRUE(pus_st03_isInitialized());
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_INITIALIZED, pus_st03_initialize(NULL));
	pus_clearError();

	// Finalization
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_finalize());
	CU_ASSERT_FALSE(pus_st03_isInitialized());
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	CU_ASSERT_TRUE(pus_mutexDestroy(&mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_st03_finalize());
	pus_clearError();

	// Getters and setters
	CU_ASSERT_TRUE(pus_mutexInit(&mutex));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_initialize(&mutex));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_setUInt32Param(HK_PARAM_UINT01, 25));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_setInt32Param(HK_PARAM_INT01, -15));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_setInt32Param(HK_PARAM_INT02, 40));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_setReal64Param(HK_PARAM_REAL01, 0.1234));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_setByteParam(HK_PARAM_BYTE01, 100));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_setBoolParam(HK_PARAM_BOOL01, true));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_getReal64Param(HK_PARAM_REAL01, &d1));
	CU_ASSERT_EQUAL(0.1234, d1);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_getInt32Param(HK_PARAM_INT02, &i2));
	CU_ASSERT_EQUAL(40, i2);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_getByteParam(HK_PARAM_BYTE01, &c1));
	CU_ASSERT_EQUAL(100, c1);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_getUInt32Param(HK_PARAM_UINT01, &ui1));
	CU_ASSERT_EQUAL(25, ui1);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_getInt32Param(HK_PARAM_INT01, &i1));
	CU_ASSERT_EQUAL(-15, i1);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_getBoolParam(HK_PARAM_BOOL01, &b1));
	CU_ASSERT_EQUAL(true, b1);

	// Getter and setter errors
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st03_getInt32Param(HK_PARAM_INT01, NULL)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st03_getUInt32Param(HK_PARAM_UINT01, NULL)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st03_getReal64Param(HK_PARAM_REAL01, NULL)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st03_getByteParam(HK_PARAM_BYTE01, NULL)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st03_getBoolParam(HK_PARAM_BOOL01, NULL)); pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_st03_getInt32Param(10, &i1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_st03_getUInt32Param(10, &ui1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_st03_getReal64Param(10, &d1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_st03_getByteParam(10, &c1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_st03_getBoolParam(10, &b1)); pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_st03_getInt32Param(HK_PARAM_REAL01, &i1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_st03_getUInt32Param(HK_PARAM_REAL01, &ui1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_st03_getReal64Param(HK_PARAM_INT01, &d1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_st03_getByteParam(HK_PARAM_INT01, &c1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_st03_getBoolParam(HK_PARAM_INT01, &b1)); pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_st03_setInt32Param(10, -5)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_st03_setUInt32Param(10, 5)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_st03_setReal64Param(10, -5.0)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_st03_setByteParam(10, 5)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_ID, pus_st03_setBoolParam(10, true)); pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_st03_setInt32Param(HK_PARAM_REAL01, -5)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_st03_setUInt32Param(HK_PARAM_REAL01, 5)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_st03_setReal64Param(HK_PARAM_INT01, -5.0)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_st03_setByteParam(HK_PARAM_INT01, 5)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_INVALID_TYPE, pus_st03_setBoolParam(HK_PARAM_INT01, true)); pus_clearError();

	// Uninitialized mutex
	CU_ASSERT_TRUE(pus_mutexDestroy(&mutex));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_finalize());
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(PUS_ERROR_INITIALIZATION, pus_st03_initialize(&mutex));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_TRUE(pus_mutexInit(&mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_initialize(&mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	CU_ASSERT_TRUE(pus_mutexDestroy(&mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_st03_setInt32Param(HK_PARAM_INT01, -15)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_st03_setUInt32Param(HK_PARAM_UINT01, 25)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_st03_setReal64Param(HK_PARAM_REAL01, 0.1234)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_st03_setByteParam(HK_PARAM_BYTE01, 100)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_st03_setBoolParam(HK_PARAM_BOOL01, true)); pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_st03_getInt32Param(HK_PARAM_INT01, &i1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_st03_getUInt32Param(HK_PARAM_UINT01, &ui1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_st03_getReal64Param(HK_PARAM_REAL01, &d1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_st03_getByteParam(HK_PARAM_BYTE01, &c1)); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_st03_getBoolParam(HK_PARAM_BOOL01, &b1)); pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_finalize());
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	// PUS limits: alter stored values
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_initialize(NULL));
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	extern pusInternalParam_t pus_st03_params[];

	pus_st03_params[HK_PARAM_UINT01] = (uint64_t)UINT32_MAX + 1;
	CU_ASSERT_EQUAL(PUS_ERROR_LIMIT, pus_st03_getUInt32Param(HK_PARAM_UINT01, &ui1)); pus_clearError();

	int64_t ov = (int64_t)INT32_MAX + 1;
	memcpy(&pus_st03_params[HK_PARAM_INT01], &ov, sizeof(int64_t));
	CU_ASSERT_EQUAL(PUS_ERROR_LIMIT, pus_st03_getInt32Param(HK_PARAM_INT01, &i1)); pus_clearError();

	ov = (int64_t)INT32_MIN - 1;
	memcpy(&pus_st03_params[HK_PARAM_INT01], &ov, sizeof(int64_t));
	CU_ASSERT_EQUAL(PUS_ERROR_LIMIT, pus_st03_getInt32Param(HK_PARAM_INT01, &i1)); pus_clearError();

	pus_st03_params[HK_PARAM_BYTE01] = (uint64_t)UINT8_MAX + 1;
	CU_ASSERT_EQUAL(PUS_ERROR_LIMIT, pus_st03_getByteParam(HK_PARAM_BYTE01, &c1)); pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_finalize());
	CU_ASSERT_FALSE(PUS_IS_ERROR());

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
    if ((NULL == CU_add_test(pSuite, "test_st03", test_st03)) ||
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

