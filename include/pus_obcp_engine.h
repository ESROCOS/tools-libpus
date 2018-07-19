/*! \file pus_obcp_engine.h
 *  \brief Functions for managing ...
 *
 *  This module contains functions to ...
 *
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_OBCP_ENGINE_H
#define PUS_OBCP_ENGINE_H

#include "pus_types.h"
#ifdef PUS_CONFIGURE_OBCP_ENGINE

#include "pus_error.h"
#include "pus_threads.h"

#ifdef  __cplusplus
extern "C" {
#endif


// Core python py/
#include "py/runtime.h"
#include "py/gc.h"
#include "py/stackctrl.h"
#include "py/pystack.h"
#include "py/objmodule.h"
// Core python .
#include "mputil.h"

//mp_context function
#include "mpcontext.h"



#define PUS_OBCP_HEAP_SIZE 16384

#define PUS_OBCP_STACK_LIMIT 32768

typedef struct
{
    pusSt18ObcpId_t id;
    pusSt18ObservabilityLevel_t observability; //0 procedure(status), step(status at steps), detailed, none
    volatile pusSt18ObcpStatus_t status; //0: unload, 1:inactive, 2:active and running, 3: active and held
    volatile pusSt18ObcpConfirmationStatus_t confirmation;
    pusSt18ObcpStepId_t actual_step;
    pusSt18ObcpStepId_t next_step;

    pusSt18ObcpCode_t code;

    //heap / stack / ctx
    mp_state_ctx_t mp_ctx;
    uint64_t mp_heap[PUS_OBCP_HEAP_SIZE];
    mp_obj_t mp_pystack[PUS_OBCP_HEAP_SIZE];

	#ifndef PUS_DISABLE_THREADS
    	pthread_mutex_t mutex;
    	pthread_cond_t cond;
    	pthread_cond_t cond_suspend;
	#endif

    bool interpreterInitialized;
}pusObcpInfo_t;


//CODE

//! Initialize the data structures of the PUS ST[18] service
/*! Create the parameter tables from the configuration and initializes a mutex.
 *  Alternatively, can pass NULL as mutex if access protection is provided externally,
 *  for instance, by TASTE.
 *  \param[inout] mutex Mutex to be initialized; if NULL, access protection is disabled
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_initialize(pusMutex_t* mutex); //TODO Mutex as param

// Check if the OBCP service is initialized
bool pus_obcp_isInitialized();

//! Finalize the OBCP service
/*! Finalize the OBCP service
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_finalize();

//! Start the OBCP engine
/*! Start the OBCP engine
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_startEngine();

//! Stop the OBCP engine
/*! Stop the OBCP engine
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_stopEngine();

//! Check if OBCP engine is running
/*! Check if OBCP engine is running
 *  \return Boolean
 */
bool pus_obcp_isEngineRunning();

//! Get the number of OBCPs loaded and activates
/*! Get the number of OBCPs loaded and activates
 *  \return The number of OBCPs
 */
uint32_t pus_obcp_getObcpLoadedActives();

//! Get the number of OBCPs loaded and inactives
/*! Get the number of OBCPs loaded and inactives
 *  \return The number of OBCPs
 */
uint32_t pus_obcp_getObcpLoadedInactives();

//! Get the number of OBCPs slot not loaded
/*! Get the number of OBCPs slot not loaded
 *  \return The number of OBCPs
 */
uint32_t pus_obcp_getObcpSlotNotLoaded();

