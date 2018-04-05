//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS Service ST[18] On-board control procedure
// 
// File automatically generated from the pus_st18_config.h.mako template
//
//                     -- DO NOT MODIFY --


#ifndef PUS_ST18_CONFIG_H
#define PUS_ST18_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif


#include "pus_types.h"
#include "pus_threads.h"
#include <string.h>

#include "pus_obcp_engine.h"


#define MAXIMUN_OBCP ${config['maximumObcp']}

extern volatile bool pus_obcp_engineStopped;

#ifndef PUS_DISABLE_THREADS
extern pthread_mutex_t pus_obcp_mutexEngine;
extern pthread_cond_t pus_obcp_condEngine;
#endif


extern const size_t pus_obcp_ObcpLimit;

extern pusObcpInfo_t pus_obcp_infoList[];


#ifdef __cplusplus
}
#endif

 
 #endif