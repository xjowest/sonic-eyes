#ifndef ANALYSIS_ALGORITHM_H
#define ANALYSIS_ALGORITHM_H

#include "typeDefs.h"
#include "highPassFilter.h"

class analysisAlgorithm{
public:
    analysisAlgorithm();
    ~analysisAlgorithm();

    void analyzeData(ImageArray & image);
    
private:
    void applyThreshHoldFilter(ImageArray & image);
    void applyErosionFilter(ImageArray & image);
    void applyDilationFilter(ImageArray & image);
    Pixel returnExtremeValue(ImageArray & image, int x, int y, float plusOrMinus);

    highPassFilter * hpFilter;
};

#endif
