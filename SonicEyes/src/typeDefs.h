#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include "SDL/SDL.h"

using namespace std;

// Definitions
#define DEPTH_LEVELS 100		// The depth resolution
#define MIN_DEPTH 0			// Closest to the camera in meters
#define MAX_DEPTH 5			// Farthest away from the camera in meters
#define MAX_CLUSTER_DEPTH_DEVIATION 0.3 // For the cluster algorithm
#define SONAR_WIDTH 400                 // Width of sonar data (X)
#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
#define IMAGE_SIZE 640 * 480
#define IMAGE_PITCH 3                   // Bytes per pixel
#define SAMPLE_FREQUENCY 20000
#define LOWEST_FREQUENCY 1000
#define HIGHEST_FREQUENCY 10000

// Typedefs
typedef unsigned char Pixel;

typedef Uint8 Sample;

typedef unsigned char Index;

typedef unsigned char DepthValue;

typedef unsigned char U8;

typedef unsigned short U16;

typedef vector< vector<float> > Kernel;

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

struct SoundData {
    public:	
    Sample values[SAMPLE_FREQUENCY / LOWEST_FREQUENCY];

    int duration;
    
    void operator=(const SoundData &I ){
	for(int i = 0; i < SAMPLE_FREQUENCY / LOWEST_FREQUENCY; i++){
	    values[i] = I.values[i];	    
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

#endif
