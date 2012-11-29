#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i=0;
    double k1 = 0.07143;
    double f1 = 1.4;

    unsigned char depth[50];

    while(f1 < 2.10){
	f1 += k1;
	depth[i] = (unsigned char)(f1 * 256.0 / 5 - 1.0);
	printf("%u\n", (unsigned int)depth[i]);
	i++;
    }
    
    return 0;
}
