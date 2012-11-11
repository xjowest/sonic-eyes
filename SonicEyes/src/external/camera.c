#include "camera.h"

int GetPixelData(Image img, char* fileName, U16 width, U16 height){
    FILE* fd;

    fd = fopen(fileName, "rb");

    if(fd){
	fread(img, sizeof(U8), width*height, fd);
    }
    else
	return -1;

    fclose(fd);

    return 0;
}
