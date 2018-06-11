/*! \file pus_file_management.h
 *  \brief Functions for managing ...
 *
 *  This module contains functions to ...
 *
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_FILE_MANAGEMENT_H
#define PUS_FILE_MANAGEMENT_H

#include "pus_types.h"
#ifdef PUS_CONFIGURE_ST23_ENABLED

#include "pus_error.h"
#include "pus_threads.h"

#include <stdio.h>

#ifdef  __cplusplus
extern "C" {
#endif


#ifdef __gnu_linux__
	typedef FILE pusSt23FileDescriptor_t;
#endif

#ifdef RTEMS_____
	typedef uint8_t pusSt23FileDescriptor_t;
#endif

//! Type to manage files
typedef struct
{
	pusSt23RepositoryPath_t repository; //!< Repository of the file
	pusSt23FileName_t fileName; //!< File name
	pusSt23MaximumSize_t maxSize; //!< Size  of the file
	bool opened; //!< True if file is opened
	bool deleted; //!< True if file is deleted
	pusSt23FileDescriptor_t* file; //descriptor
}pusSt23File_t;

//! Type to manage files
typedef struct
{
	pusSt23RepositoryPath_t repository; //!< Repository
	pusSt23RepositoryDomain_t domain; //!< Domain of the repository
	pusSt23RepositorySystem_t system; //!< System of the repository
}pusSt23Repository_t;


// Mutex to lock access to the event tables
extern pusMutex_t* pus_files_mutex;

// Initialized flag
extern bool pus_files_initializedFlag;

//! Function to initialize the files manager used by service ST[23]
/*! This function is generated from the mission database, and it should be declared
 *  in \ref pus_st05_config.h
 */
extern pusError_t pus_files_configure();


//! Initialize the data structures of the files manager
/*! Create the parameter tables from the configuration and initializes a mutex.
 *  Alternatively, can pass NULL as mutex if access protection is provided externally,
 *  for instance, by TASTE.
 *  \param[inout] mutex Mutex to be initialized; if NULL, access protection is disabled
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_files_initialize(pusMutex_t* mutex, pusSt23RepositoryId_t repositoryId);

//! Release the resources allocated by the files manager
/*! \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_files_finalize();

//! Check if the files manager is initialized
bool pus_files_isInitialized();

pusError_t pus_files_createFile(pusSt23RepositoryPath_t* repository, pusSt23FileName_t* fileName, pusSt23MaximumSize_t size);

pusError_t pus_files_deleteFile(pusSt23RepositoryPath_t* repository, pusSt23FileName_t* fileName);

bool pus_files_isFileInTable(pusSt23RepositoryPath_t* repository, pusSt23FileName_t* fileName, size_t* index);

bool pus_files_isSameRepository(pusSt23RepositoryPath_t* repository1, pusSt23RepositoryPath_t* repository2);

bool pus_files_isSameFileName(pusSt23FileName_t* fileName1, pusSt23FileName_t* fileName2);

pusError_t pus_files_copyFile(pusSt23RepositoryPath_t* sourceRepository, pusSt23FileName_t* sourceFileName,
								pusSt23RepositoryPath_t* targetRepository, pusSt23FileName_t* targetFileName);

pusError_t pus_files_copyFileLinuxLocalToLinuxLocal(pusSt23RepositoryDomain_t* sourceDomain, pusSt23FileName_t* sourceFileName,
										pusSt23RepositoryDomain_t* targetDomain, pusSt23FileName_t* targetFileName);

pusError_t pus_files_getRepositoryPathFromId(pusSt23RepositoryPath_t* path, pusSt23RepositoryId_t id);

pusError_t pus_files_copyFromLocalToLocalLinux(pusSt23FileName_t* sourceFileName, pusSt23FileName_t* targetFileName);


pusError_t pus_files_getDomainFromRepositoryPath(pusSt23RepositoryDomain_t* domain, pusSt23RepositoryPath_t* repositoryPath);

#ifdef  __cplusplus
}
#endif

#endif

#endif // PUS_FILE_MANAGEMENT_H
