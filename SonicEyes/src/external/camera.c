#include "camera.h"

void GetPixelData(Image img, char* fileName, U16 size){
  FILE* fd;

  fd = fopen(fileName, "rb");

  if(fd)
    fread(img, sizeof(U8), size, fd);
  else
    printf("Could not read file");
  
  fclose(fd);
}
