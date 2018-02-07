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
    Py_Initialize();
    PyRun_SimpleString("import sys\n");
    PyRun_SimpleString("sys.path.insert(0, '/home/esrocos/esrocos-ws-pus/tools-pusconsole/app')\n");
    PyRun_SimpleString("import Main\n");
    PyRun_SimpleString("Main.main()\n");
    Py_Finalize();
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
    printf("Recibido\n");  
}


void ground_PI_triggerTmGUI()
{
    pusPacket_t packet;
    while(PUS_NO_ERROR == pus_notify_readTc(&packet))
    {
        ground_RI_newTc(&packet);
    }
    
}
