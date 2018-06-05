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


#ifndef PUS_ST17_PACKETS_H
#define PUS_ST17_PACKETS_H

#include "pus_types.h"
#ifdef PUS_CONFIGURE_ST17_ENABLED

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*! Builds a TC[17,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_17_1_createConnectionTestRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);

/*! Builds a TM[17,2] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_17_2_createConnectionTestReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination);

/*! Calla a function that builds a TM[17,2] packet in the packet passed as parameter with the TC information.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] inTc TC packet to get the destination of the response
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_st17_createTestResponse(pusPacket_t* outTm, pusApidInfo_t* apid, const pusPacket_t* inTc);


//! Check that a packet is of a PUS ST[17] TC kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[17]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST17 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt17Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);


//! Check that a packet is of a PUS ST[17] TM kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[05]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST17 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt17Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);


//! Helper macro for pus_expectSt17; adds function name
#define PUS_EXPECT_ST17TM(packet, subtype) pus_expectSt17Tm((packet), (subtype), __func__)
#define PUS_EXPECT_ST17TC(packet, subtype) pus_expectSt17Tc((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif

#endif
