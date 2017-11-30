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
//#include "pus_housekeeping.h" //TODO params

pusError_t pus_tc_12_X_createDefaultPacket(pusPacket_t* outTc, pusApidInfo_t* apid, pusSubservice_t subtype);

pusError_t pus_tc_12_1_createEnableParameterMonitoringDefinitions(pusPacket_t* outTc, pusApidInfo_t* apid);

pusError_t pus_tc_12_2_createDisableParameterMonitoringDefinitions(pusPacket_t* outTc, pusApidInfo_t* apid);

pusError_t pus_tm_12_12_createCheckTransitionReport(pusPacket_t* outTm, pusApidInfo_t* apid);

pusError_t pus_tc_12_15_createEnableParameterMonitoring(pusPacket_t* outTc, pusApidInfo_t* apid);

pusError_t pus_tc_12_16_createDisableParameterMonitoring(pusPacket_t* outTc, pusApidInfo_t* apid);



#ifdef  __cplusplus
}
#endif

#endif
