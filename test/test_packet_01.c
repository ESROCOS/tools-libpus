#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#include "pus_packet.h"

#include <stdio.h>
#include <math.h>

// Sample init and clean functions
/*
int init_suite_pusPacket(void) { return 0; }
int clean_suite_pusPacket(void) { return 0; }
*/

void test_setPacketDefaults(void)
{
    pusResult_t result = PUS_FAIL;
    pusPacket_t packet;

    pus_setPacketDefaults(&packet);
    CU_ASSERT_EQUAL(pus_PACKET_VERSION_CURRENT, packet.packetVersion);
    CU_ASSERT_FALSE(packet.secondaryHeaderFlag);
    CU_ASSERT_EQUAL(pus_APID_IDLE, packet.apid);
    CU_ASSERT_EQUAL(pus_STANDALONE_PACKET, packet.sequenceFlags);
    CU_ASSERT_EQUAL(0, packet.sequenceCount);

}

void test_setSequenceIncrement(void)
{
    CU_ASSERT_EQUAL(1, pus_incrementSequenceCount(0));
    CU_ASSERT_EQUAL(0, pus_incrementSequenceCount(pow(2,14) - 1));
}


/*
void test_success2(void)
{
   CU_ASSERT_NOT_EQUAL(2, -1);
}

void test_success3(void)
{
   CU_ASSERT_STRING_EQUAL("string #1", "string #1");
}

void test_success4(void)
{
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");
}

void test_failure1(void)
{
   CU_ASSERT(FALSE);
}

void test_failure2(void)
{
   CU_ASSERT_EQUAL(2, 3);
}

void test_failure3(void)
{
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
}

void test_failure4(void)
{
   CU_ASSERT_STRING_EQUAL("string #1", "string #2");
}
*/

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
    if ((NULL == CU_add_test(pSuite, "test_setPacketDefaults_null", test_setPacketDefaults)) ||
        (NULL == CU_add_test(pSuite, "test_setSequenceIncrement", test_setSequenceIncrement)))
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
