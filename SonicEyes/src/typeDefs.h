#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

// Definitions
#define DEPTH_LEVELS 100				// The depth resolution
#define MIN_DEPTH 0						// Closest to the camera in meters
#define MAX_DEPTH 10					// Farthest away from the camera in meters
#define MAX_CLUSTER_DEPTH_DEVIATION 0.3 // For the cluster algorithm
#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480

// Typedefs
typedef unsigned char Pixel;

typedef unsigned char Index;

typedef unsigned char DepthValue;

typedef vector< vector<float> > Kernel;

// Structs
struct ImageArray{
public:	
	Pixel values[IMAGE_WIDTH][IMAGE_HEIGHT];
	
	void operator=(const ImageArray &I ){
		for(int i = 0; i < IMAGE_WIDTH; i++){
			for(int j = 0; j < IMAGE_HEIGHT; j++){
				values[i][j] = I.values[i][j];
			}
		}
	}
};

struct DepthData{
public:
	DepthValue values[IMAGE_WIDTH];
	
	void operator=(const DepthData &I ){
		for(int i = 0; i < IMAGE_WIDTH; i++){		
			values[i] = I.values[i];
		}		
	}
};

struct Cluster{
public:
	int index;
	int startIndex;
	int endIndex;
	DepthValue depth;

	void operator=(const Cluster &I ){
		index = I.index;
		startIndex = I.startIndex;
		endIndex = I.endIndex;
		depth = I.depth;
	}		
};


struct ClusterData{
	vector< Cluster > clusters;
	
	void addToClusters(float inValue){
		
	}
};

#endif
