/* User code: This file will not be overwritten by TASTE. */

#include "st17.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

#include "pus_st17_packets.h"


pusApidInfo_t apidSt17; //TODO or general for On-Board Services

void st17_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	pus_initApidInfo(&apidSt17, 1, NULL);
}

void st17_PI_tc17(const asn1SccPusPacket *IN_tcPacket)
{
    /* Write your code here! */
	pusError_t error = PUS_EXPECT_ST17TC(IN_tcPacket, pusSubtype_NONE);
	if( PUS_NO_ERROR == error )
	{
		printf(" - ST17: TC%llu_%llu received.\n", pus_getTcService(IN_tcPacket), pus_getTcSubtype(IN_tcPacket));

		printf(" - ST17: processing packet\n");
		pusPacket_t tmResponse;
		pus_st17_createTestResponse(&tmResponse, &apidSt17, IN_tcPacket);
		printf(" - ST17: Sending TM17.2\n");
		st17_RI_newTm(&tmResponse);


		printf(" - ST17: sending packet to ST01\n");
		asn1SccPusApid apid = 1;
		asn1SccPusSequenceCount count = 0;
		asn1SccT_Boolean flagError = false;
		asn1SccPusSt01FailureCode errorCode = 0;
		asn1SccPusSt01FailureInfo info;
		st17_RI_ACK(IN_tcPacket, &apid, &count, &flagError, &errorCode, &info);
	}
	else
	{
		//create tm1.2 if needed

		printf(" - ST17: Error in st17_PI_tc17, %d (no exit)\n", error);
	}



	//pus_st17_processTcPacket(&tcRead, &apid);
}

