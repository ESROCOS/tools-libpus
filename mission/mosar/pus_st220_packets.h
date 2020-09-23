/*! \file pus_st17_packets.h
 *  \brief PUS service ST[17] Test Connection
 *
 *  This module provides the functions to generate reports of the service ST[17],
 *  as well as getter/setter and checking functions.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 *  - TC[17,1] Perform an are-you-alive connection test
 *  - TM[17,2] Are-you-alive connection test report
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */


#ifndef PUS_ST220_PACKETS_H
#define PUS_ST220_PACKETS_H

#include "pus_enable_services.h"
#ifdef PUS_CONFIGURE_ST220_ENABLED

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*! Builds a TC[200,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCount Sequence counter for this TC
 *  \param[in] state state to be added in data fueld
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
/*extern*/ pusError_t pus_tc_220_1_createNewTargetState(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt220_stateID state);
/*extern*/ pusSt220_stateID pus_tc_220_1_getTargetState(const pusPacket_t* inTC);
/*extern*/ pusError_t pus_tc_220_1_setTargetState(pusPacket_t* inTC, pusSt220_stateID state);

/*! Builds a TC[200,2] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCount Sequence counter for this TC
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
/*extern*/ pusError_t pus_tc_200_2_createGetCurrentState(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);

/*! Builds a TM[200,3] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCount Sequence counter for this TC
 *  \param[in] destination Destination for this TM packet
 *  \param[in] state state to be added in data fueld
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
/*extern*/ pusError_t pus_tm_220_3_createActualStatusReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt220_stateID state);
/*extern*/ pusSt220_stateID pus_tm_220_3_getCurrentState(const pusPacket_t* inTC);
/*extern*/ pusError_t pus_tm_220_3_setCurrentState(pusPacket_t* inTC, pusSt220_stateID state);

//! Check that a packet is of a PUS ST[220] TC kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[220]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST220 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
extern pusError_t pus_expectSt220Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);


//! Check that a packet is of a PUS ST[220] TM kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[220]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST220 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
extern pusError_t pus_expectSt220Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);


//! Helper macro for pus_expectSt17; adds function name
#define PUS_EXPECT_ST220TM(packet, subtype) pus_expectSt220Tm((packet), (subtype), __func__)
#define PUS_EXPECT_ST220TC(packet, subtype) pus_expectSt220Tc((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif

#endif
