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

extern pusSt23FilesTableSize_t pus_files_tableSize;
extern pusSt23File_t pus_files_table[];

pusError_t pus_files_initialize(pusMutex_t* mutex, pusSt23RepositoryPath_t* repository)
{
	if( NULL == repository)
	{
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

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
	for(size_t i = 0; i < pus_files_tableSize; i++)
	{
		pus_files_table[i].opened = false;
		pus_files_table[i].deleted = true;
	}

	//Reposirory
	serviceRepository = *repository;

	// Flag service initialized = true
	pus_files_initializedFlag = true;
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

//open file
pusError_t pus_files_createFile(pusSt23RepositoryPath_t* repository, pusSt23FileName_t* fileName, pusSt23MaximumSize_t size)
{
	if( NULL == repository || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}

	if (!pus_files_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		static size_t j = 0;

		for( size_t i = 0; i < pus_files_tableSize; i++)
		{
			if(pus_files_table[j].deleted == true )
			{
				FILE* fp;

				fp = fopen((char*)fileName->arr, "w");
				if(fp == NULL)
				{
					return PUS_SET_ERROR(PUS_ERROR_CREATING_FILE);
				}

				fseek(fp, size-1, 0);
				fputs("5", fp);
				if( (uint32_t)ftell(fp) != size)
				{
					return PUS_SET_ERROR(PUS_ERROR_CREATING_FILE);
				}
				fclose(fp);

				pus_files_table[j].fileName = *fileName;
				pus_files_table[j].repository = *repository;
				pus_files_table[j].maxSize = size;
				pus_files_table[j].deleted = false;
				j = (j + 1)%pus_files_tableSize;

				return PUS_SET_ERROR(PUS_NO_ERROR);
			}
		}
	}

	return PUS_SET_ERROR(PUS_ERROR_CREATING_FILE);
}

pusError_t pus_files_isFileInTable(pusSt23RepositoryPath_t* repository, pusSt23FileName_t* fileName)
{
	/*if(repository->nCount == serviceRepository.nCount)
	{

	}*/

	return PUS_NO_ERROR;
}

pusError_t pus_files_deleteFile(pusSt23RepositoryPath_t* repository, pusSt23FileName_t* fileName)
{
	if( NULL == repository || NULL == fileName )
	{
		return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
	}
	if (!pus_files_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	if( PUS_NO_ERROR != pus_files_isFileInTable(repository, fileName))
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	// get table index TODO

	int ret;
	ret = remove((char*)fileName->arr);
	if( 0 == ret )
	{
		//pus_files_table[j].deleted = true; TODO
		return PUS_NO_ERROR;
	}
	else
	{
		return PUS_SET_ERROR(PUS_ERROR_DELETING_FILE);
	}
}




//close file
