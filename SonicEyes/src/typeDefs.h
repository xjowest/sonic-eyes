#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include "SDL/SDL.h"

using namespace std;

// Definitions
#define DEPTH_LEVELS 100.0		// The depth resolution
#define MIN_DEPTH 0.0			// Closest to the camera in meters
#define MAX_DEPTH 5.0			// Farthest away from the camera in meters
#define MAX_CLUSTER_DEPTH_DEVIATION 0.3 // For the cluster algorithm
#define SONAR_WIDTH 400                 // Width of sonar data (X)
#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
#define MIDDLE_OF_IMAGE IMAGE_HEIGHT/2
#define IMAGE_SIZE 640 * 480
#define IMAGE_PITCH 3                   // Bytes per pixel
#define SAMPLE_FREQUENCY 22050
#define NUMBER_OF_SOUND_SAMPLES 44100
#define NUMBER_OF_SECONDS 1

// Typedefs
typedef unsigned char Pixel;

typedef Sint16 Sample;

typedef unsigned char Index;

typedef unsigned char U8;

typedef unsigned short U16;

typedef float DepthValue;

typedef vector< vector<float> > Kernel;

typedef int DepthValues[NUMBER_OF_SOUND_SAMPLES];

typedef bool EdgePositions[IMAGE_WIDTH];

// Structs
struct ImageArray {
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

struct DepthData {
    public:
    DepthValue values[SONAR_WIDTH];
    
    void operator=(const DepthData &I ){
		for(int i = 0; i < SONAR_WIDTH; i++){		
		    values[i] = I.values[i];
		}		
    }
};

struct Cluster {
    public:
    Cluster(){
	startIndex = 0;
	endIndex = 0;
	depth = 0;
    }
    
    int startIndex;
    int endIndex;
    DepthValue depth;
    
    void operator=(const Cluster &I ){
	startIndex = I.startIndex;
	endIndex = I.endIndex;
	depth = I.depth;
    }		
};


struct ClusterData {
    vector< Cluster > clusters;    
};

struct AnalyzedData {
    DepthValues depthValues;    
};

struct SampleBurst {
    Sample * burst;
    
    SampleBurst() {
	burst = (Sample *) malloc(sizeof(Sample) * NUMBER_OF_SECONDS * SAMPLE_FREQUENCY);
	memset(burst, 0, NUMBER_OF_SECONDS * SAMPLE_FREQUENCY);
    }
    ~SampleBurst() {
	free(burst);
    }
};

#endif
