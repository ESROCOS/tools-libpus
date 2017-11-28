// PUS Packet Queues configuration
// 
// File automatically generated from the pus_st08_config.h.mako template
//
//                     -- DO NOT MODIFY --

#ifndef PUS_ST08_CONFIG_H
#define PUS_ST08_CONFIG_H

#include "pus_error.h"
#include "pus_types.h"

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
 
 
#ifdef __cplusplus
}
#endif

 
 #endif