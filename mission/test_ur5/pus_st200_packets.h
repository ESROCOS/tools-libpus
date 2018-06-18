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


#ifndef PUS_ST200_PACKETS_H
#define PUS_ST200_PACKETS_H

#include "pus_types.h"
#ifdef PUS_CONFIGURE_ST200_ENABLED

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*! Builds a TC[20,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_200_1_createControlCameraRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200ControlId operation);

/*! Builds a TM[20,2] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_200_2_createControlCameraReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200Observation observation);

//! Setter for the controlId of a TC[200,1] packet
pusError_t pus_tc_200_1_setControlId(pusPacket_t* outTc, pusSt200ControlId operation);

//! Getter for the controlId of a TC[200,1] packet
pusSt200ControlId pus_tc_200_1_getControlId(const pusPacket_t* inTc);

//! Setter for the observation of a TM[200,2] packet
pusError_t pus_tm_200_2_setObservation(pusPacket_t* outTm, pusSt200Observation observation);

//! Getter for the observation of a TM[200,2] packet
pusSt200Observation pus_tm_200_2_getObservation(const pusPacket_t* inTM);


//! Check that a packet is of a PUS ST[20] TC kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[20]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST17 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt200Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);


//! Check that a packet is of a PUS ST[20] TM kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[20]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST17 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt200Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);


//! Helper macro for pus_expectSt17; adds function name
#define PUS_EXPECT_ST200TM(packet, subtype) pus_expectSt200Tm((packet), (subtype), __func__)
#define PUS_EXPECT_ST200TC(packet, subtype) pus_expectSt200Tc((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif

#endif
