#include "pus_file_management.h"


#ifdef __gnu_linux__
	#include "pus_file_management_linux.c"
#endif

//TODO
#ifdef RTEMS
	#include "pus_filemanagement_rtems.c"
#endif
