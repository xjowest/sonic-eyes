#include "screenInterface.h"

screenInterface::screenInterface() {
    screenSurface = NULL;
    renderedImage = NULL;

    screenSurface = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
}

screenInterface::~screenInterface(){
    SDL_FreeSurface(screenSurface);
    SDL_FreeSurface(renderedImage);
}

void screenInterface::render(ImageArray image){
    SDL_BlitSurface(renderedImage, NULL, screenSurface, NULL);
    SDL_Flip(screenSurface);
    SDL_Delay( 2000 );
}
