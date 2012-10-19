#ifndef FILTER_BASE_CLASS_H
#define FILTER_BASE_CLASS_H

#include "typeDefs.h"

class filterBaseClass{
public:
    filterBaseClass();
    ~filterBaseClass();
    
private:
    void applyFilter(ImageArray & image);
    Pixel filterCurrentPixel(ImageArray & image, int x, int y);
    
protected:
    Kernel kernel;
    unsigned char offsetX;
    unsigned char offsetY;
};

#endif
