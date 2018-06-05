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
#ifdef PUS_CONFIGURE_OBCP_ENGINE

const size_t pus_obcp_ObcpLimit = MAXIMUN_OBCP;

pusObcpInfo_t pus_obcp_infoList[MAXIMUN_OBCP];

pthread_t pus_obcp_threads[MAXIMUN_OBCP];


pusError_t pus_obcp_configure()
{

	for(size_t i = 0; i < MAXIMUN_OBCP; i++)
	{
		memcpy(pus_obcp_infoList[i].id.arr, "DEFAULT\0", 10); //DEFAULT
        pus_obcp_infoList[i].status = PUS_OBCP_STATUS_UNLOAD; //UNLOAD
        pus_obcp_infoList[i].interpreterInitialized = false;
        
        #ifndef PUS_DISABLE_THREADS
        	pthread_mutex_init(&pus_obcp_infoList[i].mutex, NULL);
        	pthread_cond_init(&pus_obcp_infoList[i].cond, NULL);
        	pthread_cond_init(&pus_obcp_infoList[i].cond_suspend, NULL);	
        	
        #endif
	}
			
	return PUS_NO_ERROR;
}

#endif
