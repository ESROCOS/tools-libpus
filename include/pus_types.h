/*! \file pus_types.h
 *  \brief Types used in the PUS packet data structures.
 *
 *  The structure of the packets is defined by the ASN.1 types. This module provides
 *  wrapper types and supporting definitions for convenience. In addition, these
 *  types provide some independence from the underlaying representation.
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_TYPES_H
#define PUS_TYPES_H

#include "pus_enable_services.h"

#if (defined(PUS_CONFIGURE_ST05_ENABLED) || defined(PUS_CONFIGURE_ST18_ENABLED) || defined(PUS_CONFIGURE_ST19_ENABLED) ) && !defined( PUS_CONFIGURE_EVENTS_TABLE )
#error "Any service need events-table but it is not enabled!"
#endif

#if (defined(PUS_CONFIGURE_ST03_ENABLED) || defined(PUS_CONFIGURE_ST12_ENABLED) || defined(PUS_CONFIGURE_ST18_ENABLED) ) && !defined( PUS_CONFIGURE_HK_PARAMS_TABLE )
#error "Any service need Hk parameters table but it is not enabled!"
#endif

#if (defined(PUS_CONFIGURE_ST18_ENABLED) || defined(PUS_CONFIGURE_ST20_ENABLED) ) && !defined( PUS_CONFIGURE_ONBOARD_PARAMS_TABLE )
#error "Any service need on-board parameters table but it is not enabled!"
#endif

#if (defined(PUS_CONFIGURE_ST18_ENABLED)  && !defined( PUS_CONFIGURE_OBCP_ENGINE ))
#error "Any service need OBCP-engine table but it is not enabled!"
#endif


#include <stdint.h>
#include <stdbool.h>

// to prevent redefinition of types when it is used with taste (dataview_unique.h)
#if(!defined(GENERATED_ASN1SCC_DATAVIEW_UNIQ_H) && !defined(GENERATED_ASN1SCC_dataview_uniq_H))
#include "ccsds_packet.h"
#include "ccsds_packet_fields.h"
#include "pus_config.h"
#include "pus_st01.h"
#include "pus_st03.h"
#include "pus_st05.h"
#include "pus_st08.h"
#include "pus_st09.h"
#include "pus_st12.h"
#include "pus_st18.h"
#include "pus_st19.h"
#include "pus_st20.h"
#include "pus_st23.h"
#include "pus_services.h"
#endif

#include "pus_mission_types.h"

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
typedef asn1SccPusSt03StoredParam pusStoredParam_t; //!< Stored param for all packets' services
typedef asn1SccPusPacketReduced pusPacketReduced_t; //!< Packet reduced


typedef asn1SccPusSt05Event pusSt05Event_t; //!< Type of the ST[05] event with data
typedef asn1SccPusSt05EventId pusSt05EventId_t; //!< Type of the ST[05] event ID
typedef asn1SccPusSt05EventAuxData pusSt05EventAuxData_t; //!< Type of the ST[05] event AuxData

typedef asn1SccPusSt08FunctionId pusSt08FunctiontId_t; //!< Type of the ST[08] function ID

typedef asn1SccPusSt09ExponentialRate pusSt09ExponentialRate_t; //!< Report generation exponential rate

typedef asn1SccPusTcScheduledActivity pusSt11ScheduledActivity_t; //!< Scheduled activity for st11; time and action

typedef asn1SccPusSt12pmonId pusSt12PmonId_t; //!< Pmon definition identifier

typedef asn1SccPusSt18ObcpId pusSt18ObcpId_t; //! Obcp procedure identifier
typedef asn1SccPusSt18ObcpCode pusSt18ObcpCode_t; //! Obcp procedure code
typedef asn1SccPusSt18ObcpChecksum pusSt18ObcpChecksum_t; //! Obcp procedure checksum
typedef asn1SccPusSt18ObservabilityLevel pusSt18ObservabilityLevel_t; //! Obcp observability level
typedef asn1SccPusUInt32 pusSt18ObcpStepId_t; //! OBCP step id
typedef asn1SccPusUInt32 pusSt18ObcpStatus_t; //! OBCP status
typedef asn1SccPusUInt32 pusSt18ObcpConfirmationStatus_t; //! OBCP status


typedef asn1SccPusSt20OnBoardParameterId pusSt20OnBoardParamId_t; //!< Identifier of on-board parameters

typedef asn1SccPusSt23RepositoryPath pusSt23RepositoryPath_t; //!< Repository path of a file
typedef asn1SccPusSt23FileName pusSt23FileName_t; //!< File name
typedef asn1SccPusUInt64 pusSt23MaximumSize_t; //!< Maximum size of files
typedef asn1SccPusUInt32 pusSt23FilesTableSize_t; //!< Maximum size of table files
typedef asn1SccPusSt23RepositoryDomain pusSt23RepositoryDomain_t; //!< Repository domain
typedef asn1SccPusSt23RepositoryDomain pusSt23RepositorySystem_t; //!< Repository domain
typedef asn1SccPusUInt32 pusSt23RepositoryId_t; //! RepositoryId

typedef asn1SccPusUInt64 pusPacketQueueId_t;




// Types for union discriminants; using GCC extension typeof to alias an anonymous enum type
#ifdef __cplusplus
typedef decltype(asn1SccPusPacketData_selection::PusPacketData_NONE) pusPacketDataKind_t; //!< Type of the union discriminant for asn1SccPusPacketData
typedef decltype(asn1SccPusTmSourceData_selection::PusTmSourceData_NONE) pusTmDataKind_t; //!< Type of the union discriminant for asn1SccPusTmSourceData
typedef decltype(asn1SccPusTcApplicationData_selection::PusTcApplicationData_NONE) pusTcDataKind_t;  //!< Type of the union discriminant for asn1SccPusTcApplicationData
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
#define pus_TM_DATA_NONE 		((pusTmDataKind_t) PusTmSourceData_st_0_0_PRESENT)
#define pus_TM_DATA_ST_1_X		((pusTmDataKind_t) st_1_X_PRESENT)
#define pus_TM_DATA_ST_3_25		((pusTmDataKind_t) st_3_25_PRESENT)
#define pus_TM_DATA_ST_5_X		((pusTmDataKind_t) st_5_X_PRESENT)
#define pus_TM_DATA_ST_9_2		((pusTmDataKind_t) st_9_2_PRESENT)
#define pus_TM_DATA_ST_20_2		((pusTmDataKind_t) st_20_2_PRESENT)
#define pus_TM_DATA_ST_23_4		((pusTmDataKind_t) st_23_4_PRESENT)


// pusPacketTcDataKind_t
#define pus_TC_DATA_NONE 		((pusTcDataKind_t) PusTcApplicationData_st_0_0_PRESENT)
#define pus_TC_DATA_ST_3_5 		((pusTcDataKind_t) PusTcApplicationData_st_3_5_PRESENT)
#define pus_TC_DATA_ST_3_6 		((pusTcDataKind_t) PusTcApplicationData_st_3_6_PRESENT)
#define pus_TC_DATA_ST_8_1 		((pusTcDataKind_t) PusTcApplicationData_st_8_1_PRESENT)
#define pus_TC_DATA_ST_9_1		((pusTcDataKind_t) PusTcApplicationData_st_9_1_PRESENT)
#define pus_TC_DATA_ST_11_4		((pusTcDataKind_t) st_11_4_PRESENT)
#define pus_TC_DATA_ST_12_1_2	((pusTcDataKind_t) PusTcApplicationData_st_12_1_2_PRESENT)
#define pus_TC_DATA_ST_18_1		((pusTcDataKind_t) st_18_1_PRESENT)
#define pus_TC_DATA_ST_18_2_6_12 ((pusTcDataKind_t) PusTcApplicationData_st_18_2_6_12_PRESENT)
#define pus_TC_DATA_ST_18_3		((pusTcDataKind_t) PusTcApplicationData_st_18_3_PRESENT)
#define pus_TC_DATA_ST_18_4_5	((pusTcDataKind_t) PusTcApplicationData_st_18_4_5_PRESENT)
#define pus_TC_DATA_ST_18_13	((pusTcDataKind_t) PusTcApplicationData_st_18_13_PRESENT)
#define pus_TC_DATA_ST_19_1		((pusTcDataKind_t) st_19_1_PRESENT)
#define pus_TC_DATA_ST_19_X		((pusTcDataKind_t) PusTcApplicationData_st_19_X_PRESENT)
#define pus_TC_DATA_ST_20_X		((pusTcDataKind_t) PusTcApplicationData_st_20_X_PRESENT)
#define pus_TC_DATA_ST_23_1		((pusTcDataKind_t) PusTcApplicationData_st_23_1_PRESENT)
#define pus_TC_DATA_ST_23_2_3	((pusTcDataKind_t) PusTcApplicationData_st_23_2_3_PRESENT)
#define pus_TC_DATA_ST_23_14	((pusTcDataKind_t) PusTcApplicationData_st_23_14_PRESENT)


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

#define pus_ST18_SIZE_OBCP_ID pus_ST18_SIZE_OBCP_ID

#define pus_ST18_MAX_SIZE_OBCP_CODE pus_ST18_MAX_SIZE_OBCP_CODE

#define pus_ST18_SIZE_OBCP_CHECKSUM pus_ST18_SIZE_OBCP_CHECKSUM

#define pus_ST23_MAX_SIZE_FILE_PATH pus_ST23_MAX_SIZE_FILE_PATH

#define pus_ST23_MAX_SIZE_REPOSITORY_PATH pus_ST23_MAX_SIZE_REPOSITORY_PATH

#define pus_ST23_MAX_SIZE_REPOSITORY_DOMAIN pus_ST23_MAX_SIZE_REPOSITORY_DOMAIN

#define pus_ST23_MAX_SIZE_FILE pus_ST23_MAX_SIZE_FILE


//! OBCP observability and status
#define PUS_OBCP_OBSERVABILITY_NONE 0
#define PUS_OBCP_OBSERVABILITY_PROCEDURE 1
#define PUS_OBCP_OBSERVABILITY_STEP 2
#define PUS_OBCP_OBSERVABILITY_DETAILED 3

#define PUS_OBCP_STATUS_UNLOAD 0
#define PUS_OBCP_STATUS_INACTIVE 1
#define PUS_OBCP_STATUS_ACTIVE_RUNNING 2
#define PUS_OBCP_STATUS_ACTIVE_HELD_REQUEST 3
#define PUS_OBCP_STATUS_ACTIVE_HELD 4
#define PUS_OBCP_STATUS_ACTIVE_RESUME_REQUEST 5
#define PUS_OBCP_STATUS_ACTIVE_STOP_REQUEST 6
#define PUS_OBCP_STATUS_ACTIVE_ABORT_REQUEST 7

#define PUS_OBCP_CONFIRMATION_STATUS_NOT_COMPLETED 0
#define PUS_OBCP_CONFIRMATION_STATUS_SUCCESS 1
#define PUS_OBCP_CONFIRMATION_STATUS_STOPPED 2
#define PUS_OBCP_CONFIRMATION_STATUS_ABORTED 3


#ifdef  __cplusplus
}
#endif

#endif //PUS_TYPES_H

