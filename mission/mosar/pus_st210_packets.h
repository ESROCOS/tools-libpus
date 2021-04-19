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
extern pusError_t pus_tc_210_1_createSpwRoutingTableSetEntry(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 ROUTING_TABLE_INDEX, asn1SccPusUInt8 ROUTING_TABLE_DIRECTION, asn1SccPusUInt8 TRAFFIC_PRIORITY);
extern asn1SccPusUInt8 pus_tc_210_1_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_1_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_1_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_1_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_1_getParamRoutingTableIndex(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_1_setParamRoutingTableIndex(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_1_getParamRoutingTableDirection(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_1_setParamRoutingTableDirection(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_1_getParamTrafficPriority(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_1_setParamTrafficPriority(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_2_createSpwPnpSetOwnerFields(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 SET_OWNER);
extern asn1SccPusUInt8 pus_tc_210_2_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_2_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_2_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_2_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_2_getParamSetOwner(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_2_setParamSetOwner(pusPacket_t* outTC, asn1SccPusUInt8 param);



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

/* HOTDOCK */
extern pusError_t pus_tc_210_21_createSetHouskeepingDataRate(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusUInt8 POLLING_HK_TM);
extern asn1SccPusUInt8 pus_tc_210_21_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_21_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_21_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_21_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_21_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_21_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_21_getParamPollingHkTm(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_21_setParamPollingHkTm(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_22_createGoToState(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusUInt8 TARGET_STATE);
extern asn1SccPusUInt8 pus_tc_210_22_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_22_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_22_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_22_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_22_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_22_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_22_getParamTargetState(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_22_setParamTargetState(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_23_createCommandP15VLine(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean P15V_CMD);
extern asn1SccPusUInt8 pus_tc_210_23_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_23_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_23_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_23_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_23_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_23_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusBoolean pus_tc_210_23_getParamP15vCmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_23_setParamP15vCmd(pusPacket_t* outTC, asn1SccPusBoolean param);

extern pusError_t pus_tc_210_24_createCommandP2V5Line(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean P2V5_CMD);
extern asn1SccPusUInt8 pus_tc_210_24_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_24_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_24_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_24_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_24_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_24_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusBoolean pus_tc_210_24_getParamP2v5Cmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_24_setParamP2v5Cmd(pusPacket_t* outTC, asn1SccPusBoolean param);

extern pusError_t pus_tc_210_25_createCoomdadRelay(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean RELAY_CMD);
extern asn1SccPusUInt8 pus_tc_210_25_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_25_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_25_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_25_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_25_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_25_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusBoolean pus_tc_210_25_getParamRelayCmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_25_setParamRelayCmd(pusPacket_t* outTC, asn1SccPusBoolean param);

extern pusError_t pus_tc_210_26_createSetLvdsPins(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusUInt8 LVDS_A_CMD, asn1SccPusUInt8 LVDS_B_CMD);
extern asn1SccPusUInt8 pus_tc_210_26_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_26_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_26_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_26_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_26_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_26_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_26_getParamLvdsACmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_26_setParamLvdsACmd(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_26_getParamLvdsBCmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_26_setParamLvdsBCmd(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_27_createPowerOnOffMotor(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean MOTOR_ON_OFF);
extern asn1SccPusUInt8 pus_tc_210_27_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_27_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_27_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_27_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_27_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_27_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusBoolean pus_tc_210_27_getParamMotorOnOff(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_27_setParamMotorOnOff(pusPacket_t* outTC, asn1SccPusBoolean param);

extern pusError_t pus_tc_210_28_createSetMotorSpeed(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusFloat32 MOTOR_TARGET_SPEED);
extern asn1SccPusUInt8 pus_tc_210_28_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_28_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_28_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_28_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_28_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_28_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusFloat32 pus_tc_210_28_getParamMotorTargetSpeed(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_28_setParamMotorTargetSpeed(pusPacket_t* outTC, asn1SccPusFloat32 param);

extern pusError_t pus_tc_210_29_createSetMotorDirection(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusBoolean MOTOR_DIRECTION_SPEED);
extern asn1SccPusUInt8 pus_tc_210_29_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_29_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_29_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_29_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_29_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_29_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusBoolean pus_tc_210_29_getParamMotorDirectionSpeed(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_29_setParamMotorDirectionSpeed(pusPacket_t* outTC, asn1SccPusBoolean param);

extern pusError_t pus_tc_210_30_createSetMotorCurrentLimit(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusFloat32 MOTOR_CURRENT_LIMIT);
extern asn1SccPusUInt8 pus_tc_210_30_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_30_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_30_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_30_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_30_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_30_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusFloat32 pus_tc_210_30_getParamMotorCurrentLimit(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_30_setParamMotorCurrentLimit(pusPacket_t* outTC, asn1SccPusFloat32 param);

extern pusError_t pus_tc_210_31_createCalibrateController(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId, asn1SccPusUInt8 CONTROLLER_CALIB);
extern asn1SccPusUInt8 pus_tc_210_31_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_31_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_31_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_31_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_31_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_31_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_31_getParamControllerCalib(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_31_setParamControllerCalib(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_32_createResetController(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId);
extern asn1SccPusUInt8 pus_tc_210_32_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_32_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_32_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_32_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_32_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_32_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);


/* OSP */
extern pusError_t pus_tc_210_41_createOspControlCommand(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 COMMAND);
extern asn1SccPusUInt8 pus_tc_210_41_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_41_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_41_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_41_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_41_getParamCommand(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_41_setParamCommand(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_42_createCaptureImage(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId);
extern asn1SccPusUInt8 pus_tc_210_42_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_42_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_42_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_42_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);

/* BAT */
extern pusError_t pus_tc_210_61_createHk1Request(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId);
extern asn1SccPusUInt8 pus_tc_210_61_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_61_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_61_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_61_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_62_createAllHkRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId);
extern asn1SccPusUInt8 pus_tc_210_62_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_62_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_62_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_62_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);

extern pusError_t pus_tc_210_63_createCommand48VConverter(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusBoolean CONV_48V_CMD);
extern asn1SccPusUInt8 pus_tc_210_63_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_63_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_63_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_63_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusBoolean pus_tc_210_63_getParamConv48vCmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_63_setParamConv48vCmd(pusPacket_t* outTC, asn1SccPusBoolean param);

extern pusError_t pus_tc_210_64_createCommandBatCharger(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusBoolean BAT_CH_CMD);
extern asn1SccPusUInt8 pus_tc_210_64_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_64_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_64_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_64_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusBoolean pus_tc_210_64_getParamBatChCmd(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_64_setParamBatChCmd(pusPacket_t* outTC, asn1SccPusBoolean param);

/* WM */
extern pusError_t pus_tc_210_71_createJointTrajectory(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 nSteps, asn1SccPusTC_210_71_Data_goalValues goalValues);
extern asn1SccPusUInt8 pus_tc_210_71_getParamSM_ID(const pusPacket_t* inTC);
extern asn1SccPusUInt8 pus_tc_210_71_getParamCOMP_ID(const pusPacket_t* inTC);
extern asn1SccPusUInt8 pus_tc_210_71_getParamN_STEPS(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_71_getParamGoalValues(const pusPacket_t* inTC, asn1SccPusTC_210_71_Data_goalValues *goalValues);

extern pusError_t pus_tc_210_72_createCartGoal(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusTC_210_72_Data_desiredPos desiredPos);
extern asn1SccPusUInt8 pus_tc_210_72_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_72_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_72_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_72_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern pusError_t pus_tc_210_72_getParamDesiredPos(const pusPacket_t* inTC, asn1SccPusTC_210_72_Data_desiredPos *desiredPos);
extern pusError_t pus_tc_210_72_setParamDesiredPose(pusPacket_t* outTC, asn1SccPusTC_210_72_Data_desiredPos param);

extern pusError_t pus_tc_210_73_createInterface(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusInt32 setMode, asn1SccPusInt32 hdId, asn1SccPusInt32 manipulatorBase, asn1SccPusInt32 graspRelease);
extern asn1SccPusUInt8 pus_tc_210_73_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_73_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_73_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_73_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusInt32 pus_tc_210_73_getParamSET_MODE(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_73_setParamMode(pusPacket_t* outTC, asn1SccPusInt32 param);
extern asn1SccPusInt32 pus_tc_210_73_getParamHD_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_73_setParamHdId(pusPacket_t* outTC, asn1SccPusInt32 param);
extern asn1SccPusInt32 pus_tc_210_73_getParamMANIPULATOR_BASE(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_73_setParamManipulatorBase(pusPacket_t* outTC, asn1SccPusInt32 param);
extern asn1SccPusInt32 pus_tc_210_73_getParamGRASP_RELEASE(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_73_setParamGraspRelease(pusPacket_t* outTC, asn1SccPusInt32 param);

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

extern pusError_t pus_tc_210_95_createSmPowerOff(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, asn1SccPusUInt8 smId, asn1SccPusUInt8 componentId, asn1SccPusUInt8 subcomponentId);
extern asn1SccPusUInt8 pus_tc_210_95_getParamSM_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_95_setParamSM_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_95_getParamCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_95_setParamCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);
extern asn1SccPusUInt8 pus_tc_210_95_getParamSUBCOMP_ID(const pusPacket_t* inTC);
extern pusError_t pus_tc_210_95_setParamSUBCOMP_ID(pusPacket_t* outTC, asn1SccPusUInt8 param);


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