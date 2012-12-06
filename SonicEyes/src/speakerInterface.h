#ifndef SPEAKER_INTERFACE_H
#define SPEAKER_INTERFACE_H

#include "typeDefs.h"
#include "SDL/SDL.h"
#include <SDL/SDL_audio.h>
#include <queue>
#include <cmath>

struct SoundObject
{
    double freq;
    int samplesLeft;
};

class speakerInterface{
public:
    speakerInterface();
    ~speakerInterface();
    
    void playSound(double freq, int duration);    
    void generateSamples(Sint16 *stream, int length);
    void wait();
    
private:
    SDL_AudioSpec * desiredAudioSpec;
    SDL_AudioSpec * obtainedAudioSpec;
    std::queue<SoundObject> sounds;
    double v;

};

void audioCallback(void * userData, Uint8 * stream, int len);


#endif
