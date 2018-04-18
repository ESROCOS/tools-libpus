#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "../../include/pus_st01_packets.h"
#include "../../include/pus_st03_packets.h"

#include "pus_packet_queues.h"
#include "pus_packet_queues_config.h"
#include "pus_packet_reduced.h"

// Sample init and clean functions
/*
int init_suite_pusPacket(void) { return 0; }
int clean_suite_pusPacket(void) { return 0; }
*/

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

   // printf("uint64_t %lu\n", sizeof(uint64_t));
   // printf("ul %lu\n", sizeof(unsigned long int));
   // printf("ull %lu\n", sizeof(unsigned long long int));
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

	pus_now(NULL);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
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

    //failures
    pusPacket_t packet2;
    CU_ASSERT_FALSE(pus_getTcAckFlagAcceptance(&packet2));
    CU_ASSERT_FALSE(pus_getTcAckFlagStart(&packet2));
    CU_ASSERT_FALSE(pus_getTcAckFlagProgress(&packet2));
    CU_ASSERT_FALSE(pus_getTcAckFlagCompletion(&packet2));
}

void test_packetVerification(void)
{
	pusPacket_t packet;

//	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TM, PUS_EXPECT_TM(&packet));
//	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, PUS_EXPECT_TC(&packet));
	// TM packet

	pus_initTmPacket(&packet);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_verifyTmHeaderDefaults(&packet));
	packet.packetType = pus_TC;
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TM, pus_verifyTmHeaderDefaults(&packet));
	packet.packetType = pus_TM;
	packet.packetVersion = 25;
	CU_ASSERT_EQUAL(PUS_ERROR_UNEXPECTED_PACKET_VERSION, pus_verifyTmHeaderDefaults(&packet));
	packet.packetVersion = pus_PACKET_VERSION_CURRENT;
	packet.secondaryHeaderFlag = false;
	CU_ASSERT_EQUAL(PUS_ERROR_HEADER_MISMATCH, pus_verifyTmHeaderDefaults(&packet));
	packet.secondaryHeaderFlag = true;

	// TM packet without header

	pus_initTmPacketNoHeader(&packet);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_verifyTmHeaderDefaults(&packet));

	// TC packet

	pus_initTcPacket(&packet);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_verifyTcHeaderDefaults(&packet));
	packet.packetType = pus_TM;
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, pus_verifyTcHeaderDefaults(&packet));
	packet.packetType = pus_TC;
	packet.packetVersion = 25;
	CU_ASSERT_EQUAL(PUS_ERROR_UNEXPECTED_PACKET_VERSION, pus_verifyTcHeaderDefaults(&packet));
	packet.packetVersion = pus_PACKET_VERSION_CURRENT;
	packet.secondaryHeaderFlag = false;
	CU_ASSERT_EQUAL(PUS_ERROR_HEADER_MISMATCH, pus_verifyTcHeaderDefaults(&packet));
	packet.secondaryHeaderFlag = true;

	// TC packet without header

	pus_initTcPacketNoHeader(&packet);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_verifyTcHeaderDefaults(&packet));

	// CCSDS header

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_verifyCcsdsHeaderDefaults(&packet));
	packet.packetVersion = 25;
	CU_ASSERT_EQUAL(PUS_ERROR_UNEXPECTED_PACKET_VERSION, pus_verifyCcsdsHeaderDefaults(&packet));
	packet.packetVersion = pus_PACKET_VERSION_CURRENT;
	packet.sequenceFlags = 0;
	CU_ASSERT_EQUAL(PUS_ERROR_UNEXPECTED_SEQUENCE_FLAGS, pus_verifyCcsdsHeaderDefaults(&packet));
	packet.sequenceFlags = pus_STANDALONE_PACKET;

	// Packet data kind

	pus_initTmPacket(&packet);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_verifyPacketDataKind(&packet));
	pus_setSecondaryHeaderFlag(&packet, false);
	CU_ASSERT_EQUAL(PUS_ERROR_HEADER_MISMATCH, pus_verifyPacketDataKind(&packet));

	pus_initTmPacketNoHeader(&packet);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_verifyPacketDataKind(&packet));
	pus_setSecondaryHeaderFlag(&packet, true);
	CU_ASSERT_EQUAL(PUS_ERROR_HEADER_MISMATCH, pus_verifyPacketDataKind(&packet));

	pus_initTcPacket(&packet);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_verifyPacketDataKind(&packet));
	pus_setSecondaryHeaderFlag(&packet, false);
	CU_ASSERT_EQUAL(PUS_ERROR_HEADER_MISMATCH, pus_verifyPacketDataKind(&packet));

	pus_initTcPacketNoHeader(&packet);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_verifyPacketDataKind(&packet));
	pus_setSecondaryHeaderFlag(&packet, true);
	CU_ASSERT_EQUAL(PUS_ERROR_HEADER_MISMATCH, pus_verifyPacketDataKind(&packet));

	pus_setPacketDefaults(&packet);
	packet.packetType = 2;
	CU_ASSERT_EQUAL(PUS_ERROR_PACKET_TYPE, pus_verifyPacketDataKind(&packet));


}

