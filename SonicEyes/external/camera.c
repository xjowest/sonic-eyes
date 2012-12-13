#include "camera.h"

void GetPixelData(Image * img, char* fileName, int size){
    FILE* fd;
    fd = fopen(fileName, "r");

    if(fd){
	fread((Image*)img, sizeof(Image), size, fd);
    }
    else
	printf("Could not read file");
    
    fclose(fd);
}
