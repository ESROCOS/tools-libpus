## Template for generating the PUS ST[03] housekeeping and diagnostic
## service configuration
##
## The template expects the following arguments:
## - config: a dictionary containing the service configuration, read from the JSON file
## - tempvars: an empty dictionary to be used to store global counters within the template 
##             (see http://docs.makotemplates.org/en/latest/runtime.html#context)
<%
# Array lengths
tempvars['numParams'] = len(config['parameters'])

# Counters for adding to arrays
tempvars['paramsCount'] = -1
tempvars['defaultReportCount'] = -1

# Indices assigned to the parameters
tempvars['paramIndex'] = dict()

%>

// PUS service ST[03] configuration
// 
// File automatically generated from the pus_st30_config.h.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_st03_config.h"
#include <string.h> //memcpy

// ST[03] arrays
pusSt03ParamInfo_t pus_st03_paramInfo[${tempvars['numParams']}];
pusStoredParam_t pus_st03_params[${tempvars['numParams']}];
pusSt03ParamId_t pus_st03_defaultHkReport[${len(config['defaultHkReport'])}];
pusSt03ReportInfo_t pus_st03_defaultHkReportInfo;

// ST[03] constants
const pusSt03ParamId_t pus_ST03_PARAM_LIMIT = PUS_ST03_PARAM_LIMIT;


pusError_t pus_hk_configure()
{
	pus_st03_defaultHkReportInfo.numParams = 0;
	pus_st03_defaultHkReportInfo.paramIds = &pus_st03_defaultHkReport[0];

	// Store parameters info
% for param in config['parameters']:
<%
    tempvars['paramsCount'] = tempvars['paramsCount'] + 1
    tempvars['paramIndex'][param['label']] = tempvars['paramsCount']
%>
    pus_st03_paramInfo[${param['label']}].label = "${param['label']}";
    pus_st03_paramInfo[${param['label']}].type = PUS_${param['type']};
% endfor

	// Default HK report
% for id in config['defaultHkReport']:
% if id in tempvars['paramIndex']:
<%
    tempvars['defaultReportCount'] = tempvars['defaultReportCount'] + 1
%>\
    pus_st03_defaultHkReport[${tempvars['defaultReportCount']}] = ${tempvars['paramIndex'][id]}; 
% else:
<% 
    raise Exception('ST[03] configuration: unknown parameter ID {} in defaultHKReport'.format(id)) 
%>
% endif
% endfor
% if tempvars['defaultReportCount'] >= 0:
	pus_st03_defaultHkReportInfo.numParams = ${tempvars['defaultReportCount'] + 1};
% else:
<% 
    raise Exception('ST[03] configuration: defaultHKReport is empty') 
%>
% endif  

    return PUS_NO_ERROR;
}

//TODO void/type or error

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
	
	return PUS_NO_ERROR;
}

pusError_t pus_hk_get${param['label']}(${param['type']}* value)
{
	%if str(param['type']) == str("INT32"):
	return pus_hk_getInt32Param(${param['label']}, value);
	//return pus_paramToInt32(value, pus_st03_params[${param['label']}]);
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
	
	return PUS_NO_ERROR;
}

% endfor

