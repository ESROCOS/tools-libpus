/*! \file pus_st05_packets.h
 *  \brief PUS service ST[05] Event Reporting
 *
 *  This module provides the functions to generate reports of the service ST[05],
 *  as well as getter/setter and checking functions.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 *  - TM[5,1] Informative event report
 *  - TM[5,2] Low severity anomaly report
 *  - TM[5,3] Medium severity anomaly report
 *  - TM[5,4] High severity anomaly report
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_ST05_PACKETS_H
#define PUS_ST05_PACKETS_H


#include "pus_types.h"
#include "pus_error.h"
#include "pus_apid.h"

#ifdef  __cplusplus
extern "C" {
#endif

//! Build the common part of the ST[05] event reports
/*! Builds a TM[5,X] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] event Information about the event which generate the event report
 *  \param[in] destination
 *  \param[in] subtype The TM service subtype to be created
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_5_X_createEventReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt05Event_t* event, pusApid_t destination, pusSubservice_t subtype);

//! Build the common part of the ST[05] reports
/*! Builds a TM[5,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] event Information about the event which generate the event report
 *  \param[in] destination
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_5_1_createInformativeEventReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt05Event_t* event, pusApid_t destination);

//! Build the common part of the ST[05] reports
/*! Builds a TM[5,2] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] event Information about the event which generate the event report
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_5_2_createLowSeverityEventReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt05Event_t* event, pusApid_t destination);

//! Build the common part of the ST[05] reports
/*! Builds a TM[5,3] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] event Information about the event which generate the event report
 *  \param[in] destination
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_5_3_createMediumSeverityEventReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt05Event_t* event, pusApid_t destination);

//! Build the common part of the ST[05] reports
/*! Builds a TM[5,4] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] event Information about the event which generate the event report
 *  \param[in] destination
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_5_4_createHighSeverityEventReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt05Event_t* event, pusApid_t destination);


// get/set Event report data
//! Set packet data field with the event information for a TM(5,X) event report
pusError_t pus_tm_5_X_setTmEventReportData(pusPacket_t* outTm, const pusSt05Event_t* event);

//! Get packet data field with the event information for a TM(5,X) event report
pusError_t pus_tm_5_X_getTmEventReportData(const pusPacket_t* outTm, pusSt05Event_t* event);




//! Check that a packet is of a PUS ST[05] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[05]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST05 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt05Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt01; adds function name
#define PUS_EXPECT_ST05(packet, subtype) pus_expectSt05Tm((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif // PUS_ST05_PACKETS_H
