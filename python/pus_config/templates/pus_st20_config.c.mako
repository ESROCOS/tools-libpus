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
		return str("Int32")
	elif str(configType) == str("UINT32"):
		return str("UInt32")
	elif str(configType) == str("REAL64"):
		return str("Real64")
	elif str(configType) == str("BYTE"):
		return str("Byte")
	elif str(configType) == str("BOOL"):
		return str("Bool")
	endif
	
%>

// PUS service ST[20] configuration
// 
// File automatically generated from the pus_st20_config.h.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_st20_config.h"
#include "pus_parameter_management.h"

// ST[20] arrays
pusSt20ParamInfo_t pus_st20_paramInfo[${tempvars['numParams']}];
pusStoredParam_t pus_st20_params[${tempvars['numParams']}];


// ST[20] constants
const pusSt20OnBoardParamId_t pus_ST20_PARAM_LIMIT = PUS_ST20_PARAM_LIMIT;


pusError_t pus_parameters_configure()
{
	// Store parameters info
% for param in config['parameters']:
    pus_st20_paramInfo[${param['label']}].label = "${param['label']}";
    pus_st20_paramInfo[${param['label']}].type = PUS_${param['type']};
% endfor

    return PUS_NO_ERROR;
}


% for param in config['parameters']:
pusError_t pus_hk_set${param['label']}(${getCTypes(param['type'])} value)
{
	return pus_parameters_set${getAliasName(param['type'])}Param(${param['label']}, value);
}

pusError_t pus_hk_get${param['label']}(${getCTypes(param['type'])}* value)
{
	return pus_parameters_get${getAliasName(param['type'])}Param(${param['label']}, value);
}


% endfor



