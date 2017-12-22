## Template for generating the PUS ST[20] housekeeping and diagnostic
## service configuration
##
## The template expects the following arguments:
## - config: a dictionary containing the service configuration, read from the JSON file
## - tempvars: an empty dictionary to be used to store global counters within the template 
##             (see http://docs.makotemplates.org/en/latest/runtime.html#context)
<%
# Array lengths
tempvars['numParams'] = len(config['parameters'])
%>

// PUS service ST[20] configuration
// 
// File automatically generated from the pus_st20_config.h.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_st20_config.h"

// ST[20] arrays
pusSt20ParamInfo_t pus_st20_paramInfo[${tempvars['numParams']}];
pusStoredParam_t pus_st20_params[${tempvars['numParams']}];


// ST[20] constants
const pusSt20OnBoardParamId_t pus_ST03_PARAM_LIMIT = PUS_ST20_PARAM_LIMIT;


pusError_t pus_parameters_configure()
{
	// Store parameters info
% for param in config['parameters']:
    pus_st20_paramInfo[${param['label']}].label = "${param['label']}";
    pus_st20_paramInfo[${param['label']}].type = PUS_${param['type']};
% endfor

    return PUS_NO_ERROR;
}

/*
% for param in config['parameters']:
pusError_t pus_hk_set${param['label']}(${param['type']} value)
{
	%if str(param['type']) == str("INT32"):
	return pus_hk_setInt32Param(${param['label']}, value);
	%elif str(param['type']) == str("UINT32"):
	return pus_hk_setUInt32Param(${param['label']}, value);
	%elif str(param['type']) == str("REAL64"):
	return pus_hk_setReal64Param(${param['label']}, value);
	%elif str(param['type']) == str("BYTE"):
	return pus_hk_setByteParam(${param['label']}, value);
	%elif str(param['type']) == str("BOOL"):
	return pus_hk_setBoolParam(${param['label']}, value);
	%else:
	return PUS_ERROR_NOT_IMPLEMENTED;
	%endif
}

pusError_t pus_hk_get${param['label']}(${param['type']}* value)
{
	%if str(param['type']) == str("INT32"):
	return pus_hk_getInt32Param(${param['label']}, value);
	%elif str(param['type']) == str("UINT32"):
	return pus_hk_getUInt32Param(${param['label']}, value);
	%elif str(param['type']) == str("REAL64"):
	return pus_hk_getReal64Param(${param['label']}, value);
	%elif str(param['type']) == str("BYTE"):
	return pus_hk_getByteParam(${param['label']}, value);
	%elif str(param['type']) == str("BOOL"):
	return pus_hk_getBoolParam(${param['label']}, value);
	%else:
	return PUS_ERROR_NOT_IMPLEMENTED;
	%endif
}

% endfor

*/

