#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

// Tests for thread functions disabled
#ifndef PUS_DISABLE_THREADS
#error This test should be compiled with -DPUS_DISABLE_THREADS
#endif

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_threads.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_packet_queues.h"

#include "pus_packet_queues_config.h"

#include "../../include/pus_st01_packets.h"


#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Sample init and clean functions
/*
int init_suite_pusPacket(void) { return 0; }
int clean_suite_pusPacket(void) { return 0; }
*/

void test_apid()
{
	pusApidInfo_t obj;
	pusMutex_t mutex;

	// Valid, no mutex
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initApidInfo(&obj, 33, NULL));
	CU_ASSERT_EQUAL(33, pus_getInfoApid(&obj));
	CU_ASSERT_EQUAL(0, pus_getNextPacketCount(&obj));
	CU_ASSERT_EQUAL(1, pus_getNextPacketCount(&obj));
	CU_ASSERT_EQUAL(2, pus_getNextPacketCount(&obj));

	// Wrap
	obj.packetCount = 16383;
	CU_ASSERT_EQUAL(16383, pus_getNextPacketCount(&obj));
	CU_ASSERT_EQUAL(0, pus_getNextPacketCount(&obj));
	pus_clearError();

	// Errors
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_initApidInfo(NULL, 55, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(pus_APID_IDLE, pus_getInfoApid(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(0, pus_getNextPacketCount(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	// Mutex
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initApidInfo(&obj, 44, &mutex));
	CU_ASSERT_EQUAL(0, pus_getNextPacketCount(&obj));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS_DISABLED, PUS_GET_ERROR());
}

void test_mutex()
{
	pusMutex_t mutex;

	CU_ASSERT_FALSE(pus_mutexInitOk(&mutex));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS_DISABLED, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_FALSE(pus_mutexDestroyOk(&mutex));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS_DISABLED, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_FALSE(pus_mutexLockOk(&mutex));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS_DISABLED, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_FALSE(pus_mutexUnlockOk(&mutex));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS_DISABLED, PUS_GET_ERROR());
	pus_clearError();
}

void test_packetQueue()
{
	pusPacket_t packet;
	pusPacket_t buffer[5];
	pusPacketQueue_t queue;

	queue.buffer = buffer;
	queue.length = 5;
	queue.nPacketInside = 0;
	queue.out = 0;

	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_packetQueues_push(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_packetQueues_pop(&packet, &queue));

	queue.mutex = NULL;

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_packetQueues_push(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_packetQueues_pop(&packet, &queue));
	CU_ASSERT_FALSE(pus_packetQueues_isInitialized());

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_packetQueues_push(NULL, &queue));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_packetQueues_pop(NULL, &queue));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_initialize());
	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_INITIALIZED, pus_packetQueues_initialize());
	CU_ASSERT_TRUE(pus_packetQueues_isInitialized());
	CU_ASSERT_EQUAL(0, pus_packetQueue_tc.nPacketInside);
	CU_ASSERT_EQUAL(0, pus_packetQueue_tc.out);
	CU_ASSERT_EQUAL(0, pus_packetQueue_tm.nPacketInside);
	CU_ASSERT_EQUAL(0, pus_packetQueue_tm.out);


	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_push(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_push(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_push(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_push(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_push(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_ERROR_FULL_QUEUE, pus_packetQueues_push(&packet, &queue));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_push(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_ERROR_FULL_QUEUE, pus_packetQueues_push(&packet, &queue));
	CU_ASSERT_EQUAL(1, queue.out);

	/*pusMutex_t mutex;
	CU_ASSERT_TRUE(pus_mutexInitOk(&mutex));
	printf("\nerror: %d\n", PUS_GET_ERROR());
	queue.mutex = mutex;*/

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, &queue));
	CU_ASSERT_EQUAL(PUS_ERROR_EMPTY_QUEUE, pus_packetQueues_pop(&packet, &queue));

	CU_ASSERT_EQUAL(0, queue.nPacketInside);

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
    if ((NULL == CU_add_test(pSuite, "test_apid", test_apid)) ||
		(NULL == CU_add_test(pSuite, "test_mutex", test_mutex)) ||
		(NULL == CU_add_test(pSuite, "test_packetQueue", test_packetQueue)) ||
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

