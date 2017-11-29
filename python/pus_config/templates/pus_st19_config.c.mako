// PUS Service ST[19] Event-Actions
// 
// File automatically generated from the pus_st19_config.c.mako template
//
//                     -- DO NOT MODIFY --


#include "pus_st19_config.h"

#include "pus_st05_config.h"

const size_t pus_st19_EventActionDefinitionListMaximum = PUS_ST05_EVENT_BUFFER_LIMIT;

pusSt19EventActionDefinition_t pus_st19_EventActionDefinitionList[PUS_ST05_EVENT_BUFFER_LIMIT];

pusError_t pus_eventAction_configure()
{
	for(size_t i = 0; i < PUS_ST05_EVENT_BUFFER_LIMIT; i++)
	{
		pus_st19_EventActionDefinitionList[i].deleted = true;
	}
			
	return PUS_NO_ERROR;
}