#include <stdlib.h>

#include "cinder2d/cinder2d.h"

int cinder2d_context_init(struct Cinder2D_Context *self)
{
    if (!self)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Null passed instead of self");
        #endif
        return EXIT_FAILURE;
    }

    // ==== WINDOW ====
    self->window = malloc(sizeof(Cinder2D_Window));
    if (!self->window)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Failed to allocate memory for a window struct");
        #endif
        self->window = NULL;
        return EXIT_FAILURE;
    }

    self->window = NULL;
}