//! Loab an OBCP into the engine
/*! Loab an OBCP into the engine
 *  \param[in] id Identifier of the OBCP
 *  \param[in] code Code of the OBCP
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_loadObcp( pusSt18ObcpId_t* id, pusSt18ObcpCode_t* code );

//! Unload an OBCP from the engine
/*! Unload an OBCP from the engine
 *  \param[in] id Identifier of the OBCP
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_unloadObcp( pusSt18ObcpId_t* id);

//! Activate an OBCP
/*! Activate an OBCP loaded in the engine
 *  \param[in] id Identifier of the OBCP
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_activateObcp( pusSt18ObcpId_t* id);

//! Abort an OBCP
/*! Abort an OBCP loaded in the engine
 *  \param[in] id Identifier of the OBCP
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_abortObcp(pusSt18ObcpId_t* id);

//! Stop an OBCP
/*! Stop an OBCP loaded in the engine
 *  \param[in] id Identifier of the OBCP
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_stopObcp(pusSt18ObcpId_t* id);

//! Resume an OBCP
/*! Resume an OBCP loaded in the engine and suspended
 *  \param[in] id Identifier of the OBCP
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_resumeObcp( pusSt18ObcpId_t* id );

//! Execute an OBCP
/*! Execute an OBCP activated in the engine
 *  \param[in] id Identifier of the OBCP
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_executeObcp(pusSt18ObcpId_t* id);


//! Suspend an OBCP
/*! Suspend an OBCP running in the engine
 *  \param[in] id Identifier of the OBCP
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_suspendObcp(pusSt18ObcpId_t* id);

//! Check if two OBCP identifier are the same
/*! Check if two OBCP identifier are the same
 *  \param[in] id1 Identifier of the OBCP1
 *  \param[in] id2 Identifier of the OBCP2
 *  \return True if both IDs are the same, false if error
 */
bool pus_obcp_IsSameObcpId(pusSt18ObcpId_t* id1, pusSt18ObcpId_t* id2);

//! Check if an OBCP is previously loaded
/*! Check if an OBCP is previously loaded
 *  \param[in] id Identifier of the OBCP
 *  \param[out] index Index of the OBCP if it is loaded
 *  \return True if the OBCP are loaded, false if error
 */
bool pus_obcp_IsObcpLoaded( pusSt18ObcpId_t* id, size_t* index);

//! Wait until an obcp is activated
/*! Wait until an obcp is activated
 *  \param[in] obcpInfo Info struct
 *  \return True if the OBCP are activated, false if error
 */
pusError_t pus_obcp_waitForActivation(pusObcpInfo_t* obcpInfo);

//! Wait until an obcp is resumed
/*! Wait until an obcp is resumed
 *  \param[in] obcpInfo OBCP info struct
 *  \return True if the OBCP are activated, false if error
 */
pusError_t pus_obcp_waitForResume(pusObcpInfo_t* obcpInfo);

//! Wait until an obcp is resumed
/*! Wait until an obcp is resumed
 *  \param[in] id Identifier of the OBCP
 *  \return True if the OBCP are activated, false if error
 */
pusError_t pus_obcp_waitForResumeById(pusSt18ObcpId_t* id);

//! Set the status of an obcp after its execution
/*! Set the status of an obcp after its execution
 *  \param[in] obcpInfo OBCP info struct
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_setStatusAferExecution(pusObcpInfo_t* obcpInfo);

//! Set the confirmation status of an obcp
/*! Set the confirmation status of an obcp
 *  \param[in] id Identifier of the OBCP
 *  \param[in] status Status to set
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_setConfirmationStatus(pusSt18ObcpId_t* id, pusSt18ObcpConfirmationStatus_t status);

//! Get the status of an obcp
/*! Get the status of an obcp
 *  \param[in] id Identifier of the OBCP
 *  \return Status of the OBCP
 */
pusSt18ObcpStatus_t pus_obcp_getStatus(pusSt18ObcpId_t* id);

//! Set the status of an obcp
/*! Set the status of an obcp
 *  \param[in] id Identifier of the OBCP
 *  \param[in] status Status to set
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_setStatus(pusSt18ObcpId_t* id, pusSt18ObcpStatus_t status);


//! Set the load information of an OBCP
/*! Set the load information of an OBCP
 *  \param[in] obcpInfo OBCP info struct
 *  \param[in] id Identifier of the OBCP
 *  \param[in] status Status to set
 *  \param[in] code Code of the OBCP
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_setLoadInfo(pusObcpInfo_t* obcpInfo, pusSt18ObcpId_t* id, pusSt18ObcpStatus_t status, pusSt18ObcpCode_t* code);

//! Execute the code of an OBCP
/*! Execute the code of an OBCP
 *  \param[in] obcpInfo OBCP info struct
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_executeCode(pusObcpInfo_t* obcpInfo);

//! Init the uPy interpreter
/*! Init the uPy interpreter
 *  \param[in] obcpInfo OBCP info struct
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_obcp_initUPyInterpreter(pusObcpInfo_t* obcpInfo);

void* pus_obcp_thread( void * arg);

#ifdef  __cplusplus
}
#endif

#endif

#endif // PUS_OBCP_ENGINE_H

