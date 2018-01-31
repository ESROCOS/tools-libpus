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


#ifndef PUS_ST12_CONFIG_H
#define PUS_ST12_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif


#include "pus_error.h"
#include "pus_types.h"
#include "pus_st03_config.h"
#include "pus_parameter_monitoring.h"


// Parameter limit
#define PUS_ST12_PARAM_LIMIT ((pusSt03ParamId_t) ${config['parameters'].__len__()})

extern pusSt12PmonDefinition pus_pmon_definitionList[];

extern pusError_t pus_pmon_configure();

#ifdef __cplusplus
}
#endif


#endif // PUS_ST03_CONFIG_H
