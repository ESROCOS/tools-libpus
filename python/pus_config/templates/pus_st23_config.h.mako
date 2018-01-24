## Template for generating the PUS ST[23] Files management
##
## The template expects the following arguments:
## - config: a dictionary containing the service configuration, read from the JSON file
## - tempvars: an empty dictionary to be used to store global counters within the template 
##             (see http://docs.makotemplates.org/en/latest/runtime.html#context)
##

// PUS service ST[23] Files management
// 
// File automatically generated from the pus_st23_config.h.mako template
//
//                     -- DO NOT MODIFY --

#ifndef PUS_ST23_CONFIG_H
#define PUS_ST23_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif


#include "pus_error.h"
#include "pus_types.h"
#include "pus_file_management.h"


#define PUS_ST23_FILES_LIMIT ((size_t) ${config['maximumFiles']})

extern pusSt23FilesTableSize_t pus_files_tableSize;

extern pusSt23File_t pus_files_table[];

//! Initialize the configuration of the ST[23] service from the mission database
pusError_t pus_files_configure();





#ifdef __cplusplus
}
#endif


#endif // PUS_ST03_CONFIG_H
