/*! \file pus_error.h
 *  \brief Functions to record internal error conditions.
 *
 *  The functions and types of this module are used by other PUS library functions
 *  to record any internal errors that occur and do not interrupt the execution.
 *
 *  The module provides the function \ref pus_getError to retrieve the last error
 *  condition reported.
 *
 *  The functions in this module are not thread-safe. This intends to keep the module
 *  as simple as possible.
 *
 *  \author GMV
 */

#ifndef PUS_ERROR_H
#define PUS_ERROR_H

#include <stdint.h>
#include <stddef.h>


//! Macro to set the error code, including the function name
#define PUS_SET_ERROR(code) pus_setError((code), __func__, 0)

//! Macro to set the error code, including the function name, with a data parameter
#define PUS_SET_ERROR_2(code, data) pus_setError((code), __func__, (pusErrorData_t)(data))

//! Macro to get the last error code, without additional data
#define PUS_GET_ERROR() pus_getError(NULL, NULL, NULL)

//! Macro to check if there was an error
#define PUS_IS_ERROR() (PUS_NO_ERROR != pus_getError(NULL, NULL, NULL))


//! Type for the internal PUS library error codes
typedef enum
{
    PUS_NO_ERROR = 0,
	PUS_ERROR_NULLPTR,
    PUS_ERROR_COUNT_WRAP,
    PUS_ERROR_HEADER_MISMATCH,
	PUS_ERROR_PACKET_TYPE,
    PUS_ERROR_NOT_TM,
    PUS_ERROR_NOT_TC,
	PUS_ERROR_SYSTEM_TIME,
	PUS_ERROR_LIMIT,
	PUS_ERROR_UNEXPECTED_PACKET_VERSION,
	PUS_ERROR_UNEXPECTED_SEQUENCE_FLAGS,
	PUS_ERROR_UNEXPECTED_PUS_VERSION,
	PUS_ERROR_NOT_IMPLEMENTED,
	PUS_ERROR_TM_KIND,
	PUS_ERROR_TM_SERVICE,
	PUS_ERROR_TM_SUBTYPE,
	PUS_ERROR_TC_KIND,
	PUS_ERROR_TC_SERVICE,
	PUS_ERROR_TC_SUBTYPE,
	PUS_ERROR_SUBTYPE_MISMATCH,
	PUS_ERROR_THREADS,
	PUS_ERROR_BEFORE,
    
    // Limit
    PUS_LAST_ERROR
} pusError_t;

//! Type for additional error data
typedef size_t pusErrorData_t;

//! Type of the function name for internal errors
typedef const char* pusErrorFunction_t;

//! Set error code
/*! \warning Not thread-safe
 */
void pus_setError(pusError_t error, const char* function, pusErrorData_t data);

//! Get last error code
/*! \param[out] outError If not null address is passed, writes the error code to it
 *  \param[out] outFunction If not null address is passed, writes the error source to it
 *  \param[out] outData If not null address is passed, writes the error data to it
 *  \return The error code
 *  \warning Not thread-safe
 *
 */
pusError_t pus_getError(pusError_t* outError, pusErrorFunction_t* outFunction, pusErrorData_t* outData);

//! Clear the error code
/*! \warning Not thread-safe
 */
void pus_clearError();

#endif // PUS_ERROR_H
