#ifndef MAIN_H
#define MAIN_H

#include "typeDefs.h"
#include "cameraInterface.h"
#include "screenInterface.h"
#include "speakerInterface.h"
#include "sonarInterface.h"

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
    speakerInterface * spkrInterface;
    sonarInterface * snrInterface;

    ImageArray hej; 
};

#endif
