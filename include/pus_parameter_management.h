/*! \file pus_parameter_management.h
 *  \brief Management of on-board parameters
 *
 *  Defines the parameters table used by the service ST[20].
 *
 *  Access to the table is optionally protected by a mutex. This allows implementing
 *  the service using external synchronization (by TASTE) or not.
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_PARAMETER_MANAGEMENT_H
#define PUS_PARAMETER_MANAGEMENT_H

#include "pus_types.h"
#ifdef PUS_CONFIGURE_ONBOARD_PARAMS_TABLE

#include "pus_error.h"
#include "pus_apid.h"
#include "pus_threads.h"
#include "pus_stored_param.h"
#include "pus_packet.h"
#include <string.h>

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

//! Array with parameter information (length = number of parameters)
extern pusSt20ParamInfo_t pus_st20_paramInfo[];

//! Array for parameters values (all stored in 64 bits)
extern pusStoredParam_t pus_st20_params[];

//! ST[20]on board parameters limit
extern const pusSt20OnBoardParamId_t pus_ST20_PARAM_LIMIT;

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


//
// Getters and setters for PM (parameter management) parameters
//

//! Get the current value of a parameter in 64 bits, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_getStoredParam(pusSt20OnBoardParamId_t param, pusStoredParam_t* outValue);

//! Set a value of a parameter in 64 bits, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_setStoredParam(pusSt20OnBoardParamId_t param, pusStoredParam_t outValue);

//! Get the current value of an uint32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_getUInt32Param(pusSt20OnBoardParamId_t param, uint32_t* outValue);

//! Set the value of an uint32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_setUInt32Param(pusSt20OnBoardParamId_t param, uint32_t value);

//! Get the current value of an int32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_getInt32Param(pusSt20OnBoardParamId_t param, int32_t* outValue);

//! Set the value of an int32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_setInt32Param(pusSt20OnBoardParamId_t param, int32_t value);

//! Get the current value of a double parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_getReal64Param(pusSt20OnBoardParamId_t param, double* outValue);

//! Set the value of a double parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_setReal64Param(pusSt20OnBoardParamId_t param, double value);

//! Get the current value of a bool parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_getBoolParam(pusSt20OnBoardParamId_t param, bool* outValue);

//! Set the value of a Boolean parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_setBoolParam(pusSt20OnBoardParamId_t param, bool value);

//! Get the current value of an uint8_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_getByteParam(pusSt20OnBoardParamId_t param, uint8_t* outValue);

//! Set the value of an uint8_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_setByteParam(pusSt20OnBoardParamId_t param, uint8_t value);

//! Get the type of the parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] type The parameter type
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_parameters_getParamType(pusSt20OnBoardParamId_t param, pusParamType_t* type);


#ifdef  __cplusplus
}
#endif

#endif

#endif // PUS_HOUSEKEEPING_H
