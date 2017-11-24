/*! \file pus_st08_packets.h
 *  \brief PUS service ST[08] Function management
 *
 *  This module provides the functions to generate the TC of the service ST[08],
 *  as well as getter/setter and checking functions.
 *
 *	Implemented subservices:
 *  - TC[8,1] Perform a function.
 *
 *  \author GMV
 */


#ifndef PUS_ST08_PACKETS_H
#define PUS_ST08_PACKETS_H


#include "pus_types.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_apid.h"


extern pusError_t pus_st08_configure();

pusError_t pus_tc_8_2_createPerformFuctionRequest(pusPacket_t* outTc, pusApidInfo_t* apid/*, pusApid_t destination*/, pusSt08FunctiontId_t functionId);

void pus_tc_8_2_setFunctionId(pusPacket_t* outTc, pusSt08FunctiontId_t functionId);

bool pus_st08_inInFunctionTable(pusSt08FunctiontId_t functionId);



pusError_t pus_expectSt08(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);
#define PUS_EXPECT_ST08(packet, subtype) pus_expectSt08((packet), (subtype), __func__)



#endif
