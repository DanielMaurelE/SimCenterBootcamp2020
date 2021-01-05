#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stress.h"

int main(char argc, char **argv){
	float sXX=atof(argv[1]), sYY=atof(argv[2]), tXY=atof(argv[3]),theta=0.0,incr=atof(argv[4]), spy=0.0, spx=0.0, tpxy=0.0;
	//float sXX=12.0, sYY=-5.5, tXY=3.5,theta=50.0, spy=0.0, spx=0.0, tpxy=0.0;
	int maxim=(int)(ceil(360/incr));
	for (int i=0; i<=maxim; i++){
		theta=(float)(i*incr);
		StressTransform(sXX,sYY,tXY,theta,&spx,&spy,&tpxy);
		printf("Theta %f| s'x %f | s'y %f | t'xy %f \n",theta,spx,spy,tpxy);
	}
	return 0;
}