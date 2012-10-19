#ifndef MAIN_H
#define MAIN_H

#include "typeDefs.h"
#include "cameraInterface.h"
#include "screenInterface.h"

class mainClass{

public:
    mainClass();
    ~mainClass();

    void setup();
    void update();
    void draw();

private:
    cameraInterface * camInterface;
    screenInterface * scrnInterface;

    ImageArray hej; 
};

#endif
