/*! \file pus_st12_packets.h
 *  \brief PUS service ST[12] On-board Monitoring
 *
 *  This module provides the functions to generate packets of the service ST[12],
 *  as well as getter/setter and checking functions.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 *  - TC[12,1] enable Parameter Monitoring Definitions
 *  - TM[12,2] disable Parameter Monitoring Definitions
 *  - TM[12,12] check Transition Report
 *  - TC[12,15] enable Parameter Monitoring
 *  - TM[12,16] disable Parameter Monitoring
 *  \author GMV
 */

#ifndef PUS_ST12_PACKETS_H
#define PUS_ST12_PACKETS_H

#ifdef  __cplusplus
extern "C" {
#endif

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_threads.h"
#include "pus_types.h"
#include "pus_packet.h"



pusError_t pus_tc_12_X_createDefaultPacket(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSubservice_t subtype);

pusError_t pus_tc_12_1_createEnableParameterMonitoringDefinitions(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt12PmonId_t pmon);

pusError_t pus_tc_12_2_createDisableParameterMonitoringDefinitions(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt12PmonId_t pmon);

//pusError_t pus_tm_12_12_createCheckTransitionReport(pusPacket_t* outTm, pusApidInfo_t* apid);

pusError_t pus_tc_12_15_createEnableParameterMonitoring(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);

pusError_t pus_tc_12_16_createDisableParameterMonitoring(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);

//! Set pmonId to the data field of TC[12,1] and TC[17,2]
pusError_t pus_tc_12_1_2_setPmonId(pusPacket_t* outTc, pusSt12PmonId_t pmon);

//! Get pmonId from the data field of TC[12,1] and TC[17,2]
pusError_t pus_tc_12_1_2_getPmonId(pusSt12PmonId_t* pmon, pusPacket_t* tcPacket);


//! Check that a packet is of a PUS ST[12] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TC types in ST[12]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST12 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt12Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt12; adds function name
#define PUS_EXPECT_ST12TC(packet, subtype) pus_expectSt12Tc((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif
