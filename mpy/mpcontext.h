#ifndef MPCONTEXT_H
#define MPCONTEXT_H

#include "py/mpstate.h"

#define MP_MAX_CONTEXT 5

// Initialize upython thread context bookkeeping
void mp_init_context_arrays();

// Returns the upython context of the current thread (NULL if error)
struct _mp_state_ctx_t* mp_get_context();

// Associates the upython context to the current thread (returns the context index, or -1 if error)
int mp_register_current_context(struct _mp_state_ctx_t* ctx);


#endif // MPCONTEXT_H
