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

# Indices assigned to the parameters
tempvars['paramIndex'] = dict()


def getCTypes( configType ):
	if str(configType) == str("INT32"):
		return str("int32_t")
	elif str(configType) == str("UINT32"):
		return str("uint32_t")
	elif str(configType) == str("REAL64"):
		return str("double")
	elif str(configType) == str("BYTE"):
		return str("uint8_t")
	elif str(configType) == str("BOOL"):
		return str("bool")
	endif
	
def getAliasName( configType ):
	if str(configType) == str("INT32"):
		return str("int32")
	elif str(configType) == str("UINT32"):
		return str("uint32")
	elif str(configType) == str("REAL64"):
		return str("real64")
	elif str(configType) == str("BYTE"):
		return str("byte")
	elif str(configType) == str("BOOL"):
		return str("bool")
	endif
	
%>

// PUS service ST[12] configuration
// 
// File automatically generated from the pus_st12_config.c.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_st12_config.h"




// ST[113] constants
const pusSt03ParamId_t pus_ST12_PARAM_LIMIT = PUS_ST12_PARAM_LIMIT;

pusSt12PmonDefinition pus_pmon_definitionList[PUS_ST12_PARAM_LIMIT];


pusError_t pus_pmon_configure()
{
	% for param in config['parameters']:
	pus_pmon_definitionList[${param['label']}].status = true;
	pus_pmon_definitionList[${param['label']}].check.low_limit.${param['type']} = ${param['low_limit']};
	pus_pmon_definitionList[${param['label']}].check.high_limit.${param['type']} = ${param['high_limit']};
	
	% endfor
    return PUS_NO_ERROR;
}



