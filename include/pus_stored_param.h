/*! \file pus_stored_param.h
 * \brief Management of the Stored parameters in packets
 *
 *  Defines the stored parameters for data field in packets.
 *
 *
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_STORED_PARAM_H
#define PUS_STORED_PARAM_H

#include "pus_types.h"
#include "pus_threads.h"
#include "pus_error.h"
#include "pus_packet.h"


#ifdef  __cplusplus
extern "C" {
#endif

typedef enum
{
	PUS_INT32,
	PUS_UINT32,
	PUS_REAL64,
	PUS_BYTE,
	PUS_BOOL
} pusParamType_t; //!< Param type that shall be stored in packets.




//! Convert a value from the internal parameter format to uint32_t
pusError_t pus_paramToUint32(uint32_t* outValue, pusStoredParam_t paramValue);

//! Convert a value from the internal parameter format to int32_t
pusError_t pus_paramToInt32(int32_t* outValue, pusStoredParam_t paramValue);

//! Convert a value from the internal parameter format to double
pusError_t pus_paramToReal64(double* outValue, pusStoredParam_t paramValue);

//! Convert a value from the internal parameter format to bool
pusError_t pus_paramToBool(bool* outValue, pusStoredParam_t paramValue);

//! Convert a value from the internal parameter format to byte
pusError_t pus_paramToByte(uint8_t* outValue, pusStoredParam_t paramValue);


//! Convert a uint32_t value into an internal parameter format
pusError_t pus_uint32ToParam(pusStoredParam_t* outParam, uint32_t inValue);

//! Convert a int32_t value into an internal parameter format
pusError_t pus_int32ToParam(pusStoredParam_t* outParam, int32_t inValue);

//! Convert a double value into an internal parameter format
pusError_t pus_real64ToParam(pusStoredParam_t* outParam, double inValue);

//! Convert a bool value into an internal parameter format
pusError_t pus_boolToParam(pusStoredParam_t* outParam, bool inValue);

//! Convert a byte value into an internal parameter format
pusError_t pus_byteToParam(pusStoredParam_t* outParam, uint8_t inValue);



#ifdef  __cplusplus
}
#endif

#endif
