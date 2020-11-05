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

#include "pus_enable_services.h"
#include "pus_types.h"
#ifdef PUS_CONFIGURE_ST200_ENABLED

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"

#ifdef  __cplusplus
extern "C" {
#endif
/*! Builds a TC[20,18] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tm_200_18_createPlannerReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_18_Observation observation);
pusSt200_18_Observation pus_tm_200_18_getPlannerObservation(const pusPacket_t* inTM);


/*! Builds a TC[20,19] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tc_200_19_createMissionRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200_19_Goal goal);
pusSt200_19_Goal pus_tc_200_19_getMissionGoal(const pusPacket_t* inTC);
pusError_t pus_tc_200_19_setMissionGoal(pusPacket_t* outTc, pusSt200_19_Goal goal);
/*! Builds a TC[20,20] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tm_200_20_createMissionReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_20_Observation observation);
pusSt200_20_Observation pus_tm_200_20_getMissionObservation(const pusPacket_t* inTM);


/*! Builds a TC[20,13] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tc_200_13_createSodmissionRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200_13_Goal goal);
pusSt200_13_Goal pus_tc_200_13_getSodmissionGoal(const pusPacket_t* inTC);
pusError_t pus_tc_200_13_setSodmissionGoal(pusPacket_t* outTc, pusSt200_13_Goal goal);
/*! Builds a TC[20,14] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tm_200_14_createSodmissionReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_14_Observation observation);
pusSt200_14_Observation pus_tm_200_14_getSodmissionObservation(const pusPacket_t* inTM);


/*! Builds a TC[20,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tc_200_1_createHotdockcmdRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200_1_Goal goal);
pusSt200_1_Goal pus_tc_200_1_getHotdockcmdGoal(const pusPacket_t* inTC);
pusError_t pus_tc_200_1_setHotdockcmdGoal(pusPacket_t* outTc, pusSt200_1_Goal goal);
/*! Builds a TC[20,2] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tm_200_2_createHotdockcmdReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_2_Observation observation);
pusSt200_2_Observation pus_tm_200_2_getHotdockcmdObservation(const pusPacket_t* inTM);


/*! Builds a TC[20,4] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tm_200_4_createHotdockstatusReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_4_Observation observation);
pusSt200_4_Observation pus_tm_200_4_getHotdockstatusObservation(const pusPacket_t* inTM);


/*! Builds a TC[20,5] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tc_200_5_createWmcmdRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200_5_Goal goal);
pusSt200_5_Goal pus_tc_200_5_getWmcmdGoal(const pusPacket_t* inTC);
pusError_t pus_tc_200_5_setWmcmdGoal(pusPacket_t* outTc, pusSt200_5_Goal goal);
/*! Builds a TC[20,6] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tm_200_6_createWmcmdReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_6_Observation observation);
pusSt200_6_Observation pus_tm_200_6_getWmcmdObservation(const pusPacket_t* inTM);


/*! Builds a TC[20,9] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tc_200_9_createBasecmdRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200_9_Goal goal);
pusSt200_9_Goal pus_tc_200_9_getBasecmdGoal(const pusPacket_t* inTC);
pusError_t pus_tc_200_9_setBasecmdGoal(pusPacket_t* outTc, pusSt200_9_Goal goal);
/*! Builds a TC[20,10] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tm_200_10_createBasecmdReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_10_Observation observation);
pusSt200_10_Observation pus_tm_200_10_getBasecmdObservation(const pusPacket_t* inTM);


/*! Builds a TC[20,11] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tc_200_11_createEfcmdRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt200_11_Goal goal);
pusSt200_11_Goal pus_tc_200_11_getEfcmdGoal(const pusPacket_t* inTC);
pusError_t pus_tc_200_11_setEfcmdGoal(pusPacket_t* outTc, pusSt200_11_Goal goal);
/*! Builds a TC[20,12] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tm_200_12_createEfcmdReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_12_Observation observation);
pusSt200_12_Observation pus_tm_200_12_getEfcmdObservation(const pusPacket_t* inTM);


/*! Builds a TC[20,8] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */ 
pusError_t pus_tm_200_8_createWmstatusReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, pusSt200_8_Observation observation);
pusSt200_8_Observation pus_tm_200_8_getWmstatusObservation(const pusPacket_t* inTM);



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
