//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS Packet Queues configuration
// 
// File automatically generated from the pus_st08_config.h.mako template
//
//                     -- DO NOT MODIFY --


#ifndef PUS_ST08_CONFIG_H
#define PUS_ST08_CONFIG_H


#include "pus_types.h"
#ifdef PUS_CONFIGURE_ST08_ENABLED

#include "pus_error.h"
#include "pus_st08_packets.h"

#ifdef __cplusplus
extern "C" {
#endif


<% count = 0 %>
% for function in config['functions']:
#define ${function['label']} ((pusSt08FunctiontId_t) ${count}) \
<% count = count + 1 %>
% endfor
#define PUS_ST08_LIMITFUNCTIONS ${count}

extern const size_t pus_st08_limitFunctions;

extern pusError_t (*pus_st08_functionTable[])();
 
extern pusError_t pus_st08_configure(); 

extern pusSt08FunctionInfo_t pus_st08_functionInfoList[];
 
 
#ifdef __cplusplus
}
#endif

#endif
 
 #endif