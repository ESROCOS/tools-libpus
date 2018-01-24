## Template for generating the PUS ST[23] Files management
## service configuration
##
## The template expects the following arguments:
## - config: a dictionary containing the service configuration, read from the JSON file
## - tempvars: an empty dictionary to be used to store global counters within the template 
##             (see http://docs.makotemplates.org/en/latest/runtime.html#context)


// PUS service ST[23] configuration
// 
// File automatically generated from the pus_st23_config.h.mako template
//
//                     -- DO NOT MODIFY --

#include "pus_st23_config.h"
#include "pus_file_management.h"




pusSt23FilesTableSize_t pus_files_tableSize = ${config['maximumFiles']};

pusError_t pus_files_configure()
{


    return PUS_NO_ERROR;
}




