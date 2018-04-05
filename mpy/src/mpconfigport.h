// options to control how MicroPython is built

#include <stdint.h>

#define MICROPY_NLR_SETJMP          (1)
#define MICROPY_ALLOC_PATH_MAX      (128)
#define MICROPY_PERSISTENT_CODE_LOAD (1)
#define MICROPY_ENABLE_COMPILER     (0)
#define MICROPY_COMP_CONST          (0)
#define MICROPY_COMP_DOUBLE_TUPLE_ASSIGN (1)
#define MICROPY_COMP_TRIPLE_TUPLE_ASSIGN (1)
#define MICROPY_ENABLE_GC           (1)
#define MICROPY_ENABLE_IMMORTAL_GC  (0) //MODIFIED GC.collec() not working: original value = 1
#define MICROPY_ENABLE_FINALISER    (0)
#define MICROPY_ENABLE_PYSTACK      (1)
#define MICROPY_STACK_CHECK         (1)
#define MICROPY_ENABLE_SOURCE_LINE  (1)
#define MICROPY_ENABLE_DOC_STRING   (0)
#define MICROPY_ERROR_REPORTING     (MICROPY_ERROR_REPORTING_NORMAL)
#define MICROPY_OPT_COMPUTED_GOTO   (1)
#define MICROPY_CPYTHON_COMPAT      (0)
#define MICROPY_LONGINT_IMPL        (MICROPY_LONGINT_IMPL_MPZ)
#define MICROPY_FLOAT_IMPL          (MICROPY_FLOAT_IMPL_DOUBLE)
#define MICROPY_USE_INTERNAL_ERRNO  (1)
#define MICROPY_USE_INTERNAL_PRINTF (0)
#define MICROPY_PY_FUNCTION_ATTRS   (1)
#define MICROPY_PY_BUILTINS_STR_UNICODE (1)
#define MICROPY_PY_BUILTINS_STR_SPLITLINES (1)
#define MICROPY_PY_BUILTINS_MEMORYVIEW (1)
#define MICROPY_PY_BUILTINS_FROZENSET (1)
#define MICROPY_PY_MICROPYTHON_MEM_INFO (1)
#define MICROPY_PY_SYS              (1)
#define MICROPY_PY_SYS_EXIT         (1)
#define MICROPY_PY_SYS_MAXSIZE      (1)
#define MICROPY_PY_SYS_MODULES      (0)
#define MICROPY_PY_SYS_PLATFORM     "taste-x86"
#define MICROPY_PY_COLLECTIONS_ORDEREDDICT (1)
#define MICROPY_PY_GC               (1)
#define MICROPY_PY_ARRAY            (1)
#define MICROPY_PY_ARRAY_SLICE_ASSIGN (1)
#define MICROPY_PY_ATTRTUPLE        (1)
#define MICROPY_PY_COLLECTIONS      (1)
#define MICROPY_PY_MATH             (1)
#define MICROPY_PY_CMATH            (0)
#define MICROPY_PY_UBINASCII        (0)
#define MICROPY_PY_IO               (0)
#define MICROPY_PY_STRUCT           (1)
#define MICROPY_ENABLE_EMERGENCY_EXCEPTION_BUF (1)
#define MICROPY_EMERGENCY_EXCEPTION_BUF_SIZE (256)
#define MICROPY_ENABLE_MPY_MODULES  (0)
#define MICROPY_MAKE_POINTER_CALLABLE(p) ((void*)p)

#if defined(MICROPY_USE_64BIT_NAN_BOXING) && MICROPY_USE_64BIT_NAN_BOXING

// configuration for 64-bit NaN boxing
#define MICROPY_OBJ_REPR (MICROPY_OBJ_REPR_D)
typedef int64_t mp_int_t;
typedef uint64_t mp_uint_t;

#else

// configuration for objects with machine-word size
#define MICROPY_OBJ_REPR (MICROPY_OBJ_REPR_A)
typedef intptr_t mp_int_t;
typedef uintptr_t mp_uint_t;

#endif

typedef long mp_off_t;

// We need to provide a declaration/definition of alloca()
#include <alloca.h>

/*
// We define our own state accessor macros so we can have multiple instances of the VM/runtime
struct _mp_state_ctx_t;
extern struct _mp_state_ctx_t *mp_current_ctx;
#define MP_STATE_PTR (mp_current_ctx)
#define MP_STATE_VM(x) (MP_STATE_PTR->vm.x)
#define MP_STATE_MEM(x) (MP_STATE_PTR->mem.x)
#define MP_STATE_THREAD(x) (MP_STATE_PTR->thread.x)
//#define MP_STATE_PORT MP_STATE_VM
*/


// Access the interpreter context through a function to have one per thread
struct _mp_state_ctx_t;
extern struct _mp_state_ctx_t* mp_get_context();

#define MP_STATE_PTR (mp_get_context())
#define MP_STATE_VM(x) (MP_STATE_PTR->vm.x)
#define MP_STATE_MEM(x) (MP_STATE_PTR->mem.x)
#define MP_STATE_THREAD(x) (MP_STATE_PTR->thread.x)


// builtin modules
extern const struct _mp_obj_module_t mp_module_obcpModule;
extern const struct _mp_obj_module_t mp_module_testmodule;
extern const struct _mp_obj_module_t mp_module_userFunctions;
#define MICROPY_PORT_BUILTIN_MODULES \
	{ MP_OBJ_NEW_QSTR(MP_QSTR_testmodule), (mp_obj_t)&mp_module_testmodule }, \
   { MP_OBJ_NEW_QSTR(MP_QSTR_obcpModule), (mp_obj_t)&mp_module_obcpModule }, \
   { MP_OBJ_NEW_QSTR(MP_QSTR_userFunctions), (mp_obj_t)&mp_module_userFunctions }, \




