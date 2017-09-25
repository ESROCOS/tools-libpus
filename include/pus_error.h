#ifndef PUS_ERROR_H
#define PUS_ERROR_H

#include <stdint.h>
#include <stddef.h>

//! Type for the internal PUS library error codes
typedef enum
{
    PUS_NO_ERROR = 0,
    PUS_ERROR_COUNT_WRAP,
    PUS_ERROR_NO_HEADER,
    PUS_ERROR_NOT_TM,
    
    // Limit
    PUS_LAST_ERROR
} pusError_t;


//! Type for error sources
typedef enum
{
    PUS_SOURCE_NONE = 0,
    PUS_SETSEQUENCECOUNT,
    PUS_GETPACKETDATAKIND,
    PUS_SETPACKETDATAKIND,
    PUS_GETPUSVERSION,
    PUS_SETPUSVERSION,
    PUS_GETTMSERVICE,
    PUS_SETTMSERVICE,
    PUS_GETTCSERVICE,
    PUS_SETTCSERVICE,
    
    // Limit
    PUS_SOURCE_LAST
} pusErrorSource_t;


//! Type for additional error data
typedef int32_t pusErrorData_t;



//! Set error code
/*! \warning Not thread-safe
 */
void pus_setError(pusError_t error, pusErrorSource_t source, pusErrorData_t data);

//! Get last error code
/*! \param[out] outError If not null address is passed, writes the error code to it
 *  \param[out] outSource If not null address is passed, writes the error source to it
 *  \param[out] outData If not null address is passed, writes the error data to it
 *  \return The error code
 *  \warning Not thread-safe
 *
 */
pusError_t pus_getError(pusError_t* outError, pusErrorSource_t* outSource, pusErrorData_t* outData);

//! Clear the error code
/*! \warning Not thread-safe
 */
void pus_clearError();

#endif // PUS_ERROR_H
