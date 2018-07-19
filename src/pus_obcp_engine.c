/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */

#include "pus_obcp_engine.h"
#ifdef PUS_CONFIGURE_OBCP_ENGINE

#include <string.h>
#include <stdio.h>

#ifndef PUS_DISABLE_THREADS // PUS_DISABLE_THREADS //TODO

extern const size_t pus_obcp_ObcpLimit;
extern pusObcpInfo_t pus_obcp_infoList[];
extern pusError_t pus_obcp_configure();

// Initialized flag
bool pus_obcp_initializedFlag = false;

bool pus_obcp_engineRunning = false;



//MUTEX
pusMutex_t* pus_obcp_mutex = NULL;

pusError_t pus_obcp_initialize(pusMutex_t* mutex)
{
	if (pus_obcp_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_ALREADY_INITIALIZED);
	}

	pus_obcp_mutex = mutex;

	if (NULL != pus_obcp_mutex && !pus_mutexLockOk(pus_obcp_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	mp_init_context_arrays();

	if( PUS_NO_ERROR != pus_obcp_configure())
	{
		if (NULL != pus_obcp_mutex)
		{
			(void) pus_mutexUnlockOk(pus_obcp_mutex);
		}
		return PUS_SET_ERROR(PUS_ERROR_INITIALIZATION);
	}

	pus_obcp_initializedFlag = true;

	pus_obcp_engineRunning = false;

	if (NULL != pus_obcp_mutex && !pus_mutexUnlockOk(pus_obcp_mutex))
	{
		return PUS_ERROR_INITIALIZATION;
	}

	extern pthread_t pus_obcp_threads[];
	for(size_t i = 0; i < pus_obcp_ObcpLimit; i++)
	{
		pthread_create(&pus_obcp_threads[i], NULL, pus_obcp_thread, (void*)i);
	}

	pus_obcp_startEngine();

	return PUS_NO_ERROR;
}

pusError_t pus_obcp_finalize()
{
	if (!pus_obcp_isInitialized())
	{
		return PUS_SET_ERROR(PUS_ERROR_NOT_INITIALIZED);
	}
	else
	{
		pus_obcp_mutex = NULL;
		pus_obcp_initializedFlag = false;
		return PUS_NO_ERROR;
	}
}

bool pus_obcp_isInitialized()
{
	return pus_obcp_initializedFlag;
}

pusError_t pus_obcp_startEngine()
{
	if( false == pus_obcp_isInitialized())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( pus_obcp_engineRunning == true )
	{
		return PUS_ERROR_OBCP_ENGINE_ALREADY_RUNNING;
	}

	pus_obcp_engineRunning = true;

	return PUS_NO_ERROR;
}


pusError_t pus_obcp_stopEngine()
{
	if( false == pus_obcp_isInitialized())
	{
		return PUS_ERROR_NOT_INITIALIZED;
	}

	if( pus_obcp_engineRunning == false )
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	pus_obcp_engineRunning = false;

	return PUS_NO_ERROR;
}

bool pus_obcp_isEngineRunning()
{
	if(!pus_obcp_isInitialized())
	{
		return false;
	}

	return pus_obcp_engineRunning;
}

uint32_t pus_obcp_getObcpLoadedActives()
{
	if(!pus_obcp_isEngineRunning())
	{
		return 0;
	}

	uint32_t cont = 0;
	for(size_t i = 0; i < pus_obcp_ObcpLimit; i++)
	{
		if(0 != pthread_mutex_lock(&pus_obcp_infoList[i].mutex))
		{
			return 0;
		}

		if( PUS_OBCP_STATUS_ACTIVE_RUNNING == pus_obcp_infoList[i].status)
		{
			cont++;
		}

		if(0 != pthread_mutex_unlock(&pus_obcp_infoList[i].mutex))
		{
			return 0;
		}
	}

	return cont;
}

uint32_t pus_obcp_getObcpLoadedInactives()
{
	if(!pus_obcp_isEngineRunning())
	{
		return 0;
	}

	uint32_t cont = 0;
	for(size_t i = 0; i < pus_obcp_ObcpLimit; i++)
	{
		if(0 != pthread_mutex_lock(&pus_obcp_infoList[i].mutex))
		{
			return 0;
		}

		if( PUS_OBCP_STATUS_INACTIVE == pus_obcp_infoList[i].status)
		{
			cont++;
		}

		if(0 != pthread_mutex_unlock(&pus_obcp_infoList[i].mutex))
		{
			return 0;
		}
	}

	return cont;
}

uint32_t pus_obcp_getObcpSlotNotLoaded()
{
	if(!pus_obcp_isEngineRunning())
	{
		return 0;
	}

	uint32_t cont = 0;
	for(size_t i = 0; i < pus_obcp_ObcpLimit; i++)
	{
		if(0 != pthread_mutex_lock(&pus_obcp_infoList[i].mutex))
		{
			return 0;
		}

		if( PUS_OBCP_STATUS_UNLOAD == pus_obcp_infoList[i].status)
		{
			cont++;
		}

		if(0 != pthread_mutex_unlock(&pus_obcp_infoList[i].mutex))
		{
			return 0;
		}
	}

	return cont;
}

bool pus_obcp_IsSameObcpId(pusSt18ObcpId_t* id1, pusSt18ObcpId_t* id2)
{
    if(0 == strcmp((char*)id1->arr, (char*)id2->arr))
    {
        //printf("TRUE!\n");
        return true;
    }
    else
    {
        //printf("FALSE!\n");
        return false;
    }
}

bool pus_obcp_IsObcpLoaded( pusSt18ObcpId_t* id, size_t* index )
{
	if( false == pus_obcp_isEngineRunning())
	{
		return false;
	}

	uint32_t status;
	for(size_t i = 0; i < pus_obcp_ObcpLimit; i++)
	{
    	if(0 != pthread_mutex_lock(&pus_obcp_infoList[i].mutex))
    	{
    		return false;
    	}
		status = pus_obcp_infoList[i].status;
    	if(0 != pthread_mutex_unlock(&pus_obcp_infoList[i].mutex))
    	{
    		return false;
    	}

		if( status != PUS_OBCP_STATUS_UNLOAD)
		{
			//printf("i: %lu, id.arr %s, pus_obcp_infoList[i]: %s --> ", i, (char*)id->arr, (char*)pus_obcp_infoList[i].id.arr);
			if( true == pus_obcp_IsSameObcpId( id, &pus_obcp_infoList[i].id) )
			{
				*index = i;
				return true;
			}
		}
	}
	return false;
}


pusError_t pus_obcp_setLoadInfo(pusObcpInfo_t* obcpInfo, pusSt18ObcpId_t* id, pusSt18ObcpStatus_t status, pusSt18ObcpCode_t* code)
{
	obcpInfo->id = *id;
	obcpInfo->status = status;
	obcpInfo->code = *code;
	obcpInfo->confirmation = PUS_OBCP_CONFIRMATION_STATUS_NOT_COMPLETED;

	return PUS_NO_ERROR;
}


pusError_t pus_obcp_loadObcp( pusSt18ObcpId_t* id, pusSt18ObcpCode_t* code )
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}
	size_t index;
	if( true == pus_obcp_IsObcpLoaded(id, &index) )
    {
        return PUS_ERROR_OBCP_ALREADY_LOADED;
    }
    for(size_t i = 0; i < pus_obcp_ObcpLimit; i++)
    {
    	printf(" ---- Loading %d, status %d\n", i, pus_obcp_infoList[i].status);
		if(0 !=  pthread_mutex_lock(&pus_obcp_infoList[i].mutex))
    	{
    		return PUS_ERROR_THREADS;
    	}
        if( pus_obcp_infoList[i].status == PUS_OBCP_STATUS_UNLOAD )
        {
        	pus_obcp_setLoadInfo(&pus_obcp_infoList[i], id, PUS_OBCP_STATUS_INACTIVE, code);

            if(0 != pthread_mutex_unlock(&pus_obcp_infoList[i].mutex))
			{
				return PUS_ERROR_THREADS;
			}
            return PUS_NO_ERROR;
        }
    	if(0 != pthread_mutex_unlock(&pus_obcp_infoList[i].mutex))
    	{
    		return PUS_ERROR_THREADS;
    	}
    }

    return PUS_ERROR_OBCP_FULL_BUFFER;
}


