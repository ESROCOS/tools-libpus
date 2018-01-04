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

#include "pus_packet_reduced.h"
#include "pus_st11_packets.h"

#ifdef  __cplusplus
extern "C" {
#endif


typedef struct
{
	pusTime_t time;
	pusPacket_t action;
	bool deleted;
}pusSchedulingActivity_t;

extern pusSchedulingActivity_t pus_scheduling_table[];

extern const size_t pus_scheduling_tableSize;

extern pusSt11ScheduledActivity_t pus_scheduling_tableAuxiliar[];

//! Function to initialize the time-based scheduling configuration
/*! This function is generated from the mission database, and it should be declared
 *  in \ref pus_st11_config.h
 */
extern pusError_t pus_scheduling_configure();

//! Function that initialize the time-based scheduling.
pusError_t pus_scheduling_initialize(pusMutex_t* mutex);

//! Function that finalize the time-based scheduling.
pusError_t pus_scheduling_finalize();

//! Check if the time-based scheduling is initialized.
bool pus_scheduling_isInitialized();

//! Check if the time-based scheduling function is enabled.
bool pus_scheduling_isFunctionEnable();

//! Setter for the  time-based scheduling function flag
pusError_t pus_scheduling_setFunctionFlag(bool flag);

//! Enable the time-based scheduling function
pusError_t pus_scheduling_enableFunction();

//! Disable the time-based scheduling function
pusError_t pus_scheduling_disableFunction();

//! Reset the time-based scheduling function
pusError_t pus_scheduling_resetFunction();

//! Add a new activity to the time-based scheduling table
pusError_t pus_scheduling_insertActivity(const pusPacket_t* tcAction, const pusTime_t* time);

//! Check if a scheduled activity can be executed
bool pus_scheduling_isActivityExecutable(const pusTime_t* timeRelease, const pusTime_t* timeRef);

//! Get an executable activity
/*!
 * Set in the packet passed an activity that can be executed.
 */
pusError_t pus_scheduling_getScheduledActivity(pusPacket_t* tcAction, const pusTime_t* time);

//! Insert the activities in TC[11,4] packet to the scheduling table.
/*!
 *  \param[in] packet TC[11.4] packet
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_scheduling_tc_11_4_packetToTable(const pusPacket_t* packet);


#ifdef  __cplusplus
}
#endif

#endif
