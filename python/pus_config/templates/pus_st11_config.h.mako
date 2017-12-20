// PUS Service ST[11] Time-based Monitoring
// 
// File automatically generated from the pus_st11_config.h.mako template
//
//                     -- DO NOT MODIFY --



#ifndef PUS_ST11_CONFIG_H
#define PUS_ST11_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif


#include "pus_error.h"
#include "pus_types.h"

#include "pus_timebased_scheduling.h"

#define PUS_SCHEDULING_MAXIMUN_ACTIVITIES_IN_TABLE ((size_t) ${config['maximumActivities']})

extern pusSchedulingActivity_t pus_scheduling_table[];

extern const size_t pus_scheduling_tableSize;

extern pusSt11ScheduledActivity_t pus_scheduling_tableAuxiliar[];

#ifdef __cplusplus
}
#endif

 
#endif