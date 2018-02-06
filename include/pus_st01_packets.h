/*! \file pus_st01_packets.h
 *  \brief PUS service ST[01] Request Verification.
 *
 *  This module provides the functions to generate reports of the service ST[01],
 *  as well as getter/setter and checking functions.
 *
 *  All standard reports are implemented except for:
 *  - TM[1,10] Failed routing verification report
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_ST01_PACKETS_H
#define PUS_ST01_PACKETS_H

#include "pus_types.h"
#include "pus_error.h"
#include "pus_apid.h"


#ifdef  __cplusplus
extern "C" {
#endif
//
// Creation of TC acceptance report
//

//! Build the common part of the ST[01] reports
/*! Builds a TM[1,X] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \param[in] receivedTc The TC acknowledged in the report
 *  \param[in] subtype The TM service subtype to be created
 */
pusError_t pus_tm_1_X_createReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusPacket_t* receivedTc, pusSubservice_t subtype);

//! Build an acceptance report for a TC
/*! Builds a TM[1,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \param[in] receivedTc The TC acknowledged in the report
 */
pusError_t pus_tm_1_1_createAcceptanceReportSuccess(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusPacket_t* receivedTc);

//! Build an acceptance report for a TC
/*! Builds a TM[1,2] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \param[in] receivedTc The TC acknowledged in the report
 *  \param[in] code Failure code
 *  \param[in] info Failure info; pass NULL to leave default
 */
pusError_t pus_tm_1_2_createAcceptanceReportFailure(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusPacket_t* receivedTc,
		pusSt01FailureCode_t code, const pusSt01FailureInfo_t* info);

//! Build an acceptance report for a TC
/*! Builds a TM[1,3] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \param[in] receivedTc The TC acknowledged in the report
 */
pusError_t pus_tm_1_3_createStartReportSuccess(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusPacket_t* receivedTc);

//! Build an acceptance report for a TC
/*! Builds a TM[1,4] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \param[in] receivedTc The TC acknowledged in the report
 *  \param[in] code Failure code
 *  \param[in] info Failure info; pass NULL to leave default
 */
pusError_t pus_tm_1_4_createStartReportFailure(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusPacket_t* receivedTc,
		pusSt01FailureCode_t code, const pusSt01FailureInfo_t* info);

//! Build an acceptance report for a TC
/*! Builds a TM[1,5] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \param[in] receivedTc The TC acknowledged in the report
 *  \param[in] step The procedure step
 */
pusError_t pus_tm_1_5_createProgressReportSuccess(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusPacket_t* receivedTc, pusStepId_t step);

//! Build an acceptance report for a TC
/*! Builds a TM[1,6] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \param[in] receivedTc The TC acknowledged in the report
 *  \param[in] step The procedure step
 *  \param[in] code Failure code
 *  \param[in] info Failure info; pass NULL to leave default
 */
pusError_t pus_tm_1_6_createProgressReportFailure(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusPacket_t* receivedTc,
		pusStepId_t step, pusSt01FailureCode_t code, const pusSt01FailureInfo_t* info);

//! Build an acceptance report for a TC
/*! Builds a TM[1,7] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \param[in] receivedTc The TC acknowledged in the report
 */
pusError_t pus_tm_1_7_createCompletionReportSuccess(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusPacket_t* receivedTc);

//! Build an acceptance report for a TC
/*! Builds a TM[1,8] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \param[in] receivedTc The TC acknowledged in the report
 *  \param[in] code Failure code
 *  \param[in] info Failure info; pass NULL to leave default
 */
pusError_t pus_tm_1_8_createCompletionReportFailure(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusPacket_t* receivedTc,
		pusSt01FailureCode_t code, const pusSt01FailureInfo_t* info);


pusError_t pus_st01_pushTmAceptanceReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error);
pusError_t pus_st01_pushTmStartReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error);
pusError_t pus_st01_pushTmProgressReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error, pusStepId_t step);
pusError_t pus_st01_pushTmCompletionReportIfNeeded(pusPacket_t* tcRead, pusApidInfo_t* apid, bool isCorrect, pusError_t error);


//
// Report field (of the verified TC) getters and setters
//