pusError_t pus_obcp_unloadObcp( pusSt18ObcpId_t* id )
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
	  return PUS_ERROR_OBCP_NOT_LOADED;
	}

	if(0 != pthread_mutex_lock(&pus_obcp_infoList[index].mutex))
	{
		return PUS_ERROR_THREADS;
	}	//printf("LOCK ACTIVATE %p, status: %d\n", &pus_obcp_infoList[index].mutex, pthread_mutex_lock(&pus_obcp_infoList[index].mutex));

	if (pus_obcp_infoList[index].status == PUS_OBCP_STATUS_ACTIVE_RUNNING)
	{
			if(0 != pthread_mutex_unlock(&pus_obcp_infoList[index].mutex))
			{
				return PUS_ERROR_THREADS;
			}
			return PUS_ERROR_OBCP_IS_RUNNING;
	}

	memcpy(pus_obcp_infoList[index].id.arr, "DEFAULT\0", 10); //DEFAULT
	pus_obcp_infoList[index].status = PUS_OBCP_STATUS_UNLOAD; //UNLOAD

	if(0 != pthread_mutex_unlock(&pus_obcp_infoList[index].mutex))
	{
		return PUS_ERROR_THREADS;
	}
	//printf("UNLOCK ACTIVATE cond %p, status: %d\n", &pus_obcp_infoList[index].cond, pthread_cond_signal(&pus_obcp_infoList[index].cond));
	//printf("UNLOCK ACTIVATE mutex %p, status: %d\n", &pus_obcp_infoList[index].mutex, pthread_mutex_unlock(&pus_obcp_infoList[index].mutex));

	return PUS_NO_ERROR;
}


