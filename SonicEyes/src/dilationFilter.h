#ifndef DILATION_FILTER_H
#define DILATION_FILTER_H

#include "filterBaseClass.h"

class dilationFilter : public filterBaseClass
{
    public:
        dilationFilter();
        ~dilationFilter();
	void applyFilter(ImageArray & image, int threshold);
};

#endif
