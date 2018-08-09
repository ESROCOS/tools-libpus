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
 *  H2020 ESROCOS Project
 *  \author Company: GMV Aerospace & Defence S.A.U.
 *  \copyright Licence: GPLv2
 */

#ifndef PUS_ERROR_H
#define PUS_ERROR_H

#include <stdint.h>
#include <stddef.h>

#ifdef  __cplusplus
extern "C" {
#endif

//! Macro to set the error code, including the function name
#define PUS_SET_ERROR(code) pus_setError((code), __func__, (pusErrorData_t){.integer=0})

//! Macro to set the error code, including the function name, with a data parameter
#define PUS_SET_ERROR_INT(code, data) pus_setError((code), __func__, (pusErrorData_t){.integer=(int32_t)(data)})

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
	PUS_ERROR_ALREADY_INITIALIZED,
	PUS_ERROR_NOT_INITIALIZED,
	PUS_ERROR_INITIALIZATION,
	PUS_ERROR_FINALIZATION,
	PUS_ERROR_INVALID_ID,
	PUS_ERROR_INVALID_TYPE,
	PUS_ERROR_THREADS_DISABLED,
	PUS_ERROR_REPORT_ID_UNKNOWN,
	PUS_ERROR_REPORT_LENGTH,
	PUS_ERROR_EVENT_NOT_FOUND,
	PUS_ERROR_NEXT_EVENT_NOT_FOUND, //st05
	PUS_ERROR_OUT_OF_RANGE, //st05
	PUS_ERROR_EMPTY_BUFFER, //ST05
	PUS_ERROR_FULL_QUEUE, //packets_queue
	PUS_ERROR_EMPTY_QUEUE, //packets_queue
	PUS_ERROR_UNEXPECTED_FUNCTION_ID,
	PUS_ERROR_FULL_EVENT_ACTION_LIST, //st19
	PUS_ERROR_DEFINITION_NOT_FOUND,
	PUS_ERROR_DEFINITION_ALREADY_EXIST,
	PUS_ERROR_NO_ACTION_FOR_EVENT,
	PUS_ERROR_ALREADY_ENABLED,
	PUS_ERROR_ALREADY_DISABLED,
	PUS_ERROR_UNEXPECTED_PARAM_TYPE,
	PUS_ERROR_BELOW_LOW_LIMIT,
	PUS_ERROR_ABOVE_HIGH_LIMIT,
	PUS_ERROR_DEFINITION_DISABLED,
	PUS_ERROR_FUNCTION_NOT_ACTIVATED,
	PUS_ERROR_MAXIMUM_REACHED,
	PUS_ERROR_NOT_AVAILABLE,
	PUS_ERROR_CREATING_FILE, // ST23
	PUS_ERROR_DELETING_FILE,
	PUS_ERROR_COPYING_FILE,
	PUS_ERROR_FILE_REPOSITORY,
	PUS_ERROR_FILE_NOT_FOUND,
	PUS_ERROR_FILE_ALREADY_CREATED,
	PUS_ERROR_FILE_IN_TABLE,
	PUS_ERROR_OBCP_ALREADY_LOADED, //ST18
	PUS_ERROR_OBCP_FULL_BUFFER,
	PUS_ERROR_OBCP_NOT_LOADED,
	PUS_ERROR_OBCP_ALREADY_ACTIVATED,
	PUS_ERROR_OBCP_IS_RUNNING,
	PUS_ERROR_OBCP_NOT_RUNNING,
	PUS_ERROR_OBCP_ENGINE_ALREADY_RUNNING,
	PUS_ERROR_OBCP_ENGINE_NOT_RUNNING,
	PUS_ERROR_EXECUTING_OBCP,
	PUS_ERROR_OBCP_INTERPRETER_NOT_INIT,
	PUS_ERROR_OBCP_NOT_HELD,
    // Limit
    PUS_LAST_ERROR
} pusError_t;

//! Type for additional error data
/*! For the moment, all error codes have an integer data (0 if not used).
 *  A union is used here so that in the future other codes can be added, without needing casts.
 */
typedef union
{
	int32_t integer;
} pusErrorData_t;

//! Type of the function name for internal errors
typedef const char* pusErrorFunction_t;

//! Set error code
/*! \warning Not thread-safe
 */
pusError_t pus_setError(pusError_t error, const char* function, pusErrorData_t data);

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

#ifdef  __cplusplus
}
#endif

#endif // PUS_ERROR_H
