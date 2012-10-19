#include "main.h"

mainClass::mainClass(){
    camInterface = new cameraInterface();
    scrnInterface = new screenInterface();
    spkrInterface = new speakerInterface();

    setup();
}

mainClass::~mainClass(){
    delete camInterface;
    delete scrnInterface;
    delete spkrInterface;
}

void mainClass::setup(){
}


void mainClass::update(){
}


void mainClass::draw(){
}

int main(){
    mainClass * main = new mainClass();
    delete main;
    return 0;
}
