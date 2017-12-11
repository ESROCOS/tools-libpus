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

//TODO P-field

//TODO pusTime_t  ¿ CCSDS 301.0-B-4

uint64_t time_report_generation_rate;



pusError_t pus_tc_9_1_createSetTimeReportRate(pusPacket_t* outTc, pusApidInfo_t* apid);

pusError_t pus_tm_9_2_createCucTimeReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusApid_t destination);

pusError_t pus_time_getReportGenerationRate(uint64_t * rate);

pusError_t pus_time_setRerportGenerationRate(pusSt09ExponentialRate_t expRate);



#ifdef  __cplusplus
}
#endif

#endif
