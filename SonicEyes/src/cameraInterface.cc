#include "cameraInterface.h"

//extern "C" int GetPixelData(Pixel * img, char * fileName, U16 size);

cameraInterface::cameraInterface(){
}

cameraInterface::~cameraInterface(){
}

void cameraInterface::getCurrentImage(ImageArray image){
    /*   
    Pixel pixelData[IMAGE_SIZE * IMAGE_PITCH];
    Pixel bwPixelData[IMAGE_SIZE];
    char fileName[] = "../resources/currentImg.raw";
    int i,x,y;
    
    GetPixelData(pixelData, fileName, (U16)(IMAGE_SIZE * IMAGE_PITCH));
    
    // Make image black and white 
    for(i=0;i<IMAGE_SIZE;i++){
	bwPixelData[i] = (pixelData[i*IMAGE_PITCH] + 
			  pixelData[i*IMAGE_PITCH+1] + 
			  pixelData[i*IMAGE_PITCH+2]) / IMAGE_PITCH;
    }  
    
    // Copy pixel data into 2D-array 
    for(y=0;y<IMAGE_HEIGHT;y++){
	for(x=0;x<IMAGE_WIDTH;x++){
	    currentImage.values[x][y] = bwPixelData[x + y * IMAGE_WIDTH];
	}
    }
    */
    image = currentImage;
}
