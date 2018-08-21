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
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


#include "pus_st23_packets.h"
#include "pus_file_management.h"
#include "pus_st23_config.h"


void packets_st23()
{
	pusPacket_t tc, tm;
	pusSt23RepositoryPath_t repo, repo2, repo3;
	pusSt23FileName_t file, file2, file3;
	pusSt23MaximumSize_t size, size2;

	//printf("Sizeof packet: %lu, packetReduced: %lu\n", sizeof(tc), sizeof(pusPacketReduced_t));

	size = 5;

	repo.nCount = 10;
	memcpy(repo.arr, "123456789\0", 10);

	file.nCount = 10;
	memcpy(file.arr, "123456789\0", 10);


	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_X_createDefaultRequest(NULL, 1, 1, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_1_createCreateFileRequest(NULL, 1, 1, NULL, NULL, size));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_2_createDeleteFileRequest(NULL, 1, 1, NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_3_createReportFileAtributesRequest(NULL, 1, 1, NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tm_23_4_createReportFileAtributesReport(NULL, 1, 1, 1, NULL, NULL, size));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_14_createCopyFileRequest(NULL, 1, 1, NULL, NULL, NULL, NULL));

	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_tm_23_1_4_setMaximumSize(NULL, 1));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_tm_23_1_4_getMaximumSize(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_14_setSourceFileName(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_14_getSourceFileName(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_14_setTargetFileName(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_14_getTargetFileName(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_14_setSourceRepositoryPath(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_14_getSourceRepositoryPath(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_14_setTargetRepositoryPath(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_tc_23_14_getTargetRepositoryPath(NULL, NULL));

	pus_clearError();

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_X_createDefaultRequest(&tc, 1, 1, 1));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_1_createCreateFileRequest(&tc, 1, 1, &repo, &file, size));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_tm_23_X_getFileName(&file2, &tc));
	CU_ASSERT_EQUAL(0, memcmp(file.arr, file2.arr, 10));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_tm_23_X_getRepositoryPath(&repo2, &tc));
	CU_ASSERT_EQUAL(0, memcmp(repo.arr, repo2.arr, 10));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_tm_23_1_4_getMaximumSize(&size2, &tc));
	CU_ASSERT_EQUAL(size, size2);


	memcpy(repo.arr, "987654321\0", 10);
	memcpy(file.arr, "987654321\0", 10);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_2_createDeleteFileRequest(&tc, 1, 1, &repo, &file));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_tm_23_X_getFileName(&file2, &tc));
	CU_ASSERT_EQUAL(0, memcmp(file.arr, file2.arr, 10));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_tm_23_X_getRepositoryPath(&repo2, &tc));
	CU_ASSERT_EQUAL(0, memcmp(repo.arr, repo2.arr, 10));

	memcpy(repo.arr, "123456789\0", 10);
	memcpy(file.arr, "123456789\0", 10);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_3_createReportFileAtributesRequest(&tc, 1, 1, &repo, &file));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_tm_23_X_getFileName(&file2, &tc));
	CU_ASSERT_EQUAL(0, memcmp(file.arr, file2.arr, 10));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_tm_23_X_getRepositoryPath(&repo2, &tc));
	CU_ASSERT_EQUAL(0, memcmp(repo.arr, repo2.arr, 10));

	memcpy(repo.arr, "987654321\0", 10);
	memcpy(file.arr, "987654321\0", 10);
	size = 9;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tm_23_4_createReportFileAtributesReport(&tm, 1, 1, 1, &repo, &file, size));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_tm_23_X_getFileName(&file2, &tm));
	CU_ASSERT_EQUAL(0, memcmp(file.arr, file2.arr, 10));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_tm_23_X_getRepositoryPath(&repo2, &tm));
	CU_ASSERT_EQUAL(0, memcmp(repo.arr, repo2.arr, 10));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_tm_23_1_4_getMaximumSize(&size2, &tm));
	CU_ASSERT_EQUAL(size, size2);

	memcpy(repo.arr, "111111111\0", 10);
	memcpy(file.arr, "222555888\0", 10);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_14_createCopyFileRequest(&tc, 1, 1, &repo, &file, &repo2, &file2));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_14_getSourceFileName(&file3, &tc));
	CU_ASSERT_EQUAL(0, memcmp(file.arr, file3.arr, 10));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_14_getSourceRepositoryPath(&repo3, &tc));
	CU_ASSERT_EQUAL(0, memcmp(repo.arr, repo3.arr, 10));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_14_getTargetFileName(&file3, &tc));
	CU_ASSERT_EQUAL(0, memcmp(file2.arr, file3.arr, 10));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_tc_23_14_getTargetRepositoryPath(&repo3, &tc));
	CU_ASSERT_EQUAL(0, memcmp(repo2.arr, repo3.arr, 10));


	pus_clearError();

	pusPacket_t tm2, tc2;
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST23TM(&tm2, pusSubtype_NONE));
	CU_ASSERT_NOT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST23TC(&tc2, pusSubtype_NONE));

	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST23TM(&tm, pusSubtype_NONE));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, PUS_EXPECT_ST23TC(&tc, pusSubtype_NONE));

	pus_setTmSubtype(&tm, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST23TM(&tm, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SUBTYPE, PUS_EXPECT_ST23TM(&tm, 1));

	pus_setTmService(&tm, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TM_SERVICE, PUS_EXPECT_ST23TM(&tm, 0));


	pus_setTcSubtype(&tc, 6); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST23TC(&tc, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SUBTYPE, PUS_EXPECT_ST23TC(&tc, 1));

	pus_setTcService(&tc, 2); pus_clearError();
	CU_ASSERT_EQUAL(PUS_ERROR_TC_SERVICE, PUS_EXPECT_ST23TC(&tc, 0));
	pus_clearError();
}


