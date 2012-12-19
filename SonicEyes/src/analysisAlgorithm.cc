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
    dirFilter->applyFilter(image);
    lpFilter->applyFilter(image);
    lpFilter->applyFilter(image);
    hpFilter->applyFilter(image);
    applyThreshHoldFilter(image);
    eroFilter->applyFilter(image, 2);
    dilFilter->applyFilter(image, 2);
    //eroFilter->applyFilter(image, 4);
    //dilFilter->applyFilter(image, 4);
    //eroFilter->applyFilter(image, 4);
    //dilFilter->applyFilter(image, 4);
}

void analysisAlgorithm::applyThreshHoldFilter(ImageArray & image) {
    for(int i = 0; i < IMAGE_WIDTH; i++) {
	for(int j = 0; j < IMAGE_HEIGHT; j++) {
	    if ((float)image.values[i][j] >= 25.0) {
		image.values[i][j] = 255.0;
	    }
	    else {
		image.values[i][j] = 0.0;
	    }
	}
    }
}
