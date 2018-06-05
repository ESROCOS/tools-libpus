/*! \file pus_st20_packets.h
 *  \brief PUS service ST[20] On-board parameters management.
 *
 *  This module contains the functions to manage the on-board parameters management
 *  database
 *
 *  Only a subset of the standard requests and reports are implemented.
 *  - TC[20,1] Report Parameter Values (request)
 *  - TM[20,2] Report Parameter Values
 *  - TC[20,3] Set Parameter Values
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_ST20_PACKETS_H
#define PUS_ST20_PACKETS_H

#include "pus_types.h"
#ifdef PUS_CONFIGURE_ST20_ENABLED

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_threads.h"

#include "pus_parameter_management.h"

#include "pus_packet.h"
#include <string.h>

#ifdef  __cplusplus
extern "C" {
#endif



/*! Builds a TC[20,1] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] param On-board parameter identifier
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_20_1_createParameterValueRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt20OnBoardParamId_t param);

/*! Builds a TM[20,2] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] destination Destination of the TM report
 *  \param[in] param On-board parameter identifier
 *  \param[in] value Value of the on-board parameter
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_20_2_createParameterValueReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt20OnBoardParamId_t param, pusStoredParam_t value);

/*! Builds a TC[20,3] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] param On-board parameter identifier
 *  \param[in] value Value of the on-board parameter
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_20_3_createSetParameterValueRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt20OnBoardParamId_t param, pusStoredParam_t value);

//! Set on-board paramId into a TC[20,1] or TC[20,3] packet
pusError_t pus_tc_20_X_setParamId(pusPacket_t* outTc, pusSt20OnBoardParamId_t param);

//! Get on-board paramId from a TC[20,1] or TC[20,3] packet
pusSt20OnBoardParamId_t pus_tc_20_X_getParamId(const pusPacket_t* outTc);

//! Set on-board param value into a TC[20,3] packet
pusError_t pus_tc_20_3_setParamValue(pusPacket_t* outTc, pusStoredParam_t value);

//! Get on-board param value from a TC[20,3] packet
pusStoredParam_t pus_tc_20_3_getParamValue(const pusPacket_t* outTc);

//! Set on-board paramId into a TM[20,2]
pusError_t pus_tm_20_2_setParamId(pusPacket_t* outTc, pusSt20OnBoardParamId_t param);

//! Get on-board paramId from a TM[20,2]
pusSt20OnBoardParamId_t pus_tm_20_2_getParamId(const pusPacket_t* outTc);

//! Set on-board param value into a TM[20,2]
pusError_t pus_tm_20_2_setParamValue(pusPacket_t* outTc, pusStoredParam_t value);

//! Get on-board param value from a TM[20,2]
pusStoredParam_t pus_tm_20_2_getParamValue(const pusPacket_t* outTc);


//
// Parameter checking
//

//! Check that a packet is of a PUS ST[20] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[03]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST20 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt20Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Check that a packet is of a PUS ST[03] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[03]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST03 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt20Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt20Tc; adds function name
#define PUS_EXPECT_ST20TC(packet, subtype) pus_expectSt20Tc((packet), (subtype), __func__)

//! Helper macro for pus_expectSt20Tm; adds function name
#define PUS_EXPECT_ST20TM(packet, subtype) pus_expectSt20Tm((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif

#endif // PUS_ST20_PACKETS_H

