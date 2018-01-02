## Template for generating the PUS ST[03] housekeeping and diagnostic
## service configuration
##
## The template expects the following arguments:
## - config: a dictionary containing the service configuration, read from the JSON file
## - tempvars: an empty dictionary to be used to store global counters within the template 
##             (see http://docs.makotemplates.org/en/latest/runtime.html#context)
##
// PUS service ST[20] configuration
// 
// File automatically generated from the pus_st20_config.h.mako template
//
//                     -- DO NOT MODIFY --

#ifndef PUS_ST20_CONFIG_H
#define PUS_ST20_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif


#include "pus_error.h"
#include "pus_types.h"
#include "pus_parameter_management.h"


// Parameter identifiers
<% count = 0 %>
% for param in config['parameters']:
#define ${param['label']} ((pusSt20OnBoardParamId_t) ${count}) \
<% count = count + 1 %>
% endfor
#define PUS_ST20_PARAM_LIMIT ((pusSt20OnBoardParamId_t) ${count})


//! Array with parameter information (length = number of parameters)
extern pusSt20ParamInfo_t pus_st20_paramInfo[];

//! Array for parameters values (all stored in 64 bits)
extern pusStoredParam_t pus_st20_params[];

//! ST[20]on board parameters limit
extern const pusSt20OnBoardParamId_t pus_ST20_PARAM_LIMIT;

//! Initialize the configuration of the ST[20] service from the mission database
pusError_t pus_parameteres_configure();


/*
//Param types
typedef int32_t INT32;
typedef uint32_t UINT32;
typedef double REAL64;
typedef uint8_t BYTE;
typedef bool BOOL;

//Param getters/setters
% for param in config['parameters']:
pusError_t pus_parameters_set${param['label']}(${param['type']} value);
pusError_t pus_parameters_get${param['label']}(${param['type']}* value);

% endfor
*/

#ifdef __cplusplus
}
#endif


#endif // PUS_ST03_CONFIG_H
