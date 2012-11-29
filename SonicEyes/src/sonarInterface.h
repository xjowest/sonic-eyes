#ifndef SONAR_INTERFACE_H
#define SONAR_INTERFACE_H

#include "typeDefs.h"

class sonarInterface{
public:
    sonarInterface();
    ~sonarInterface();

    void getDepthData(DepthData depth);
    
private:
    DepthData currentDepth;
};

#endif
