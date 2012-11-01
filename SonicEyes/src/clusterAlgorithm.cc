#include "clusterAlgorithm.h"

clusterAlgorithm::clusterAlgorithm() {
}

clusterAlgorithm::~clusterAlgorithm() {
}

ClusterData clusterAlgorithm::detectClusters(DepthData inDepthData) {
    DepthData tempDepthData;
    ClusterData outClusterData;
    
    clampDepthValues(inDepthData, tempDepthData);
    assignClusters(tempDepthData, outClusterData);
    calculateClusterDepths(outClusterData, inDepthData);

    return outClusterData;
}

void clusterAlgorithm::clampDepthValues(DepthData inDepthData, DepthData tempDepthData) {
    for(int i = 0; i < SONAR_WIDTH; i++){
	for(int j = MIN_DEPTH; j < MAX_DEPTH; j+= (MAX_DEPTH - MIN_DEPTH)/DEPTH_LEVELS) {
	    if(inDepthData.values[i] <= j){
		tempDepthData.values[i] = j;
	    }			
	}
    }
}

void clusterAlgorithm::assignClusters(DepthData tempDepthData, ClusterData outClusterData) {
    for(int i = 0; i < SONAR_WIDTH; i++) {	
	Cluster tempCluster;
	tempCluster.startIndex = i;
	tempCluster.endIndex = i;
	
	DepthValue currentClusterDepth = tempDepthData.values[i];
	
	for(int j = i+1; j < SONAR_WIDTH; j++) {
	    if(tempDepthData.values[j] > currentClusterDepth + MAX_CLUSTER_DEPTH_DEVIATION ||
	       tempDepthData.values[j] < currentClusterDepth - MAX_CLUSTER_DEPTH_DEVIATION) {
		i = j;
		break;
	    }
	}
	outClusterData.clusters.push_back(tempCluster);	
    }
}

void clusterAlgorithm::calculateClusterDepths(ClusterData outClusterData, DepthData inDepthData) {
    for(unsigned char i = 0; i < outClusterData.clusters.size(); i++){
	float tempDepth;
	for(int j = outClusterData.clusters[i].startIndex; j < outClusterData.clusters[i].endIndex; j++) {
	    tempDepth += (float)inDepthData.values[j];
	}
	outClusterData.clusters[i].depth = tempDepth / (outClusterData.clusters[i].endIndex - outClusterData.clusters[i].startIndex);
    }
}
