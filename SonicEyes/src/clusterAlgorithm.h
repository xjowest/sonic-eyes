#ifndef CLUSTER_ALGORITHM_H
#define CLUSTER_ALGORITHM_H

#include "typeDefs.h"

class clusterAlgorithm{
public:
    clusterAlgorithm();
    ~clusterAlgorithm();

    ClusterData detectClusters(DepthData inDepthData);
    
    void clampDepthValues(DepthData inDepthData, DepthData tempDepthData);
    void assignClusters(DepthData tempDepthData, ClusterData outClusterData);
    void calculateClusterDepths(ClusterData outClusterData, DepthData inDepthData);
    
private:
};

#endif
