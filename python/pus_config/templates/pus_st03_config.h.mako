## Template for generating the PUS ST[03] housekeeping and diagnostic
## service configuration
##
## The template expects the following arguments:
## - config: a dictionary containing the service configuration, read from the JSON file
## - tempvars: an empty dictionary to be used to store global counters within the template 
##             (see http://docs.makotemplates.org/en/latest/runtime.html#context)
##
//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS service ST[03] configuration
// 
// File automatically generated from the pus_st30_config.h.mako template
//
//                     -- DO NOT MODIFY --


#ifndef PUS_ST03_CONFIG_H
#define PUS_ST03_CONFIG_H

#include "pus_types.h"
#ifdef PUS_CONFIGURE_HK_PARAMS_TABLE

#ifdef __cplusplus
extern "C" {
#endif


#include "pus_error.h"
#include "pus_types.h"
#include "pus_housekeeping.h"


// Datapool Parameter identifiers
<% count = 0 %>
% for param in config['parameters']:
<% 
if param['type'] == 'UINT16':
    param['type'] = 'UINT32'
elif param['type'] == 'REAL32':
    param['type'] = 'REAL64'
%>

#define ${param['label']} ((pusSt03ParamId_t) ${count}U) \
<% count = count + 1 %>
% endfor
#define PUS_ST03_PARAM_LIMIT ((pusSt03ParamId_t) ${count}U)

// Housekeeping reports identifiers
<% count = 0 %>
% for report in config['hkReports']:
#define PUS_HK_REP_${report['name']} (${count}U) \
<% count = count + 1 %>
% endfor
#define PUS_HK_NUMBER_REPORTS (${count}U)

//! Array with parameter information (length = number of parameters)
extern pusSt03ParamInfo_t pus_st03_paramInfo[];

//! Array for parameters values (all stored in 64 bits)
extern pusStoredParam_t pus_st03_params[];

//! Structure of HK reports
extern pusSt03ReportInfo_t pus_st03_HkReportInfos[];

//! First invalid parameter ID
extern const pusSt03ParamId_t pus_ST03_PARAM_LIMIT;

//! Initialize the configuration of the ST[03] service from the mission database
pusError_t pus_hk_configure();

//! Get parameters from a HK report ID.
extern pusError_t pus_hk_getReportParams(pusSt03HousekeepingReportId_t reportId, size_t *numParams, pusSt03ParamId_t* paramIds);

//Param types
typedef int32_t INT32;
typedef uint32_t UINT32;
typedef double REAL64;
typedef uint8_t BYTE;
typedef bool BOOL;

//Param getters/setters
% for param in config['parameters']:
<% 
if param['type'] == 'UINT16':
    param['type'] = 'UINT32'
elif param['type'] == 'REAL32':
    param['type'] = 'REAL64'
%>
pusError_t pus_hk_set${param['label']}(${param['type']} value);
pusError_t pus_hk_get${param['label']}(${param['type']}* value);

% endfor
 

#ifdef __cplusplus
}
#endif

#endif

#endif // PUS_ST03_CONFIG_H
