#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // need this for the constant pi = M_PI

#include "stresstransform.h"


int main(int argc, char **argv) {

	// get dth from the first argument.  This is given in degrees!
	// might be smart to set a default value, just in case the user
	// forgets when calling this  program;)


	// set the initial stress state

	STRESS S0;
	STRESS Sp;

	S0.sigx = 12.0;
	S0.sigy = -5.5;
	S0.tau  =  3.5;

	// loop to compute transformed states
	double incr=5.0, theta=0.0;
	if(argc>1){
		double incr=atof(argv[1]);
	}
	for(int i=0;i<=(int)(ceil(180.0/incr));i++){
		StressTransform(S0, &Sp, (double)(i*incr));
		printf("%12.6f, %12.6f, %12.6f, %12.6f\n",(double)(i*incr), Sp.sigx, Sp.sigy, Sp.tau);
	}
}

