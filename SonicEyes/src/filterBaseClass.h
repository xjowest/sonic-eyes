#ifndef FILTER_BASE_CLASS_H
#define FILTER_BASE_CLASS_H

#include "typeDefs.h"

class filterBaseClass{
public:
    filterBaseClass();
    ~filterBaseClass();    
    void applyFilter(ImageArray & image);

private:    
    Pixel filterCurrentPixel(ImageArray & image, int x, int y);
    
protected:    
    int countNeighbouringPixels(ImageArray & image, int x, int y);

    vector< vector<float> > kernel;
    unsigned char offsetX;
    unsigned char offsetY;
};

#endif
