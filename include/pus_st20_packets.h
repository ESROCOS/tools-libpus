//! \file pus_st03_packets.h
/*! \brief Implementation of the PUS service ST[03] Housekeeping.
 *
 *  This module contains the functions to manage the on-board housekeeping parameters
 *  database, to generate housekeeping and parameter reports, and to process the TCs
 *  to manage this service.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 *  - Housekeeping
 *    + TM[3,25] Housekeeping parameter report
 *
 *  \author GMV
 */

#ifndef PUS_ST20_PACKETS_H
#define PUS_ST20_PACKETS_H

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_housekeeping.h"
#include "pus_threads.h"
#include "pus_types.h"

#ifdef  __cplusplus
extern "C" {
#endif



//
// Parameter checking
//

//! Check that a packet is of a PUS ST[20] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TC has this subtype; use pusSubtype_NONE to check for all TC types in ST[03]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST20 to include the caller function's name)
 *  \return If valid TC, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt20Tc(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Check that a packet is of a PUS ST[03] kind
/*! \param[in] packet The PUS packet
 *  \param[in] expectedSubtype Check that the TM has this subtype; use pusSubtype_NONE to check for all TM types in ST[03]
 *  \param[in] function Function name to write as error information (use with the macro \ref PUS_EXPECT_ST03 to include the caller function's name)
 *  \return If valid TM, PUS_NO_ERROR; otherwise, an error code
 */
pusError_t pus_expectSt20Tm(const pusPacket_t* packet, pusSubservice_t expectedSubtype, const char* function);

//! Helper macro for pus_expectSt20Tc; adds function name
#define PUS_EXPECT_ST20TC(packet, subtype) pus_expectSt20Tc((packet), (subtype), __func__)

//! Helper macro for pus_expectSt20Tm; adds function name
#define PUS_EXPECT_ST20TM(packet, subtype) pus_expectSt20Tm((packet), (subtype), __func__)

#ifdef  __cplusplus
}
#endif

#endif // PUS_ST03_PACKETS_H
