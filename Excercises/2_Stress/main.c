#include <stdio.h>
#include <math.h>
#include "stress.h"

int main(char argc, char * argv[5]){
	float sXX=12.0, sYY=-5.5, tXY=3.5,theta=50.0, spy=0.0, spx=0.0, tpxy=0.0;
	StressTransform(sXX,sYY,tXY,theta,&spx,&spy,&tpxy);
	printf("s'x %f \ns'y %f \nt'xy %f \n",spx,spy,tpxy);
	return 0;
}