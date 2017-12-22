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


void packets_st20()
{
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
