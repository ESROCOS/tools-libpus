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

#ifdef  __cplusplus
extern "C" {
#endif

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
pusError_t pus_files_initialize(pusMutex_t* mutex);

//! Release the resources allocated by the files manager
/*! \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_files_finalize();

//! Check if the files manager is initialized
bool pus_files_isInitialized();


#ifdef  __cplusplus
}
#endif

#endif // PUS_FILE_MANAGEMENT_H
