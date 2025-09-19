#include <stdbool.h>

#include "cinder2d/cinder2d.h"

int main(void)
{
    CINDER2D_LOG("Hello, World!");

    Cinder2D_Context c = {0};
    cinder2d_context_con(&c);
    c.cinder2d_context_init(&c);

    cinder2d_create_window(&c, "Sup!", 1600, 1000, SDL_WINDOW_OPENGL);

    c.input->cinder2d_input_init = cinder2d_input_init;
    c.input->cinder2d_input_update = cinder2d_input_update;
    c.input->cinder2d_input_init(c.input);
    
    bool x = true;

    while (x)
    {
        c.input->cinder2d_input_update(c.input);
        
    }
   
    SDL_Delay(1000);

    c.cinder2d_context_destroy(&c);

    return 0;
}