#include <stdio.h>
#include <stdlib.h>

#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480

typedef unsigned char U8;
typedef unsigned short U16;
typedef U8 * Image;

extern "C" Image GetPixelData(Image img, char* fileName, U16 width, U16 height);

int main(void){
    Image img = (U8*)malloc((size_t)(IMAGE_WIDTH * IMAGE_HEIGHT));

    if(!GetPixelData(img, (char *)"test.txt", IMAGE_WIDTH, IMAGE_HEIGHT))
	printf("%s", img);
    else
	printf("Error\n");

    return 0;
}
