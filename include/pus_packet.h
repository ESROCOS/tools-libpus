/*! \file pus_packet.h
 *  \brief Functions for managing PUS TM/TC packets and their header information.
 *
 *  This module contains functions to initialize PUS packets, get and set the
 *  packet header fields, and verify the content of the headers.
 *
 *  Getter/setter and utility functions use the \ref pus_setError / \ref pus_getError
 *  mechanism for error reporting. Other functions return \ref pusError_t, but may also
 *  set error codes. The functions do not check error codes.
 *
 *  The packet fields are accessed through the getter/setter functions in order to
 *  be independent from the underlaying representation coming from the ASN.1 type
 *  definitions.
 *
 *  \author GMV
 */

#ifndef PUS_PACKET_H
#define PUS_PACKET_H

#include "pus_types.h"
#include "pus_error.h"


//
// Getters and setters
//

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

//! Getter for the PUS version number in TM secondary header
/*! Must be called for TM packet with secondary header
 */
pusVersion_t pus_getTmPusVersion(const pusPacket_t* packet);

//! Setter for the PUS version number in TM secondary header
/*! Must be called for TM packet with secondary header
 */
void pus_setTmPusVersion(pusPacket_t* packet, pusVersion_t version);

//! Getter for the PUS version number in TC secondary header
/*! Must be called for TC packet with secondary header
 */
pusVersion_t pus_getTcPusVersion(const pusPacket_t* packet);

//! Setter for the PUS version number in TC secondary header
/*! Must be called for TC packet with secondary header
 */
void pus_setTcPusVersion(pusPacket_t* packet, pusVersion_t version);

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

//! Getter for the TC service type
/*! Must be called for TC packet with secondary header
 */
pusService_t pus_getTcService(const pusPacket_t* packet);

//! Setter for the TC service type
/*! Must be called for TC packet with secondary header
 */
void pus_setTcService(pusPacket_t* packet, pusService_t service);

//! Getter for the TC service subtype
/*! Must be called for TC packet with secondary header
 */
pusSubservice_t pus_getTcSubtype(const pusPacket_t* packet);

//! Setter for the TC service subtype
/*! Must be called for TC packet with secondary header
 */
void pus_setTcSubtype(pusPacket_t* packet, pusService_t subtype);

//! Getter for the TM time reference status field
/*! Must be called for a TM packet with header
 */
pusTimeRefStatus_t pus_getTmTimeReferenceStatus(const pusPacket_t* packet);

//! Setter for the TM time reference status field
/*! Must be called for a TM packet with header
 */
void pus_setTmTimeReferenceStatus(pusPacket_t* packet, pusTimeRefStatus_t status);

//! Getter for the TM message type counter field
/*! Must be called for a TM packet with header
 */
pusMsgTypeCount_t pus_getTmMessageTypeCounter(const pusPacket_t* packet);

//! Setter for the TM message type counter field
/*! Must be called for a TM packet with header
 */
void pus_setTmMessageTypeCounter(pusPacket_t* packet, pusMsgTypeCount_t count);

//! Getter for the TM packet destination field
/*! Must be called for a TM packet with header
 */
pusApid_t pus_getTmDestination(const pusPacket_t* packet);

//! Setter for the TM packet destination field
/*! Must be called for a TM packet with header
 */
void pus_setTmDestination(pusPacket_t* packet, pusApid_t apid);

//! Getter for the TC packet source field
/*! Must be called for a TC packet with header
 */
pusApid_t pus_getTcSource(const pusPacket_t* packet);

//! Setter for the TC packet destination field
/*! Must be called for a TC packet with header
 */
void pus_setTcSource(pusPacket_t* packet, pusApid_t apid);

//! Getter for the TM packet time field
/*! Must be called for a TM packet with header
 * \param[out] outTime Address to write the time value
 */
void pus_getTmPacketTime(pusTime_t* outTime, const pusPacket_t* packet);

//! Setter for the TM packet time field
/*! Must be called for a TM packet with header
 * \param[in] time Address of the time value
 */
void pus_setTmPacketTime(pusPacket_t* packet, const pusTime_t* time);

//! Set the TM packet time field to now
/*! Must be called for a TM packet with header
 */
void pus_setTmPacketTimeNow(pusPacket_t* packet);

//! Getter for the TC packet acknowledgment flag for acceptance report
/*! Must be called for a TC packet with header
 */
bool pus_getTcAckFlagAcceptance(const pusPacket_t* packet);

//! Getter for the TC packet acknowledgment flag for start report
/*! Must be called for a TC packet with header
 */
bool pus_getTcAckFlagStart(const pusPacket_t* packet);

//! Getter for the TC packet acknowledgment flag for progress report
/*! Must be called for a TC packet with header
 */
bool pus_getTcAckFlagProgress(const pusPacket_t* packet);