pusError_t pus_obcp_activateObcp( pusSt18ObcpId_t* id )
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
	  return PUS_ERROR_OBCP_NOT_LOADED;
	}

	if(0 != pthread_mutex_lock(&pus_obcp_infoList[index].mutex))
	{
		return PUS_ERROR_THREADS;
	}
	//printf("LOCK ACTIVATE %p, status: %d\n", &pus_obcp_infoList[index].mutex, pthread_mutex_lock(&pus_obcp_infoList[index].mutex));

	if (pus_obcp_infoList[index].status == PUS_OBCP_STATUS_ACTIVE_RUNNING)
	{
			if(0 != pthread_mutex_unlock(&pus_obcp_infoList[index].mutex))
			{
				return PUS_ERROR_THREADS;
			}
			return PUS_ERROR_OBCP_ALREADY_ACTIVATED;
	}

	if( pus_obcp_infoList[index].status ==  PUS_OBCP_STATUS_INACTIVE )
	{
		pus_obcp_infoList[index].status = PUS_OBCP_STATUS_ACTIVE_RUNNING;
	}

	//printf("UNLOCK ACTIVATE cond %p, status: %d\n", &pus_obcp_infoList[index].cond, pthread_cond_signal(&pus_obcp_infoList[index].cond));
	//printf("UNLOCK ACTIVATE mutex %p, status: %d\n", &pus_obcp_infoList[index].mutex, pthread_mutex_unlock(&pus_obcp_infoList[index].mutex));

	if(0 != pthread_cond_signal(&pus_obcp_infoList[index].cond))
	{
		return PUS_ERROR_THREADS;
	}
	if(0 != pthread_mutex_unlock(&pus_obcp_infoList[index].mutex))
	{
		return PUS_ERROR_THREADS;
	}

	//printf("UNLOCK ACTIVATE %p\n", &pus_obcp_infoList[index].cond);

	return PUS_NO_ERROR;
}


pusError_t pus_obcp_executeObcp(pusSt18ObcpId_t* id)
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
	  return PUS_ERROR_OBCP_NOT_LOADED;
	}

	if( false == &pus_obcp_infoList[index].interpreterInitialized )
	{
		return PUS_ERROR_OBCP_INTERPRETER_NOT_INIT;
	}

	if( 0 != mp_exec_mpy(pus_obcp_infoList[index].code.arr, pus_obcp_infoList[index].code.nCount))
	{
		return PUS_ERROR_EXECUTING_OBCP;
	}
	return PUS_NO_ERROR;
}

