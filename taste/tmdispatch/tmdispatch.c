/* User code: This file will not be overwritten by TASTE. */

#include "tmdispatch.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

void tmdispatch_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void tmdispatch_PI_tmTrigger()
{
    /* Write your code here! */
	printf("TmDispatch: ");

	pusPacket_t tm;
	asn1SccT_Boolean isAvailable;

	tmdispatch_RI_tmRequest(&tm, &isAvailable);
	if( false == isAvailable )
	{
		printf("NO DATA READ\n");
		pus_clearError();
		return;
	}


	pusError_t error = PUS_EXPECT_TM(&tm);
	if ( PUS_NO_ERROR == error)
	{
		printf("TM%llu_%llu in TmDispatch.\n", pus_getTmService(&tm), pus_getTmSubtype(&tm));
		tmdispatch_RI_newTm(&tm);
	}
	else
	{
		printf(" - Error tmdispatch_PI_tmTrigger, %d (no exit)\n", error);
		//TODO ¿¿¿¿¿¿¿???? when no packet received
		pus_clearError();
	}
}

