## Template for generating the PUS ST[03] housekeeping and diagnostic
## service configuration
##
## The template expects the following arguments:
## - config: a dictionary containing the service configuration, read from the JSON file
## - tempvars: an empty dictionary to be used to store global counters within the template 
##             (see http://docs.makotemplates.org/en/latest/runtime.html#context)
<%
# Array lengths
tempvars['numParams'] = len(config)

# Counters for adding to arrays
tempvars['paramsCount'] = -1

# Get the C enum string for a data type identifier
def typeEnum(str):
    if str == 'INT32':
        return 'PUS_ST03_INT32'
    elif str == 'UINT32':
        return 'PUS_ST03_UINT32'
    elif str == 'REAL64':
        return 'PUS_ST03_REAL64'
    elif str == 'BYTE':
        return 'PUS_ST03_BYTE'
    elif str == 'BOOL':
        return 'PUS_ST03_BOOL'
    else:
        raise Exception('Unknown PUS ST[03] parameter data type {}.'.format(str))
%>
##
// PUS service ST[03] configuration
// 
// File automatically generated from the pus_st30_config.h.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_st03_config.h"


// Array with parameter information (length = number of parameters)
pusSt03ParamInfo_t pus_st03_paramInfo[${tempvars['numParams']}];

// Array for parameters values (all stored in 64 bits)
uint64_t pus_st03_params[${tempvars['numParams']}];

// First invalid parameter ID
const pusSt03ParamId_t pus_ST03_PARAM_LIMIT = PUS_ST03_PARAM_LIMIT;

pusError_t pus_st03_configure()
{
% for param in config['parameters']:
<%
    tempvars['paramsCount'] = tempvars['paramsCount'] + 1
%>
    pus_st03_paramInfo[${tempvars['paramsCount']}].label = "${param['label']}";
    pus_st03_paramInfo[${tempvars['paramsCount']}].type = ${typeEnum(param['type'])};
% endfor
    
    return PUS_NO_ERROR;
}

#endif // PUS_ST03_CONFIG_H
