#ifndef MAIN_H
#define MAIN_H

#include "SDL/SDL.h"

#include "typeDefs.h"
#include "cameraInterface.h"
#include "screenInterface.h"
#include "speakerInterface.h"
#include "sonarInterface.h"
#include "clusterAlgorithm.h"
#include "analysisAlgorithm.h"
#include "soundCreator.h"

class mainClass{

public:
    mainClass();
    ~mainClass();

    bool setup();
	bool mainLoop();
    void update();
    void drawImageOnScreen(ClusterData & cluster);
    void playSoundInSpeakers(ClusterData & cluster);
    bool shutDown();

private:
    cameraInterface * camInterface;
    screenInterface * scrnInterface;
    speakerInterface * spkrInterface;
    sonarInterface * snrInterface;
    clusterAlgorithm * clusterAlgo;
    analysisAlgorithm * analysisAlgo;
    soundCreator * sndCreator;

};

#endif
