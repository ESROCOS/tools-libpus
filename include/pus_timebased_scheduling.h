/*! \file pus_timebased_scheduling.h
 *  \brief Time-based Scheduling functionality.
 *
 * TODO
 *
 *  \author GMV
 */


#ifndef PUS_TIMEBASED_SCHEDULING_H
#define PUS_TIMEBASED_SCHEDULING_H


#include "pus_types.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_apid.h"

#ifdef  __cplusplus
extern "C" {
#endif


typedef struct
{
	pusTime_t time;
	pusPacket_t action;
	bool deleted;
}pusSchedulingAction_t;

extern pusSchedulingAction_t pus_scheduling_queue[];

extern const size_t pus_scheduling_queueSize;


//! Function to initialize the time-based scheduling configuration
/*! This function is generated from the mission database, and it should be declared
 *  in \ref pus_st11_config.h
 */
extern pusError_t pus_scheduling_configure();

//! Function that initialize the time-based scheduling.
pusError_t pus_scheduling_initialize(pusMutex_t* mutex);

//! Check if the time-based scheduling is initialized.
bool pus_scheduling_isInitialized();



#ifdef  __cplusplus
}
#endif

#endif
