#include <stdio.h>
#include <time.h>
#include <math.h>
#include <omp.h>

static long int numSteps = 100000000;
int main(int argc, char **argv){
  	double pi   = 0.0;
	double pit[5];
  #pragma omp parallel num_threads(5)
  {
	double pi_temp;
	double dx = 1.0/(double)numSteps;  
    int id = omp_get_thread_num();
    int numP = omp_get_num_threads();
	double x;
	//printf("%ld\n",numSteps/numP);
	for (long int i=0; i<(long int)(numSteps/numP); i++) {
		x=(double)(id*numSteps/numP+i)*dx+0.5*dx;
		pi_temp += 4./(1.+x*x);
	}
	pit[id]=pi_temp;
  }
  for (int i=0; i<5;i++){
	  pi+=pit[i];
  }
  pi *= 1.0/(double)numSteps;
  
  printf("PI = %16.14f Difference from math.h definition %16.14f \n",pi, pi-M_PI);
  return 0;
}
