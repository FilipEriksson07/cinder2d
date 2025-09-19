#pragma once

#include <stdbool.h>

#include <SDL3/SDL.h>

typedef struct Cinder2D_Window
{
    char *title;
    unsigned int width, height;
    SDL_WindowFlags flags;

    SDL_Window *sdl_window;
    SDL_GLContext gl_context;
    bool current_context;

    int (*cinder2d_window_init)(struct Cinder2D_Window *self, const char *title, unsigned int width, unsigned int height, SDL_WindowFlags flags);
    void (*cinder2d_window_destroy)(struct Cinder2D_Window *self);
} Cinder2D_Window;

void cinder2d_window_con(struct Cinder2D_Window *self);
int cinder2d_window_init(struct Cinder2D_Window *self, const char *title, unsigned int width, unsigned int height, SDL_WindowFlags flags);
void cinder2d_window_destroy(struct Cinder2D_Window *self);