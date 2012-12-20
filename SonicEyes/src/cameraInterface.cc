#include "cameraInterface.h"

extern "C" void GetPixelData(Pixel * img, char * fileName, int size);

cameraInterface::cameraInterface(){
}

cameraInterface::~cameraInterface(){
}

void cameraInterface::getCurrentImage(ImageArray * image){
    Pixel pixelData[IMAGE_SIZE * IMAGE_PITCH];
    Pixel bwPixelData[IMAGE_SIZE];
    char fileName[] = "./resources/bild.raw";
    int i,x,y = 0;

    GetPixelData(pixelData, fileName, IMAGE_SIZE * IMAGE_PITCH);

    // Make image black and white 
    for(i=0;i<IMAGE_SIZE;i++){
	bwPixelData[i] = (pixelData[i*IMAGE_PITCH] + 
			  pixelData[i*IMAGE_PITCH+1] + 
			  pixelData[i*IMAGE_PITCH+2]) / IMAGE_PITCH;
    }
    
    // Copy pixel data into 2D-array 
    for(y=0;y<IMAGE_HEIGHT;y++){
		for(x=0;x<IMAGE_WIDTH;x++){
	    	image->values[x][y] = bwPixelData[x + y * IMAGE_WIDTH];
		}
    }
}
