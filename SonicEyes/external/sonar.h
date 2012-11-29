#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int U32;

typedef U16 * DepthValue;

void GetSonarData(DepthValue z, char* fileName, U8 size);
