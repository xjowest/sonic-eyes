#ifndef MAIN_H
#define MAIN_H

#include "typeDefs.h"
#include "cameraInterface.h"

class mainClass{

public:
    mainClass();
    ~mainClass();

    void setup();
    void update();
    void draw();

private:
    cameraInterface * camInterface;
    ImageArray hej; 
};

#endif
