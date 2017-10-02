#ifndef PUS_ERROR_H
#define PUS_ERROR_H

#include <stdint.h>
#include <stddef.h>

//! Type for the internal PUS library error codes
typedef enum
{
    PUS_NO_ERROR = 0,
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
    
    // Limit
    PUS_LAST_ERROR
} pusError_t;


//! Type for error sources
typedef enum
{
    PUS_SOURCE_NONE = 0,
    PUS_SETSEQUENCECOUNT,
	PUS_SETPACKETDATALENGTH,
    PUS_GETPACKETDATAKIND,
    PUS_SETPACKETDATAKIND,
	PUS_GETTMPUSVERSION,
	PUS_SETTMPUSVERSION,
	PUS_GETTCPUSVERSION,
	PUS_SETTCPUSVERSION,
    PUS_GETTMSERVICE,
    PUS_SETTMSERVICE,
    PUS_GETTMSUBTYPE,
    PUS_SETTMSUBTYPE,
    PUS_GETTCSERVICE,
    PUS_SETTCSERVICE,
    PUS_GETTCSUBTYPE,
    PUS_SETTCSUBTYPE,
	PUS_GETTMTIMEREFSTATUS,
	PUS_SETTMTIMEREFSTATUS,
	PUS_GETTMMESSAGETYPECOUNTER,
	PUS_SETTMMESSAGETYPECOUNTER,
	PUS_GETTMDESTINATION,
	PUS_SETTMDESTINATION,
	PUS_GETTCSOURCE,
	PUS_SETTCSOURCE,
	PUS_GETTMPACKETTIME,
	PUS_SETTMPACKETTIME,
	PUS_GETTCACKFLAGACCEPTANCE,
	PUS_GETTCACKFLAGSTART,
	PUS_GETTCACKFLAGPROGRESS,
	PUS_GETTCACKFLAGCOMPLETION,
	PUS_SETTCACKFLAGS,
	PUS_CHECKTMHEADERDEFAULTS,
	PUS_CHECKTCHEADERDEFAULTS,
	PUS_NOW,
    
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
