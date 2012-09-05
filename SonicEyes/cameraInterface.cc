#include "cameraInterface.h"

cameraInterface::cameraInterface(){
    camWidth 		= 320;
	camHeight 		= 240;

	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(camWidth,camHeight);
}

cameraInterface::~cameraInterface(){
}

ImageArray camerInterface::getImage(){
    static ImageArray grabbedImage;

    vidGrabber.grabFrame();

    if (vidGrabber.isFrameNew()){
        convertGrabbedDataToImageArray(grabbedImage, vidGrabber.getPixels());
    }

    return grabbedImage;
}

void cameraInterface::convertGrabbedDataToImageArray(& ImageArray imArray, unsigned char * pixelData){
    for(int y = 0; y < camHeight-2; y++){
        for(int x = 0; x < camWidth-2; x++){
            imArray[x][y] = (pixelData[x*3+y*camWidth*3] + pixelData[x*3+y*camWidth*3+1] + pixelData[x*3+y*camWidth*3+2]) / 3;
        }
    }
}

