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

//! Initialize the packet data field with no data (sets length=0 and data=NONE)
void pus_setPacketDataNone(pusPacket_t* packet);

//! Setter for the packet data field according to the type of packet
void pus_setPacketDataKind(pusPacket_t* packet, pusPacketDataKind_t kind);

//! Getter for the kind of packet data field
pusPacketDataKind_t pus_getPacketDataKind(const pusPacket_t* packet);

//! Getter for the PUS version number in secondary header
/*! Must be called only if there is a secondary header
 */
pusVersion_t pus_getPusVersion(const pusPacket_t* packet);

//! Setter for the PUS version number in secondary header
/*! Must be called only if there is a secondary header
 */
void pus_setPusVersion(pusPacket_t* packet, pusVersion_t version);

//! Getter for the TM service type
/*! Must be called for TM packet with secondary header
 */
pusService_t pus_getTmService(const pusPacket_t* packet);

//! Setter for the TM service type
/*! Must be called for TM packet with secondary header
 */
void pus_setTmService(pusPacket_t* packet, pusService_t service);

//! Getter for the TM service subtype
/*! Must be called for TM packet with secondary header
 */
pusSubservice_t pus_getTmSubtype(const pusPacket_t* packet);

//! Setter for the TM service subtype
/*! Must be called for TM packet with secondary header
 */
void pus_setTmSubtype(pusPacket_t* packet, pusService_t subtype);

//! Getter for the TM time reference status field
/*! Must be called for a TM packet with header
 */
pusTimeRefStatus_t pus_getTimeReferenceStatus(const pusPacket_t* packet);

//! Setter for the TM time reference status field
/*! Must be called for a TM packet with header
 */
void pus_setTimeReferenceStatus(pusPacket_t* packet, pusTimeRefStatus_t status);

//! Getter for the TM message type counter field
/*! Must be called for a TM packet with header
 */
pusMsgTypeCount_t pus_getMessageTypeCounter(const pusPacket_t* packet);

//! Setter for the TM message type counter field
/*! Must be called for a TM packet with header
 */
void pus_setMessageTypeCounter(pusPacket_t* packet, pusMsgTypeCount_t count);

//! Getter for the TM packet destination field
/*! Must be called for a TM packet with header
 */
pusApid_t pus_getDestination(const pusPacket_t* packet);

//! Setter for the TM packet destination field
/*! Must be called for a TM packet with header
 */
void pus_setDestination(pusPacket_t* packet, pusApid_t apid);

//! Getter for the TM packet time field
/*! Must be called for a TM packet with header
 * \param[out] outTime Address to write the time value
 */
void pus_getPacketTime(pusTime_t* outTime, const pusPacket_t* packet);

//! Setter for the TM packet time field
/*! Must be called for a TM packet with header
 * \param[in] time Address of the time value
 */
void pus_setPacketTime(pusPacket_t* packet, const pusTime_t* time);




// Utility functions for packet types

//! Wrapping increment of packet sequence number
pusSequenceCount_t pus_incrementSequenceCount(pusSequenceCount_t count);

//! Set the TM packet time field to now
/*! Must be called for a TM packet with header
 */
void pus_setPacketTimeNow(pusPacket_t* packet);



// Packet initialisation

//! Set default values for a CCDS packet
void pus_setPacketDefaults(pusPacket_t* packet);

//! Initialize a TM packet
/*! Set default header fields and secondary header.
 *  Time report packets of ST[09], which have no secondary header, are
 *  excluded.
 */
void pus_initTmPacket(pusPacket_t* packet);



#endif // PUS_PACKET_H
