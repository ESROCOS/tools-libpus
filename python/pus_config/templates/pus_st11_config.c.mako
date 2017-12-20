// PUS Service ST[11] Time-based Monitoring
// 
// File automatically generated from the pus_st11_config.c.mako template
//
//                     -- DO NOT MODIFY --


#include "pus_st11_config.h"


pusSchedulingActivity_t pus_scheduling_table[${config['maximumActivities']}];

pusSt11ScheduledActivity_t pus_scheduling_tableAuxiliar[${config['maximumActivities']}];

const size_t pus_scheduling_tableSize = ${config['maximumActivities']};

pusError_t pus_scheduling_configure()
{
	return PUS_NO_ERROR;
}