#include <stdio.h>
#include <stdlib.h>

typedef unsigned char U8;
typedef unsigned short U16;

int main(void)
{
  double k1 = 1.02;
  double k2 = 1.62;
  U16 m = 140;
  U16 f[400];//cm
  int i;

  for(i=0;i<400;i++){
    f[i] = m + i*k1;
  }
  
  for(i=80;i<148;i++){
    f[i] = 500;
  }

  for(i=148;i>

  for(i=0;i<400;i++)
    printf("%u ", f[i]);

  printf("\n");  

  return 0;
}