void test_st23()
{
	pusSt23RepositoryPath_t repo;
	pusSt23FileName_t fileT; 
	pusSt23MaximumSize_t maxS;
	pusSt23RepositorySystem_t sys;
	//pus_files_getRepositoryPathFromId(&repo, PUS_REPOSITORY_TEST);
	system("mkdir -p /tmp/pus");

	CU_ASSERT_EQUAL(false, pus_files_isSameRepository(NULL, NULL));
	CU_ASSERT_EQUAL(false, pus_files_isSameFileName(NULL, NULL));
	CU_ASSERT_EQUAL(false, pus_files_isFileInTable(NULL, NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_files_getRepositoryPathFromId(NULL, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_files_createFile(NULL, NULL, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_files_deleteFile(NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_files_copyFile(NULL, NULL, NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_files_getFileMaxSize(NULL, NULL, NULL));
	CU_ASSERT_EQUAL(PUS_ERROR_NULLPTR, pus_files_getSystemFromRepositoryPath(NULL, NULL));
	
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_files_getRepositoryPathFromId(&repo, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_files_createFile(&repo, &fileT, 0));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_files_deleteFile(&repo, &fileT));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_files_getFileMaxSize(&maxS, &repo, &fileT));
	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_files_getSystemFromRepositoryPath(&sys, &repo));
	

	CU_ASSERT_EQUAL(PUS_ERROR_NOT_INITIALIZED, pus_files_finalize());
	CU_ASSERT_FALSE(pus_files_isInitialized());

	CU_ASSERT_EQUAL(PUS_ERROR_INITIALIZATION, pus_files_initialize(NULL, 5));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_files_initialize(NULL, PUS_REPOSITORY_TEST));
	CU_ASSERT_EQUAL(PUS_ERROR_ALREADY_INITIALIZED, pus_files_initialize(NULL, PUS_REPOSITORY_TEST));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_files_finalize());

	pusMutex_t mutex;
	pus_mutexInitOk(&mutex);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_files_initialize(&mutex, PUS_REPOSITORY_TEST));
	CU_ASSERT_TRUE(pus_files_isInitialized());

	pusSt23FileName_t file, file2;
	pusSt23MaximumSize_t size = 300;


	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_files_getRepositoryPathFromId(&repo, PUS_REPOSITORY_TEST));

	memcpy(file.arr, "hello.txt\0", pus_ST23_MAX_SIZE_FILE_PATH - 1);
	file.nCount = strlen((char*)file.arr) + 1;

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_files_createFile(&repo, &file, size));
	CU_ASSERT_EQUAL(PUS_ERROR_FILE_IN_TABLE, pus_files_createFile(&repo, &file, size));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_files_deleteFile(&repo, &file));
	CU_ASSERT_EQUAL(PUS_ERROR_FILE_NOT_FOUND, pus_files_deleteFile(&repo, &file));

	char command[50];
	pusSt23RepositoryDomain_t domain;
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_files_createFile(&repo, &file, size));
	pus_files_getDomainFromRepositoryPath(&domain, &repo);

	sprintf(command, "echo \"hello, how are you?\" > %s%s",  (char*)domain.arr, (char*)file.arr);
	system(command);

	memcpy(file2.arr, "helloCpy.txt\0", pus_ST23_MAX_SIZE_FILE_PATH -1);
	file2.nCount = strlen((char*)file.arr) + 1;

	pusError_t a = pus_files_copyFile(&repo, &file, &repo, &file2);
	CU_ASSERT_EQUAL(PUS_NO_ERROR, a);

	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_files_deleteFile(&repo, &file));
	CU_ASSERT_EQUAL(PUS_NO_ERROR, pus_files_deleteFile(&repo, &file2));


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
    if ((NULL == CU_add_test(pSuite, "test_st23", test_st23)) ||
    	(NULL == CU_add_test(pSuite, "packets_st23", packets_st23)) ||
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
    if( 0 != numFailures )
    {
    	printf("\n-- Check if '/tmp/pus' directory is created --\n");
    }
    return numFailures;
}
