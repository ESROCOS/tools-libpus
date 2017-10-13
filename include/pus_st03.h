//! \file pus_st03.h
/*! \brief Implementation of the PUS service ST[03] Housekeeping.
 *
 *  This module contains the functions to manage the on-board housekeeping parameters
 *  database, to generate housekeeping and parameter reports, and to process the TCs
 *  to manage this service.
 *
 *  Only a subset of the standard requests and reports are implemented.
 *
 *  - Housekeeping
 *    +
 *
 *  \author GMV
 */

#ifndef PUS_ST03_H
#define PUS_ST03_H

#include "pus_types.h"
#include "pus_error.h"
#include "pus_apid.h"


//
// Parameter tables
//

//! Type of supported parameter types
typedef enum
{
	PUS_ST03_INT32,
	PUS_ST03_UINT32,
	PUS_ST03_REAL64,
	PUS_ST03_BYTE,
	PUS_ST03_BOOL
} pusSt03ParamType_t;

//! Type to describe a parameter: type, location, etc.
typedef struct
{
	const char* label; //!< Name of the parameter, for debugging purposes
	pusSt03ParamType_t type; //!< Data type
	void* base; //!< Base address of the array containing the parameter
	size_t index; //!< Index of the parameter in the array
} pusSt03ParamInfo_t;





#endif // PUS_ST03_H
