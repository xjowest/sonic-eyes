#include "screenInterface.h"

screenInterface::screenInterface() {
	screenSurface = NULL;
	screenSurface = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
}

screenInterface::~screenInterface(){
	SDL_FreeSurface(screenSurface);
}

void screenInterface::render(ImageArray imageToRender){	
	for(int i = 0; i < IMAGE_WIDTH; i++) {
		for(int j = 0; j < IMAGE_HEIGHT; j++) {			
			Uint32 currPixelColor;  
			currPixelColor = SDL_MapRGB(screenSurface->format,
				imageToRender.values[i][j], 
				imageToRender.values[i][j], 
				imageToRender.values[i][j]);

			Uint32 *currPixelMemoryPos;
			currPixelMemoryPos = (Uint32*) screenSurface->pixels + (IMAGE_WIDTH * j + i);
			*currPixelMemoryPos = currPixelColor;
		}
	}

	SDL_Flip(screenSurface);
}
