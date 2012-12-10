#ifndef SOUND_CREATOR_H
#define SOUND_CREATOR_H

#include "typeDefs.h"
#include <queue>
#include <cmath>

class soundCreator{
public:
    soundCreator();
    ~soundCreator();
    
    void createSound(SampleBurst * sampleBurst);
    
private:
};

#endif
