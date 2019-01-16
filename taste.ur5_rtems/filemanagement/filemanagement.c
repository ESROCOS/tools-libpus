/*
* H2020 ESROCOS Project
* Company: GMV Aerospace & Defence S.A.U.
* Licence: GPLv2
*/

/* User code: This file will not be overwritten by TASTE. */

#include "filemanagement.h"

#include "pus_st23_config.h"
#include "pus_file_management.h"

void filemanagement_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */

	pus_files_initialize(NULL, PUS_REPOSITORY_TEST); //TODO define
	system("mkdir -p /tmp/pus"); //TODO CHANGEEEE!!!!
}

void filemanagement_PI_copy(const asn1SccPusSt23RepositoryPath *IN_sourceRepository,
                            const asn1SccPusSt23FileName *IN_sourceFile,
                            const asn1SccPusSt23RepositoryPath *IN_targetRepository,
                            const asn1SccPusSt23FileName *IN_targetFile,
                            asn1SccPusSt01FailureCode *OUT_confirmation)
{
    /* Write your code here! */
	*OUT_confirmation = pus_files_copyFile(IN_sourceRepository, IN_sourceFile, IN_targetRepository, IN_targetFile);
}

void filemanagement_PI_delete(const asn1SccPusSt23RepositoryPath *IN_repository,
                              const asn1SccPusSt23FileName *IN_file,
                              asn1SccPusSt01FailureCode *OUT_confirmation)
{
    /* Write your code here! */
	*OUT_confirmation = pus_files_deleteFile(IN_repository, IN_file);
}

void filemanagement_PI_create(const asn1SccPusSt23RepositoryPath *IN_repository,
                              const asn1SccPusSt23FileName *IN_file,
							  const asn1SccPusUInt64 *IN_maxSize,
                              asn1SccPusSt01FailureCode *OUT_confirmation)
{
    /* Write your code here! */
	*OUT_confirmation = pus_files_createFile(IN_repository, IN_file, *IN_maxSize);
}

void filemanagement_PI_getAttributes(const asn1SccPusSt23RepositoryPath *IN_repository,
									 const asn1SccPusSt23FileName *IN_file,
									 asn1SccPusUInt64 *OUT_maxSize,
                                     asn1SccPusSt01FailureCode *OUT_confirmation)
{
    /* Write your code here! */
	*OUT_confirmation = pus_files_getFileMaxSize(OUT_maxSize, IN_repository, IN_file);
}

