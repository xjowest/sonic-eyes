#include "highPassFilter.h"

highPassFilter::highPassFilter()
{
    this->kernel[0][0] = -1/9;
    this->kernel[1][0] = -1/9;
    this->kernel[2][0] = -1/9;
    this->kernel[0][1] = -1/9;
    this->kernel[1][1] =  8/9;
    this->kernel[2][1] = -1/9;
    this->kernel[0][2] = -1/9;
    this->kernel[1][2] = -1/9;
    this->kernel[2][2] = -1/9;

    this->offsetX = 1;
    this->offsetY = 1;
}

highPassFilter::~highPassFilter()
{
}


