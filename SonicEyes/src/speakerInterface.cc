#include "speakerInterface.h"

speakerInterface::speakerInterface() {
    desiredAudioSpec = new SDL_AudioSpec();
    obtainedAudioSpec = new SDL_AudioSpec();
    
    // Set the audio format 
    desiredAudioSpec->freq = SAMPLE_FREQUENCY;
    desiredAudioSpec->format = AUDIO_S16SYS;
    desiredAudioSpec->channels = 2;    // 1 = mono, 2 = stereo 
    desiredAudioSpec->samples = NUMBER_OF_SOUND_SAMPLES;  // Good low-latency value for callback 
    desiredAudioSpec->callback = audioCallback;
    desiredAudioSpec->userdata = this;

    // Open the audio device, forcing the desired format 
    if ( SDL_OpenAudio(desiredAudioSpec, obtainedAudioSpec) != 0 ) {
        fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
	exit(0);
    }

    delete desiredAudioSpec;

    sampleBuffer = new SampleBurst();

    // start play audio    
    SDL_PauseAudio(0);
}

speakerInterface::~speakerInterface() {
    SDL_CloseAudio();
    delete obtainedAudioSpec;
    delete sampleBuffer;
}

void speakerInterface::playSound(SampleBurst * sampleBurst) {
    SDL_LockAudio();
    memset(sampleBuffer->burst, 0, sizeof(Sample) * NUMBER_OF_SOUND_SAMPLES);
    memcpy(sampleBuffer->burst, sampleBurst->burst, sizeof(Sample) * NUMBER_OF_SOUND_SAMPLES);
    SDL_UnlockAudio();    
}

void speakerInterface::wait() {
    SDL_Delay(100);
    SDL_LockAudio();
    SDL_UnlockAudio();
}

void speakerInterface::refillSoundBuffer(Sint16 * stream) {
    memcpy(stream, sampleBuffer->burst, sizeof(Sint16) * NUMBER_OF_SOUND_SAMPLES);
}


/******************************************************************/
/* Global functions                                               */
/******************************************************************/

void audioCallback(void * _userData, Uint8 * _stream, int _length) {
    Sint16 * stream = (Sint16 *) _stream;
    speakerInterface * speaker = (speakerInterface*) _userData;
    speaker->refillSoundBuffer(stream);
}
