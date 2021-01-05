// program to solve quadratic equation
//        ax^2 + bx + c = 0
//
// soln: x = -b/2a +/- sqrt(b^2-4ac)/2a
//
// write a program to take 3 inputs and output the soln
// deal with possible errors in input, i.e. b^2-4ac negative

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if (argc != 4) {
    printf("Usage: appName a b c\n");
    exit(-1);
  }

  float a = atof(argv[1]);
  float b = atof(argv[2]);
  float c = atof(argv[3]);
  double soln1 = 0.0, soln2 = 0.0;
  if(4*a*c>b*b){
    printf("Error b^2-4ac is negative \n");
  }
  else if(4*a*c==b*b){
    soln1 = (double)(-b/(2.0*a)+sqrt(b*b-4.0*a*c)/(2.0*a));
    printf("Solution : %lf \n",soln1);
  }
  else if(a==0.0){
    soln1 = (double)(-c/b);
    printf("Solution : %lf \n",soln1);
  }
  else{
    soln1 = (double)(-b/(2.0*a)+sqrt(b*b-4.0*a*c)/(2.0*a));
    soln2 = (double)(-b/(2.0*a)-sqrt(b*b-4.0*a*c)/(2.0*a));
    printf("Solution 1 : %lf \nSolution 2: %lf \n",soln1,soln2);
  }
  return 0;
}
