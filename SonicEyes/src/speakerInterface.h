#ifndef SPEAKER_INTERFACE_H
#define SPEAKER_INTERFACE_H

#include "typeDefs.h"
#include "SDL/SDL.h"
#include <SDL/SDL_audio.h>

class speakerInterface{
public:
    speakerInterface();
    ~speakerInterface();
    
    void playSound(SampleBurst * sampleBurst);    
    void refillSoundBuffer(Sint16 * stream);
    void wait();
    
private:
    SDL_AudioSpec * desiredAudioSpec;
    SDL_AudioSpec * obtainedAudioSpec;
    SampleBurst * sampleBuffer;
};

void audioCallback(void * _userData, Uint8 * _stream, int _length);


#endif
