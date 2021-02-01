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
//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS service ST[03] configuration
// 
// File automatically generated from the pus_st30_config.h.mako template
//


#include "pus_st03_config.h"
#ifdef PUS_CONFIGURE_HK_PARAMS_TABLE

#include <string.h> //memcpy

// ST[03] arrays
pusSt03ParamInfo_t pus_st03_paramInfo[${tempvars['numParams']}];
pusStoredParam_t pus_st03_params[${tempvars['numParams']}];

// ST[03] reports
% for report in config['hkReports']:
pusSt03ParamId_t pus_st03_HkReportsIDs_${report['name']}[${len(report['parameters'])}];
% endfor
pusSt03ReportInfo_t pus_st03_HkReportInfos[PUS_HK_NUMBER_REPORTS];

// ST[03] constants
const pusSt03ParamId_t pus_ST03_PARAM_LIMIT = PUS_ST03_PARAM_LIMIT;
const pusSt03HousekeepingReportId_t pus_ST03_REPORT_LIMIT = PUS_HK_NUMBER_REPORTS;

pusError_t pus_hk_configure()
{
	// Store parameters info
% for param in config['parameters']:
<% 
if param['type'] == 'UINT16':
    param['type'] = 'UINT32'
elif param['type'] == 'REAL32':
    param['type'] = 'REAL64'
%>
    pus_st03_params[${param['label']}] = 0;
    pus_st03_paramInfo[${param['label']}].label = "${param['label']}";
    pus_st03_paramInfo[${param['label']}].type = PUS_${param['type']};
% endfor
	// HK reports definition
	% for j, report in enumerate(config['hkReports']):
% for i, param in enumerate(report['parameters']):
	pus_st03_HkReportsIDs_${report['name']}[${i}] = ${param};
% endfor
	pus_st03_HkReportInfos[PUS_HK_REP_${report['name']}].numParams = ${len(report['parameters'])}U;
	pus_st03_HkReportInfos[PUS_HK_REP_${report['name']}].paramIds = &pus_st03_HkReportsIDs_${report['name']}[0];
	%if j == 0:
    pus_st03_HkReportInfos[PUS_HK_REP_${report['name']}].isEnabled = TRUE;
	%else:
	pus_st03_HkReportInfos[PUS_HK_REP_${report['name']}].isEnabled = FALSE;
	%endif

% endfor
    return PUS_NO_ERROR;
}

pusError_t pus_hk_getReportParams(pusSt03HousekeepingReportId_t reportId, size_t *numParams, pusSt03ParamId_t* paramIds)
{
    if((numParams == NULL) || (paramIds == NULL))
    {
        return PUS_SET_ERROR(PUS_ERROR_NULLPTR);
    }

    if(reportId >= PUS_HK_NUMBER_REPORTS)
    {
        return PUS_SET_ERROR(PUS_ERROR_INVALID_ID);
    }
    else
    {
        *numParams = pus_st03_HkReportInfos[reportId].numParams;
    	memcpy(paramIds, pus_st03_HkReportInfos[reportId].paramIds, sizeof(pusSt03ParamId_t) * 20);

        
        return PUS_SET_ERROR(PUS_NO_ERROR);
    }
}

% for param in config['parameters']:
<% 
if param['type'] == 'UINT16':
    param['type'] = 'UINT32'
elif param['type'] == 'REAL32':
    param['type'] = 'REAL64'
%>
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

#endif

