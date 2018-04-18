/* This file was generated automatically: DO NOT MODIFY IT ! */

#include <stdlib.h>
#ifdef __unix__
#include <stdio.h>
#include "PrintTypesAsASN1.h"
#include "timeInMS.h"
#endif

#include "C_ASN1_Types.h"
#include "trigger_polyorb_interface.h"

void trigger_RI_tmTrigger()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: trigger,tmdispatch,tmTrigger,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_async_trigger_tmTrigger();

    vm_async_trigger_tmTrigger();

}

void trigger_RI_HkReportTrigger()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: trigger,st03,HkReportTrigger,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_async_trigger_HkReportTrigger();

    vm_async_trigger_HkReportTrigger();

}

void trigger_RI_PmonTrigger()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: trigger,st12,PmonTrigger,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_async_trigger_PmonTrigger();

    vm_async_trigger_PmonTrigger();

}

void trigger_RI_EventReportTrigger()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: trigger,st05,EventReportTrigger,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_async_trigger_EventReportTrigger();

    vm_async_trigger_EventReportTrigger();

}

void trigger_RI_tcTrigger()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: trigger,tcdispatch,tcTrigger,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_async_trigger_tcTrigger();

    vm_async_trigger_tcTrigger();

}

void trigger_RI_debugEventsTrigger()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: trigger,events,debugEventsTrigger,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_async_trigger_debugEventsTrigger();

    vm_async_trigger_debugEventsTrigger();

}

void trigger_RI_EventActionTrigger()
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: trigger,st19,EventActionTrigger,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Call to VM callback function */
    extern void vm_async_trigger_EventActionTrigger();

    vm_async_trigger_EventActionTrigger();

}

void trigger_RI_check_queue(asn1SccT_Boolean *OUT_res)
{
#ifdef __unix__
    static int innerMsc = -1;
    if (-1 == innerMsc)
        innerMsc = (NULL != getenv("TASTE_INNER_MSC"))?1:0;
    if (1 == innerMsc) {
        long long msc_time = getTimeInMilliseconds();

        printf ("\nINNER: trigger,x86_partition_taste_api,check_queue,%lld\n", msc_time);
        fflush(stdout);
    }
#endif


    /* Buffer(s) for the output parameter(s) */
    static char OUT_buf_res[sizeof(asn1SccT_Boolean)];
    int size_OUT_buf_res=0;

    /* Call to VM callback function */
    extern void vm_trigger_check_queue(void *, size_t *);

    vm_trigger_check_queue(OUT_buf_res, &size_OUT_buf_res);

    /* Decode each output parameter */
    if (0 != Decode_NATIVE_T_Boolean(OUT_res, OUT_buf_res, size_OUT_buf_res)) {
#ifdef __unix__
        printf("\nError Decoding T_Boolean\n");
#endif
        return;
    }

}

