#ifndef SPEAKER_INTERFACE_H
#define SPEAKER_INTERFACE_H

#include "typeDefs.h"

class speakerInterface{
public:
    speakerInterface();
    ~speakerInterface();

    void playSound(SoundData soundToBePlayed);
    
private:
};

#endif
