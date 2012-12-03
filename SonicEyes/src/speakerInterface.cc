#include "speakerInterface.h"

speakerInterface::speakerInterface() {
    v = 0;
    desiredAudioSpec = new SDL_AudioSpec();
    obtainedAudioSpec = new SDL_AudioSpec();
    
    // Set the audio format 
    desiredAudioSpec->freq = 44100;
    desiredAudioSpec->format = AUDIO_S16SYS;
    desiredAudioSpec->channels = 2;    // 1 = mono, 2 = stereo 
    desiredAudioSpec->samples = 2048;  // Good low-latency value for callback 
    desiredAudioSpec->callback = audioCallback;
    desiredAudioSpec->userdata = this;

    // Open the audio device, forcing the desired format 
    if ( SDL_OpenAudio(desiredAudioSpec, obtainedAudioSpec) != 0 ) {
        fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
	exit(0);
    }

    // start play audio
    SDL_PauseAudio(0);
}

speakerInterface::~speakerInterface() {
    SDL_CloseAudio();
    delete desiredAudioSpec;
    delete obtainedAudioSpec;
}

void speakerInterface::playSound(double freq, int duration) {
    SoundObject so;
    so.freq = freq;
    so.samplesLeft = duration * 44100 / 1000;

    SDL_LockAudio();
    sounds.push(so);
    SDL_UnlockAudio();    
}

void speakerInterface::generateSamples(Sint16 *stream, int length) {
    int i = 0;
    while (i < length) {

        if (sounds.empty()) {
            while (i < length) {
                stream[i] = 0;
                i++;
            }
            return;
        }
        SoundObject& so = sounds.front();

        int samplesToDo = std::min(i + so.samplesLeft, length);
        so.samplesLeft -= samplesToDo - i;

        while (i < samplesToDo) {
            stream[i] = 28000 * std::sin(v * 2 * M_PI / 44100);
            i++;
            v += so.freq;
        }

        if (so.samplesLeft == 0) {
            sounds.pop();
        }
    }
}

void speakerInterface::wait() {
    int size;
    do {
        SDL_Delay(20);
        SDL_LockAudio();
        size = sounds.size();
        SDL_UnlockAudio();
    } while (size > 0);
}

void audioCallback(void * userData, Uint8 * _stream, int len) {
    Sint16 *stream = (Sint16*) _stream;
    int length = len / 2;
    speakerInterface * speaker = (speakerInterface*) userData;

    speaker->generateSamples(stream, length);
}
