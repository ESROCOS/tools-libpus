/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
#include "pus_file_management.h"
// Linux files includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mutex to lock access to the event tables
pusMutex_t* pus_files_mutex = NULL;

// Initialized flag
bool pus_files_initializedFlag = false;

// Repository
pusSt23RepositoryPath_t serviceRepository;

extern pusSt23FilesTableSize_t pus_files_filesTableSize;
extern pusSt23File_t pus_files_filesTable[];

extern size_t pus_files_repositoriesTableSize;
extern pusSt23Repository_t pus_files_repositoriesTable[];

pusError_t pus_files_initialize(pusMutex_t* mutex, pusSt23RepositoryId_t repositoryId)
{
	return PUS_NO_ERROR;
}


pusError_t pus_files_finalize()
{
	return PUS_NO_ERROR;
}

bool pus_files_isInitialized()
{
	return pus_files_initializedFlag;
}

bool pus_files_isSameRepository(const pusSt23RepositoryPath_t* repository1, const pusSt23RepositoryPath_t* repository2)
{
	return false;
}


bool pus_files_isSameFileName( const pusSt23FileName_t* fileName1, const  pusSt23FileName_t* fileName2)
{
	return false;
}

bool pus_files_isFileInTable(const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName, size_t* index)
{
	return false;
}

pusError_t pus_files_getRepositoryPathFromId(pusSt23RepositoryPath_t* path, pusSt23RepositoryId_t id)
{
	return PUS_SET_ERROR(PUS_NO_ERROR);
}


pusError_t pus_files_createFile(const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName, pusSt23MaximumSize_t size)
{
	return PUS_SET_ERROR(PUS_ERROR_CREATING_FILE);
}


pusError_t pus_files_deleteFile(const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName)
{
	return PUS_SET_ERROR(PUS_ERROR_DELETING_FILE);

}

pusError_t pus_files_copyFile(const pusSt23RepositoryPath_t* sourceRepository, const pusSt23FileName_t* sourceFileName,
								const pusSt23RepositoryPath_t* targetRepository, const pusSt23FileName_t* targetFileName)
{
	return PUS_SET_ERROR(PUS_NO_ERROR);
}


pusError_t pus_files_getFileMaxSize(pusSt23MaximumSize_t* maxSize, const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName)
{
	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_files_getDomainFromRepositoryPath(pusSt23RepositoryDomain_t* domain, const pusSt23RepositoryPath_t* repositoryPath)
{
	return PUS_SET_ERROR(PUS_ERROR_FILE_REPOSITORY);
}

pusError_t pus_files_getSystemFromRepositoryPath(pusSt23RepositorySystem_t* system, const pusSt23RepositoryPath_t* repositoryPath)
{
	return PUS_SET_ERROR(PUS_ERROR_FILE_REPOSITORY);
}

