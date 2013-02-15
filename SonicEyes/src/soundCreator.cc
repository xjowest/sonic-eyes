#include "soundCreator.h"

soundCreator::soundCreator() {
}

soundCreator::~soundCreator() {
}

void soundCreator::createSound(SampleBurst * sampleBurst, ClusterData & cluster) {
    int buf_size = NUMBER_OF_SECONDS * SAMPLE_FREQUENCY;
	double A = 0;
	double freqStart = 0.f;
	double freqEnd = 0.f;
	double * tmpBuf = (double*)malloc(buf_size * sizeof(double));
	memset(tmpBuf, 0, buf_size * sizeof(double));
	double maxSample = 0;
	
	for(int i = 0; i < cluster.clusters.size(); i++){
		if(cluster.clusters[i].endIndex - cluster.clusters[i].startIndex > 20){
			A = 30000.0 * (1.0-(cluster.clusters[i].depth / MAX_DEPTH));
					
			freqStart = cluster.clusters[i].startIndex * 5 + 500;
			freqEnd = cluster.clusters[i].endIndex * 5 + 500;
			
			for(int t = 0; t < buf_size; t++){
				tmpBuf[t] += A*sin(2.0 * M_PI * freqEnd * t / SAMPLE_FREQUENCY);
				tmpBuf[t] += A*sin(2.0 * M_PI * freqStart * t / SAMPLE_FREQUENCY);
			}
			
			printf("Amplitude %f at frequency %f and %f\n", A, freqStart, freqEnd);
			
		}
		for(int t = 0; t < buf_size; t++){
			if(tmpBuf[t] > maxSample)
				maxSample = tmpBuf[t];
		}
		
		
	}
	
	for(int t = 0; t < buf_size; t++){
		sampleBurst->burst[t] = 30000 * tmpBuf[t] / maxSample;
	}
	
	free(tmpBuf);
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
			
		printf("Cluster[%i]: %i\n", i, cluster.clusters[i].depth);
	}
	printf("Max: %u, Min: %u:\n", max, min);	
		
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
