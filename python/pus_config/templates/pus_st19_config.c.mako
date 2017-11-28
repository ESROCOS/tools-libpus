// PUS Service ST[19] Event-Actions
// 
// File automatically generated from the pus_st19_config.c.mako template
//
//                     -- DO NOT MODIFY --


#include "pus_st19_config.h"

extern const size_t pus_st19_EventActionDefinitionListMaximum = ${config['maximumDefinitions']};

pusSt19EventActionDefinition_t pus_st19_EventActionDefinitionList[${config['maximumDefinitions']}];

pusError_t pus_eventAction_configure()
{
	%for i in range(0, config['maximumDefinitions']):
	pus_st19_EventActionDefinitionList[${i}].deleted = true;
	% endfor
			
	return PUS_NO_ERROR;
}