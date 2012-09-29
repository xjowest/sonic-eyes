#include <cstring>
#include <cstdio>
#include "filterBaseClass.h"

//using namespace std;

filterBaseClass::filterBaseClass()
{

}

filterBaseClass::~filterBaseClass()
{

}

void filterBaseClass::applyFilter(ImageArray & image)
{
    ImageArray result;

    for (int x = 0; x < 640; x++)
    {
        for (int y = 0; y < 480; y++)
        {
            result[x][y] = filterCurrentPixel(image, x, y);
        }
    }

    std::memcpy(image, &result, sizeof(ImageArray));
}

Pixel filterBaseClass::filterCurrentPixel(ImageArray & image, int x, int y)
{
    Pixel result = 0;

    for (Index i = 0; i < this->kernel.size(); i++)
    {
        for (Index j = 0; j < this->kernel[0].size(); j++)
        {
            if(this->kernel[i][j] != NULL)
            {
                if(x-offsetX+i >= 0 && x-offsetX+i < 640 &&
                   y-offsetY+j >= 0 && y-offsetY+j < 480)
                {
                    result += image[x-offsetX+i][y-offsetY+j] * this->kernel[i][j];
                }
                else
                {
                    result = image[x][y] * this->kernel[i][j];
                }
            }
        }
    }

    return result;
}
