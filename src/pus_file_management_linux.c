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

bool pus_files_isSameRepository(pusSt23RepositoryPath_t* repository1, pusSt23RepositoryPath_t* repository2)
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


bool pus_files_isSameFileName( pusSt23FileName_t* fileName1, pusSt23FileName_t* fileName2)
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

bool pus_files_isFileInTable(pusSt23RepositoryPath_t* repository, pusSt23FileName_t* fileName, size_t* index)
{
	if( NULL == repository || NULL == fileName )
	{
		PUS_SET_ERROR(PUS_ERROR_NULLPTR);
		return false;
	}
	if( ! pus_files_isSameRepository(repository, &serviceRepository))
	{
		PUS_SET_ERROR(PUS_ERROR_FILE_REPOSITORY);
		return false;
	}
	for(size_t i = 0; i < pus_files_tableSize; i++)
	{
		if( pus_files_table[i].deleted == false )
		{
			if(pus_files_isSameFileName(fileName, &pus_files_table[i].fileName))
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

	PUS_SET_ERROR( PUS_ERROR_FILE_NOT_FOUND );
	return false;
}


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
	if( pus_files_isFileInTable(repository, fileName, NULL))
	{
		return PUS_SET_ERROR( PUS_ERROR_FILE_IN_TABLE );;
	}
	else
	{
		static size_t j = 0;

		for( size_t i = 0; i < pus_files_tableSize; i++)
		{
			if( pus_files_table[j].deleted == true )
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

				return PUS_SET_ERROR(PUS_NO_ERROR);
			}
			j = (j + 1)%pus_files_tableSize;
		}
	}

	return PUS_SET_ERROR(PUS_ERROR_CREATING_FILE);
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
	size_t index;
	if( false == pus_files_isFileInTable(repository, fileName, &index))
	{
		return PUS_GET_ERROR();
	}

	if( 0 == remove((char*)fileName->arr) )
	{
		pus_files_table[index].deleted = true;
		return PUS_NO_ERROR;
	}
	else
	{
		return PUS_SET_ERROR(PUS_ERROR_DELETING_FILE);
	}
}


int copy_file(char *old_filename, char  *new_filename)
{
	FILE  *ptr_old, *ptr_new;
	int a;

	ptr_old = fopen(old_filename, "r");
	if( NULL == ptr_old )
	{
		printf("Error fopen\n");
		return PUS_SET_ERROR(PUS_ERROR_CREATING_FILE);
	}

	ptr_new = fopen(new_filename, "w");
	if( NULL == ptr_new )
	{
		fclose(ptr_new);
		printf("Error fopen\n");
		return PUS_SET_ERROR(PUS_ERROR_CREATING_FILE);
	}

	while(1)
	{
		a  =  fgetc(ptr_old);

		if(!feof(ptr_old))
			fputc(a, ptr_new);
		else
			break;
	}

	fclose(ptr_new);
	fclose(ptr_old);
	return  0;
}

pusError_t pus_files_copyFile(pusSt23RepositoryPath_t* sourceRepository, pusSt23FileName_t* sourceFileName,
								pusSt23RepositoryPath_t* targetRepository, pusSt23FileName_t* targetFileName)
{
	// from service
	if( pus_files_isSameRepository(sourceRepository, &serviceRepository) )
	{
		size_t index;
		if( false == pus_files_isFileInTable(sourceRepository, sourceFileName, &index))
		{
			return PUS_GET_ERROR();
		}

		return PUS_NO_ERROR;
	}
	// to service
	if( pus_files_isSameRepository(targetRepository, &serviceRepository) )
	{
		size_t index;
		if( false == pus_files_isFileInTable(targetRepository, targetFileName, &index))
		{
			return PUS_GET_ERROR();
		}


		return PUS_NO_ERROR;
	}

	return PUS_SET_ERROR(PUS_ERROR_FILE_REPOSITORY);
}