//! Set the packet version number field (of the verified TC) for a TM(1,X) report
void pus_tm_1_X_setPacketVersionNumber(pusPacket_t* tm, pusPacketVersion_t version);

//! Get the packet version number field (of the verified TC) for a TM(1,X) report
pusPacketVersion_t pus_tm_1_X_getPacketVersionNumber(pusPacket_t* tm);

//! Set the packet type field (of the verified TC) for a TM(1,X) report
void pus_tm_1_X_setPacketType(pusPacket_t* tm, pusPacketType_t type);

//! Get the packet type field (of the verified TC) for a TM(1,X) report
pusPacketType_t pus_tm_1_X_getPacketType(pusPacket_t* tm);

//! Set the secondary header field (of the verified TC) for a TM(1,X) report
void pus_tm_1_X_setSecondaryHeaderFlag(pusPacket_t* tm, bool flag);

//! Get the secondary header field (of the verified TC) for a TM(1,X) report
bool pus_tm_1_X_getSecondaryHeaderFlag(pusPacket_t* tm);

//! Set the APID field (of the verified TC) for a TM(1,X) report
void pus_tm_1_X_setApid(pusPacket_t* tm, pusApid_t apid);

//! Get the APID field (of the verified TC) for a TM(1,X) report
pusApid_t pus_tm_1_X_getApid(pusPacket_t* tm);

//! Set the packet sequence flags field (of the verified TC) for a TM(1,X) report
void pus_tm_1_X_setSequenceFlags(pusPacket_t* tm, pusSequenceFlags_t flags);

//! Get the packet sequence flags field (of the verified TC) for a TM(1,X) report
pusSequenceFlags_t pus_tm_1_X_getSequenceFlags(pusPacket_t* tm);

//! Set the packet sequence count field (of the verified TC) for a TM(1,X) report
void pus_tm_1_X_setSequenceCount(pusPacket_t* tm, pusSequenceCount_t count);

//! Get the packet sequence count field (of the verified TC) for a TM(1,X) report
pusSequenceCount_t pus_tm_1_X_getSequenceCount(pusPacket_t* tm);

//! Set the step field for a TM(1,X) report
void pus_tm_1_X_setStep(pusPacket_t* tm, pusStepId_t step);

//! Get the step field for a TM(1,X) report
pusStepId_t pus_tm_1_X_getStep(pusPacket_t* tm);

//! Initialize the failure data structure in a ST[01] TM packet
void pus_tm_1_X_initFailureInfo(pusPacket_t* tm);

//! Get the failure information in a ST[01] TM packet
/*! \param[in] tm The ST[01] TM packet
 *  \param[inout] info The failure info; if NULL, the info field is not returned
 *  \return The failure code
 */
pusSt01FailureCode_t pus_tm_1_X_getFailureInfo(const pusPacket_t* tm, pusSt01FailureInfo_t* outInfo);

//! Set the failure information in a ST[01] TM packet
/*! \param[in] tm The ST[01] TM packet
 *  \param[in] code The failure code
 *  \param[in] info The failure info; if NULL, the info field is not filled
 */
void pus_tm_1_X_setFailureInfo(pusPacket_t* tm, pusSt01FailureCode_t code, const pusSt01FailureInfo_t* info);


//
// Management of failure values
//

//! Default values for failure info
void pus_initSt01FailureInfo(pusSt01FailureInfo_t* info);

//! Set failure information
void pus_setSt01FailureInfo(pusSt01FailureInfo_t* info, pusInt32_t subcode, pusInt32_t data, pusMemAddr_t address);

//! Get failure information: subcode
pusInt32_t pus_getSt01FailureSubcode(const pusSt01FailureInfo_t* info);

//! Get failure information: data
pusInt32_t pus_getSt01FailureData(const pusSt01FailureInfo_t* info);

//! Get failure information: address
pusMemAddr_t pus_getSt01FailureAddress(const pusSt01FailureInfo_t* info);


//
// Parameter checking
//

//! Check that a packet is of a PUS ST[01] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[01]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST01 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt01Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt01; adds function name
#define PUS_EXPECT_ST01(packet, subtype) pus_expectSt01Tm((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif // PUS_ST01_PACKETS_H
