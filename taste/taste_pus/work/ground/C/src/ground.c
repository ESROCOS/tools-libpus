/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
 
/* User code: This file will not be overwritten by TASTE. */

#include "ground.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <Python.h>

#include "pus_error.h"
#include "pus_notify.h"
#include "pus_packet.h"


#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"
#include "pus_st08_packets.h"
#include "pus_st08_config.h"

void *myThreadFun(void* arg)
{
    /*
    import builtins
    builtins.ESROCOS_PUSGUI_MODULE = sys.argv[1]
    builtins.ESROCOS_PUSGUI_CONFIG = "config.json"
    import PusGui
    */

	(void*)arg; /* unused */
    
    Py_Initialize();
    PyRun_SimpleString("import builtins\n");
    PyRun_SimpleString("builtins.ESROCOS_PUSGUI_MODULE = \"esrocos_pus_test_01\"\n");
    PyRun_SimpleString("builtins.ESROCOS_PUSGUI_CONFIG = \"/home/peraspera/esrocos_workspace/tools/libpus/mission/test_01/gui_config.json\"\n");
    PyRun_SimpleString("builtins.ESROCOS_PUSGUI_MISSION = \"/home/peraspera/esrocos_workspace/tools/libpus/mission/test_01\"\n");
    PyRun_SimpleString("import PusGui\n");
    PyRun_SimpleString("PusGui.create()\n");

    Py_Finalize();

    return NULL;
}

void ground_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
    printf("Notify init: %d\n", pus_notify_initialize());

    //init thread
    pthread_t tid;
    pthread_create(&tid, NULL, myThreadFun, NULL);
    printf("Startup completed!\n");
}

void ground_PI_newTm(const asn1SccPusPacket *IN_tmPacket)
{
    /* Write your code here! */
    pus_notify_writeTm(IN_tmPacket);
    printf("Received\n");  
}


void ground_PI_triggerTmGUI()
{
    pusPacket_t packet;
    while(PUS_NO_ERROR == pus_notify_readTc(&packet))
    {
        ground_RI_newTc(&packet);
    }
    
}
