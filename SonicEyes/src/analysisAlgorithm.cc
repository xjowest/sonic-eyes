#include "analysisAlgorithm.h"

analysisAlgorithm::analysisAlgorithm() {
    hpFilter = new highPassFilter();    
    lpFilter = new lowPassFilter();
    dirFilter = new directionFilter();
    eroFilter = new erosionFilter();
    dilFilter = new dilationFilter();
}

analysisAlgorithm::~analysisAlgorithm() {
    delete hpFilter;
    delete lpFilter;
    delete dirFilter;
    delete eroFilter;
    delete dilFilter;
}

void analysisAlgorithm::analyzeData(ImageArray & image) {    
    lpFilter->applyFilter(image);
    dirFilter->applyFilter(image);
    hpFilter->applyFilter(image);
    applyThreshHoldFilter(image);
    eroFilter->applyFilter(image, 3);
    eroFilter->applyFilter(image, 3);
    dilFilter->applyFilter(image, 3);
    eroFilter->applyFilter(image, 3);
    dilFilter->applyFilter(image, 3);
    eroFilter->applyFilter(image, 3);
    dilFilter->applyFilter(image, 3);
    dilFilter->applyFilter(image, 3);
    dilFilter->applyFilter(image, 3);
    dilFilter->applyFilter(image, 3);
}

void analysisAlgorithm::applyThreshHoldFilter(ImageArray & image) {
    for(int i = 0; i < IMAGE_WIDTH; i++) {
	for(int j = 0; j < IMAGE_HEIGHT; j++) {
	    if ((float)image.values[i][j] >= 27.0) {
		image.values[i][j] = 255.0;
	    }
	    else {
		image.values[i][j] = 0.0;
	    }
	}
    }
}
