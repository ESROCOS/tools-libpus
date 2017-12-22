//! \file pus_housekeeping.h
/*! \brief Management of on-board parameters
 *
 *  Defines the parameters table used by the service ST[20].
 *
 *  Access to the table is optionally protected by a mutex. This allows implementing
 *  the service using external synchronization (by TASTE) or not.
 *
 *  \author GMV
 */

#ifndef PUS_PARAMETER_MANAGEMENT_H
#define PUS_PARAMETER_MANAGEMENT_H

#include "pus_types.h"
#include "pus_error.h"
#include "pus_apid.h"
#include "pus_threads.h"
#include "pus_stored_param.h"

#ifdef  __cplusplus
extern "C" {
#endif

//
// Data types
//

//! Type to describe a parameter: type, label, etc. (the parameter ID gives its location in the array)
typedef struct
{
	const char* label; //!< Name of the parameter, for debugging purposes
	pusParamType_t type; //!< Data type
} pusSt20ParamInfo_t;



//
// Service initialization and tear down
//

//! Function to initialize the service ST[20] configuration
/*! This function is generated from the mission database, and it should be declared
 *  in \ref pus_st20_config.h
 */
extern pusError_t pus_parameters_configure();

//! Initialize the data structures of the PUS ST[20] service
/*! Create the parameter tables from the configuration and initializes a mutex.
 *  Alternatively, can pass NULL as mutex if access protection is provided externally,
 *  for instance, by TASTE.
 *  \param[inout] mutex Mutex to be initialized; if NULL, access protection is disabled
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_initialize(pusMutex_t* mutex);

//! Release the resources allocated by the PUS ST[20] service
/*! \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_finalize();

//! Check if the service ST[20] is initialized
bool pus_parameters_isInitialized();



#ifdef  __cplusplus
}
#endif

#endif // PUS_HOUSEKEEPING_H
