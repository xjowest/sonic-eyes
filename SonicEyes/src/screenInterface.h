#ifndef SCREEN_INTERFACE_H
#define SCREEN_INTERFACE_H

#include "SDL/SDL.h"

#include "typeDefs.h"

class screenInterface{
public:
    screenInterface();
    ~screenInterface();

    void render(ImageArray imageToRender);
    
private:
    SDL_Surface * screenSurface;
};

#endif
