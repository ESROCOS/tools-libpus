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
pusSt201Orientation pus_robotControl_homeOrientation;
pusSt201Position pus_robotControl_homePosition;


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


pusError_t pus_robotControl_setHomePositionPoints(pusSt201Point point1, pusSt201Point point2, pusSt201Point point3)
{

	if (!pus_robotControl_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	if (NULL != pus_robotControl_mutex && !pus_mutexLockOk(pus_robotControl_mutex))
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}

	pus_robotControl_homePosition.arr[0] = point1;
	pus_robotControl_homePosition.arr[1] = point2;
	pus_robotControl_homePosition.arr[2] = point3;
	pus_robotControl_isHomeSet = true;

	if (NULL != pus_robotControl_mutex && !pus_mutexUnlockOk(pus_robotControl_mutex))
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}

	return PUS_NO_ERROR;
}

pusError_t pus_robotControl_getHomePositionPoints(pusSt201Point* point1, pusSt201Point* point2, pusSt201Point* point3)
{

	if (!pus_robotControl_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	if (NULL != pus_robotControl_mutex && !pus_mutexLockOk(pus_robotControl_mutex))
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}

	if( pus_robotControl_isHomeSet == false)
	{
		if (NULL != pus_robotControl_mutex && !pus_mutexUnlockOk(pus_robotControl_mutex))
		{
			return PUS_SET_ERROR(PUS_ERROR_THREADS);
		}
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}

	*point1 = pus_robotControl_homePosition.arr[0];
	*point2 = pus_robotControl_homePosition.arr[1];
	*point3 = pus_robotControl_homePosition.arr[2];

	if (NULL != pus_robotControl_mutex && !pus_mutexUnlockOk(pus_robotControl_mutex))
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}

	return PUS_NO_ERROR;
}

pusError_t pus_robotControl_setHomeOrientationPoints(pusSt201Point point1, pusSt201Point point2, pusSt201Point point3, pusSt201Point point4)
{

	if (!pus_robotControl_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	if (NULL != pus_robotControl_mutex && !pus_mutexLockOk(pus_robotControl_mutex))
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}

	pus_robotControl_homeOrientation.arr[0] = point1;
	pus_robotControl_homeOrientation.arr[1] = point2;
	pus_robotControl_homeOrientation.arr[2] = point3;
	pus_robotControl_homeOrientation.arr[3] = point4;

	if (NULL != pus_robotControl_mutex && !pus_mutexUnlockOk(pus_robotControl_mutex))
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}

	return PUS_NO_ERROR;
}


pusError_t pus_robotControl_getHomeOrientationPoints(pusSt201Point* point1, pusSt201Point* point2, pusSt201Point* point3, pusSt201Point* point4)
{

	if (!pus_robotControl_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	if (NULL != pus_robotControl_mutex && !pus_mutexLockOk(pus_robotControl_mutex))
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}

	*point1 = pus_robotControl_homeOrientation.arr[0];
	*point2 = pus_robotControl_homeOrientation.arr[1];
	*point3 = pus_robotControl_homeOrientation.arr[2];
	*point4 = pus_robotControl_homeOrientation.arr[3];

	if (NULL != pus_robotControl_mutex && !pus_mutexUnlockOk(pus_robotControl_mutex))
	{
		return PUS_SET_ERROR(PUS_ERROR_THREADS);
	}

	return PUS_NO_ERROR;
}