//! Getter for the TC packet acknowledgment flag for completion report
/*! Must be called for a TC packet with header
 */
bool pus_getTcAckFlagCompletion(const pusPacket_t* packet);

//! Setter for the TC packet acknowledgment flags
/*! Must be called for a TC packet with header
 */
void pus_setTcAckFlags(pusPacket_t* packet, bool acceptance, bool start, bool progress, bool completion);


//
// Getters/setters for union types
//

//! Getter for the kind of packet data field
pusPacketDataKind_t pus_getPacketDataKind(const pusPacket_t* packet);

//! Setter for the packet data field according to the type of packet
void pus_setPacketDataKind(pusPacket_t* packet, pusPacketDataKind_t kind);

//! Getter for the kind of TM data field, for packets with secondary header
pusTmDataKind_t pus_getTmDataKind(const pusPacket_t* packet);

//! Setter for the kind of TM data field, for packets with secondary header
void pus_setTmDataKind(pusPacket_t* packet, pusPacketDataKind_t kind);

//! Getter for the kind of TM data field, for packets without secondary header
pusTmDataKind_t pus_getTmNoHeaderDataKind(const pusPacket_t* packet);

//! Setter for the kind of TM data field, for packets without secondary header
void pus_setTmNoHeaderDataKind(pusPacket_t* packet, pusPacketDataKind_t kind);


//
// Utility functions for packet types
//

//! Wrapping increment of packet sequence number
pusSequenceCount_t pus_incrementSequenceCount(pusSequenceCount_t count);

//! Set the TM packet time field to now
/*! Must be called for a TM packet with header
 */
void pus_setPacketTimeNow(pusPacket_t* packet);


//
// Packet initialisation
//

//! Set default values for a CCDS packet
pusError_t pus_setPacketDefaults(pusPacket_t* packet);

//! Initialize a TM packet
/*! Set default header fields and secondary header.
 *  Time report packets of ST[09], which have no secondary header, are
 *  excluded.
 */
pusError_t pus_initTmPacket(pusPacket_t* packet);

//! Initialize with defaults the packet header and secondary header of a TC packet
pusError_t pus_initTcPacket(pusPacket_t* packet);

//! Initialize a TM packet without secondary header
/*! E.g., for time report packets of ST[09]
 */
pusError_t pus_initTmPacketNoHeader(pusPacket_t* packet);

//! Initialize a TC packet without secondary header
pusError_t pus_initTcPacketNoHeader(pusPacket_t* packet);


//
// Packet verification
//

//! Verify the CCSDS header defaults
pusError_t pus_verifyCcsdsHeaderDefaults(const pusPacket_t* packet);

//! Check that the data kind matches the CCSDS header flags
pusError_t pus_verifyPacketDataKind(const pusPacket_t* packet);

//! Verify the secondary header defaults for a TM
pusError_t pus_verifyTmSecondaryHeaderDefaults(const pusPacket_t* packet);

//! Verify the secondary header defaults for a TC
pusError_t pus_checkTcSecondaryHeaderDefaults(const pusPacket_t* packet);

//! Verify the header defaults for a TM
/*! Includes check for CCSDS header defaults and packet data kind
 */
pusError_t pus_verifyTmHeaderDefaults(const pusPacket_t* packet);

//! Verify the header defaults for a TC
/*! Includes check for CCSDS header defaults and packet data kind
 */
pusError_t pus_verifyTcHeaderDefaults(const pusPacket_t* packet);


//
// Parameter checking
//

//! Check that a packet is a TM, and set error condition otherwise
/*! If packet is as expected, returns PUS_NO_ERROR; otherwise, sets error condition
 *  with pus_setError and returns the error code. Use with macros for convenience.
 *  \param[in] packet The packet to check
 *  \param[in] function Name of the function to log in case of error
 *  \param[in] data Data to log in case of error
 *  \return PUS_NO_ERROR if OK, or error code set otherwise
 */
pusError_t pus_expectTm(const pusPacket_t* packet, const char* funcname, pusErrorData_t data);

//! Check that a packet is a TM, and set error condition otherwise
/*! If packet is as expected, returns PUS_NO_ERROR; otherwise, sets error condition
 *  with pus_setError and returns the error code. Use with macros for convenience.
 *  \param[in] packet The packet to check
 *  \param[in] function Name of the function to log in case of error
 *  \param[in] data Data to log in case of error
 *  \return PUS_NO_ERROR if OK, or error code set otherwise
 */
pusError_t pus_expectTmHeader(const pusPacket_t* packet, const char* funcname, pusErrorData_t data);

