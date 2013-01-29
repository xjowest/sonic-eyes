#ifndef SPEAKER_INTERFACE_H
#define SPEAKER_INTERFACE_H

#include "typeDefs.h"
#include "SDL/SDL.h"
#include <SDL/SDL_audio.h>
#include <cmath>
#include <OpenAL/al.h>
#include <OpenAL/alc.h>

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
	size_t m_bufSize;
	ALCdevice * m_dev;
	ALCcontext * m_ctx;
	ALuint m_buf;
	ALuint m_src;
};

void audioCallback(void * _userData, Uint8 * _stream, int _length);


#endif
