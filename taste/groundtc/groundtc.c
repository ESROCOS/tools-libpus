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


void groundtc_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
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

	pusApid_t apid;
	pusSequenceCount_t seqCount;
	groundtc_RI_getApid(&apid);
	groundtc_RI_getSequenceCounter(&seqCount);


	error = pus_tc_17_1_createConnectionTestRequest(&tcSend, apid, seqCount);
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

