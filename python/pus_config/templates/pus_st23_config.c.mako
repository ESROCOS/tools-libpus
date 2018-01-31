## Template for generating the PUS ST[23] Files management
## service configuration
##
## The template expects the following arguments:
## - config: a dictionary containing the service configuration, read from the JSON file
## - tempvars: an empty dictionary to be used to store global counters within the template 
##             (see http://docs.makotemplates.org/en/latest/runtime.html#context)

//
// H2020 ESROCOS Project
// Company: GMV Aerospace & Defence S.A.U.
// Licence: GPLv2
//
// PUS service ST[23] configuration
// 
// File automatically generated from the pus_st23_config.h.mako template
//
//                     -- DO NOT MODIFY --


#include "pus_st23_config.h"
#include "pus_file_management.h"
#include "pus_types.h"
#include <string.h>




size_t pus_files_filesTableSize = ${config['maximumFiles']};

pusSt23File_t pus_files_filesTable[${config['maximumFiles']}];

size_t pus_files_repositoriesTableSize = ${len(config['repositories'])};

pusSt23Repository_t pus_files_repositoriesTable[${len(config['repositories'])}];


pusError_t pus_files_configure()
{
	% for repo in config['repositories']:
	memcpy(pus_files_repositoriesTable[${repo['label']}].repository.arr, "${repo['label']}", pus_ST23_MAX_SIZE_REPOSITORY_PATH - 1);
	pus_files_repositoriesTable[${repo['label']}].repository.nCount = strlen((char*)pus_files_repositoriesTable[${repo['label']}].repository.arr) + 1;

	memcpy(pus_files_repositoriesTable[${repo['label']}].domain.arr, "${repo['domain']}", pus_ST23_MAX_SIZE_REPOSITORY_DOMAIN - 1);
	pus_files_repositoriesTable[${repo['label']}].domain.nCount = strlen((char*)pus_files_repositoriesTable[${repo['label']}].domain.arr) + 1;

	memcpy(pus_files_repositoriesTable[${repo['label']}].system.arr, "${repo['system']}", pus_ST23_MAX_SIZE_REPOSITORY_DOMAIN - 1);
	pus_files_repositoriesTable[${repo['label']}].system.nCount = strlen((char*)pus_files_repositoriesTable[${repo['label']}].system.arr) + 1;
	
	% endfor
	
    return PUS_NO_ERROR;
}




