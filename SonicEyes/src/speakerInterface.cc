#include "speakerInterface.h"

speakerInterface::speakerInterface() 
	: m_bufSize(0)
	, m_dev(NULL)
	, m_ctx(NULL)
	, m_src(0)
{
	// Init device
	const char *defname = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
	m_dev = alcOpenDevice(defname);
	m_ctx = alcCreateContext(m_dev, NULL);
	alcMakeContextCurrent(m_ctx);

	// Generate sound buffer
	
	alGenBuffers(1, &m_buf);
	m_bufSize = NUMBER_OF_SECONDS * SAMPLE_FREQUENCY;
    sampleBuffer = new SampleBurst();
}

speakerInterface::~speakerInterface() {
	alcMakeContextCurrent(NULL);
	alcDestroyContext(m_ctx);
	alcCloseDevice(m_dev);
	alSourceStop(m_src);
	alDeleteSources(1, &m_src);
    delete sampleBuffer;
}

void speakerInterface::playSound(SampleBurst * sampleBurst) {
    alBufferData(m_buf, AL_FORMAT_MONO16, sampleBurst->burst, m_bufSize * sizeof(short), SAMPLE_FREQUENCY);
 
    /* Set-up sound source and play buffer */
    alGenSources(1, &m_src);
    alSourcei(m_src, AL_BUFFER, m_buf);

	alSourcef(m_src, AL_SEC_OFFSET, 0.0f);
	alSourcePlay(m_src);
}

void speakerInterface::wait() {

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
