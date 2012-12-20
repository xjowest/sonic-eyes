#include "sonar.h"

void GetSonarData(DepthValue * z, char* fileName, int size)
{
    FILE* fd;

    fd = fopen(fileName, "r");
    
    if(fd)
	fread((DepthValue*)z, sizeof(DepthValue), size, fd);
    else
	printf("Could not read file");
    
    fclose(fd);   
}

