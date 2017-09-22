#ifndef PUS_PACKET_H
#define PUS_PACKET_H

#include "pus_types.h"

// Getters and setters

//! Getter for packet version in CCSDS packet header
pusPacketVersion_t pus_getPacketVersion(const pusPacket_t* packet);

//! Setter for packet version in CCSDS packet header
void pus_setPacketVersion(pusPacket_t* packet, pusPacketVersion_t version);

//! Getter for packet type (TM, TC) in CCSDS packet header
pusPacketType_t pus_getPacketType(const pusPacket_t* packet);

//! Setter for packet type (TM, TC) in CCSDS packet header
void pus_setPacketType(pusPacket_t* packet, pusPacketType_t type);

//! Getter for APID in CCSDS packet header
pusApid_t pus_getApid(const pusPacket_t* packet);

//! Setter for APID in CCSDS packet header
void pus_setApid(pusPacket_t* packet, pusApid_t apid);

//! Getter for secondary header flag in CCSDS packet header
bool pus_getSecondaryHeaderFlag(const pusPacket_t* packet);

//! Setter for secondary header flag in CCSDS packet header
void pus_setSecondaryHeaderFlag(pusPacket_t* packet, bool hasIt);

//! Getter for sequence flags in CCSDS packet header
pusSequenceFlags_t pus_getSequenceFlags(const pusPacket_t* packet);

//! Setter for sequence flags in CCSDS packet header
void pus_setSequenceFlags(pusPacket_t* packet, pusSequenceFlags_t flags);

//! Getter for sequence count in CCSDS packet header
pusSequenceCount_t pus_getSequenceCount(const pusPacket_t* packet);

//! Setter for sequence count in CCSDS packet header
/*! \param[in] count Count value, should fit in 14 bits
 *  \return The count set (may wrap arround)
 */
pusSequenceCount_t pus_setSequenceCount(pusPacket_t* packet, pusSequenceCount_t count);

//! Getter for data length in CCSDS packet header
pusPacketDataLength_t pus_getPacketDataLength(const pusPacket_t* packet);

//! Setter for data length in CCSDS packet header
/*! \param[in] length Length of the data, it's an uint16_t
 */
void pus_setPacketDataLength(pusPacket_t* packet, pusPacketDataLength_t length);



// Utility functions for packet types

//! Wrapping increment of packet sequence number
pusSequenceCount_t pus_incrementSequenceCount(pusSequenceCount_t count);


// Packet initialisation

//! Set default values for a CCDS packet
void pus_setPacketDefaults(pusPacket_t* packet);




#endif // PUS_PACKET_H
