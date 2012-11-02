#include "main.h"

mainClass::mainClass(){
}

mainClass::~mainClass(){
}

bool mainClass::setup(){
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
	return false;
    }
    
    camInterface = new cameraInterface();
    scrnInterface = new screenInterface();
    spkrInterface = new speakerInterface();
    snrInterface = new sonarInterface();
    clusterAlgo = new clusterAlgorithm();
    analysisAlgo = new analysisAlgorithm();

    return true;
}


void mainClass::update(){
}


void mainClass::draw(){
    ImageArray temp;
    scrnInterface->render(temp);
}

bool mainClass::shutDown(){    
    delete camInterface;
    delete scrnInterface;
    delete spkrInterface;
    delete snrInterface;
    delete clusterAlgo;
    delete analysisAlgo;

    SDL_Quit();
    return true;
}

int main(int argc, char* args[]){
    mainClass * main = new mainClass();    
    if(!main->setup()) {
	printf("error during setup!\n");
	return -1;
    }

    main->draw();

    if(!main->shutDown()) {
	printf("error during shut down!\n");
	return -1;
    }
    delete main;
    return 0;
}
