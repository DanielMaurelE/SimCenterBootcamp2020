#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
	static int long StepCount=10000000;
	double Pi=0.0, time=0.0, x=0;
	clock_t begin = clock();
	for(int i=1;i<=StepCount;i++){
		Pi+=4.0/(1+((i-0.5)/StepCount)*((i-0.5)/StepCount));
	}
	Pi=Pi/((double)StepCount);
    clock_t end = clock();
	time=(double)(end - begin) / CLOCKS_PER_SEC;
	printf("Pi = %lf | Excecution time = %lf s \n",Pi,time);
	return 0;
}
