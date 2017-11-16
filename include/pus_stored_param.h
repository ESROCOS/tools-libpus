//! \file pus_stored_param.h
/*! \brief Management of the StoredParam
 *
 *  Defines the stored param for data.
 *
 *
 *  \author GMV
 */

#ifndef PUS_STORED_PARAM_H
#define PUS_STORED_PARAM_H

#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"

typedef uint64_t pusStoredParam_t;

//
// Cast parameter to type
//

//! Convert a value from the internal parameter format to uint32_t
pusError_t pus_paramToUInt32(uint32_t* outValue, pusStoredParam_t paramValue);

//! Convert a value from the internal parameter format to int32_t
pusError_t pus_paramToInt32(int32_t* outValue, pusStoredParam_t paramValue);

//! Convert a value from the internal parameter format to uint32_t
pusError_t pus_paramToReal64(double* outValue, pusStoredParam_t paramValue);

//! Convert a value from the internal parameter format to uint32_t
pusError_t pus_paramToBool(bool* outValue, pusStoredParam_t paramValue);

//! Convert a value from the internal parameter format to uint32_t
pusError_t pus_paramToByte(uint8_t* outValue, pusStoredParam_t paramValue);


#endif
