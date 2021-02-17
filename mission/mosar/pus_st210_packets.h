/*! \file pus_st210_packets.h
 *  \brief PUS service ST[210] RMAP
 *
 *  This module provides the functions to generate reports of the service ST[210],
 *  as well as getter/setter and checking functions.
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */


#ifndef PUS_ST210_PACKETS_H
#define PUS_ST210_PACKETS_H

#include "pus_enable_services.h"
#ifdef PUS_CONFIGURE_ST210_ENABLED

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*! TODO!!! Builds a TC[200,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCount Sequence counter for this TC
 *  \param[in] state state to be added in data fueld
 *  \return Error code (PUS_NO_ERROR if success)
 */ 

/* R_ICU_SPW_PNP */
extern pusError_t pus_tc_210_1_createSpwRoutingTableSetEntry(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt16 SET_ROUTING_ENTRY, asn1SccPusUInt8 SPW_TRAFFIC_PRIORITY);
extern asn1SccPusUInt8 pus_tc_210_1_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_1_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_1_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_1_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt16 pus_tc_210_1_getParamSetRoutingEntry(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_1_setParamSetRoutingEntry(pusPacket_t* outTC, asn1SccPusUInt16 param);
extern asn1SccPusUInt8 pus_tc_210_1_getParamSpwTrafficPriority(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_1_setParamSpwTrafficPriority(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_2_createSpwPnpSetOwnerFields(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt16 SET_OWNER);
extern asn1SccPusUInt8 pus_tc_210_2_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_2_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_2_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_2_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt16 pus_tc_210_2_getParamSetOwner(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_2_setParamSetOwner(pusPacket_t* outTC, asn1SccPusUInt16 param);


/* R_ICU */
extern pusError_t pus_tc_210_11_createConfigureTimeEpoch(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusInt32 SECS_SINCE_EPOCH, asn1SccPusInt32 NANOSECS_SINCE_EPOCH);
extern asn1SccPusUInt8 pus_tc_210_11_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_11_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_11_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_11_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusInt32 pus_tc_210_11_getParamSecsSinceEpoch(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_11_setParamSecsSinceEpoch(pusPacket_t* outTC, asn1SccPusInt32 param);
extern asn1SccPusInt32 pus_tc_210_11_getParamNanosecsSinceEpoch(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_11_setParamNanosecsSinceEpoch(pusPacket_t* outTC, asn1SccPusInt32 param);

extern pusError_t pus_tc_210_12_createSetLeds(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 SET_LEDS);
extern asn1SccPusUInt8 pus_tc_210_12_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_12_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_12_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_12_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_12_getParamSetLeds(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_12_setParamSetLeds(pusPacket_t* outTC, asn1SccPusUInt8 param);

/* THS */
extern pusError_t pus_tc_210_81_createModeCommand(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 TARGET_MODE);
extern asn1SccPusUInt8 pus_tc_210_81_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_81_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_81_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_81_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_81_getParamTargetMode(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_81_setParamTargetMode(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_82_createComponentsCommand(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 COMPONENT_TARGET_ID, asn1SccPusBoolean COMPONENT_TARGET_STATUS);
extern asn1SccPusUInt8 pus_tc_210_82_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_82_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_82_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_82_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_82_getParamComponentTargetId(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_82_setParamComponentTargetId(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusBoolean pus_tc_210_82_getParamComponentTargetStatus(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_82_setParamComponentTargetStatus(pusPacket_t* outTC, asn1SccPusBoolean param);


/* CPDU */
extern pusError_t pus_tc_210_91_createSpecificHkRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusUInt8 HK_X_REQUEST);
extern asn1SccPusUInt8 pus_tc_210_91_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_91_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_91_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_91_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_91_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_91_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_91_getParamHkXRequest(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_91_setParamHkXRequest(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_92_createAllHkRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId);
extern asn1SccPusUInt8 pus_tc_210_92_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_92_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_92_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_92_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_92_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_92_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_93_createCommandSwitch1(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean SW1_CMD, asn1SccPusBoolean SW2_CMD, asn1SccPusBoolean SW3_CMD, asn1SccPusBoolean SW4_CMD, asn1SccPusBoolean SW5_CMD);
extern asn1SccPusUInt8 pus_tc_210_93_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_93_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_93_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_93_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_93_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_93_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusBoolean pus_tc_210_93_getParamSw1Cmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_93_setParamSw1Cmd(pusPacket_t* outTC, asn1SccPusBoolean param);
extern asn1SccPusBoolean pus_tc_210_93_getParamSw2Cmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_93_setParamSw2Cmd(pusPacket_t* outTC, asn1SccPusBoolean param);
extern asn1SccPusBoolean pus_tc_210_93_getParamSw3Cmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_93_setParamSw3Cmd(pusPacket_t* outTC, asn1SccPusBoolean param);
extern asn1SccPusBoolean pus_tc_210_93_getParamSw4Cmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_93_setParamSw4Cmd(pusPacket_t* outTC, asn1SccPusBoolean param);
extern asn1SccPusBoolean pus_tc_210_93_getParamSw5Cmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_93_setParamSw5Cmd(pusPacket_t* outTC, asn1SccPusBoolean param);

extern pusError_t pus_tc_210_94_createCommand24VConverterA(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean CONV_24V_A_CMD, asn1SccPusBoolean CONV_24V_B_CMD, asn1SccPusBoolean CONV_12V_CMD, asn1SccPusBoolean CONV_19V_CMD);
extern asn1SccPusUInt8 pus_tc_210_94_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_94_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_94_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_94_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_94_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_94_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusBoolean pus_tc_210_94_getParamConv24vACmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_94_setParamConv24vACmd(pusPacket_t* outTC, asn1SccPusBoolean param);
extern asn1SccPusBoolean pus_tc_210_94_getParamConv24vBCmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_94_setParamConv24vBCmd(pusPacket_t* outTC, asn1SccPusBoolean param);
extern asn1SccPusBoolean pus_tc_210_94_getParamConv12vCmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_94_setParamConv12vCmd(pusPacket_t* outTC, asn1SccPusBoolean param);
extern asn1SccPusBoolean pus_tc_210_94_getParamConv19vCmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_94_setParamConv19vCmd(pusPacket_t* outTC, asn1SccPusBoolean param);


//! Check that a packet is of a PUS ST[210] TC kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[210]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST210 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
extern pusError_t pus_expectSt210Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);


//! Check that a packet is of a PUS ST[210] TM kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[210]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST210 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
extern pusError_t pus_expectSt210Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);


//! Helper macro for pus_expectSt17; adds function name
#define PUS_EXPECT_ST210TM(packet, subtype) pus_expectSt210Tm((packet), (subtype), __func__)
#define PUS_EXPECT_ST210TC(packet, subtype) pus_expectSt210Tc((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif /* PUS_CONFIGURE_ST210_ENABLED */

#endif /* PUS_ST210_PACKETS_H */