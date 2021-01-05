#include <stdio.h>
#include <math.h>
#include "stress.h"

float deg2rad(float a){
	float b;
	b=a/180.0*3.14159265358979323846;
	return b;
}

void StressTransform(float sXX,float sYY,float tXY, float theta, float *spx, float *spy, float *tpxy){
	float thetaR;
	thetaR=deg2rad(theta);
	*spx=sXX*cos(thetaR)*cos(thetaR)+sYY*sin(thetaR)*sin(thetaR)+2*tXY*sin(thetaR)*cos(thetaR);
	*spy=sXX*sin(thetaR)*sin(thetaR)+sYY*cos(thetaR)*cos(thetaR)-2*tXY*sin(thetaR)*cos(thetaR);
	*tpxy=(sXX-sYY)*sin(thetaR)*cos(thetaR)+tXY*(cos(thetaR)*cos(thetaR)-sin(thetaR)*sin(thetaR));
	}
		