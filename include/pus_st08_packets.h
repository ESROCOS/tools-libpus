/*! \file pus_st08_packets.h
 *  \brief PUS service ST[08] Function management
 *
 *  This module provides the functions to generate the TC of the service ST[08],
 *  as well as getter/setter and checking functions.
 *
 *	Implemented subservices:
 *  - TC[8,1] Perform a function.
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */


#ifndef PUS_ST08_PACKETS_H
#define PUS_ST08_PACKETS_H


#include "pus_types.h"
#ifdef PUS_CONFIGURE_ST08_ENABLED

#include "pus_error.h"
#include "pus_packet.h"
#include "pus_apid.h"

#ifdef  __cplusplus
extern "C" {
#endif

//! Type to describe a function: label, ..
typedef struct
{
	const char* label; //!< Name of the event, for debugging purposes
} pusSt08FunctionInfo_t;

//! Function to initialize the service ST[08] configuration
/*! This function is generated from the mission database, and it should be declared
 *  in \ref pus_st08_config.h
 */
extern pusError_t pus_st08_configure();

//! Function that initialize the ST08 service.
pusError_t pus_st08_initialize(pusMutex_t* mutex);

//! Finalize the service
pusError_t pus_st08_finalize();

//! Check if the ST08 is initalized.
bool pus_st08_isInitialized();


//! Build a Perform a function request packet.
/*! Builds a TC[8_1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TC
 *  \param[in] apid APID of the process sending the request
 *  \param[in] functionId The function that shall be performed
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_8_1_createPerformFuctionRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt08FunctiontId_t functionId);

//! Setter for the functionID param
void pus_tc_8_1_setFunctionId(pusPacket_t* outTc, pusSt08FunctiontId_t functionId);

//! Getter for the functionID param
void pus_tc_8_1_getFunctionId(pusSt08FunctiontId_t* functionId, const pusPacket_t* outTc);

//! Function that check if the function ID is defined in the configuration options.
bool pus_st08_isInFunctionTable(pusSt08FunctiontId_t functionId);

//! Perform a funcion passing it ID as a parameter
pusError_t pus_st08_performAFunction(pusSt08FunctiontId_t functionId);

//
// Parameter checking
//

//! Check that a packet is of a PUS ST[08] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[08]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST08 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt08(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt08; adds function name
#define PUS_EXPECT_ST08(packet, subtype) pus_expectSt08((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif

#endif
