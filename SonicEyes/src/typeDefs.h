#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef unsigned char Pixel;

typedef unsigned char Index;

typedef vector< vector<float> > Kernel;

struct ImageArray{
public:	
//~ImageArray(){delete values;}

    Pixel values[640][480];

    void operator=(const ImageArray &I ){
	for(int i = 0; i < 640; i++){
	    for(int j = 0; j < 480; j++){
		values[i][j] = I.values[i][j];
	    }
	}
    }
};

#endif
