/*! \file pus_housekeeping.h
 *  \brief Management of the housekeeping and diagnostics parameters table
 *
 *  Defines the parameters table used by the service ST[03].
 *
 *  Access to the table is optionally protected by a mutex. This allows implementing
 *  the service using external synchronization (by TASTE) or not.
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_HOUSEKEEPING_H
#define PUS_HOUSEKEEPING_H

#include "pus_types.h"
#ifdef PUS_CONFIGURE_HK_PARAMS_TABLE

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
} pusSt03ParamInfo_t;

//! Type used for the internal storage of parameters in an array
//typedef uint64_t pusStoredParam_t;

//! Type to define the structure of a housekeeping report
typedef struct
{
	size_t numParams;			//!< Number of parameters in the report
	pusSt03ParamId_t* paramIds;	//!< IDs of the parameters in the report
} pusSt03ReportInfo_t;


//
// Service initialization and tear down
//

//! Function to initialize the service ST[03] configuration
/*! This function is generated from the mission database, and it should be declared
 *  in \ref pus_st03_config.h
 */
extern pusError_t pus_hk_configure();

//! Initialize the data structures of the PUS ST[03] service
/*! Create the parameter tables from the configuration and initializes a mutex.
 *  Alternatively, can pass NULL as mutex if access protection is provided externally,
 *  for instance, by TASTE.
 *  \param[inout] mutex Mutex to be initialized; if NULL, access protection is disabled
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_initialize(pusMutex_t* mutex);

//! Release the resources allocated by the PUS ST[03] service
/*! \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_finalize();

//! Check if the service ST[03] is initialized
bool pus_hk_isInitialized();


//
// Getters and setters for HK parameters
//

//! Get the current value of a stored parameter (in 64bits), using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_getStoredParam(pusSt03ParamId_t param, pusStoredParam_t* outValue);

//! Set the value of a stored parameter (in 64bits), using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_setStoredParam(pusSt03ParamId_t param, pusStoredParam_t outValue);


//! Get the current value of an uint32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_getUInt32Param(pusSt03ParamId_t param, uint32_t* outValue);

//! Set the value of an uint32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_setUInt32Param(pusSt03ParamId_t param, uint32_t value);

//! Get the current value of an int32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_getInt32Param(pusSt03ParamId_t param, int32_t* outValue);

//! Set the value of an int32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_setInt32Param(pusSt03ParamId_t param, int32_t value);

//! Get the current value of a double parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_getReal64Param(pusSt03ParamId_t param, double* outValue);

//! Set the value of a double parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_setReal64Param(pusSt03ParamId_t param, double value);

//! Get the current value of a bool parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_getBoolParam(pusSt03ParamId_t param, bool* outValue);

//! Set the value of a Boolean parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_setBoolParam(pusSt03ParamId_t param, bool value);

//! Get the current value of an uint8_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_getByteParam(pusSt03ParamId_t param, uint8_t* outValue);

//! Set the value of an uint8_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_setByteParam(pusSt03ParamId_t param, uint8_t value);

//! Get the type of the parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] type The parameter type
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_hk_getParamType(pusSt03ParamId_t param, pusParamType_t* type);

#ifdef  __cplusplus
}
#endif

#endif

#endif // PUS_HOUSEKEEPING_H
