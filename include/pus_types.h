#ifndef PUS_TYPES_H
#define PUS_TYPES_H

#include <stdint.h>
#include <stdbool.h>

#include "asn1/ccsds_packet.h"

// Create aliases for the generated PUS types

typedef asn1SccPusPacket pusPacket_t;   //!< Type of CCSDS packets
typedef asn1SccPusPacketVersion pusPacketVersion_t; //!< Type of CCSDS packet version
typedef asn1SccPusPacketType pusPacketType_t; //!< Type of CCSDS packet type (TM, TC)
typedef asn1SccPusApid pusApid_t; //!< Type of CCSDS packet APID
typedef asn1SccPusSequenceFlags pusSequenceFlags_t; //!< Type of CCSDS packet sequence flags
typedef asn1SccPusSequenceCount pusSequenceCount_t; //!< Type of CCSDS packet sequence flags
typedef uint16_t pusPacketDataLength_t; //!< Type of CCSDS packet data length; use directly uint16_t to enforce limit
typedef asn1SccPusVersionNumber pusVersion_t; //!< Type of the PUS version number
typedef asn1SccPusServiceType pusService_t; //!< Type of the PUS service type
typedef asn1SccPusSubserviceType pusSubservice_t; //!< Type of the PUS subservice type



// Aliases for enum values
extern const pusPacketType_t pus_TM;
extern const pusPacketType_t pus_TC;

extern const pusSequenceFlags_t pus_STANDALONE_PACKET;

extern const pusVersion_t pus_V2;
extern const pusVersion_t pus_INVALID_VERSION;


// Type limits
#define pusUInt3_LIMIT  ((const unsigned int) 8)
#define pusUInt4_LIMIT  ((const unsigned int) 16)
#define pusUInt8_LIMIT  ((const unsigned int) 256)
#define pusUInt11_LIMIT ((const unsigned int) 2048)
#define pusUInt14_LIMIT ((const unsigned int) 16384)
#define pusUInt16_LIMIT ((const unsigned int) 65536)

#define pusSequenceCount_LIMIT pusUInt14_LIMIT
#define pusPacketDataLenght_LIMIT pusUInt16_LIMIT


// Error type and codes

//! Type for the result of PUS library operations
typedef enum
{
    PUS_SUCCESS = 0,
    PUS_FAIL,
    
    // Limit
    PUS_LAST_RESULT
} pusResult_t;





// Supporting types for unions

//! Possible types of data in a CCSDS packet
typedef enum
{
    pus_PACKET_DATA_NONE = 0,
    pus_TM_DATA,
    pus_TM_DATA_NO_HEADER,
    pus_TC_DATA,
    pus_TC_DATA_NO_HEADER,
    
    // Limit
    pus_PACKET_DATA_LAST
} pusPacketDataKind_t;



#endif //PUS_TYPES_H

