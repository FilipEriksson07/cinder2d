#include <stdlib.h>
#include <stdbool.h>

#include "cinder2d/cinder2d.h"
#include "cinder2d/cinder2d_window.h"

void cinder2d_context_con(struct Cinder2D_Context *self)
{
    if (!self)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Null passed instead of self");
        #endif
        return;
    }

    self->cinder2d_context_init = cinder2d_context_init;
    self->cinder2d_context_destroy = cinder2d_context_destroy;

    return;
}

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
    #if CINDER2D_USE_WINDOW
        if (SDL_Init(SDL_INIT_VIDEO) != true)
        {
            #if CINDER2D_DEBUG_MODE
                CINDER2D_ERROR("Failed to initialize SDL: %s", SDL_GetError());
            #endif
            return EXIT_FAILURE;
        }

        self->window = malloc(sizeof(Cinder2D_Window));
        if (!self->window)
        {
            #if CINDER2D_DEBUG_MODE
                CINDER2D_ERROR("Failed to allocate memory for a window struct");
            #endif
            self->window = NULL;
            return EXIT_FAILURE;
        }
    #endif
    // ==== INPUT ====
    #if CINDER2D_USE_INPUT
        if (SDL_Init(SDL_INIT_EVENTS) != true)
        {
            #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Failed to initialize SDL: %s", SDL_GetError());
            #endif
            self->input = NULL;
            return EXIT_FAILURE;
        }

        self->input = malloc(sizeof(Cinder2D_Input));
        if (!self->input)
        {
            #if CINDER2D_DEBUG_MODE
                CINDER2D_ERROR("Failed to allocate memory for a input struct");
            #endif
            self->input = NULL;
            return EXIT_FAILURE;
        }
    #endif

    return EXIT_SUCCESS;
}

// The user always has to handle the life time of the class
void cinder2d_context_destroy(struct Cinder2D_Context *self)
{
    if (!self)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Null passed instead of self");
        #endif
        return;
    }

    #if CINDER2D_USE_WINDOW
        if (self->window)
        {
            self->window->cinder2d_window_destroy(self->window);
            free(self->window);
            self->window = NULL;
        }

        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    #endif

    #if CINDER2D_USE_INPUT
        if (self->input)
        {
            // TODO call the destructor of the input class!
            free(self->input);
            self->input = NULL;
        }

        SDL_QuitSubSystem(SDL_INIT_EVENTS);
    #endif

    SDL_Quit();
}

// ==== High level functions ====
#if CINDER2D_USE_WINDOW
int cinder2d_create_window(struct Cinder2D_Context *self, const char *title, unsigned int width, unsigned int height, SDL_WindowFlags flags)
{
    if (!self)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Null passed instead of self");
        #endif
        return EXIT_FAILURE;
    }

    cinder2d_window_con(self->window);
    if (cinder2d_window_init(self->window, title, width, height, flags) != EXIT_SUCCESS)
    {
        #if CINDER2D_DEBUG_MODE
            CINDER2D_ERROR("Failed to create a window, did you forget to add the OpenGL window flag?");
        #endif

        self->window = NULL;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
#else
int cinder2d_create_window(struct Cinder2D_Context *self, const char *title, unsigned int width, unsigned int height, SDL_WindowFlags flags)
{
    (void)self;
    (void)title;
    (void)width;
    (void)height;
    (void)flags;

    CINDER2D_ERROR("Window module is disabled for this build, enable it to use the window functions");

    return EXIT_SUCCESS;
}
#endif