#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;

typedef U8 * Image;

void GetPixelData(Image img, char* fileName, U16 size);
