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

// PUS service ST[12] configuration
// 
// File automatically generated from the pus_st12_config.c.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_st12_config.h"


// ST[03] constants
const pusSt03ParamId_t pus_ST12_PARAM_LIMIT = PUS_ST12_PARAM_LIMIT;

pusSt12PmonDefinition pus_pmon_definitionList[PUS_ST12_PARAM_LIMIT];


pusError_t pus_pmon_configure()
{

	% for param in config['parameters']:
	pus_pmon_definitionList[${param['label']}].status = true;
	pus_pmon_definitionList[${param['label']}].check.checking_status = 1;
	
	% endfor
    return PUS_NO_ERROR;
}



