 /*! \file pus_st17_packets.h
 *  \brief PUS service ST[201]
 *
 *  This module provides the functions to generate reports of the service ST[17],
 *  as well as getter/setter and checking functions.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 *  - TC[201,1]
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */


#ifndef PUS_ST201_PACKETS_H
#define PUS_ST201_PACKETS_H

#include "pus_types.h"
//#ifdef PUS_CONFIGURE_ST17_ENABLED
#ifdef PUS_CONFIGURE_ST201_ENABLED

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*! Builds a TC[201,1] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_201_1_createSetHomeRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt201Position* position, pusSt201Orientation* orientation);

/*! Builds a TC[201,2] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_201_2_createPlanHomeRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);

/*! Builds a TC[201,3] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_201_3_createPlanMoveRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSt201Position* position, pusSt201Orientation* orientation);

/*! Builds a TM[201,4] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_201_4_createPlanReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination, const pusSt201PlanObservation* observation);


pusError_t pus_tc_201_1_3_setOrientationPoints(pusPacket_t* outTc, pusSt201Point point1, pusSt201Point point2, pusSt201Point point3, pusSt201Point point4);

pusError_t pus_tc_201_1_3_getOrientationPoints(pusSt201Point* point1, pusSt201Point* point2, pusSt201Point* point3, pusSt201Point* point4, const pusPacket_t* inTc);

pusError_t pus_tc_201_1_3_setPositionPoints(pusPacket_t* outTc, pusSt201Point point1, pusSt201Point point2, pusSt201Point point3);

pusError_t pus_tc_201_1_3_getPositionPoints(pusSt201Point* point1, pusSt201Point* point2, pusSt201Point* point3, const pusPacket_t* inTc);

pusError_t pus_tm_201_4_setPlanObservation(pusPacket_t* outTm, const pusSt201PlanObservation* observation);

pusError_t pus_tm_201_4_getPlanObservation(pusSt201PlanObservation* observation, const pusPacket_t* inTM);


//! Check that a packet is of a PUS ST[201] TC kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[20]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST17 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt201Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);


//! Check that a packet is of a PUS ST[201] TM kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[20]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST17 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt201Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);


//! Helper macro for pus_expectSt17; adds function name
#define PUS_EXPECT_ST201TM(packet, subtype) pus_expectSt201Tm((packet), (subtype), __func__)
#define PUS_EXPECT_ST201TC(packet, subtype) pus_expectSt201Tc((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif

#endif
