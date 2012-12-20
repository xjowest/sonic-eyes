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

void analysisAlgorithm::analyzeData(ImageArray & image, EdgePositions & positions) {    
    lpFilter->applyFilter(image);
    dirFilter->applyFilter(image);
    hpFilter->applyFilter(image);
    applyThreshHoldFilter(image);

    for(int i = 0; i < 12; i++) {
	eroFilter->applyFilter(image, 1);
    }
    for(int i = 0; i < 50; i++) {
	dilFilter->applyFilter(image, 1);
    }

    detectEdges(image, positions);
    drawEdges(image, positions);
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

void analysisAlgorithm::detectEdges(ImageArray & image, EdgePositions & positions) {
    int previousEdge = -2;
    for(int i = 0; i < IMAGE_WIDTH; i++) {
	if((int)image.values[i][MIDDLE_OF_IMAGE] == 255) {
	    if(i >= previousEdge+3) {
		positions[i] = true;
	    }	   
	    previousEdge = i;
	}
    }
}

void analysisAlgorithm::drawEdges(ImageArray & image, EdgePositions & positions) {
    for (int i = 0; i < IMAGE_WIDTH; i++) {
	for(int j = 0; j < IMAGE_HEIGHT; j++) {
	    if(positions[i]) {
		image.values[i][j] = (Pixel)255;
	    }
	    else {
		image.values[i][j] = (Pixel)0;
	    }
	}
    }
}
