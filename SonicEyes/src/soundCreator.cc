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
	int nCluster = 0;
	double A = 0;
	double min = 5, max = 0;
	int buf_size = NUMBER_OF_SECONDS * SAMPLE_FREQUENCY;
	float freq = 400.f;
	float seconds = 0.f;
	float totalSeconds = 0.f;
	
	for(int i = 0; i < cluster.clusters.size(); i++){
		if(cluster.clusters[i].depth > max)
			max = cluster.clusters[i].depth;
			
		if(cluster.clusters[i].depth < min)
			min = cluster.clusters[i].depth;
	}
		
		
	A = 30000.0 * (1.0-((cluster.clusters[nCluster].depth - min) / (max - min)));
		
	for(int t=0; t< buf_size; t++) {
		
		if(cluster.clusters[nCluster].endIndex < 400 && nCluster < cluster.clusters.size()){
			if(t > cluster.clusters[nCluster].endIndex * buf_size / SONAR_WIDTH){
				if(nCluster > 0){
					seconds = (float)((float)NUMBER_OF_SECONDS * (float)(cluster.clusters[nCluster].endIndex - cluster.clusters[nCluster - 1].endIndex) / SONAR_WIDTH);
				}
				else{
					seconds = (float)(NUMBER_OF_SECONDS * (float)(cluster.clusters[nCluster].endIndex) / SONAR_WIDTH);
				}
				printf("Seconds played: %f at amplitude: %f\n", seconds, A);
				
				totalSeconds += seconds;
				nCluster++;
				A = 30000.0 * (1.0-((cluster.clusters[nCluster].depth - min) / (max - min)));
			}
		}		
		
		sampleBurst->burst[t] = A * sin((2.0 * (float)(M_PI) * freq) / SAMPLE_FREQUENCY * t );
	}
	
	printf("\nTotal number of seconds played: %f\n", totalSeconds);
	
}
