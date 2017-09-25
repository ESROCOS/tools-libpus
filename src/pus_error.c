#include "pus_error.h"

// Error variables
volatile pusError_t lastErrorCode = PUS_NO_ERROR;
volatile pusErrorSource_t lastErrorSource = PUS_SOURCE_NONE;
volatile pusErrorData_t lastErrorData = 0;


void pus_setError(pusError_t error, pusErrorSource_t source, pusErrorData_t data)
{
    lastErrorCode = error;
    lastErrorSource = source;
    lastErrorData = data;
}


pusError_t pus_getError(pusError_t* outError, pusErrorSource_t* outSource, pusErrorData_t* outData)
{
    pusError_t code = lastErrorCode;
    
    if (NULL != outError)
    {
        *outError = code;
    }
    
    if (NULL != outSource)
    {
        *outData = lastErrorSource;
    }
    
    if (NULL != outData)
    {
        *outData = lastErrorData;
    }
    
    return code;
}


void pus_clearError()
{
    lastErrorCode = PUS_NO_ERROR;
    lastErrorData = 0;
}


//! Get last error code
/*! \param[out] outError If not null address is passed, writes the error code to it
 *  \param[out] outSource If not null address is passed, writes the error source to it
 *  \param[out] outData If not null address is passed, writes the error data to it
 *  \return The error code
 *  \warning Not thread-safe
 *
 */
