/*
 * H2020 ESROCOS Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */
 
/* User code: This file will not be overwritten by TASTE. */

#include "onboardapid.h"

/* Function static data is declared in this file : */
#include "Context-onboardapid.h"


#include <stdio.h>
#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_types.h"

pusApidInfo_t apid;

void onboardapid_startup()
{
    /* Write your initialization code here,
       but do not make any call to a required interface. */
	pus_initApidInfo(&apid, onboardapid_ctxt.apid, NULL);
}

void onboardapid_PI_getApid(asn1SccPusApid *OUT_apid)
{
    /* Write your code here! */
	*OUT_apid = apid.apid;
}

void onboardapid_PI_getSequenceCount(asn1SccPusSequenceCount *OUT_sequenceCount)
{
    /* Write your code here! */
	*OUT_sequenceCount = pus_getNextPacketCount(&apid);
}

