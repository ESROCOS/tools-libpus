/*
 * H2020 MOSAR Project
 * Company: GMV Aerospace & Defence S.A.U.
 * Licence: GPLv2
 */


#include "pusservices_config.h"
#include "pusservices_apid.h"


/*! Current APID and count data structure */
pusApidInfo_t g_apid;

/*! Initialize the APID of the current PUS node */
void pusservices_initApid(asn1SccPusApid apid)
{
    pus_initApidInfo(&g_apid, apid, NULL);
}

/*! Get the APID of the current PUS node */
asn1SccPusApid pusservices_getApid(void)
{
    return g_apid.apid;
}

/*! Get the next TM counter value for the current PUS node */
asn1SccPusSequenceCount pusservices_getTmSequenceCount(void)
{
    return pus_getNextPacketCount(&g_apid);
}
