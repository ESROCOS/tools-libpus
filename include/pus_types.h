/*! \file pus_types.h
 *  \brief Types used in the PUS packet data structures.
 *
 *  The structure of the packets is defined by the ASN.1 types. This module provides
 *  wrapper types and supporting definitions for convenience. In addition, these
 *  types provide some independence from the underlaying representation.
 *
 *  \author GMV
 */

#ifndef PUS_TYPES_H
#define PUS_TYPES_H

#include <stdint.h>
#include <stdbool.h>

// to prevent redefinition of types when it is used whith taste (dataview_unique.h)
#ifndef GENERATED_ASN1SCC_DATAVIEW_UNIQ_H
#include "asn1/ccsds_packet.h"
#include "asn1/pus_config.h"
#include "asn1/pus_st01.h"
#include "asn1/pus_st03.h"
#include "asn1/pus_st05.h"
#include "asn1/pus_st08.h"
#include "asn1/pus_st09.h"
#include "asn1/pus_st12.h"
#include "asn1/pus_st19.h"
#include "asn1/pus_st20.h"
#include "asn1/pus_services.h"
#endif

#ifdef  __cplusplus
extern "C" {
#endif
//
// Aliases for the generated PUS types
//

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
typedef asn1SccPusTimeReferenceStatus pusTimeRefStatus_t; //!< Type of the TM time reference status field
typedef asn1SccPusMessageTypeCounter pusMsgTypeCount_t; //!< Type of the TM message type counter filed
typedef asn1SccPusTime pusTime_t; //!< Type of the TM packet time field
typedef asn1SccPusAcknowledgementFlags pusAckFlags_t; //!< Type of the TC packet acknowledgment flags
typedef asn1SccPusPacketData pusPacketData_t; //!< Type of the CCSDS packet data section
typedef asn1SccPusSt01Failure pusSt01Failure_t; //!< Type of the failure code and information in ST[01] reports
typedef asn1SccPusSt01FailureCode pusSt01FailureCode_t; //!< Type of the failure code in ST[01] reports
typedef asn1SccPusSt01FailureInfo pusSt01FailureInfo_t; //!< Type of the failure information in ST[01] reports
typedef asn1SccPusStepId pusStepId_t; //!< Type of procedure steps
typedef asn1SccPusInt32 pusInt32_t; //!< Type of int32 fields
typedef asn1SccPusMemAddr pusMemAddr_t; //!< Type of memory address fields
typedef asn1SccPusSt03HousekeepingReportId pusSt03HousekeepingReportId_t; //!< Type of the ST[03] housekeeping report identifier field
typedef asn1SccPusSt03ParameterId pusSt03ParamId_t; //!< Type of the ST[03] parameter identifiers

typedef asn1SccPusSt05Event pusSt05Event_t; //!< Type of the ST[05] event with data
typedef asn1SccPusSt05EventId pusSt05EventId_t; //!< Type of the ST[05] event ID
typedef asn1SccPusSt05EventAuxData pusSt05EventAuxData_t; //!< Type of the ST[05] event AuxData

typedef asn1SccPusSt08FunctionId pusSt08FunctiontId_t; //!< Type of the ST[08] function ID

typedef asn1SccPusPacketReduced pusPacketReduced_t; //!< Packet reduced

typedef asn1SccPusSt12pmonId pusSt12PmonId_t; //!< Pmon ID
typedef asn1SccPusSt09ExponentialRate pusSt09ExponentialRate_t; //!< report generation exponential rate

typedef asn1SccPusTcScheduledActivity pusSt11ScheduledActivity_t;

typedef asn1SccPusSt03StoredParam pusStoredParam_t;

typedef asn1SccPusSt20OnBoardParameterId pusSt20OnBoardParamId_t;


// Types for union discriminants; using GCC extension typeof to alias an anonymous enum type
#ifdef __cplusplus
typedef decltype(asn1SccPusPacketData::PusPacketData_NONE) pusPacketDataKind_t; //!< Type of the union discriminant for asn1SccPusPacketData
typedef decltype(asn1SccPusTmSourceData::PusTmSourceData_NONE) pusTmDataKind_t; //!< Type of the union discriminant for asn1SccPusTmSourceData
typedef decltype(asn1SccPusTcApplicationData::PusTcApplicationData_NONE) pusTcDataKind_t;  //!< Type of the union discriminant for asn1SccPusTcApplicationData
#else
typedef __typeof__(PusPacketData_NONE) pusPacketDataKind_t; //!< Type of the union discriminant for asn1SccPusPacketData
typedef __typeof__(PusTmSourceData_NONE) pusTmDataKind_t; //!< Type of the union discriminant for asn1SccPusTmSourceData
typedef __typeof__(PusTcApplicationData_NONE) pusTcDataKind_t;  //!< Type of the union discriminant for asn1SccPusTcApplicationData
#endif


//
// Aliases for enum and union values
//

// pusPacketType_t
#define pus_TM ((pusPacketType_t) asn1Sccpus_TM)
#define pus_TC ((pusPacketType_t) asn1Sccpus_TC)

// pusSequenceFlags_t
#define pus_STANDALONE_PACKET ((pusSequenceFlags_t) asn1Sccpus_STANDALONE_PACKET)

// pusVersion_t
#define pus_V2 				((pusVersion_t) asn1Sccpus_V2)
#define pus_INVALID_VERSION ((pusVersion_t) asn1Sccpus_INVALID_VERSION)

// packetDataKind_t
#define pus_PACKET_DATA_NONE 	((pusPacketDataKind_t) PusPacketData_NONE)
#define pus_TM_DATA 			((pusPacketDataKind_t) PusPacketData_tmData_PRESENT)
#define pus_TM_DATA_NO_HEADER 	((pusPacketDataKind_t) PusPacketData_tmDataNoHeader_PRESENT)
#define pus_TC_DATA 			((pusPacketDataKind_t) PusPacketData_tcData_PRESENT)
#define pus_TC_DATA_NO_HEADER 	((pusPacketDataKind_t) PusPacketData_tcDataNoHeader_PRESENT)

// pusPacketTmDataKind_t
#define pus_TM_DATA_NONE 		((pusTmDataKind_t) PusTmSourceData_NONE)
#define pus_TM_DATA_ST_1_X		((pusTmDataKind_t) st_1_X_PRESENT)
#define pus_TM_DATA_ST_3_25		((pusTmDataKind_t) st_3_25_PRESENT)
#define pus_TM_DATA_ST_5_X		((pusTmDataKind_t) st_5_X_PRESENT)
#define pus_TM_DATA_ST_9_2		((pusTmDataKind_t) st_9_2_PRESENT)
#define pus_TM_DATA_ST_20_2		((pusTmDataKind_t) st_20_2_PRESENT)



// pusPacketTcDataKind_t
#define pus_TC_DATA_NONE 		((pusTcDataKind_t) PusTcApplicationData_NONE)
#define pus_TC_DATA_ST_8_1 		((pusTcDataKind_t) PusTcApplicationData_st_8_1_PRESENT)
#define pus_TC_DATA_ST_9_1		((pusTcDataKind_t) PusTcApplicationData_st_9_1_PRESENT)
#define pus_TC_DATA_ST_11_4		((pusTcDataKind_t) st_11_4_PRESENT)
#define pus_TC_DATA_ST_12_1_2	((pusTcDataKind_t) PusTcApplicationData_st_12_1_2_PRESENT)
#define pus_TC_DATA_ST_19_1		((pusTcDataKind_t) st_19_1_PRESENT)
#define pus_TC_DATA_ST_19_X		((pusTcDataKind_t) PusTcApplicationData_st_19_X_PRESENT)
#define pus_TC_DATA_ST_20_X		((pusTcDataKind_t) PusTcApplicationData_st_20_X_PRESENT)


//
// Type limits
//
#define pusUInt3_LIMIT  ((const unsigned int) 8)
#define pusUInt4_LIMIT  ((const unsigned int) 16)
#define pusUInt8_LIMIT  ((const unsigned int) 256)
#define pusUInt11_LIMIT ((const unsigned int) 2048)
#define pusUInt14_LIMIT ((const unsigned int) 16384)
#define pusUInt16_LIMIT ((const unsigned int) 65536)

//! First value not representable by the pusSequenceCount_t type
#define pusSequenceCount_LIMIT pusUInt14_LIMIT

//! First value not representable by the pusPacketDataLength_t type
#define pusPacketDataLength_LIMIT pusUInt16_LIMIT

#ifdef  __cplusplus
}
#endif

#endif //PUS_TYPES_H

