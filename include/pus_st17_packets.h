/*! \file pus_st17_packets.h
 *  \brief PUS service ST[15] Test Connection
 *
 *  This module provides the functions to generate reports of the service ST[17],
 *  as well as getter/setter and checking functions.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 *  - TC[17,1] Perform an are-you-alive connection test
 *  - TM[17,2] Are-you-alive connection test report
 *
 *  \author GMV
 */


#ifndef PUS_ST17_PACKETS_H
#define PUS_ST17_PACKETS_H


#include "pus_apid.h"
#include "pus_error.h"
#include "pus_threads.h"
#include "pus_types.h"


pusError_t pus_tm_17_2_ConnectionTestReport(pusPacket_t* outTm, pusApidInfo_t* apid, pusApid_t destination);





#endif
