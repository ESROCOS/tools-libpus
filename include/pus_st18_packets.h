/*! \file pus_st18_packets.h
 *  \brief PUS service ST[18] On-board control procedure
 *
 *  This module provides the functions to generate reports of the service ST[18],
 *  as well as getter/setter and checking functions.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 * OBCP management
 *	- TC[18,1] Load OBCP Direct
 *	- TC[18,2] Unload OBCP
 *	- TC[18,3] Activate OBCP
 *	- TC[18,4] Stop OBCP
 *	- TC[18,5] Suspend OBCP
 *	- TC[18,6] Resume OBCP
 *	- TC[18,12] Abort OBCP
 *	- TC[18,13] Load OBCP by reference
 * OBCP engine management
 *	- TC[18,21] Start OBCP engine
 *	- TC[18,22] Stop OBCP engine
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */


#ifndef PUS_ST18_PACKETS_H
#define PUS_ST18_PACKETS_H


#include "pus_apid.h"
#include "pus_error.h"
#include "pus_types.h"

#ifdef  __cplusplus
extern "C" {
#endif

/*! Builds a default TC[18,X] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the request
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] subtype Subservice type of the request
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_18_X_createDefaultRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSubservice_t subtype);

/*! Builds a TC[23,1] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the request
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] obcpId OCBP identifier
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_18_1_createLoadObcpDirectRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt18ObcpId_t* obcpId, const pusSt18ObcpCode_t* code);

/*! Builds a TC[23,2] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_18_2_createUnloadObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt18ObcpId_t* obcpId);

/*! Builds a TC[23,3] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the request
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] obcpId OCBP identifier
 *  \param[in] observability Observability level to use during the execution of the OBCP
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_18_3_createActivateObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const pusSt18ObcpId_t* obcpId, pusSt18ObservabilityLevel_t observability);

/*! Builds a TC[23,4] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the request
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] obcpId OCBP identifier
 *  \param[in] step Step where the Obcp shall be stopped.
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_18_4_createStopObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const pusSt18ObcpId_t* obcpId, pusSt18ObcpStepId_t step);

/*! Builds a TC[23,5] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the request
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] obcpId OCBP identifier
 *  \param[in] step Step where the Obcp shall be suspended.
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_18_5_createSuspendObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const pusSt18ObcpId_t* obcpId, pusSt18ObcpStepId_t step);


/*! Builds a TC[23,6] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the request
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] obcpId OCBP identifier
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_18_6_createResumeObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,const pusSt18ObcpId_t* obcpId);

/*! Builds a TC[23,12] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] obcpId OCBP identifier
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_18_12_createAbortObcpRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, const pusSt18ObcpId_t* obcpId);

/*! Builds a TC[23,13] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the request
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] obcpId OCBP identifier
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_18_13_createLoadObcpReferenceRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount,
		const pusSt18ObcpId_t* obcpId, const pusSt23RepositoryPath_t* repository, const pusSt23FileName_t* fileName);

/*! Builds a TC[23,21] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the request
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_18_21_createStartObcpEngineRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);

/*! Builds a TC[23,22] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the request
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_18_22_createStopObcpEngineRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);


//! Setter for the OBCP ID of a TC[18,X] packet
pusError_t pus_tc_18_X_setObcpId(pusPacket_t* outTc, const pusSt18ObcpId_t* obcpId);

//! Getter for the OBCP ID of a TC[18,X] packet
pusError_t pus_tc_18_X_getObcpId(pusSt18ObcpId_t* obcpId, const pusPacket_t* outTc);

//! Setter for the OBCP Code of a TC[18,1] packet
pusError_t pus_tc_18_1_setObcpCode(pusPacket_t* outTc, const pusSt18ObcpCode_t* code);

//! Getter for the OBCP Code of a TC[18,1] packet
pusError_t pus_tc_18_1_getObcpCode(pusSt18ObcpCode_t* code, const pusPacket_t* outTc);

//! Setter for the OBCP observability level of a TC[18,3] packet
pusError_t pus_tc_18_3_setObservabilityLevel(pusPacket_t* outTc, pusSt18ObservabilityLevel_t observability);

//! Getter for the OBCP observability level of a TC[18,3] packet
pusError_t pus_tc_18_3_getObservabilityLevel(pusSt18ObservabilityLevel_t* observability, const pusPacket_t* outTc);

//! Setter for the OBCP Step Id of a TC[18,4] and TC[18,5] packet
pusError_t pus_tc_18_4_5_setObcpStepId(pusPacket_t* outTc, pusSt18ObcpStepId_t obcpId);

//! Getter for the OBCP Step Id of a TC[18,4] and TC[18,5] packet
pusError_t pus_tc_18_4_5_getObcpStepId(pusSt18ObcpStepId_t* obcpId, const pusPacket_t* outTc);

//! Setter for the OBCP file name of a TC[18,13] packet
pusError_t pus_tc_18_13_setFileName(pusPacket_t* outTc, const pusSt23FileName_t* fileName);

//! Getter for the OBCP file name of a TC[18,13] packet
pusError_t pus_tc_18_13_getFileName(pusSt23FileName_t* fileName, const pusPacket_t* outTc);

//! Setter for the OBCP repository path of a TC[18,13] packet
pusError_t pus_tc_18_13_setRepositoryPath(pusPacket_t* outTc, const pusSt23RepositoryPath_t* repository);

//! Getter for the OBCP repository path of a TC[18,13] packet
pusError_t pus_tc_18_13_getRepositoryPath(pusSt23RepositoryPath_t* repository, const pusPacket_t* outTc);

//
// Parameter checking
//

//! Check that a packet is of a PUS ST[18] TC kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[18]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST17 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt18Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt18; adds function name
#define PUS_EXPECT_ST18TC(packet, subtype) pus_expectSt18Tc((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif
