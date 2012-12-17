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
    Pixel result = 0;

    for (Index i = 0; i < this->kernel.size(); i++) {
        for (Index j = 0; j < this->kernel[0].size(); j++) {
            if(x-offsetX+i >= 0 && x-offsetX+i < IMAGE_WIDTH &&
               y-offsetY+j >= 0 && y-offsetY+j < IMAGE_HEIGHT) {
                result += image.values[x-offsetX+i][y-offsetY+j] * this->kernel[i][j];
            } else {
                result = image.values[x][y] * this->kernel[i][j];
            }            
        }
    }

    return result;
}
