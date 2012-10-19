#include "main.h"

mainClass::mainClass(){
    camInterface = new cameraInterface();
    scrnInterface = new screenInterface();
    spkrInterface = new speakerInterface();
    snrInterface = new sonarInterface();
    clusterAlgo = new clusterAlgorithm();
    analysisAlgo = new analysisAlgorithm();

    setup();
}

mainClass::~mainClass(){
    delete camInterface;
    delete scrnInterface;
    delete spkrInterface;
    delete snrInterface;
    delete clusterAlgo;
    delete analysisAlgo;
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
