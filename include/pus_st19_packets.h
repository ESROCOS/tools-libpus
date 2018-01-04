/*! \file pus_st19_packets.h
 *  \brief PUS service ST[19] Event-action
 *
 *  This module provides the functions to generate packets of the service ST[19],
 *  as well as getter/setter and checking functions.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 *  - TC[11,1] enable the time-based schedule execution function
 *  - TM[11,2] disable the time-based schedule execution function
 *  - TC[11,3] reset the time-based schedule
 *  - TM[11,4] insert activities into the time-based schedule
 *  \author GMV
 */

/*
 * EventDefinition ID
 *
 * Rechazar request si no existe,
 *
 * Recibe TC19.1 (add new) si es correcto,
 * 	- no existe, añade y lo pone en disable
 * 	- si existe, reemplaza la accion
 *s
 */

#ifndef PUS_ST19_PACKETS_H
#define PUS_ST19_PACKETS_H


#include "pus_error.h"
#include "pus_packet.h"
#include "pus_apid.h"
#include "pus_types.h"

#include "pus_packet_reduced.h"

#ifdef  __cplusplus
extern "C" {
#endif

//! Build the common part of the ST[19] reports
/*! Builds a TC[19,X] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_19_X_createDefaultEventActionRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);

//! Build an acceptance report for a TC
/*! Builds a TC[19,1] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_19_1_createAddEventActionDefinitionsRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt05EventId_t eventId, pusPacket_t* tcAction);

//! Build an acceptance report for a TC
/*! Builds a TC[19,2] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_19_2_createDeleteEventActionDefinitionsRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt05EventId_t eventId);

//! Build an acceptance report for a TC
/*! Builds a TC[19,4] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_19_4_createEnableEventActionDefinitions(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt05EventId_t eventId);

//! Build an acceptance report for a TC
/*! Builds a TC[19,5] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_19_5_createDisableEventActionDefinitions(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt05EventId_t eventId);


//! Function that set the eventId to the data field of tC[19,X]
pusError_t pus_tc_19_X_setEventId(pusPacket_t* packet, pusSt05EventId_t eventId);

//! Function that return the eventId from the data field of tC[19,X]
pusError_t pus_tc_19_X_getEventId(pusSt05EventId_t* eventID, const pusPacket_t* packet);

//! Function that set an action to a TC packet
void pus_tc_19_1_setAction(pusPacket_t* outTc, pusPacketReduced_t* actionR);

void pus_tc_19_1_getAction(pusPacketReduced_t* action, const pusPacket_t* tc);

//
// Parameter checking
//

//! Check that a packet is of a PUS ST[19] TC kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[19]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST19 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt19Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt19Tc; adds function name
#define PUS_EXPECT_ST19(packet, subtype) pus_expectSt19Tc((packet), (subtype), __func__)



#ifdef  __cplusplus
}
#endif

#endif
