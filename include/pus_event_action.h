//header


#ifndef PUS_EVENT_ACTION_H
#define PUS_EVENT_ACTION_H


#include "pus_types.h"
#include "pus_error.h"
#include "pus_threads.h"
#include "pus_events.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	pusSt05EventId_t eventID;
	bool definitionStatus;
	pusPacket_t tcAction; //action TC? or reduced
	bool deleted;
}pusSt19EventActionDefinition_t;

//from config TODO
extern pusSt19EventActionDefinition_t pus_st19_EventActionDefinitionList[];
extern const size_t pus_st19_EventActionDefinitionListMaximum;

extern pusError_t pus_eventAction_configure();

pusError_t pus_eventAction_initialize(pusMutex_t* mutex);

bool pus_eventAction_isInitialized();







#ifdef __cplusplus
}
#endif


#endif
