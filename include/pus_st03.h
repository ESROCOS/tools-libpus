//! \file pus_st03.h
/*! \brief Implementation of the PUS service ST[03] Housekeeping.
 *
 *  This module contains the functions to manage the on-board housekeeping parameters
 *  database, to generate housekeeping and parameter reports, and to process the TCs
 *  to manage this service.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 *  - Housekeeping
 *    +
 *
 *  \author GMV
 */

#ifndef PUS_ST03_H
#define PUS_ST03_H

#include "pus_types.h"
#include "pus_error.h"
#include "pus_apid.h"
#include "pus_threads.h"


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


//! Function to initialize the service ST[03] configuration
/*! This function is generated from the mission database, and it should be declared
 *  in \ref pus_st03_config.h
 */
extern pusError_t pus_st03_configure();

//! Initialize the data structures of the PUS ST[03] service
/*! Create the parameter tables from the configuration and initializes a mutex.
 *  Alternatively, can pass NULL as mutex if access protection is provided externally,
 *  for instance, by TASTE.
 *  \param[inout] mutex Mutex to be initialized; if NULL, access protection is disabled
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_initialize(pusMutex_t* mutex);

//! Release the resources allocated by the PUS ST[03] service
/*! \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_finalize();

//! Check if the service ST[03] is initialized
bool pus_st03_isInitialized();


//! Build the default housekeeping parameter report
/*! Builds a TM[1,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_3_25_createHousekeepingReportDefault(pusPacket_t* outTm, pusApidInfo_t* apid);

//! Build a housekeeping parameter report
/*! Builds a TM[1,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \param[in] reportId The report ID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_3_25_createHousekeepingReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusSt03HousekeepingReportId_t reportId);

//! Get the current value of an uint32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_getUInt32Param(pusSt03ParamId_t param, uint32_t* outValue);

//! Set the value of an uint32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_setUInt32Param(pusSt03ParamId_t param, uint32_t value);

//! Get the current value of an int32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_getInt32Param(pusSt03ParamId_t param, int32_t* outValue);

//! Set the value of an int32_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_setInt32Param(pusSt03ParamId_t param, int32_t value);

//! Get the current value of a double parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_getReal64Param(pusSt03ParamId_t param, double* outValue);

//! Set the value of a double parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_setReal64Param(pusSt03ParamId_t param, double value);

//! Get the current value of a bool parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_getBoolParam(pusSt03ParamId_t param, bool* outValue);

//! Set the value of a Boolean parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_setBoolParam(pusSt03ParamId_t param, bool value);

//! Get the current value of an uint8_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[out] outValue The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_getByteParam(pusSt03ParamId_t param, uint8_t* outValue);

//! Set the value of an uint8_t parameter, using a lock
/*! If the service was initialized with mutex, uses it to lock the parameter table.
 *  \param[in] param The parameter identifier
 *  \param[in] value The parameter value
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st03_setByteParam(pusSt03ParamId_t param, uint8_t value);



#endif // PUS_ST03_H
