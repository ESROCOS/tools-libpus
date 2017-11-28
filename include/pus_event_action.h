//header


#ifndef PUS_EVENT_ACTION_H
#define PUS_EVENT_ACTION_H


#include "pus_types.h"
#include "pus_error.h"
#include "pus_threads.h"
#include "pus_events.h"

typedef struct
{
	pusSt05EventId_t eventID;
	bool status;
	pusPacket_t tcAction; //action TC?
}pusSt19EventActionDefinition_t;

//from config TODO
extern pusSt19EventActionDefinition_t pus_st19_EventActionDefinitionList[];


#endif
