#include "main.h"

mainClass::mainClass() {
}

mainClass::~mainClass() {
}

bool mainClass::setup() {
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
	return false;
    }
    camInterface = new cameraInterface();
    scrnInterface = new screenInterface();
    spkrInterface = new speakerInterface();
    snrInterface = new sonarInterface();
    clusterAlgo = new clusterAlgorithm();
    analysisAlgo = new analysisAlgorithm();
    sndCreator = new soundCreator();

    return true;
}

bool mainClass::mainLoop() {
	SDL_Event event;

	while(true) {
		while(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return true;
			}	
		}
		drawImageOnScreen();
		//playSoundInSpeakers();
	}
}

void mainClass::update() {
}


void mainClass::drawImageOnScreen() {
    
    ImageArray tempImage;
    ImageArray originalImage;
    EdgePositions positions;
    memset(&positions, false, sizeof(EdgePositions));

    camInterface->getCurrentImage(&tempImage);
    originalImage = tempImage;    
    analysisAlgo->analyzeData(tempImage, positions);
    for(int i = 0; i < IMAGE_WIDTH; i++) {
	for(int j = 0; j < IMAGE_HEIGHT; j++) {
	    if(tempImage.values[i][j] < originalImage.values[i][j]){		
		tempImage.values[i][j] = originalImage.values[i][j];
	    }
	}
    }
    scrnInterface->render(tempImage);
    
}

void mainClass::playSoundInSpeakers() {
    SampleBurst * sampleBurst = new SampleBurst();
    
    sndCreator->createSound(sampleBurst);
    spkrInterface->playSound(sampleBurst);
    
    delete sampleBurst;
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

int main(int argc, char* args[]) {
    mainClass * main = new mainClass();    
    if(!main->setup()) {
	printf("error during setup!\n");
	return -1;
    }

    if(!main->mainLoop()) {
		return -1;
	}

    if(!main->shutDown()) {
	printf("error during shut down!\n");
	return -1;
    }
    delete main;
    return 0;
}
