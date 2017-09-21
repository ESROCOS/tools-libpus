#ifndef PUS_TYPES_H
#define PUS_TYPES_H

#include <stdint.h>

#include "asn1/ccsds_packet.h"

// Create aliases for the generated PUS types

typedef asn1SccPusPacket pusPacket_t;   //!< Type of CCSDS packets


// Aliases for enum values
extern const asn1SccPusPacketType pusTm;
extern const asn1SccPusPacketType pusTc;

extern const asn1SccPusSequenceFlags pusStandalonePacket;



// Error type and codes

typedef uint32_t pus_result_t;

#define PUS_SUCCESS     ((pus_result_t)  0)
#define PUS_FAIL        ((pus_result_t)  1)
#define PUS_NULLPTR     ((pus_result_t)  2)

#endif //PUS_TYPES_H