pusError_t pus_obcp_stopObcp(pusSt18ObcpId_t* id)
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
	  return PUS_ERROR_OBCP_NOT_LOADED;
	}

	pthread_mutex_lock(&pus_obcp_infoList[index].mutex);
	if( pus_obcp_infoList[index].status !=  PUS_OBCP_STATUS_ACTIVE_RUNNING )
	{
		pthread_mutex_unlock(&pus_obcp_infoList[index].mutex);
		return PUS_ERROR_OBCP_IS_RUNNING;
	}

	//TODO else error
	pus_obcp_infoList[index].status = PUS_OBCP_STATUS_ACTIVE_STOP_REQUEST;
	pthread_mutex_unlock(&pus_obcp_infoList[index].mutex);

	return PUS_NO_ERROR;
}

pusError_t pus_obcp_suspendObcp(pusSt18ObcpId_t* id)
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
	  return PUS_ERROR_OBCP_NOT_LOADED;
	}

	pthread_mutex_lock(&pus_obcp_infoList[index].mutex);
	if( pus_obcp_infoList[index].status ==  PUS_OBCP_STATUS_ACTIVE_RUNNING )
	{
		pus_obcp_infoList[index].status = PUS_OBCP_STATUS_ACTIVE_HELD_REQUEST;
	}
	pthread_mutex_unlock(&pus_obcp_infoList[index].mutex);

	//TODO else error

	return PUS_NO_ERROR;
}


pusError_t pus_obcp_abortObcp(pusSt18ObcpId_t* id)
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
	  return PUS_ERROR_OBCP_NOT_LOADED;
	}

	pthread_mutex_lock(&pus_obcp_infoList[index].mutex);
	pus_obcp_infoList[index].status = PUS_OBCP_STATUS_ACTIVE_ABORT_REQUEST;
	pthread_mutex_unlock(&pus_obcp_infoList[index].mutex);

	return PUS_NO_ERROR;
}

pusError_t pus_obcp_resumeObcp( pusSt18ObcpId_t* id )
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
	  return PUS_ERROR_OBCP_NOT_LOADED;
	}

	if(0 != pthread_mutex_lock(&pus_obcp_infoList[index].mutex))
	{
		return PUS_ERROR_THREADS;
	}

	if (pus_obcp_infoList[index].status != PUS_OBCP_STATUS_ACTIVE_HELD)
	{
			if(0 != pthread_mutex_unlock(&pus_obcp_infoList[index].mutex))
			{
				return PUS_ERROR_THREADS;
			}
			return PUS_ERROR_OBCP_NOT_HELD;
	}

	pus_obcp_infoList[index].status = PUS_OBCP_STATUS_ACTIVE_RESUME_REQUEST;

	if(0 != pthread_cond_signal(&pus_obcp_infoList[index].cond_suspend))
	{
		return PUS_ERROR_THREADS;
	}
	if(0 != pthread_mutex_unlock(&pus_obcp_infoList[index].mutex))
	{
		return PUS_ERROR_THREADS;
	}

	return PUS_NO_ERROR;
}


pusError_t pus_obcp_waitForActivation(pusObcpInfo_t* obcpInfo)
{
	pthread_mutex_lock(&obcpInfo->mutex);

	while( obcpInfo->status != PUS_OBCP_STATUS_ACTIVE_RUNNING )
	{
		pthread_cond_wait (&obcpInfo->cond, &obcpInfo->mutex);
	}

	pthread_mutex_unlock(&obcpInfo->mutex);

	return PUS_NO_ERROR;
}

pusError_t pus_obcp_waitForActivationById(pusSt18ObcpId_t* id)
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
		return PUS_ERROR_OBCP_NOT_LOADED;
	}

	return pus_obcp_waitForActivation(&pus_obcp_infoList[index]);
}

pusError_t pus_obcp_waitForResume(pusObcpInfo_t* obcpInfo)
{
	pthread_mutex_lock(&obcpInfo->mutex);

	while( obcpInfo->status != PUS_OBCP_STATUS_ACTIVE_RESUME_REQUEST )
	{
		printf("OBCP suspended\n");
		pthread_cond_wait (&obcpInfo->cond_suspend, &obcpInfo->mutex);
	}

	pthread_mutex_unlock(&obcpInfo->mutex);

	return PUS_NO_ERROR;
}

