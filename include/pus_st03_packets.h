/*! \file pus_st03_packets.h
 *  \brief PUS service ST[03] Housekeeping.
 *
 *  This module provides the functions to generate packets of the service ST[03],
 *  as well as getter/setter and checking functions.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 *  - Housekeeping
 *    + TM[3,25] Housekeeping parameter report
 *
 *  \author GMV
 */

#ifndef PUS_ST03_PACKETS_H
#define PUS_ST03_PACKETS_H

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_housekeeping.h"
#include "pus_threads.h"
#include "pus_types.h"

#ifdef  __cplusplus
extern "C" {
#endif

//
// Report creation
//

//! Build the default housekeeping parameter report
/*! Builds a TM[3_25] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_3_25_createHousekeepingReportDefault(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination);

//! Build a housekeeping parameter report
/*! Builds a TM[3,25 packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] count TM sequence counter for the source APID
 *  \param[in] reportId The report ID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_3_25_createHousekeepingReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt03HousekeepingReportId_t reportId, pusApid_t destination);


//
// Getters and setters for report fields
//

//! Getter for the TM[3,25] report ID field
pusSt03HousekeepingReportId_t pus_tm_3_25_getReportId(const pusPacket_t* tm);

//! Setter for the TM[3,25] report ID field
void pus_tm_3_25_setReportId(pusPacket_t* outTm, pusSt03HousekeepingReportId_t reportId);

//! Copy the values of a list of parameters into an output array
/*! \param[out] outTm TM packet to fill the parameter values
 *  \param[in] paramIds Array of the parameter IDs whose values will be included in the report
 *  \param[in] numParams Length of the paramIds array; must be at most \ref pus_ST03_MAX_REPORT_LENGTH
 */
pusError_t pus_tm_3_25_setParameterValues(pusPacket_t* outTm, pusSt03HousekeepingReportId_t reportId);

//! Set the value of one parameter in the report (to be casted to the correct type)
/*! \param[out] tm The TM packet
 *  \param[in] index The index of the parameter to be returned; must be at most \ref pus_ST03_MAX_REPORT_LENGTH
 *  \param[in] inValue Input parameter value as \ref pusStoredParam_t, to be casted to the correct type
 */
pusError_t pus_tm_3_25_setParameterValue(pusPacket_t* tm, size_t index, pusStoredParam_t inValue);


//! Get the value of one parameter in the report (to be casted to the correct type)
/*! \param[in] tm The TM packet
 *  \param[in] index The index of the parameter to be returned; must be at most \ref pus_ST03_MAX_REPORT_LENGTH
 *  \param[out] outValue Outputs the parameter value as \ref pusInternalParam_t, to be casted to the correct type
 */
pusError_t pus_tm_3_25_getParameterValue(const pusPacket_t* tm, size_t index, pusStoredParam_t* outValue);

//! Get the number of parameters in the report
/*! \param[in] tm The TM packet
 *  \param[out] outNumParams Outputs the number of parameters
 */
pusError_t pus_tm_3_25_getNumParameters(const pusPacket_t* tm, size_t* outNumParams);

//! Set the number of parameters in the report
/*! \param[out] tm The TM packet
 *  \param[in] inNumParams Input for the number of parameters
 */
pusError_t pus_tm_3_25_setNumParameters(pusPacket_t* tm, size_t outNumParams);

//
// Parameter checking
//

//! Check that a packet is of a PUS ST[03] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[03]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST03 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt03Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt03; adds function name
#define PUS_EXPECT_ST03(packet, subtype) pus_expectSt03Tm((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif // PUS_ST03_PACKETS_H
