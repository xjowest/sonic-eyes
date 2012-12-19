#include "lowPassFilter.h"

lowPassFilter::lowPassFilter()
{
    kernel= vector< vector<float> >(3, vector<float>(3, 0.0));
    
    kernel[0][0] = (float)1/16;
    kernel[1][0] = (float)2/16;
    kernel[2][0] = (float)1/16;
    kernel[0][1] = (float)2/16;
    kernel[1][1] = (float)4/16;
    kernel[2][1] = (float)2/16;
    kernel[0][2] = (float)1/16;
    kernel[1][2] = (float)2/16;
    kernel[2][2] = (float)1/16;    

    this->offsetX = 1;
    this->offsetY = 1;
}

lowPassFilter::~lowPassFilter()
{
}


