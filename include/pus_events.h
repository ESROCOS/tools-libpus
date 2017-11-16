//! \file pus_events.h
/*! \brief Management of the events table used by several services
 *
 *  Defines the parameters table used by the service ST[05], ST[18] and ST[19].
 *
 *  The table contains the last N events. This allows that each of the services that
 *  have to process the event can do it in turn, provided that there are not too
 *  many events. Each service passes a counter of the last event processed when
 *  requesting the next event available. It is possible that several activations of
 *  the same event are in the table at the same time.
 *
 *  Access to the table is optionally protected by a mutex. This allows implementing
 *  the service using external synchronization (by TASTE) or not.
 *
 *  \author GMV
 */

#ifndef PUS_EVENTS_H
#define PUS_EVENTS_H

#include "pus_types.h"
#include "pus_error.h"
#include "pus_apid.h"
#include "pus_threads.h"


//
// Data types
//
/*
//! Type of supported parameter types
typedef enum
{
	PUS_ST03_INT32,
	PUS_ST03_UINT32,
	PUS_ST03_REAL64,
	PUS_ST03_BYTE,
	PUS_ST03_BOOL
} pusSt03ParamType_t;

//! Type to describe a parameter: type, label, etc. (the parameter ID gives its location in the array)
typedef struct
{
	const char* label; //!< Name of the parameter, for debugging purposes
	pusSt03ParamType_t type; //!< Data type
} pusSt03ParamInfo_t;

//! Type used for the internal storage of parameters in an array
typedef uint64_t pusStoredParam_t;

//! Type to define the structure of a housekeeping report
typedef struct
{
	size_t numParams;			//!< Number of parameters in the report
	pusSt03ParamId_t* paramIds;	//!< IDs of the parameters in the report
} pusSt03ReportInfo_t;

*/


//
// Service initialization and tear down
//

//! Function to initialize the event manager used by service ST[05] and several others
/*! This function is generated from the mission database, and it should be declared
 *  in \ref pus_st05_config.h
 */
extern pusError_t pus_events_configure();

//! Initialize the data structures of the event manager
/*! Create the parameter tables from the configuration and initializes a mutex.
 *  Alternatively, can pass NULL as mutex if access protection is provided externally,
 *  for instance, by TASTE.
 *  \param[inout] mutex Mutex to be initialized; if NULL, access protection is disabled
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_events_initialize(pusMutex_t* mutex);

//! Release the resources allocated by the event manager
/*! \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_events_finalize();

//! Check if the event manager is initialized
bool pus_events_isInitialized();


////
//// Getters and setters for HK parameters
////
//
////! Get the current value of an uint32_t parameter, using a lock
///*! If the service was initialized with mutex, uses it to lock the parameter table.
// *  \param[in] param The parameter identifier
// *  \param[out] outValue The parameter value
// *  \return Error code (PUS_NO_ERROR if success)
// */
//pusError_t pus_hk_getUInt32Param(pusSt03ParamId_t param, uint32_t* outValue);
//
////! Set the value of an uint32_t parameter, using a lock
///*! If the service was initialized with mutex, uses it to lock the parameter table.
// *  \param[in] param The parameter identifier
// *  \param[in] value The parameter value
// *  \return Error code (PUS_NO_ERROR if success)
// */
//pusError_t pus_hk_setUInt32Param(pusSt03ParamId_t param, uint32_t value);
//
////! Get the current value of an int32_t parameter, using a lock
///*! If the service was initialized with mutex, uses it to lock the parameter table.
// *  \param[in] param The parameter identifier
// *  \param[out] outValue The parameter value
// *  \return Error code (PUS_NO_ERROR if success)
// */
//pusError_t pus_hk_getInt32Param(pusSt03ParamId_t param, int32_t* outValue);
//
////! Set the value of an int32_t parameter, using a lock
///*! If the service was initialized with mutex, uses it to lock the parameter table.
// *  \param[in] param The parameter identifier
// *  \param[in] value The parameter value
// *  \return Error code (PUS_NO_ERROR if success)
// */
//pusError_t pus_hk_setInt32Param(pusSt03ParamId_t param, int32_t value);
//
////! Get the current value of a double parameter, using a lock
///*! If the service was initialized with mutex, uses it to lock the parameter table.
// *  \param[in] param The parameter identifier
// *  \param[out] outValue The parameter value
// *  \return Error code (PUS_NO_ERROR if success)
// */
//pusError_t pus_hk_getReal64Param(pusSt03ParamId_t param, double* outValue);
//
////! Set the value of a double parameter, using a lock
///*! If the service was initialized with mutex, uses it to lock the parameter table.
// *  \param[in] param The parameter identifier
// *  \param[in] value The parameter value
// *  \return Error code (PUS_NO_ERROR if success)
// */
//pusError_t pus_hk_setReal64Param(pusSt03ParamId_t param, double value);
//
////! Get the current value of a bool parameter, using a lock
///*! If the service was initialized with mutex, uses it to lock the parameter table.
// *  \param[in] param The parameter identifier
// *  \param[out] outValue The parameter value
// *  \return Error code (PUS_NO_ERROR if success)
// */
//pusError_t pus_hk_getBoolParam(pusSt03ParamId_t param, bool* outValue);
//
////! Set the value of a Boolean parameter, using a lock
///*! If the service was initialized with mutex, uses it to lock the parameter table.
// *  \param[in] param The parameter identifier
// *  \param[in] value The parameter value
// *  \return Error code (PUS_NO_ERROR if success)
// */
//pusError_t pus_hk_setBoolParam(pusSt03ParamId_t param, bool value);
//
////! Get the current value of an uint8_t parameter, using a lock
///*! If the service was initialized with mutex, uses it to lock the parameter table.
// *  \param[in] param The parameter identifier
// *  \param[out] outValue The parameter value
// *  \return Error code (PUS_NO_ERROR if success)
// */
//pusError_t pus_hk_getByteParam(pusSt03ParamId_t param, uint8_t* outValue);
//
////! Set the value of an uint8_t parameter, using a lock
///*! If the service was initialized with mutex, uses it to lock the parameter table.
// *  \param[in] param The parameter identifier
// *  \param[in] value The parameter value
// *  \return Error code (PUS_NO_ERROR if success)
// */
//pusError_t pus_hk_setByteParam(pusSt03ParamId_t param, uint8_t value);
//
//
////
//// Cast parameter to type
////
//
////! Convert a value from the internal parameter format to uint32_t
//pusError_t pus_hk_paramToUInt32(uint32_t* outValue, pusStoredParam_t paramValue);
//
////! Convert a value from the internal parameter format to int32_t
//pusError_t pus_hk_paramToInt32(int32_t* outValue, pusStoredParam_t paramValue);
//
////! Convert a value from the internal parameter format to uint32_t
//pusError_t pus_hk_paramToReal64(double* outValue, pusStoredParam_t paramValue);
//
////! Convert a value from the internal parameter format to uint32_t
//pusError_t pus_hk_paramToBool(bool* outValue, pusStoredParam_t paramValue);
//
////! Convert a value from the internal parameter format to uint32_t
//pusError_t pus_hk_paramToByte(uint8_t* outValue, pusStoredParam_t paramValue);


#endif // PUS_EVENTS_H
