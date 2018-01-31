/*! \file pus_apid.h
 *  \brief Data type to handle the TM count of an Application Process.
 *
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_APID_H
#define PUS_APID_H

#include "pus_error.h"
#include "pus_types.h"
#include "pus_threads.h"

#ifdef  __cplusplus
extern "C" {
#endif

//! Type to keep the information (e.g., packet counts) for a given APID
typedef struct
{
	pusApid_t apid; 			//!< The APID
	pusSequenceCount_t packetCount; //!< Count of TM messages sent
	pusMutex_t* mutex;			//!< Mutex for access control (may be NULL if not needed)
} pusApidInfo_t;


//! Initialize the \ref pusApidInfo_t data structure
/*! \param[out] obj The data structure to initialize
 *  \param[in] apid The associated APID
 *  \param[in] mutex A mutex for access control; use NULL if not needed
 */
pusError_t pus_initApidInfo(pusApidInfo_t* obj, pusApid_t apid, pusMutex_t* mutex);

//! Get the APID from a \ref pusApidInfo_t object
pusApid_t pus_getInfoApid(const pusApidInfo_t* obj);

//! Get the count value for the next TM packet
pusSequenceCount_t pus_getNextPacketCount(pusApidInfo_t* obj);

#ifdef  __cplusplus
}
#endif

#endif // PUS_APID_H
