#ifndef ANALYSIS_ALGORITHM_H
#define ANALYSIS_ALGORITHM_H

#include "typeDefs.h"
#include "highPassFilter.h"
#include "lowPassFilter.h"
#include "directionFilter.h"
#include "erosionFilter.h"
#include "dilationFilter.h"

class analysisAlgorithm{
public:
    analysisAlgorithm();
    ~analysisAlgorithm();

    void analyzeData(ImageArray & image);
    
private:
    void applyThreshHoldFilter(ImageArray & image);

    highPassFilter * hpFilter;
    lowPassFilter * lpFilter;
    directionFilter * dirFilter;
    erosionFilter * eroFilter;
    dilationFilter * dilFilter;

};

#endif
