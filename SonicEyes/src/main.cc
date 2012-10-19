#include "main.h"

mainClass::mainClass(){
    camInterface = new cameraInterface();
    setup();
}

mainClass::~mainClass(){
    delete camInterface;
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
