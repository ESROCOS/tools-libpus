/*! \file pus_notify.h
 *  \brief Auxiliary functions to the interface with PusConsole
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */
#ifndef PUS_NOTIFY_H
#define PUS_NOTIFY_H

#include "pus_types.h"
#include "pus_error.h"
#include "pus_threads.h"

#ifdef  __cplusplus
extern "C" {
#endif

pusPacket_t pus_notify_getPacket();

void pus_notify_setPacket(pusPacket_t* packet);

void pus_notify_getMutex(pusMutex_t *mutex);

void pus_notify_setMutex(pusMutex_t mutex);


#ifdef  __cplusplus
}
#endif

#endif
