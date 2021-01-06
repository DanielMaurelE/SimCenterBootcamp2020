
// program to read values from a file, each file a csv list of int and two double
// written: fmk

#include <stdio.h>
#include <stdlib.h>
#include "reallocate.h"
#include <unistd.h>
int main(int argc, char **argv) {

	if (argc != 2) {
		fprintf(stdout, "ERROR correct usage appName inputFile\n");
		return -1;
	}
	  
	FILE *filePtr = fopen(argv[1],"r"); 

	int i = 0;
	float float1, float2;
	int maxVectorSize = 100;
	double *vector1 = (double *)malloc(maxVectorSize*sizeof(double));
	double *vector2 = (double *)malloc(maxVectorSize*sizeof(double));  
	int vectorSize = 0;
	  
	  while (fscanf(filePtr,"%d, %f, %f\n", &i, &float1, &float2) != EOF) {
		vector1[vectorSize] = float1;
		vector2[vectorSize] = float2;
		printf("%d, %f, %f %d\n",i, vector2[i], vector1[i],vectorSize);
		vectorSize++;
		if (vectorSize == maxVectorSize) {
			//reallocate(vector1,vector2,&maxVectorSize);
			vector1=(double*)realloc(vector1,maxVectorSize*2*sizeof(double));
			vector2=(double*)realloc(vector2,maxVectorSize*2*sizeof(double));
			maxVectorSize=maxVectorSize*2;
		}
	}
	fclose(filePtr);  
	free(vector1);
	free(vector2);
}
