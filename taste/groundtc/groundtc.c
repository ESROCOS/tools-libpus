/* User code: This file will not be overwritten by TASTE. */

#include "groundtc.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

#include "pus_st17_packets.h"

pusApidInfo_t apidGroundTC;

void groundtc_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	pus_initApidInfo(&apidGroundTC, 1, NULL);
}

void groundtc_PI_GroundTcTrigger()
{
    /* Write your code here! */
	pusPacket_t tcSend;
	pusError_t error = 0;


	if ( PUS_NO_ERROR != error)
	{
		printf("Error in groundtc_PI_GroundTcTrigger (initializing apid), %d\n", error);
		exit(-1);
	}


	error = pus_tc_17_1_createConnectionTestRequest(&tcSend, &apidGroundTC);
	if( PUS_NO_ERROR == error )
	{
		printf("TC%llu_%llu send from Ground.\n", pus_getTcService(&tcSend), pus_getTcSubtype(&tcSend));
		groundtc_RI_newTc(&tcSend);
	}
	else
	{
		printf("Error in groundtc_PI_GroundTcTrigger, %d (exit)\n", error);
		exit(-1);
	}
}

