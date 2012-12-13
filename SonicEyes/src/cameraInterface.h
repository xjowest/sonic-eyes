#ifndef CAMERA_INTERFACE_H
#define CAMERA_INTERFACE_H

#include "typeDefs.h"

class cameraInterface{
public:
    cameraInterface();
    ~cameraInterface();

    void getCurrentImage(ImageArray * image);
    
private:
    ImageArray currentImage;
};

#endif
