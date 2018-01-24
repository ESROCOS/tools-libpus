/*! \file pus_file_management.h
 *  \brief Functions for managing ...
 *
 *  This module contains functions to ...
 *
 *
 *  \author GMV
 */

#ifndef PUS_FILE_MANAGEMENT_H
#define PUS_FILE_MANAGEMENT_H

#include "pus_types.h"
#include "pus_error.h"
#include "pus_threads.h"

#include <stdio.h>

#ifdef  __cplusplus
extern "C" {
#endif

//! Type to manage files
typedef struct
{
	pusSt23RepositoryPath_t repository; //!< Reposirory of the file
	pusSt23FileName_t fileName; //!< File name
	pusSt23MaximumSize_t maxSize; //!< Size  of the file
	bool opened; //!< True if file is opened
	bool deleted; //!< True if file is deleted
	FILE* file;
}pusSt23File_t;

extern pusSt23FilesTableSize_t pus_files_tableSize;

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
pusError_t pus_files_initialize(pusMutex_t* mutex, pusSt23RepositoryPath_t* repository);

//! Release the resources allocated by the files manager
/*! \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_files_finalize();

//! Check if the files manager is initialized
bool pus_files_isInitialized();

pusError_t pus_files_createFile(pusSt23RepositoryPath_t* repository, pusSt23FileName_t* fileName, pusSt23MaximumSize_t size);
pusError_t pus_files_deleteFile(pusSt23RepositoryPath_t* repository, pusSt23FileName_t* fileName);


#ifdef  __cplusplus
}
#endif

#endif // PUS_FILE_MANAGEMENT_H
