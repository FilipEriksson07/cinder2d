#pragma once

#include <stdbool.h>

#include <SDL3/SDL.h>

typedef enum Cinder2D_InputKey
{
    CINDER2D_KEY_W,
    CINDER2D_KEY_A,
    CINDER2D_KEY_S,
    CINDER2D_KEY_D
} Cinder2D_InputKey;

typedef struct Cinder2D_InputState
{
    bool down;
    bool pressed;
    bool released;
} Cinder2D_InputState;

typedef struct Cinder2D_Input
{
    Cinder2D_InputState *keys;
    unsigned int n_keys;

    int (*cinder2d_input_init)(struct Cinder2D_Input *self);
    void (*cinder2d_input_update)(struct Cinder2D_Input *self);
} Cinder2D_Input;

void cinder2d_input_con(struct Cinder2D_Input *self);
int cinder2d_input_init(struct Cinder2D_Input *self);
void cinder2d_input_update(struct Cinder2D_Input *self);