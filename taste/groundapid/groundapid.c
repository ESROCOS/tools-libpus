/* User code: This file will not be overwritten by TASTE. */

#include "groundapid.h"

/* Function static data is declared in this file : */
#include "Context-groundapid.h"


#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_types.h"

pusApidInfo_t apid;

void groundapid_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */

	pus_initApidInfo(&apid, groundapid_ctxt.apid, NULL);
}

void groundapid_PI_getApid(asn1SccPusApid *OUT_apid)
{
    /* Write your code here! */
	*OUT_apid = apid.apid;
}

void groundapid_PI_getSequenceCounter(asn1SccPusSequenceCount *OUT_sequenceCount)
{
    /* Write your code here! */
	*OUT_sequenceCount = pus_getNextPacketCount(&apid);
}

