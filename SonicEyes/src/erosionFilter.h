#ifndef EROSION_FILTER_H
#define EROSION_FILTER_H

#include "filterBaseClass.h"

class erosionFilter : public filterBaseClass
{
    public:
        erosionFilter();
        ~erosionFilter();
	void applyFilter(ImageArray & image, int threshold);
};

#endif
