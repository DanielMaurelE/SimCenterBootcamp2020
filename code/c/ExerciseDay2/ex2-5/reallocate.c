#include "reallocate.h"
#include <stdlib.h>
#include <stdio.h>

void reallocate(double *vector1,double *vector2,int *maxVectorSize){
	double *vector1_temp = (double *)malloc(*maxVectorSize*2*sizeof(double));
	double *vector2_temp = (double *)malloc(*maxVectorSize*2*sizeof(double));
	for(int i=0;i<*maxVectorSize;i++){
		vector1_temp[i]=*vector1;
		vector2_temp[i]=*vector2;
		vector1++;
		vector2++;
	}
	printf("HI \n");
	double* vector1_old=vector1;
	double* vector2_old=vector2;
	free(vector1_old);
	free(vector2_old);
	vector1 = (double*)malloc(*maxVectorSize*2*sizeof(double));
	vector2 = (double*)malloc(*maxVectorSize*2*sizeof(double));
	for(int i=0;i<*maxVectorSize;i++){
		vector1[i]=*vector1_temp;
		vector2[i]=*vector2_temp;
		vector1++;
		vector2++;
	}
	free(vector1_temp);
	free(vector2_temp);
	*maxVectorSize=*maxVectorSize*2;
}