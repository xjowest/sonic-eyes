#include "main.h"

mainClass::mainClass(){
    camInterface = new cameraInterface();
    scrnInterface = new screenInterface();

    setup();
}

mainClass::~mainClass(){
    delete camInterface;
    delete scrnInterface;
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
