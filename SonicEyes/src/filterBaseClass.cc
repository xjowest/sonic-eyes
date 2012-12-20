#include "filterBaseClass.h"

filterBaseClass::filterBaseClass() {
}

filterBaseClass::~filterBaseClass() {
}

void filterBaseClass::applyFilter(ImageArray & image) {
    ImageArray result;

    for (int x = 0; x < IMAGE_WIDTH; x++) {
        for (int y = 0; y < IMAGE_HEIGHT; y++) {
            result.values[x][y] = filterCurrentPixel(image, x, y);
        }
    }

    image = result;
}

Pixel filterBaseClass::filterCurrentPixel(ImageArray & image, int x, int y) {
    float result = 0;

    for (Index i = 0; i < this->kernel.size(); i++) {
        for (Index j = 0; j < this->kernel[0].size(); j++) {
            if(x-offsetX+i >= 0 && x-offsetX+i < IMAGE_WIDTH &&
               y-offsetY+j >= 0 && y-offsetY+j < IMAGE_HEIGHT) {
                result += (float)image.values[x-offsetX+i][y-offsetY+j] * this->kernel[i][j];
            } else {
                result += (float)image.values[x][y] * this->kernel[i][j];
            }            
        }
    }
    if(result < 0.0) {
	result = 0.0;
    }
    else if(result > 255.0) {
	result = 255.0;
    }
    return (Pixel)result;
}

int filterBaseClass::countNeighbouringPixels(ImageArray & image, int x, int y) {
    int result = 0;
//    if ((int)image.values[x][y] == 255) {
//	result = -1;
//    }

    if((int)image.values[x][y-1] == 255 &&
       y-1 >= 0) {
	result++;
    }
    if((int)image.values[x][y+1] == 255 &&
       y+1 < IMAGE_HEIGHT) {
	result++;
    }

/*
    for (Index i = 0; i < this->kernel.size(); i++) {
        for (Index j = 0; j < this->kernel[0].size(); j++) {
            if(x-offsetX+i >= 0 && x-offsetX+i < IMAGE_WIDTH &&
               y-offsetY+j >= 0 && y-offsetY+j < IMAGE_HEIGHT &&
	       y != y-offsetY+j &&
	       (int)image.values[x-offsetX+i][y-offsetY+j] == 255) {
                result++;
	    }
	}
	}*/

    return result;
}