//! Check that a packet is a TM, and set error condition otherwise
/*! If packet is as expected, returns PUS_NO_ERROR; otherwise, sets error condition
 *  with pus_setError and returns the error code. Use with macros for convenience.
 *  \param[in] packet The packet to check
 *  \param[in] function Name of the function to log in case of error
 *  \param[in] data Data to log in case of error
 *  \return PUS_NO_ERROR if OK, or error code set otherwise
 */
pusError_t pus_expectTmNoHeader(const pusPacket_t* packet, const char* funcname, pusErrorData_t data);

//! Check that a packet is a TM, and set error condition otherwise
/*! If packet is as expected, returns PUS_NO_ERROR; otherwise, sets error condition
 *  with pus_setError and returns the error code. Use with macros for convenience.
 *  \param[in] packet The packet to check
 *  \param[in] function Name of the function to log in case of error
 *  \param[in] data Data to log in case of error
 *  \return PUS_NO_ERROR if OK, or error code set otherwise
 */
pusError_t pus_expectTc(const pusPacket_t* packet, const char* funcname, pusErrorData_t data);

//! Check that a packet is a TM, and set error condition otherwise
/*! If packet is as expected, returns PUS_NO_ERROR; otherwise, sets error condition
 *  with pus_setError and returns the error code. Use with macros for convenience.
 *  \param[in] packet The packet to check
 *  \param[in] function Name of the function to log in case of error
 *  \param[in] data Data to log in case of error
 *  \return PUS_NO_ERROR if OK, or error code set otherwise
 */
pusError_t pus_expectTcHeader(const pusPacket_t* packet, const char* funcname, pusErrorData_t data);

//! Check that a packet is a TM, and set error condition otherwise
/*! If packet is as expected, returns PUS_NO_ERROR; otherwise, sets error condition
 *  with pus_setError and returns the error code. Use with macros for convenience.
 *  \param[in] packet The packet to check
 *  \param[in] function Name of the function to log in case of error
 *  \param[in] data Data to log in case of error
 *  \return PUS_NO_ERROR if OK, or error code set otherwise
 */
pusError_t pus_expectTcNoHeader(const pusPacket_t* packet, const char* funcname, pusErrorData_t data);

//! Helper macro for pus_expectTm; adds caller function's name
#define PUS_EXPECT_TM(packet) pus_expectTm((packet), __func__, (pusErrorData_t){.integer=0})

//! Helper macro for pus_expectTmHeader; adds caller function's name and data
#define PUS_EXPECT_TM_INT(packet, data) pus_expectTm((packet), __func__, (pusErrorData_t){.integer=(int32_t)(data)})

//! Helper macro for pus_expectTmHeader; adds caller function's name
#define PUS_EXPECT_TM_HEADER(packet) pus_expectTmHeader((packet), __func__, (pusErrorData_t){.integer=0})

//! Helper macro for pus_expectTmHeader; adds caller function's name
#define PUS_EXPECT_TM_HEADER_INT(packet, data) pus_expectTmHeader((packet), __func__, (pusErrorData_t){.integer=(int32_t)(data)})

//! Helper macro for pus_expectTmNoNoHeader; adds caller function's name
#define PUS_EXPECT_TM_NO_HEADER(packet) pus_expectTmNoHeader((packet), __func__, (pusErrorData_t){.integer=0})

//! Helper macro for pus_expectTmNoNoHeader; adds caller function's name
#define PUS_EXPECT_TM_NO_HEADER_INT(packet, data) pus_expectTmNoHeader((packet), __func__, (pusErrorData_t){.integer=(int32_t)(data)})

//! Helper macro for pus_expectTc; adds caller function's name
#define PUS_EXPECT_TC(packet) pus_expectTc((packet), __func__, (pusErrorData_t){.integer=0})

//! Helper macro for pus_expectTcHeader; adds caller function's name and data
#define PUS_EXPECT_TC_INT(packet, data) pus_expectTc((packet), __func__, (pusErrorData_t){.integer=(int32_t)(data)})

//! Helper macro for pus_expectTcHeader; adds caller function's name
#define PUS_EXPECT_TC_HEADER(packet) pus_expectTcHeader((packet), __func__, (pusErrorData_t){.integer=0})

//! Helper macro for pus_expectTcHeader; adds caller function's name
#define PUS_EXPECT_TC_HEADER_INT(packet, data) pus_expectTcHeader((packet), __func__, (pusErrorData_t){.integer=(int32_t)(data)})

//! Helper macro for pus_expectTcNoHeader; adds caller function's name
#define PUS_EXPECT_TC_NO_HEADER(packet) pus_expectTcNoHeader((packet), __func__, (pusErrorData_t){.integer=0})

//! Helper macro for pus_expectTcNoHeader; adds caller function's name
#define PUS_EXPECT_TC_NO_HEADER_INT(packet, data) pus_expectTcNoHeader((packet), __func__, (pusErrorData_t){.integer=(int32_t)(data)})

#endif // PUS_PACKET_H
