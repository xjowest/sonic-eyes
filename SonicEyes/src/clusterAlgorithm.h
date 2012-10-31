#ifndef CLUSTER_ALGORITHM_H
#define CLUSTER_ALGORITHM_H

#include "typeDefs.h"

class clusterAlgorithm{
public:
    clusterAlgorithm();
    ~clusterAlgorithm();

    ClusterData detectClusters(DepthData inData);
    
private:
};

#endif
