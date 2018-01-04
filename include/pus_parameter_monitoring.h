/*! \file pus_parameter_monitoring.h
 *  \brief Management of the parameter monitoring table
 *
 *  Defines the parameters monitoring table used by the service ST[12].
 *
 *  Access to the table is optionally protected by a mutex. This allows implementing
 *  the service using external synchronization (by TASTE) or not.
 *
 *  \author GMV
 */

#ifndef PUS_PARAMETER_MONITORING_H
#define PUS_PARAMETER_MONITORING_H

#ifdef  __cplusplus
extern "C" {
#endif

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_threads.h"
#include "pus_types.h"
#include "pus_packet.h"
#include "pus_stored_param.h"
#include "pus_housekeeping.h"


typedef struct{
	//bool checking_status;
	//int repetition; //repetition number
	//int check_type; //limit, expect, delta
	union uLow
	{
		int32_t INT32;
		uint32_t UINT32;
		double REAL64;
		bool BOOL;
		byte BYTE;
	}low_limit;
	union uHigh
	{
		int32_t INT32;
		uint32_t UINT32;
		double REAL64;
		bool BOOL;
		byte BYTE;
	}high_limit;
	//int expected;
	//int mask;
}pusSt12CheckDefinition;

typedef struct{
	// pmon id -> array index;
	// param id -> array index (1 pmon per param)
	bool status;
	pusSt12CheckDefinition check;
}pusSt12PmonDefinition;

extern const pusSt12PmonId_t pus_ST12_PARAM_LIMIT;



//! Function to initialize the monitored params used by service ST[12] and several others
/*! This function is generated from the mission database, and it should be declared
 *  in \ref pus_st12_config.h
 */
extern pusError_t pus_pmon_configure();

//! Initialize the data structures of the PMON service
/*! Create the parameter tables from the configuration and initializes a mutex.
 *  Alternatively, can pass NULL as mutex if access protection is provided externally,
 *  for instance, by TASTE.
 *  \param[inout] mutex Mutex to be initialized; if NULL, access protection is disabled
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_pmon_initialize(pusMutex_t* mutex);

//! Release the resources allocated by the event manager
/*! \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_pmon_finalize();

//! Check if the event manager is initialized
bool pus_pmon_isInitialized();

//! Check if the PMON function is activated
bool pus_pmon_isFunctionActivated();

//! Get for the definition status
bool pus_pmon_getDefinitionStatus(pusSt12PmonId_t id);

//! Set for the definition status
pusError_t pus_pmon_setDefinitionStatus(pusSt12PmonId_t id, bool status);

//
// PMON behaviour
//
//! Enable a PMON definition
pusError_t pus_pmon_enableDefinition(pusSt12PmonId_t id);

//! disable a PMON definition
pusError_t pus_pmon_disableDefinition(pusSt12PmonId_t id);

//! Enable the PMON function
pusError_t pus_pmon_enableFunction();

//! Disable the PMON function
pusError_t pus_pmon_disableFunction();

//! Check if a PMON Id is in the param list
bool pus_pmon_isInDefinitionList(pusSt12PmonId_t id);

//! Check if a value is valid
pusError_t pus_pmon_checkParameter(pusSt12PmonId_t id);


//
// Checking limits.
//
//! Check if a Int32 param is in its limits
pusError_t pus_pmon_checkLimitInt32(pusSt12PmonId_t id, int32_t value);

//! Check if a Uint32 param is in its limits
pusError_t pus_pmon_checkLimitUint32(pusSt12PmonId_t id, uint32_t value);

//! Check if a Real64 param is in its limits
pusError_t pus_pmon_checkLimitReal64(pusSt12PmonId_t id, double value);

//! Check if a Byte param is in its limits
pusError_t pus_pmon_checkLimitByte(pusSt12PmonId_t id, uint8_t value);

//! Check if a Bool param is in its limits
pusError_t pus_pmon_checkLimitBool(pusSt12PmonId_t id, bool value);


#ifdef  __cplusplus
}
#endif

#endif
