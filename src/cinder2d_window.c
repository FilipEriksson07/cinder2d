#include <stdlib.h>
#include <string.h>

#include <SDL3/SDL.h>

#include "cinder2d/cinder2d_window.h"
#include "cinder2d/cinder2d.h"

void cinder2d_window_con(struct Cinder2D_Window *self)
{
    if (!self)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Null passed instead of self");
        #endif
        return;
    }

    self->cinder2d_window_init = cinder2d_window_init;
    self->cinder2d_window_destroy = cinder2d_window_destroy;
}

int cinder2d_window_init(struct Cinder2D_Window *self, const char *title, unsigned int width, unsigned int height, SDL_WindowFlags flags)
{
    if (!self)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("NULL passed instead of self");
        #endif
        return EXIT_FAILURE;
    }

    self->title = malloc(strlen(title) + 1);
    if (!self->title)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Failed to allocate memory for the window title");
        #endif
        self->cinder2d_window_destroy(self);
        return EXIT_FAILURE;
    }
    strcpy(self->title, title);

    self->sdl_window = SDL_CreateWindow(title, width, height, flags);
    if (!self->sdl_window)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Failed to create a SDL window: %s", SDL_GetError());
        #endif
        self->cinder2d_window_destroy(self);
        return EXIT_FAILURE;
    }

    self->gl_context = SDL_GL_CreateContext(self->sdl_window);
    if (!self->gl_context)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Failed to create a GL context: %s", SDL_GetError());
        #endif
        self->cinder2d_window_destroy(self);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void cinder2d_window_destroy(struct Cinder2D_Window *self)
{
    if (!self)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_WARN("NULL passed instead of self");
        #endif
        return;
    }

    if (self->gl_context)
    {
        SDL_GL_DestroyContext(self->gl_context);
        self->gl_context = NULL;
    }
    if (self->sdl_window)
    {
        SDL_DestroyWindow(self->sdl_window);
        self->sdl_window = NULL;
    }
    if (self->title)
    {
        free(self->title);
        self->title = NULL;
    }
    self->width = 0;
    self->height = 0;
    self->flags = 0;
}