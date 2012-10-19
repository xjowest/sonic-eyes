#include "main.h"

mainClass::mainClass(){
    camInterface = new cameraInterface();
    scrnInterface = new screenInterface();
    spkrInterface = new speakerInterface();
    snrInterface = new sonarInterface();
    clstrAlgo = new clusterAlgorithm();

    setup();
}

mainClass::~mainClass(){
    delete camInterface;
    delete scrnInterface;
    delete spkrInterface;
    delete snrInterface;
    delete clstrAlgo;
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
