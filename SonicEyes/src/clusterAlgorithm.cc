#include "clusterAlgorithm.h"

clusterAlgorithm::clusterAlgorithm() {
}

clusterAlgorithm::~clusterAlgorithm(){
}

ClusterData clusterAlgorithm::detectClusters(DepthData inData){
	ClusterData outData;
	
	for(int i = 0; i < IMAGE_WIDTH; i++){
		for(int j = MIN_DEPTH; j < MAX_DEPTH; j+= MAX_DEPTH/DEPTH_LEVELS){
			if(inData.values[i] < j){
				outData.addToClusters(j);
			}			
		}
	}
	
	return outData;
}
