#include "pus_types.h"
#ifdef PUS_CONFIGURE_OBCP_ENGINE

#include "py/nlr.h"
#include "py/obj.h"
#include "py/runtime.h"
#include "py/binary.h"

#include <stdio.h>

STATIC mp_obj_t helloTest(mp_obj_t what)
{
    int aux =  mp_obj_get_int(what);
    printf("Hello! Test int param %d\n", aux);
    return mp_const_true;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mymodule_helloTest_obj, helloTest);


STATIC const mp_map_elem_t testmodule_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_mymodule) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_helloTest), (mp_obj_t)&mymodule_helloTest_obj },
};

STATIC MP_DEFINE_CONST_DICT (
    mp_module_testmodule_globals,
    testmodule_globals_table
);

const mp_obj_module_t mp_module_testmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_testmodule_globals,
};

#endif

