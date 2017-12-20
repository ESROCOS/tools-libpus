/*! \file pus_st12_packets.h
 *  \brief PUS service ST[11] time-based scheduling
 *
 *  This module provides the functions to generate packets of the service ST[11],
 *  as well as getter/setter and checking functions.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 *  - TC[11,1] enable the time-based schedule execution function
 *  - TM[11,2] disable the time-based schedule execution function
 *  - TC[11,3] reset the time-based schedule
 *  - TM[11,4] insert activities into the time-based schedule
 *  \author GMV
 */

#ifndef PUS_ST11_PACKETS_H
#define PUS_ST11_PACKETS_H

#ifdef  __cplusplus
extern "C" {
#endif

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_threads.h"
#include "pus_types.h"
#include "pus_packet.h"



/*
 * JSON:
 *  - Maximun number of definitions:
 *  - Time marging:  release > now+marging
 *  - Maximun delta between release and real release
 *
 *
 * Scheduled activity definition STRUCT*
 *  - request (TC)
 *  - release time
 *  - if sub-schedule: ID
 *  - if groups: ID
 *  - (flag deleted ?¿)
 *
 * FLAG: time-based schedule execution function status (general) TC[11.1] TC[11.2]
 * 		 default false! // accepted/rejected if enable or disable before
 *
 * TC[11.3] reset schedule
 *   - flag_function to false
 *   - delete all scheduled activities
 *   - if sub-schedules: delete all
 *   - if groups: enable all
 *
 * TC[11,4]
 *   - N instruction
 *   - reject if maximun reached
 *	 - accept:
 *	 	- create scheduled
 *
 *
 * */


//! Build the common part of the ST[11] TC packets
/*! Builds a TC[11,X] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 *  \param[in] subtype The TM service subtype to be created
 */
pusError_t pus_tc_11_X_createDefaultPacket(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSubservice_t subtype);


//! Build a TC to enable the time-based schedule function
/*! Builds a TC[11,1] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_11_1_createEnableTimeBasedSchedule(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);


//! Build a TC to disable the time-based schedule function
/*! Builds a TC[11,2] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_11_2_createDisableTimeBasedSchedule(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);


//! Build a TC to reset the time-based schedule
/*! Builds a TC[11,3] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_11_3_createResetTimeBasedSchedule(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);


//! Build a TC to insert activities into the time-based schedule
/*! Builds a TC[11,4] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_11_4_createInsertActivityIntoSchedule(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, uint32_t nCount, const pusSt11ScheduledActivity_t* activities);


//! Check that a packet is of a PUS ST[11] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TC types in ST[11]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST11 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt11Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt12; adds function name
#define PUS_EXPECT_ST11TC(packet, subtype) pus_expectSt11Tc((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif
