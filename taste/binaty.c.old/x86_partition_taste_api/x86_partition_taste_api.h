/* TASTE API */
/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef __AUTO_CODE_H_x86_partition_taste_api__
#define __AUTO_CODE_H_x86_partition_taste_api__

#include "C_ASN1_Types.h"
#ifdef __cplusplus
    extern "C" {
#endif

#ifdef __unix__
    #include <stdbool.h>
    #include <stdlib.h>
    static bool debugCheckQ = false;
#endif

void x86_partition_taste_api_startup();

void x86_partition_taste_api_PI_ground_has_pending_msg(asn1SccT_Boolean *res);

void x86_partition_taste_api_PI_tcqueue_has_pending_msg(asn1SccT_Boolean *res);

void x86_partition_taste_api_PI_tcdispatch_has_pending_msg(asn1SccT_Boolean *res);

void x86_partition_taste_api_PI_tmdispatch_has_pending_msg(asn1SccT_Boolean *res);

void x86_partition_taste_api_PI_events_has_pending_msg(asn1SccT_Boolean *res);

void x86_partition_taste_api_PI_st05_has_pending_msg(asn1SccT_Boolean *res);

void x86_partition_taste_api_PI_st19_has_pending_msg(asn1SccT_Boolean *res);

void x86_partition_taste_api_PI_st03_has_pending_msg(asn1SccT_Boolean *res);

void x86_partition_taste_api_PI_st12_has_pending_msg(asn1SccT_Boolean *res);

void x86_partition_taste_api_PI_trigger_has_pending_msg(asn1SccT_Boolean *res);

void x86_partition_taste_api_PI_onboardsoftware_has_pending_msg(asn1SccT_Boolean *res);

#ifdef __cplusplus
}
#endif

#endif