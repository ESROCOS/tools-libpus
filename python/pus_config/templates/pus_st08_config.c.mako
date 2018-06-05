//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS Packet Queues configuration
// 
// File automatically generated from the pus_st08_config.c.mako template
//
//                     -- DO NOT MODIFY --



#include "pus_st08_config.h"
#ifdef PUS_CONFIGURE_ST08_ENABLED


pusError_t (*pus_st08_functionTable[${config['functions'].__len__()}])();

const size_t pus_st08_limitFunctions = ${config['functions'].__len__()};

pusSt08FunctionInfo_t pus_st08_functionInfoList[${config['functions'].__len__()}];

pusError_t pus_st08_configure()
{
	% for function in config['functions']:
	extern pusError_t ${function['name']}();
	pus_st08_functionTable[${function['label']}] = &${function['name']};
	
	pus_st08_functionInfoList[${function['label']}].label = "${function['label']}";
		
	% endfor
			
	return PUS_NO_ERROR;
}

#endif
