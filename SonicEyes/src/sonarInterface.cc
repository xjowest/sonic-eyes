#include "sonarInterface.h"

extern "C" void GetSonarData(DepthValue z, char* fileName, U8 size);

sonarInterface::sonarInterface() {
}

sonarInterface::~sonarInterface(){
}

void sonarInterface::getDepthData(DepthData depth){
    
    DepthValue zData[SONAR_WIDTH];
    int i;
    char fileName[] = "../resources/currentDepth.txt";    
    
    GetSonarData(zData, fileName, (U8)SONAR_WIDTH);
    
    for(i=0;i<SONAR_WIDTH;i++){
	currentDepth.values[i] = zData[i];
    }

    depth = currentDepth;
    
}
