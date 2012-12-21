#include "soundCreator.h"

soundCreator::soundCreator() {
}

soundCreator::~soundCreator() {
}

void soundCreator::createSound(SampleBurst * sampleBurst, ClusterData & cluster) {
    for(int i = 0; i < (int)cluster.clusters.size(); i++) {	
	for(int j = cluster.clusters[i].startIndex; j <= cluster.clusters[i].endIndex; j++){ // j+ 100 = frekvens i Hz
	    for(int t = 0; t < NUMBER_OF_SOUND_SAMPLES; t++) {
		float desiredFrequency = j+100;
		sampleBurst->burst[t] += (int)(28000 - (cluster.clusters[i].depth * 18000 / 5)) * (sin((t * desiredFrequency * 2 * M_PI) / SAMPLE_FREQUENCY / 2));
	    }
	}
    }

    int highestAmplitude = 0;
    for(int t = 0; t < NUMBER_OF_SOUND_SAMPLES; t++) {
	if(sampleBurst->burst[t] > highestAmplitude) {
	    highestAmplitude = sampleBurst->burst[t];
	}
    }

    for(int t = 0; t < NUMBER_OF_SOUND_SAMPLES; t++) {
	//printf("Burst value %i\n", sampleBurst->burst[t]);
	//printf("Highest value %i\n", highestAmplitude);
	sampleBurst->burst[t] = (int)((float)sampleBurst->burst[t] / (float)highestAmplitude * 28000);
	//printf("Burst normalized %i\n", sampleBurst->burst[t]);
    }
//    float desiredAmplitude = 28000.0 - (cluster.clusters[i].depth * 18000 / 5.0);
//    sampleBurst->burst[t] = sampleBurst->burst[t] * desiredAmplitude;
/*    
      for(int i = 0; i < NUMBER_OF_SOUND_SAMPLES; i++) {
      float desiredFrequency = 500;
      sampleBurst->burst[i] = (int)(25000 * sin((i * desiredFrequency * 2 * M_PI) / SAMPLE_FREQUENCY / 2));
      printf("sample[%i]:%i\n",i,sampleBurst->burst[i]);
      printf("realValue:%f\n", (i * desiredFrequency) / SAMPLE_FREQUENCY / 2);
      printf("desired:%f\n",desiredFrequency);
      }
*/
}
