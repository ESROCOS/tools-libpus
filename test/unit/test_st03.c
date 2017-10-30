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

void test_init()
{
	pusMutex_t mutex;

	CU_ASSERT_TRUE(pus_mutexInitOk(&mutex));
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

	CU_ASSERT_TRUE(pus_mutexDestroyOk(&mutex));
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_st03_finalize());
	pus_clearError();

	// Uninitialized mutex
	CU_ASSERT_EQUAL(PUS_ERROR_INITIALIZATION, pus_st03_initialize(&mutex));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, PUS_GET_ERROR());
	pus_clearError();
}

void test_params()
{
	pusMutex_t mutex;
	uint32_t ui1 = 0;
	int32_t i1 = 0;
	int32_t i2 = 0;
	double d1 = 0;
	uint8_t c1 = 0;
	bool b1 = false;

	// Initialization
	CU_ASSERT_TRUE(pus_mutexInitOk(&mutex));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_initialize(&mutex));

	// Getters and setters
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
	CU_ASSERT_TRUE(pus_mutexDestroyOk(&mutex));
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

void test_st03()
{
	pusMutex_t mutexHk, mutexApid;
	pusPacket_t tm, tm2;
	pusApidInfo_t apid;
	uint32_t ui1 = 0;
	int32_t i1 = 0;
	double d1 = 0;
	uint8_t c1 = 0;
	bool b1 = false;
	pusTime_t tv, now;
	size_t len;
	pusInternalParam_t val;
	pusSt03ParamId_t paramIds[3] = {HK_PARAM_REAL01, HK_PARAM_INT01, HK_PARAM_INT02};

	CU_ASSERT_TRUE(pus_mutexInitOk(&mutexHk));
	CU_ASSERT_TRUE(pus_mutexInitOk(&mutexApid));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initApidInfo(&apid, 33, &mutexApid));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_initialize(&mutexHk));

	// Initialize parameters
	pus_st03_setReal64Param(HK_PARAM_REAL01, 5.4321);
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	pus_st03_setInt32Param(HK_PARAM_INT01, -1001);
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	pus_st03_setUInt32Param(HK_PARAM_UINT01, 1001);
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	pus_st03_setByteParam(HK_PARAM_BYTE01, 0xc1);
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	pus_st03_setBoolParam(HK_PARAM_BOOL01, true);
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	// Create and check default report
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_3_25_createHousekeepingReportDefault(&tm, &apid, 55));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST03(&tm, pusSubtype_NONE));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST03(&tm, pus_TM_3_25_housekeepingReport));

	CU_ASSERT_EQUAL(pus_TM, pus_getPacketType(&tm));
	CU_ASSERT_TRUE(pus_getSecondaryHeaderFlag(&tm));
	CU_ASSERT_EQUAL(33, pus_getApid(&tm));

	CU_ASSERT_EQUAL(pus_ST03_housekeeping, pus_getTmService(&tm));
	CU_ASSERT_EQUAL(pus_TM_3_25_housekeepingReport, pus_getTmSubtype(&tm));
	CU_ASSERT_EQUAL(pus_TM_DATA_ST_3_25, pus_getTmDataKind(&tm));

	CU_ASSERT_EQUAL(55, pus_getTmDestination(&tm));
	CU_ASSERT_EQUAL(0, pus_getSequenceCount(&tm));

	pus_now(&now);
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	pus_getTmPacketTime(&tv, &tm);
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	CU_ASSERT_TRUE(now.tv_sec >= tv.tv_sec && tv.tv_sec - now.tv_sec <= 1);

	// Report id
	CU_ASSERT_EQUAL(pus_ST03_DEFAULT_HK_REPORT, pus_tm_3_25_getReportId(&tm));

	pus_tm_3_25_setReportId(&tm, 70);
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(70, pus_tm_3_25_getReportId(&tm));

	pus_tm_3_25_setReportId(&tm, pus_ST03_DEFAULT_HK_REPORT);
	CU_ASSERT_FALSE(PUS_IS_ERROR());
	CU_ASSERT_EQUAL(pus_ST03_DEFAULT_HK_REPORT, pus_tm_3_25_getReportId(&tm))

	// Report contents
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_3_25_getNumParameters(&tm, &len));
	CU_ASSERT_EQUAL(len, pus_st03_defaultHkReportInfo.numParams);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_3_25_getParameterValue(&tm, 0, &val));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_paramToReal64(&d1, val));
	CU_ASSERT_EQUAL(5.4321, d1);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_3_25_getParameterValue(&tm, 1, &val));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_paramToInt32(&i1, val));
	CU_ASSERT_EQUAL(-1001, i1);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_3_25_getParameterValue(&tm, 2, &val));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_paramToUInt32(&ui1, val));
	CU_ASSERT_EQUAL(1001, ui1);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_3_25_getParameterValue(&tm, 3, &val));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_paramToByte(&c1, val));
	CU_ASSERT_EQUAL(0xc1, c1);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_3_25_getParameterValue(&tm, 4, &val));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_paramToBool(&b1, val));
	CU_ASSERT_EQUAL(true, b1);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_finalize());
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	CU_ASSERT_TRUE(pus_mutexDestroyOk(&mutexHk));
	CU_ASSERT_TRUE(pus_mutexDestroyOk(&mutexApid));

	// Errors

	// Pointers
	CU_ASSERT_EQUAL(0, pus_tm_3_25_getReportId(NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	pus_tm_3_25_setReportId(NULL, 15);
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_3_25_setParameterValues(NULL, paramIds, 3));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_3_25_setParameterValues(&tm, NULL, 3));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_3_25_getParameterValue(NULL, HK_PARAM_REAL01, &val));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_3_25_getParameterValue(&tm, HK_PARAM_REAL01, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_3_25_getNumParameters(NULL, &len));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_3_25_getNumParameters(&tm, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st03_paramToUInt32(NULL, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st03_paramToInt32(NULL, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st03_paramToReal64(NULL, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st03_paramToByte(NULL, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_st03_paramToBool(NULL, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_3_25_createHousekeepingReport(NULL, &apid, pus_ST03_DEFAULT_HK_REPORT, pus_APID_IDLE));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_3_25_createHousekeepingReport(&tm, NULL, pus_ST03_DEFAULT_HK_REPORT, pus_APID_IDLE));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, PUS_GET_ERROR()); pus_clearError();

	// Not initialized
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_tm_3_25_createHousekeepingReport(&tm, &apid, pus_ST03_DEFAULT_HK_REPORT, pus_APID_IDLE));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, PUS_GET_ERROR()); pus_clearError();

	// Reinitialize
	CU_ASSERT_TRUE(pus_mutexInitOk(&mutexHk));
	CU_ASSERT_TRUE(pus_mutexInitOk(&mutexApid));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initApidInfo(&apid, 33, &mutexApid));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_initialize(&mutexHk));


	// Wrong packet
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_3_25_createHousekeepingReport(&tm2, &apid, pus_ST03_DEFAULT_HK_REPORT, pus_APID_IDLE));

	pus_setTmService(&tm2, pusService_NONE);
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, PUS_EXPECT_ST03(&tm2, pus_TM_3_25_housekeepingReport));
	pus_setTmService(&tm2, pus_ST03_housekeeping);

	pus_setTmSubtype(&tm2, pusSubtype_NONE);
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST03(&tm2, pus_TM_3_25_housekeepingReport));
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST03(&tm2, pusSubtype_NONE));
	pus_setTmSubtype(&tm2, pus_TM_3_25_housekeepingReport);

	pus_setTmDataKind(&tm2, pus_TM_DATA_ST_1_X);
	CU_ASSERT_EQUAL(PUS_ERROR_TM_KIND, PUS_EXPECT_ST03(&tm2, pus_TM_3_25_housekeepingReport));
	pus_setTmDataKind(&tm2, pus_TM_DATA_ST_3_25);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_initTcPacketNoHeader(&tm2));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_TM, PUS_EXPECT_ST03(&tm2, pus_TM_3_25_housekeepingReport)); pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_3_25_createHousekeepingReport(&tm2, &apid, pus_ST03_DEFAULT_HK_REPORT, pus_APID_IDLE));
	pus_setTmService(&tm2, pusService_NONE);

	CU_ASSERT_EQUAL(0, pus_tm_3_25_getReportId(&tm2));
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, pus_tm_3_25_setParameterValues(&tm2, paramIds, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, pus_tm_3_25_getParameterValue(&tm2, 0, &val));
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, pus_tm_3_25_getNumParameters(&tm2, &len));
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, PUS_GET_ERROR()); pus_clearError();

	// pus_tm_3_25_createHousekeepingReport
	PUS_SET_ERROR(PUS_ERROR_NOT_IMPLEMENTED);
	CU_ASSERT_EQUAL(PUS_ERROR_BEFORE, pus_tm_3_25_createHousekeepingReport(&tm, &apid, pus_ST03_DEFAULT_HK_REPORT, pus_APID_IDLE));
	pus_clearError();

	CU_ASSERT_EQUAL(PUS_ERROR_REPORT_ID_UNKNOWN, pus_tm_3_25_createHousekeepingReport(&tm, &apid, 1234, pus_APID_IDLE));
	CU_ASSERT_EQUAL(PUS_ERROR_REPORT_ID_UNKNOWN, PUS_GET_ERROR()); pus_clearError();

	extern pusSt03ReportInfo_t pus_st03_defaultHkReportInfo;
	size_t oldNumParams = pus_st03_defaultHkReportInfo.numParams;

	pus_st03_defaultHkReportInfo.numParams = 1000;
	CU_ASSERT_EQUAL(PUS_ERROR_REPORT_LENGTH, pus_tm_3_25_createHousekeepingReport(&tm, &apid, pus_ST03_DEFAULT_HK_REPORT, pus_APID_IDLE));
	CU_ASSERT_EQUAL(PUS_ERROR_REPORT_LENGTH, PUS_GET_ERROR()); pus_clearError();
	pus_st03_defaultHkReportInfo.numParams = oldNumParams;

	// pus_tm_3_25_setParameterValues
	CU_ASSERT_TRUE(pus_mutexDestroyOk(&mutexHk));

	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, pus_tm_3_25_setParameterValues(&tm, paramIds, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_THREADS, PUS_GET_ERROR()); pus_clearError();

	CU_ASSERT_TRUE(pus_mutexInitOk(&mutexHk));

	CU_ASSERT_EQUAL(PUS_ERROR_REPORT_LENGTH, pus_tm_3_25_setParameterValues(&tm, paramIds, 1000));
	CU_ASSERT_EQUAL(PUS_ERROR_REPORT_LENGTH, PUS_GET_ERROR()); pus_clearError();

	// pus_tm_3_25_getParameterValue
	CU_ASSERT_EQUAL(PUS_ERROR_REPORT_LENGTH, pus_tm_3_25_getParameterValue(&tm, 1000, &val));
	CU_ASSERT_EQUAL(PUS_ERROR_REPORT_LENGTH, PUS_GET_ERROR()); pus_clearError();


	// Finalize
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_st03_finalize());
	CU_ASSERT_FALSE(PUS_IS_ERROR());

	CU_ASSERT_TRUE(pus_mutexDestroyOk(&mutexHk));
	CU_ASSERT_TRUE(pus_mutexDestroyOk(&mutexApid));
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
    if ((NULL == CU_add_test(pSuite, "test_init", test_init)) ||
		(NULL == CU_add_test(pSuite, "test_params", test_params)) ||
		(NULL == CU_add_test(pSuite, "test_st03", test_st03)) ||
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

