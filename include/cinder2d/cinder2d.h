#pragma once

#include <stdio.h>
#include <stdarg.h>

#include "cinder2d_config.h"

#if CINDER2D_USE_WINDOW
    #include "cinder2d/cinder2d_window.h"
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
    #define CINDER2D_LOG(fmt, ...) cinder2d_log_internal("DEBUG", __FILE__, __LINE__, fmt, ##__VA_ARGS__)
    #define CINDER2D_WARN(fmt, ...) cinder2d_log_internal("WARNING", __FILE__, __LINE__, fmt, ##__VA_ARGS__)
    #define CINDER2D_ERROR(fmt, ...) cinder2d_log_internal("ERROR", __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#else
    #define CNDER2D_LOG(fmt, ...) ((void)0)
    #define CINDER2D_WARN(fmt, ...) ((void)0)
    #define CINDER2D_ERROR(fmt, ...) ((void)0)
#endif

typedef struct Cinder2D_Context
{
    #if CINDER2D_USE_WINDOW
        Cinder2D_Window *window;
    #endif
} Cinder2D_Context;