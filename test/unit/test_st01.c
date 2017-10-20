#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_st01.h"
#include "pus_st03.h"

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Sample init and clean functions
/*
int init_suite_pusPacket(void) { return 0; }
int clean_suite_pusPacket(void) { return 0; }
*/

void test_st01()
{
	pusPacket_t tc;
	pusPacket_t tm;

	pusApidInfo_t apid;
	pus_initApidInfo(&apid, 33, NULL);
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	// Test TC
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initTcPacket(&tc));
	pus_setTcSource(&tc, 11);
	pus_setSequenceCount(&tc, 22);
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	// Test failures
	pusSt01FailureInfo_t info1, info2;
	pus_setSt01FailureInfo(&info1, 101, 102, 103);
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	// TM[1,1]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_1_1_createAcceptanceReportSuccess(&tm, &apid, &tc));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST01(&tm, pus_TM_1_1_successfulAcceptance));
	CU_ASSERT_EQUAL(11, pus_getTmDestination(&tm));
	CU_ASSERT_EQUAL(22, pus_tm_1_X_getSequenceCount(&tm));
	CU_ASSERT_EQUAL(33, pus_getApid(&tm));
	CU_ASSERT_EQUAL(0, pus_getSequenceCount(&tm));
	CU_ASSERT_EQUAL(pus_TC, pus_tm_1_X_getPacketType(&tm));
	CU_ASSERT_TRUE(pus_tm_1_X_getSecondaryHeaderFlag(&tm));
	CU_ASSERT_EQUAL(pus_getPacketVersion(&tc), pus_tm_1_X_getPacketVersionNumber(&tm));
	CU_ASSERT_EQUAL(pus_getSequenceFlags(&tc), pus_tm_1_X_getSequenceFlags(&tm));
	CU_ASSERT_EQUAL(0, pus_tm_1_X_getStep(&tm));
	CU_ASSERT_EQUAL(pus_ST01_NO_ERROR, pus_tm_1_X_getFailureInfo(&tm, NULL))

	// TM[1,2]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_1_2_createAcceptanceReportFailure(&tm, &apid, &tc, pus_ST01_ERROR_SERVICE_UNAVAILABLE, &info1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST01(&tm, pus_TM_1_2_failedAcceptance));
	pus_initSt01FailureInfo(&info2);
	CU_ASSERT_EQUAL(pus_ST01_ERROR_SERVICE_UNAVAILABLE, pus_tm_1_X_getFailureInfo(&tm, &info2));
	CU_ASSERT_EQUAL(101, pus_getSt01FailureSubcode(&info2));
	CU_ASSERT_EQUAL(102, pus_getSt01FailureData(&info2));
	CU_ASSERT_EQUAL(103, pus_getSt01FailureAddress(&info2));

	// TM[1,3]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_1_3_createStartReportSuccess(&tm, &apid, &tc));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST01(&tm, pus_TM_1_3_successfulStart));

	// TM[1,4]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_1_4_createStartReportFailure(&tm, &apid, &tc, pus_ST01_ERROR_WRONG_FORMAT, NULL));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST01(&tm, pus_TM_1_4_failedStart));
	CU_ASSERT_EQUAL(pus_ST01_ERROR_WRONG_FORMAT, pus_tm_1_X_getFailureInfo(&tm, NULL));

	// TM[1,5]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_1_5_createProgressReportSuccess(&tm, &apid, &tc, 71));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST01(&tm, pus_TM_1_5_successfulProgress));
	CU_ASSERT_EQUAL(71, pus_tm_1_X_getStep(&tm));

	// TM[1,6]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_1_6_createProgressReportFailure(&tm, &apid, &tc, 72, pus_ST01_ERROR_SUBTYPE_UNAVAILABLE, NULL));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST01(&tm, pus_TM_1_6_failedProgress));
	CU_ASSERT_EQUAL(pus_ST01_ERROR_SUBTYPE_UNAVAILABLE, pus_tm_1_X_getFailureInfo(&tm, NULL));
	CU_ASSERT_EQUAL(72, pus_tm_1_X_getStep(&tm));

	// TM[1,7]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_1_7_createCompletionReportSuccess(&tm, &apid, &tc));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST01(&tm, pus_TM_1_7_successfulCompletion));

	// TM[1,8]
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_1_8_createCompletionReportFailure(&tm, &apid, &tc, pus_ST01_ERROR_WRONG_FORMAT, NULL));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST01(&tm, pus_TM_1_8_failedCompletion));
	CU_ASSERT_EQUAL(pus_ST01_ERROR_WRONG_FORMAT, pus_tm_1_X_getFailureInfo(&tm, NULL));

	// TC without header
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initTcPacketNoHeader(&tc));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_1_1_createAcceptanceReportSuccess(&tm, &apid, &tc));
	CU_ASSERT_FALSE(pus_tm_1_X_getSecondaryHeaderFlag(&tm));

	// TM counter
	CU_ASSERT_EQUAL(8, pus_getSequenceCount(&tm));

	// Errors
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_X_createReport(NULL, &apid, &tc, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_X_createReport(&tm, NULL, &tc, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_X_createReport(&tm, &apid, NULL, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_1_createAcceptanceReportSuccess(NULL, &apid, &tc));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_1_createAcceptanceReportSuccess(&tm, NULL, &tc));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_1_createAcceptanceReportSuccess(&tm, &apid, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_2_createAcceptanceReportFailure(NULL, &apid, &tc, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_2_createAcceptanceReportFailure(&tm, NULL, &tc, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_2_createAcceptanceReportFailure(&tm, &apid, NULL, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_3_createStartReportSuccess(NULL, &apid, &tc));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_3_createStartReportSuccess(&tm, NULL, &tc));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_3_createStartReportSuccess(&tm, &apid, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_4_createStartReportFailure(NULL, &apid, &tc, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_4_createStartReportFailure(&tm, NULL, &tc, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_4_createStartReportFailure(&tm, &apid, NULL, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_5_createProgressReportSuccess(NULL, &apid, &tc, 11));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_5_createProgressReportSuccess(&tm, NULL, &tc, 12));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_5_createProgressReportSuccess(&tm, &apid, NULL, 13));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_6_createProgressReportFailure(NULL, &apid, &tc, 11, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_6_createProgressReportFailure(&tm, NULL, &tc, 12, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_6_createProgressReportFailure(&tm, &apid, NULL, 13, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_7_createCompletionReportSuccess(NULL, &apid, &tc));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_7_createCompletionReportSuccess(&tm, NULL, &tc));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_7_createCompletionReportSuccess(&tm, &apid, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_8_createCompletionReportFailure(NULL, &apid, &tc, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_8_createCompletionReportFailure(&tm, NULL, &tc, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_1_8_createCompletionReportFailure(&tm, &apid, NULL, 1, &info1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_1_1_createAcceptanceReportSuccess(&tm, &apid, &tc));
	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_1_2_createAcceptanceReportFailure(&tm, &apid, &tc, 0, NULL));
	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_1_3_createStartReportSuccess(&tm, &apid, &tc));
	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_1_4_createStartReportFailure(&tm, &apid, &tc, 0, &info1));
	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_1_5_createProgressReportSuccess(&tm, &apid, &tc, 20));
	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_1_6_createProgressReportFailure(&tm, &apid, &tc, 21, 1, &info1));
	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_1_7_createCompletionReportSuccess(&tm, &apid, &tc));
	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_1_8_createCompletionReportFailure(&tm, &apid, &tc, 1, &info1));
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, pus_tm_1_1_createAcceptanceReportSuccess(&tm, &apid, &tm));
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, pus_tm_1_1_createAcceptanceReportSuccess(&tm, &apid, &tm));
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, pus_tm_1_2_createAcceptanceReportFailure(&tm, &apid, &tm, 0, NULL));
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, pus_tm_1_3_createStartReportSuccess(&tm, &apid, &tm));
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, pus_tm_1_4_createStartReportFailure(&tm, &apid, &tm, 0, &info1));
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, pus_tm_1_5_createProgressReportSuccess(&tm, &apid, &tm, 20));
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, pus_tm_1_6_createProgressReportFailure(&tm, &apid, &tm, 21, 1, &info1));
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, pus_tm_1_7_createCompletionReportSuccess(&tm, &apid, &tm));
	pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TC, pus_tm_1_8_createCompletionReportFailure(&tm, &apid, &tm, 1, &info1));
	pus_clearError();

	pus_tm_1_X_setPacketVersionNumber(NULL, 0);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(pus_PACKET_VERSION_CURRENT, pus_tm_1_X_getPacketVersionNumber(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	pus_tm_1_X_setPacketType(NULL, pus_TC);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	pus_tm_1_X_getPacketType(NULL);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	pus_tm_1_X_setSecondaryHeaderFlag(NULL, false);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(false, pus_tm_1_X_getSecondaryHeaderFlag(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	pus_tm_1_X_setApid(&tm, 35);
	CU_ASSERT_EQUAL(35, pus_tm_1_X_getApid(&tm));
	CU_ASSERT_EQUAL(pus_APID_IDLE, pus_tm_1_X_getApid(NULL));

	pus_tm_1_X_setSequenceFlags(NULL, pus_STANDALONE_PACKET);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(pus_STANDALONE_PACKET, pus_tm_1_X_getSequenceFlags(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	pus_tm_1_X_setSequenceCount(NULL, 5);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(0, pus_tm_1_X_getSequenceCount(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	pus_tm_1_X_setStep(NULL, 5);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(0, pus_tm_1_X_getStep(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	pus_tm_1_X_initFailureInfo(NULL);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	pus_tm_1_X_getFailureInfo(&tc, NULL);
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TM, PUS_GET_ERROR());
	pus_clearError();

	pus_initSt01FailureInfo(NULL);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	pus_setSt01FailureInfo(NULL, 1, 2, 3);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(0, pus_getSt01FailureSubcode(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(0, pus_getSt01FailureData(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(0, pus_getSt01FailureAddress(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR());
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_1_1_createAcceptanceReportSuccess(&tm, &apid, &tc));
	tm.data.u.tmData.header.service = pusService_NONE;
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, PUS_EXPECT_ST01(&tm, pus_TM_1_1_successfulAcceptance));
	tm.data.u.tmData.header.service = pus_ST01_requestVerification;
	tm.data.u.tmData.header.subtype = pus_TM_1_2_failedAcceptance;
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST01(&tm, pus_TM_1_1_successfulAcceptance));
	tm.data.u.tmData.header.subtype = pus_TM_1_1_successfulAcceptance;
	tm.data.u.tmData.header.subtype = pusSubtype_NONE;
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST01(&tm, pusSubtype_NONE));
	tm.data.u.tmData.header.subtype = pus_TM_1_1_successfulAcceptance;
	tm.data.u.tmData.data.kind = pus_TM_DATA_NONE;
	CU_ASSERT_EQUAL(PUS_ERROR_TM_KIND, PUS_EXPECT_ST01(&tm, pus_TM_1_1_successfulAcceptance));
	tm.data.u.tmData.data.kind = pus_TM_DATA_ST_1_X;

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
    if ((NULL == CU_add_test(pSuite, "test_st01", test_st01)) ||
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

