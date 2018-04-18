/* This file was generated automatically: DO NOT MODIFY IT ! */

#ifndef VM_IF_filemanagement
#define VM_IF_filemanagement

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Function initialization:
 * Calls all dependent user (or GUI) startup code - including sychronous RI
*/
void init_filemanagement();

void filemanagement_copy ();
extern void filemanagement_PI_copy ();
void filemanagement_delete ();
extern void filemanagement_PI_delete ();
void filemanagement_create ();
extern void filemanagement_PI_create ();
void filemanagement_getAttributes ();
extern void filemanagement_PI_getAttributes ();
#ifdef __cplusplus
}
#endif

#endif
