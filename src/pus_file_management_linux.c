#include "pus_file_management.h"
// Linux files includes
#include <stdio.h>


// Mutex to lock access to the event tables
pusMutex_t* pus_files_mutex = NULL;

// Initialized flag
bool pus_files_initializedFlag = false;


//! Type to manage files
typedef struct
{
	pusSt23RepositoryPath_t repository; //!< Reposirory of the file
	pusSt23FileName_t fileName; //!< File name
	pusSt23MaximumSize_t maxSize; //!< Size  of the file
	bool opened; //!< True if definition is opened
}pusSt23File_t;

pusError_t pus_files_initialize(pusMutex_t* mutex)
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
pusError pus_files_open(pusSt23FileId_t id)
{
	FILE *fp;

	fp = fopen("/tmp/test.txt", "w+");
	fprintf(fp, "This is testing for fprintf 1...\n");
	fputs("This is testing for fputs...\n", fp);
	fclose(fp);

	return PUS_NO_ERROR;
}

pusError pus_files_open(pusSt23FileId_t id)
{

	//fclose(fp);

	return PUS_NO_ERROR;
}


//close file
