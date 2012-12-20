#include "sonarInterface.h"

extern "C" void GetSonarData(DepthValue * z, char* fileName, int size);

sonarInterface::sonarInterface() {
}

sonarInterface::~sonarInterface(){
}

void sonarInterface::getDepthData(DepthData * depth){
    
  DepthValue zData[SONAR_WIDTH];
  int i;
  char fileName[] = "./resources/currentDepth.txt";    
  
  GetSonarData(zData, fileName, SONAR_WIDTH);
  
  for(i=0;i<SONAR_WIDTH;i++){
  	depth->values[i] = zData[i];
  }
      
}
