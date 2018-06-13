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
#include "pus_packet.h"
#include "pus_threads.h"
#include "pus_packet_queues.h"


#ifdef  __cplusplus
extern "C" {
#endif

//! Initializes the queue and the related mutex.
/*! Initializes a queue of tm packets to be red from
 *  pus console and to be written from taste. To guarantee
 *  mutual exclusion a mutex is also initialized.
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_notify_initialize();

//! Destroys mutex.
/*!
 * \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_notify_finalize();

//! Write a packet into its queue
/*! Push a packet into its queue checking if it is possible and blocks
 *  the process waiting for the mutex.
 *  \param[in] packet Packet that is going to be pushed
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_notify_writeTm(const pusPacket_t *packet);

//! Pop packet from its queue
/*! Pop packet from its queue checking if it is possible
 * 	\param[out] outPacket Packet that is going to be popped
 * 	\param queue Queue where the packet is going to be popped
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_notify_readTm(pusPacket_t *packet);

//! Write a packet into its queue
/*! Push a packet into its queue checking if it is possible and blocks
 *  the process waiting for the mutex.
 *  \param[in] packet Packet that is going to be pushed
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_notify_writeTc(const pusPacket_t *packet);

//! Pop packet from its queue
/*! Pop packet from its queue checking if it is possible
 * 	\param[out] outPacket Packet that is going to be popped
 * 	\param queue Queue where the packet is going to be popped
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_notify_readTc(pusPacket_t *packet);

// Retrieves the number of packets in the queue
/*!
 * \return Number of packets in queue.
 */
size_t pus_notify_getTmQueueNumPackets();

pusError_t pus_notify_sendPacket(const pusPacket_t *packet);

//void set_fun_pointer(void (*sending_interface_)(pusPacket_t *));

#ifdef  __cplusplus
}
#endif

#endif