pusError_t pus_obcp_waitForResumeById(pusSt18ObcpId_t* id)
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
		return PUS_ERROR_OBCP_NOT_LOADED;
	}

	pus_obcp_infoList[index].status = PUS_OBCP_STATUS_ACTIVE_HELD;

	return pus_obcp_waitForResume(&pus_obcp_infoList[index]);
}

pusError_t pus_obcp_setStatusAferExecution(pusObcpInfo_t* obcpInfo)
{
	pthread_mutex_lock(&obcpInfo->mutex);
	if (obcpInfo->status != PUS_OBCP_STATUS_UNLOAD)
	{
		obcpInfo->status = PUS_OBCP_STATUS_INACTIVE;
	}

	pthread_mutex_unlock(&obcpInfo->mutex);

	return PUS_NO_ERROR;
}


pusError_t pus_obcp_setConfirmationStatus(pusSt18ObcpId_t* id, pusSt18ObcpConfirmationStatus_t status)
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
		return PUS_ERROR_OBCP_NOT_LOADED;
	}

	pus_obcp_infoList[index].confirmation = status;

	return PUS_NO_ERROR;
}


pusError_t pus_obcp_setStatus(pusSt18ObcpId_t* id, pusSt18ObcpStatus_t status)
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
		return PUS_ERROR_OBCP_NOT_LOADED;
	}

	pthread_mutex_lock(&pus_obcp_infoList[index].mutex);

	pus_obcp_infoList[index].status = status;

	pthread_mutex_unlock(&pus_obcp_infoList[index].mutex);

	return PUS_NO_ERROR;
}

pusSt18ObcpStatus_t pus_obcp_getStatus(pusSt18ObcpId_t* id)
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_OBCP_STATUS_UNLOAD;
	}

	size_t index;
	if( false == pus_obcp_IsObcpLoaded(id, &index) )
	{
		return PUS_OBCP_STATUS_UNLOAD;
	}

	pthread_mutex_lock(&pus_obcp_infoList[index].mutex);

	pusSt18ObcpStatus_t status = pus_obcp_infoList[index].status;

	pthread_mutex_unlock(&pus_obcp_infoList[index].mutex);

	return status;
}

/////////////
pusError_t pus_obcp_executeCode(pusObcpInfo_t* obcpInfo)
{
	if( false == pus_obcp_isEngineRunning())
	{
		return PUS_ERROR_OBCP_ENGINE_NOT_RUNNING;
	}

	if( false == obcpInfo->interpreterInitialized )
	{
		return PUS_ERROR_OBCP_INTERPRETER_NOT_INIT;
	}

	if( 0 != mp_exec_mpy(obcpInfo->code.arr, obcpInfo->code.nCount))
	{
		return PUS_ERROR_EXECUTING_OBCP;
	}
	return PUS_NO_ERROR;
}


pusError_t pus_obcp_initUPyInterpreter(pusObcpInfo_t* obcpInfo)
{
    mp_register_current_context(&obcpInfo->mp_ctx);
    mp_stack_ctrl_init();
    mp_stack_set_limit(PUS_OBCP_STACK_LIMIT); //changed from 8192
    gc_init(obcpInfo->mp_heap, (uint8_t*)obcpInfo->mp_heap + sizeof(obcpInfo->mp_heap));
    mp_pystack_init(obcpInfo->mp_pystack, (uint8_t*)obcpInfo->mp_pystack + sizeof(obcpInfo->mp_pystack));
    mp_init();

    obcpInfo->interpreterInitialized = true;

	return PUS_NO_ERROR;
}

void* pus_obcp_thread( void * arg )
{
    size_t id = (size_t)arg;
    printf("Pthread %lu created\n", id);

    pus_obcp_initUPyInterpreter(&pus_obcp_infoList[id]);

    while(1)
    {
		//WAIT FOR OBCP_ACTIVATION
		pus_obcp_waitForActivation(&pus_obcp_infoList[id]);

		//SCRIPT EXECUTION
		if( PUS_NO_ERROR != pus_obcp_executeCode(&pus_obcp_infoList[id]))
		{
			printf("Exception raised from OBCP execution\n");
		}

		//CHANGE STATUS
		pus_obcp_setStatusAferExecution(&pus_obcp_infoList[id]);
    }

    return NULL;
}

#endif // PUS_DISABLE_THREADS

#endif
