//! \file pus_st23_packets.h
/*! \brief Implementation of the PUS service ST[23] File management.
 *
 *  This module contains the functions to manage the file management
 *
 *  Only a subset of the standard requests and reports are implemented.
 *  * File handling
 *   - TC[23,1] Create file
 *   - TC[23,2] Delete file
 *   - TC[23,3] Report file attributes (request)
 *   - TM[23,4] Report file attributes
 *  * File copy
 *   - TC[23,14] Copy file
 *
 *  \author GMV
 */

#ifndef PUS_ST23_PACKETS_H
#define PUS_ST23_PACKETS_H

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_threads.h"
#include "pus_types.h"

#ifdef  __cplusplus
extern "C" {
#endif


/*! Builds a default TC[23,X] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_23_X_createDefaultRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount, pusSubservice_t subtype);

/*! Builds a TC[23,1] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_23_1_createCreateFileRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);

/*! Builds a TC[23,2] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_23_2_createDeleteFileRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);

/*! Builds a TC[23,3] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_23_3_createReportFileAtributesRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);

/*! Builds a TM[23_4] packet in the packet passed as parameter.
 *  \param[out] outTm Packet variable to build the TM
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \param[in] destination Destination of the TM report
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tm_23_4_createReportFileAtributesReport(pusPacket_t* outTm, pusApid_t apid, pusSequenceCount_t sequenceCount, pusApid_t destination);

/*! Builds a TC[23,1] packet in the packet passed as parameter.
 *  \param[out] outTc Packet variable to build the TC
 *  \param[in] apid APID of the process sending the report
 *  \param[in] sequenceCountcount TC sequence counter for the source APID
 *  \return Error code (PUS_NO_ERROR if success)
 */
pusError_t pus_tc_23_14_createCopyFileRequest(pusPacket_t* outTc, pusApid_t apid, pusSequenceCount_t sequenceCount);


//
// Parameter checking
//

//! Check that a packet is of a PUS ST[23] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[23]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST23 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt23Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Check that a packet is of a PUS ST[23] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[23]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST23 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt23Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt20Tc; adds function name
#define PUS_EXPECT_ST23TC(packet, subtype) pus_expectSt23Tc((packet), (subtype), __func__)

//! Helper macro for pus_expectSt20Tm; adds function name
#define PUS_EXPECT_ST23TM(packet, subtype) pus_expectSt23Tm((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif // PUS_ST20_PACKETS_H
