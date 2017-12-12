/*! \file pus_st09_packets.h
 *  \brief PUS service ST[09] Time management
 *
 *  This module provides the functions to generate the TC and TM of the service ST[09],
 *  as well as getter/setter and checking functions.
 *
 *	Implemented subservices:
 *  - TC[9,1] Set Time Report Rate.
 *	- TC[9,2] Cuc Time Report.
 *
 *  \author GMV
 */


#ifndef PUS_ST08_PACKETS_H
#define PUS_ST08_PACKETS_H

#include "pus_time.h"
#include "pus_types.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_apid.h"

#ifdef  __cplusplus
extern "C" {
#endif

// JSON
// The time report generation rates supported by the spacecraft shall be declared when specifying the time management service
// 	The possible time report generation rates are 1, 2, 4, 8, 16, 32, 64, 128 or 256.
// 	The report generation rate is relative to the generation of telemetry transfer frames on virtual channel 0.
// 	For example, if the report generation rate is 16, then every 16th transfer frame on virtual channel 0 causes the generation of a time report packet.

//TODO P-field ¿?

//TODO pusTime_t  ¿ CCSDS 301.0-B-4

uint64_t pus_time_reportGenerationRate;


//! Build a Set time report rate
/*! Builds a TC[9,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TC
 *  \param[in] apid APID of the process that send the packet
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_9_1_createSetTimeReportRate(pusPacket_t* outTc, pusApidInfo_t* apid, pusSt09ExponentialRate_t expRate);

//! Build a CUC time report
/*! Builds a TM[9,2] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] destination Destination of the packet
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_9_2_createCucTimeReport(pusPacket_t* outTm, pusApidInfo_t* apid);


//! Set the exponential rate to a TC[9,1] packet
pusError_t pus_tc_9_1_setExponentialRate(pusPacket_t* tc, pusSt09ExponentialRate_t expRate);

//! Get the exponential rate from a TC[9,1] packet
pusError_t pus_tc_9_1_getExponentialRate(pusSt09ExponentialRate_t* expRate, pusPacket_t* tc);

// TODO
//! Set the data field of a TM[9,2]
pusError_t pus_tm_9_2_setDataField(pusPacket_t* tm);

//! Getter for the time report generation rate of the service
pusError_t pus_time_getReportGenerationRate(uint64_t * rate);

//! Setter for the time report generation rate of the service
pusError_t pus_time_setRerportGenerationRate(pusSt09ExponentialRate_t expRate);


//! Check that a packet is of a PUS ST[09] TC kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[09]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST09TC to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt09Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);


//! Check that a packet is of a PUS ST[09] TM kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[09]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST09TM to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt09Tm(const pusPacket_t* packet, const char* function);


//! Helper macro for pus_expectSt17; adds function name
#define PUS_EXPECT_ST09TC(packet, subtype) pus_expectSt09Tc((packet), (subtype), __func__)
#define PUS_EXPECT_ST09TM(packet) pus_expectSt09Tm((packet),  __func__)


#ifdef  __cplusplus
}
#endif

#endif
