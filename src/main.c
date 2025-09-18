#include <stdio.h>

#include "cinder2d/cinder2d.h"

int main(int argc, char *argv[])
{
    Cinder2D_Context c = {};

    cinder2d_window_con(&c);
    c.window->cinder2d_window_init(&c.window);

    SDL_Delay(2000);
    c.window->cinder2d_window_destroy(&c.window);
    return 0;
}