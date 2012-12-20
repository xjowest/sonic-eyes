#include "soundCreator.h"

soundCreator::soundCreator() {
}

soundCreator::~soundCreator() {
}

void soundCreator::createSound(SampleBurst * sampleBurst) {
    for(int i = 0; i < NUMBER_OF_SOUND_SAMPLES; i++) {
	float desiredFrequency = 1000-(i*900/NUMBER_OF_SOUND_SAMPLES);
	sampleBurst->burst[i] = (Sample)(25000 * std::sin((i * desiredFrequency * 2 * M_PI) / SAMPLE_FREQUENCY));
    }
}
