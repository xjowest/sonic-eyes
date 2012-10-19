#include "cameraInterface.h"

cameraInterface::cameraInterface() {
}

cameraInterface::~cameraInterface(){
}

void cameraInterface::getCurrentImage(ImageArray image){
    image = currentImage;
}
