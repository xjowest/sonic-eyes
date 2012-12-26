#ifndef SOUND_CREATOR_H
#define SOUND_CREATOR_H

#include "typeDefs.h"
#include <cmath>

class soundCreator{
public:
    soundCreator();
    ~soundCreator();
    
    void createSound(SampleBurst * sampleBurst, ClusterData & cluster);
	void createSweepSound(SampleBurst * sampleBurst, ClusterData & cluster);
    
private:
};

#endif
