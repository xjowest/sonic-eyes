#include "cameraInterface.h"

//extern "C" int GetPixelData(Pixel * img, char * fileName, unsigned short width, unsigned short height);

cameraInterface::cameraInterface() {
}

cameraInterface::~cameraInterface(){
}

void cameraInterface::getCurrentImage(ImageArray image){
    /*
    Pixel * pixelData = (Pixel*)malloc((size_t)(IMAGE_WIDTH * IMAGE_HEIGHT));
    char fileName[] = "currentImg.raw";
    int x,y;
    
    if(-1 == GetPixelData(pixelData, fileName, IMAGE_WIDTH, IMAGE_HEIGHT)){
	//Error code
	return;
    }
    
    for(y=0;y<IMAGE_WIDTH;y++){
	for(x=0;x<IMAGE_HEIGHT;x++){
	    currentImage.values[x][y] = *pixelData;
	    pixelData++;
	}
    }
    */
    image = currentImage;
}
