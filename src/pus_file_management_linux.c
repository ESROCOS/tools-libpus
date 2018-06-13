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
	if (pus_files_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	pus_files_mutex = mutex;

	if (NULL != pus_files_mutex && !pus_mutexLockOk(pus_files_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	if (PUS_NO_ERROR != pus_files_configure())
	{
		if (NULL != pus_files_mutex)
		{
			(void) pus_mutexUnlockOk(pus_files_mutex);
		}
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	if (NULL != pus_files_mutex && !pus_mutexUnlockOk(pus_files_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}


	// Init values
	for(size_t i = 0; i < pus_files_filesTableSize; i++)
	{
		//pus_files_filesTable[i].opened = false;
		pus_files_filesTable[i].deleted = true;
	}

	// Flag service initialized = true
	pus_files_initializedFlag = true;

	//Reposirory
	if(PUS_NO_ERROR != pus_files_getRepositoryPathFromId(&serviceRepository, repositoryId))
	{
		pus_files_initializedFlag = false;
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	return PUS_NO_ERROR;
}


pusError_t pus_files_finalize()
{
	if (!pus_files_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		pus_files_mutex = NULL;
		pus_files_initializedFlag = false;
		return PUS_NO_ERROR;
	}
}

bool pus_files_isInitialized()
{
	return pus_files_initializedFlag;
}

bool pus_files_isSameRepository(const pusSt23RepositoryPath_t* repository1, const pusSt23RepositoryPath_t* repository2)
{
	if( NULL == repository1 || NULL == repository2 )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}
	else if( repository1->nCount == repository2->nCount )
	{
		if( 0 == memcmp(repository1->arr, repository2->arr, repository1->nCount) )
		{
			return true;
		}
	}
	return false;
}


bool pus_files_isSameFileName( const pusSt23FileName_t* fileName1, const  pusSt23FileName_t* fileName2)
{
	if( NULL == fileName1 || NULL == fileName2 )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}
	else if( fileName1->nCount == fileName2->nCount )
	{
		if( 0 == memcmp(fileName1->arr, fileName2->arr, fileName1->nCount) )
		{
			return true;
		}
	}
	return false;
}

bool pus_files_isFileInTable(const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName, size_t* index)
{
	if( NULL == repository || NULL == fileName )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}
	/*if( false == pus_files_isSameRepository(repository, &serviceRepository))
	{
		PUS_SET_ERROR(PUS_ERROR_FILE_REPOSITORY);
		return false;
	}*/
	for(size_t i = 0; i < pus_files_filesTableSize; i++)
	{
		if( pus_files_filesTable[i].deleted == false )
		{
			if(pus_files_isSameRepository(repository, &pus_files_filesTable[i].repository))
			{
				if(pus_files_isSameFileName(fileName, &pus_files_filesTable[i].fileName))
				{
					if( NULL != index)
					{
						*index = i;
					}
					PUS_SET_ERROR( PUS_NO_ERROR );
					return true;
				}
			}
		}
	}

	PUS_SET_ERROR( PUS_ERROR_FILE_NOT_FOUND );
	return false;
}

pusError_t pus_files_getRepositoryPathFromId(pusSt23RepositoryPath_t* path, pusSt23RepositoryId_t id)
{
	if( NULL == path )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if( !pus_files_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	if( id > pus_files_repositoriesTableSize)
	{
		return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
	}

	*path = pus_files_repositoriesTable[id].repository;

	return PUS_SET_ERROR(PUS_NO_ERROR);
}


pusError_t pus_files_createFile(const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName, pusSt23MaximumSize_t size)
{
	if( NULL == repository || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if (!pus_files_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	if( pus_files_isFileInTable(repository, fileName, NULL))
	{
		return PUS_SET_ERROR( PUS_ERROR_FILE_IN_TABLE );
	}
	else
	{
		static size_t j = 0;
		for( size_t i = 0; i < pus_files_filesTableSize; i++)
		{
			if( true == pus_files_filesTable[j].deleted )
			{
				FILE* fp;
				char path[100];
				pusSt23RepositoryDomain_t domain;
				pus_files_getDomainFromRepositoryPath(&domain, repository);
				sprintf(path, "%s%s", (char*)domain.arr, (char*)fileName->arr);
				//printf("Path: %s\n", path);
				fp = fopen(path, "w");
				if(fp == NULL)
				{
					return PUS_SET_ERROR(PUS_ERROR_CREATING_FILE);
				}

				/* TODO
				fseek(fp, size-1, 0);
				fputs("5", fp);
				if( (uint32_t)ftell(fp) != size)
				{
					return PUS_SET_ERROR(PUS_ERROR_CREATING_FILE);
				}*/
				fclose(fp);

				pus_files_filesTable[j].fileName = *fileName;
				pus_files_filesTable[j].repository = *repository;
				pus_files_filesTable[j].maxSize = size;
				pus_files_filesTable[j].deleted = false;

				j = (j + 1)%pus_files_filesTableSize;
				return PUS_SET_ERROR(PUS_NO_ERROR);
			}
			j = (j + 1)%pus_files_filesTableSize;
		}
	}

	return PUS_SET_ERROR(PUS_ERROR_CREATING_FILE);
}


pusError_t pus_files_deleteFile(const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName)
{
	if( NULL == repository || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if (!pus_files_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	if( false == pus_files_isSameRepository(repository, &serviceRepository))
	{
		return PUS_SET_ERROR(PUS_ERROR_FILE_REPOSITORY);
	}

	size_t index;
	if( false == pus_files_isFileInTable(repository, fileName, &index))
	{
		return PUS_GET_ERROR();
	}

	char path[100];
	pusSt23RepositoryDomain_t domain;
	pus_files_getDomainFromRepositoryPath(&domain, repository);
	sprintf(path, "%s%s", (char*)domain.arr, (char*)fileName->arr);
	if( 0 == remove( path ))
	{
		pus_files_filesTable[index].deleted = true;
		return PUS_NO_ERROR;
	}
	else
	{
		return PUS_SET_ERROR(PUS_ERROR_DELETING_FILE);
	}
}

pusError_t pus_files_copyFile(const pusSt23RepositoryPath_t* sourceRepository, const pusSt23FileName_t* sourceFileName,
								const pusSt23RepositoryPath_t* targetRepository, const pusSt23FileName_t* targetFileName)
{
	if( NULL == sourceRepository || NULL == sourceFileName || NULL == targetRepository || NULL == targetFileName)
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	size_t index;

	if( true == pus_files_isSameRepository(sourceRepository, &serviceRepository))
	{
		if( false == pus_files_isFileInTable(sourceRepository, sourceFileName, &index))
		{
			(void)index;
			return PUS_GET_ERROR();
		}
	}

	if( true == pus_files_isSameRepository(targetRepository, &serviceRepository))
	{
		if( true == pus_files_isFileInTable(targetRepository, targetFileName, &index))
		{

			return PUS_SET_ERROR(PUS_ERROR_FILE_IN_TABLE);
		}

		if( PUS_NO_ERROR != pus_files_createFile(targetRepository, targetFileName, pus_ST23_MAX_SIZE_FILE))
		{
			return PUS_GET_ERROR();
		}
	}
	(void)index; //avoid unused variable warning

	pusSt23RepositoryDomain_t sourceDomain, targetDomain;
	pus_files_getDomainFromRepositoryPath(&sourceDomain, sourceRepository);
	pus_files_getDomainFromRepositoryPath(&targetDomain, targetRepository);

	char ch, source_file[200], target_file[200];
	FILE *source, *target;

	sprintf( source_file, "%s%s", (char*)sourceDomain.arr, (char*)sourceFileName->arr);
	sprintf( target_file, "%s%s", (char*)targetDomain.arr, (char*)targetFileName->arr);

	source = fopen(source_file, "r");
	if( source == NULL )
	{
		return PUS_SET_ERROR(PUS_ERROR_COPYING_FILE);
	}

	target = fopen(target_file, "w");
	if( target == NULL )
	{
		fclose(source);
		return PUS_SET_ERROR(PUS_ERROR_COPYING_FILE);
	}

	while( ( ch = fgetc(source) ) != EOF )
		fputc(ch, target);

	fclose(source);
	fclose(target);

	return PUS_SET_ERROR(PUS_NO_ERROR);
}


pusError_t pus_files_getFileMaxSize(pusSt23MaximumSize_t* maxSize, const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName)
{
	if( NULL == repository || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if (!pus_files_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	if( false == pus_files_isFileInTable(repository, fileName, NULL))
	{
		return PUS_SET_ERROR( PUS_ERROR_FILE_IN_TABLE );
	}
	for(size_t i = 0; i < pus_files_filesTableSize; i++)
	{
		if(pus_files_isSameFileName(fileName, &pus_files_filesTable[i].fileName))
		{
			*maxSize = pus_files_filesTable[i].maxSize;
		}
	}

	return PUS_SET_ERROR(PUS_NO_ERROR);
}

pusError_t pus_files_getDomainFromRepositoryPath(pusSt23RepositoryDomain_t* domain, const pusSt23RepositoryPath_t* repositoryPath)
{
	if( NULL == domain || NULL == repositoryPath )
	{
		return PUS_SET_ERROR(PUS_NO_ERROR);
	}
	if( ! pus_files_isInitialized() )
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	for(size_t i = 0; i < pus_files_repositoriesTableSize; i++)
	{
		if( pus_files_isSameRepository(repositoryPath, &pus_files_repositoriesTable[i].repository))
		{
			*domain = pus_files_repositoriesTable[i].domain;
		}
	}

	return PUS_SET_ERROR(PUS_ERROR_FILE_REPOSITORY);
}

pusError_t pus_files_getSystemFromRepositoryPath(pusSt23RepositorySystem_t* system, const pusSt23RepositoryPath_t* repositoryPath)
{
	if( NULL == system || NULL == repositoryPath )
	{
		return PUS_SET_ERROR(PUS_NO_ERROR);
	}
	if( ! pus_files_isInitialized() )
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	for(size_t i = 0; i < pus_files_repositoriesTableSize; i++)
	{
		if( pus_files_isSameRepository(repositoryPath, &pus_files_repositoriesTable[i].repository))
		{
			*system = pus_files_repositoriesTable[i].system;
		}
	}

	return PUS_SET_ERROR(PUS_ERROR_FILE_REPOSITORY);
}




