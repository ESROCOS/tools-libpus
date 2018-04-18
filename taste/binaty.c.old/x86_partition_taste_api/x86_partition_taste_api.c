/* TASTE API */
/* This file was generated automatically: DO NOT MODIFY IT ! */

#include <deployment.h>

#include "x86_partition_taste_api.h"

extern int __po_hi_gqueue_get_count(int, int);

#ifdef __unix__
    #include <stdio.h>
#endif

void x86_partition_taste_api_startup()
{
    /* TASTE API start up */
    #ifdef __unix__
        debugCheckQ = getenv("CHECKQ_DEBUG");
    #endif
}

void x86_partition_taste_api_PI_ground_has_pending_msg(asn1SccT_Boolean *res) {
    /* Check all incoming queues (if any) for a pending message */
    *res = 0;
    if (__po_hi_gqueue_get_count(x86_partition_vt_ground_newtm_k, vt_ground_newtm_local_inport_artificial_newtm)) {
        *res = 1;
        #ifdef __unix__
            if (debugCheckQ) {
                printf ("[DEBUG] Pending message newTm in function ground\n");
            }
        #endif
    }
}

void x86_partition_taste_api_PI_tcqueue_has_pending_msg(asn1SccT_Boolean *res) {
    /* Check all incoming queues (if any) for a pending message */
    *res = 0;
    if (__po_hi_gqueue_get_count(x86_partition_vt_tcqueue_newtc_k, vt_tcqueue_newtc_local_inport_artificial_newtc)) {
        *res = 1;
        #ifdef __unix__
            if (debugCheckQ) {
                printf ("[DEBUG] Pending message newTc in function tcqueue\n");
            }
        #endif
    }
}

void x86_partition_taste_api_PI_tcdispatch_has_pending_msg(asn1SccT_Boolean *res) {
    /* Check all incoming queues (if any) for a pending message */
    *res = 0;
    if (__po_hi_gqueue_get_count(x86_partition_tcdispatch_k, tcdispatch_local_inport_tctrigger)) {
        *res = 1;
        #ifdef __unix__
            if (debugCheckQ) {
                printf ("[DEBUG] Pending message tcTrigger in function tcdispatch\n");
            }
        #endif
    }
}

void x86_partition_taste_api_PI_tmdispatch_has_pending_msg(asn1SccT_Boolean *res) {
    /* Check all incoming queues (if any) for a pending message */
    *res = 0;
    if (__po_hi_gqueue_get_count(x86_partition_tmdispatch_k, tmdispatch_local_inport_tmtrigger)) {
        *res = 1;
        #ifdef __unix__
            if (debugCheckQ) {
                printf ("[DEBUG] Pending message tmTrigger in function tmdispatch\n");
            }
        #endif
    }
}

void x86_partition_taste_api_PI_events_has_pending_msg(asn1SccT_Boolean *res) {
    /* Check all incoming queues (if any) for a pending message */
    *res = 0;
    if (__po_hi_gqueue_get_count(x86_partition_vt_events_debugeventstrigger_k, vt_events_debugeventstrigger_local_inport_artificial_debugeventstrigger)) {
        *res = 1;
        #ifdef __unix__
            if (debugCheckQ) {
                printf ("[DEBUG] Pending message debugEventsTrigger in function events\n");
            }
        #endif
    }
}

void x86_partition_taste_api_PI_st05_has_pending_msg(asn1SccT_Boolean *res) {
    /* Check all incoming queues (if any) for a pending message */
    *res = 0;
    if (__po_hi_gqueue_get_count(x86_partition_st05_k, st05_local_inport_eventreporttrigger)) {
        *res = 1;
        #ifdef __unix__
            if (debugCheckQ) {
                printf ("[DEBUG] Pending message EventReportTrigger in function st05\n");
            }
        #endif
    }
}

void x86_partition_taste_api_PI_st19_has_pending_msg(asn1SccT_Boolean *res) {
    /* Check all incoming queues (if any) for a pending message */
    *res = 0;
    if (__po_hi_gqueue_get_count(x86_partition_vt_st19_eventactiontrigger_k, vt_st19_eventactiontrigger_local_inport_artificial_eventactiontrigger)) {
        *res = 1;
        #ifdef __unix__
            if (debugCheckQ) {
                printf ("[DEBUG] Pending message EventActionTrigger in function st19\n");
            }
        #endif
    }
}

void x86_partition_taste_api_PI_st03_has_pending_msg(asn1SccT_Boolean *res) {
    /* Check all incoming queues (if any) for a pending message */
    *res = 0;
    if (__po_hi_gqueue_get_count(x86_partition_st03_k, st03_local_inport_hkreporttrigger)) {
        *res = 1;
        #ifdef __unix__
            if (debugCheckQ) {
                printf ("[DEBUG] Pending message HkReportTrigger in function st03\n");
            }
        #endif
    }
}

void x86_partition_taste_api_PI_st12_has_pending_msg(asn1SccT_Boolean *res) {
    /* Check all incoming queues (if any) for a pending message */
    *res = 0;
    if (__po_hi_gqueue_get_count(x86_partition_vt_st12_pmontrigger_k, vt_st12_pmontrigger_local_inport_artificial_pmontrigger)) {
        *res = 1;
        #ifdef __unix__
            if (debugCheckQ) {
                printf ("[DEBUG] Pending message PmonTrigger in function st12\n");
            }
        #endif
    }
}

void x86_partition_taste_api_PI_trigger_has_pending_msg(asn1SccT_Boolean *res) {
    /* Check all incoming queues (if any) for a pending message */
}

void x86_partition_taste_api_PI_onboardsoftware_has_pending_msg(asn1SccT_Boolean *res) {
    /* Check all incoming queues (if any) for a pending message */
}

