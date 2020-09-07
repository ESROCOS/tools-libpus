/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */


#include "pus_robot_control.h"

// Mutex to lock access to the home plan coords
pusMutex_t* pus_robotControl_mutex = NULL;

// Initialized flag
bool pus_robotControl_initializedFlag = false;

bool pus_robotControl_isHomeSet = false;


pusError_t pus_robotControl_initialize(pusMutex_t* mutex)
{
	if (pus_robotControl_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	pus_robotControl_mutex = mutex;

	if (NULL != pus_robotControl_mutex && !pus_mutexLockOk(pus_robotControl_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	// Init something?


	if (NULL != pus_robotControl_mutex && !pus_mutexUnlockOk(pus_robotControl_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	pus_robotControl_initializedFlag = true;
	return PUS_NO_ERROR;
}

pusError_t pus_robotControl_finalize()
{
	if (!pus_robotControl_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		pus_robotControl_mutex = NULL;
		pus_robotControl_initializedFlag = false;
		return PUS_NO_ERROR;
	}
}

bool pus_robotControl_isInitialized()
{
	return pus_robotControl_initializedFlag;
}