void test_error()
{
	pusError_t err;
	pusErrorFunction_t fun;
	pusErrorData_t dat;

	pus_clearError();
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	PUS_SET_ERROR(PUS_ERROR_LIMIT);
	CU_ASSERT(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(PUS_ERROR_LIMIT, PUS_GET_ERROR());
	CU_ASSERT_EQUAL(PUS_ERROR_LIMIT, pus_getError(&err, &fun, &dat));
	CU_ASSERT_NSTRING_EQUAL("test_error", fun, 20);
	pus_clearError();
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	PUS_SET_ERROR_INT(PUS_ERROR_NOT_IMPLEMENTED, 5);
	CU_ASSERT(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_IMPLEMENTED, pus_getError(&err, &fun, &dat));
	CU_ASSERT_NSTRING_EQUAL("test_error", fun, 20);
	CU_ASSERT_EQUAL(5, dat.integer);
	pus_clearError();
}

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

	// Valid, mutex
	CU_ASSERT_TRUE(pus_mutexInitOk(&mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initApidInfo(&obj, 44, &mutex));
	CU_ASSERT_EQUAL(44, pus_getInfoApid(&obj));
	CU_ASSERT_EQUAL(0, pus_getNextPacketCount(&obj));
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(1, pus_getNextPacketCount(&obj));
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(2, pus_getNextPacketCount(&obj));
	CU_ASSERT_FALSE(PUS_IS_ERROR());

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

	pus_mutexDestroyOk(&mutex);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initApidInfo(&obj, 66, &mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(0, pus_getNextPacketCount(&obj));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, PUS_GET_ERROR());
	pus_clearError();

}

void test_threads()
{
	pusMutex_t mutex;

	CU_ASSERT_TRUE(pus_mutexInitOk(&mutex));
	CU_ASSERT_TRUE(pus_mutexLockOk(&mutex));
	CU_ASSERT_TRUE(pus_mutexUnlockOk(&mutex));
	CU_ASSERT_TRUE(pus_mutexDestroyOk(&mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	// Errors, null pointer
	CU_ASSERT_FALSE(pus_mutexInitOk(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_FALSE(pus_mutexLockOk(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_FALSE(pus_mutexUnlockOk(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_FALSE(pus_mutexDestroyOk(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	// Errors, mutex previously destroyed
	CU_ASSERT_FALSE(pus_mutexLockOk(&mutex));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_FALSE(pus_mutexUnlockOk(&mutex));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, PUS_GET_ERROR()); pus_clearError();

	// Errors, destroying locked mutex
	CU_ASSERT_TRUE(pus_mutexInitOk(&mutex));
	CU_ASSERT_TRUE(pus_mutexLockOk(&mutex));
	CU_ASSERT_FALSE(pus_mutexDestroyOk(&mutex));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_TRUE(pus_mutexUnlockOk(&mutex));
	CU_ASSERT_TRUE(pus_mutexDestroyOk(&mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());
}

void test_packetErrors()
{
	pusPacket_t packet;

	CU_ASSERT_EQUAL(0, pus_getPacketVersion(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setPacketVersion(NULL, 0);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(0, pus_getPacketType(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setPacketType(NULL, 0);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pus_APID_IDLE, pus_getApid(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setApid(NULL, pus_APID_TIME);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(0, pus_getPacketVersion(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(0, pus_getPacketDataLength(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setPacketVersion(NULL, 0);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(false, pus_getSecondaryHeaderFlag(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setSecondaryHeaderFlag(NULL, true);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pus_STANDALONE_PACKET, pus_getSequenceFlags(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setSequenceFlags(NULL, pus_STANDALONE_PACKET);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(0, pus_getSequenceCount(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setSequenceCount(NULL, 0);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(0, pus_setSequenceCount(&packet, pusPacketDataLength_LIMIT));
	CU_ASSERT_EQUAL(PUS_ERROR_COUNT_WRAP, PUS_GET_ERROR()); pus_clearError();

	pus_setPacketDataLength(NULL, 100);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pus_INVALID_VERSION, pus_getTmPusVersion(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setTmPusVersion(NULL, 0);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pus_INVALID_VERSION, pus_getTcPusVersion(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setTcPusVersion(NULL, 0);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pusService_NONE, pus_getTmService(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setTmService(NULL, 0);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pusSubtype_NONE, pus_getTmSubtype(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setTmSubtype(NULL, 0);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pusService_NONE, pus_getTcService(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setTcService(NULL, 0);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pusSubtype_NONE, pus_getTcSubtype(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setTcSubtype(NULL, 0);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pus_PACKET_DATA_NONE, pus_getPacketDataKind(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setPacketDataKind(NULL, pus_TM_DATA_NO_HEADER);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pus_TM_DATA_NONE, pus_getTmDataKind(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setTmDataKind(NULL, st_1_X_PRESENT);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(pus_TM_DATA_NONE, pus_getTmNoHeaderDataKind(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_setTmNoHeaderDataKind(NULL, pus_TM_DATA_NONE);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	pus_clearError();
}

void test_packetQueue()
{
	pusPacket_t packet;

	pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_packetQueues_push(&packet, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_packetQueues_pop(&packet, 0));
	CU_ASSERT_FALSE(pus_packetQueues_isInitialized());

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_packetQueues_push(NULL, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_packetQueues_pop(NULL, 0));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_initialize());
	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_INITIALIZED, pus_packetQueues_initialize());
	CU_ASSERT_TRUE(pus_packetQueues_isInitialized());
	CU_ASSERT_EQUAL(0, pus_packetQueue_table[0].nPacketInside);
	CU_ASSERT_EQUAL(0, pus_packetQueue_table[0].out);

	for(size_t i=0; i< pus_packetQueue_table[0].length; i++)
	{
		CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_push(&packet, 0));
	}
	CU_ASSERT_EQUAL(PUS_ERROR_FULL_QUEUE, pus_packetQueues_push(&packet, 0));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, 0));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_push(&packet, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_FULL_QUEUE, pus_packetQueues_push(&packet, 0));
	CU_ASSERT_EQUAL(1, pus_packetQueue_table[0].out);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, 0));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, 0));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, 0));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, 0));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetQueues_pop(&packet, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_EMPTY_QUEUE, pus_packetQueues_pop(&packet, 0));
	CU_ASSERT_EQUAL(0, pus_packetQueue_table[0].nPacketInside);

	pus_clearError();
}

void test_packetReduced()
{
	pus_clearError();
	pusPacket_t packet;
	pusPacketReduced_t packetR;

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initTcPacket(&packet));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_8_1);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_9_1);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_12_1_2);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_18_2_6_12);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_18_3);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_18_4_5);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_18_13);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_19_X);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_20_X);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_23_1);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_23_2_3);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	pus_setTcDataKind(&packet, pus_TC_DATA_ST_23_14);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketReducedFromPacket(&packetR, &packet));
	CU_ASSERT_EQUAL(packetR.data.kind, packet.data.kind);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_packetReduced_createPacketFromPacketReduced(&packet, &packetR));

	//pusError_t err = pus_packetReduced_setDataFromPacketReducedToPacket(&packet, &packetR);
	//CU_ASSERT_EQUAL(PUS_NO_ERROR, err);
	//printf("Error err: %u", err);

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
    if ((NULL == CU_add_test(pSuite, "test_packetHeader", test_packetHeader)) ||
        (NULL == CU_add_test(pSuite, "test_setSequenceIncrement", test_setSequenceIncrement)) ||
		(NULL == CU_add_test(pSuite, "test_tmHeader", test_tmHeader)) ||
		(NULL == CU_add_test(pSuite, "test_tcHeader", test_tcHeader)) ||
		(NULL == CU_add_test(pSuite, "test_packetVerification", test_packetVerification)) ||
		(NULL == CU_add_test(pSuite, "test_packetErrors", test_packetErrors)) ||
		(NULL == CU_add_test(pSuite, "test_time", test_time)) ||
		(NULL == CU_add_test(pSuite, "test_error", test_error)) ||
		(NULL == CU_add_test(pSuite, "test_apid", test_apid)) ||
		(NULL == CU_add_test(pSuite, "test_threads", test_threads)) ||
		(NULL == CU_add_test(pSuite, "test_packetQueue", test_packetQueue)) ||
		(NULL == CU_add_test(pSuite, "test_packetReduced", test_packetReduced)) ||
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

