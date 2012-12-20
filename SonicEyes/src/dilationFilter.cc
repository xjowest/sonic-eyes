#include "dilationFilter.h"

dilationFilter::dilationFilter()
{
    kernel= vector< vector<float> >(3, vector<float>(3, 0.0));
    
    kernel[0][0] = (float)1;
    kernel[1][0] = (float)1;
    kernel[2][0] = (float)1;
    kernel[0][1] = (float)1;
    kernel[1][1] = (float)1;
    kernel[2][1] = (float)1;
    kernel[0][2] = (float)1;
    kernel[1][2] = (float)1;
    kernel[2][2] = (float)1;
    
    this->offsetX = 1;
    this->offsetY = 1;
}

dilationFilter::~dilationFilter()
{
}


void dilationFilter::applyFilter(ImageArray & image, int threshold) {
    ImageArray result;
    
    for (int x = 0; x < IMAGE_WIDTH; x++) {
        for (int y = 0; y < IMAGE_HEIGHT; y++) {
	    if(countNeighbouringPixels(image, x, y) >= threshold) {
		result.values[x][y] = (Pixel)255;
	    }
	    else {
		result.values[x][y] = image.values[x][y];
	    }
        }
    }
    
    image = result;
}
