#include "sonar.h"

void GetSonarData(DepthValue z, char* fileName, U8 size)
{
    FILE* fd;

    fd = fopen(fileName, "rb");
    
    if(fd)
	fread(z, sizeof(U8), size, fd);
    else
	printf("Could not read file");
    
    fclose(fd);   
}

