#include "highPassFilter.h"

highPassFilter::highPassFilter()
{
    kernel= vector< vector<float> >(3, vector<float>(3, 0.0));
    
    kernel[0][0] = (float)-1/9;
    kernel[1][0] = (float)-1/9;
    kernel[2][0] = (float)-1/9;
    kernel[0][1] = (float)-1/9;
    kernel[1][1] = (float) 8/9;
    kernel[2][1] = (float)-1/9;
    kernel[0][2] = (float)-1/9;
    kernel[1][2] = (float)-1/9;
    kernel[2][2] = (float)-1/9;
    
    this->offsetX = 1;
    this->offsetY = 1;
}

highPassFilter::~highPassFilter()
{
}


