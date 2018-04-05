#include "py/nlr.h"
#include "py/obj.h"
#include "py/runtime.h"
#include "py/binary.h"

#include <stdio.h>

STATIC mp_obj_t exampleFunction(mp_obj_t what)
{
    int aux =  mp_obj_get_int(what);
    printf("Integer param read: %d\n", aux);
    return mp_const_true;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(userFunctions_exampleFunction_obj, exampleFunction);


STATIC const mp_map_elem_t userFunctions_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_userFunctions) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_exampleFunction), (mp_obj_t)&userFunctions_exampleFunction_obj },
};

STATIC MP_DEFINE_CONST_DICT (
    mp_module_userFunctions_globals,
	userFunctions_globals_table
);

const mp_obj_module_t mp_module_userFunctions = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_userFunctions_globals,
};
