

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

#ifdef  __cplusplus
extern "C" {
#endif

//! Build the common part of the ST[19] reports
/*! Builds a TC[19,X] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_19_X_createDefaultEventActionRequest(pusPacket_t* outTc, pusApidInfo_t* apid);

//! Build an acceptance report for a TC
/*! Builds a TC[19,1] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_19_1_createAddEventActionDefinitionsRequest(pusPacket_t* outTc, pusApidInfo_t* apid);

//! Build an acceptance report for a TC
/*! Builds a TC[19,2] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_19_2_createDeleteEventActionDefinitionsRequest(pusPacket_t* outTc, pusApidInfo_t* apid);

//! Build an acceptance report for a TC
/*! Builds a TC[19,4] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_19_4_createEnableEventActionDefinitions(pusPacket_t* outTc, pusApidInfo_t* apid);

//! Build an acceptance report for a TC
/*! Builds a TC[19,5] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 */
pusError_t pus_tc_19_5_createDisableEventActionDefinitions(pusPacket_t* outTc, pusApidInfo_t* apid);

#ifdef  __cplusplus
}
#endif

#endif
