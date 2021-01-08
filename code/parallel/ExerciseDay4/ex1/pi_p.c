#include <stdio.h>
#include <time.h>
#include <math.h>
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

static long int numSteps = 40000;

int main(int argc, char **argv) {
	
  int numP, procID;  
  // the usual mpi initialization
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numP);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);
  double pi   = 0.0;
  double dx = 1./(double)numSteps;
  int LUMP = (int)numSteps/(int)numP;  
  double *globalData=NULL;
  double localData[LUMP];
  printf("%lf\n",dx);
  // perform calculation

  // process 0 is only 1 that needs global data
  
  if (procID == 0) {
    globalData = (double*)malloc(LUMP * numP * sizeof(double));
	for (int i=0; i<LUMP*numP; i++)
      globalData[i] = 0;
  }
  for (int i=0; i<LUMP; i++){
    localData[i] = 4./(1.+(((double)(procID*LUMP+i)*dx+0.5*dx)*(((double)(procID*LUMP)+i)*dx+0.5*dx)));
  }
  MPI_Gather(localData, LUMP, MPI_DOUBLE, globalData, LUMP, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  if (procID == 0) {
    for (int i=0; i<(numP*LUMP); i++){
      pi += globalData[i];
	}
	pi *= dx;
  }
  if (procID == 0){
    free(globalData);
	printf("PI = %16.14f Difference from math.h definition %16.14f \n",pi, pi-M_PI);
  }
  MPI_Finalize();
}
