#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#include "pus_packet.h"
#include "pus_time.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Sample init and clean functions
/*
int init_suite_pusPacket(void) { return 0; }
int clean_suite_pusPacket(void) { return 0; }
*/

void test_packetHeader(void)
{
    pusPacket_t packet;

    pus_setPacketDefaults(&packet);

    CU_ASSERT_EQUAL(pus_PACKET_VERSION_CURRENT, pus_getPacketVersion(&packet));
    CU_ASSERT_FALSE(pus_getSecondaryHeaderFlag(&packet));
    CU_ASSERT_EQUAL(pus_APID_IDLE, pus_getApid(&packet));
    CU_ASSERT_EQUAL(pus_STANDALONE_PACKET, pus_getSequenceFlags(&packet));
    CU_ASSERT_EQUAL(0, pus_getSequenceCount(&packet));
    CU_ASSERT_EQUAL(pus_PACKET_DATA_NONE, pus_getPacketDataKind(&packet));
}

void test_setSequenceIncrement(void)
{
    CU_ASSERT_EQUAL(1, pus_incrementSequenceCount(0));
    CU_ASSERT_EQUAL(0, pus_incrementSequenceCount(pow(2,14) - 1));
}

void test_time(void)
{
	pusTime_t t1, t2;
	struct timespec ts;

	pus_now(&t1);
	pus_time2posix(&ts, &t1);
	pus_posix2time(&t2, &ts);

	CU_ASSERT_EQUAL(t1.tv_sec, t2.tv_sec);
	CU_ASSERT_EQUAL(t1.tv_nsec, t2.tv_nsec);
}

void test_tmHeader(void)
{
	pusPacket_t packet;

	pus_initTmPacket(&packet);

	CU_ASSERT_EQUAL(pus_TM, pus_getPacketType(&packet));
    CU_ASSERT_TRUE(pus_getSecondaryHeaderFlag(&packet));

    CU_ASSERT_EQUAL(pus_VERSION_CURRENT, pus_getTmPusVersion(&packet));
    CU_ASSERT_EQUAL(pus_TIME_REFERENCE_STATUS_NONE, pus_getTmTimeReferenceStatus(&packet));
    CU_ASSERT_EQUAL(pusService_NONE, pus_getTmService(&packet));
    CU_ASSERT_EQUAL(pusSubtype_NONE, pus_getTmSubtype(&packet));
    CU_ASSERT_EQUAL(pus_MESSAGE_TYPE_COUNTER_NONE, pus_getTmMessageTypeCounter(&packet));
    CU_ASSERT_EQUAL(pus_APID_IDLE, pus_getTmDestination(&packet));

    pusTime_t time;
    pus_getTmPacketTime(&time, &packet);
    CU_ASSERT_NOT_EQUAL(0, time.tv_sec);

    CU_ASSERT_EQUAL(pus_TM_DATA, pus_getPacketDataKind(&packet));
}

void test_tcHeader(void)
{
	pusPacket_t packet;

	pus_initTcPacket(&packet);

	CU_ASSERT_EQUAL(pus_TC, pus_getPacketType(&packet));
    CU_ASSERT_TRUE(pus_getSecondaryHeaderFlag(&packet));

    CU_ASSERT_EQUAL(pus_VERSION_CURRENT, pus_getTcPusVersion(&packet));
    CU_ASSERT_FALSE(pus_getTcAckFlagAcceptance(&packet));
    CU_ASSERT_FALSE(pus_getTcAckFlagStart(&packet));
    CU_ASSERT_FALSE(pus_getTcAckFlagProgress(&packet));
    CU_ASSERT_FALSE(pus_getTcAckFlagCompletion(&packet));
    CU_ASSERT_EQUAL(pusService_NONE, pus_getTcService(&packet));
    CU_ASSERT_EQUAL(pusSubtype_NONE, pus_getTcSubtype(&packet));
    CU_ASSERT_EQUAL(pus_APID_IDLE, pus_getTcSource(&packet));

    CU_ASSERT_EQUAL(pus_TC_DATA, pus_getPacketDataKind(&packet));
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
    if ((NULL == CU_add_test(pSuite, "test_packetHeader", test_packetHeader)) ||
        (NULL == CU_add_test(pSuite, "test_setSequenceIncrement", test_setSequenceIncrement)) ||
		(NULL == CU_add_test(pSuite, "test_time", test_time)) ||
		(NULL == CU_add_test(pSuite, "test_tmHeader", test_tmHeader)) ||
		(NULL == CU_add_test(pSuite, "test_tcHeader", test_tcHeader)) ||
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
