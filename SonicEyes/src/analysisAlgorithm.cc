#include "analysisAlgorithm.h"

analysisAlgorithm::analysisAlgorithm() {
    hpFilter = new highPassFilter();
}

analysisAlgorithm::~analysisAlgorithm() {
    delete hpFilter;
}

void analysisAlgorithm::analyzeData(ImageArray & image) {
    hpFilter->applyFilter(image);
    applyThreshHoldFilter(image);
    applyDilationFilter(image);
}

void analysisAlgorithm::applyThreshHoldFilter(ImageArray & image) {
    for(int i = 0; i < IMAGE_WIDTH; i++) {
	for(int j = 0; j < IMAGE_HEIGHT; j++) {
	    if ((float)image.values[i][j] >= 128.0) {
		image.values[i][j] = 0.0;
	    }
	    else {
		image.values[i][j] = 255.0;
	    }
	}
    }
}

void analysisAlgorithm::applyErosionFilter(ImageArray & image) {
    ImageArray result;

    for (int x = 0; x < IMAGE_WIDTH; x++) {
        for (int y = 0; y < IMAGE_HEIGHT; y++) {
            result.values[x][y] = returnExtremeValue(image, x, y, -1.0);
	    //printf("result:%f\n", result.values[x][y]);
        }
    }

    image = result;
}

void analysisAlgorithm::applyDilationFilter(ImageArray & image) {
    ImageArray result;

    for (int x = 0; x < IMAGE_WIDTH; x++) {
        for (int y = 0; y < IMAGE_HEIGHT; y++) {
            result.values[x][y] = returnExtremeValue(image, x, y, 1.0);
        }
    }
    image = result;
}

Pixel analysisAlgorithm::returnExtremeValue(ImageArray & image, int x, int y, float plusOrMinus) {
    float result = 255 * plusOrMinus;
    
    for (Index i = 0; i < 3; i++) {
        for (Index j = 0; j < 3; j++) {
            if(x-1+i >= 0 && x-1+i < IMAGE_WIDTH &&
               y-1+j >= 0 && y-1+j < IMAGE_HEIGHT &&
	       ((float)image.values[x-1+i][y-1+j] * plusOrMinus) > result) {
		if(x < 10) {
		    //printf("%f\n", (float)image.values[x-1+i][y-1+j]);
		}
                result = (float)image.values[x-1+i][y-1+j];
		//result = 128;
	    }
        }
    }
    
    return (unsigned char) result;
}
