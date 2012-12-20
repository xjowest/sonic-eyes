#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "externalTypeDefs.h"

int main(void)
{
	FILE * fd = NULL;
	int i = SONAR_WIDTH - 1;
	int j, k = 0;
	double angle = 37.0;
	double dAngle = 0.25;
	double angDepth[SONAR_WIDTH];
	DepthValue eukDepth[SONAR_WIDTH];
	
	while(angle < 54){
		angDepth[i] = -j*dAngle*0.05294 + 3.6;
		j++;
		i--;
		angle += dAngle;
	}
	
	j = 1;
	
	while(angle < 70){
		angDepth[i] = j*dAngle*0.11875 + 2.7;
		j++;
		i--;
		angle += dAngle;
	}
	
	while(angle < 90){
		angDepth[i] = 5.0;
		i--;
		angle += dAngle;
	}
	
	k = i;
	j = 1;
		
	while(i >= 0){
		angDepth[i] = j*(dAngle)*0.02245 + 2.1;
		j++;
		i--;
		angle += dAngle;
	}
	
	angle -= dAngle;
	
	for(i=0;i<k;i++){
		eukDepth[i] = (DepthValue)(angDepth[i] * sin((180-angle) * 2 * PI / 360) * 100 / 5);
		angle -=dAngle;
	}
	
	for(i=k;i<SONAR_WIDTH;i++){
		eukDepth[i] = (DepthValue)(angDepth[i] * sin(angle * 2 * PI / 360) * 100 / 5);
		angle -=dAngle;
	}	
	
	fd = fopen("../resources/currentDepth.txt", "w");
	fwrite(eukDepth, sizeof(DepthValue), sizeof(eukDepth), fd);
	fclose(fd);
	
	return 0;
}
