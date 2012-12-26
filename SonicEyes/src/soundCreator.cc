#include "soundCreator.h"

soundCreator::soundCreator() {
}

soundCreator::~soundCreator() {
}

void soundCreator::createSound(SampleBurst * sampleBurst, ClusterData & cluster) {
    for(int i = 0; i < (int)cluster.clusters.size(); i++) {
		if(cluster.clusters[i].endIndex - cluster.clusters[i].startIndex > 20){
			int frequency = cluster.clusters[i].startIndex * 10 + 500;
			for(int t=0;t<NUMBER_OF_SOUND_SAMPLES;t++){
				sampleBurst->burst[t] += (4000 - (cluster.clusters[i].depth * 2000 / 5) / cluster.clusters.size()) * sin(2 * M_PI * frequency * t / SAMPLE_FREQUENCY);
			}
			
			printf("Playing frequencies: %i\n", frequency);
    	}
	}
}

void soundCreator::createSweepSound(SampleBurst * sampleBurst, ClusterData & cluster){
	for(int i = 0; i < NUMBER_OF_SOUND_SAMPLES; i++){
		sampleBurst->burst[i] = (4000 - (cluster.clusters[(int)(i * (cluster.clusters.size() - 1) / NUMBER_OF_SOUND_SAMPLES)].depth * 2000)) * sin(2 * M_PI * 500 * i / SAMPLE_FREQUENCY);
	}
	
}
