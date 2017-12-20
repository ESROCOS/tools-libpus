/*! \file pus_packet_reduced.h
 *  \brief PacketReduced functions.
 *
 * TODO
 *
 *  \author GMV
 */


#ifndef PUS_PACKET_REDUCED_H
#define PUS_PACKET_REDUCED_H


#include "pus_types.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_apid.h"

#ifdef  __cplusplus
extern "C" {
#endif



//! Create a pusPacketReduced from a pusPacket
/*! Set parameters to a pusPacketReduced from a pusPacket
 *  \param[out] outTcR PacketReduced that is going to be created
 *  \param[in] inTc Packet to get parameters for PacketReduced.
 */
pusError_t pus_packetReduced_createPacketReducedFromPacket(pusPacketReduced_t* outTcR, pusPacket_t* inTc);

//! Create a Packet from a packetReduced
/*! Set parameters to a pusPacketReduced from a pusPacket
 *  \param[out] outTc Packet that is going to be created
 *  \param[in] inTcR PacketReduced to get parameters for Packet.
 */
pusError_t pus_packetReduced_createPacketFromPacketReduced(pusPacket_t* outTc, pusPacketReduced_t* inTcR);

//! Function that set the tcData field from a pusPacket_t to a pusPacketReduced_t
pusError_t pus_packetReduced_setDataFromPacketToPacketReduced(pusPacketReduced_t* outPacket, pusPacket_t* inTc);

//! Function that set the tcData field from a pusPacketReduced_t to a pusPacket_t
pusError_t pus_packetReduced_setDataFromPacketReducedToPacket(pusPacket_t* outTc, pusPacketReduced_t* inTcR);

#ifdef  __cplusplus
}
#endif

#endif
