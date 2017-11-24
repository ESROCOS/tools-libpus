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
 *  \author GMV
 */

#ifndef PUS_ST05_PACKETS_H
#define PUS_ST05_PACKETS_H


#include "pus_types.h"
#include "pus_error.h"
#include "pus_apid.h"

// Declarar lista de eventos



//! Build the common part of the ST[05] event reports
/*! Builds a TM[5,X] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] event Information about the event which generate the event report
 *  \param[in] destination
 *  \param[in] subtype The TM service subtype to be created
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_5_X_createEventReport(pusPacket_t* outTm, pusApidInfo_t* apid, const pusSt05Event_t* event, pusApid_t destination, pusSubservice_t subtype);

//! Build the common part of the ST[05] reports
/*! Builds a TM[5,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] event Information about the event which generate the event report
 *  \param[in] destination
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_5_1_createInformativeEventReport(pusPacket_t* outTm, pusApidInfo_t* apid, const pusSt05Event_t* event, pusApid_t destination);

//! Build the common part of the ST[05] reports
/*! Builds a TM[5,2] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] event Information about the event which generate the event report
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_5_2_createLowSeverityEventReport(pusPacket_t* outTm, pusApidInfo_t* apid, const pusSt05Event_t* event, pusApid_t destination);

//! Build the common part of the ST[05] reports
/*! Builds a TM[5,3] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] event Information about the event which generate the event report
 *  \param[in] destination
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_5_3_createMediumSeverityEventReport(pusPacket_t* outTm, pusApidInfo_t* apid, const pusSt05Event_t* event, pusApid_t destination);

//! Build the common part of the ST[05] reports
/*! Builds a TM[5,4] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] event Information about the event which generate the event report
 *  \param[in] destination
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_5_4_createHighSeverityEventReport(pusPacket_t* outTm, pusApidInfo_t* apid, const pusSt05Event_t* event, pusApid_t destination);


// get/set Event report data
//! Set packet data field with the event information for a TM(5,X) event report
pusError_t pus_tm_5_X_setTmEventReportData(pusPacket_t* outTm, const pusSt05Event_t* event);

//! Get packet data field with the event information for a TM(5,X) event report
pusError_t pus_tm_5_X_getTmEventReportData(const pusPacket_t* outTm, pusSt05Event_t* event);

// Getters/Setters pusSt05Event_t
//! Getter for eventId in event structure
pusSt05EventId_t pus_tm_5_X_getEventId(const pusSt05Event_t* event);

//! Setter for eventId in event structure
void pus_tm_5_X_setEventId(pusSt05Event_t* event, pusSt05EventId_t eventId);

//! Getter for data in event structure
pusSt05EventAuxData_t pus_tm_5_X_getEventAuxData(const pusSt05Event_t* event);

//! Setter for data in event structure
void pus_tm_5_X_setEventAuxData(pusSt05Event_t* event, pusSt05EventAuxData_t data);

//! Getter for data1 in data structure
pusStoredParam_t pus_tm_5_X_getEventAuxData1(const pusSt05EventAuxData_t* data);

//! Setter for data1 in data structure
void pus_tm_5_X_setEventAuxData1(pusSt05EventAuxData_t* data, pusStoredParam_t data1);

//! Getter for data2 in data structure
pusStoredParam_t pus_tm_5_X_getEventAuxData2(const pusSt05EventAuxData_t* data);

//! setter for data2 in data structure
void pus_tm_5_X_setEventAuxData2(pusSt05EventAuxData_t* data, pusStoredParam_t data2);


//! Check that a packet is of a PUS ST[05] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[05]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST05 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt05Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt01; adds function name
#define PUS_EXPECT_ST05(packet, subtype) pus_expectSt05Tm((packet), (subtype), __func__)


#endif // PUS_ST05_PACKETS_H
