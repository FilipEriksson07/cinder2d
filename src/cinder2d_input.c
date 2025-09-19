#include <stdlib.h>
#include <stdbool.h>

#include <SDL3/SDL.h>

#include "cinder2d/cinder2d_input.h"
#include "cinder2d/cinder2d.h"

void cinder2d_input_con(struct Cinder2D_Input *self)
{
    if (!self)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Null passed instead of self");
        #endif
        return;
    }

    self->cinder2d_input_init = cinder2d_input_init;
    self->cinder2d_input_update = cinder2d_input_update;
}

int cinder2d_input_init(struct Cinder2D_Input *self)
{
    if (!self)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Null passed instead of self");
        #endif
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void cinder2d_input_process_event(Cinder2D_Input *self, const SDL_Event *event)
{
    if (!self || !event)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Null passed instead of self/event");
        #endif
        return;
    }

    
}

void cinder2d_input_update(struct Cinder2D_Input *self)
{
    if (!self)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Null passed instead of self");
        #endif
        return;
    }

}