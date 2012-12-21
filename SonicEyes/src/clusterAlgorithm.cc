#include "clusterAlgorithm.h"

clusterAlgorithm::clusterAlgorithm() {
}

clusterAlgorithm::~clusterAlgorithm() {
}

ClusterData clusterAlgorithm::detectClusters(DepthData & inDepthData) {
    DepthData tempDepthData;
    ClusterData outClusterData;
    memset(&tempDepthData.values, 0, sizeof(tempDepthData.values));
    
    assignClusters(inDepthData, outClusterData);
    calculateClusterDepths(outClusterData, inDepthData);

    return outClusterData;
}

void clusterAlgorithm::assignClusters(DepthData & tempDepthData, ClusterData & outClusterData) {
    for(int i = 0; i < SONAR_WIDTH; i++) {	
	Cluster tempCluster;
	tempCluster.startIndex = i;
	tempCluster.endIndex = i;
	
	DepthValue currentClusterDepth = tempDepthData.values[i];
	for(int j = i+1; j < SONAR_WIDTH; j++) {
	    tempCluster.endIndex = j;
	    if(tempDepthData.values[j] > (currentClusterDepth + MAX_CLUSTER_DEPTH_DEVIATION) ||
	       tempDepthData.values[j] < (currentClusterDepth - MAX_CLUSTER_DEPTH_DEVIATION)) {		
		tempCluster.endIndex = j;
		i=j;
		break;
	    }
	}	
	outClusterData.clusters.push_back(tempCluster);
	if(tempCluster.endIndex == SONAR_WIDTH-1) {
	    break;
	}
    }
}

void clusterAlgorithm::calculateClusterDepths(ClusterData & outClusterData, DepthData & inDepthData) {
    for(unsigned char i = 0; i < outClusterData.clusters.size(); i++){
	float tempDepth = 0;

	for(int j = outClusterData.clusters[i].startIndex; j <= outClusterData.clusters[i].endIndex; j++) {
	    tempDepth += (float)inDepthData.values[j];
	}
	if(outClusterData.clusters[i].endIndex - outClusterData.clusters[i].startIndex > 0) {
	    outClusterData.clusters[i].depth = tempDepth / (outClusterData.clusters[i].endIndex - outClusterData.clusters[i].startIndex);
	}
	else {
	    outClusterData.clusters[i].depth = tempDepth;
	}
	printf("tempDepth[%i]: %f\n", i,tempDepth);
    }
}
