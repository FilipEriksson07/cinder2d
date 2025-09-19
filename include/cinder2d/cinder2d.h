#pragma once

#include <stdio.h>
#include <stdarg.h>

#include <SDL3/SDL.h>

#include "cinder2d_config.h"

#if CINDER2D_USE_WINDOW
    #include "cinder2d/cinder2d_window.h"
#endif

#if CINDER2D_USE_INPUT
    #include "cinder2d/cinder2d_input.h"
#endif

// ==== Logging function ====
static inline void cinder2d_log_internal(const char *level, const char *file, int line, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "[%s] (%s:%d) ", level, file, line);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}

#if CINDER2D_DEBUG_MODE
    #define CINDER2D_LOG(...) cinder2d_log_internal("DEBUG", __FILE__, __LINE__, ##__VA_ARGS__)
    #define CINDER2D_WARN(...) cinder2d_log_internal("WARNING", __FILE__, __LINE__, ##__VA_ARGS__)
    #define CINDER2D_ERROR(...) cinder2d_log_internal("ERROR", __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define CINDER2D_LOG(...) ((void)0)
    #define CINDER2D_WARN(...) ((void)0)
    #define CINDER2D_ERROR(...) ((void)0)
#endif

typedef struct Cinder2D_Context
{
    #if CINDER2D_USE_WINDOW
        Cinder2D_Window *window;
    #endif
    #if CINDER2D_USE_INPUT
        Cinder2D_Input *input;
    #endif

    int (*cinder2d_context_init)(struct Cinder2D_Context *self);
    void (*cinder2d_context_destroy)(struct Cinder2D_Context *self);
} Cinder2D_Context;

void cinder2d_context_con(struct Cinder2D_Context *self);
int cinder2d_context_init(struct Cinder2D_Context *self);
void cinder2d_context_destroy(struct Cinder2D_Context *self);

#if CINDER2D_USE_WINDOW
int cinder2d_create_window(struct Cinder2D_Context *self, const char *title, unsigned int width, unsigned int height, SDL_WindowFlags flags);
#else
int cinder2d_create_window(struct Cinder2D_Context *self, const char *title, unsigned int width, unsigned int height, SDL_WindowFlags flags);
#endif