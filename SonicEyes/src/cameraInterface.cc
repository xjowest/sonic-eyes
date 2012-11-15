#include "cameraInterface.h"

//extern "C" int GetPixelData(Pixel * img, char * fileName, unsigned short width, unsigned short height);

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
  
  GetPixelData(pixelData, fileName, IMAGE_SIZE * IMAGE_PITCH));
 
  // Make image black and white 
  for(i=0;i<IMAGE_SIZE;i++){
    bwPixelData[i] = (pixelData[i*IMAGE_PITCH] + 
		      pixelData[i*IMAGE_PITCH+1] + 
		      pixelData[i*IMAGE_PITCH+2]) / IMAGE_PITCH;
  }  
  
  // Copy pixel data into 2D-array 
  for(y=0;y<IMAGE_WIDTH;y++){
      for(x=0;x<IMAGE_HEIGHT;x++){
	currentImage.values[x][y] = *pixelData;
	pixelData++;
      }
  }
  */
  image = currentImage;
}
