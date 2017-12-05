//TODO header

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


typedef struct{
	//bool checking_status;
	//int repetition; //repetition number
	//int check_type; //limit, expect, delta //TODO ENUM?
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
bool pus_pmon_inInDefinitionList(pusSt12PmonId_t id);

//! Check if a value is valid
pusError_t pus_pmon_checkParameter(pusSt12PmonId_t id, int value);



#ifdef  __cplusplus
}
#endif

#endif
