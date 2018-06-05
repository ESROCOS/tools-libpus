//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS Service ST[11] Time-based Monitoring
// 
// File automatically generated from the pus_st11_config.c.mako template
//
//                     -- DO NOT MODIFY --


#include "pus_st11_config.h"
#ifdef PUS_CONFIGURE_ST11_ENABLED

pusSchedulingActivity_t pus_scheduling_table[${config['maximumActivities']}];

pusSt11ScheduledActivity_t pus_scheduling_tableAuxiliar[${config['maximumActivities']}];

const size_t pus_scheduling_tableSize = ${config['maximumActivities']};

pusError_t pus_scheduling_configure()
{
	return PUS_NO_ERROR;
}

#endif
