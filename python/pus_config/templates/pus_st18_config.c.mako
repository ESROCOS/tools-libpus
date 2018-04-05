//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS Service ST[18] On-board control procedure
// 
// File automatically generated from the pus_st18_config.c.mako template
//
//                     -- DO NOT MODIFY --


#include "pus_st18_config.h"

volatile bool pus_obcp_engineStopped = true;

const size_t pus_obcp_ObcpLimit = MAXIMUN_OBCP;

pusObcpInfo_t pus_obcp_infoList[MAXIMUN_OBCP];

#ifndef PUS_DISABLE_THREADS
pthread_mutex_t pus_obcp_mutexEngine;
pthread_cond_t pus_obcp_condEngine;
#endif

pusError_t pus_obcp_configure()
{
	#ifndef PUS_DISABLE_THREADS
    	pthread_mutex_init(&pus_obcp_mutexEngine, NULL);
    	pthread_cond_init(&pus_obcp_condEngine, NULL);
    #endif
	
	for(size_t i = 0; i < MAXIMUN_OBCP; i++)
	{
		memcpy(pus_obcp_infoList[i].id.arr, "DEFAULT\0", 10); //DEFAULT
        pus_obcp_infoList[i].status = PUS_OBCP_STATUS_UNLOAD; //UNLOAD
        pus_obcp_infoList[i].interpreterInitialized = false;
        
        #ifndef PUS_DISABLE_THREADS
        	pthread_mutex_init(&pus_obcp_infoList[i].mutex, NULL);
        	pthread_cond_init(&pus_obcp_infoList[i].cond, NULL);
        #endif
	}
			
	return PUS_NO_ERROR;
}

