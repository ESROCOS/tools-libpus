/* User code: This file will not be overwritten by TASTE. */

#include "groundtm.h"

#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"
#include "pus_stored_param.h"
#include "pus_types.h"
#include "pus_packet_queues.h"

void groundtm_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
}

void groundtm_PI_newTm(const asn1SccPusPacket *IN_tmPacket)
{
    /* Write your code here! */
	pusService_t service = pus_getTmService(IN_tmPacket);
	pusSubservice_t subtype = pus_getTmSubtype(IN_tmPacket);

	printf("GROUND: TM%llu_%llu in TmGround.\n", service, subtype);

	if(service == pus_ST03_housekeeping)
	{
		size_t nParam;
		pusStoredParam_t outValue;
		pusSt03HousekeepingReportId_t reportId = pus_tm_3_25_getReportId(IN_tmPacket);

		pus_tm_3_25_getNumParameters(IN_tmPacket, &nParam);
		printf("GROUND: reportId: %lu, nParam: %lu\n", reportId, nParam);

		for(size_t i = 0; i < nParam; i++)
		{
			pus_tm_3_25_getParameterValue(IN_tmPacket, i, &outValue);
			printf("GROUND: i:%lu, id:%lu\n", i ,outValue);
		}
	}
}

